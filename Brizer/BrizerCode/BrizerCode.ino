//========================================================== ПРОЕКТ - БРИЗЕР ========================================================================================

//#define type_brizer         //принимает температуру с улицы - не коментируем(бризер OLD), если отдаёт то - коментируем(бризе NEW)



#ifdef type_brizer
//======================================================== ПЕРЕМЕННЫЕ НАСТРОЕК OLD БРИЗЕРА ======================================================================================

#define on_vent 55              // минуты работы для уменьшения показаний Co2 (мин)(от 1 до 59 мин)                                              (настраиваемая в меню)    @
#define CO2_no_good 650         // показания, при привышение которых автоматически вклчается проветривание(от 0 до 5000 ppm)                     (настраиваемая в меню)    @
#define update_celsius_NORM 90  // частота обновления темпераутры, поддерживаемой на выходе (мин, от 0 до 99) при 0 изменений не происходит      (настраиваемая в меню)    @
#define celsius_NORM 23.8       // температура которая будет поддерживаться в комнате                                                            (настраиваемая в меню)    @

#define time_nite 23        // час - начало ночи (включая)(час)(от 1 до 24 часов)                                                                 (настраиваемая в меню)    @
#define time_no_nite 8      // час - конец ночи(включая)(час)(от 1 до 24 часов)                                                                   (настраиваемая в меню)    @
#define check_temp 7       // минуты, за которое печка должна успеть нагреть воздух до приемлемого(если не успеет то выключит прветривание, чтобы было теплее)(минуты)         (настраиваемая в меню)   @
#define on_display 120      // секунды, через которое монитор переходит на начальный экран и выключается если энкодр неподвижен(сек)  если отрицательное - никогда не сработает (настраиваемая в меню)   @

#define CO2_out_people 550  // CO2 при котором считается что человека нет в комнате
#define time_out_people 5  // время проверки дома ли чловек(минуты)

#define power_hot 1000.0    // мощность пчеки в Вт/ч 
#define day_cost 4.06       // цена электричества в дневное время (руб/кВт)       (настраиваемая в меню)    @
#define night_cost 2.34     // цена электричества в ночное время  (руб/кВт)       (настраиваемая в меню)    @
#define time_day_cost 23    // время дневнго тарифа за элекричество (включая) (ч)
#define time_naght_cost 7   // время ночного тарифа за элекричество (включая) (ч)

#define winter_begin 12     // начало зимы(включая)
#define winter_end 2        // конец зимы(включая)



#define eeprom_first_on_ 69     // поменяй на любое другое число от 0 до 254 при загрузке в плату если хочешь поменять настройки(те что можно менять в меню)

#define type_graf_temp          // меняет вид графика температуры(для изменния закоментиковать строку)       //(не коментированное = ноль в центре, коментиованное = ноль снизу)

//================================================ ПОДКЛЮЧЕНИЕ УСТРОЙСТВ И ИМОДУЛЕЙ(РАСПИНОВКА) OLD БРИЗЕРА =====================================================================

//монитор - A4-SDA, A5-SCL
//часы - A4-SDA, A5-SCL

#define adressMon 0x3F     //адрес кристалического экрана(либо "0x27" - новый, либо "0x3F" - старый)

#define dPinHot A2         //пин на реле вкл/выкл пекчи
#define InvHot                 //ивертировать пин для печки(поставить "!" для инвертации или пробел если без)
#define dPinVentDay 10     //пин на реле день для вентелятора
#define InvVentDay             //ивертировать пин день для вентелятора(поставить "!" для инвертации или пробел если без)
#define dPinVentNite A3    //пин на реле ночь для вентелятора
#define InvVentNite            //ивертировать пин ночь для вентелятора(поставить "!" для инвертации или пробел если без)

#define APinCO2TX A0       //аналоговый пин для датчика Co2 TX(пин A0)
#define APinCO2RX A1       //аналоговый пин для датчика Co2 RX(пин A1)

#define PinTermDsHot 7     //пин, подключённый к синему проводу термометра,на выходе из бризера(data)(нужен резистор 4.7 КОм к 5 вольтам)     БРИЗЕР
//#define PinTermDsStreet 8  //пин, подключённый к синему проводу термометра,выходяшего наулицу(data)(нужен резистор 4.7 КОм к 5 вольтам)        УЛИЦА
#define PinTermsDsHome 5   //пин, подключённый к синему проводу термометра,в комнате(data)(нужен резистор 4.7 КОм к 5 вольтам)       ДОМ 

#define CLK_S1 2           //пин CLK или S1 для энкодера(цифровой)
#define DT_S2 3            //пин DT или S2 для энкодера (цифровой)
#define SW_Key 9           //пин SW или Key для энкодера(аналоговый или цифровой)





#else
//======================================================== ПЕРЕМЕННЫЕ НАСТРОЕК NEW БРИЗЕРА ======================================================================================

#define on_vent 55              // минуты работы для уменьшения показаний Co2 (мин)(от 1 до 59 мин)                                               (настраиваемая в меню)    @
#define CO2_no_good 650         // показания, при привышение которых автоматически вклчается проветривание(от 0 до 5000 ppm)                      (настраиваемая в меню)    @
#define update_celsius_NORM 90  // частота обновления темпераутры, поддерживаемой на выходе (мин, от 0 до 99) при 0 изменений не происходит       (настраиваемая в меню)    @
#define celsius_NORM 23.8       // температура которая будет поддерживаться в комнате                                                             (настраиваемая в меню)    @

#define time_nite 23        // час - начало ночи (включая)(час)(от 1 до 24 часов)                                                                 (настраиваемая в меню)    @
#define time_no_nite 8      // час - конец ночи(включая)(час)(от 1 до 24 часов)                                                                   (настраиваемая в меню)    @
#define check_temp 7        // минуты, за которое печка должна успеть нагреть воздух до приемлемого(если не успеет то выключит прветривание, чтобы было теплее)(минуты)          (настраиваемая в меню)   @
#define on_display 120      // секунды, через которое монитор переходит на начальный экран и выключается если энкодр неподвижен(сек)  если отрицательное - никогда не сработает (настраиваемая в меню)   @

#define CO2_out_people 430  // CO2 при котором считается что человека нет в комнате
#define time_out_people 5  // время проверки дома ли чловек(минуты)

#define power_hot 650.0     // мощность пчеки в Вт/ч 
#define day_cost 4.06       // цена электричества в дневное время (кВт/ч)         (настраиваемая в меню)    @
#define night_cost 2.34     // цена электричества в ночное время (кВт/ч)          (настраиваемая в меню)    @
#define time_day_cost 23    // время дневнго тарифа за элекричество (включая) (ч)
#define time_naght_cost 7   // время ночного тарифа за элекричество (включая) (ч)

#define winter_begin 12     // начало зимы (включая)
#define winter_end 2        // конец зимы  (включая)



#define eeprom_first_on_ 68     // поменяй на любое другое число от 0 до 254 при загрузке в плату если хочешь поменять сохраняемые настройки(те что можно менять в меню)

#define type_graf_temp          // меняет вид графика температуры(для изменния закоментиковать строку)       //(не коментированное = ноль в центре, коментиованное = ноль снизу)

//================================================ ПОДКЛЮЧЕНИЕ УСТРОЙСТВ И ИМОДУЛЕЙ(РАСПИНОВКА) NEW БРИЗЕРА =====================================================================

//монитор - A4-SDA, A5-SCL
//часы - A4-SDA, A5-SCL

#define adressMon 0x27     // адрес кристалического экрана(либо "0x27" - новый, либо "0x3F" - старый)

#define dPinHot A2         // пин на реле вкл/выкл пекчи
#define InvHot                 // ивертировать пин для печки(поставить "!" для инвертации или пробел если без)
#define dPinVentDay 10     // пин на реле день для вентелятора
#define InvVentDay !           // ивертировать пин день для вентелятора(поставить "!" для инвертации или пробел если без)
#define dPinVentNite A3    // пин на реле ночь для вентелятора
#define InvVentNite !          // ивертировать пин ночь для вентелятора(поставить "!" для инвертации или пробел если без)

#define APinCO2TX A0       // аналоговый пин для датчика Co2 TX(пин A0)
#define APinCO2RX A1       // аналоговый пин для датчика Co2 RX(пин A1)

#define PinTermDsHot 7     // пин, подключённый к синему проводу термометра,на выходе из бризера(data)(нужен резистор 4.7 КОм к 5 вольтам)     БРИЗЕР
#define PinTermDsStreet 8  // пин, подключённый к синему проводу термометра,выходяшего наулицу(data)(нужен резистор 4.7 КОм к 5 вольтам)       УЛИЦА
#define PinTermsDsHome 5   // пин, подключённый к синему проводу термометра,в комнате(data)(нужен резистор 4.7 КОм к 5 вольтам)                ДОМ 

#define CLK_S1 2           // пин CLK или S1 для энкодера(цифровой)
#define DT_S2 3            // пин DT или S2 для энкодера (цифровой)
#define SW_Key 9           // пин SW или Key для энкодера(аналоговый или цифровой)

#endif





//============================================================== БИБЛИОТЕКИ =======================================================================================

#include "time_pause.h"            // паузы с помощью часов
#include "Settings_Control.h"      // хранение и изменение переменных настроек
#include "MedianFilter.h"

#include <avr/eeprom.h>            // для работы с энерго-независимой памятью(eeprom)
#include <DS3231.h>                // библиотека для часов
#include <Wire.h>                  // хз чё
#include <LiquidCrystal_I2C.h>     // библиотрека для кристалического экрана
#include <SoftwareSerial.h>        // библиотека для Co2 датчика
#include "GyverEncoder.h"          // библиотека для энкодера
#include "microDS18B20.h"          // библиотека для термометра
#include "GyverPID.h"              // для PID регулятора у печки
#include "GyverWDT.h"              // перезагрузка при зависание

//========================================================= ИНДЕФИКАЦИЯ УСТРОЙСТВ ==================================================================================

LiquidCrystal_I2C lcd(adressMon, 16, 2);     // настройки кристалического экрана (первое число в скобках - адрес(либо "0x27", либо "0x3F")если не работате не то, не то - в инет)

MicroDS18B20 termDsHot(PinTermDsHot);        // датчик температуры          //пин, подключённый к синему проводу термометра,на выходе из бризера (data)(нужен резистор 4.7 КОм к 5 вольтам)  (см.раньше)
#ifndef type_brizer
MicroDS18B20 termDsStreet(PinTermDsStreet);  // датчик температуры          //пин, подключённый к синему проводу термометра,выходяшего наулицу (data)(нужен резистор 4.7 КОм к 5 вольтам)  (см.раньше)
#endif
MicroDS18B20 termDsHome(PinTermsDsHome);     // датчик температуры          //пин, подключённый к синему проводу термометра,дома (data)(нужен резистор 4.7 КОм к 5 вольтам)  (см.раньше)

