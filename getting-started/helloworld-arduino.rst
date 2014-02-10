"Blink" in Arduino
===================
This example shows how to build a simple *blink* application with biicode.

``IMPORTANT:`` You can only have one language for Hive, so do not mix blocks with  Arduino and C/C++ Desktop apps.

Remember that you need to :ref:`configure your biicode workspace <arduino_installation>` with the Arduino SDK.

Start with an Arduino example
-------------------------------

Create a new hive
^^^^^^^^^^^^^^^^^^

Creating a new hive with the ``bii new`` command.

.. code-block:: bash
	:emphasize-lines: 1, 4, 6

	$ bii new arduino_hive
	Created new hive arduino_hive
	Select language: (java/node/fortran/python/cpp/arduino/None)
	Introduce lang (default:None): arduino
	How would you like to name your first block?
	Introduce block name (default:arduino_block): arduino_block
	INFO: block name: arduino_block
	Generate a default firmware?  (YES/no) [ENTER]
	INFO: Default extension file is '.cpp'. You can use '.c' extension too.

	Creating a main file "main.cpp"

	File main.cpp has been created in [HIVE_PATH]/blocks/[USER]/arduino_block/main.cpp

With this command you create the next tree:

.. code-block:: text
	:emphasize-lines: 9, 10, 11, 12

	|-- arduino_hive
	|    +-- bii
	|    +-- bin
	|    +-- build
	|    +-- deps
	|    +-- blocks
	|         +-- my_user_name
	|         |     +-- arduino_block
	|         |     |		|-- main.cpp
	|         |     |		|-- bii
	|         |     |		|	|-- mains.bii
	



These files have the following content:

**main_arduino.cpp**

This is the main project file.

.. literalinclude:: ../_static/code/arduino/hello-world/main_arduino.cpp
   :language: cpp
   :linenos:

**Download the file**

Single files: :download:`main_arduino.cpp <../_static/code/arduino/hello-world/main_arduino.cpp>`

	
**bii/mains.bii**

biicode uses this file to define main_arduino.cpp like a main file. You have all the :ref:`info about mains.bii here <mains_bii>`.

.. code-block:: text

	main_arduino.cpp


Configure your settings
^^^^^^^^^^^^^^^^^^^^^^^^^^

Configure the hive settings.bii file with the info about your board and serial port. Here a Windows example:

.. code-block:: text
	:emphasize-lines: 2
	
	arduino:
		board: {board: mega2560, no_autolibs: 'false', port: COM7, programmer: usbtinyisp}

If you want to remember how configure your settings, review the section:

	*	:ref:`Arduino settings in MacOS<arduino_default_settings_mac>`
	*	:ref:`Arduino settings in Linux<arduino_default_settings_linux>`
	*	:ref:`Arduino settings in Windows<arduino_default_settings_win>`
		
Build and Upload
^^^^^^^^^^^^^^^^^^^^

Now, you can compile your firmware and upload it in your Arduino. The command ``build`` compiles your firmware, and ``upload`` sends it to your Arduino. Enter into your arduino hive folder and execute:

.. code-block:: bash
	:emphasize-lines: 2, 8

	$ cd arduino_hive
	$ bii arduino:build
	
	...
	
	[100%] Built target [USER]_arduino_block_main
	
	$ bii arduino:upload
	
	...
	
	Writing | ################################################## | 100% 0.00s

	avrdude.exe: 0 bytes of eeprom written

	avrdude.exe: safemode: Fuses OK

	avrdude.exe done.  Thank you.

	[100%] Built target [USER]_arduino_block_main-upload
	
	
Creating reusable code
^^^^^^^^^^^^^^^^^^^^^^^^

There is a problem with the above example. The use of delay blocks the execution flow of arduino, so if you want, for example, to control a motor, process serial port inputs, or whatever other work you have to do, you **cannot use** the previous blink version, as it blocks execution.
The following code use the method ``millis()`` and 2 control variables to count the time in a period of time. when this time are equal to 1000 the status of the led change.
	

