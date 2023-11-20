#include <avr/eeprom.h>            // для работы с энерго-независимой памятью(eeprom)
#include "GyverWDT.h"              // перезагрузка при зависание

#define free_eeprom 1003            // свободная(не занята настройками) энерго-независимая пымять (от 0 до free_eeprom)

//======================================================== ДЛЯ УДОБСТВА ПРОГРАМИСТА ================================================================================
// номера всех листов

#define namber_list_CO2 3           // количество графиков CO2
#define namber_list_temp_and_hot 3  // количество графиков температуры и энергозатрат(1 график - месяц)
#define namber_list_settings 10     // количество настроек

#define min 0
#define date 10
#define dow  1



int CO2_arr_month[namber_list_CO2][24];  // массив для графика CO2

byte size_TEMP_and_RUB_arr[namber_list_temp_and_hot];    // размеры всех массив температуры и энергозатрат
int RUB_arr_month[namber_list_temp_and_hot][31];         // рубли за месяц
int TEMP_arr_month[namber_list_temp_and_hot][31];        // массив для графика температуры



//  Watchdog.enable(RESET_MODE, 1024); // Режим сторжевого сброса , таймаут ~1с        (128 = ~1c)




void setup(){
  Serial.begin(9600);
  
  //создание и заполение массивов значениями по умолчанию
  clear_arr(CO2_arr_month[0], namber_list_CO2 * 24);             // CO2
  clear_arr(RUB_arr_month[0], namber_list_temp_and_hot * 31);    // температура
  clear_arr(TEMP_arr_month[0], namber_list_temp_and_hot * 31);   // энергозатраты

  Serial.println("start");


   // проверить был ли это запланированный ресет ((free_eeprom - количество графиков CO2 * 24) -по- free_eeprom)байты
    if (dow < namber_list_CO2) { // каждый понедельник - запланированный ресет (в 00:00 )       // !!!!!!!!!!!!!!!!!!!!!!!!!! (добать провеку что не прошло больше недели)
      int iter = 2 + (dow + 2 - namber_list_CO2) * 48;
      for (byte i = namber_list_CO2 - 1; i > (dow + 2 - namber_list_CO2); --i) {
        for (char j = 23; j >= 0; --j, iter += 2) {
          CO2_arr_month[i][j] = eeprom_read_word(free_eeprom - iter);             // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
      }
       Serial.println(eeprom_read_word(free_eeprom - iter) / 100.0);              // вспомнить требуемую температуры на выходе из бризеара
       Serial.println(eeprom_read_word(free_eeprom - iter - 2));          // вспомнить на сколько запустить проветривание
       Serial.println(boolean(eeprom_read_byte(free_eeprom - iter - 3)));         // вспонить тут ли человек
       Serial.println();
    }


  //чтение из памяти данных о графиках
  byte norm_iter_temp_arr_all = date - 1;








  
  { // сичтать данные о температуре и энергозатратах из памяти (0 -по- (namber_list_temp_and_hot * 125)  )байт
    // считывание данных из памяти
    size_TEMP_and_RUB_arr[0] = eeprom_read_byte(0);           // размер графика
    for (byte i = 0; i < size_TEMP_and_RUB_arr[0]; ++i){      // первый месяц
      TEMP_arr_month[0][i] = eeprom_read_word(namber_list_temp_and_hot + i * 4);
      RUB_arr_month[0][i]  = eeprom_read_word(namber_list_temp_and_hot + i * 4 + 2);
    }
    
    int iter = namber_list_temp_and_hot + 124;                // отступ на первый месяц и размеры графиков
    for (byte i = 1; i < namber_list_temp_and_hot; ++i) {     // все последующие месяца   
      size_TEMP_and_RUB_arr[i] = eeprom_read_byte(i);           // размеры графиков
      for (byte j = 0; j < size_TEMP_and_RUB_arr[i]; ++j) {     // сами графики
        TEMP_arr_month[i][j] = eeprom_read_word(iter);
        iter += 2;
        RUB_arr_month[i][j]  = eeprom_read_word(iter);
        iter += 2;
      }
    }

    // изменить массивы если был пропуск дней(простой)
    if (norm_iter_temp_arr_all < size_TEMP_and_RUB_arr[0]) {  // начался новый месяц
      move_temp_and_hot();                                       // сдвинуть графики температуры и энергозатрат
      size_TEMP_and_RUB_arr[0] = norm_iter_temp_arr_all;         // сбросить итератор
    }
    else {                                                // новый месяц ещё не начался
      while (size_TEMP_and_RUB_arr[0] < norm_iter_temp_arr_all) { // заполнить пропущенный дни значениями по умолчанию
        RUB_arr_month[0][size_TEMP_and_RUB_arr[0]] = 10111;
        TEMP_arr_month[0][size_TEMP_and_RUB_arr[0]++] = 10111;
      }
    }


    save_temp_and_hot();                                  // сохранить в эн.память графики температуры и энергозатрат
  }














  for(int i = 0; i < namber_list_temp_and_hot; ++i){
    Serial.print(size_TEMP_and_RUB_arr[i]);
    Serial.print('\t');
    for(int j = 0; j < 31; ++j){
      Serial.print(TEMP_arr_month[i][j]);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
  }
  Serial.println();
  Serial.println();
  Serial.println();

  for(int i = 0; i < namber_list_temp_and_hot; ++i){
    Serial.print(size_TEMP_and_RUB_arr[i]);
    Serial.print('\t');
    for(int j = 0; j < 31; ++j){
      Serial.print(RUB_arr_month[i][j]);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
  }

  Serial.println();
  Serial.println();
  Serial.println();

  for(int i = 0; i < namber_list_CO2; ++i){
    Serial.print("24");
    Serial.print('\t');
    for(int j = 0; j < 24; ++j){
      Serial.print(CO2_arr_month[i][j]);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
  }

  
}



void loop(){
  delay(5000);
}


void save_temp_and_hot() {                   // сохранить в эн.память графики температуры и энергозатрат
  eeprom_update_byte(0, size_TEMP_and_RUB_arr[0]);           // отдельно сохранить первый месяц
  for (byte i = 0; i < size_TEMP_and_RUB_arr[0]; ++i){
    eeprom_update_word(namber_list_temp_and_hot + i * 4, TEMP_arr_month[0][i]);
    eeprom_update_word(namber_list_temp_and_hot + i * 4 + 2, RUB_arr_month[0][i]);
  }
  
  int iter = namber_list_temp_and_hot + 124;                 // оставить место для продолжения первого месяца    и размеров графиков
  for (byte i = 1; i < namber_list_temp_and_hot; ++i) {      // перезапись графикоф температуры в пямять
    eeprom_update_byte(i, size_TEMP_and_RUB_arr[i]);           // размеры графиков
    for (byte j = 0; j < size_TEMP_and_RUB_arr[i]; ++j) {      // сами графики
      eeprom_update_word(iter, TEMP_arr_month[i][j]);
      iter += 2;
      eeprom_update_word(iter, RUB_arr_month[i][j]);
      iter += 2;
    }
  } 
}


void clear_arr(int* arr, unsigned int size) {        // заполняет массив [column * size] значениями по умолчанию
  for (unsigned int i = 0; i < size; ++i) {
    *(arr + i) = 11111;
  }
}


void move_temp_and_hot() {                   // сдвинуть графики температуры и энергозатрат на следующий месяц
  for (byte i = namber_list_temp_and_hot - 1; i > 0; --i) {      // сдвигание всех месяцев на одни вправо
    for (byte j = 0; j < 31; ++j) {                      // перемещение данных из предыдущего месяца в следующий
      RUB_arr_month[i][j] = RUB_arr_month[i - 1][j];
      RUB_arr_month[i - 1][j] = 11011;                 // заполнить старое значение значением по умолчинию

      TEMP_arr_month[i][j] = TEMP_arr_month[i - 1][j];
      TEMP_arr_month[i - 1][j] = 11011;                      // заполнить старое значение значением по умолчинию
    }
    size_TEMP_and_RUB_arr[i] = size_TEMP_and_RUB_arr[i - 1];     // сдвинуть также массив с размерами
  }
}
