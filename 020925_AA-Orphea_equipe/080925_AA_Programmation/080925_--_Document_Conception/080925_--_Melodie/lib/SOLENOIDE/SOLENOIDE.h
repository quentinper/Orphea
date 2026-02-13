/***************************************************************
 * @file        AHT20.h
 * @author      Lorenzo S. & Quentin P.
 * @version     2
 * @date        2025-05-19
 * @brief       Gestion du capteur d'humidité.
 * @details     SAE S4 BUG GEII FA ESE
 * @copyright   (c) Lorenzo S. & Quentin P.- Tous droits réservés
 ***************************************************************/
#ifndef SOLENOIDE_H
#define SOLENOIDE_H

#include <Arduino.h>

/*Définition pin Solenoide pour les 2 octaves*/

#define DO_OCTAVE_1 32
#define DO_OCTAVE_2 33

#define RE_OCTAVE_1 34
#define RE_OCTAVE_2 35

#define MI_OCTAVE_1 36
#define MI_OCTAVE_2 37

#define FA_OCTAVE_1 38
#define FA_OCTAVE_2 39

#define SOL_OCTAVE_1 40
#define SOL_OCTAVE_2 41

#define LA_OCTAVE_1 42
#define LA_OCTAVE_2 43

#define SI_OCTAVE_1 44
#define SI_OCTAVE_2 45

class SOLENOIDE
{
public:
    SOLENOIDE();
    void detectionAutomatedMode();
    void automatedMode(uint8_t melodie);
    int detectionSolenoide(int freq);

private:
    uint8_t _melodie = 0;
    uint8_t _octave = 0;
    int _freq = 0;
    // int detectionSolenoide(int freq);
};

#endif