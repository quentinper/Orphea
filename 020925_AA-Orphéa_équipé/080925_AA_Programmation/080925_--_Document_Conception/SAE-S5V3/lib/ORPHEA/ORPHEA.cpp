/***************************************************************
 * @file        ORPHEA.cpp
 * @author      Lorenzo S. & Quentin P. & William L-C
 * @version     1
 * @date        2026-01-24
 * @brief       Gestion du système audio ORPHEA.
 * @details     SAE S5-S6 BUG GEII FA ESE
 * @copyright   (c) Lorenzo S. & Quentin P. & William L-C - Tous droits réservés
 ***************************************************************/

#include <ORPHEA.h>

ORPHEA::ORPHEA()
{
  
}

// Constantes MIDI
#define TX_PIN 17
#define RX_PIN 16
#define MIDI_BAUDRATE 31250

// Configuration I2S
#define I2S_NUM         I2S_NUM_0
#define I2S_SAMPLE_RATE 44100  // Fréquence d'échantillonnage (Hz)
#define I2S_BITS        I2S_BITS_PER_SAMPLE_16BIT
#define I2S_CHANNELS    I2S_CHANNEL_FMT_RIGHT_LEFT 

// Broches I2S (ajuste selon ton hardware)
#define I2S_BCK_IO      5  //4
#define I2S_WS_IO       4  //5
#define I2S_DO_IO       18

// Polyphonie : max 8 notes actives
#define MAX_NOTES 32
#define BUFFER_SIZE 128  // Nombre d'échantillons à générer/envoyer par bloc (augmente pour plus de fluidité)

// Paramètres table SIN
#define SINE_TABLE_BITS 10   // 10 bits pour l'index
#define SINE_TABLE_SHIFT (32 - SINE_TABLE_BITS) // 22
#define SCALE_FACTOR_FLOAT 32767.0f // Ou autre max pour votre table

// Déclaration nécessaire
extern const int16_t sineTable[1024];

enum ADSR_State { ATTACK, DECAY, SUSTAIN, RELEASE, IDLE };

struct Note {
    float frequency;
    uint32_t phase[3];
    uint32_t phaseInc[3]; // <--- On stocke l'incrément ici
    bool active;
    bool releasing;
    float currentLevel;
    int midiNote;
    ADSR_State state = IDLE;
};

bool FLAG = false;
int64_t t0 = 0;
int64_t dt = 0;

//Objet
Note activeNotes[MAX_NOTES];

// Fonction pour calculer la fréquence MIDI (note 60 = 261.63 Hz pour Do4)
float ORPHEA::midiToFrequency(int midiNote) 
{
  return 440.0 * pow(2.0, (midiNote - 69) / 12.0);
}


void ORPHEA::addNote(int midiNote) {
    for (int i = 0; i < MAX_NOTES; i++) {
        if (!activeNotes[i].active && !activeNotes[i].releasing) {
            activeNotes[i].midiNote = midiNote;
            float freq = midiToFrequency(midiNote);
            activeNotes[i].frequency = freq;
            
            // Pré-calcul pour les harmoniques
            for (int h = 0; h < 3; h++) {
                activeNotes[i].phase[h] = 0;
                // Calcul de l'incrément une bonne fois pour toutes
                activeNotes[i].phaseInc[h] = (uint32_t)((freq * (h + 1) * 4294967296.0f) / I2S_SAMPLE_RATE);
            }
            
            activeNotes[i].active = true;
            activeNotes[i].releasing = false;
            activeNotes[i].state = ATTACK;
            activeNotes[i].currentLevel = 0.0f;
            break;
        }
    }
}

void ORPHEA::removeNote(int midiNote) {
  for (int i = 0; i < MAX_NOTES; i++) {
    if (activeNotes[i].midiNote == midiNote && activeNotes[i].active) {
      activeNotes[i].active = false;
      activeNotes[i].releasing = true;
      activeNotes[i].state = RELEASE; // Passe en release
      break;
    }
  }
}

