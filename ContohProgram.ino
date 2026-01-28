#include <WiFi.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define led 18 
#define led2 23

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "GANTI SSID KAMU";
const char* password = "GANTI PASSWORD KAMU";

void setup(){
  Serial.begin(115200);
  // Letakkan kode SETUP kamu disini
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

  // Setup WIFI (TIDAK USAH DIUBAH)
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(50);
    Serial.print(".");
  }

  // Setup OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    for(;;);
  }

  // Setup OTA
  //ArduinoOTA.setHostname("ESP32 OTA"); //-> Menamai board ESP32 (OPSIONAL)
  //ArduinoOTA.setPassword("1234"); // -> Memasukkan password saat uppload program (OPSIONAL)
  ArduinoOTA.begin(); // -> Wajib dipakai saat upload program

  Serial.print("\nIP -> ");
  Serial.println(WiFi.localIP());

  // Setup OLED bisa diubah atau ga dipakai
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(28, 30);
  display.print("OVER-THE-AIR");
  display.display();

}

void loop(){
  ArduinoOTA.handle(); // Wajib dipakai saat upload program
  // Letakkan kode LOOP kamu di sini
  for(int i = 0; i < 5; i++){
  digitalWrite(led2, HIGH);
  delay(50);
  digitalWrite(led2, LOW);
  delay(50);
  digitalWrite(led, HIGH);
  delay(50);
  digitalWrite(led, LOW);
  delay(50);
  }

  delay(1000);
}
