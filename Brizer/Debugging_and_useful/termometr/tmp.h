//============================= МЕДИАЛЬНЫЙ ФИЛЬТР ДЛЯ ДАТЧИКОВ =================================
#pragma once

template <typename T>
class MedianFilter{                       
  public:
    medianFilter(){           // конструктор по умолчанию
      this->value = 0;
      for (byte i; i < 3; ++i){
        this->arr[i] = 0;
      }
    }
    
    void set_value(T value, byte iter){     // записать новое значение
      this->arr[iter] = value;
    
      if ((arr[0] <= arr[1]) && (arr[0] <= arr[2])) {  // отфильтровать значения
        value = (arr[1] <= arr[2]) ? arr[1] : arr[2];
      }else if ((arr[1] <= arr[0]) && (arr[1] <= arr[2])) {
        value = (arr[0] <= arr[2]) ? arr[0] : arr[2];
      }else{
        value = (arr[0] <= arr[1]) ? arr[0] : arr[1];
      }
      this->value = value;
      //flag_update = update_value((this->value), value);  // обновить флаг для монитора
      
    }
    T get_value(){                          // получить текущее значение
      return this->value;
    }
    
    bool flag_update;  // флаг для обновления монитора
  private:
    T value;           // отфильтрованное значение
    T arr[3];          // массив для фильрации
};