int16_t ORPHEA::generateSample() {
    float mixedSample = 0.0f;
    
    const float attackStep  = 0.005f;  // Plus grand = attaque plus rapide
    const float decayStep   = 0.0002f; // Vitesse de descente vers sustain
    const float sustainLevel = 0.5f;   // Volume maintenu tant que la touche est pressée
    const float releaseStep = 0.9997f; // Ton releaseRate actuel

    for (int i = 0; i < MAX_NOTES; i++) {
        if (activeNotes[i].state != IDLE) {
            float noteSample = 0.0f;

            // --- CALCUL DE L'ENVELOPPE ADSR ---
            if (activeNotes[i].active) {
                if (activeNotes[i].state == ATTACK) {
                    activeNotes[i].currentLevel += attackStep;
                    if (activeNotes[i].currentLevel >= 1.0f) {
                        activeNotes[i].currentLevel = 1.0f;
                        activeNotes[i].state = DECAY;
                    }
                } else if (activeNotes[i].state == DECAY) {
                    activeNotes[i].currentLevel -= decayStep;
                    if (activeNotes[i].currentLevel <= sustainLevel) {
                        activeNotes[i].currentLevel = sustainLevel;
                        activeNotes[i].state = SUSTAIN;
                    }
                }
            } else if (activeNotes[i].releasing) {
                activeNotes[i].currentLevel *= releaseStep;
                if (activeNotes[i].currentLevel < 0.001f) {
                    activeNotes[i].state = IDLE;
                    activeNotes[i].releasing = false;
                    continue;
                }
            }

            // --- SYNTHÈSE ADDITIVE (Utilisant les phaseInc pré-calculés) ---
            const float amps[3] = {0.60f, 0.30f, 0.10f}; 
            
            for (int h = 0; h < 2; h++) {
                // On utilise directement l'incrément stocké
                int index = activeNotes[i].phase[h] >> SINE_TABLE_SHIFT;
                float sineVal = (float)sineTable[index] / 32767.0f;
                
                noteSample += sineVal * amps[h];
                activeNotes[i].phase[h] += activeNotes[i].phaseInc[h]; // Gain CPU majeur ici
            }

            mixedSample += noteSample * activeNotes[i].currentLevel;
        }
    }
    
    mixedSample *= 0.25f; 
    return (int16_t)(mixedSample * 32767.0f);
}

// Fonction principale pour traiter les commandes MIDI et jouer la musique
void ORPHEA::playMidiNote(uint8_t status, uint8_t data1, uint8_t data2) {
  if(LATENCY_CHECK)
      {
        FLAG = true;
        t0 = esp_timer_get_time();
      }
  if (status == 0x90 && data2 > 0) {  // Note On
    addNote(data1);
  } else if (status == 0x80 || (status == 0x90 && data2 == 0)) {  // Note Off
    removeNote(data1);
  }
  // Ajoute d'autres commandes MIDI si besoin (velocity, pitch bend)
}

// Tâche pour la réception MIDI et génération audio (exécutée sur core 0)
void ORPHEA::midiAudioTask(void *pvParameters) 
{
  Serial1.begin(MIDI_BAUDRATE, SERIAL_8N1, RX_PIN, TX_PIN); 
  int16_t buffer[BUFFER_SIZE * 2];  // Buffer pour stéréo (2 canaux)
  while (true) {
    // Lecture des données série (MIDI) 
    if (Serial1.available() >= 3) 
    {
      if(LATENCY_CHECK)
      {
        FLAG = true;
        t0 = esp_timer_get_time();
      }
      uint8_t status = Serial1.read();// 0x90 ou 0x80
      uint8_t data1 = Serial1.read();//  note(0-127)
      uint8_t data2 = Serial1.read();//  velocity(0-127) -> 0 = note off
      if (status >= 0x80) {
        playMidiNote(status, data1, data2);
      }
    }
   
    // Générer un bloc d'échantillons
    for (int i = 0; i < BUFFER_SIZE; i++) {
      int16_t sample = generateSample();
      buffer[i * 2] = sample;     // Canal gauche
      buffer[i * 2 + 1] = sample; // Canal droite
    }

    // Écrire le bloc entier sur I2S
    size_t bytes_written;
    i2s_write(I2S_NUM, buffer, sizeof(buffer), &bytes_written, portMAX_DELAY);
    // Yield et délai pour le scheduler/watchdog
    if(LATENCY_CHECK && FLAG) {
        dt = esp_timer_get_time() - t0;
        Serial.printf("Latence: %lld µs\n", dt);
        FLAG = false;
    }
    taskYIELD();
   // vTaskDelay(1);  // Délai minimal
  }
}

void ORPHEA::createTaskMidiAudio()
{

    // Initialiser les notes actives
  for (int i = 0; i < MAX_NOTES; i++) {                      // Initialiser les notes actives
    activeNotes[i].active = false;
  }

  // Configuration I2S (buffers plus grands pour fluidité)
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = I2S_SAMPLE_RATE,
    .bits_per_sample = I2S_BITS,
    .channel_format = I2S_CHANNELS,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 128,  // Augmenté pour moins d'interruptions
    .use_apll = false,
    .tx_desc_auto_clear = true,
    .fixed_mclk = 0
  };
  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCK_IO,
    .ws_io_num = I2S_WS_IO,
    .data_out_num = I2S_DO_IO,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM, &pin_config);
  i2s_zero_dma_buffer(I2S_NUM);

   xTaskCreatePinnedToCore(
        [](void*) {
        ORPHEA myOrphea;
        myOrphea.midiAudioTask(nullptr);
        },
        "MidiAudioTask",
        4096,       // stack size en bytes
        NULL,       // paramètre
        20,          // priorité haute
        NULL,       //  handle
        1           // Core 1
    );
}