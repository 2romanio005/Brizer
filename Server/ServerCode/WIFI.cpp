#include "Main.h"

void WIFI_init() {
  WiFi.mode(WIFI_STA);  // Попытка подключения к точке доступа


  if (WIFI_ssid == "" && WIFI_password == "") {
    WiFi.begin();
  }
  else {
    WiFi.begin(WIFI_ssid, WIFI_password);
  }
  // Делаем проверку подключения до тех пор пока не подключится
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
  }
}
