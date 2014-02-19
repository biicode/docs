#pragma once

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class Blink
{
public:
	void blink_setup(int led, int interval_ms);
	void blink_loop();

private:
	int ledState;			// ledState used to set the LED
	long previousMillis;	// will store last time LED was updated
	int interval; 
	int ledPin;
};