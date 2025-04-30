#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <PubSubClient.h>

#define LED_BUILTIN 2

const char *ssid_Router = "iPhoneHotspot"; //Enter the router name
const char *password_Router = "verizonftw"; //Enter the router password

const int mqtt_port = 1883;

void setup(){
  Serial.begin(115200);

  delay(2000);
  
  Serial.println("Setup start");
  WiFi.begin(ssid_Router, password_Router);
  Serial.println(String("Connecting to ")+ssid_Router);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Setup End");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
