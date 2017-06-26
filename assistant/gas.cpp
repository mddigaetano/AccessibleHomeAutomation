#include <Arduino.h>
#include "gas.hpp"

void gas(){
  if(digitalRead(PIN_GAS) == LOW){
    tone(PIN_BUZZER, 450);
  }
  else{
    noTone(PIN_BUZZER);
  }
}

