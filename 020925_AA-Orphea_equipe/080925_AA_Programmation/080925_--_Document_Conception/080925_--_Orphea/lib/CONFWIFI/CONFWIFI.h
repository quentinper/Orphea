/***************************************************************
 * @file        CONFWIFI.h
 * @author      Lorenzo S. & Quentin P. & William L-C
 * @version     1
 * @date        2026-01-24
 * @brief       Gestion du module WIFI.
 * @details     SAE S5-S6 BUG GEII FA ESE
 * @copyright   (c)  Lorenzo S. & Quentin P. & William L-C - Tous droits réservés
 ***************************************************************/

#ifndef CONF_WIFI_H
#define CONF_WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <ORPHEA.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
extern bool SETUP;
extern bool DEBUG;
extern bool ERROR;

extern ORPHEA myOrphea;

// a compléter
class CONFWIFI
{
public:
    // constructor
    CONFWIFI();
    void set_routes();
    bool wifi_begin();
    void initLittleFS();
    static void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);

private:
};

#endif