GyverPID regulator(5, 0.0585, 15, 1000);     // коэф. П, коэф. И, коэф. Д, период дискретизации dt (мс) для PID регулятора у печки

DS3231 dst(SDA, SCL);                        // часы
Time time;

Encoder enc(CLK_S1, DT_S2, SW_Key);          // пины к которым подключен энкодер

SoftwareSerial mySerial(APinCO2TX, APinCO2RX); // TX, RX для датчика CO2


//======================================================== ДЛЯ УДОБСТВА ПРОГРАМИСТА ================================================================================

#define sec_control_CO2 5                 // врем между проверками датчика CO2 (сек)(от 1 сек до много сек)      
#define CO2_graf_paunts 100               // за сколько принимать одну ячейку графика CO2 (ppm)(от 1 до 300)
#define CO2_graf_min 4                    // с какой нижней ячейки начинать рисовать графики CO2 (от 0 до 50)( минимальное CO2 наулице / CO2_graf_paunts )
#define Start_celsius_NORM 20.0           // начальная температура требуемая на выходе из бризера
#define period_PID 1000.0                 // частота пид регулятора (1 секунда)
#define WDT_PRESCALER 128                 // максимальное время прохождения loop цикла (при привышении автоматическая перезагрузка)    (128 = ~1c)    // 64 // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// номера всех листов
#define list_time 0       // лист с текушим временем и датчиком CO2  
#define list_temp 1       // лист с различными температурами  
#define list_CO2_graf 2   // лист с графиком CO2
#define list_temp_graf 3  // лист с графиком температуры
#define list_hot_graf 4   // лист с графиком энергозатрат
#define list_settings 5   // ЭТОТ ВСЕГДА ДОЛЖЕН БЫТЬ ПОСЛЕДНИМ(самое большое число)  // лист с настройками

#define namber_list_CO2 3           // количество графиков CO2(1 график - день)
#define namber_list_temp_and_hot 7  // количество графиков температуры и энергозатрат(1 график - месяц)
#define namber_list_settings 10     // количество настроек

//#define test_memory                 // проверять хватает ли памяти (закоментированна - нет, не закоментированна - да)
#define free_eeprom 1005            // свободная(не занята настройками) энерго-независимая пымять (от 0 до free_eeprom)


//======================================================================== МАКРОСЫ ===================================================================================================

#define reset_me() asm("JMP 0")

//============================================================ НЕ РЕАЛИЗОВАННОЕ(или ненужное :D ) ====================================================================================


//#define PinLed A2     //пин на светодиод

//================================================== ОПИСАНИЕ ФУНКЦИЙ ИСПОЛЬЗУЕМЫХ В ДРУГИХ ФУНКЦИЯХ И СО ЗНАЧЕНИЯМИ ПО УМОЛЧАНИЮ ====================================================

void lcd_clear_value(const byte line = 0, const byte column = 0, const byte size = 2);
template <typename T>
void lcd_print_value(const T value, const T size = 2);


//==================================================================== ПЕРЕМЕННЫЕ ДЛЯ РАБОТЫ ПРОГРАММЫ ===============================================================================

MedianFilter<float> celsius_hot;       // отфильтрованные значения с датчика температуры из бризера
MedianFilter<float> celsius_street;    // отфильтрованные значения с датчика температуры на улице
MedianFilter<float> celsius_home;      // отфильтрованные значения с датчика температуры дома
byte iterator_celsius = 0;          // итератор для датчиков температуры
MedianFilter<int> ppm;                 // отфильтрованные значения с датчика CO2
byte iterator_CO2 = 0;              // итератор для датчика CO2

#ifdef type_brizer
byte iterator_celsius_street = 0;  //отдельный итератор для фильтрации температуры с улицы получаемой со второго бризера
#endif



int CO2_arr_month[namber_list_CO2][24];  // массив для графика CO2

int RUB_naw_month = 0;            // цена за последний месяц работы
int RUB_before_month = 0;         // цена за предыдущий месяц работы
int Wt_from_day = 0;              // ватт за сегодня
float P_counter_day = 0;          // ватт в денневном тарифе
float P_counter_night = 0;        // ватт в ночном тарифе

long TEMP_sum = 0;                // сумма данных темппературы на улице за день для нахождения арифметического среднего
byte temp_iterator = 0;           // считает в какой элемнт записать температуру за час

byte work_hot = 0;                // загруженость печки в процентах




byte cmd[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};  // для считывания CО2
byte response[9];                                                      // для считывания CО2

bool flag_out_people = 0;          // флаг, показывающий есть ли человек в комнате или нет   0 - есть 1 - нет

bool flag;                     // для ПИД регулятора
uint32_t tmr;                  // тоже ПИД




int8_t value_string_parsing = 0;   // общение с esp
String buf_string;





// флаги для обновления монитора по частям
bool flag_update_date;        // дата
bool flag_update_work_hot;    // процент работы печки
bool flag_time_hot;           // целиком лист с энергозатратами
bool flag_graf_CO2;           // график CO2
bool flag_graf_temp;          // график температуры
bool flag_settings;           // целиком лист с настройками



// для настроек с помощью энкодера
bool choose_type = 0;
bool choose_settings = 0;

byte choose_mod = 0;
bool flag_speed_choose = 0;
bool flag_out_speed_choose = 0;



byte time_control_new_hour = 0;        // обработка всех событий с началом нового часа: запись значений с датчика температуры для графика, активация провека CO2, сбора данных времени работы печки

uint32_t time_control_sec_events = 0;  // для ежесекундных событий + опрос CO2
byte time_control_CO2 = 0;             // для опроса датчика температуры раз в 5 секунтд

time_pause time_time_out_people;       //таймер проверки на наличие человека в комнате

time_pause time_on_vent;               //таймер для работы проветривания

time_pause time_update_celsius_NORM;   //таймер для обновления требуемой температуры на выходе из бризера
time_pause time_check_temp;            //таймер за который печка должна успеть нагреть воздух до приемлемого

time_pause time_speed_choose;          //таймер для бысых изменений настроек
time_pause time_on_display;            //таймер для сборас экрана на начальное положение

time_pause time_time_hot_day;          //таймер для запоминания времени работы печки днём
time_pause time_time_hot_night;        //таймер для запоминания времени работы печки ночью


//те переменные которые можно менять энкодором
Settings_Control<byte> Settings_time_nite(time_nite, 23);                                                         // время начала ночи
Settings_Control<byte> Settings_time_no_nite(time_no_nite, 23);                                                   // время конца ночи
Settings_Control<byte> Settings_check_temp(check_temp, 59, 1, 0, &time_check_temp);                               // время для проверки хватает ли печик для нагрева (связана с таймером)
//Settings_Control<int>  Settings_on_display(on_display, 9990, 10, 0, &time_on_display);                            // время до спящего режима у экана (связана с таймером)
Settings_Control<int>  Settings_on_display(on_display, 9990, 10);                                                 // время до спящего режима у экана (связана с таймером)

Settings_Control<byte> Settings_on_vent(on_vent, 59, 1, 1, &time_on_vent);                                        // время работы вентилятора(связана с таймером)
Settings_Control<int>  Settings_CO2_no_good(CO2_no_good, 5000, 10, 10);                                           // показания CO2 при которых включается поветривание
Settings_Control<float>Settings_celsius_NORM(celsius_NORM, 50, 0.1);                                              // температура, которую нужно поддерживать в комнате
Settings_Control<byte> Settings_update_celsius_NORM(update_celsius_NORM, 99, 1, 0, &time_update_celsius_NORM);    // время между изменениями температуры требуемой на выходе из бризера(связана с таймером)

Settings_Control<int>  Settings_CO2_out_people(CO2_out_people, 5000, 10, 10);                                     // CO2 при котором считается что человека нет в комнате
Settings_Control<byte> Settings_time_out_people(time_out_people, 99, 1, 0, &time_time_out_people);                // время через которое проходит проверка на наличие человека в комнате(связана с таймером)

Settings_Control<float> Settings_day_cost(day_cost, 9.99, 0.01);                                                  // цена за дневное электричество
Settings_Control<float> Settings_night_cost(night_cost, 9.99, 0.01);                                              // цена за ночное электричество



Settings_Control<byte> Settings_namber_list(0, list_settings);                // основные листы экрана

Settings_Control<byte> Settings_namber_graf_CO2(0, namber_list_CO2 * 2 - 1);                  // подлисты графиков CO2
Settings_Control<byte> Settings_namber_graf_temp(0, namber_list_temp_and_hot * 3 - 1);    // подлисты графиков температуры
Settings_Control<byte> Settings_namber_graf_hot(0, namber_list_temp_and_hot * 3 + 1);     // подлисты графиков затрат
Settings_Control<byte> Settings_namber_settings(0, namber_list_settings - 1);             // подлисты настроек



