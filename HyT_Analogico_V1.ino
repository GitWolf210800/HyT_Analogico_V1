
///////////// ESP32 LIBRERIAS ///////////////////////////////
#include <ArduinoJson.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <esp_task_wdt.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#define nobrownout true
#define lowtxpower true

#define WDT_TIMEOUT 3600

#include <SPIFFS.h>
#include <FS.h>
#include <Wire.h>

#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>
#define LED        2
//////////////////////////////////////////////////////////



///////////Display SH1106 Comunicacion I2C pines 21/SDA 22/SCL////////

#include <Arduino.h>
#include <U8g2lib.h>
////////////////////////////////////////////////////////////

#include <PubSubClient.h>
#include <WiFiClient.h>

#include <TimeLib.h>
#include <WiFiUdp.h>

#include "VARIABLES.hpp"
#include "OBJETOS.hpp"
#include "SPIFFS.hpp"
#include "CONFIG_INSTAL.hpp"
#include "CONFIG_WIFI_RED.hpp"

#define TemperaturaSensor 32
#define HumedadSensor 39

const char* version = __FILE__;

void setup() {
  Serial.begin(115200); //Abriendo puerto Serie

  conexion();

  if (SPIFFS.begin()) {//inicia y corrobora apertura spiffs
     Serial.println("SPIFFS opened!");
  }

  u8g2.begin();
 //u8g2.setFontMode(0);    // enable transparent mode, which is faster

 sensadoSet();

 tempMQTT = millis();

}

void loop() {
  for (int i=0 ; i<60 ;i++) {
    server.handleClient();   //WebServer debe "loopearse" para responder an qcualquier momento
    client.loop();
    if (!client.connected()) {//loopeo del MQTT
      reconnect();
    }
    
    if ((millis()-tempMQTT) >= tiempoMQTT) {
      jsonPub();
      tempMQTT = millis();
    }
    
    sensado();

    Fecha_Hora();//lee fecha y hora

    if(m==30000){  
      drawTem();
      m++;   
    }
    if(m==60000){  
      drawHum();
      m=0;   
    }
    else{m++;}

    if((hr==0)&&(sg==30)&&(j==1)){
      Serial.println("reset automatico: ");
      Serial.print(mn);
      Serial.print(":");
      Serial.println(sg);
      ESP.restart();
    }
    
  }

}
