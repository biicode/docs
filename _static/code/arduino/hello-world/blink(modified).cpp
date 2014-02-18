#include "blink.h"

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

void intermittent()
{
	unsigned long currentMillis = millis();
	long stop_ms = interval / 2;
	long dif = 0;
	int aux_ledstate = ledState;

	while (true)
	{
		dif = millis() - currentMillis;
		if (dif % 20 == 0)
		{
			if (aux_ledstate == LOW)
				aux_ledstate = HIGH;
			else
				aux_ledstate = LOW;
			// set the LED with the ledState of the variable:
			digitalWrite(ledPin, aux_ledstate);
		}
		if (dif > stop_ms) return;
	}
}

void blink_loop(){
	unsigned long currentMillis = millis();
	 
	if(currentMillis - previousMillis > interval) {
		// save the last time you blinked the LED 
		previousMillis = currentMillis;   

		// if the LED is off turn it on and vice-versa:
		//TODO: Check if ledState = !ledState; works
		if (ledState == LOW)
		{
		  ledState = HIGH;
		  intermittent();
		}
		else
		{
		  ledState = LOW;
		  intermittent();
		}

		// set the LED with the ledState of the variable:
		digitalWrite(ledPin, ledState);
	  }
 }