**blink.h**

.. literalinclude:: ../_static/code/arduino/hello-world/blink.h
   :language: cpp
   :linenos:


**blink.cpp**

.. literalinclude:: ../_static/code/arduino/hello-world/blink.cpp
   :language: cpp
   :linenos:

**mainblink.cpp**

.. literalinclude:: ../_static/code/arduino/hello-world/mainblink.cpp
   :language: cpp
   :linenos:

**Download all the files**
	
ZIP file: :download:`blink.zip <../_static/code/arduino/hello-world/blink.zip>`
	
Single files: :download:`mainblink.cpp <../_static/code/arduino/hello-world/mainblink.cpp>` :download:`blink.cpp <../_static/code/arduino/hello-world/blink.cpp>` :download:`blink.h <../_static/code/arduino/hello-world/blink.h>`


	
Publish your code and reuse it
---------------------------------

Once your have written, compiled and successfully executed some code, surely you are willing to share it with the biicode community! Uploading your code to biicode is really simple using the ``bii publish`` command. You will be requested to provide a **tag** and a **message**. Valid tags are ``STABLE``, ``ALPHA``, ``BETA``, and ``DEV``. They provide information about the development state of your hive. The message is any information describing your publication.

.. code-block:: bash

	$ bii publish
	block:   your_user_name/arduino_block
	Introduce tag: STABLE
	Introduce msg: My first project with biicode
	  Reading Hive...
	  Checking block your_user_name/your_user_name/arduino_block/master
		  ... your block is being published here

	Successfully published your_user_name/arduino_block(your_user_name/master): 0

If your code has been published correctly —as it is the case in the previous example—, you can navigate it here: ``www.biicode.com/user_name``

Reuse it!
^^^^^^^^^^

Reusing your ``Blink`` class in other projects or blocks is straightforward. Create a new hive, with a default firmware and modify it with this code.

**main_reuse.cpp**

.. literalinclude:: ../_static/code/arduino/hello-world/main_reuse.cpp
   :language: cpp
   :linenos:  

**Download the file**

Single files: :download:`main_reuse.cpp <../_static/code/arduino/hello-world/main_reuse.cpp>`


**Note**: don't forget to define main_reuse.cpp like a main file! :ref:`More info about mains.bii here <mains_bii>`.

Assuming that your user name is *your_user_name* and the block where you published the code was named *your_block*, you could navigate to http://www.biicode.com, go to your profile and see your code there.

Once you have the code, invoke ``find`` to resolve external dependencies, so the Blink_lib class is retrieved. Then, build and upload in your Arduino as usual. Not forget check your Arduino settings to upload correctly:

.. code-block:: bash

	$ bii find
	...
	$ bii arduino:build
	...
	$ bii arduino:upload

	Uploading...[ 90%] Built target uno_CORE
	[100%] Built target your_user_name_my_block_blink
	Scanning dependencies of target [USER]_my_block_blink-upload

	avrdude.exe: AVR device initialized and ready to accept instructions

	Reading | ################################################## | 100% 0.00s

	avrdude.exe: Device signature = 0x1e950f
	avrdude.exe: reading input file "[USER]_my_block_blink.hex"
	avrdude.exe: input file [USER]_my_block_blink.hex auto detected as Intel Hex
	avrdude.exe: writing flash (1116 bytes):

	Writing | ################################################## | 100% 0.18s

	avrdude.exe: 1116 bytes of flash written
	avrdude.exe: reading input file "[USER]_my_block_blink.eep"
	avrdude.exe: writing eeprom (0 bytes):

	Writing | ################################################## | 100% 0.00s

	avrdude.exe: 0 bytes of eeprom written

	avrdude.exe: safemode: Fuses OK

	avrdude.exe done.  Thank you.

	[100%] Built target [USER]_my_block_blink-upload

