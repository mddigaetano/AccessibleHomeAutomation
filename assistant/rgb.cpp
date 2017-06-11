#include <Arduino.h>
#include "debug.h"
#include "rgb.h"

void rgb(const char * message){
  #if VERBOSITY
      Serial.println(message);
  #endif
  if(strcmp(message, "RED") == 0){
    rgb_set(RED);
  }
  else if(strcmp(message, "GREEN") == 0){
    rgb_set(GREEN);
  }
  else if(strcmp(message, "BLUE") == 0){
    rgb_set(BLUE);
  }
  else if(strcmp(message, "ORANGE") == 0){
    rgb_set(ORANGE);
  }
  else if(strcmp(message, "YELLOW") == 0){
    rgb_set(YELLOW);
  }
  else if(strcmp(message, "PURPLE") == 0){
    rgb_set(PURPLE);
  }
  else if(strcmp(message, "INDIGO") == 0){
    rgb_set(INDIGO);
  }
  else if(strcmp(message, "WHITE") == 0){
    rgb_set(WHITE);
  }
  else if(strcmp(message, "OFF") == 0){
    rgb_set(OFF);
  }
  else if(strcmp(message, "FADE") == 0){
    #if VERBOSITY
      Serial.println("trovato fade");
    #endif
    state = FADE;
  }
}

void rgb_set(const int * color, bool fixed){
  if(fixed){
    state = FIXED;
  }
  analogWrite(PIN_RED, color[0]);
  analogWrite(PIN_GREEN, color[1]);
  analogWrite(PIN_BLUE, color[2]);
}

void rgb_fade(){
  const int gap = 1;
  const int max_value = 150;
  
  static int increment = gap;
  static int current[] = {0, 0, 0};
  static int current_color = 0;

  #if VERBOSITY
    Serial.println("dentro fade");
  #endif
  if(current[current_color] <= max_value && current[current_color] >= 0){
    current[current_color] += increment;
    rgb_set(current, false);
    
    if(current[current_color] + increment > max_value){
      increment *= -1;
    }
    else if(current[current_color] + increment < 0){
      increment *= -1;
      if(current_color == 2){
        current_color = 0;
      } else{
        current_color++;
      }
    }
  }  
}

