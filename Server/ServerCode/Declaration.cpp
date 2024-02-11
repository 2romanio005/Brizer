#include "Main.h"

ESP8266WebServer HTTP(portHTTP);                // Web интерфейс для устройства

WebSocketsServer webSocket(portWebSocket);      // web sockets server




bool flag_data_in = 1; // флаг позволяющий отловить отсутстиве данных с ардуино

#ifdef type_brizer
bool flag_temp_in = 1; // флаг позволяющий отловить отсутствие данных о температуре с отправляющей esp

MessageDataBetweenEsp message_from_esp { "null" };
#else
MessageDataBetweenEsp message_for_esp { "111.11" };
#endif



char value_string_parsing = 0;
String serialReadingBuf;

uint32_t time_asking = 0;
