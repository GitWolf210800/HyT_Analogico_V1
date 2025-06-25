void conexion() {
  WiFi.mode(WIFI_STA);
  //Wire.begin(D1,D2); // Inicia el puerto I2C para el display y RTC
  //Wire.begin(); // Inicia el puerto I2C para el display y RTC
  
  WiFi.config(ip, gateway, subnet);//configura la dirección del wifi
  WiFi.begin(ssid, password);//establece usuario y contraseña
  Serial.println("");
  //// Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    MAC=WiFi.macAddress();
    Serial.print("IP address: ");
    Serial.println(MAC);
   Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    
  if (MDNS.begin("esp8266")) {/////////???????
    Serial.println("MDNS responder started");
     }
//////Aquí fija las acciones del servidor web para cada situación:on (pueden incluirse otras acciones), no found.
  server.on("/", handle_OnConnect);
  server.on("/calibrar", HTTP_POST, guardar_conf);
  //server.on("/calibrar", paginaconf);
  //server.on("/guardar_conf", guardar_conf); //Graba en la eeprom la configuracion
  server.on("/restart", handle_restart);
  server.onNotFound(handle_NotFound);
  server.begin();//inicia servidor web
  Serial.println("HTTP server started");

  /////FTP Setup, ensure SPIFFS is started before ftp;  /////////
  /*if (SPIFFS.begin()) {//inicia y corrobora apertura spiffs
      Serial.println("SPIFFS opened!");
      ftpSrv.begin("esp8266","pepito");    //username, password for ftp.  set ports in ESP8266FtpServer.h  (default 21, 50009 for PASV)
      } */

  Udp.begin(localPort);
  setSyncProvider(getNtpTime);

    /*Inicio el MQTT*/

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}