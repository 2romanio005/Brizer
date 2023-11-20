#include <avr/eeprom.h>            // для работы с энерго-независимой памятью(eeprom)

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

void setup() {
  for(byte i = 0; i < 24; ++i){
    CO2_arr_month[2][i] = 300 + i;  
  }
  for(byte i = 0; i < 24; ++i){
    CO2_arr_month[1][i] = 200 + i;  
  }
  for(byte i = 0; i < 24; ++i){
    CO2_arr_month[0][i] = 100 + i;  
  }
  


  
  size_TEMP_and_RUB_arr[0] = date - 1;
  Serial.begin(9600);
      if (true) {        // обработка всех событий с началом нового дня: графики температуры, CO2, энергозатрат
        for (byte i = namber_list_CO2 - 1; i > 0; --i) { // изменить графики CO2
          for (byte j = 0; j < 24; ++j) {   
            CO2_arr_month[i][j] = CO2_arr_month[i - 1][j];
          }
        }
        clear_arr(CO2_arr_month[0], 24);                 // очистить данные терущего дня ([0])


        {                             // если получено достаточно значений
          // сбор данных времени работы печки
          RUB_arr_month[0][size_TEMP_and_RUB_arr[0]] = size_TEMP_and_RUB_arr[0] * 10 + 1;



          // запись усреднённого значения температуры за день в массив

          TEMP_arr_month[0][size_TEMP_and_RUB_arr[0]] = size_TEMP_and_RUB_arr[0] * 10 + 1;
        }

        int tmp = 1;
        if (tmp != 1) {      // если новый месяц не наступил:
          // обновление данных в энергонезависимой памяти:
          eeprom_update_word((size_TEMP_and_RUB_arr[0] - 1) * 4 + namber_list_temp_and_hot, TEMP_arr_month[0][size_TEMP_and_RUB_arr[0]]);      // температура   !!!!!!!!!!!!!!!!
          eeprom_update_word((size_TEMP_and_RUB_arr[0] - 1) * 4 + namber_list_temp_and_hot + 2, RUB_arr_month[0][size_TEMP_and_RUB_arr[0]]);           // энергозатраты


          eeprom_update_byte(0, size_TEMP_and_RUB_arr[0]);                                                                        // последний обновлённый пункт
          size_TEMP_and_RUB_arr[0]++;
        }
        else {                     // обработка всех событий с началом нового месяца:
          size_TEMP_and_RUB_arr[0]++;
          move_temp_and_hot();                        // сдвинуть графики температуры и энергозатрат
          size_TEMP_and_RUB_arr[0] = 0;               // сбросить итератор на начало массива


          save_temp_and_hot();                        // сохранить в эн.память графики температуры и энергозатрат

        }

        if (dow == 1) {       // обработка всех событий с началом новой недели: плановая перезагрузка
          int iter = 2;
          Serial.println("new_week");
          for (byte i = namber_list_CO2 - 1; i > 0; --i) {
            for (char j = 23; j >= 0; --j, iter += 2) {                    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
              eeprom_update_word(free_eeprom - iter, CO2_arr_month[i][j]); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            }
          }
          eeprom_update_word(free_eeprom - iter, int(2020));
          eeprom_update_word(free_eeprom - iter - 2, int(10));
          eeprom_update_byte(free_eeprom - iter - 3, byte(1));

          delay(300);       // перезагрузка МК  
          Serial.println("Restrt");
        }
      }


}

void loop() {
  // put your main code here, to run repeatedly:

}






void clear_arr(int* arr, unsigned int size) {        // заполняет массив [column * size] значениями по умолчанию
  for (unsigned int i = 0; i < size; ++i) {
    *(arr + i) = 10111;
  }
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


void move_temp_and_hot() {                   // сдвинуть графики температуры и энергозатрат на следующий месяц
  for (byte i = namber_list_temp_and_hot - 1; i > 0; --i) {      // сдвигание всех месяцев на одни вправо
    for (byte j = 0; j < 31; ++j) {                      // перемещение данных из предыдущего месяца в следующий
      RUB_arr_month[i][j] = RUB_arr_month[i - 1][j];
      RUB_arr_month[i - 1][j] = 11111;                 // заполнить старое значение значением по умолчинию

      TEMP_arr_month[i][j] = TEMP_arr_month[i - 1][j];
      TEMP_arr_month[i - 1][j] = 11111;                      // заполнить старое значение значением по умолчинию
    }
    size_TEMP_and_RUB_arr[i] = size_TEMP_and_RUB_arr[i - 1];     // сдвинуть также массив с размерами
  }
}



  
