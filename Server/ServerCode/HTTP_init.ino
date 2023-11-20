
void HTTP_init(void) {
  HTTP.on("/load_data", HTTP_GET, []() {
    HTTP.send(200, "text/plain", sensors);
//    Serial.println('!');
  });
  HTTP.on("/load_data_CO2", HTTP_GET, []() {
    HTTP.send(200, "text/plain", graf_CO2);
  });
  HTTP.on("/load_data_TEMP", HTTP_GET, []() {
    HTTP.send(200, "text/plain", graf_TEMP);
  });
  HTTP.on("/load_data_RUB", HTTP_GET, []() {
    HTTP.send(200, "text/plain", graf_RUB);
  });
  HTTP.on("/load_settings", HTTP_GET, []() {
    HTTP.send(200, "text/plain", settings);
  });
  
  HTTP.on("/save", HTTP_GET, []() {              // Получаем изменения настроек с веб сайта

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
//      HTTP.send(200, "text / plain", "Reset OK"); // Oтправляем ответ Reset OK
//      ESP.restart();                                // перезагружаем модуль
//    }
//    else {                                        // иначе
//      HTTP.send(200, "text / plain", "No Reset"); // Oтправляем ответ No Reset
//    }
//  });
  // Добавляем функцию Update для перезаписи прошивки по WiFi при 1М(256K SPIFFS) и выше
//  httpUpdater.setup(&HTTP);
  // Запускаем HTTP сервер
  HTTP.begin();
}
