#include <ESP8266WiFi.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step1-wifi
#include <ESP8266WebServer.h>   //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step2-webserver
#include <ESP8266SSDP.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step3-ssdp
#include <FS.h>                 //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step4-fswebserver
//                    ПЕРЕДАЧА ДАННЫХ НА WEB СТРАНИЦУ. Видео с уроком http://esp8266-arduinoide.ru/step5-datapages/
//                    ПЕРЕДАЧА ДАННЫХ С WEB СТРАНИЦЫ.  Видео с уроком http://esp8266-arduinoide.ru/step6-datasend/
#include <ArduinoJson.h>        //Установить из менеджера библиотек. https://arduinojson.org/
//                    ЗАПИСЬ И ЧТЕНИЕ ПАРАМЕТРОВ КОНФИГУРАЦИИ В ФАЙЛ. Видео с уроком http://esp8266-arduinoide.ru/step7-fileconfig/
#include <ESP8266HTTPUpdateServer.h>  //Содержится в пакете.  Видео с уроком http://esp8266-arduinoide.ru/step8-timeupdate/
#include <ESP8266FtpServer.h>                                           // Библиотека для работы с SPIFFS по FTP

#include <espnow.h> // общение между двумя esp8266 платами


// Объект для обнавления с web страницы
ESP8266HTTPUpdateServer httpUpdater;

// Web интерфейс для устройства
ESP8266WebServer HTTP;

// Для файловой системы
File fsUploadFile;

FtpServer ftpSrv;                                                       // Определяем объект для работы с модулем по FTP (для отладки HTML)





//#define type_brizer         //принимает температуру с улицы то - не коментируем(бризер OLD), если отдаёт то - коментируем(бризе NEW)




#define change_settings_password "2020"
#define change_memory_password "memory"

String _ssid     = "point";         // Для хранения SSID
String _password = "555energy555";  // Для хранения пароля сети

#ifndef type_brizer
//8C:AA:B5:1B:16:76
uint8_t broadcastAddress[] = {0x8C, 0xAA, 0xB5, 0x1B, 0x16, 0x76}; // MAC-адрес получателя
#endif

String configSetup = "{}";
String configJson = "{}";
int port = 80;


String sensors = "0;0;0;0;0;0;0;0;0";
#ifdef type_brizer
String graf_CO2 = "null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null;null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null;";
String graf_TEMP = "null;bull;null;";
String graf_RUB = "null;bull;null;";
#else
String graf_CO2 = "null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null;null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null;";
String graf_TEMP = "null;bull;null;null;null;null;null;";
String graf_RUB = "null;bull;null;null;null;null;null;";
#endif
String settings = "0;0;0;0.0;0;0;0;0;0;0;0";



bool flag_data_in = 1; // флаг позволяющий отловить отсутстиве данных с ардуино

#ifdef type_brizer
bool flag_temp_in = 1; // флаг позволяющий отловить отсутствие данных о температуре с отправляющей esp

struct message_from_esp{
  String temp_street = "null";
} message_from_esp;
#else 
struct message_for_esp{
  String temp_street = "111.11";
} message_for_esp;
#endif



char value_string_parsing = 0;
char buf_char;
String buf_string;

uint32_t time_asking = 0;





//
