#include "Main.h"

void ESPNOW_init() {
  esp_now_init();   // общение между двумя esp
#ifdef type_brizer   // приёмник
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(accept_message_from_esp);
#else                // отправитель
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);   // Указываем роль платы в ESP-NOW ОТПРАВИТЕЛЬ
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);   // Регистрируем пиры
#endif
}
