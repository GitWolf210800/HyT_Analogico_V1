void writeFile(const char *path, String message) {
  File file = SPIFFS.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("No se pudo abrir el archivo en escritura");
    return;
  }

  if (file.println(message)) {
    Serial.println("Archivo escrito correctamente");
  } else {
    Serial.println("Error al escribir en el archivo");
  }
  file.close();
}

bool readFile(const char *path, String &data) {
  File file = SPIFFS.open(path, FILE_READ);
  if (!file) {
    Serial.println("No se pudo abrir el archivo en lectura");
    return false;
  }

  data = file.readString();
  file.close();
  return true;
}