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

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7624.js" id="asciicast-7624" async data-speed="2"></script>

Now you can create automatically a main file with a default blink template, you just use the ``bii arduino:wizard`` command (more information about this command :ref:`here <bii_arduino_wizard>`).

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7652.js" id="asciicast-7652" async data-speed="2"></script>

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
	|         |     |		|-- main_arduino.cpp
	|         |     |		|-- bii
	|         |     |		|	|-- mains.bii
	



These files have the following content:

**main_arduino.cpp**

This is the main project file.

.. literalinclude:: ../_static/code/arduino/hello-world/main_arduino.cpp
   :language: cpp
   :linenos:

**Downloads**

.. |main_arduino| replace:: :download:`main_arduino.cpp <../_static/code/arduino/hello-world/main_arduino.cpp>`

+------------------+
| Single file      |
+==================+
| |main_arduino|   |
+------------------+
	
**bii/mains.bii**

biicode uses this file to define main_arduino.cpp like a main file. You have all the :ref:`info about mains.bii here <mains_bii>`.

.. code-block:: text

	main_arduino.cpp

	
Creating reusable code
^^^^^^^^^^^^^^^^^^^^^^^^

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

**NOTE:** This ZIP file also contains the bii folder with the right mains.bii.

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

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7645.js" id="asciicast-7645" async data-speed="2"></script>

	

Publish your code and reuse it
---------------------------------

Once your have written, compiled and successfully executed some code, surely you are willing to share it with the biicode community! Uploading your code to biicode is really simple using the ``bii publish`` command. You will be requested to provide a **tag** and a **message**. Valid tags are ``STABLE``, ``ALPHA``, ``BETA``, and ``DEV``. They provide information about the development state of your hive. The message is any information describing your publication.

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7629.js" id="asciicast-7629" async data-speed="2"></script>

If your code has been published correctly —as it is the case in the previous example—, you can navigate it here: ``www.biicode.com/user_name``

Reuse it!
^^^^^^^^^^

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

+------------------+
| Single file      |
+==================+
| |main_reuse|     |
+------------------+



**Note**: don't forget to define main_reuse.cpp like a main file! :ref:`More info about mains.bii here <mains_bii>`.

Assuming that your user name is *your_user_name* and the block where you published the code was named *your_block*, you could navigate to http://www.biicode.com, go to your profile and see your code there.

Once you have the code, invoke ``find`` to resolve external dependencies, so the Blink class is retrieved. Then, build and upload in your Arduino as usual. Not forget check your Arduino settings to upload correctly:


.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7649.js" id="asciicast-7649" async data-speed="2"></script>


.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7650.js" id="asciicast-7650" async data-speed="2"></script>

