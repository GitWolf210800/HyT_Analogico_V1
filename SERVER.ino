void handle_OnConnect() {
  Fecha_Hora();
  server.send(200, "text/html", SendHTML(t,h,hr,mn,sg,di,me,an)); 
  }

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
  }

void handle_restart() {
  Serial.print("restart");
  delay(500);
  ESP.restart();
}

//-------------------PAGINA DE CONFIGURACION--------------------
void paginaconf() {
  server.send(200, "text/html", pagina()); 
}


void handleJSON() {
  Serial.println("entro a la funcion");
  // Verifica si la solicitud contiene datos en formato JSON
  if (server.hasArg("plain")) {
    String jsonBody = server.arg("plain");

    // Crea un objeto JSON con la librería ArduinoJson
    StaticJsonDocument<200> doc;

    // Deserializa el JSON recibido
    DeserializationError error = deserializeJson(doc, jsonBody);

    if (!error) {
      // Accede a los valores JSON y realiza alguna operación
      int temperatura = doc["temperatura"];  // Suponiendo que hay una clave llamada "key1"
      int humedad = doc["humedad"];          // Suponiendo que hay una clave llamada "key2"

      Serial.println(temperatura);
      Serial.println(humedad);

      // Envía una respuesta al cliente
      server.send(200, "application/json", "{\"status\":\"success\"}");
    } else {
      server.send(400, "application/json", "{\"status\":\"error\",\"message\":\"Invalid JSON\"}");
    }
  } else {
    server.send(400, "application/json", "{\"status\":\"error\",\"message\":\"No JSON provided\"}");
  }
}