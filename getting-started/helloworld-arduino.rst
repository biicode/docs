"Blink" in Arduino
==================

This example shows how to build a simple *blink* application with biicode.

``IMPORTANT:`` It is not possible to develop C/C++ and Arduino apps simultaneously in the same hive.

Remember that you need to :ref:`configure your biicode workspace <arduino_installation>` with CMake, MinGW and the Arduino SDK.


Create a new hive
-----------------
The first step is to create a new hive (a biicode project) inside your workspace with the ``bii new`` command.

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

With this command you create the next folders

.. code-block:: text

   |-- arduino_hive
   |    +-- bin
   |    +-- blocks
   |    |     +-- my_user_name
   |    |    |     +-- arduino_block
   |    |    |     |       +-- main.cpp
   |    +-- build
   |    +-- cmake
   |    +-- deps
  


These files have the following content:

**main.cpp**

This is the main project file.

biicode uses the ``// bii:#entry_point()`` comment line to define main.cpp like a main file. It is important that you **add this comment in all** the files you want to be **Arduino main files**.

.. literalinclude:: ../_static/code/arduino/hello-world/main_arduino.cpp
   :language: cpp
   :linenos:
   :emphasize-lines: 17

``// bii:#entry_point()``: biicode uses this line to define main.cpp like a main file.
   
**Download the file**

.. |main_arduino| replace:: :download:`main_arduino.cpp <../_static/code/arduino/hello-world/main_arduino.cpp>`

+------------+----------------+
| ZIP        | Single files   |
+============+================+
|      -     | |main_arduino| |
+------------+----------------+

Configure your settings
-----------------------

Configure the hive settings.bii file with the info about your board and serial port. Here a Windows example:

.. code-block:: text
	:emphasize-lines: 2
	
	arduino:
		board: {board: mega2560, no_autolibs: 'false', port: COM7, programmer: usbtinyisp}

If you want to remember how configure your settings, review the section:

	*	:ref:`Arduino settings in MacOS<arduino_default_settings_mac>`
	*	:ref:`Arduino settings in Linux<arduino_default_settings_linux>`
	*	:ref:`Arduino settings in Windows<arduino_default_settings_win>`
		
Build and upload
----------------

Now, you can compile your firmware and upload it in your Arduino. The command ``build`` compiles your firmware, and ``upload`` sends it to your Arduino. 
Move into your arduino hive folder and execute:

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
----------------------

There is a problem with the above example. The use of delay blocks the execution flow of arduino, so if you want, for example, to control a motor, process serial port inputs, or whatever other work you have to do, you **cannot use** the previous blink version, as it blocks execution.
The following code use the method ``millis()`` and 2 control variables to count the time in a period of time. when this time are equal to 1000 the status of the led change. So replace the example before with the next files and don't forget to **change** ``blocks/your_user_name/arduino_block/bii/mains.bii`` **with mainblink.cpp name instead of main_arduino.cpp**. 
	

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

**Downloads**
	
.. |blink.zip| replace:: :download:`blink.zip <../_static/code/arduino/hello-world/blink.zip>`
.. |mainblink.cpp| replace:: :download:`mainblink.cpp <../_static/code/arduino/hello-world/mainblink.cpp>`
.. |blink.cpp| replace:: :download:`blink.cpp <../_static/code/arduino/hello-world/blink.cpp>`
.. |blink.h| replace:: :download:`blink.h <../_static/code/arduino/hello-world/blink.h>`

+--------------------+----------------+
| ZIP (all the files)| Single files   |
+====================+================+
|                    | |mainblink.cpp||
|                    +----------------+
| |blink.zip|        | |blink.cpp|    |
|                    +----------------+
|                    | |blink.h|      |
+--------------------+----------------+

Build and upload to your arduino again:

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7645.js" id="asciicast-7645" async data-speed="2"></script>

	
Publish your code
-----------------

You can easily publish your code using the ``bii publish`` command. You will be requested to provide a **tag** and a **message**. Valid tags are ``STABLE``, ``ALPHA``, ``BETA``, and ``DEV``. They provide information about the development state of your hive. The message is any information describing your publication.

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7629.js" id="asciicast-7629" async data-speed="2"></script>

If your code has been published correctly —as it is the case in the previous example—, you can navigate it here: ``www.biicode.com/user_name``

Reuse it!
---------

Reusing your ``Blink`` class in other projects or blocks is straightforward. Create a new hive, with a default firmware.

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7655.js" id="asciicast-7655" async data-speed="2"></script>


Then modify it with this code and write your own user name.	
	
**main_reuse.cpp**

.. literalinclude:: ../_static/code/arduino/hello-world/main_reuse.cpp
   :language: cpp
   :emphasize-lines: 1
   :linenos:  

**Downloads**

.. |main_reuse| replace:: :download:`main_reuse.cpp <../_static/code/arduino/hello-world/main_reuse.cpp>`


+------------+----------------+
| ZIP        | Single files   |
+============+================+
|      -     | |main_reuse|   |
+------------+----------------+


**Note**: don't forget to define main_reuse.cpp like a main file! :ref:`More info about mains.bii here <mains_bii>`.

Assuming that your user name is *your_user_name* and the block where you published the code was named *your_block*, you could navigate to http://www.biicode.com, go to your profile and see your code there.

Once you have the code, invoke ``find`` to resolve external dependencies, so the Blink class is retrieved. Then, build and upload in your Arduino as usual. Not forget check your Arduino settings to upload correctly:


.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7649.js" id="asciicast-7649" async data-speed="2"></script>


.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7650.js" id="asciicast-7650" async data-speed="2"></script>

