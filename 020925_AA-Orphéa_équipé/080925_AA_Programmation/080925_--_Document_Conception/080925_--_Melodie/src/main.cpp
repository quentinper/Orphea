#include <Arduino.h>
#include <SOLENOIDE.h>
// #include "CONFNOT.h"
#include <GESTNOTES.h>

SOLENOIDE mySolenoide;
GESTNOTES myGestNotes;

// Code Arduino pour détecter les fronts montants et descendants sur 24 boutons
// Utilise le polling (scrutation logicielle) car les interruptions matérielles sont limitées (seulement 2 sur Uno)
// Adapté pour un Arduino Mega (qui a plus de broches) ou utilisez des registres à décalage pour étendre les entrées

#define NUM_BUTTONS 24
#define NOTE_1  26
#define NOTE_2  27
#define NOTE_3  28
#define NOTE_4  29
#define NOTE_5  30
#define NOTE_6  31
#define NOTE_7  32
#define NOTE_8  33
#define NOTE_9  34
#define NOTE_10 35
#define NOTE_11 36
#define NOTE_12 37
#define NOTE_13 38
#define NOTE_14 39
#define NOTE_15 40
#define NOTE_16 41
#define NOTE_17 42
#define NOTE_18 43
#define NOTE_19 44
#define NOTE_20 45
#define NOTE_21 46
#define NOTE_22 47
#define NOTE_23 48
#define NOTE_24 49


const int buttonPins[NUM_BUTTONS] = 
{
  NOTE_1, NOTE_2, NOTE_3, NOTE_4, NOTE_5, NOTE_6, NOTE_7, NOTE_8, NOTE_9, NOTE_10, 
  NOTE_11, NOTE_12, NOTE_13, NOTE_14, NOTE_15, NOTE_16, NOTE_17, NOTE_18, NOTE_19, 
  NOTE_20, NOTE_21, NOTE_22, NOTE_23, NOTE_24
}; // Exemple de broches (ajustez selon votre carte)

volatile bool risingEdgeDetected[NUM_BUTTONS] = {false};
volatile bool fallingEdgeDetected[NUM_BUTTONS] = {false};
bool lastButtonStates[NUM_BUTTONS] = {HIGH}; // État précédent de chaque bouton (HIGH par défaut avec pull-up)
bool DEBUG = false;
int getNote(int i);
void setup()
{
  Serial.begin(115200);
  Serial1.begin(31250);
  Serial.println("Initialisation...");
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP); // Configuration en entrée avec pull-up interne
  }
}

void loop()
{
  // Scrutation logicielle pour détecter les fronts
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    bool currentState = digitalRead(buttonPins[i]);
    if(DEBUG)
    {
      for(int i = 0 ; i < NUM_BUTTONS; i++)
      {
        risingEdgeDetected[i] = true;
        if (risingEdgeDetected[i])
        {
          int strg = getNote(i);
          Serial1.write(0x90);
          Serial1.write(strg);
          Serial1.write(100);
          Serial.write(0x90);
          Serial.write(strg);
          Serial.write(100);
        }
        delay(1000);
        fallingEdgeDetected[i] = true;
        if (fallingEdgeDetected[i])
        {
          int strg = getNote(i);
          Serial1.write(0x80);
          Serial1.write(strg);
          Serial1.write((byte)0);
          Serial.write(0x80);
          Serial.write(strg);
          Serial.write((byte)0);
          fallingEdgeDetected[i] = false;
        }
      }
    }
    if (lastButtonStates[i] == LOW && currentState == HIGH)
    {
      risingEdgeDetected[i] = true;
    }
    else if (lastButtonStates[i] == HIGH && currentState == LOW)
    {
      fallingEdgeDetected[i] = true;
    }

    lastButtonStates[i] = currentState;
  }

  // Traitement des détections dans la boucle principale
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    if (risingEdgeDetected[i])
    {
      int strg = getNote(i);
      Serial1.write(0x90);
      Serial1.write(strg);
      Serial1.write(100);
      Serial.write(0x90);
      Serial.write(strg);
      Serial.write(100);
      risingEdgeDetected[i] = false;
    }

    if (fallingEdgeDetected[i])
    {

      int strg = getNote(i);
      Serial1.write(0x80);
      Serial1.write(strg);
      Serial1.write((byte)0);
      Serial.write(0x80);
      Serial.write(strg);
      Serial.write((byte)0);
      fallingEdgeDetected[i] = false;
    }
  }

  delay(10); // Petit délai pour éviter le rebond (debouncing simple), ajustez si nécessaire
}

int getNote(int i)
{
  {
    // Décalage MIDI constant (Offset).
    // Si l'index 0 correspond à la note 61, l'offset est 61.
    const int MIDI_OFFSET = 84;

    // Vérifie si l'index est dans la plage de 0 à 23.
    if (i >= 0 && i <= 23)
    {
      // Calcul direct : Note MIDI = Index + Décalage
      // Exemple : i=0 => 0 + 61 = 61
      // Exemple : i=23 => 23 + 61 = 84
      return MIDI_OFFSET - i;
    }

    // Retourne 0 si l'index est invalide (bonne pratique pour les erreurs/valeur par défaut)
    return 0;
  }
  // ---- Fonctions d'envoi MIDI ----
}
