#pragma once

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

void blink_setup(int led, int interval_ms);
// the loop routine runs over and over again forever:
void blink_loop();