#ifndef GESTNOTES_H
#define GESTNOTES_H

#include <Arduino.h>

class GESTNOTES
{
public:
    GESTNOTES();
    void initSol(uint8_t notesStart, uint8_t notesNumber);
    void gestionAccord();

private:
    unsigned long _now;
    int _idx3Glob;
    int _resAccords;
    uint8_t _notesNumber;
    uint8_t _notesStart;
    uint8_t _notesPlayed[12];
    uint8_t _previousNotesPlayed[12];
    // void _readSol(uint8_t notes[12]);
    void sendNoteOff(byte note);
    void sendNoteOn(byte note, byte velocity);
    int getNote(int i);
    int _buttonPins[12];
    volatile bool _risingEdgeDetected[12];
    volatile bool _fallingEdgeDetected[12];
    bool _lastButtonStates[12] = {HIGH}; // État précédent de chaque bouton (HIGH par défaut avec pull-up)
};
#endif