void setup() { // ===================================================== VOID SETUP() ================================================================================
  delay(5000);
  Serial.begin(9600);      // сериал порт(используется для общения с esp)
  mySerial.begin(9600);    // CO2 датчик
  //  Serial.println(F("setup_start"));

  //============================================================== НАСТРОЙКИ УСТРОЙСТВ ===============================================================================

  enc.setType(TYPE2);            // тип энкодера TYPE1 одношаговый, TYPE2 двухшаговый. Если ваш энкодер работает странно, смените тип (у нас лучше 2 тип работает)
  enc.setDirection(REVERSE);     // в какую сторону поворот энкодера REVERSE или NORM
  attachInterrupt(0, isr, 2);    // прерывание на 2 пине! CLK у энка(поворот)
  attachInterrupt(1, isr, 2);    // прерывание на 3 пине! DT у энка(поворот в другую сторону)

  pinMode(dPinVentNite, OUTPUT); // релешка на ночной режим вентилятора
  pinMode(dPinVentDay, OUTPUT);  // релешка н адневной режим вентилятора
  pinMode(dPinHot, OUTPUT);      // релешка на печку
  //pinMode(PinLed, OUTPUT);     // светодиод

  digitalWrite(dPinVentNite, InvVentNite(0));
  digitalWrite(dPinVentDay, InvVentDay(0));
  digitalWrite(dPinHot, InvHot(0));
  //digitalWrite(PinLed, 0);

  regulator.setDirection(InvHot(NORMAL));    // направление регулирования (NORMAL/REVERSE). менять не надо уже настроено
  regulator.setLimits(0, 255);               // пределы значений шима (ставим для 8 битного ШИМ). ПО УМОЛЧАНИЮ СТОЯТ 0 И 255
  regulator.setpoint = Start_celsius_NORM;   // сообщаем регулятору температуру, которую он должен поддерживать

  //delay(3000);
  lcd.init();                     // для дисплея
  lcd.backlight();

  dst.begin();                    // для часов

  /*   // изменить дату (изменяй в first_file_for_brizer)
    dst.setDOW(WEDNESDAY);        //  установить день недели  MONDAY(1) TUESDAY(2) WEDNESDAY(3) THURSDAY(4) FRIDAY(5) SATURDAY(6) SUNDAY(7)
    dst.setTime(23, 59, 40);      //  установить время(часы, минуты, секунды)(24 формат)
    dst.setDate(30, 9, 2020);     //  установить дату(день ,месяц ,год)
  */

  time = dst.getTime();       // получение времени с часов

  updated_monitor();          // полное обновение экрана



#ifdef test_memory
  { // проверка хватит ли энергонезависимой памяти
    int tmp = ((namber_list_CO2 - 1) * 48) + 5 + (namber_list_temp_and_hot * 125);
    if (tmp >= free_eeprom) {
      lcd.setCursor(0, 0);
      lcd.print("Memory is over!");
      lcd.setCursor(0, 1);
      lcd.print("Overflow:");
      lcd.print(tmp - free_eeprom + 1);
      while (1) {}
    }
  }
#endif



  // создание и заполение массивов значениями по умолчанию
  clear_arr(CO2_arr_month[0], 24 * namber_list_CO2);                      // график CO2

  termDsHot.requestTemp();
#ifndef type_brizer
  termDsStreet.requestTemp();
#endif
  termDsHome.requestTemp();
  for (byte i = 0; i < 3; ++i) {                        // для фильтрации датчика температуры
    celsius_hot.set_value(termDsHot.getTemp(), i);
#ifndef type_brizer
    celsius_street.set_value(termDsStreet.getTemp(), i);
#else
    celsius_street.set_value(111.11, i);
#endif
    celsius_home.set_value(termDsHome.getTemp(), i);
  }




  // считывание настроек из энерго-независимой памяти
  if (eeprom_read_byte(1023) != eeprom_first_on_) {     // если это первое включение то забить ячейки памяти значениями по умолчанию и отметить что первое включение произошло (999 - 1023)байты
    eeprom_write_byte(1023, eeprom_first_on_);

    eeprom_update_word(1021, celsius_NORM * 100);
    eeprom_update_byte(1020, update_celsius_NORM);
    eeprom_update_word(1018, CO2_no_good);
    eeprom_update_byte(1017, on_vent);

    eeprom_update_byte(1016, time_nite);
    eeprom_update_byte(1015, time_no_nite);
    eeprom_update_word(1013, on_display);
    eeprom_update_byte(1012, check_temp);

    eeprom_update_word(1010, CO2_out_people);
    eeprom_update_byte(1009, time_out_people);

    eeprom_update_word(1007, day_cost * 100);
    eeprom_update_word(free_eeprom, night_cost * 100);
    delay(500);
  }
  else {                                                // если включение не первое то считать настройки из памят
    Settings_celsius_NORM.set_value(eeprom_read_word(1021) * 0.01);
    Settings_update_celsius_NORM.set_value(eeprom_read_byte(1020));
    Settings_CO2_no_good.set_value(eeprom_read_word(1018));
    Settings_on_vent.set_value(eeprom_read_byte(1017));

    Settings_time_nite.set_value(eeprom_read_byte(1016));
    Settings_time_no_nite.set_value(eeprom_read_byte(1015));
    Settings_on_display.set_value(eeprom_read_word(1013));
    Settings_check_temp.set_value(eeprom_read_byte(1012));

    Settings_CO2_out_people.set_value(eeprom_read_word(1010));
    Settings_time_out_people.set_value(eeprom_read_byte(1009));

    Settings_day_cost.set_value(eeprom_read_word(1007) * 0.01);
    Settings_night_cost.set_value(eeprom_read_word(free_eeprom) * 0.01);
  }


  // задание первых таймеров
  if (Settings_update_celsius_NORM.get_value() != 0) {  // таймер обновления требуемой температуры на выходе
    time_update_celsius_NORM.reset(0, Settings_update_celsius_NORM.get_value(), 0);
  }
  if (Settings_time_out_people.get_value() != 0) {      // таймер проверки на наличие человека в комнате
    time_time_out_people.reset(0, Settings_time_out_people.get_value(), 0);
  }
  time_control_new_hour = time.hour;                    // для отслеживания начала нового часа



  { // проверить остались ли данные с последнего сохранения CO2 + каждый понедельник - запланированный ресет (в 00:00 ) (((free_eeprom - количество графиков CO2 - 1) * 48) - 5 -по- free_eeprom)байты
    if (time.dow < namber_list_CO2) {

      int iter = 2 + (time.dow + 2 - namber_list_CO2) * 48;
      for (byte i = namber_list_CO2 - 1; i > (time.dow + 2 - namber_list_CO2); --i) {
        for (char j = 23; j >= 0; --j, iter += 2) {
          CO2_arr_month[i][j] = eeprom_read_word(free_eeprom - iter);
        }
      }

      for (byte i = 0; i < 3; ++i) {                            // вспомнить последние значения CO2
        ppm.set_value(CO2_arr_month[1][23], i);
      }

      if (time.dow == 1 && time.min == 0) {                     // если это плановая перезагрузка то вспомнить доп переменные
        regulator.setpoint = (eeprom_read_word(free_eeprom - iter) / 100.0);         // вспомнить требуемую температуры на выходе из бризеара
        time_on_vent.reset(0, eeprom_read_word(free_eeprom - iter - 2), 0);          // вспомнить на сколько запустить проветривание
        flag_out_people = boolean(eeprom_read_byte(free_eeprom - iter - 3));         // вспонить тут ли человек
        time_on_display.reset(0);                                                    // выключить дисплей
      }
    }
  }


  /*
    день первого месяца: namber_list_temp_and_hot + 4 * (текущ число - нужный день - 1)
  
    день второго-все_остальные_месяца: namber_list_temp_and_hot + 124 + 4 * (кол_дней в всех_пред_мес(кроме 1) - 1)     + 4 * нжный день
  */
  //чтение из памяти данных о графиках температуры и энергозатрат
  byte norm_iter_temp_arr_all = time.date - 1;
  { // проверить данные о температуре и энергозатратах из памяти (0 -по- (namber_list_temp_and_hot * 125)  )байт
    byte size_first = eeprom_read_byte(0);           // размер графика


    // изменить массивы если был пропуск дней(простой)
    if (norm_iter_temp_arr_all < size_first) {       // начался новый месяц
      move_temp_and_hot();                                      // сдвинуть графики температуры и энергозатрат
      size_first = 0;
    }
    while (norm_iter_temp_arr_all > size_first) {    // заполнить пропущенный дни значениями по умолчанию
      eeprom_update_dword(namber_list_temp_and_hot + size_first * 4, 728181607);
      ++size_first;
    }
    eeprom_update_byte(0, norm_iter_temp_arr_all);             // сбросить итератор

    get_RUB_last_month();                                 // пересчёт некоторых значений для монитора энергозатрат
  }


  Watchdog.enable(RESET_MODE, WDT_PRESCALER); // Режим сторжевого сброса , таймаут ~1с        (128 = ~1c)
  //  Serial.println(F("setup_finish"));

}


//uint32_t time_;


