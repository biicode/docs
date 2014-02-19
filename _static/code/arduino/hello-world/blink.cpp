#include "blink.h"

void Blink::blink_setup(int led, int interval_ms)
{
	ledState = LOW;
	previousMillis = 0;

	interval = 1000;
	ledPin = 13;
	pinMode(ledPin, OUTPUT);
}

void Blink::blink_loop(){

	unsigned long currentMillis = millis();
	 
	if(currentMillis - previousMillis > interval) {
		// save the last time you blinked the LED 
		previousMillis = currentMillis;   

		// if the LED is off turn it on and vice-versa:
		//TODO: Check if ledState = !ledState; works
		if (ledState == LOW)
		  ledState = HIGH;
		else
		  ledState = LOW;

		// set the LED with the ledState of the variable:
		digitalWrite(ledPin, ledState);
	  }
 }
