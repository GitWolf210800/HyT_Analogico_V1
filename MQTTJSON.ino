void jsonPub(){
    StaticJsonDocument<200> JSON;

        JSON["temperatura"] = t;
        JSON["humedad"] = h;
        //JSON["presion"] = presion;  // linea de codigo para sensados con BME
        JSON["programa"] = version;
        JSON["direccion_ip"] = WiFi.localIP();
        JSON["instalacion"] = descripcion;
        
    serializeJson(JSON, jsonMqtt);
    Serial.println(jsonMqtt);
    client.publish(topico, jsonMqtt.c_str());

    JSON.clear(); 
    jsonMqtt = "";

}