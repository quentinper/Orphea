/***************************************************************
 * @file        SSD1306.cpp
 * @author      Lorenzo S. & Quentin P.
 * @version     2
 * @date        2025-05-19
 * @brief       Gestion de l'affichage OLED.
 * @details     SAE S4 BUG GEII FA ESE -
 * @copyright   (c) Lorenzo S. & Quentin P.- Tous droits réservés
 ***************************************************************/
#include <SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <images.h>

SSD1306::SSD1306()
{
    _adress = 0;
    _value = 0;
}
//************************************

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT); // Définition unique
GFXcanvas1 canvas(SCREEN_WIDTH, SCREEN_HEIGHT);


/*************************************************************************************************
 * @brief Initialise l'écran OLED avec l'adresse spécifiée
 * @param SSD1306_adr : Adresse I2C de l'écran SSD1306
 **************************************************************************************************/
void SSD1306::beginOLED(uint8_t SSD1306_adr)
{
    _adress = SSD1306_adr;
    if (!oled.begin(SSD1306_SWITCHCAPVCC, _adress))
    {
        if(SETUP||DEBUG)
            Serial.println(F("Échec de l'initialisation de l'écran OLED"));
        while (true)
            ;
    }
    else
    {
        if(SETUP||DEBUG)
            Serial.println("Capteur SSD1306 connecté");
    }
    oled.clearDisplay();
    oled.display();
}

