/***************************************************************
 * @file        SECURITY.cpp
 * @author      Lorenzo S. & Quentin P. & William L-C
 * @version     1
 * @date        2026-01-24
 * @brief       Gestion des Securité de ORPHEA.
 * @details     SAE S5-S6 BUG GEII FA ESE
 * @copyright   (c)  Lorenzo S. & Quentin P. & William L-C - Tous droits réservés
 ***************************************************************/

#include <SECURITY.h>

SECURITY::SECURITY()
{
  
}

Adafruit_NeoPixel led(1, 48, NEO_GRB + NEO_KHZ800);

/*************************************************************************************************
 * @brief Crée une tâche de vérification des tensions sur les broches analogiques.
 *        Cette tâche est exécutée sur le core 1 et vérifie si les tensions sont inférieures à 3.1V.
 **************************************************************************************************/
void SECURITY::createTaskCheckVoltages()
{
  xTaskCreatePinnedToCore(
    [](void*) {
      while (true) {
        SECURITY mySecurity;
        mySecurity.checkVoltages();
      vTaskDelay(5000 / portTICK_PERIOD_MS); // toutes les 5 secondes
      }
    },
    "VoltageCheckTask",
    2048,      // stack size en bytes
    NULL,      // paramètre
    1,         // priorité basse
    NULL,      // handle
    0          // Core 0
  );
}

/*************************************************************************************************
 * @brief Vérifie les tensions sur les broches analogiques et allume une LED intégrée si une 
 *        tension est inférieure à 3.1V.
 **************************************************************************************************/
void SECURITY::checkVoltages() {
    led.begin(); 
  // Implémente la vérification des tensions si nécessaire
  pinMode(11, INPUT); // Exemple pour une broche de mesure
  int U12V = analogRead(11);
  int U9V = analogRead(12);
  int U5V = analogRead(13);
  float voltage12V = U12V * 3.3 / 4095.0;
  float voltage9V = U9V * 3.3 / 4095.0;
  float voltage5V = U5V * 3.3 / 4095.0;

  if(DEBUG) {
  Serial.println(U5V);
  Serial.println(U9V);
  Serial.println(U12V);
  Serial.println(voltage12V);
  Serial.println(voltage9V);
  Serial.println(voltage5V);
  }
  // Si la tension est inférieure à 3.2V, allume la LED intégrée et retourne true
  if(voltage12V < 3.1 || voltage9V < 3.1 || voltage5V < 3.1)
  {  
    led.setPixelColor(0, 60, 0, 0);
    led.show();
    if(DEBUG||ERROR)
      Serial.println("Voltage too low!");
    return;
  }
  led.setPixelColor(0, 0, 60, 0);
  led.show();
  if(DEBUG)
    Serial.println("Voltage OK.");
}

