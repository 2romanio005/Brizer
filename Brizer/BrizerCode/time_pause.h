//============================================================ ТАЙМЕР НА ЧАСАХ =======================================================================================

#pragma once
#include <DS3231.h>          //библиотека для часов

class time_pause {
  public:
    time_pause();                                                           // конструктор по умолчанию
//    time_pause(unsigned long hour , unsigned long min , unsigned long sec); // конструктор с заданием таймеров стразу(часы, минуты, секунды)

    void reset(unsigned long hour , unsigned long min , unsigned long sec); // задать таймер(часы, минуты, секунды)
    void reset(unsigned long sec);                                          // задать таймер(только секунды)
    void del();                 // перевести таймер в спящий/выключенный режим
    bool check_work();          // проверить в каком режиме таймер(выкл = 0\вкл = 1) 
    bool check();               // проверить вышло ли время таймера(да = 1\нет = 0)
    int get_time_to_finish();   // позвращает время до завершения таймера в минутах
  private:
    int hour;     // часы тамера
    byte min;     // минуты таймера
    byte sec;     // секунды таймера
};