void loop()  { // ===================================================== VOID LOOP() =================================================================================
  //time_ = millis();
  { // получение времени с часов
    byte tmp_min = time.min;
    time = dst.getTime();
    if (tmp_min != time.min) {                      // обновить ли дату на мониторе?
      flag_update_date = 1;
    }

  }

  //  Serial.print(millis() - time_);
  //  Serial.print(',');
  //  //time_ = millis();

  { // работа с lcd дисплеем
    if (choose_type == 0 && enc.isRightH()) {                    // перелистывание страниц вправо
      //      lcd.noBlink();
      //      lcd.noCursor();

      Settings_namber_list.change_value_up();

      updated_monitor();           //обновить все значения
    }
    if (choose_type == 0 && enc.isLeftH()) {                     // перелистывание страниц влево
      //      lcd.noBlink();
      //      lcd.noCursor();

      Settings_namber_list.change_value_down();

      updated_monitor();           //обновить все значения
    }

    enc.tick();

    if (enc.isTurn() || enc.isPress()) {                         // включение дисплея
      if (Settings_on_display.get_value() != 0 && time_on_display.check_work() == 0) {              //если дисплей выключен
        lcd.backlight();
        Settings_namber_list.set_value(0);

        updated_monitor();           //обновить все значения
      }
      if (Settings_on_display.get_value() != 0) {
        time_on_display.reset(Settings_on_display.get_value());
      } else {
        time_on_display.del();
      }
    }
    if (time_on_display.check()) {                               // выключение дисплея
      lcd.noBacklight();

      lcd.noBlink();
      lcd.noCursor();

      Settings_namber_list.set_value(0);

      Settings_namber_graf_CO2.set_value(0);    // сбросить все подлисты на начальный
      Settings_namber_graf_temp.set_value(0);
      Settings_namber_graf_hot.set_value(0);
      Settings_namber_settings.set_value(0);


      choose_type = 0;                          // выйти из режима настроек
      choose_settings = 0;
      time_speed_choose.del();
      choose_mod = 0;
      flag_speed_choose = 0;
      flag_out_speed_choose = 0;
    }

    if (enc.isClick()) {                                         // вхождение\выхождение на страницу
      if (choose_type == 0) {                  // если сейчас не в режиме выбора подлиста
        if (Settings_namber_list.get_value() != list_temp && Settings_namber_list.get_value() != list_time) {   // если это не тот лит на котором нет подлистов
          choose_type = 1;     // закрепить это лист и перемещать по его подлистам
          lcd.setCursor(0, 0);
          lcd.cursor();
          lcd.blink();
        }
      } else {                       // если сейчас не в режиме выбора листа, а уже вощёл в лист по клику
        if ((Settings_namber_list.get_value() == list_settings || (Settings_namber_list.get_value() == list_hot_graf && Settings_namber_graf_hot.get_value() <= 1)) && choose_settings == 0) {      //если это лист с настройками и режим настраивания не включён
          choose_settings = 1;      // включить режим настраивания
          lcd.noBlink();
        }
        else {          // выключить режим настраивания и перехода между подлистами
          lcd.noBlink();
          lcd.noCursor();

          if (choose_settings) { //если был в режиме настроек
            switch (Settings_namber_list.get_value()) {         //сохраненить в энергонезависимую память настройки и другое
              case list_hot_graf:
                eeprom_update_word(1007, Settings_day_cost.get_value() * 100);
                eeprom_update_word(free_eeprom, Settings_night_cost.get_value() * 100);

                Settings_namber_graf_hot.set_value(0);
                break;
              case list_settings:
                save_settings();

                Settings_namber_settings.set_value((Settings_namber_settings.get_value() / 4) * 4);
                //                while (Settings_namber_settings.get_value() % 4 != 0) {
                //                  Settings_namber_settings.change_value_down();
                //                }
                break;
            }
          }

          choose_type = 0;
          choose_settings = 0;
          flag_out_speed_choose = 0;
          choose_mod = 0;
          flag_speed_choose = 0;
        }
      }
    }

    if (choose_settings) {                                       // настройки
      if (enc.isHold()) {
        if (time_speed_choose.check_work() == 0) {     // если таймер выключен
          time_speed_choose.reset(1);
        }
        byte mod = 2;
        if (enc.isRightH()) {
          time_speed_choose.reset(1);
          choose_mod = 1;
          flag_out_speed_choose = 0;
          flag_speed_choose = 0;
          mod = 1;
        }
        if (enc.isLeftH()) {
          time_speed_choose.reset(1);
          choose_mod = 2;
          flag_out_speed_choose = 0;
          flag_speed_choose = 0;
          mod = 0;
        }
        if (flag_speed_choose == 1 && time_speed_choose.check()) {
          time_speed_choose.reset(0);
          delay(25);
          flag_out_speed_choose = 1;
          if (choose_mod == 1) {
            mod = 1;
          } else {
            mod = 0;
          }
        }

        if (mod != 2) {  // здесь все изменения самих настроек
          if (Settings_namber_list.get_value() == list_settings) {

            /*                                                  // тоже-самое но вроде хуже
              {                   // изменение переменных при их настройке
              Settings_Control<int>  *temp_value_int = NULL;
              Settings_Control<byte> *temp_value_byte = NULL;

              byte temp_namber_settings = Settings_namber_settings.get_value();
              bool type = 0;
              if (temp_namber_settings == 0) {
                mod ? Settings_celsius_NORM.change_value_up() : Settings_celsius_NORM.change_value_down();
              }
              else {
                switch (temp_namber_settings) {
                  case 1:
                    temp_value_byte =  &Settings_update_celsius_NORM;
                    break;
                  case 2:
                    temp_value_int = &Settings_CO2_no_good;
                    type = 1;
                    break;
                  case 3:
                    temp_value_byte = &Settings_on_vent;
                    break;
                  case 4:
                    temp_value_byte = &Settings_time_nite;
                    break;
                  case 5:
                    temp_value_byte = &Settings_time_no_nite;
                    break;
                  case 6:
                    temp_value_int = &Settings_on_display;
                    type = 1;
                    break;
                  case 7:
                    temp_value_byte = &Settings_check_temp;
                    break;
                  case 8:
                    temp_value_int = &Settings_CO2_out_people;
                    type = 1;
                    break;
                  case 9:
                    temp_value_byte = &Settings_time_out_people;
                    break;
                };
                type ? (mod ? temp_value_int->change_value_up() : temp_value_int->change_value_down()) : (mod ? temp_value_byte->change_value_up() : temp_value_byte->change_value_down());

              }
              }

              {                   // обновляет переменные на мониторе когда их настраивают
              switch (Settings_namber_settings.get_value()) {
                case 0:
                  lcd_clear_value(4, 0, 4);
                  lcd_print_value(int(Settings_celsius_NORM.get_value()));
                  lcd.setCursor(6, 0);
                  lcd.print('.');
                  lcd.print(int(Settings_celsius_NORM.get_value() * 10) - (int(Settings_celsius_NORM.get_value())) * 10);
                  break;
                case 1:
                  lcd_clear_value(14, 0);
                  lcd.print(Settings_update_celsius_NORM.get_value());
                  break;
                case 2:
                  lcd_clear_value(4, 1, 5);
                  lcd_print_value(Settings_CO2_no_good.get_value());
                  break;
                case 3:
                  lcd_clear_value(14, 1);
                  lcd_print_value(Settings_on_vent.get_value());
                  break;

                case 4:
                  lcd_clear_value(6, 0);
                  lcd_print_value(Settings_time_nite.get_value());
                  break;
                case 5:
                  lcd_clear_value(14, 0);
                  lcd_print_value(Settings_time_no_nite.get_value());
                  break;
                case 6:
                  lcd_clear_value(4, 1, 5);
                  lcd_print_value(Settings_on_display.get_value());
                  break;
                case 7:
                  lcd_clear_value(14, 1);
                  lcd_print_value(Settings_check_temp.get_value());
                  break;

                case 8:
                  lcd_clear_value(4, 0, 5);
                  lcd_print_value(Settings_CO2_out_people.get_value());
                  break;
                case 9:
                  lcd_clear_value(14, 0);
                  lcd_print_value(Settings_time_out_people.get_value());
              }
              }

            */

            { // изменение основных настроек
              if (Settings_namber_settings.get_value() == 0) {  // единственная настройка с float
                //mod ? Settings_celsius_NORM.change_value_up() : Settings_celsius_NORM.change_value_down();
                if (mod) {
                  Settings_celsius_NORM.change_value_up();
                } else {
                  Settings_celsius_NORM.change_value_down();
                }
                lcd_clear_value(4, 0, 4);
                lcd.print(abs(Settings_celsius_NORM.get_value()), 1);

//                lcd_print_value(int(Settings_celsius_NORM.get_value()));
//                lcd.setCursor(6, 0);
//                lcd.print('.');
//                lcd.print(int(Settings_celsius_NORM.get_value() * 10) - (int(Settings_celsius_NORM.get_value())) * 10);
              }
              else {                                            // все остальные настройки
                auto pointer_int = [&mod](Settings_Control<int> *point) {
                  if (mod) {
                    point->change_value_up();
                  } else {
                    point->change_value_down();
                  }
                };
                auto pointer_byte = [&mod](Settings_Control<byte> *point) {
                  if (mod) {
                    point->change_value_up();
                  } else {
                    point->change_value_down();
                  }
                };

                switch (Settings_namber_settings.get_value()) {
                  case 1:
                    pointer_byte(&Settings_update_celsius_NORM);
                    lcd_clear_value(14, 0);
                    lcd.print(Settings_update_celsius_NORM.get_value());
                    break;
                  case 2:
                    pointer_int(&Settings_CO2_no_good);
                    lcd_clear_value(4, 1, 5);
                    lcd_print_value(Settings_CO2_no_good.get_value());
                    break;
                  case 3:
                    pointer_byte(&Settings_on_vent);
                    lcd_clear_value(14, 1);
                    lcd_print_value(Settings_on_vent.get_value());
                    break;

                  case 4:
                    pointer_byte(&Settings_time_nite);
                    lcd_clear_value(6, 0);
                    lcd_print_value(Settings_time_nite.get_value());
                    break;
                  case 5:
                    pointer_byte(&Settings_time_no_nite);
                    lcd_clear_value(14, 0);
                    lcd_print_value(Settings_time_no_nite.get_value());
                    break;
                  case 6:
                    pointer_int(&Settings_on_display);
                    lcd_clear_value(4, 1, 5);
                    lcd_print_value(Settings_on_display.get_value());

                    if (Settings_on_display.get_value() != 0) {     // единственный таймер в секундах а не минутах
                      time_on_display.reset(Settings_on_display.get_value());
                    } else {
                      time_on_display.del();
                    }
                    break;
                  case 7:
                    pointer_byte(&Settings_check_temp);
                    lcd_clear_value(14, 1);
                    lcd_print_value(Settings_check_temp.get_value());
                    break;

                  case 8:
                    pointer_int(&Settings_CO2_out_people);
                    lcd_clear_value(4, 0, 5);
                    lcd_print_value(Settings_CO2_out_people.get_value());
                    break;
                  case 9:
                    pointer_byte(&Settings_time_out_people);
                    lcd_clear_value(14, 0);
                    lcd_print_value(Settings_time_out_people.get_value());
                }
              }
            }

          }
          else {                                              // изменение настроек горячего экрана
            //HotControl(mod);
            Settings_Control<float> *temp_value_float = NULL;
            switch (Settings_namber_graf_hot.get_value()) {
              case 0:
                temp_value_float = &Settings_day_cost;
                break;
              case 1:
                temp_value_float = &Settings_night_cost;
                break;
            }

            mod ? (temp_value_float->change_value_up()) : (temp_value_float->change_value_down());
            flag_time_hot = 1;  //обновить 3 лист (с печкой там)
          }
        }

      } else {
        time_speed_choose.del();
        if (flag_out_speed_choose) {
          flag_speed_choose = 0;
        } else if (choose_mod != 0) {
          flag_speed_choose = 1;
        }
      }
    }

    if (choose_type && enc.isHold() && choose_settings == 0) {   // перемещение между подлистами
      Settings_Control<byte> *temp_value = NULL;
      switch (Settings_namber_list.get_value()) {
        case list_CO2_graf:
          temp_value = &Settings_namber_graf_CO2;
          break;
        case list_temp_graf:
          temp_value = &Settings_namber_graf_temp;
          break;
        case list_hot_graf:
          temp_value = &Settings_namber_graf_hot;
          break;
        case list_settings:
          temp_value = &Settings_namber_settings;
          break;
      }

      if (enc.isRightH()) {
        temp_value->change_value_up();
        updated_monitor();           //обновить все значения
      }
      if (enc.isLeftH()) {
        temp_value->change_value_down();
        updated_monitor();           //обновить все значения
      }
    }



    switch (Settings_namber_list.get_value()) {                  // отрисовка монитора
      case list_time:          //лист со временем(начальный)
        {
          enc.tick();
          if (flag_update_date) {
            flag_update_date = 0;
            enc.tick();

            //lcd_clear_value(0, 0, 16);
            lcd.setCursor(0, 0);
            lcd_print_value(time.date);                   // вывод текушего дня
            lcd.print('.');
            lcd_print_value(time.mon);                    // вывод текушего месяца

            //lcd.setCursor(6, 0);
            lcd.print(' ');
            lcd_print_value(time.hour);                   // вывод текушего времени (часы)
            lcd.print(':');
            lcd_print_value(time.min);                    // вывод текушего времени (мин)

            //lcd.setCursor(12, 0);                         // вывод текушего дня недели
            //lcd.print(' ');
            switch (time.dow) {
              case 7:
                lcd.print(F(" Sun7"));
                break;
              case 1:
                lcd.print(F(" Mon1"));
                break;
              case 2:
                lcd.print(F(" Tue2"));
                break;
              case 3:
                lcd.print(F(" Wed3"));
                break;
              case 4:
                lcd.print(F(" Thu4"));
                break;
              case 5:
                lcd.print(F(" Fri5"));
                break;
              case 6:
                lcd.print(F(" Sat6"));
                break;
            }

            lcd_clear_value(8, 1, 8);                   //вывести время до окончания проветривания
            if (time_on_vent.check_work()) {
              lcd.print(F("vent"));
              lcd.print(time_on_vent.get_time_to_finish());
              lcd.setCursor(15, 1);
              if (Day_or_no()) {
                lcd.print('H');
              } else {
                lcd.print('L');
              }
              //lcd.print(Day_or_no());
            }

          }

          if (ppm.flag_update) {
            ppm.flag_update = 0;
            //вывод текушего Co2
            lcd.setCursor(0, 1);
            lcd.print(F("CO"));
            lcd_print_mini_two(2, 1);
            lcd_clear_value(3, 1, 5);
            lcd.print(ppm.get_value());
          }
          break;
        }
      case list_temp:          //лист с датчиками(температуры)
        {
          enc.tick();
          if (celsius_street.flag_update) {  //вывести температуру с улицы
            celsius_street.flag_update = 0;
            lcd_clear_value(0, 0, 10);
            lcd.print(F("Ext"));
            float tmp = celsius_street.get_value();
            if (tmp == 111.11) {
              lcd.print(" ----");
            } else {
              if (tmp >= 0) {
                lcd.print('+');
              } else {
                lcd.print('-');
              }
              lcd_print_value(abs(int(tmp)));
              lcd.print('.');
              lcd.print(abs(int(tmp * 10)) - (int(tmp) * 10));
            }
            lcd_print_degree(8, 0);
            lcd.print(' ');
          }

          if (celsius_hot.flag_update) {     //вывести темепературу у печки
            celsius_hot.flag_update = 0;
            lcd_clear_value(10, 0, 7);
            lcd.print(F("Hot"));
            lcd_print_value(abs(int(round(celsius_hot.get_value()))));
            lcd_print_degree(15, 0);
          }

          if (celsius_home.flag_update) {    //вывести температуру в доме
            celsius_home.flag_update = 0;
            lcd_clear_value(0, 1, 10);
            lcd.print(F("Home"));

            lcd_print_value(abs(int(celsius_home.get_value())));
            lcd.print('.');
            lcd.print(abs(int(celsius_home.get_value() * 10)) - (int(celsius_home.get_value()) * 10));
            lcd_print_degree(8, 1);
          }

          if (flag_update_work_hot) {     //вывести процент работы печки
            flag_update_work_hot = 0;
            lcd_clear_value(10, 1, 6);

            if (work_hot == 100) {
              lcd.setCursor(12, 1);
            } else if (work_hot > 9) {
              lcd.setCursor(13, 1);
            } else {
              if (flag_out_people) {        // если челомека нет в комнате
                lcd.print(F("Emp"));
              }
              lcd.setCursor(14, 1);
            }
            lcd.print(work_hot);
            lcd.print('%');
          }

          break;
        }
      case list_CO2_graf:      //лист с графиком CO2
        {
          enc.tick();
          if (flag_graf_CO2) {    // вывести график CO2
            //lcd.clear();
            flag_graf_CO2 = 0;

            lcd.setCursor(0, 0);
            lcd.print(F(" CO2"));
            lcd.setCursor(0, 1);

            int8_t tmp;
            if (Settings_namber_graf_CO2.get_value() < 2) {
              tmp = time_control_new_hour;
            } else {
              tmp = 24;
            }
            if (Settings_namber_graf_CO2.get_value() % 2 == 1) {
              tmp -= 12;
            }

            byte size_;
            if (tmp < 12) {
              size_ = tmp;
            } else {
              size_ = 12;
            }

            if (tmp <= 0 || CO2_arr_month[Settings_namber_graf_CO2.get_value() / 2][tmp - 1] == 11111) {                           // вывести время самаго первого пункта в графике
              lcd.print(F("--"));
            } else {
              lcd_print_value(tmp - 1);
            }

            if (Settings_namber_graf_CO2.get_value() < 9) {
              lcd.print(' ');
            }
            lcd.print((Settings_namber_graf_CO2.get_value() + 1));                                                                 // вывести номер подлиста

            print_graf(CO2_arr_month[Settings_namber_graf_CO2.get_value() / 2] + tmp, size_, 12, CO2_graf_min, CO2_graf_paunts);   // вывести сам график

            lcd.setCursor(0, 0);
          }
          break;
        }
      case list_temp_graf:     //лист с графиком температутры
        {
          enc.tick();
          if (flag_graf_temp) {
            //lcd.clear();
            flag_graf_temp = 0;

            if (Settings_namber_graf_temp.get_value() < 9) {
              lcd.print(' ');
            }
            lcd.print(F("t^C"));
            lcd.print(Settings_namber_graf_temp.get_value() + 1);

            int8_t size_;
            int* tmp_arr = get_graf_by_eeprom_for_print(124 + namber_list_temp_and_hot, Settings_namber_graf_temp.get_value(), size_);


#ifdef type_graf_temp                                 // определить вид графика
            int8_t zero = get_zero(tmp_arr + size_, size_, 100);       // график с нулём в центре
            graf_temp(tmp_arr + size_, size_, 11, zero, 100);
#else
            int8_t zero = get_zero_graf(tmp_arr + size_, size_, 100);  // графи с нулём снизу
            print_graf(tmp_arr + size_, size_, 11, zero, 100);
#endif
            delete[] tmp_arr;

            lcd.setCursor(2, 1);
            if (zero == 111) {                                           // вывести ноль графика температуры
              lcd.print(F(" --"));
            } else {
              if (zero > 0) {
                lcd.print('+');
              } else if (zero < 0) {
                lcd.print('-');
              } else {
                lcd.print(' ');
              }

              lcd_print_value(abs(zero));
            }

            lcd.setCursor(0, 0);
          }
          break;
        }
      case list_hot_graf:      //лист с рублями
        {
          enc.tick();
          if (flag_time_hot) {
            lcd.clear();
            flag_time_hot = 0;

            if (Settings_namber_graf_hot.get_value() <= 1) {       // выбрать что показывать: настройки...
              lcd.setCursor(1, 0);
              lcd.print('D');
              lcd.print(Settings_day_cost.get_value());       // дневной тариф

              lcd.setCursor(7, 0);
              lcd.print('W');
              lcd_print_value(Wt_from_day, 5);                       // ваты за день

              lcd.setCursor(1, 1);
              lcd.print('N');
              lcd.print(Settings_night_cost.get_value());     // ночной тариф

              lcd_print_rub(7, 1);
              lcd_print_value(RUB_naw_month, 4);             // цена за последние 30 дгей работы

              lcd.setCursor(13, 1);
              lcd_print_value(int(round((P_counter_day * Settings_day_cost.get_value() + P_counter_night * Settings_night_cost.get_value()) / 1000.0)), 2);   // вывести затраты(рубли) за день
            }
            else {                                                 // ...или графики
              if (Settings_namber_graf_hot.get_value() < 11) {
                lcd.print(' ');
              }
              lcd.print(F("RUB"));
              lcd.print(Settings_namber_graf_hot.get_value() - 1);

              int8_t size_;
              int* tmp_arr = get_graf_by_eeprom_for_print(126 + namber_list_temp_and_hot, Settings_namber_graf_hot.get_value() - 2, size_);
              //129, 8
              //Serial.println(size_);
              int8_t zero = get_zero_graf(tmp_arr + size_, size_, 100);           // получить ноль графика
              print_graf(tmp_arr + size_, size_, 11, zero, 100);                  // вывести сам график

              delete[] tmp_arr;

              lcd.setCursor(2, 1);
              lcd.print(' ');
              if (zero == 111) {                                          // вывести ноль графика
                lcd.print(F("--"));
              } else {
                lcd_print_value(zero);
              }




              //              graf_RUB(arr);
            }


            if (Settings_namber_graf_hot.get_value() == 1) {       // поставить курсор в нужное место
              lcd.setCursor(0, 1);
            }
            else {
              lcd.setCursor(0, 0);
            }
          }
          break;
        }
      case list_settings:      //лист с настройками
        {
          enc.tick();
          if (flag_settings) {
            lcd.clear();
            flag_settings = 0;
            switch (Settings_namber_settings.get_value() / 4) {
              case 0:
                lcd.setCursor(1, 0);                            //вывест температуру, которую надо поддерживать в комнате
                lcd.print(F("nrm"));
                lcd.setCursor(4, 0);
                lcd.print(abs(Settings_celsius_NORM.get_value()), 1);
//                lcd_print_value(int(Settings_celsius_NORM.get_value()));
//                lcd.setCursor(6, 0);
//                lcd.print('.');
//                lcd.print(int(Settings_celsius_NORM.get_value() * 10) - (int(Settings_celsius_NORM.get_value())) * 10);

                lcd.setCursor(9, 0);
                lcd.print(F("vary"));
                lcd.setCursor(14, 0);
                lcd.print(Settings_update_celsius_NORM.get_value());   //вывести время между изменениями температуры, которую надо поддерживать в комнате

                lcd.setCursor(1, 1);
                lcd.print(F("CO"));
                lcd_print_mini_two(3, 1);
                lcd.setCursor(4, 1);
                lcd_print_value(Settings_CO2_no_good.get_value());  //вывести кол Co2 при привышене которого включается печка

                lcd.setCursor(9, 1);
                lcd.print(F("work "));
                lcd.setCursor(14, 1);
                lcd_print_value(Settings_on_vent.get_value());    //вывести время работы проветривания
                break;
              case 1:
                lcd.setCursor(1, 0);
                lcd.print(F("night"));
                lcd.setCursor(6, 0);
                lcd_print_value(Settings_time_nite.get_value());   //вывести време - начало ночи

                lcd.setCursor(9, 0);
                lcd.print(F("day  "));
                lcd.setCursor(14, 0);
                lcd_print_value(Settings_time_no_nite.get_value());   //вывести време - конец ночи

                lcd.setCursor(1, 1);
                lcd.print(F("mon"));
                lcd.setCursor(4, 1);
                lcd_print_value(Settings_on_display.get_value());       //вывести время, через которое монитор переходит на начальный экран и выключается если энкодр не подвижен

                lcd.setCursor(9, 1);
                lcd.print(F("check"));
                lcd.setCursor(14, 1);
                lcd_print_value(Settings_check_temp.get_value());  //вывести время, за которое печка должна успеть нагреть воздух до приемлемого
                break;
              case 2:
                lcd.setCursor(1, 0);
                lcd.print(F("Men"));
                lcd.setCursor(4, 0);
                lcd_print_value(Settings_CO2_out_people.get_value());   //вывести CO2 нет человека в комнате

                lcd.setCursor(9, 0);
                lcd.print(F("t_Men"));
                lcd.setCursor(14, 0);
                lcd_print_value(Settings_time_out_people.get_value());   //вывести време - проверки на человека в комнате
                break;
            }
          }

          switch (Settings_namber_settings.get_value() % 4) {
            case 0:
              lcd.setCursor(0, 0);
              break;
            case 1:
              lcd.setCursor(8, 0);
              break;
            case 2:
              lcd.setCursor(0, 1);
              break;
            case 3:
              lcd.setCursor(8, 1);
              break;
          }

          break;
        }
    }

  }

  //  Serial.print(millis() - time_);
  //  Serial.print(',');
  //  //time_ = millis();

  { // главная часть проги + опрос датчиков температуры и CO2

    if (time.hour != time_control_new_hour) {         // обработка всех событий с началом нового часа, дня и тд: запись значений с датчиков температуры/CO2 для графиков, активация провеки CO2, сбор данных времени работы печки

      { // запись значений графика CO2 и активация проветривание
        CO2_arr_month[0][time_control_new_hour] = ppm.get_value();        // задать новый элемент

        if (CO2_arr_month[0][time_control_new_hour] > Settings_CO2_no_good.get_value() && time_on_vent.get_time_to_finish() <= Settings_on_vent.get_value()) {
          time_on_vent.reset(0, Settings_on_vent.get_value(), 0);         // запустить проветривание

          flag_out_people = 0;                       // выкчить режим без человека
          tmr = millis();
        }
      }

      time_control_new_hour = time.hour;                          // сбросить таймер на новый час   !нужен здесь не двигай вверх!
      updated_monitor();                                          // обновить все значения для монитора

      if (celsius_street.get_value() != 111.11) {
        TEMP_sum += 100 * celsius_street.get_value();             // запись значений графика температуры
        ++temp_iterator;
      }

      if (time_control_new_hour == 0) {                           // обработка всех событий с началом нового дня: графики температуры, CO2, энергозатрат
        Watchdog.disable();

        for (byte i = namber_list_CO2 - 1; i > 0; --i) {                      // изменить графики CO2
          for (byte j = 0; j < 24; ++j) {
            CO2_arr_month[i][j] = CO2_arr_month[i - 1][j];
          }
        }
        clear_arr(CO2_arr_month[0], 24);                                      // очистить данные текущего дня ([0])


        int tmp_iter = eeprom_read_byte(0) * 4 + namber_list_temp_and_hot;
        if (temp_iterator < 23) {                                             // если за день не получено достаточное колличество значений температуры о работе печки
          eeprom_update_dword(tmp_iter, 728181607);
          //          RUB_arr_month[0][size_TEMP_and_RUB_arr[0]] = 11111;
          //          TEMP_arr_month[0][size_TEMP_and_RUB_arr[0]] = 11111;
        }
        else {                                                                // если получено достаточно значений
          // запись усреднённого значения температуры за день в массив
          eeprom_write_word(tmp_iter, round(TEMP_sum / float(temp_iterator)));
          TEMP_sum = 0;
          temp_iterator = 0;

          // запись цены работы печки
          eeprom_write_word(tmp_iter + 2, round((P_counter_day * Settings_day_cost.get_value() + P_counter_night * Settings_night_cost.get_value()) / 10.0));

          P_counter_day = 0;
          P_counter_night = 0;

        }
        get_RUB_last_month();                                                 // пересчёт некоторых значений для монитора энергозатрат

        eeprom_write_byte(0, eeprom_read_byte(0) + 1);                                                                                     // колличество сохранённых дней

        if (time.date == 1) {                                                 // обработка всех событий с началом нового месяца:
          move_temp_and_hot();                                                              // сдвинуть графики температуры и энергозатрат
        }

        if (time.dow == 1) {                                                  // обработка всех событий с началом новой недели: плановая перезагрузка
          int iter = 2;                                                                     // записать графики CO2 в память
          for (byte i = namber_list_CO2 - 1; i > 0; --i) {
            for (char j = 23; j >= 0; --j, iter += 2) {
              eeprom_update_word(free_eeprom - iter, CO2_arr_month[i][j]);
            }
          }
          eeprom_update_word(free_eeprom - iter, regulator.setpoint * 100);                 // записать температуру на выходе
          eeprom_update_word(free_eeprom - iter - 2, (time_on_vent.check_work() ? time_on_vent.get_time_to_finish() : 0));     // записать сколько времени ещё работь вентилятору
          eeprom_update_byte(free_eeprom - iter - 3, byte(flag_out_people));                // записать дома ли человек

          delay(300);                                                                       // перезагрузка МК        !!!!!!!!!!!!!!!!!!!!!!!!!!!
          reset_me();                                                                       // перезагрузка МК
        }

        Watchdog.enable(RESET_MODE, WDT_PRESCALER); // Режим сторжевого сброса , таймаут ~1с        (128 = ~1c)
      }

    }



    if (millis() - time_control_sec_events >= 1000) { // счётчик ватов потребляемых печкой, опрос датчиков температуры, задание силы работы печки, опрос датчика  CO2
      time_control_sec_events = millis();

      //                                                                        РАБОТА С ДАТЧИКАМИ ТЕМПЕРАТУРЫ
      termDsHot.requestTemp();
#ifndef type_brizer
      termDsStreet.requestTemp();
#endif
      termDsHome.requestTemp();

      celsius_hot.set_value(termDsHot.getTemp(), iterator_celsius);        // у печки
#ifndef type_brizer
      celsius_street.set_value(termDsStreet.getTemp(), iterator_celsius);  // наулице
#endif
      celsius_home.set_value(termDsHome.getTemp(), iterator_celsius);      // в комнате

      if (++iterator_celsius == 3) iterator_celsius = 0;



      //                                                                           РАБОТА С ПИД РЕГУЛЯТОРОМ
      if (flag_out_people == 0) {                               // обычный режим работы
        regulator.input = celsius_hot.get_value();                                                    // сообщаем регулятору текущую температуру (при обычном режиме работы)
        regulator.getResult();

        if (time.hour >= time_naght_cost || time.hour <= time_day_cost) {                             // добавить в счётчик ватов(дня или ночи) ватты за секунду
          P_counter_night += (power_hot / 3600.0 * regulator.output / 255.0);
        } else {
          P_counter_day += (power_hot / 3600.0 * regulator.output / 255.0);
        }

        flag_time_hot = update_value(Wt_from_day, int(round(P_counter_day + P_counter_night)));       // для понимание изменится ли что-то на горячем листе если да то обновить его

        // проверка на включение режима без человка
        if (time_on_vent.check_work() == 0 && ppm.get_value() < Settings_CO2_out_people.get_value() && celsius_home.get_value() > Settings_celsius_NORM.get_value()) {   // вентилятор выключен, CO2 маленькое и температура высокая - человека нет в комнате
          if (Settings_time_out_people.get_value() != 0 && time_time_out_people.check_work() == 0) {    // запускаем таймер на возможное включение режима без человека
            time_time_out_people.reset(0, Settings_time_out_people.get_value(), 0);
          }

          if (time_time_out_people.check()) {                                                            // если таймер вышел то комната пустая
            flag_out_people = 1;                                                                              // комната пустая

            flag_update_work_hot = 1;                                                                         // обновить вывод на мониторе режима с человеком
          }

        } else {
          time_time_out_people.del();                                                                    // одно из условий нарушено и человек всё же дома
        }

      }
      else {                                                    // режим работы без человека в комнате
        regulator.input = regulator.setpoint;        // чтобы не было резкого скачка
        regulator.getResult();
        regulator.output = 0;                        // выключить печку

        if (ppm.get_value() > Settings_CO2_out_people.get_value() || celsius_home.get_value() <= Settings_celsius_NORM.get_value()) {   // если чеолвек появился или слишком холодно
          flag_out_people = 0;                       // выкчить режим без человека
          tmr = millis();
          flag_update_work_hot = 1;                  // обновить вывод на мониторе режима с человеком
        }
      }

      /*
            Serial.print(celsius_hot);
            Serial.print(",");
            Serial.print(regulator.setpoint);
            Serial.print(",");
            Serial.print(float(regulator.output / 25.5));
            Serial.print(",");
            Serial.print(flag_out_people * 5 + 2);
            Serial.print(",");
            Serial.print(digitalRead(dPinHot) * 5 + 1);
            Serial.print(",");
            Serial.println(Settings_celsius_NORM.get_value());
        //      Serial.print(",");
        //      Serial.println(celsius_home);
      */

      flag_update_work_hot = update_value(work_hot, byte(round(regulator.output / 2.55)));   // обновить процент работы печки



      if (++time_control_CO2 == sec_control_CO2) { //                                           СБОР ТЕКУШИХ ПОКАЗАНИЙ С ДАТЧИКА CO2
        time_control_CO2 = 0;

        mySerial.write(cmd, 9);
        memset(response, 0, 9);
        mySerial.readBytes(response, 9);
        byte crc = 0;
        for (byte i = 1; i < 8; i++) crc += response[i];
        crc = 255 - crc;
        ++crc;

        if (response[0] == 0xFF && response[1] == 0x86 && response[8] == crc) {
          //update_value(ppm, int(256 * response[2] + response[3]));   // получить ppm из 2 байтов датчика([2] - старший байт, [3] - младший байт)
          ppm.set_value(int(256 * response[2] + response[3]), iterator_CO2);
          if (++iterator_CO2 == 3) iterator_CO2 = 0;
        } else {
          mySerial.begin(9600);
        }

        //        if ( !(response[0] == 0xFF && response[1] == 0x86 && response[8] == crc) ) {
        //          mySerial.begin(9600);
        //        }
        //        else {
        //          flag_update_ppm = update_value(ppm, int(256 * response[2] + response[3]));   // получить ppm из 2 байтов датчика([2] - старший байт, [3] - младший байт)
        //        }
      }
    }
    PWM_hot_tick();                                   // управлять печкой с помощью низкочастотного ШИМа


    if (time_update_celsius_NORM.check()) {           // если настало время изменения температуры на выходе
      if (Settings_update_celsius_NORM.get_value() != 0) {
        time_update_celsius_NORM.reset(0, Settings_update_celsius_NORM.get_value(), 0);
      }

      regulator.setpoint = constrain((regulator.setpoint + Settings_celsius_NORM.get_value() - float(celsius_home.get_value())), Settings_celsius_NORM.get_value() - 6, Settings_celsius_NORM.get_value() + 6);
    }


    if (time_on_vent.check_work()) {                  // если проветривание включено
      if (Day_or_no()) {                                                           // дневной или ночной режим вентилятора
        digitalWrite(dPinVentNite, InvVentNite(0));          //дневной режим вентилятора
        digitalWrite(dPinVentDay, InvVentDay(1));
      } else {
        digitalWrite(dPinVentNite, InvVentNite(1));          //ночной режим вентилятора
        digitalWrite(dPinVentDay, InvVentDay(0));
      }
      if (time_on_vent.check()) {                                                  // если время проветривания кончилось - выключить вентилятор
        digitalWrite(dPinVentDay, InvVentDay(0));
        digitalWrite(dPinVentNite, InvVentNite(0));

        flag_update_date = 1;   // убрать врямя до конца проветривания с монитора
      }

      if (time_on_vent.check_work() && celsius_hot.get_value() < regulator.setpoint) {  // если температуры на выходе маленькая и вентилятор включен
        if (time_check_temp.check_work() == 0 && Settings_check_temp.get_value() != 0) {   // запустить отсчёт для проверки хватает ли печки для нормальной температуры
          time_check_temp.reset(0, Settings_check_temp.get_value(), 0);
        }

        if (time_check_temp.check()) {                                                     // если печка несправляется - выключить проветривание
          digitalWrite(dPinVentDay, InvVentDay(0));    // выключить проветривание
          digitalWrite(dPinVentNite, InvVentNite(0));
          time_on_vent.del();

          flag_update_date = 1;                         // убрать врямя до конца проветривания с монитора

          time_check_temp.del();                        // завешить отсчёт для проверки хватает ли печки для нормальной температуры
        }

      } else {
        time_check_temp.del();                                                             // завешить отсчёт для проверки хватает ли печки для нормальной температуры
      }

    }

  }

  //  Serial.print(millis() - time_)
  //  Serial.println(',');


  { // общение Arduino с esp6288
    if (Serial.available() > 0) {      // проверка на содержание данных в буфере
      char buf_char = Serial.read();
      switch (buf_char) {
        case '!':    // пришёл запрос от esp - отправить данные
          {
            Watchdog.disable();

            void(*tmp_foo)() = []() {
              Serial.print(';');
            };
            void(*tmp_foo_two)() = []() {
              Serial.print('/');
            };

            value_string_parsing = 0;

#ifndef type_brizer
            Serial.print(celsius_street.get_value());       // датчик с улицы есть только у одного
            tmp_foo();
#endif

            Serial.print(celsius_hot.get_value());
            tmp_foo();
            Serial.print(celsius_home.get_value());
            tmp_foo();
            Serial.print(ppm.get_value());
            tmp_foo();
            Serial.print(work_hot);
            tmp_foo();
            Serial.print(Wt_from_day);
            tmp_foo();
            Serial.print(RUB_naw_month);
            tmp_foo();
            Serial.print(RUB_before_month);
            tmp_foo();
            Serial.print(int(round((P_counter_day * Settings_day_cost.get_value() + P_counter_night * Settings_night_cost.get_value()) / 1000.0)));

            tmp_foo_two();                                                        // данные с датчкиов кончились


            Serial.print(Settings_CO2_no_good.get_value());
            tmp_foo();
            Serial.print(Settings_on_vent.get_value());
            tmp_foo();
            Serial.print(time_on_vent.get_time_to_finish());
            tmp_foo();
            Serial.print(Settings_celsius_NORM.get_value());
            tmp_foo();
            Serial.print(Settings_check_temp.get_value());
            tmp_foo();
            Serial.print(Settings_update_celsius_NORM.get_value());
            tmp_foo();
            Serial.print(Settings_CO2_out_people.get_value());
            tmp_foo();
            Serial.print(Settings_time_out_people.get_value());
            tmp_foo();
            Serial.print(Settings_time_nite.get_value());
            tmp_foo();
            Serial.print(Settings_time_no_nite.get_value());
            tmp_foo();
            Serial.print(Settings_on_display.get_value());
            //            tmp_foo();

            tmp_foo_two();                                                        // настройки кончились




            for (byte i = 0; i < namber_list_CO2; ++i) {                        // отправить графики CO2
              byte j = 0;

              while (true) {
                if (CO2_arr_month[i][j] == 11111) {
                  Serial.print(F("null"));
                } else {
                  Serial.print(CO2_arr_month[i][j]);
                }

                if (++j == 24) {
                  break;
                }
                Serial.print(',');
              }

              Serial.print(';');
            }
            tmp_foo_two();         // график CO2 кончился


            void (*graf_json)(const byte size, int &iter) = [](const byte size, int &iter) {     // отправка графиков температуры энергозатрат для esp
              byte i = 0;
              while (size > 0) {
                if (int(eeprom_read_word(iter)) == 11111) {
                  Serial.print(F("null"));
                } else {
                  Serial.print(int(eeprom_read_word(iter)));
                }
                iter += 4;
                if (++i == size) {
                  break;
                }
                Serial.print(',');
              }

              Serial.print(';');
            };

            int iter = namber_list_temp_and_hot;
            for (byte i = 0; i < namber_list_temp_and_hot; ++i) {               // отправить графики температуры
              graf_json(eeprom_read_byte(i), iter);
              if (i == 0) {
                iter = 124 + namber_list_temp_and_hot;
              }
            }
            tmp_foo_two();         // график температуры кончился

            iter = namber_list_temp_and_hot + 2;
            for (byte i = 0; i < namber_list_temp_and_hot; ++i) {               // отправить графики энергозатрат
              graf_json(eeprom_read_byte(i), iter);
              if (i == 0) {
                iter = 126 + namber_list_temp_and_hot;
              }
            }
            tmp_foo_two();         // график энергозатрат кончился

            Serial.println();

            Watchdog.enable(RESET_MODE, WDT_PRESCALER); // Режим сторжевого сброса , таймаут ~1с        (128 = ~1c)
            break;
          }
        case ';':
          {
            switch (value_string_parsing) {
              case 0:
                Settings_CO2_no_good.set_value(buf_string.toInt());
                break;
              case 1:
                Settings_on_vent.set_value(byte(buf_string.toInt()));
                break;
              case 2:
                {
                  int tp = buf_string.toInt();
                  if (tp <= 0) {
                    digitalWrite(dPinVentDay, InvVentDay(0));
                    digitalWrite(dPinVentNite, InvVentNite(0));
                    time_on_vent.del();
                  } else {
                    time_on_vent.reset(0, tp, 0);
                    flag_out_people = 0;
                    tmr = millis();
                  }
                  flag_update_date = 1;                         // изменить врямя до конца проветривания на мониторе
                  break;
                }
              case 3:
                Settings_celsius_NORM.set_value(atof(buf_string.c_str()));
                //Settings_celsius_NORM.set_value(buf_string.toFloat());
                break;
              case 4:
                Settings_check_temp.set_value(byte(buf_string.toInt()));
                break;
              case 5:
                Settings_update_celsius_NORM.set_value(byte(buf_string.toInt()));
                break;
              case 6:
                Settings_CO2_out_people.set_value(buf_string.toInt());
                break;
              case 7:
                Settings_time_out_people.set_value(byte(buf_string.toInt()));
                break;
              case 8:
                Settings_time_nite.set_value(byte(buf_string.toInt()));
                break;
              case 9:
                Settings_time_no_nite.set_value(byte(buf_string.toInt()));
                break;
              case 10:
                Settings_on_display.set_value(buf_string.toInt());

                value_string_parsing = -1;
                save_settings();
                flag_settings = 1;
                break;
            }
            ++value_string_parsing;
            buf_string = "";
          
            break;
          }
        case '$':
          {
            byte tmp = buf_string.indexOf(',');
            int place = (buf_string.substring(1, tmp)).toInt();
            long value = (buf_string.substring(tmp + 1)).toInt();
            switch(buf_string[0]){
              case '1':
                eeprom_write_byte(place, byte(value));
                break;
              case '2':
                eeprom_write_word(place, int(value));
                break;
              case '4':
                eeprom_write_dword(place, value);
                break;
//              case 'f':
//                eeprom_write_float(place, float(atof(buf_string.substring(tmp + 1))));
//                break;
            }
            updated_monitor();
            buf_string = "";
            break;
          }
#ifdef type_brizer
        case '@':    // данные с другого бризера о температуре с улицы - записать их
          {
            if (++iterator_celsius_street == 3) iterator_celsius_street = 0;
            //celsius_street.set_value(atof(buf_string.c_str()), iterator_celsius_street);            // наулице
            celsius_street.set_value(buf_string.toFloat(), iterator_celsius_street);            // наулице


            buf_string = "";
            break;
          }
#endif
        default:     // иначе не запрос а данные о обновление настроек - начать считывать данные в строку до сивмвола - ключа (@ $ ; )
          {
            if (buf_char != '\n' && buf_char != ' ' && buf_char != '\r' && buf_char != '\t' && buf_char != '\0') {
              buf_string += buf_char;
            }
            break;
          }
      }
    }

  }

  //  int tmp__ = millis() - time_;
  //  if(tmp__ > 5){
  //    Serial.println(tmp__);
  //  }

  Watchdog.reset(); // Переодический сброс watchdog, означающий, что устройство не зависло

}








void isr() {                               // отработка в прерывании для энкодера
  enc.tick();
}



boolean Day_or_no() {                      // определение какой режим вентилятора включить
  if (time.mon >= winter_begin || time.mon <= winter_end) {
    return 0;   //ночной режим
  }

  if (Settings_time_nite.get_value() == Settings_time_no_nite.get_value()) {
    return 1;    //дневной режим
  }

  if (Settings_time_nite.get_value() > Settings_time_no_nite.get_value()) {
    if (time.hour >= Settings_time_nite.get_value() || time.hour <= Settings_time_no_nite.get_value()) {
      return 0;     //ночной режим
    }
    return 1;     //дневной режим
  }
  if (time.hour >= Settings_time_nite.get_value() && time.hour <= Settings_time_no_nite.get_value()) {
    return 0;     //ночной режим
  }
  return 1;     //дневной режим
}

void PWM_hot_tick() {                      // управлять печкой с помощью низкочастотного ШИМа
  if (regulator.output == 0) {
    digitalWrite(dPinHot, InvHot(0));
    return;
  }
  int activePeriod = round(float(regulator.output) * period_PID / 255.0);
  if (millis() - tmr >= (flag ? activePeriod : (int(period_PID) - activePeriod))) {
    tmr = millis();
    flag = !flag;
    digitalWrite(dPinHot, InvHot(flag));
  }
}

template <typename T>
bool update_value(T& value, T new_value) { // обновление переменной одновременно с местом под неё на экране
  if (value != new_value) {
    value = new_value;
    return 1;
  }
  return 0;
}



int8_t get_zero_graf(const int* graf, int8_t size, const float step) {                                           // получение нуля для графика (относительно низа)
  int zero = 11111;
  while (size >= 1) {
    if (*(graf - size) < zero) {
      zero = *(graf - size);
    }
    --size;
  }


  return int8_t(round(zero / step));


}
void print_graf(const int* graf, const int8_t size, const byte norm_size, const int8_t zero, const float step) { // рисование графика (относительно низа)

  byte one[8] = {      //создание новых символов для рисования графиков
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111
  };
  byte two[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B11111
  };
  byte three[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B11111,
    B11111,
  };
  byte four[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B11111,
    B11111,
    B11111
  };
  byte five[8] = {
    B00000,
    B00000,
    B00000,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  };
  byte six[8] = {
    B00000,
    B00000,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  };
  byte seven[8] = {
    B00000,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  };
  byte eight[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  };
  //создание новых символов для рисования графиков ^

  lcd.createChar(1, one);      //создание навых символов для рисования графика Co2
  lcd.createChar(2, two);
  lcd.createChar(3, three);
  lcd.createChar(4, four);
  lcd.createChar(5, five);
  lcd.createChar(6, six);
  lcd.createChar(7, seven);
  lcd.createChar(8, eight);

  byte place = 16 - norm_size;    //находим место в котором выводить на экран этот пункт
  int8_t temp;
  for (byte i = 1; i <= norm_size; ++i, ++place) {
    lcd.setCursor(place, 1);
    if (i > size || *(graf - i) == 11111) {       //если нечего выводить
      lcd.print('/');
      lcd.setCursor(place, 0);
      lcd.print('/');
      continue;
    }

    temp = round(*(graf - i) / step - zero);   //учесть значение от которого строится график(понять сколько одиночных деления занимает этот пункт)
    if (temp <= 0) {    //вывести этот пункт
      lcd.print(' ');
      lcd_clear_value(place, 0, 1);
    } else if (temp > 8) {
      lcd.write(byte(8));
      lcd.setCursor(place, 0);
      if ((temp - 8) > 8) {
        lcd.print('+');
      } else {
        lcd.write(byte(temp - 8));
      }
    }
    else {
      lcd.write(byte(temp));
      lcd_clear_value(place, 0, 1);
    }
  }
}


#ifdef type_graf_temp
int8_t get_zero(const int* graf, int8_t size, const float step) {                                                // получение нуля для графика (относительно центра)      температуры
  byte temp_zero_iterator = 0;
  float zero = 0;
  while (size >= 1) {
    if (*(graf - size) != 11111) {
      ++temp_zero_iterator;
      zero += *(graf - size);
    }
    --size;
  }

  if (temp_zero_iterator != 0) {
    return int8_t(round(zero / temp_zero_iterator / step));
  }

  return 111;
}
void graf_temp(const int* graf, const int8_t size, const byte norm_size, const int8_t zero, const float step) {  // рисование графика (относительно центра)               температуры
  byte un_one[8] = {
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
  };
  byte un_two[8] = {
    B00000,
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
  };
  byte un_three[8] = {
    B00000,
    B00000,
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
  };
  byte un_four[8] = {
    B00000,
    B00000,
    B00000,
    B11111,
    B00000,
    B00000,
    B00000,
    B00000
  };
  byte un_five[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B00000,
    B00000,
    B00000
  };
  byte un_six[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B00000,
    B00000
  };
  byte un_seven[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B00000
  };
  byte un_eight[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111
  };

  lcd.createChar(1, un_one);     //создание навых символов для рисования графика Co2
  lcd.createChar(2, un_two);
  lcd.createChar(3, un_three);
  lcd.createChar(4, un_four);
  lcd.createChar(5, un_five);
  lcd.createChar(6, un_six);
  lcd.createChar(7, un_seven);
  lcd.createChar(8, un_eight);

  byte place = 16 - norm_size;
  int8_t tmp;
  for (byte i = 1; i <= norm_size; ++i, ++place) {
    if (i > size || *(graf - i) == 11111) {
      lcd.setCursor(place, 0);
      lcd.print('/');
      lcd.setCursor(place, 1);
      lcd.print('/');
      continue;
    }
    tmp = round(*(graf - i) / step - zero);

    lcd.setCursor(place, 0);
    if (tmp == 0) {
      lcd.print(' ');
      lcd.setCursor(place, 1);
      lcd.print(' ');
    } else if (tmp > 0) {
      if (tmp <= 8) {
        lcd.write(byte(9 - tmp));
      } else {
        lcd.print('+');
      }
      lcd.setCursor(place, 1);
      lcd.print(' ');
    } else {
      lcd.print(' ');
      lcd.setCursor(place, 1);
      if (tmp >= -8) {
        lcd.write(byte(-1 * tmp));
      } else {
        lcd.print('-');
      }
    }
  }

}
#endif


void lcd_clear_value(const byte line, const byte column, const byte size) {  // стереть определённое место на мониторе
  lcd.setCursor(line, column);
  for (byte i = 0; i < size; ++i) {
    lcd.print(' ');
  }
  lcd.setCursor(line, column);
}
template <typename T>
void lcd_print_value(const T value, const T size) {                          // вывести целое положительное число на экран

  T temp = value;
  T symbol = 0;
  do {
    temp /= 10;
    ++symbol;
  } while (temp != 0);

  for (byte i = 0; i < size - symbol; ++i) {
    lcd.print('0');
  }
  lcd.print(value);
}
void updated_monitor() {                                                     // обновить все значения для монитора
  flag_update_date = 1;
  ppm.flag_update = 1;

  celsius_home.flag_update = 1;
  celsius_street.flag_update = 1;
  celsius_hot.flag_update = 1;
  flag_update_work_hot = 1;

  flag_graf_CO2 = 1;

  flag_graf_temp = 1;

  flag_time_hot = 1;

  flag_settings = 1;
}

void lcd_print_rub(const byte line, const byte column) {                     // вывести знак рубля
  byte rub[8] = {      //создание нового символа
    B01110,
    B01001,
    B01001,
    B11110,
    B01000,
    B11110,
    B01000,
    B00000
  };
  lcd.createChar(0, rub);      //создание навых символов
  lcd.setCursor(line, column);
  lcd.write(byte(0));
}
void lcd_print_degree(const byte line, const byte column) {                  // вывести знак градуса
  byte degree[8] = {      //создание нового символа
    B01000,
    B10100,
    B01000,
    B00110,
    B01001,
    B01000,
    B01001,
    B00110
  };
  lcd.createChar(0, degree);      //создание навых символов
  lcd.setCursor(line, column);
  lcd.write(byte(0));
}
void lcd_print_mini_two(const byte line, const byte column) {                // вывести маленькую двойку(индекс CO2)
  byte mini_two[8] = {      //создание нового символа
    B00000,
    B00000,
    B00000,
    B01100,
    B10010,
    B00100,
    B01000,
    B11110
  };
  lcd.createChar(1, mini_two);      //создание навых символов
  lcd.setCursor(line, column);
  lcd.write(byte(1));
}




// используются 2+ раза, но уменьшают размер кода
void move_temp_and_hot() {                   // сдвинуть месяца температуры и энергозатрат
  byte step = eeprom_read_byte(0) * 4;                               // то на сколько сместить все месяца

  int iter = namber_list_temp_and_hot + 124;                         // считаем индекс начала записи последнего дня предпоследнего месяца
  for (byte i = 1; i < namber_list_temp_and_hot - 1; ++i) {
    iter += eeprom_read_byte(i) * 4;
  }

  while (iter != 124 + namber_list_temp_and_hot) {                   // смещаем все месяца кроме нулевого и последнего на размер нулевого
    iter -= 4;
    eeprom_write_dword(iter + step, eeprom_read_dword(iter));
    //    eeprom_write_word(iter + step, epprom_read_word(iter));
    //    eeprom_write_word(iter + step + 2, epprom_read_word(iter + 2));
  }

  iter += step;
  while (iter != 124 + namber_list_temp_and_hot) {                    // перемещаем нулевой месяц
    iter -= 4;
    eeprom_write_dword(iter, eeprom_read_dword(iter - 124));
    //    eeprom_write_word(iter, epprom_read_word(iter - 124));
    //    eeprom_write_word(iter + 2, eeprom_read_word(iter - 122));
  }

  for (byte i = namber_list_temp_and_hot - 1; i > 0; --i) {           // сдивуть размеры месяцов
    eeprom_write_byte(i, eeprom_read_byte(i - 1));
  }
  eeprom_write_byte(0, 0);
}

void get_RUB_last_month() {                  // пересчёт цены за последние месяца работы(текущий и предыдущий)
  float tmp = 0;
  int iter = namber_list_temp_and_hot + 2;

  for (byte i = 0; i < eeprom_read_byte(0); ++i) {
    if (eeprom_read_word(iter) != 11111) {
      tmp += eeprom_read_word(iter);
    }
    iter += 4;
  }
  RUB_naw_month = round(tmp / 100.0);          // текущий месяц




  tmp = 0;
  iter = namber_list_temp_and_hot + 126;

  for (byte i = 0; i < eeprom_read_byte(1); ++i) {
    if (eeprom_read_word(iter) != 11111) {
      tmp += eeprom_read_word(iter);
    }
    iter += 4;
  }
  RUB_before_month = round(tmp / 100.0);       // предыдущий месяц
}

void save_settings() {                       // сохранение настроек в энергонезависемую память
  eeprom_update_word(1021, Settings_celsius_NORM.get_value() * 100);
  eeprom_update_byte(1020, Settings_update_celsius_NORM.get_value());
  eeprom_update_word(1018, Settings_CO2_no_good.get_value());
  eeprom_update_byte(1017, Settings_on_vent.get_value());

  eeprom_update_byte(1016, Settings_time_nite.get_value());
  eeprom_update_byte(1015, Settings_time_no_nite.get_value());
  eeprom_update_word(1013, Settings_on_display.get_value());
  eeprom_update_byte(1012, Settings_check_temp.get_value());

  eeprom_update_word(1010, Settings_CO2_out_people.get_value());
  eeprom_update_byte(1009, Settings_time_out_people.get_value());
}

void clear_arr(int* arr, unsigned int size) {        // заполняет массив [column * size] значениями по умолчанию
  for (unsigned int i = 0; i < size; ++i) {
    *(arr + i) = 11111;
  }
}

int* get_graf_by_eeprom_for_print(int iter, byte Settings_namber_graf, int8_t& size_) {     // считать данные из энергонезависимой памяти для вывода на график( тумпература и энергозатраты)
  if (Settings_namber_graf < 3) {
    iter -= 124;
  } else {
    for (byte i = 1; i < Settings_namber_graf / 3; ++i) {
      iter += eeprom_read_byte(i) * 4;
    }
  }
  //Serial.print(eeprom_read_byte(Settings_namber_graf / 3)); Serial.print('\t'); Serial.println(eeprom_read_byte(Settings_namber_graf / 3) - 11 * (Settings_namber_graf % 3));
  size_ = eeprom_read_byte(Settings_namber_graf / 3) - 11 * (Settings_namber_graf % 3);
  iter += size_ * 4;

  lcd.setCursor(0, 1);
  if (size_ <= 0) {           // вывести номер самого первого дня графика температуры
    lcd.print(F("--"));
  } else {
    lcd_print_value(size_);

    if (size_ > 11) {
      size_ = 11;
    }

    int* tmp_arr = new int[size_];
    for (int8_t i = size_ - 1; i >= 0; --i) {
      iter -= 4;
      tmp_arr[i] = eeprom_read_word(iter);
    }
    return tmp_arr;

  }

  return NULL;
}






//конец :
