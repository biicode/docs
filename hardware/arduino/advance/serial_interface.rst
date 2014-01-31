===============================
Serial Interface: Arduino & C++
===============================

With this serial interface you can define your own commands for the arduino. You will be able to send commands from a console in your PC to the arduino.
In this example we use a desktop console app to move a servo attached to the Arduino, we just have to send the "servo" command  and the angle.


How does it work?
-----------------

Just need to use the methods ``read`` and ``write`` to comunicate with the device through serial port. Those functions are defined in `david/serial_arduino <https://www.biicode.com/david/blocks/david/serial_arduino/branches/master>`_ and `david/serial_cpp <https://www.biicode.com/david/blocks/david/serial_cpp/branches/master>`_ libraries.
You can find the whole api definition in the blocks web!


How do I use it?
-----------------

* You need to create two hives arduino_app adn cpp_app, one will contain the code that will be uploaded to arduino and the other one the client application that will run in your PC.
* Copy the example code, C++ app code goes into your your pc hive and arduino code goes into the hive with arduino code.

The code
--------

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
		serial serialport('#', ';', "COM8", 9600); //Change the serial port ID!!

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
	#include "arduino/libraries/servo/servo.h"
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


Execute following commands in each hive:

**Arduino App**

.. code-block:: bash

    $ bii find
    $ bii arduino:upload

**C++ App**

.. code-block:: bash

    $ bii find
    $ bii cpp:run

    ...

    Enter: servo
    servo
    Enter: 180
    180
    Enter: servo
    servo
    Enter: 90
    ...

