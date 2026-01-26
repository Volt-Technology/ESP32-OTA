#include <WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "GANTI SSID KAMU";
const char* password = "GANTI PASSWORD KAMU";

void setup(){
  Serial.begin(115200);

  // Setup WIFI (TIDAK USAH DIUBAH)
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(50);
    Serial.print(".");
  }

  // Setup OTA
  //ArduinoOTA.setHostname("ESP32 OTA"); //-> OPSIONAL
  //ArduinoOTA.setPassword("1234"); // -> OPSIONAL
  ArduinoOTA.begin(); // -> Wajib dipakai saat upload program
  
  Serial.print("\nIP -> ");
  Serial.println(WiFi.localIP());
}

void loop(){
  ArduinoOTA.handle(); // Wajib dipakai saat upload program
 
}