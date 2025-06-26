void sensadoSet() {

  /*leer(0).toCharArray(FCHchar, 50);
  leer(50).toCharArray(FCTchar, 50);
  FCHfloat=atof(FCHchar);
  FCTfloat=atof(FCTchar);*/

  if(readFile("calibraciones.txt", calibracion)) {
    int commaIndex2 = calibracion.indexOf(',');
    if(commaIndex2 != -1) {
      FCTstring = calibracion.substring(0, commaIndex2);
      FCHstring = calibracion.substring(commaIndex2 + 1);
      //Convertir las cadenas a flotantes si es necesario
      FCTfloat = FCTstring.toFloat();
      FCHfloat = FCHstring.toFloat();
      Serial.println("valores leidos desde memoria Flash");
         Serial.print("FCTfloat");
         Serial.print(",");
         Serial.println(FCTfloat);
         Serial.print("FCHfloat");
         Serial.print(",");
         Serial.println(FCHfloat);
      }
    }

  /*Serial.println(FCHfloat);
  Serial.println(FCTfloat);*/

  if(FCHfloat==0){
    FCHfloat=1;
  }
  if(FCTfloat==0){
    FCTfloat=1;
  }

  payload = get_server();  

  /*FCHfloat=FCH1float;
  FCTfloat=FCT1float;*/

  StaticJsonDocument<50> doc_response;

  DeserializationError error = deserializeJson(doc_response, payload);

  fac_calTemp_server = doc_response["temperatura"];
  fac_calHum_server = doc_response["humedad"];

  //Serial.println(payload);

  Serial.print("Factor de calibracion temp before, ");
  Serial.println(FCTfloat);
  Serial.print("Factor de calibracion hum before, ");
  Serial.println(FCHfloat);

  if (payload != "vacio" && payload != "error"){
    if(fac_calTemp_server != 1 && FCTfloat != fac_calTemp_server){
      FCTfloat = fac_calTemp_server;
    }

    if(fac_calHum_server != 1 && FCHfloat != fac_calHum_server){
      FCHfloat = fac_calHum_server;
    }
  }
  
  
  /*if (FCH1float == 1 || FCT1float == 1){
    server.send()
  }*/
  
  Serial.print("Factor de calibracion temp after, ");
  Serial.println(FCTfloat);
  Serial.print("Factor de calibracion hum after, ");
  Serial.println(FCHfloat);
  

  //// sensor hum y tem/////////////////////////////////////////////pendiente sensor a medir
  delay(100);
  
  h10=analogRead(HumedadSensor)*FCHfloat;
  t10=analogRead(TemperaturaSensor)*FCTfloat;
  h1=h2=h3=h4=h5=h6=h7=h8=h9=h10;
  t1=t2=t3=t4=t5=t6=t7=t8=t9=t10;
  /**/
 /////////////////////////////////////////////////////////////////////////////////////////////////////
  Serial.print("h1:");
  Serial.print(h1);
  Serial.print(", h2:");
  Serial.print(h2);
  Serial.print("h3:");
  Serial.print(h3);
  Serial.print(", h4:");
  Serial.print(h4);
  Serial.print("h5:");
  Serial.print(h5);
  Serial.print(", h6:");
  Serial.print(h6);
  Serial.print("h7:");
  Serial.print(h7);
  Serial.print(", h8:");
  Serial.print(h8);
  Serial.print("h9:");
  Serial.print(h9);
  Serial.print(", h10:");
  Serial.println(h10);
}


String get_server() {
  if (WiFi.status() == WL_CONNECTED) {

  StaticJsonDocument<100> doc_get;
  doc_get["instalacion"] = descripcion;
  doc_get["tabla"] = "factor_calibracion_puestos_clima";

  String queryParams;
  serializeJson(doc_get, queryParams);

    // Reemplazar caracteres especiales en la cadena de consulta (opcional)
  queryParams.replace("\"", "");  // Elimina comillas dobles
  queryParams.replace("{", "");   // Elimina llave de apertura
  queryParams.replace("}", "");   // Elimina llave de cierre
  queryParams.replace(":", "=");  // Reemplaza ":" por "="
  queryParams.replace(",", "&");  // Reemplaza "," por "&"


  String serverPath = "http://192.168.3.122:1880/factorcalibracion?" + queryParams;

  //Serial.println(serverPath);

  http_client.begin(espClient, serverPath);
  int httpResponseCode = http_client.GET();

  if (httpResponseCode > 0) {
    String payload_res = http_client.getString();
    //Serial.println("Respuesta del servidor");
    //Serial.println(payload);

    Serial.println(payload_res);

    return payload_res;
  } else {
    Serial.print("Error en la peticion GET, código: ");
    Serial.println(httpResponseCode);
    return "error";
  }

  http_client.end();

} else {
  Serial.println("Error de Conexion Wi-Fi");
  return "error";
}  
}