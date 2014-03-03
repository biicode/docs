Arduino MacOS
=============

Download the Arduino Software
---------------------------------
You need to `download the Arduino software <http://arduino.cc/en/Main/Software>`_ first, it is important to choose a SDK compatible with your board. If you need more info visit the `official Arduino website <http://arduino.cc/en/Main/Software>`_.

``IMPORTANT:`` Check you have installed the :ref:`C++ Development Tools<cpp_desktop_mac>`.

Update your environment.bii
----------------------------------

If you haven't done so, you must first :ref:`create a biicode workspace <create_workspace>`.

``IMPORTANT:`` You can only have one coding language for each Hive, so do not mix blocks with  Arduino and C/C++ Desktop apps.

Then you will see in your ``bii_workspace/bii`` folder the following **environment.bii** file with this default configuration:

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

Change the ``compilers path`` in the environment if you have installed the Arduino Software in other folder. On the other side, you have the following tool info:

	* ``arch``: AVR
	* ``family``: Gnu
	* ``version``: 1.0.5

Don't forget to check you have the right version of your SDK. You can see your version in the file ``[Arduino_SDK_path]/revisions.txt``.

.. _arduino_default_settings_mac:
		
Update your board configuration
-------------------------------

Your workspace ``bii/environment.bii`` file also contains some specific settings for your actual Ardino board. This way, all new hives will share the same configuration. Edit the ``boards`` entry reflecting your current setup. These are the default settings you will find wen you open this file: ::

	boards:
  	  - {board: uno, no_autolibs: 'false', port: /dev/tty.usbserial, programmer: usbtinyisp}

You must specify the correct option for each of the fields: ``board``, ``no_autolibs``, ``port``, and ``programmer``:


Board
^^^^^^

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
^^^^^^^^^^^

You can choose ``no_autolibs`` between **'false'** or **'true'**. This setting disables Arduino library detection, so if it's **'false'** you can use Arduino libraries.

This option is interesting because you may not want to use these libraries if you have a better one. For example, you have just done a **Servo** library with a lot of improvements and you prefer to use it, then you would set ``no_autolibs`` value **'true'**.


port
^^^^

``port`` USB is where your Arduino board is connected.

	*	**Mac**

		When specifying the serial port name on Mac OS X, use the following names (where XXX is a unique ID):

		* ``/dev/tty.usbmodemXXX``
		* ``/dev/tty.usbserialXXX``
		
		Where ``tty.usbmodemXXX`` is for new Uno and Mega Arduino's, while ``tty.usbserialXXX`` are the older ones.

Want to know in which usb port is your Arduino connected? Use the command :ref:`arduino:usb<arduino_usb>`.

programmer
^^^^^^^^^^

``programmer`` is referred to the Arduino Programmers (SDK Arduino 1.0.5)

	* ``avrisp``: AVR ISP
	* ``avrispmkii``: AVRISP mkII
	* ``usbtinyisp``: USBtinyISP
	* ``usbasp``: USBasp
	* ``parallel``: Parallel Programmer
	* ``arduinoisp``: Arduino as ISP

