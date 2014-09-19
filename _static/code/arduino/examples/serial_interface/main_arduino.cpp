#include <Arduino.h>

#include <Servo.h>
#include "david/serial_arduino/serial.h"


serial serialport('#', ';', 9600);
String msg = "";
String premsg = "";
Servo myservo;

void setup() {
	myservo.attach(9);
	serialport.init();
}

// bii:#entry_point()
void loop() {

	msg = serialport.read(); //read a message
	if(msg != "")
	{
		serialport.writeOpen();
		serialport.writeString(msg); //send a message
		serialport.writeEnd();

		if(premsg=="servo"){
			int n;
			n = atoi(msg.c_str());
			myservo.write(n);
		}
		premsg = msg;
	}
}