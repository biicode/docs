.. _bii_arduino_tools:

Arduino Tools list
==================
This section summarizes the **Arduino commands available to be used with the biicode client program**. You can see these tools if you execute:

.. code-block:: bash
	
	$ bii -h arduino
	
	...

	---------EXPERIMENTAL Arduino general tools commands--------
	  arduino:build   Build the project (with Make, Mingw32-make or NMake)
	  arduino:configure Configure project with cmake
	  arduino:settings Shows (initializes from default if not existing) hive settings
	  arduino:upload  Upload a firmware in Arduino
	  arduino:usb     Scans the USB devices
	  arduino:wizard  Create a default class with constructor/destructor and a main.cpp or main.c


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
	-- Generating david_serial_arduino
	-- Configuring done
	-- Generating done
	-- Build files have been written to: [YOUR_BII_WORKSPACE/YOUR_HIVE]/build

	  
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

	
``bii arduino:settings``: Shows hive settings
---------------------------------------------
This command shows your settings about arduino or initializes the settings from default workspace settings in your hive if not existing.

.. code-block:: bash

	$ bii arduino:settings
	INFO: These are your arduino settings for this hive
	INFO: board: {board: uno, no_autolibs: 'false', port: COM3, programmer: usbtinyisp}
	builder: {family: MINGW}
	compiler: {arch: AVR, family: MINGW, version: 1.0.5}
	configurer: {family: CMake}

	INFO: If you want to change it, you have to modify this file:
		[YOUR_BII_WORKSPACE/YOUR_HIVE]/bii/settings.bii


``bii arduino:usb``: Scans the USB devices
------------------------------------------
Shows us which is the port where you have connected your arduino, so you can configure your settings according to the port and board type.

.. code-block:: bash

	$ bii arduino:usb
	USB Devices:
	  Arduino Leonardo (COM3)		
		

``bii arduino:upload``: Upload a firmware in Arduino
----------------------------------------------------
When you are sure about the firmware you want to upload in the arduino, this command sends automatically your firmware to it.

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


``bii arduino:wizard``: Create default classes or main files
------------------------------------------------------------
This command has several utilities. It's a very simple way to create us a default class or main.cpp/main.c for your project. You have this options to execute the command:


**Without options**
By default it is called to create a new default class.

.. code-block:: bash
	
	$ bii arduino:wizard
	Class name (default: newclass): my_lib

	Creating a new class named "my_lib"
	WARN:
	You're not in a valid block
	INFO: You can save it in a block of your choice.
	For example: 'my_block2' or 'user25/my_block4'
	Block name (default:my_block): other_block
	All files will be saved in your default directory [YOUR_HIVE]/your_user_name/other_block

	These files have been created:
		my_lib.h
		my_lib.cpp


**With options**
Creating a default class:

.. code-block:: bash
	
	$ bii arduino:wizard --newclass my_lib

	Creating a new class named "my_lib"
	WARN:
	You're not in a valid block
	INFO: You can save it in a block of your choice.
	For example: 'my_block2' or 'user25/my_block4'
	Block name (default:my_block): [ENTER]
	All files will be saved in your default directory [YOUR_HIVE]/your_user_name/my_block

	These files have been created:
		my_lib.h
		my_lib.cpp

Creating a default main.cpp file:

.. code-block:: bash
	
	$ bii arduino:wizard --newclass my_main
	INFO: Default extension file is '.cpp'. You can use '.c' extension too.

	Creating a main file "my_main.cpp"
	WARN:
	You're not in a valid block
	INFO: You can save it in a block of your choice.
	For example: 'my_block2' or 'user25/my_block4'
	Block name (default:my_block): firmware
	All files will be saved in your default directory [YOUR_HIVE]/your_user_name/firmware

	File my_main.cpp has been created in [YOUR_HIVE]/your_user_name/firmware/my_main.cpp


Creating a default main.c file:

.. code-block:: bash
	
	$ bii arduino:wizard --newclass my_main.c

	Creating a main file "my_main.c"
	WARN:
	You're not in a valid block
	INFO: You can save it in a block of your choice.
	For example: 'my_block2' or 'user25/my_block4'
	Block name (default:my_block): firmware
	All files will be saved in your default directory [YOUR_HIVE]/your_user_name/firmware

	File my_main.c has been created in [YOUR_HIVE]/your_user_name/firmware/my_main.c



















