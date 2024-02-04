#include "messages.h"

// Объект для обновления с web страницы
// ESP8266HTTPUpdateServer httpUpdater;

// Web интерфейс для устройства
ESP8266WebServer HTTP;

// Для файловой системы
File fsUploadFile;

// Определяем объект для работы с модулем по FTP (для отладки HTML)
FtpServer ftpSrv;






String configSetup = "{}";
String configJson = "{}";
int port = 80;


bool flag_data_in = 1; // флаг позволяющий отловить отсутстиве данных с ардуино

#ifdef type_brizer
bool flag_temp_in = 1; // флаг позволяющий отловить отсутствие данных о температуре с отправляющей esp

struct message_from_esp {
  String temp_street = "null";
} message_from_esp;
#else
struct message_for_esp {
  String temp_street = "111.11";
} message_for_esp;
#endif



char value_string_parsing = 0;
char buf_char;
String buf_string;

uint32_t time_asking = 0;





//
