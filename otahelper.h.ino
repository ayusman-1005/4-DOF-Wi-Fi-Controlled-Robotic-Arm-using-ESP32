//This is the custom OTA header file made to clean the program and help push updates wirelessly without the need of connecting physically every time. 



// OTAHelper.h
#ifndef OTA_HELPER_H
#define OTA_HELPER_H

#include <WiFi.h>
#include <ArduinoOTA.h>

class OTAHelper {
  const char* ssid;
  const char* password;
  const char* ota_password;
  const char* hostname;

public:
  OTAHelper(const char* ssid, const char* password, const char* ota_password, const char* hostname)
    : ssid(ssid), password(password), ota_password(ota_password), hostname(hostname) {}

  void begin() {
    Serial.begin(115200);

    // WiFi connection
    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    Serial.println("\nWiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // OTA setup
    ArduinoOTA.setHostname(hostname);
    ArduinoOTA.setPassword(ota_password);

    ArduinoOTA.begin();
    Serial.println("OTA Ready for uploads as '" + String(hostname) + "'");
  }

  void handle() {
    ArduinoOTA.handle();
  }
};

#endif
