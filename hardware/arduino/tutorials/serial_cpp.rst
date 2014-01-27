====================================
Arduino & C++: Serial Port Interface
====================================

With this example you will turn on and turn off a LED using a console application that communicates with the Arduino by serial port.

You onli need to change the line 13 with the name of the USB port.

**C++ aplication main.cpp**

.. code-block:: cpp
	:linenos:

	#include <stdio.h>
	#include <tchar.h>
	#include "david/serialport/serialport.h"
	#include <string>
	#include <iostream>

	using namespace std; 
	int main()
	{
		unsigned char incomingData[256] = "";
		unsigned char outputData[256] = "";
		SerialPort serial;
		serial.init("COM8");
		serial.setBaud(9600);
		while(1){
			cout << "Enter value 1 or 0 [(1 = ON) (0 = OFF)]: ";
			cin >> incomingData;
			serial.send(256,incomingData);
		}
		
		return 0;
	}

**Arduino main.cpp**
	
.. code-block:: cpp
	:linenos:

	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif

	int led = 13;

	void setup() {
	  Serial.begin(9600);
	  pinMode(led, OUTPUT);
	}

	void loop() {
	}

	void serialEvent() {
	  while (Serial.available()) {
		// get the new byte:
		char inChar = (char)Serial.read(); 
		if (inChar == '1') {
		  digitalWrite(led, HIGH);
		}
		if (inChar == '0') {
		  digitalWrite(led, LOW);
		}
	  }
	}