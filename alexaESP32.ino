#include <Arduino.h>
#include <WiFi.h>
#include <Espalexa.h>
#include "credentials.h"

boolean connectWifi();

void UNO(uint8_t brightness);

boolean wifiConnected = false;

Espalexa espalexa;


void setup()
{
    Serial.begin(9600);
  Serial2.begin(9600);

  wifiConnected = connectWifi();
  
  if(wifiConnected){ 
    espalexa.addDevice("uno", UNO);
    espalexa.begin();
    
  } 

  else{
    while(1){
      delay(2500);
    }
  }
  Serial2.print("^u1$");
  delay(1000);
  Serial2.print("^u1$");
  delay(1000);
  Serial2.print("^u1$");
  delay(1000);
  Serial2.print("^u1$");
  delay(1000);
  Serial2.print("^u1$");
  delay(1000);
  
  Serial2.print("^u0$");
  delay(1000);
  Serial2.print("^u0$");
  delay(1000);
  Serial2.print("^u0$");
  delay(1000);
  Serial2.print("^u0$");
  delay(1000);
  Serial2.print("^u0$");
  delay(1000);
}
 
void loop()
{
   espalexa.loop();
   delay(1);
}

void UNO(uint8_t brightness) {
    
    if (brightness) {
        for (uint8_t i=0;i<5;i++){
            Serial2.print("^u1$");
            Serial.println("1");  
            delay(100);
        }

    }
    else  {
      for (uint8_t i=0;i<5;i++){
            Serial2.print("^u0$");
            delay(100);    
        }
    }
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi(){
  boolean state = true;
  int i = 0;
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    if (i > 20){
      state = false; break;
    }
    i++;
  }

  return state;
}
