#include <GESTNOTES.h>
// Exemple de broches (ajustez selon votre carte)

GESTNOTES::GESTNOTES()
{
  _now = 0;
  _idx3Glob = 0;
  _resAccords = 0;
  _notesNumber = 0;
  _notesNumber = 0;
  _buttonPins[12];
  _risingEdgeDetected[12] = {false};
  _fallingEdgeDetected[12] = {false};
  _lastButtonStates[12] = {HIGH}; // État précédent de chaque bouton (HIGH par défaut avec pull-up)
  for (int i = 0; i < 12; i++)
  {
    _notesPlayed[i] = 0;
    _previousNotesPlayed[i] = 0;
  }
}

void GESTNOTES::initSol(uint8_t notesStart, uint8_t notesNumber)
{
  _notesStart = notesStart;
  _notesNumber = notesNumber;

  for (int idx5 = _notesStart; idx5 <= ((_notesNumber - 1) * 2) + _notesStart; idx5 += 2)
  {
    int idx1 = 0;
    _buttonPins[idx1] = idx5;
    pinMode(_buttonPins[idx1], INPUT);
  }
}

int GESTNOTES::getNote(int i)
{
  {
    // Décalage MIDI constant (Offset).
    // Si l'index 0 correspond à la note 61, l'offset est 61.
    const int MIDI_OFFSET = 61;

    // Vérifie si l'index est dans la plage de 0 à 23.
    if (i >= 0 && i <= 23)
    {
      // Calcul direct : Note MIDI = Index + Décalage
      // Exemple : i=0 => 0 + 61 = 61
      // Exemple : i=23 => 23 + 61 = 84
      return i + MIDI_OFFSET;
    }

    // Retourne 0 si l'index est invalide (bonne pratique pour les erreurs/valeur par défaut)
    return 0;
  }
  // ---- Fonctions d'envoi MIDI ----
}

void GESTNOTES::gestionAccord()
{

  // Scrutation logicielle pour détecter les fronts
  for (int i = 0; i < _notesNumber; i++)
  {
    bool currentState = digitalRead(_buttonPins[i]);

    if (_lastButtonStates[i] == LOW && currentState == HIGH)
    {
      _risingEdgeDetected[i] = true;
    }
    else if (_lastButtonStates[i] == HIGH && currentState == LOW)
    {
      _fallingEdgeDetected[i] = true;
    }

    _lastButtonStates[i] = currentState;
  }

  // Traitement des détections dans la boucle principale
  for (int i = 0; i < _notesNumber; i++)
  {
    if (_risingEdgeDetected[i])
    {
      int strg = getNote(i);
      Serial1.write(0x90);
      Serial1.write(strg);
      Serial1.write(100);
      Serial.write(0x90);
      Serial.write(strg);
      Serial.write(100);
      _risingEdgeDetected[i] = false;
    }

    if (_fallingEdgeDetected[i])
    {
      int strg = getNote(i);
      Serial1.write(0x80);
      Serial1.write(strg);
      Serial1.write((byte)0);
      Serial.write(0x80);
      Serial.write(strg);
      Serial.write((byte)0);
      _fallingEdgeDetected[i] = false;
    }
  }

  delay(10); // Petit délai pour éviter le rebond (debouncing simple), ajustez si nécessaire
}
