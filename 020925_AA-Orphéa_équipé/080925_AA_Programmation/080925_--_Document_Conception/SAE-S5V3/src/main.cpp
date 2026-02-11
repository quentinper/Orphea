/***************************************************************
 * @file        main.cpp
 * @author      Lorenzo S. & Quentin P. & William L-C
 * @version     1
 * @date        2026-01-24
 * @brief       Gestion du système audio ORPHEA.
 * @details     SAE S5-S6 BUG GEII FA ESE
 * @copyright   (c)  Lorenzo S. & Quentin P. & William L-C - Tous droits réservés
 ***************************************************************/

#include <Arduino.h>
#include <CONFWIFI.h>
#include <SECURITY.h>
#include <ORPHEA.h>
#include <SSD1306.h>

// Screen adress
#define SSD1306_ADR 0x3C

// Activer les messages de debug
bool DEBUG = 0; // Activer les messages de debug
bool SETUP = 1; // Activer les messages de trace
bool ERROR = 0; // Activer les messages d'erreur
bool LATENCY_CHECK = 0;

// Création des objets
CONFWIFI myWiFi;
SECURITY mySecurity;
ORPHEA myOrphea;
SSD1306 mySSD1306;

// Configuration initiale
void setup() 
{
  setCpuFrequencyMhz(240);                                   // Maximiser la fréquence CPU pour la génération audio
  Serial.begin(115200);                                      // Initialiser la communication série pour le debug
  myOrphea.createTaskMidiAudio();                            // Initialiser la tâche audio MIDI
  mySecurity.createTaskCheckVoltages();                      // Initialiser la tâche de vérification des tensions
  myWiFi.wifi_begin();                                       // Initialiser le module WiFi
  mySSD1306.beginOLED(SSD1306_ADR);                          // Initialiser l'écran OLED
}

// Boucle principale vide (tout est géré dans la tâche)
void loop()
{
  delay(100);
}
