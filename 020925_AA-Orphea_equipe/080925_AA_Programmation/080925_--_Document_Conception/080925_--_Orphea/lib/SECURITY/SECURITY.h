/***************************************************************
 * @file        SECURITY.h
 * @author      Lorenzo S. & Quentin P. & William L-C
 * @version     1
 * @date        2026-01-24
 * @brief       Gestion des Securité de ORPHEA.
 * @details     SAE S5-S6 BUG GEII FA ESE
 * @copyright   (c)  Lorenzo S. & Quentin P. & William L-C - Tous droits réservés
 ***************************************************************/

#ifndef SECURITY_H
#define SECURITY_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

extern bool DEBUG;
extern bool SETUP;
extern bool ERROR;

class SECURITY
{
public:
    // constructor
    SECURITY();
    void checkVoltages();
    void createTaskCheckVoltages();
    
private:
};

#endif