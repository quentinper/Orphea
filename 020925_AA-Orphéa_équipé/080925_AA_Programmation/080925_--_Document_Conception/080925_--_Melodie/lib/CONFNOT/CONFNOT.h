#ifndef CONFNOT_H
#define CONFNOT_H

#define ATTACK_TIME 0.05f   // Temps d'attaque (montée rapide)
#define DECAY_TIME 0.5f    // Temps de décroissance
#define SUSTAIN_LEVEL 0.3f // Niveau de sustain (0-1)
#define RELEASE_TIME 0.1f  // Temps de relâchement

#define REST 0
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

float notes[] = {262.0, 294.0, 330.0, 349.0, 392.0, 440.0, 494.0, 523.0};


// --- PIRATES DES CARAIBES ---

const int pirateDesCaraibesNotes[] PROGMEM = {
		NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
		NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
		NOTE_A4, NOTE_G4, NOTE_A4, 0,
		NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
		NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
		NOTE_A4, NOTE_G4, NOTE_A4, 0,
		NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
		NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
		NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
		NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
		NOTE_D5, NOTE_E5, NOTE_A4, 0, 
		NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
		NOTE_C5, NOTE_A4, NOTE_B4, 0,
		NOTE_A4, NOTE_A4, 
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
		NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
		NOTE_A4, NOTE_G4, NOTE_A4, 0,
		NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
		NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
		NOTE_A4, NOTE_G4, NOTE_A4, 0,
		NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
		NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
		NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
		NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
		NOTE_D5, NOTE_E5, NOTE_A4, 0, 
		NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
		NOTE_C5, NOTE_A4, NOTE_B4, 0,
		NOTE_E5, 0, 0, NOTE_F5, 0, 0,
		NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5,0, 0,
		NOTE_D5, 0, 0, NOTE_C5, 0, 0,
		NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,
		NOTE_E5, 0, 0, NOTE_F5, 0, 0,
		NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
		NOTE_D5, 0, 0, NOTE_C5, 0, 0,
		NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};
const int pirateDesCaraibesDuree[] PROGMEM ={
        250, 250, 500, 250, 250, 
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 750, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 750, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 250, 500, 250,
        250, 250, 500, 250, 250,
        500, 250, 500, 250,
        250, 250, 500, 250, 250,
        250, 250, 750, 750,
        500, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 750, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 750, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 500, 250, 250,
        250, 250, 250, 500, 250,
        250, 250, 500, 250, 250,
        500, 250, 500, 250,
        250, 250, 500, 250, 250,
        250, 250, 750, 750,
        500, 250, 750, 500, 250, 750,
        250, 250, 250, 250, 250, 250, 250, 250, 750,
        500, 250, 750, 500, 250, 750,
        250, 250, 250, 250, 250, 1000,
        500, 250, 750, 500, 250, 750,
        250, 250, 250, 250, 250, 250, 250, 250, 750,
        500, 250, 750, 500, 250, 750,
        250, 250, 250, 250, 250, 1000
};

// --- GAMES OF TRONES ---

const int gamesOfTroneNotes[] PROGMEM = {
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_C4,
  
  NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_D4,
  NOTE_F4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_C4,
  
  NOTE_G4, NOTE_C4,
  
  NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_D4,
  NOTE_F4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_C4,
  NOTE_G4, NOTE_C4,
  NOTE_DS4, NOTE_F4, NOTE_G4,  NOTE_C4, NOTE_DS4, NOTE_F4,
  
  NOTE_D4,
  NOTE_F4, NOTE_AS3,
  NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_AS3,
  NOTE_C4,
  NOTE_C5,
  NOTE_AS4,
  NOTE_C4,
  NOTE_G4,
  NOTE_DS4,
  NOTE_DS4, NOTE_F4,
  NOTE_G4,
  
  NOTE_C5,
  NOTE_AS4,
  NOTE_C4,
  NOTE_G4,
  NOTE_DS4,
  NOTE_DS4, NOTE_D4,
  NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4,
  NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4,
  
  NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5,
  NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5
};
const int gamesOfTroneDuree[] PROGMEM = {
  250, 250, 125, 125, 250, 250, 125, 125,
  250, 250, 125, 125, 250, 250, 125, 125,
  250, 250, 125, 125, 250, 250, 125, 125,
  250, 250, 125, 125, 250, 250, 125, 125,
  500, 500,
  
  125, 125, 500, 500, 125, 125,
  2000,
  500, 500,
  125, 125, 500, 500,
  125, 125, 2000,
  
  500, 500,
  
  125, 125, 500, 500, 125, 125,
  2000,
  500, 500,
  125, 125, 500, 500,
  125, 125, 2000,
  500, 500,
  125, 125, 500, 500, 125, 125,
  
  1000,
  500, 500,
  250, 250, 250, 250,
  2000,
  1000,
  1000,
  1000,
  1000,
  1000,
  500, 500,
  2000,
  
  1000,
  1000,
  1000,
  1000,
  1000,
  500, 500,
  250, 250, 125, 125, 250, 250, 125, 125,
  250, 250, 125, 125, 250, 250, 125, 125,
  
  500, 125, 125, 250, 250, 125, 125,
  250, 125, 125, 125, 250, 250, 125, 125
};

