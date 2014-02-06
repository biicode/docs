	#include "blink.h"
	#if ARDUINO >= 100
	#include "Arduino.h"
	#else
	#include "WProgram.h"
	#endif

	// TODO: Use a more elegant solution than global variables!
	int ledState = LOW;             // ledState used to set the LED
	long previousMillis = 0;        // will store last time LED was updated
	int interval; 
	int ledPin;

	void blink_setup(int led, int interval_ms){
		ledPin=led;
		pinMode(ledPin, OUTPUT);
		interval = interval_ms;
	}
	void blink_loop(){
		unsigned long currentMillis = millis();
		 
		if(currentMillis - previousMillis > interval) {
			// save the last time you blinked the LED 
			previousMillis = currentMillis;   

			// if the LED is off turn it on and vice-versa:
			if (ledState == LOW)
			  ledState = HIGH;
			else
			  ledState = LOW;

			// set the LED with the ledState of the variable:
			digitalWrite(ledPin, ledState);
		  }
	 }
