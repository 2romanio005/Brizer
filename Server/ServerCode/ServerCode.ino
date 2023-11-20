#include "set.h"

void setup() {
  
  ESP8266WebServer HTTP(port);
  Serial.begin(9600);
  delay(50);
  
//  Serial.println("Start 4-FS");
  FS_init();                                    // Запускаем файловую систему
//  Serial.println("Step7-FileConfig");
  configSetup = readFile("config.json", 4096);
  jsonWrite(configJson, "SSDP", jsonRead(configSetup, "SSDP"));
  
//  Serial.println("Start 1-WIFI");
  WIFIinit();                                   // Запускаем WIFI
  
//  Serial.println("Start 3-SSDP");
  SSDP_init();                                  // Настраиваем и запускаем SSDP интерфейс
  
//  Serial.println("Start 2-WebServer");
  HTTP_init();                                  // Настраиваем и запускаем HTTP интерфейс

  ftpSrv.begin("2020","2020");                                        // Поднимаем FTP-сервер для удобства отладки работы HTML (логин: relay, пароль: relay)

}


void loop() {
  HTTP.handleClient();
  ftpSrv.handleFTP();                                                 // Обработчик FTP-соединений  

  if(Serial.available() > 0){  
    buf_char = Serial.read();
    if(buf_char != '\n' && buf_char != '/'){
      buf_string += buf_char;
    }
    if(buf_char == '/'){
      switch (value_string_parsing) {
        case 0:                                     // данные с датчиков
          {
#ifdef type_brizer
          sensors = message_from_esp.temp_street;
          sensors += ';';
          sensors += buf_string;
#else
          sensors = buf_string;
 
          message_for_esp.temp_street = "";
          byte i = 0;
          while(buf_string[i] != ';'){
            message_for_esp.temp_street += buf_string[i];
            ++i;
          }
          esp_now_send(0, (uint8_t *) &message_for_esp, sizeof(message_for_esp));
#endif
          }
          break;
        case 1:                                     // настройки
          settings = buf_string;
          break;
        case 2:                                     // график CO2
          graf_CO2 = buf_string;
          break;
        case 3:                                     // графики температуры
          graf_TEMP = buf_string;
          break;
        case 4:                                     // графики энергозатрат
          graf_RUB = buf_string;
          value_string_parsing = -1;
          flag_data_in = 0;
          break;
      }
      ++value_string_parsing;
      
      buf_string = "";
    }
  }

  if(millis() - time_asking >= 300000){   //время до запроса к ардуинке
    delay(3);
    if(Serial.available() == 0){
#ifdef type_brizer
      if(flag_temp_in){
        Serial.println("111.11@");
        message_from_esp.temp_street = "null";
      }
      flag_temp_in = 1;
#endif
      time_asking = millis();
      value_string_parsing = 0;
      if(flag_data_in){
        String sensors = "0;0;0;0;0;0;0;0";
        String graf_CO2 = "null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null;null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null";
        String graf_TEMP = "null;bull;null";
        String graf_RUB = "null;bull;null";
        String settings = "0;0;0;0.0;0;0;0;0;0;0;0";
      }
      flag_data_in = 1;
      Serial.print("!");
    }
  }
}

#ifdef type_brizer
void accept_message_from_esp(uint8_t *mac_addr, uint8_t *incomingData, uint8_t len) { 
  memcpy(&message_from_esp, incomingData, sizeof(message_from_esp));
  Serial.println(message_from_esp.temp_street + '@');
  flag_temp_in = 0;
}
#endif


//
