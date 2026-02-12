/***************************************************************
 * @file        ORPHEA.h
 * @author      Lorenzo S. & Quentin P. & William L-C
 * @version     1
 * @date        2026-01-24
 * @brief       Gestion du système audio ORPHEA.
 * @details     SAE S5-S6 BUG GEII FA ESE
 * @copyright   (c) Lorenzo S. & Quentin P. & William L-C - Tous droits réservés
 ***************************************************************/

#ifndef ORPHEA_H
#define ORPHEA_H

#include <Arduino.h>
#include <driver/i2s.h>
#include <esp_heap_caps.h>
#include <math.h>
#include "SIN.h"
#include <stdint.h>
#include <stdbool.h>

extern bool DEBUG;
extern bool SETUP;
extern bool ERROR;
extern bool LATENCY_CHECK;

class ORPHEA
{
public:
    // constructor
    ORPHEA();
    float midiToFrequency(int midiNote);
    void addNote(int midiNote);
    void removeNote(int midiNote);
    int16_t generateSample();
    void playMidiNote(uint8_t status, uint8_t data1, uint8_t data2);
    void midiAudioTask(void *pvParameters);
    void createTaskMidiAudio();

private:
};

#endif