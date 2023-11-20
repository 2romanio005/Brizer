#include "time_pause.h"

time_pause::time_pause() {                                                              // конструктор по умолчанию
  this->del();
}
/*time_pause::time_pause(unsigned long hour , unsigned long min , unsigned long sec) {    // конструктор с заданием таймеров стразу(часы, минуты, секунды)
  this->reset(hour , min , sec);
}*/

void time_pause::reset(unsigned long hour , unsigned long min , unsigned long sec) {    // задать таймер(часы, минуты, секунды)
  while (sec > 59) {
    ++min;
    sec -= 60;
  }
  while (min > 59) {
    ++hour;
    min -= 60;
  }
  while (hour > 23) {
    hour -= 24;
  }

  DS3231 dst(SDA, SCL);
  dst.begin();
  Time time = dst.getTime();

  this->sec = time.sec;
  this->min = time.min;
  this->hour = time.hour;
  
  if (this->sec + sec > 59) {
    this->min++;
    this->sec += sec - 60;
  }
  else {
    this->sec += sec;
  }

  if (this->min + min > 59) {
    this->hour++;
    this->min += min - 60;
  }
  else {
    this->min += min;
  }

  if (this->hour + hour > 23) {
    this->hour += hour - 24;
  }
  else {
    this->hour += hour;
  }

}

void time_pause::reset(unsigned long sec) {                                             // задать таймер(только секунды)
  this->reset(0, 0, sec);
}

void time_pause::del() {                                                                // перевести таймер в спящий/выключенный режим
  this->hour = -1;       //такого врмени никогда не настанет(метод check() всегда возвраает false)
  this->min = 0;
  this->sec = 0;
}

bool time_pause::check_work() {                                                         // проверить в каком режиме таймер(выкл = 0\вкл = 1) 
  return (this->hour != -1);
}

bool time_pause::check() {                                                              // проверить вышло ли время таймера(да = 1\нет = 0)
  DS3231 dst(SDA, SCL);
  dst.begin();
  Time time = dst.getTime();
  if (this->hour != time.hour || this->min > time.min || this->sec > time.sec) {
    return 0;      //если время ещё не вышло
  }
  this->del();
  return 1;        //если время вышло
}

int time_pause::get_time_to_finish(){                                                   // позвращает время до завершения таймера в минутах
  if(this->check_work()){
    DS3231 dst(SDA, SCL);
    dst.begin();
    Time time = dst.getTime();
    return (((this->hour >= time.hour) ? (this->hour - time.hour) : (24 + this->hour - time.hour)) * 60 + this->min - time.min);
  }
  return 0;
}







//
