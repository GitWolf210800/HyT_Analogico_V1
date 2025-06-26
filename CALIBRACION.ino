void guardar_conf() {

  calibracion_recepcion = server.arg("plain");

  StaticJsonDocument<50> doc;

  DeserializationError error = deserializeJson(doc, calibracion_recepcion);

  if(!error) {
     //calibracion = doc["calibracion"].as<String>();
     valor_calibracion_temp = doc["temperatura"].as<float>();
     valor_calibracion_hum = doc["humedad"].as<float>();
     //Serial.println(calibracion);
     Serial.println(valor_calibracion_temp);
     Serial.println(valor_calibracion_hum);
    } else {
            server.send(400, "application/json", "{\"status\" : \"error\", \"message\" : \"Invalid JSON\"}");
      }
      
    FCTfloat = valor_calibracion_temp;
    FCTstring = String(FCTfloat, 4); //1 decimal
    FCTstring.toCharArray(FCTchar, 20);

    FCHfloat = valor_calibracion_hum;
    FCHstring = String(FCHfloat, 4); //1 decimal
    FCHstring.toCharArray(FCHchar, 20);



  writeFile("/calibraciones.txt", FCTstring + "," + FCHstring);

  /*grabar(0,FCHchar);
  grabar(50,FCTchar);*/


    t = t*FCTfloat;
    h = h*FCHfloat;
}

//----------------Función para grabar en la EEPROM-------------------
/*
void grabar(int addr, String a) {
  int tamano = a.length(); 
  char inchar[50]; 
  a.toCharArray(inchar, tamano+1);
  for (int i = 0; i < tamano; i++) {
    EEPROM.write(addr+i, inchar[i]);
  }
  for (int i = tamano; i < 50; i++) {
    EEPROM.write(addr+i, 255);
  }
  EEPROM.commit();
}

//-----------------Función para leer la EEPROM------------------------
String leer(int addr) {
   byte lectura;
   String strlectura;
   for (int i = addr; i < addr+50; i++) {
      lectura = EEPROM.read(i);
      if (lectura != 255) {
        strlectura += (char)lectura;
      }
      
   }
   return strlectura;
}*/