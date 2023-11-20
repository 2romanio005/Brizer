// ------------- Чтение значения json String
String jsonRead(String &json, String name) {
  DynamicJsonDocument jsonBuffer(1024);
  deserializeJson(jsonBuffer, json);
  return jsonBuffer[name].as<String>();
}

// ------------- Чтение значения json int
int jsonReadtoInt(String &json, String name) {
  DynamicJsonDocument jsonBuffer(1024);
  deserializeJson(jsonBuffer, json);
  return jsonBuffer[name];
}

// ------------- Запись значения json
template <typename T>
String jsonWrite(String &json, String name, T volume) {
  DynamicJsonDocument jsonBuffer(1024);
  deserializeJson(jsonBuffer, json);
  jsonBuffer[name] = volume;
  json = jsonBuffer.as<String>();
//      serializeJson(jsonBuffer, Serial);
  return jsonBuffer.as<String>();
}

void saveConfig (){
  writeFile("config.json", configSetup);
}

// ------------- Чтение файла в строку
String readFile(String fileName, size_t len) {
  File configFile = SPIFFS.open("/" + fileName, "r");
  if (!configFile) {
    return "Failed";
  }
  size_t size = configFile.size();
  if (size > len) {
    configFile.close();
    return "Large";
  }
  String temp = configFile.readString();
  configFile.close();
  return temp;
}

// ------------- Запись строки в файл
String writeFile(String fileName, String strings ) {
  File configFile = SPIFFS.open("/" + fileName, "w");
  if (!configFile) {
    return "Failed to open config file";
  }
  configFile.print(strings);
  //strings.printTo(configFile);
  configFile.close();
  return "Write sucsses";
}







//
