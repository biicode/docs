Settings options
================

.. _arduino_boards:

boards
------

This is your Arduino Board model. It must be compatible with the Arduino SDK v. 1.0.5, and must have one of the following values:

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

usb port
--------

The USB interface where your Arduino board is connected. As mentioned before, this configuration varies from one operating system to another:

	.. container:: tabs-section
		
		.. container:: tabs-item

			.. rst-class:: tabs-title
				
				Linux

			On Linux the Arduino serial device is named as follows (where X is the device number):

			* ``/dev/ttyUSBX``
			* ``/dev/ttyACMX``

			Where ``/dev/ttyACMX`` is for the new Uno and Mega Arduino's, while ``/dev/ttyUSBX`` is for the old ones.

		.. container:: tabs-item

			.. rst-class:: tabs-title
				
				MacOS

			When specifying the serial port name on Mac OS X, use the following names (where XXX is a unique ID):

			* ``/dev/tty.usbmodemXXX``
			* ``/dev/tty.usbserialXXX``
			
			Where ``tty.usbmodemXXX`` is for new Uno and Mega Arduino's, while ``tty.usbserialXXX`` are the older ones.

		.. container:: tabs-item

			.. rst-class:: tabs-title

				Windows

			When specifying the serial port name on Windows, use the following names:

			* ``COM1``, ``COM2``, etc.
