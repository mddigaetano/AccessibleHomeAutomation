#include <Arduino.h>
#include "lights.hpp"

void lights(const char * message){
  char * room;
  char * state;
  
  room = strdup(message); //duplico messaggio (message è const, devo modificarlo in qualche modo)
  state = strstr(room, ";");  //trovo la posizione della prima occorrenza di ;
  state[0] = '\0';  //sostituisco al ; il terminatore, in modo da avere due stringe in un array(????)
  #if VERBOSITY
    Serial.println(room);
    Serial.println(state);
  #endif
  on_off(room, ++state);  //++ perché devo spostarmi dopo il ;
  free(room); //adesso posso deallocare il risultato di strdup, bastava non modificarne la dimensione
}

void on_off(const char * const room, const char * const state){
  int volt;

  if(strcmp(state, "ON") == 0)
    volt = HIGH;
  else
    volt = LOW;

  if(strcmp(room, "BATHROOM") == 0)
    digitalWrite(PIN_BATHROOM, volt);
  else if(strcmp(room, "KITCHEN") == 0)
    digitalWrite(PIN_KITCHEN, volt);
  else if(strcmp(room, "DINING") == 0)
    digitalWrite(PIN_DINING, volt);
  else if(strcmp(room, "BEDROOM") == 0)
    digitalWrite(PIN_BEDROOM, volt);
  else if(strcmp(room, "ALL") == 0){
    digitalWrite(PIN_BATHROOM, volt);
    digitalWrite(PIN_KITCHEN, volt);
    digitalWrite(PIN_DINING, volt);
    digitalWrite(PIN_BEDROOM, volt);
  }
}

