.. _arduinows:

=======================================
How to configure your biicode workspace
=======================================

``IMPORTANT:`` You can only have one language for Hive, so do not mix blocks with  Arduino and C/C++ Desktop apps.

Download the Arduino Software
=============================
First, you have to download the latest release Arduino IDE from the `Arduino software website <http://arduino.cc/en/Main/Software>`_ and install it.

Update your environment.bii
===========================

If you haven't done so, you must first :ref:`create a biicode workspace <create_workspace>`.
Then you will see in your ``bii_workspace/bii`` folder the following **enviroment.bii** file (depending on your OS) with this default configuration:

Winodws
^^^^^^^
.. code-block:: text
	:emphasize-lines: 1, 7, 8, 9

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

MacOS
^^^^^
.. code-block:: text
	:emphasize-lines: 1, 7, 8, 9
	
	arduino:
	  boards:
	  - {board: uno, no_autolibs: 'false', port: /dev/tty.usbserial, programmer: usbtinyisp}
	  builders:
	  - path: make
		tool: {family: MAKE}
	  compilers:
	  - path: /Applications/Arduino.app/Contents/Resources/Java
		tool: {arch: AVR, family: GNU, version: 1.0.5}
	  configurers:
	  - path: cmake
		tool: {family: CMake}

Linux
^^^^^
.. code-block:: text
	:emphasize-lines: 1, 7, 8, 9
	
	arduino:
	  boards:
	  - {board: uno, no_autolibs: 'false', port: /dev/ttyUSB0, programmer: usbtinyisp}
	  builders:
	  - path: make
		tool: {family: MAKE}
	  compilers:
	  - path: /usr/share/arduino
		tool: {arch: AVR, family: GNU, version: 1.0.5}
	  configurers:
	  - path: cmake
		tool: {family: CMake}

Change the ``compilers path`` in the environment if you have installed the Arduino Software in other folder. By other side, you have the following tool info:

	* ``arch``: AVR
	* ``family``: MINGW (windows) or Gnu (linux/Mac)
	* ``version``: 1.0.5

You can see the version of your SDK into the file ``[Arduino_SDK_path]/revisions.txt``
		
Update your default_settings.bii
================================

If you want to create all your hives with the same settings, you should change this file. So, enter in ``bii_workspace/bii`` folder, open the **default_settings.bii** file and write the options according to your Arduino settings. These are the default settings:

	*	Winodws

		{``board``: uno, ``no_autolibs``: 'false', ``port``: COM3, ``programmer``: usbtinyisp}

	*	MacOS
	
		{``board``: uno, ``no_autolibs``: 'false', ``port``: /dev/tty.usbserial, ``programmer``: usbtinyisp}

	*	Linux
	
		{``board``: uno, ``no_autolibs``: 'false', ``port``: /dev/ttyUSB0, ``programmer``: usbtinyisp}

Then you have the following options to change each one.

Board
-----

``Board`` is referred to Arduino Boards (SDK Arduino 1.0.5), and you have these choices:

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
-----------

You can choose ``no_autolibs`` like **'false'** or **'true'**. This setting is made to disable Arduino library detection if it's **'false'**, else you can't use the Arduino libraries.

This option is interesting because you could not want use these libraries if you have a better **Servo** library and you prefer use it.


port
----

USB where you have the Arduino board connected. It depends on your OS.


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


programmer
----------
``programmer`` is referred to the Arduino Programmers (SDK Arduino 1.0.5)

	* ``avrisp``: AVR ISP
	* ``avrispmkii``: AVRISP mkII
	* ``usbtinyisp``: USBtinyISP
	* ``usbasp``: USBasp
	* ``parallel``: Parallel Programmer
	* ``arduinoisp``: Arduino as ISP

