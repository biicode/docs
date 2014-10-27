.. _bii_arduino_settings:

Configure your port and board
==============================

I changed my Arduino's port, what happens now?
----------------------------------------------
Port detection is automatic, execute ``bii arduino:upload`` to 're-detect' the board.

If you experience problems changing your port or your arduino board, just execute ``bii arduino:settings``


How can I change my Arduino project properties?
-----------------------------------------------

Execute ``bii arduino:settings`` and fill the requested info with the new data:

.. code-block:: bash

	$ bii arduino:settings
	Introduce board: mega2560
	Using arduino port: COM13


Settings options
----------------

.. _arduino_boards:

boards
^^^^^^

Type your Board model, just make sure it's compatible with the Arduino SDK v. 1.0.5 and your IDE supports it. This is a list of the boards supported by default, even though any board is welcomed!

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
	* ``bt328``: Arduino BT w/ ATmega328ad
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

USB port
^^^^^^^^

Biicode automatically detects the USB port your Arduino board is connected. Manual USB Port configuration varies from one operating system to another, so look for your USB port and then type it on the command line after executing ``bii arduino:settings``:



	.. container:: tabs-section
		
		.. container:: tabs-item

			.. rst-class:: tabs-title
				
				Linux/Unix

			For Linux/Unix type ``ls /dev/ttyUSB*`` or ``ls /dev/ttyACM*`` into a terminal window.
			You should see a device called like these:

			* ``/dev/ttyUSBX``
			* ``/dev/ttyACMX``

			Where ``/dev/ttyACMX`` is for the new Uno and Mega Arduino's and ``/dev/ttyUSBX`` is for the old ones. **X** is the device number.

		.. container:: tabs-item

			.. rst-class:: tabs-title
				
				MacOS

			Under Mac, in the Terminal window, type ``ls /dev/cu.*/`` which should give you a name like this one:

			* ``/dev/cu.usbserialXXX``

			In which **XXX** is an unique ID.
			

		.. container:: tabs-item

			.. rst-class:: tabs-title

				Windows

			If using Windows, go to the **Device Manager** and look for an entry under **Ports (COM & LPT)** that says **USB Serial Port (COMX)** specifying the serial port name on Windows, in which X is the device number:

			* ``COM1``, ``COM2``, etc.