// --- STAR WARS ---

const int starWarsNotes[] PROGMEM = {
 NOTE_AS3, NOTE_AS3, NOTE_AS3,
  NOTE_F4, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F5, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F5, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_F4, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F5, NOTE_C5,

  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F5, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_G4, NOTE_C4, NOTE_C4,
  NOTE_D4, NOTE_D4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_C4,
  NOTE_D4, NOTE_D4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,

  NOTE_C5, NOTE_G4, NOTE_G4, NOTE_C4,
  NOTE_D4, NOTE_D4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_C5, NOTE_C5,
  NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_F4,
  NOTE_C5
};
const int starWarsDuree[] PROGMEM = {
  250,250,250,
  1000,1000,
  250,250,250,1000,500,
  250,250,250,1000,500,
  250,250,250,1000,250,250,250,
  1000,1000,
  250,250,250,1000,500,

  250,250,250,1000,500,
  250,250,250,1000,250,124,
  500,250,250,250,250,250,
  250,250,250,500,250,500,250,124,
  500,250,250,250,250,250,

  250,124,1000,250,250,
  500,250,250,250,250,250,
  250,250,250,500,250,500,250,124,
  500,250,500,250,500,250,500,250,
  2000
};

// --- PANTER ROSE ---

const int panterRoseNotes[] PROGMEM = {
  0, 0, 0, NOTE_DS4, 
  NOTE_E4, 0, NOTE_FS4, NOTE_G4, 0, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
  NOTE_E4, 0, 0, NOTE_DS4,
  
  NOTE_E4, 0, NOTE_FS4, NOTE_G4, 0, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_E5,
  NOTE_DS5,   
  NOTE_D5, 0, 0, NOTE_DS4, 
  NOTE_E4, 0, NOTE_FS4, NOTE_G4, 0, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
  
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
  NOTE_E4, 0,
  0, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4,   
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4
};
const int panterRoseDuree[] PROGMEM = {
  1000, 500, 250, 250,
  500, 250, 250, 500, 250, 250,
  250, 250, 250, 250, 250, 250, 250, 250,
  1000, 125, 125, 125, 125,
  1000, 500, 250, 500,
  
  500, 250, 250, 500, 250, 250,
  250, 250, 250, 250, 250, 250, 250, 250,
  2000,
  1000, 500, 250, 250,
  500, 250, 250, 500, 250, 250,
  250, 250, 250, 250, 250, 250, 250, 250,
  
  1000, 125, 125, 125, 125,
  500, 500,
  500, 250, 250, 250, 250, 250, 250,
  125, 250, 125, 250, 125, 250, 125, 250,
  125, 125, 125, 125, 125, 1000
};

// --- HARRY POTTER ---

const int harryPotterNotes[] PROGMEM = {
  0, NOTE_D4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_C5, 
  NOTE_A4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_F4, NOTE_GS4,
  NOTE_D4, 
  NOTE_D4,
  
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_B4,
  NOTE_G4,
  NOTE_AS4,
   
  NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_AS4,
  NOTE_DS5, NOTE_D5,
  NOTE_CS5, NOTE_A4,
  NOTE_AS4, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_D4,
  NOTE_D5, 
  0, NOTE_AS4,  
  
  NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_AS4,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_AS4,
  NOTE_G4
};
const int harryPotterDuree[] PROGMEM = {
	1000, 500,
  500, 250, 500,
  1000, 500,
  1000,
  1000,
  500, 250, 500,
  1000, 500,
  2000,
  500,
  
  500, 250, 500,
  1000, 500,
  1000, 500,
  1000, 500,
  500, 250, 500,
  1000, 500,
  2000,
  500,
  
  1000, 500,
  1000, 500,
  1000, 500,
  1000, 500,
  500, 250, 500,
  1000, 500,
  2000,
  500, 500,
  
  1000, 500,
  1000, 500,
  1000, 500,
  1000, 500,
  500, 250, 500,
  1000, 500,
  2000
};

