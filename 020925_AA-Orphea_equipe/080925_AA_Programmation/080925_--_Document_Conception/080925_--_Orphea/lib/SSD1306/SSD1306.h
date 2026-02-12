/***************************************************************
 * @file        SSD1306.h
 * @author      Lorenzo S. & Quentin P.
 * @version     2
 * @date        2025-05-19
 * @brief       Gestion de l'affichage OLED.
 * @details     SAE S4 BUG GEII FA ESE -
 * @copyright   (c) Lorenzo S. & Quentin P.- Tous droits réservés
 ***************************************************************/
#ifndef SSD1306_H
#define SSD1306_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// les registres

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

extern Adafruit_SSD1306 oled;
extern bool SETUP;
extern bool DEBUG;
extern bool ERROR;
class SSD1306
{
    //
public:
    // constructeur
    SSD1306();
    void beginOLED(uint8_t SSD1306_ADR);

    // méthodes
private:
    uint8_t _adress;
    int _value;
};

#endif