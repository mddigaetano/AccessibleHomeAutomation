#include <Arduino.h>
#include "fan.hpp"

void fan(const char * message){
  if(strcmp(message, "ON") == 0){
    analogWrite(PIN_FAN1, rpm);
  }
  else{
    analogWrite(PIN_FAN1, 0);
  }
}

