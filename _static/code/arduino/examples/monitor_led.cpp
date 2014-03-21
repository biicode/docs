#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// Pin 13 has an LED connected on most Arduino boards
int led = 13;

void setup() {
	pinMode(led, OUTPUT); // initialize the digital pin as an output
	Serial.begin(9600);
	Serial.print("Send '1' or '0' to turn ON/OFF the led in Pin ");
	Serial.println(led, DEC);
}

void loop() {
	//checking data has been sent
	if (Serial.available() > 0) {
		char msg = Serial.read(); //read a message
		if(msg == '1'){
			digitalWrite(led, HIGH); // turn the LED on
			Serial.println("LED -> ON");
		}
		else if(msg == '0'){
			digitalWrite(led, LOW); // turn the LED off
			Serial.println("LED -> OFF");
		}
	}
}