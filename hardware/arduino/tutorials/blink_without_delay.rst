===================
Blink Without Delay
===================

This code work like the basic blink example but with the characteristic that this code don't use ``delay()``.

How does it work?
=================

This code use the method ``millis()`` and 2 control variavles to count the time transcurred in a period of time. when this time are equal to 1000 the status of the led change.

the code
========

**main.cpp**

.. code-block:: cpp
	:linenos:

	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif

	// constants won't change. Used here to 
	// set pin numbers:
	const int ledPin =  13;      // the number of the LED pin

	// Variables will change:
	int ledState = LOW;             // ledState used to set the LED
	long previousMillis = 0;        // will store last time LED was updated

	// the follow variables is a long because the time, measured in miliseconds,
	// will quickly become a bigger number than can be stored in an int.
	long interval = 1000;           // interval at which to blink (milliseconds)

	void setup() {
	  // set the digital pin as output:
	  pinMode(ledPin, OUTPUT);      
	}

	void loop()
	{
	  // here is where you'd put code that needs to be running all the time.

	  // check to see if it's time to blink the LED; that is, if the 
	  // difference between the current time and last time you blinked 
	  // the LED is bigger than the interval at which you want to 
	  // blink the LED.
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

**mains.bii**

biicode use this file to define main.cpp like a main file. You have all the :ref:`info about mains.bii here <mains_bii>`. You need to create this file into [BLOCK_NAME]/bii/mains.bii

.. code-block:: text
	:linenos:

	main.cpp