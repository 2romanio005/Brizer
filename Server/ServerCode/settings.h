#include "imports.h"


//#define type_brizer             // принимает температуру с улицы то - не коментируем(бризер OLD), если отдаёт то - коментируем(бризе NEW)

#define change_settings_password "2020"
#define change_memory_password "memory"

#define _ssid     "point"         // Для хранения SSID
#define _password "555energy555"  // Для хранения пароля сети



#ifndef type_brizer
//8C:AA:B5:1B:16:76
uint8_t broadcastAddress[] = {0x8C, 0xAA, 0xB5, 0x1B, 0x16, 0x76}; // MAC-адрес получателя

#define alliedOrigin "http://127.0.0.1:3000"
#define brizerMainTitle "&#1041&#1088&#1080&#1079&#1077&#1088 &#1056&#1086&#1084&#1072&#1085"
#define brizerSettingsTitle "&#1041&#1088&#1080&#1079&#1077&#1088 &#1056&#1086&#1084&#1072&#1085"
#else
#define alliedOrigin "http://127.0.0.1:3000"
#define brizerMainTitle "&#1041&#1088&#1080&#1079&#1077&#1088 &#1056&#1086&#1084&#1072&#1085"
#define brizerSettingsTitle "&#1041&#1088&#1080&#1079&#1077&#1088 &#1056&#1086&#1084&#1072&#1085"
#endif
