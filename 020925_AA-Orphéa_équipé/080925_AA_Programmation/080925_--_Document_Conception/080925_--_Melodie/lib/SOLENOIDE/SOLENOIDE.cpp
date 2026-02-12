/***************************************************************
 * @file        AHT20.cpp
 * @author      Lorenzo S. & Quentin P.
 * @version     2
 * @date        2025-05-19
 * @brief       Gestion du capteur d'humiditÃ©.
 * @details     SAE S4 BUG GEII FA ESE
 * @copyright   (c) Lorenzo S. & Quentin P.- Tous droits rÃ©servÃ©s
 ***************************************************************/
#include <Arduino.h>
#include <SOLENOIDE.h>
#include "CONFNOT.h"

extern volatile int numNotes;
String input = "";
bool flag = false;

SOLENOIDE::SOLENOIDE()
{
    _octave = 0;
    _melodie = 0;
    _freq = 0;
}

void SOLENOIDE::detectionAutomatedMode()
{
    if (Serial1.available() && !flag)
    {
        String recu = Serial1.readStringUntil('\n');
        Serial.println("Recu : " + recu);

        if (recu == "MODE=2,MELODIE=6")
        {
            Serial.println("Mode automatisé activé pour la mélodie ");
            flag = true;
            automatedMode(5);
        }
    }
}

void SOLENOIDE::automatedMode(uint8_t melodie)
{
    _melodie = melodie;
    Serial.println("OK");
    while (numNotes < NumNotesMelodie[_melodie]) // <-- utilisation du compteur ISR
    {
        int index = numNotes; // plus lisible
        int freq = pgm_read_word(&(choixMelodie[_melodie][index]));
        float duree = pgm_read_word(&(choixMelodieDuree[_melodie][index]));
        float noteDuration = duree;
        int solenoide = detectionSolenoide(freq);
        digitalWrite(solenoide, HIGH);
        delay(noteDuration);
        digitalWrite(solenoide, LOW);
    }
    flag = false;
    Serial.println("END");
}

int SOLENOIDE::detectionSolenoide(int freq)
{

    _freq = freq;
    // ---- OCTAVE 1 ----
    // ---- DO ----
    if (_freq == NOTE_B1 || _freq == NOTE_B2 || _freq == NOTE_B3 || _freq == NOTE_B4)
        return DO_OCTAVE_1;
    // ---- RE ----
    if (_freq == NOTE_C1 || _freq == NOTE_C2 || _freq == NOTE_C3 || _freq == NOTE_C4)
        return RE_OCTAVE_1;
    // ---- MI ----
    if (_freq == NOTE_D1 || _freq == NOTE_D2 || _freq == NOTE_D3 || _freq == NOTE_D4)
        return MI_OCTAVE_1;
    // ---- FA ----
    if (_freq == NOTE_E1 || _freq == NOTE_E2 || _freq == NOTE_E3 || _freq == NOTE_E4)
        return FA_OCTAVE_1;
    // ---- SOL ----
    if (_freq == NOTE_F1 || _freq == NOTE_F2 || _freq == NOTE_F3 || _freq == NOTE_F4)
        return SOL_OCTAVE_1;
    // ---- LA ----
    if (_freq == NOTE_G1 || _freq == NOTE_G2 || _freq == NOTE_G3 || _freq == NOTE_G4)
        return DO_OCTAVE_1;
    // ---- SI ----
    if (_freq == NOTE_A1 || _freq == NOTE_A2 || _freq == NOTE_A3 || _freq == NOTE_A4)
        return RE_OCTAVE_1;

    // ---- OCTAVE 2 ----

    // ---- D0 ----
    if (_freq == NOTE_B5 || _freq == NOTE_B6 || _freq == NOTE_B7)
        return DO_OCTAVE_1;
    // ---- RE ----
    if (_freq == NOTE_C5 || _freq == NOTE_C6 || _freq == NOTE_C7)
        return RE_OCTAVE_1;
    // ---- MI ----
    if (_freq == NOTE_D5 || _freq == NOTE_D6 || _freq == NOTE_D7)
        return MI_OCTAVE_1;
    // ---- FA ----
    if (_freq == NOTE_E5 || _freq == NOTE_E6 || _freq == NOTE_E7)
        return FA_OCTAVE_1;
    // ---- SOL ----
    if (_freq == NOTE_F5 || _freq == NOTE_F6 || _freq == NOTE_F7)
        return SOL_OCTAVE_1;
    // ---- LA ----
    if (_freq == NOTE_G5 || _freq == NOTE_G6 || _freq == NOTE_G7)
        return DO_OCTAVE_1;
    // ---- SI ----
    if (_freq == NOTE_A5 || _freq == NOTE_A6 || _freq == NOTE_A7)
        return RE_OCTAVE_1;

    return 0;
}