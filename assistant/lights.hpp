#ifndef ROOMS
  #define ROOMS
  #define PIN_DINING 3
  #define PIN_KITCHEN 4
  #define PIN_BATHROOM 11
  #define PIN_BEDROOM 12
#endif

void lights(const char * message);
void on_off(const char * const room, const char * const state);
