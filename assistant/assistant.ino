#include "debug.hpp"
#include "communication.hpp"
#include "lights.hpp"
#include "rgb.hpp"
#include "fan.hpp"
#include "gas.hpp"

void setup()
{
  pinMode(PIN_BATHROOM, OUTPUT);
  digitalWrite(PIN_BATHROOM, LOW);
  pinMode(PIN_KITCHEN, OUTPUT);
  digitalWrite(PIN_KITCHEN, LOW);
  pinMode(PIN_DINING, OUTPUT);
  digitalWrite(PIN_DINING, LOW);
  pinMode(PIN_BEDROOM, OUTPUT);
  digitalWrite(PIN_BEDROOM, LOW);

  pinMode(PIN_RED, OUTPUT);
  analogWrite(PIN_RED, 0);
  pinMode(PIN_GREEN, OUTPUT);
  analogWrite(PIN_GREEN, 0);
  pinMode(PIN_BLUE, OUTPUT);
  analogWrite(PIN_BLUE, 0);

  pinMode(PIN_FAN1,OUTPUT);
  analogWrite(PIN_FAN1, 0);
  pinMode(PIN_FAN2,OUTPUT);
  analogWrite(PIN_FAN2, 0);

  pinMode(PIN_GAS, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, 0);

  Serial.begin(9600);
    
  #if VERBOSITY
    Serial.println("ready");
  #endif
}

long millis_rgb = 0;
long millis_gas = 0;

void loop()
{
  const char * message;

  full_receive();
  
  if (message = full_read()) {
    #if VERBOSITY
      Serial.println(message);
    #endif

    char * ptr;
    if(ptr = strstr(message, "LIGHTS")){
      #if VERBOSITY
        Serial.println("LIGHTS ack");
      #endif
      lights(message + (strlen("LIGHTS") + 1));
    }
    else if(ptr = strstr(message, "RGB")){
      #if VERBOSITY
        Serial.println("RGB ack");
      #endif
      rgb(message + (strlen("RGB") + 1));
    }
    else if(ptr = strstr(message, "FAN")){
      #if VERBOSITY
        Serial.println("FAN ack");
      #endif
      fan(message + (strlen("FAN") + 1));
    }
  }
  
  if((millis() - millis_rgb) > timer_rgb && state == FADE){
    rgb_fade();
    millis_rgb = millis();
  }

  if((millis() - millis_gas) > timer_gas){
    gas();
    millis_gas = millis();
  }
}
