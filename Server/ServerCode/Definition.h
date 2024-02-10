#pragma once
#include "Settings.h"


extern ESP8266WebServer HTTP;                // Web интерфейс для устройства

extern WebSocketsServer webSocket;      // web sockets server




extern bool flag_data_in; // флаг позволяющий отловить отсутстиве данных с ардуино


struct MessageDataBetweenEsp {
  String temp_street;
};
#ifdef type_brizer
extern bool flag_temp_in; // флаг позволяющий отловить отсутствие данных о температуре с отправляющей esp

extern MessageDataBetweenEsp message_from_esp;
#else
extern MessageDataBetweenEsp message_for_esp;
#endif





extern char value_string_parsing;
extern char buf_char;
extern String buf_string;

extern uint32_t time_asking;
