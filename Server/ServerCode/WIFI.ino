void WIFIinit() {
  WiFi.mode(WIFI_STA);  // Попытка подключения к точке доступа


  if (_ssid == "" && _password == "") {
    WiFi.begin();
  }
  else {
    WiFi.begin(_ssid.c_str(), _password.c_str());
  }
  // Делаем проверку подключения до тех пор пока не подключится
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
  }

  esp_now_init();   // общение между двумя esp
#ifdef type_brizer   // приёмник
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(accept_message_from_esp);
#else                // отправитель
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);   // Указываем роль платы в ESP-NOW ОТПРАВИТЕЛЬ
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);   // Регистрируем пиры
#endif

}
