
void HTTP_init(void) {
//  HTTP.on("/options")
//options "/greet" do |env|
//  # Allow `POST /greet`...
//  env.response.headers["Access-Control-Allow-Methods"] = "POST"
//  # ...with `Content-type` header in the request...
//  env.response.headers["Access-Control-Allow-Headers"] = "Content-type"
//  # ...from https://www.google.com origin.
//  env.response.headers["Access-Control-Allow-Origin"] = "https://www.google.com"
  
  HTTP.on("/Content/Main/LoadingData/MainData", HTTP_GET, []() {
    HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
    HTTP.send(200, "text/plain", sensors);
  });
  HTTP.on("/Content/Main/LoadingData/CO2", HTTP_GET, []() {
    HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
    Serial.print("CO2!");
    HTTP.send(200, "text/plain", graf_CO2);
  });
  HTTP.on("/Content/Main/LoadingData/TempChart", HTTP_GET, []() {
    HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
    HTTP.send(200, "text/plain", graf_TEMP);
  });
  HTTP.on("/Content/Main/LoadingData/RubChart", HTTP_GET, []() {
    HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
    HTTP.send(200, "text/plain", graf_RUB);
  });
  HTTP.on("/Content/Settings/LoadingData/SettingsData", HTTP_GET, []() {
    HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
    HTTP.send(200, "text/plain", settings);
  });
  
  HTTP.on("/save", HTTP_GET, []() {              // Получаем изменения настроек с веб сайта
    HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
    void (*foo_tmp)(String tmp) = [](String tmp){
//      Serial.print(tmp);
//      Serial.print(';');
      settings += tmp;
      settings += ';';
    };

    if(HTTP.arg("password") == change_settings_password){
        settings = "";
        foo_tmp( HTTP.arg("CO2_no_good") );
        foo_tmp( HTTP.arg("on_vent") );
        foo_tmp( HTTP.arg("vent") );
        foo_tmp( HTTP.arg("celsius_NORM") );
        foo_tmp( HTTP.arg("check_temp") );
        foo_tmp( HTTP.arg("update_celsius_NORM") );
        foo_tmp( HTTP.arg("CO2_out_people") );
        foo_tmp( HTTP.arg("time_out_people") );
        foo_tmp( HTTP.arg("time_nite") );
        foo_tmp( HTTP.arg("time_no_nite") );
        foo_tmp( HTTP.arg("on_display") );       
        Serial.println(settings);
        
        HTTP.send(200, "application/json", "1");
    }else if(HTTP.arg("password") == change_memory_password){
      if(HTTP.arg("memory") != ""){
        Serial.println(HTTP.arg("memory") + '$');
      }
      HTTP.send(200, "application/json", "2");
    }else{
      HTTP.send(200, "application/json", "0");
    }
    


  });



  
//  HTTP.on("/config.live.json", HTTP_GET, []() {
//    jsonWrite(configJson, "time", GetTime());
//    jsonWrite(configJson, "date", GetDate());
//    HTTP.send(200, "application/json", configJson);
//  });
//  // --------------------Выдаем данные configJson
//  HTTP.on("/config.live.json", HTTP_GET, []() {
//    jsonWrite(configJson, "time", GetTime());
//    jsonWrite(configJson, "date", GetDate());
//    HTTP.send(200, "application/json", configJson);
//  });
//  // -------------------Выдаем данные configSetup
//  HTTP.on("/config.setup.json", HTTP_GET, []() {
//    HTTP.send(200, "application/json", configSetup);
//  });
//  // -------------------Выдаем данные configSetup
//  HTTP.on("/restart", HTTP_GET, []() {
//    String restart = HTTP.arg("device");          // Получаем значение device из запроса
//    if (restart == "ok") {                         // Если значение равно Ок
//      HTTP.send(200, "text / plain", "Reset OK"); // Отправляем ответ Reset OK
//      ESP.restart();                                // перезагружаем модуль
//    }
//    else {                                        // иначе
//      HTTP.send(200, "text / plain", "No Reset"); // Отправляем ответ No Reset
//    }
//  });

  // Добавляем функцию Update для перезаписи прошивки по WiFi при 1М(256K SPIFFS) и выше
//  httpUpdater.setup(&HTTP);
  // Запускаем HTTP сервер
  HTTP.begin();
}
