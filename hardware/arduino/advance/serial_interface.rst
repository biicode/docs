===============================
Serial Interface: Arduino & C++
===============================

With this serial interface library you only need to read a string or send it.

How does it work?
-----------------

Just need to use the method ``read`` and ``write`` to comunicate with the others devices by serial port.

How can i use it?
-----------------

* Just copy the files contained in the following section to a new block.
* Find the dependencies and execute your code:

**C++ App**

.. code-block:: bash

    $ bii find
    $ bii cpp:run

**Arduino App**

.. code-block:: bash

    $ bii find
    $ bii arduino:upload

C++ App functions
=================

* ``serial(char open, char end, const char device[], int spd=9600)``

This function is responsible for initializing all the parameters of the serial port.

open: Define the first character of a message.

end: Define the last character of a message.

device: Define the serial port ID.

spd: Define the speed of the serial port.

* ``string read()``

Read the serial port and return a string and return a void string if there are no info.

* ``write(unsigned char* data, int lng)``

Write an array of unsigned char by the serial port.

* ``writeString(string output)``

Write a string by the serial port.

C++ Arduino functions
=====================


* ``serial(char open, char end, int spd=9600)``

This function is responsible for initializing all the parameters of the serial port.

open: Define the first character of a message.

end: Define the last character of a message.

spd: Define the speed of the serial port.

* ``void init()``

Init the serial port whit the speed.

* ``string read()``

Read the serial port and return a string and return a void string if there are no info.

* ``write(unsigned char* output, int lng)``

Write an array of unsigned char by the serial port.

* ``writeString(String output)``

Write a string by the serial port.

* ``void writeOpen()``

Write an openChar by the serial port.

* ``writeEnd()``

Write an endChar by the serial port.

* ``writeln()``

Write a newline character by the serial port.

The code
--------

In this example we use a C++ App to move a Servo on the Arduino, we only need write a first message with the keyword "servo" and another message with the angle.

C++ app
=======

.. code-block:: cpp
	:linenos:

	#include "david/serial_cpp/serial.h"
	#include <string>
	#include <iostream>

	using namespace std;
	int main()
	{
		string incomingData = "";
		string input = "";
		serial serialport('#', ';', "COM8", 9600);

		while(1){
			input = serialport.read(); //read a message
			if (input != "") cout << input << "\n";
			else{
				cout << "Enter: ";
				cin >> incomingData;
				incomingData = "#" + incomingData;
				incomingData += ";";
				serialport.writeString(incomingData); //send a message
			}
		}
		return 0;
	}


Arduino app
===========

.. code-block:: cpp
	:linenos:

	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif
	#include <servo.h>
	#include "david/serial_arduino/serial.h"


	serial serialport('#', ';', 9600);
	String msg = "";
	String premsg = "";
	Servo myservo;

	void setup() {
		myservo.attach(9);
		serialport.init();
	}

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
