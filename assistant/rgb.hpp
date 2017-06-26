#ifndef COLORS
  #define COLORS
  #define PIN_RED 6
  #define PIN_GREEN 9
  #define PIN_BLUE 10
#endif

const int RED[] = {255, 0, 0};
const int ORANGE[] = {237, 109, 0};
const int YELLOW[] = {255, 215, 0};
const int GREEN[] = {0, 255, 0};
const int BLUE[] = {0, 0, 255};
const int PURPLE[] = {128, 0, 128};
const int INDIGO[] = {0, 46, 90};
const int WHITE[] = {255, 255, 255};

const int OFF[] = {0, 0, 0};

const long timer_rgb = 50;

enum state_t{
  FIXED,
  FADE
};

state_t state = FIXED;

void rgb(const char * message);
void rgb_set(const int * color, bool fixed = true);
void rgb_fade();

