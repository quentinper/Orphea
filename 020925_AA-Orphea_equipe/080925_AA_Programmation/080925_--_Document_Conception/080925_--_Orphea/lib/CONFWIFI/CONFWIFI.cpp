/***************************************************************
 * @file        CONFWIFI.cpp
 * @author      Lorenzo S. & Quentin P. & William L-C
 * @version     1
 * @date        2026-01-24
 * @brief       Gestion du module WIFI.
 * @details     SAE S5-S6 BUG GEII FA ESE
 * @copyright   (c) Lorenzo S. & Quentin P. & William L-C - Tous droits réservés
 ***************************************************************/

#include <CONFWIFI.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
//
AsyncWebServer server(80);
AsyncWebSocket ws("/ws"); // Le point d'entrée sera ws://192.168.4.1/ws

const char* ssid = "Orphea";      // Nom du réseau
const char* password = "Orphea_BUT3";  // Mot de passe (minimum 8 caractères)

int alim1 = 1;
int alim2 = 0;
int alim3 = 1;
int alim4 = 0;
int alim5 = 1;
// Solénoïdes reçus
int solenoids[8];

// Effets appuyés
int effect1 = 0;
int effect2 = 1;


CONFWIFI::CONFWIFI()
{
  
}

bool CONFWIFI::wifi_begin()
{
  WiFi.softAP(ssid, password);
  if(SETUP||DEBUG) {                                        
    Serial.println("Point d'accès démarré !");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());  
  }                         
  server.begin();                                            // Démarrer le serveur web       
  initLittleFS();                                            // Initialiser le système de fichiers           
  set_routes();                     
  return true;
}

void CONFWIFI::initLittleFS()
{
  if (LittleFS.begin(true) == false)
  {
    Serial.println("Error Init LittleFs");
  }
  else
  {
    File root = LittleFS.open("/");
    File file = root.openNextFile();
    while (file)
    {
      Serial.print("File: ");
      Serial.println(file.name());
      file.close();
      file = root.openNextFile();
    }
  }
}

void CONFWIFI::onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_DATA) {
        // Réception binaire (3 octets : Status, Note, Velocity)
        if (len >= 3) {
            uint8_t status   = data[0];
            uint8_t noteNum  = data[1];
            uint8_t velocity = data[2];

            if (status >= 0x80) {
                // Appel direct au moteur audio Orphea
                Serial1.write(status); Serial1.write(noteNum); Serial1.write(velocity);
                myOrphea.playMidiNote(status, noteNum, velocity);
            }
        }
    }
}

void CONFWIFI::set_routes()
{
 
  ws.onEvent(onWsEvent);
  server.addHandler(&ws);

  server.on("/maintenance", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/index.html", "text/html"); });
  server.on("/piano", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/piano.html", "text/html"); });
  server.on("/midiplayer.js", HTTP_GET, [](AsyncWebServerRequest *request) {
            request->send(LittleFS, "/midiplayer.js", "application/javascript");});
  //
  server.on("/w3.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/w3.css", "text/css"); });
  //
  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/script.js", "text/javascript"); });
  //
  server.onNotFound([](AsyncWebServerRequest *request)
            { request->send(404, "text/plain", "Page non trouvée");});
  //
  server.on("/api/alims", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        DynamicJsonDocument doc(256);
        doc["alim1"] = alim1;
        doc["alim2"] = alim2;
        doc["alim3"] = alim3;
        doc["alim4"] = alim4;
        doc["alim5"] = alim5;

        String json;
        serializeJson(doc, json);
        Serial.print(json);
        request->send(200, "application/json", json); });

    /* --------------------------
       Route : POST solénoïdes
    ---------------------------*/
    server.on("/api/solenoids", HTTP_POST, [](AsyncWebServerRequest *request) {}, // Pas de callback classique
              NULL,                                                               // Pas de gestion upload simple
              [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
              {
            DynamicJsonDocument doc(512);
            deserializeJson(doc, data);

            JsonArray arr = doc["solenoids"].as<JsonArray>();

            for (uint8_t i = 0; i < arr.size(); i++)
                solenoids[i] = arr[i];

            request->send(200, "application/json", "{\"status\":\"ok\"}"); });

    /* --------------------------
       Route : GET effets
    ---------------------------*/
    server.on("/api/effects", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        DynamicJsonDocument doc(256);
        doc["effect1"] = effect1;
        doc["effect2"] = effect2;

        String json;
        serializeJson(doc, json);
        request->send(200, "application/json", json); });
}
