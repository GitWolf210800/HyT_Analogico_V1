
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
#include <WebServer.h>
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
#include "Server.hpp"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
