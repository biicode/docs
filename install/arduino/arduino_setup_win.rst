Arduino Windows development tools install
============================================

Download the Arduino Software
---------------------------------
You need to `download the Arduino software <http://arduino.cc/en/Main/Software>`_ first, it is important to choose a SDK compatible with your board. If you need more info visit the `official Arduino website <http://arduino.cc/en/Main/Software>`_.

``Windows Users``: **Install** the Arduino software into **C:/Program Files/Arduino** and not into C:/Program Files/Arduino (x86). It is important because some CMake versions can not interpret correctly this path.





Update your environment.bii
---------------------------------

If you haven't done so, you must first :ref:`create a biicode workspace <create_workspace>`.

``IMPORTANT:`` You can only have one language for Hive, so do not mix blocks with  Arduino and C/C++ Desktop apps.

Then you will see in your ``bii_workspace/bii`` folder the following **enviroment.bii** file (depending on your OS) with this default configuration:


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


Change the ``compilers path`` in the environment if you have installed the Arduino Software in other folder. By other side, you have the following tool info:

	* ``arch``: AVR
	* ``family``: MINGW (windows) or Gnu (linux/Mac)
	* ``version``: 1.0.5

You can see the version of your SDK into the file ``[Arduino_SDK_path]/revisions.txt``
		
Update your default_settings.bii
---------------------------------

If you want to create all your hives with the same settings, you should change this file. So, enter in ``bii_workspace/bii`` folder, open the **default_settings.bii** file and write the options according to your Arduino settings. These are the default settings:

	*	**Winodws**

		{``board``: uno, ``no_autolibs``: 'false', ``port``: COM3, ``programmer``: usbtinyisp}


Then you have the following options to change each one.


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

You can choose ``no_autolibs`` like **'false'** or **'true'**. This setting is made to disable Arduino library detection if it's **'false'**, else you can't use the Arduino libraries.

This option is interesting because you could not want use these libraries if you have a better one. For example, you have just done a **Servo** library with a lot of improvements and you prefer use it, then you would assign to ``no_autolibs`` **'true'**.


port
^^^^

``port`` USB where you have the Arduino board connected. It depends on your OS.

	*	**Windows**

		When specifying the serial port name on Windows, use the following names:

		* ``com1`` ``com2`` ... ``comN``

programmer
^^^^^^^^^^

``programmer`` is referred to the Arduino Programmers (SDK Arduino 1.0.5)

	* ``avrisp``: AVR ISP
	* ``avrispmkii``: AVRISP mkII
	* ``usbtinyisp``: USBtinyISP
	* ``usbasp``: USBasp
	* ``parallel``: Parallel Programmer
	* ``arduinoisp``: Arduino as ISP

