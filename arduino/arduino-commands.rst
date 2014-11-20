.. _bii_arduino_tools:

Arduino commands
=================

This section summarizes the **Arduino commands available to be used with the biicode client program**. You can see these tools if you execute:

.. code-block:: bash

	$ bii -h arduino
	
	SYNOPSIS:
	    $ bii COMMAND [options]
	For help about a command:
	    $ bii COMMAND --help
	To change verbosity, use options --quiet --verbose

	---------Arduino commands--------
	  arduino:build   Build your firmware
	  arduino:configure Configure project with cmake
	  arduino:monitor open serial monitor
	  arduino:settings Configure project settings for arduino
	  arduino:upload  Upload a firmware in Arduino



**Note**: You need to have arduino :ref:`correctly set up <arduino_installation>`.

``bii arduino:configure``: configure your project
-----------------------------------------------

If you have configured your project as a C/C++ project and you want to develop in arduino language, this command helps you! Enter it and configure your project like an arduino project. It invokes arduino cross compiler and you are ready to start with your arduino.

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
	-- Build files have been written to: [YOUR_BII_WORKSPACE/YOUR_PROJECT]/build

.. container:: infonote

	Execute ``cmake --help`` to check all generators available.
	Here's how to configure :ref:`Eclipse for Arduino<bii_arduino_ide>`


``bii arduino:build``: build your project
-------------------------------------------

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

``bii arduino:upload``: send your code into the Arduino
----------------------------------------------------------

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



.. _bii_arduino_settings:

``bii arduino:settings``: configure your Arduino settings
-----------------------------------------------------------

This command updates your settings with the info about your board and the IDE, if you want to use one.

.. code-block:: bash

	$ bii arduino:settings
	Enter SDK path (/../biicode_env/arduino-1.0.6): [ENTER]
	Enter board (/o list supported options): mega2560
	Using arduino port: COM13


.. container:: infonote

    :ref:`Set your own settings manually<bii_arduino_settings>`.
    When using non official arduino boards, add the board support to your IDE (if using one), and type the board on ``bii arduino:settings``. 


``bii arduino:monitor``: start a serial monitor
--------------------------------------------------

This command open a serial monitor to read the serial port of your Arduino board.

.. code-block:: bash

	$ bii arduino:monitor

