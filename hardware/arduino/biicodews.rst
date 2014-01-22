=======================================
How to configure your biicode workspace
=======================================

Update your environment.bii and settings.bii
============================================

If you haven't done so, you must first :ref:`create a biicode workspace <create_workspace>`.

changes, if needed, the Arduino info on the **enviroment.bii**:

.. code-block:: text
	:emphasize-lines: 3, 8, 9

	arduino:
	  boards:
	  - {board: uno, no_autolibs: 'false', port: COM3, programmer: usbtinyisp}
	  builders:
	  - path: mingw32-make
		tool: {family: MINGW}
	  compilers:
	  - path: C:/Program Files/Arduino
		tool: {arch: AVR, family: MINGW, version: 1.0.5}
	  configurers:
	  - path: cmake
		tool: {family: CMake}

Boards information:
-------------------

Arduino Boards (SDK Arduino 1.0.5)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	* ``uno``: Arduino Uno
	* ``atmega328``: Arduino Duemilanove w/ ATmega328
	* ``diecimila``: Arduino Diecimila or Duemilanove w/ ATmega168
	* ``nano328``: Arduino Nano w/ ATmega328
	* ``nano``: Arduino Nano w/ ATmega168
	* ``mega2560``: Arduino Mega 2560 or Mega ADK
	* ``mega``: Arduino Mega (ATmega1280)
	* ``leonardo``: Arduino Leonardo
	* ``esplora``: Arduino Esplora
	* ``micro``: Arduino Micro
	* ``mini328``: Arduino Mini w/ ATmega328
	* ``mini``: Arduino Mini w/ ATmega168
	* ``ethernet``: Arduino Ethernet
	* ``fio``: Arduino Fio
	* ``bt328``: Arduino BT w/ ATmega328
	* ``bt``: Arduino BT w/ ATmega168
	* ``LilyPadUSB``: LilyPad Arduino USB
	* ``lilypad328``: LilyPad Arduino w/ ATmega328
	* ``lilypad``: LilyPad Arduino w/ ATmega168
	* ``pro5v328``: Arduino Pro or Pro Mini (5V, 16 MHz) w/ ATmega328
	* ``pro5v``: Arduino Pro or Pro Mini (5V, 16 MHz) w/ ATmega168
	* ``pro328``: Arduino Pro or Pro Mini (3.3V, 8 MHz) w/ ATmega328
	* ``pro``: Arduino Pro or Pro Mini (3.3V, 8 MHz) w/ ATmega168
	* ``atmega168``: Arduino NG or older w/ ATmega168
	* ``atmega8``: Arduino NG or older w/ ATmega8
	* ``robotControl``: Arduino Robot Control
	* ``robotMotor``: Arduino Robot Motor
	
no_autolibs
^^^^^^^^^^^

no_autolibs can be false or true.

USB port
^^^^^^^^

USB where you have the Arduino board connected

* **Linux**

* **windows**

* **Mac**

Arduino Programmers (SDK Arduino 1.0.5)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	* ``avrisp``: AVR ISP
	* ``avrispmkii``: AVRISP mkII
	* ``usbtinyisp``: USBtinyISP
	* ``usbasp``: USBasp
	* ``parallel``: Parallel Programmer
	* ``arduinoisp``: Arduino as ISP

Compilers:
----------

Path to the Arduino SDK
^^^^^^^^^^^^^^^^^^^^^^^

Tool info
^^^^^^^^^

arch: AVR

family: MINGW

version: 1.0.5


Create a new hive and code!
===========================

Creating a new hive with the ``bii new`` command.

Create all the files you need to start with the ``arduino:wizard --newmain`` command.
Then create a ``mains.bii`` file into ``block/bii`` folder. With this, you create the next tree:

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

main.cpp
--------

This is the main project file.

.. code-block:: cpp
	:linenos:

	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif

	void setup() {

	}

	void loop() {

	}

mains.bii
---------

biicode use this file to define main.cpp like a main file. You have all the :ref:`info about mains.bii here <mains-bii>`.

.. code-block:: text
	:linenos:

	main.cpp



