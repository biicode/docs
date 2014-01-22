.. _arduinows:

=======================================
How to configure your biicode workspace
=======================================

Update your environment.bii
===========================

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

no_autolibs can be false or true. Disable Arduino library detection (default On).

USB port
^^^^^^^^

USB where you have the Arduino board connected.


**Linux**

On Linux the Arduino serial device is named as follows (where X is the device number):

* ``/dev/ttyUSBX``
* ``/dev/ttyACMX``

Where ``/dev/ttyACMX`` is for the new Uno and Mega Arduino's, while ``/dev/ttyUSBX`` is for the old ones.

**windows**

When specifying the serial port name on Windows, use the following names:

* ``com1`` ``com2`` ... ``comN``

**Mac**

When specifying the serial port name on Mac OS X, use the following names (where XXX is a unique ID):

* ``/dev/tty.usbmodemXXX``
* ``/dev/tty.usbserialXXX``

Where ``tty.usbmodemXXX`` is for new Uno and Mega Arduino's, while ``tty.usbserialXXX`` are the older ones.

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

Path where you installed arduino. It is important to choose a SDK compatible with your board. If you need to download a SDK or more info visit the `official Arduino website <http://arduino.cc/en/Main/Software>`_

Tool info
^^^^^^^^^

* ``arch``: AVR
* ``amily``: MINGW (windows) or Gnu (linux/Mac)
* ``version``: 1.0.5

You can see de version of your SDK into the file ``[Arduino_SDK_path]/revisions.txt``
