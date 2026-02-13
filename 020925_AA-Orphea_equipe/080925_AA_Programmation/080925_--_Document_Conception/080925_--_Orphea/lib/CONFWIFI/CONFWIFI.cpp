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

const char* ssid = "Orphea";            // Nom du réseau
const char* password = "Orphea_BUT3";   // Mot de passe (minimum 8 caractères)

CONFWIFI::CONFWIFI()
{
  
}


/***********************************************************************************************
 * @brief Initialise l'environnement réseau et les services web du système Orphea.
 *        Cette fonction est le point d'entrée de la connectivité. Elle transforme l'ESP32 
 *        en borne Wi-Fi autonome pour permettre à un utilisateur de s'y connecter sans 
 *        routeur externe.
 * @return true si l'initialisation a été lancée avec succès.
 ***********************************************************************************************/
bool CONFWIFI::wifi_begin()
{
  WiFi.softAP(ssid, password); //Configure l'ESP32 en mode Point d'Accès (SoftAP).
  if(SETUP||DEBUG) 
  {                                        
    Serial.println("Point d'accès démarré !");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());  
  }                         
  server.begin();    // Démarrer le serveur web       
  initLittleFS();    // Initialise le système de fichiers           
  set_routes();      // Configure les routes du serveur              
  return true;
}

/***********************************************************************************************
 * @brief Initialise le système de fichiers LittleFS et liste le contenu du répertoire racine.
 *        Cette méthode est cruciale pour le projet Orphea car elle permet d'accéder aux fichiers 
 *        stockés en mémoire flash (comme les pages HTML, CSS et JS de l'interface web).
 * @details 1. LittleFS.begin(true) : Tente de monter le système de fichiers. L'argument 'true' 
 *          autorise le formatage automatique si le système est corrompu ou non initialisé.
 *          2. En cas de succès, la fonction parcourt la racine ("/") :
 *              - Ouvre chaque fichier successivement via root.openNextFile().
 *              - Affiche le nom de chaque fichier trouvé dans le moniteur série pour le debug.
 *              - Ferme chaque fichier après lecture pour libérer les ressources.
 *********************************************************************************************/
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

/***********************************************************************************************
 * @brief Gestionnaire d'événements pour le serveur WebSocket.
 *        Cette fonction traite les interactions réseau en temps réel, servant de pont 
 *        entre l'interface utilisateur (web) et le moteur de synthèse sonore.
 * @param server  : Pointeur vers l'instance du serveur WebSocket.
 * @param client  : Pointeur vers le client source de l'événement.
 * @param type    : Nature de l'événement (WS_EVT_CONNECT, WS_EVT_DATA, etc.).
 * @param arg     : Argument utilisateur supplémentaire (non utilisé).
 * @param data    : Buffer contenant les données reçues (octets MIDI : Status, Note, Velocity).
 * @param len     : Taille en octets des données reçues.
 * @note En cas de réception de données (type WS_EVT_DATA), la fonction extrait les messages 
 *       MIDI pour les transmettre à la méthode myOrphea.playMidiNote() afin de générer le son.
 ***********************************************************************************************/
void CONFWIFI::onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_DATA) {
        // Réception binaire (3 octets : Status, Note, Velocity)
        if (len >= 3) {
            uint8_t status   = data[0];   //status MIDI (note on/off)
            uint8_t noteNum  = data[1];   //numéro de la note MIDI (0-127)  
            uint8_t velocity = data[2];   //vélocité de la note MIDI (0-127)

            if (status >= 0x80) {
                // Appel direct au moteur audio Orphea
                Serial1.write(status); Serial1.write(noteNum); Serial1.write(velocity);  //Communication série avec Arduino Mega pour gestion des solénoïdes
                myOrphea.playMidiNote(status, noteNum, velocity);                        // Transmission MIDI à Orphea pour jouer la note correspondante 
            }
        }
    }
}


/**************************************************
 set_routes : Configure les routes du serveur web

 A Completer après avoir finis les routes ;-)

 **************************************************/
void CONFWIFI::set_routes()
{
 
  ws.onEvent(onWsEvent);  // Configurer le gestionnaire d'événements pour les WebSockets
  server.addHandler(&ws); // Ajouter le gestionnaire WebSocket au serveur

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
}
