#include "Main.h"



void LoadingData_Main_MainData() {                    // Отправка данных с датчиков
  HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
  HTTP.send(200, "text/plain", sensors);
}
void LoadingData_Main_CO2() {                         // Отправка графика CO2
  HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
  HTTP.send(200, "text/plain", graf_CO2);
}
void LoadingData_Main_TempChart() {                   // Отправка графика температур
  HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
  HTTP.send(200, "text/plain", graf_TEMP);
}
void LoadingData_Main_RubChart() {                    // Отправка графика затрат
  HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
  HTTP.send(200, "text/plain", graf_RUB);
}

void LoadingData_Settings_SettingsData() {            // Отправка настроек 
  HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
  String message = "";
  for(byte i = 0; i < numberMainSettingsMessage; i++){
    message += mainSettingsMessage[i] + ';';
  }
  HTTP.send(200, "text/plain", message);
}
void SavingData_Settings_MainSettings() {             // Получаем изменения настроек с веб сайта
  HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
  if (HTTP.arg(allNameMainSettingsArg[0]) == change_settings_password) {
    for (byte i = 2; i < numberMainSettingsArg; i++) {
      String argum = HTTP.arg(allNameMainSettingsArg[i]);
      if (argum != "") {
        mainSettingsMessage[i - 1] = argum;
        Serial.print(argum + ';');
      }
    }
    HTTP.send(200, "text/plain", "1");
  } else {
    HTTP.send(200, "text/plain", "0");
  }
}
void SavingData_Settings_MemorySettings() {           // Получаем изменения памяти с веб сайта
  HTTP.sendHeader("Access-Control-Allow-Origin", alliedOrigin);
  if (HTTP.arg(allNameMemorySettingsArg[0]) == change_memory_password) {
    for (byte i = 1; i < numberMemorySettingsArg; i++) {
      Serial.print(HTTP.arg(allNameMemorySettingsArg[i]) + '$');
    }
    HTTP.send(200, "text/plain", "1");
  } else {
    HTTP.send(200, "text/plain", "0");
  }
}



void HTTP_init() {
  HTTP.on("/LoadingData/Main/MainData", HTTP_GET, LoadingData_Main_MainData);                         // Отправка данных с датчиков
  HTTP.on("/LoadingData/Main/CO2", HTTP_GET, LoadingData_Main_CO2);                                   // Отправка графика CO2
  HTTP.on("/LoadingData/Main/TempChart", HTTP_GET, LoadingData_Main_TempChart);                       // Отправка графика температур
  HTTP.on("/LoadingData/Main/RubChart", HTTP_GET, LoadingData_Main_RubChart);                         // Отправка графика затрат
  
  HTTP.on("/LoadingData/Settings/SettingsData", HTTP_GET, LoadingData_Settings_SettingsData);         // Отправка настроек 
  HTTP.on("/SavingData/Settings/MainSettings", HTTP_POST, SavingData_Settings_MainSettings);          // Получаем изменения настроек с веб сайта
  HTTP.on("/SavingData/Settings/MemorySettings", HTTP_POST, SavingData_Settings_MemorySettings);      // Получаем изменения памяти с веб сайта

  HTTP.begin();
}








//
