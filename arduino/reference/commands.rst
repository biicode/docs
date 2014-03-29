.. _bii_arduino_tools:

Command list
============

This section summarizes the **Arduino commands available to be used with the biicode client program**. You can see these tools if you execute:

.. code-block:: bash

	$ bii -h arduino
	...

	---------EXPERIMENTAL Arduino general tools commands--------
	  arduino:build   Build the project (with Make, Mingw32-make or NMake)
	  arduino:configure Configure project with cmake
	  arduino:monitor EXPERIMENTAL open serial monitor
	  arduino:settings Configure hive settings for arduino
	  arduino:upload  Upload a firmware in Arduino
	  arduino:wizard  Create a default class with constructor/destructor and a main.cpp or main.c


**Note**: You need to have arduino :ref:`correctly set up <arduino_installation>`.

``bii arduino:configure``: Configure your project
-------------------------------------------------

If you have configured your hive as a C/C++ project and you want to develop in arduino language, this command helps you! Enter it and configure your hive like an arduino project. It invokes arduino cross compiler and you are ready to start with your arduino.

.. code-block:: bash

	$ bii arduino:configure

	invoking cmake  -G "MinGW Makefiles" -Wno-dev ../cmake
	-- The C compiler identification is GNU 4.3.2
	-- The CXX compiler identification is GNU 4.3.2
	-- Arduino SDK version 1.0.5: [YOUR_SDK_PATH]
	-- Check for working C compiler: [YOUR_PATH]/avr-gcc.exe
	-- Check for working C compiler: [YOUR_PATH]/avr-gcc.exe -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Check for working CXX compiler: [YOUR_PATH]/avr-g++.exe
	-- Check for working CXX compiler: [YOUR_PATH]/avr-g++.exe -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Configuring done
	-- Generating done
	-- Build files have been written to: [YOUR_BII_WORKSPACE/YOUR_HIVE]/build

.. _bii_arduino_settings:

``bii arduino:settings``: Managing your hive settings
-----------------------------------------------------

This command update your settings with the info about your board and the IDE, if you want to use one.

.. code-block:: bash

	$ bii arduino:settings
	Introduce board: uno
	Arduino detected on port COM13
	Select IDE: (eclipse/none) 
	Introduce ide (default:None) (/o list options): none

``bii arduino:build``: Build the project
----------------------------------------

This command uses the cross compiler of Arduino (C compiler -> avr-gcc and CXX compiler -> avr-g++) to build and compile the project.

.. code-block:: bash

	$ bii arduino:build
	
	...
	
	invoking cmake   -G "MinGW Makefiles" -Wno-dev ../cmake
	-- The C compiler identification is GNU 4.3.2
	-- The CXX compiler identification is GNU 4.3.2
	-- Arduino SDK version 1.0.5: [YOUR_SDK_PATH]
	-- Check for working C compiler: [YOUR_PATH]/avr-gcc.exe
	-- Check for working C compiler: [YOUR_PATH]/avr-gcc.exe -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Check for working CXX compiler: [YOUR_PATH]/avr-g++.exe
	-- Check for working CXX compiler: [YOUR_PATH]/avr-g++.exe -- works

	...

	[100%] Built target your_user_name_block_firmware


``bii arduino:upload``: Upload a firmware in Arduino
----------------------------------------------------

When you want to deploy your code into the arduino, this command sends your previously built firmware to the arduino.

.. code-block:: bash

	$ bii arduino:upload

	...

	[100%] Built target [USER]_my_block_main

	...

	Writing | ################################################## | 100% 0.00s

	avrdude.exe: 0 bytes of eeprom written

	avrdude.exe: safemode: Fuses OK

	avrdude.exe done.  Thank you.

	[100%] Built target [USER]_my_block_main-upload
