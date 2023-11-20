#include "microDS18B20.h"
#include "tmp.h"

#define PinTermDsStreet 8  // пин, подключённый к синему проводу термометра,выходяшего наулицу(data)(нужен резистор 4.7 КОм к 5 вольтам)       УЛИЦА

MicroDS18B20 termDsStreet(PinTermDsStreet);  // датчик температуры
byte temp_iterator = 0;
int TEMP_arr[24];                 // массив для усреднения температуры за день
byte iterator_celsius = 0;          // итератор для датчиков температуры

MedianFilter<float> celsius_street;    // отфильтрованные значения с датчика температуры на улице


void setup() {
  Serial.begin(9600);  

  termDsStreet.requestTemp();

  for (byte i = 0; i < 3; ++i) {                        // для фильтрации датчика температуры
    celsius_street.set_value(termDsStreet.getTemp(), i);
  }

  start:
  for(byte i = 0; i < 24; ++i){
    termDsStreet.requestTemp();
    delay(200);
    Serial.print(String(termDsStreet.getTemp()) + '\t');
    celsius_street.set_value(termDsStreet.getTemp() - 30, iterator_celsius);  // наулице
    if (++iterator_celsius == 3) iterator_celsius = 0;
    //delay(200);
    TEMP_arr[temp_iterator] = 100 * celsius_street.get_value(); // запись значений графика температуры
    Serial.println(celsius_street.get_value());
    temp_iterator++;
  }

  float tmp = 0;
  for (byte i = 0; i < temp_iterator; ++i) {
    tmp += TEMP_arr[i];
  }
  Serial.println();
  Serial.println(round(tmp / float(temp_iterator)));
  eeprom_write_word(7, (round(tmp / float(temp_iterator))));
  delay(500);
  Serial.println(int(eeprom_read_word(7)));

  
  temp_iterator = 0;

  while(Serial.available() == 0){
    
  }
  Serial.println("=================");
  Serial.read();
  goto start;
}

void loop() {
//  sensor1.requestTemp();
//  sensor2.requestTemp();
//  sensor3.requestTemp();
//
//  delay(1000);  // между request и get нужна секунда (асинхронный режим)
//  Serial.print("t");
//  Serial.print(one_sensor);
//  Serial.print(": ");
//  Serial.print(sensor1.getTemp());
//  Serial.print("\t");
//  
//  Serial.print("t");
//  Serial.print(two_sensor);
//  Serial.print(": ");
//  Serial.print(sensor2.getTemp());
//  Serial.print("\t");
//
//  Serial.print("t");
//  Serial.print(three_sensor);
//  Serial.print(": ");
//  Serial.println(sensor3.getTemp());
}