const int maintenanceNotes[] PROGMEM = {
NOTE_C1,NOTE_D1,NOTE_E1,NOTE_F1,NOTE_G1
};

const int maintenanceDuree[] PROGMEM = {
1000,1000,1000,1000,1000
};

const int numNotesPiratesDesCaraibes = sizeof(pirateDesCaraibesNotes) / sizeof(pirateDesCaraibesNotes[0]);
const int numNotesGamesOfTrone       = sizeof(gamesOfTroneNotes)       / sizeof(gamesOfTroneNotes[0]);
const int numNotesStarWars       = sizeof(starWarsNotes)       / sizeof(starWarsNotes[0]);
const int numNotesPanterRose       = sizeof(panterRoseNotes)       / sizeof(panterRoseNotes[0]);
const int numNotesHarryPotter       = sizeof(harryPotterNotes)       / sizeof(harryPotterNotes[0]);
const int numNotesMaintenance       = sizeof(maintenanceNotes)       / sizeof(maintenanceNotes[0]);

int16_t *BuffersPiratesDesCaraibes[numNotesPiratesDesCaraibes];
int16_t *BuffersGamesOfTrone[numNotesGamesOfTrone];
int16_t *BuffersStarWars[numNotesStarWars];
int16_t *BuffersPanterRose[numNotesPanterRose];
int16_t *BuffersHarryPotter[numNotesHarryPotter];
int16_t *BuffersMaintenance[numNotesMaintenance];

const int melodieLen = 7;

int NumNotesMelodie[melodieLen] ={
    numNotesPiratesDesCaraibes,
    numNotesGamesOfTrone,
	numNotesStarWars,
	numNotesPanterRose,
	numNotesHarryPotter,
  numNotesMaintenance
};

const int *choixMelodie[melodieLen] ={
    pirateDesCaraibesNotes,
    gamesOfTroneNotes,
	starWarsNotes,
	panterRoseNotes,
	harryPotterNotes,
  maintenanceNotes

};

const int *choixMelodieDuree[melodieLen] ={
    pirateDesCaraibesDuree,
    gamesOfTroneDuree,
	starWarsDuree,
	panterRoseDuree,
	harryPotterDuree,
  maintenanceDuree,
};

int16_t **choixTailleBuffer[melodieLen] ={
    BuffersPiratesDesCaraibes,
    BuffersGamesOfTrone,
	BuffersStarWars,
	BuffersPanterRose,
	BuffersHarryPotter,
  BuffersMaintenance
};


const int numNotesTest = sizeof(notes) / sizeof(notes[0]);

float harmonicMultipliers[7] = {1, 2, 3, 4, 5, 6, 7};
float amplitudes[7] = {0.45, 0.32, 0.02, 0.07, 0.04, 0.02, 0.05};

// --- Accords majeurs (7 accords) ---
float chords[7][3] = {
		{262.0, 330.0, 392.0}, // DO majeur (C)
		{294.0, 370.0, 440.0}, // RÉ majeur (D)
		{330.0, 415.0, 494.0}, // MI majeur (E)
		{349.0, 440.0, 523.0}, // FA majeur (F)
		{392.0, 494.0, 587.0}, // SOL majeur (G)
		{440.0, 554.0, 659.0}, // LA majeur (A)
		{494.0, 622.0, 740.0}  // SI majeur (B)
};
const int numChords = 7;

// --- Mélodie "La souris verte" (notes et accords associés, durées en secondes)
// ---
struct MelodyNote {
	float freq;     // Fréquence de la note mélodique
	float chord[3]; // Accord de fond (3 notes)
	float duration; // Durée en secondes
};

MelodyNote melody[] = 
{
		{NOTE_E4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},  // Dm
		{NOTE_G4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.250},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_B4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_C5, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.250},
		{NOTE_C5, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_C5, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_D5, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_B4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.250},
		{NOTE_B4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_G4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.375},
		{NOTE_E4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},  // Dm
		{NOTE_G4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.250},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_B4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_C5, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.250},
		{NOTE_C5, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_C5, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_D5, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_B4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.250},
		{NOTE_B4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_G4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.375},
		{NOTE_E4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},  // Dm
		{NOTE_G4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.250},
		{NOTE_A4, {NOTE_D4, NOTE_F4, NOTE_A4}, 0.125},
};

const int melodyLength = sizeof(melody) / sizeof(melody[0]);

// --- Buffers PSRAM ---

int16_t *noteTestBuffers[numNotesTest];
int16_t *chordBuffers[numChords];
int16_t *melodyBuffers[melodyLength]; // Buffers pour chaque note de la mélodie

#endif