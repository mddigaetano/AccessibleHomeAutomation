#include <Arduino.h>
#include "communication.hpp"

void full_receive() {
  static bool inProgress = false;
  static byte i = 0;
  char received;

  while (Serial.available() > 0 && newData == false) {
    received = Serial.read();

    if (inProgress == true) {
      if (received != END_CHAR) {
        buffer[i] = received;
        i++;
        if (i >= BUFFER_SIZE) {
          i = BUFFER_SIZE - 1;
        }
      }
      else {
        buffer[i] = '\0'; // terminate the string
        inProgress = false;
        i = 0;
        newData = true;
      }
    }

    else if (received == START_CHAR) {
      inProgress = true;
    }
  }
}

const char * full_read(){
  char * ret;
  if(newData){
    ret = buffer;
    newData = false;
  }
  else{
    ret = NULL;
  }

  return ret;
}
