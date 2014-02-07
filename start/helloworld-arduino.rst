"Hello World!" in Arduino
=============================
``IMPORTANT:`` You can only have one language for Hive, so do not mix blocks with  Arduino and C/C++ Desktop apps.

Remember that you need to :ref:`configure your biicode workspace <arduinows>` with the Arduino SDK.

Create your hive
-------------------

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

**main.cpp**

This is the main project file.

.. literalinclude:: ../_static/code/arduino/hello-world/main.cpp
   :language: cpp

**bii/mains.bii**

biicode use this file to define main.cpp like a main file. You have all the :ref:`info about mains.bii here <mains_bii>`.

.. code-block:: text

	main.cpp
	
Configure your settings
--------------------------------------

Configure the hive settings.bii file with the info about your board and serial port.

.. code-block:: text
	:emphasize-lines: 2
	
	arduino:
		board: {board: mega2560, no_autolibs: 'false', port: COM7, programmer: usbtinyisp}
		
Build and Upload
-------------------

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
---------------------------

There is a problem with the above example. The use of delay blocks the execution flow of arduino, so if you want, for example, to control a motor, process serial port inputs, or whatever other work you have to do, you **cannot use** the previous blink version, as it blocks execution.
The following code use the method ``millis()`` and 2 control variables to count the time in a period of time. when this time are equal to 1000 the status of the led change.
	

**blink.h**

.. literalinclude:: ../_static/code/arduino/hello-world/blink.h
   :language: cpp


**blink.cpp**

.. literalinclude:: ../_static/code/arduino/hello-world/blink.cpp
   :language: cpp

**main.cpp**


.. literalinclude:: ../_static/code/arduino/hello-world/mainblink.cpp
   :language: cpp
	

Publish your code
----------------------------

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
---------------
TODO:
