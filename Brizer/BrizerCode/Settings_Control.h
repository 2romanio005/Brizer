//========================================= КЛАСС ДЛЯ ХРАНЕНИЯ И ИЗМЕНЕНИЯ НАСТРОЕК ====================================

#pragma once

template <typename T>
class Settings_Control {
  public:
    Settings_control(){                                                    // конструктор по умолчанию
      this->value = 0;
      this->value_max = 99;
      this->value_min = 0;
      this->step = 1;
    };
    Settings_Control(T value, T value_max, T step = 1, T value_min = 0, time_pause* pair = NULL){   // конструктор 
      this->value_max = value_max;
      this->step = step;
      this->value_min = value_min;
      
      this->value = constrain(value, value_min, value_max);
      this->pair = pair;
    };

    void change_value_up() {                                               // увеличить переменную на шаг(step)
      if (this->value >= this->value_max) {
        this->value = this->value_min;
      } else{
        this->value += this->step;
      }
      this->update_pair();
    };
    void change_value_down() {                                             // уменьшить переменную на шаг(step)
      if (this->value <= this->value_min) {
        this->value = this->value_max;
      } else{
        this->value -= this->step;
      }
      this->update_pair();
    };

    /*void set_step(T step){                                               // установить шаг
      this->step = step;
    } */
    void set_value(T value){                                               // записать значение переменной
      T value_tmp = this->value;
      this->value = constrain(value, value_min, value_max);
      if(value_tmp != value) this->update_pair();
    };
    T get_value() {                                                        // получить значение переменной
      return this->value;
    };
  
  private:
    T value;          // переменнная
    
    T value_max;      // максимальное значение перемнной
    T value_min;      // минималоное значение перемнной
    T step;           // шаг при изменение


    time_pause* pair; // связаный с настройкой флаг
    
    void update_pair(){
      if(pair != NULL){
        if(value != 0 && pair->check_work()){
          pair->reset(0, value, 0);
        } else {
          pair->del();  
        }
      }
    }
};
