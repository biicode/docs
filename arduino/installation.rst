.. _arduino_installation:

Installation
============

This section describes how to **set up your development environment for working on Arduino projects with biicode**. The installation steps depend on you current development platform. Simply select your operating system from the options you will find in the sections bellow.

1. Biicode initial setup
------------------------

First of all, **you need to complete the biicode general installation**. Follow :ref:`the instructions in the general documentation, following this link <first_steps>`. You must: 

* **Sign up** with biicode
* Download and install the **client binaries** for your operating system
* Create a biicode **workspace**

After you have complete these steps, proceed with the following sections:

2. Install the development tools
--------------------------------

In order to configure and compile your Arduino projects with biicode, you need to install some additional tools. CMake is an open source tool that manages the software building process in a compiler-independent manner. Select your operating system bellow, and follow the instructions.

.. container:: tabs-section
	
	.. _arduino_cmake_linux:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Linux

		Install the required development tools as root:

		.. code-block:: bash

			$ sudo apt-get install build-essential cmake

		That's all!

	.. _arduino_cmake_mac:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			MacOS

		You need to get installed both XCode Developer Tools and CMake:

		#. The XCode Developer Tools

		   .. code-block:: bash

		   	$ xcode-select --install


		#. Download and install the appropriate `version of CMake <http://www.cmake.org/cmake/resources/software.html>`_ for your Mac OSX.

	.. _arduino_cmake_win:
	.. container:: tabs-item

		.. rst-class:: tabs-title

			Windows

		1. Download and install CMake. You can `download the latest version of CMake here <http://www.cmake.org/cmake/resources/software.html>`_.

		3. Add to your user ``PATH`` environment variable the path to CMake. We recommend `Rapid Environment Editor <http://www.rapidee.com/>`_ for editing environment variables. Otherwise, go to **My Computer**, click **Properties**, click **Advanced System Settings** and in the System Properties window click the **Environment Variables** button. then you will see a new window and in **User Variables** you'll find the variable ``PATH``:

		   .. image:: /_static/img/cpp_windows_path.png

		Add CMake binaries folders (i.e. ``C:\Program Files (x86)\CMake 2.8\bin``).

		You might need to close and open again any ``cmd`` windows in order to load the new value for the ``PATH`` variable.


Now, you can check CMake is working properly. Open a terminal window and run the following command. If the output message looks similar to this, CMake is successfully installed.

.. code-block:: bash

	$ cmake --version
	cmake version [version]


3. Install Arduino software
---------------------------

You need to `download the Arduino software <http://arduino.cc/en/Main/Software>`_ first, it is important to choose a SDK compatible with your board. If you need more info visit the `official Arduino website <http://arduino.cc/en/Main/Software>`_.

**Note:** In Windows, install the Arduino software into ``C:/Program Files/Arduino`` and not into ``C:/Program Files/Arduino (x86)``. This is important because some CMake versions can not interpret correctly this path.

4. Update your workspace configuration
--------------------------------------

If you haven't done so, you must first :ref:`create a biicode workspace <create_workspace>`.

**Note:** You can only have one coding language for each Hive, so do not mix blocks with  Arduino and C/C++ Desktop apps in the same hive.

Your workspace ``bii/environment.bii`` file contains this default configuration (select your operating system):

.. container:: tabs-section

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Linux

		Default arduino configuration in your workspace ``bii/environment.bii`` file:

		.. code-block:: text
			
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

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Mac OS X

		Default arduino configuration in your workspace ``bii/environment.bii`` file:

		.. code-block:: text
			
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

	.. container:: tabs-item

		.. rst-class:: tabs-title

			Windows

		Default arduino configuration in your workspace ``bii/environment.bii`` file:

		.. code-block:: text
			
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

Change the ``compilers path`` in the environment if you have installed the Arduino Software in other folder. On the other side, you have the following tool info:

	* ``arch``: AVR
	* ``family``: Gnu
	* ``version``: 1.0.5

Please, make sure you have the right version of the Arduino SDK. 

.. container:: infotool

	If you installed the arduino debian package you can see the SDK version entering ``dpkg --list arduino``:

	.. code-block:: text

		||/ Name        Version            Arch   Description
		+++-===========-==================-======-=========================
		ii  arduino     1:1.0.5+dfsg2-1    all    AVR development board IDE


	The previous output indicates the installed version is **1.0.5**.

.. _arduino_settings:

5. Update your board configuration
----------------------------------

Your workspace ``bii/environment.bii`` file also contains **some specific settings for your actual Ardino board**. This way, all new hives will share the same configuration. Edit the ``boards`` entry reflecting your current setup. These are the default settings you will find wen you open this file (select your operating system):

.. container:: tabs-section
	
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Linux

		.. code-block:: text

			arduino:
			  boards:
		  	    - {board: uno, no_autolibs: 'false', port: /dev/ttyUSB0, programmer: usbtinyisp}

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			MacOS

		.. code-block:: text
		
			arduino:
			  boards:
	  	  	    - {board: uno, no_autolibs: 'false', port: /dev/tty.usbserial, programmer: usbtinyisp}

	.. container:: tabs-item

		.. rst-class:: tabs-title

			Windows

		.. code-block:: text
			
			arduino:
			  boards:
			    - {board: uno, no_autolibs: 'false', port: COM3, programmer: usbtinyisp}
	
As you can see, the only different between operating systems is in the ``port`` field configuration. You must specify the appropriate information for each of the fields: ``board``, ``no_autolibs``, ``port``, and ``programmer``:

* **board**: This is your Arduino Board model. It must be compatible with the Arduino SDK v. 1.0.5, and must have one of the following values:

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

	
* **no_autolibs**: You can set ``no_autolibs`` to ``false`` or ``true`` values. This setting disables Arduino library detection, so if it's ``false`` you can use Arduino libraries.

	This option is useful because you may not want to use these libraries if you have a better one. For example, you have just done a **Servo** library with a lot of improvements and you prefer to use it. In this case you only need to set the ``no_autolibs`` value to ``true``.

* **port**: the USB interface where your Arduino board is connected. As mentioned before, this configuration varies from one operating system to another:

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


	You can use the ``bii arduino:usb`` command to identify the connection port of your Arduino board (:ref:`learn more about this command following this link<arduino_usb>`).

* **programmer**: This field indicates the Arduino Programmers (SDK Arduino 1.0.5). Available options are:

	* ``avrisp``: AVR ISP
	* ``avrispmkii``: AVRISP mkII
	* ``usbtinyisp``: USBtinyISP
	* ``usbasp``: USBasp
	* ``parallel``: Parallel Programmer
	* ``arduinoisp``: Arduino as ISP
