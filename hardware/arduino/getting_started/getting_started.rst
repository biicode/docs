===========================
Create a new hive and code!
===========================

Remember that you need to :ref:`configure your biicode workspace <arduinows>` with the Arduino SDK.

Create your hive
================

Creating a new hive with the ``bii new`` command.

.. code-block:: bash
	:emphasize-lines: 1, 2, 5, 8, 10

	$ bii new
	Introduce name: arduino_hello
	Created new hive arduino_hello
	Select language: (java/node/fortran/python/cpp/arduino/None)
	Introduce lang (default:None): arduino
	
	How would you like to name your first block?
	Introduce block name (default:my_block): [ENTER]
	INFO: block name: my_block
	Generate a default firmware?  (YES/no) [ENTER]
	INFO: Default extension file is '.cpp'. You can use '.c' extension too.

	Creating a main file "main.cpp"

	File main.cpp has been created in [HIVE_PATH]/blocks/[USER]/my_block/main.cpp

With this command you create the next tree:

.. code-block:: text
	:emphasize-lines: 9, 10, 11, 12

	|-- my_hive
	|    +-- bii
	|    +-- bin
	|    +-- build
	|    +-- dep
	|    +-- blocks
	|         +-- my_user_name
	|         |     +-- my_block
	|         |     |	|-- main.cpp
	|         |     |	|-- bii
	|         |     |	|	|-- mains.bii
	



These files have the following content:

**main.cpp**

This is the main project file.

.. code-block:: cpp
	:linenos:

	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif

	// Pin 13 has an LED connected on most Arduino boards.
	// give it a name:
	int led = 13;

	// the setup routine runs once when you press reset:
	void setup() {
		// initialize the digital pin as an output.
		pinMode(led, OUTPUT);
	}

	// the loop routine runs over and over again forever:
	void loop() {
		digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
		delay(1000);               // wait for a second
		digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
		delay(1000);               // wait for a second
	}

**mains.bii**

biicode use this file to define main.cpp like a main file. You have all the :ref:`info about mains.bii here <mains-bii>`.

.. code-block:: text
	:linenos:

	main.cpp
	
Configure your settings
=======================

Configure the hive settings.bii file whit the info about your board and serial port

.. code-block:: text
	:emphasize-lines: 2
	
	arduino:
		board: {board: mega2560, no_autolibs: 'false', port: COM7, programmer: usbtinyisp}
		
Build and Upload
================

.. code-block:: bash
	:emphasize-lines: 1, 7

	$ bii arduino:build
	
	...
	
	[100%] Built target [USER]_my_block_main
	
	$ bii arduino:upload
	
	...
	
	Writing | ################################################## | 100% 0.00s

	avrdude.exe: 0 bytes of eeprom written

	avrdude.exe: safemode: Fuses OK

	avrdude.exe done.  Thank you.

	[100%] Built target [USER]_my_block_main-upload
	
	