//=============================== ПОГДОТОВОКА ПЛАТЫ И МОДУЛЕЙ(для загрузки прошивки для бризера) ===============================================================


// количество различный графиков скопируйте из главной проги
#define namber_list_CO2 3           // количество графиков CO2
#define namber_list_temp_and_hot 7  // количество графиков температуры и энергозатрат(1 график - месяц)

#define test_memory                 // проверять хватает ли памяти (закоментированна - нет, не закоментированна - да)
#define free_eeprom 1005            // свободная(не занята настройками) энерго-независимая пымять (от 0 до free_eeprom)



//=============================== ИНИЦИАЛИЗАЦИЯ ВСЕГО ===========================================================================================================
#include <avr/eeprom.h>            //для работы с энерго-независимой памятью(eeprom)
#include <DS3231.h>                //библиотека для часов

//монитор - A4-SDA, A5-SCL
#include <iarduino_RTC.h>          //библиотека для часов

//часы - A4-SDA, A5-SCL
iarduino_RTC time(RTC_DS3231);  //пины подключённых часы(RST-перый(2), CLK-второй(4), DAT-третий(3))





void setup() {
  Serial.begin(9600);
  //====================================================== ЗАДАТЬ ВРЕМЯ В ЧАСАХ ======================================================================================
  Serial.println("start");
  
  
  time.begin();                       //часы 
  //time.settime(1,11,21,26,8,21,3);  //установка времени(сек,мин,час,день,месяц,год,день недели(0 - понедельник, 6 - воскресенье)        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  time.gettime(); 






  
#ifdef test_memory                                       // провека хватает ли памяти
  {
    int tmp = ((namber_list_CO2 - 1) * 48) + (namber_list_temp_and_hot * 125) + 5;    
    if (tmp >= free_eeprom) {                            // провека хватает ли памяти
      while (1) {
        Serial.println("\nMemory is over!");
        Serial.print("Overflow: ");
        Serial.println(tmp - free_eeprom + 1);
        delay(1000);
      }
    }else{
      Serial.print("Memory left: ");
      Serial.println(free_eeprom + 1 - tmp);
    }
  }
#endif



// очищение памяти
   


//  eeprom_update_byte(1023, 255);                         // сброс всех настроек

  for(byte i = 0; i < namber_list_temp_and_hot; ++i){    // графики температуры и энергозатрат
    eeprom_update_byte(i, 0);
  }

  

  int iter = 2;
  for (byte i = namber_list_CO2 - 1; i > 0; --i) {       // графики CO2
    for (char j = 23; j >= 0; --j, iter += 2) {
      eeprom_update_word(free_eeprom - iter, 11111);
    }
  }
  eeprom_update_word (free_eeprom - iter, 2000);         // доп переменные, нужные при перезагрузке
  eeprom_update_word (free_eeprom - iter - 2, 0);
  eeprom_update_byte (free_eeprom - iter - 3, 0);











 
  Serial.println("fin");
}

void loop() {
  time.gettime(); 

  Serial.print("day: ");       // вывод в сериал порт время с часов раз в секунду
  Serial.print(time.day);
  Serial.print("  ");
  Serial.print("month: ");
  Serial.print(time.month);
  Serial.print("  ");

  Serial.print("hour: ");
  Serial.print(time.Hours);    
  Serial.print("  ");
  Serial.print("min: ");
  Serial.print(time.minutes);
  Serial.print("  ");
  Serial.print("sec: ");
  Serial.print(time.seconds);
  Serial.print("  ");
  
  Serial.print("week: ");
  switch (time.weekday) {
    case 6:
      Serial.println("Sun7");
      break;
    case 0:
      Serial.println("Mon1");
      break;
    case 1:
      Serial.println("Tue2");
      break;
    case 2:
      Serial.println("Wed3");
      break;
    case 3:
      Serial.println("Thu4");
      break;
    case 4:
      Serial.println("Fri5");
      break;
    case 5:
      Serial.println("Sat6");
      break;
  }
  delay(1000);

}
