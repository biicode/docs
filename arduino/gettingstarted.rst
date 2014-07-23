.. _arduino_getting_started:


Getting started
===============

This example shows how to install biicode, code an Arduino non blocking blink ith the blick library and upload it to your Arduino. You don't need to install any blinck library, biicode will download and configure it automatically for you, |fenix_blink_biicode_link|


.. |fenix_blink_biicode_link| raw:: html

   <a href="https://www.biicode.com/fenix/fenix/blink/master" target="_blank">it is already in biicode!.</a>


1. Installing biicode and Arduino tools
---------------------------------------

First |downloads_link| and install biicode

.. |downloads_link| raw:: html

   <a href="https://www.biicode.com/downloads" target="_blank">download</a>

Then, open the console and type

.. code-block:: bash

   ~$ bii setup:arduino

This will help you to install a group of external tools (Arduino SDK, CMake and MinGW or GCC).

.. container:: infonote

    If you encounter any problem installing the Arduino tools, you can see :ref:`how to install Arduino tools manually <arduino_installation>`

2. Create your project
----------------------

First, create a project:

.. code-block:: bash

  ~$ bii init myproject

Then we can use the convenience ``new`` command to create some folders and a "Simple Blink" Arduino main file. Of course, you can do it manually too.

.. code-block:: bash

  ~$ cd myproject
  ~/myproject$ bii new myuser/myblock --hello=arduino

This should be the resulting layout:

.. code-block:: text

  +-- myproject
  |    +-- bii
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- myblock
  |    |    |    |    +-- main.cpp
  |    +-- deps

3. Define your board
--------------------

Just, define your Arduino board using the arduino:settings command. In this example we use an Arduino Uno, but you can use another like Mega2560.

.. code-block:: bash

  ~/myproject$ bii arduino:settings
  Introduce board (/o list options): uno
  Using arduino port: COM4

4. Build and upload your program
--------------------------------
Lets check that everything is fine by building and uploading the blink aplication to your Arduino.

.. code-block:: bash

  ~/myproject$ bii arduino:upload
  ...
  Writing | ################################################## | 100% 0.00s

  avrdude.exe: 0 bytes of eeprom written

  avrdude.exe: safemode: Fuses OK

  avrdude.exe done.  Thank you.

  [100%] Built target myuser_myblock_main-upload
  Upload finished

5. Depending on Fenix Blink
---------------------------

Copy the following code containing the new blink into the main.cpp file

**main.cpp**

.. code-block:: cpp
  :emphasize-lines: 1

  #include "fenix/blink/blink.h"
  Blink my_blink;
  void setup() {
    //pin = 13, interval = 1000 ms
    my_blink.setup(13, 1000);
  }
  void loop() {
    my_blink.loop();
  }

This code requires the fenix's blink.h file. If you try to arduino:upload you will get a build error.

Execute the following command to find unresolved dependencies and retrieve necessary files from servers:

.. code-block:: bash

   ~/myproject$ bii find

6. Build and upload
-------------------

Now can now build your firmware and upload it to your Arduino

.. code-block:: bash

  ~/arduino_hello_project$ bii arduino:upload
	...
  Writing | ################################################## | 100% 0.00s

  avrdude.exe: 0 bytes of eeprom written

  avrdude.exe: safemode: Fuses OK

  avrdude.exe done.  Thank you.

  [100%] Built target myuser_myblock_main-upload
  Upload finished

That’s it, if you see that output fenix's blink.h was downloaded and uploaded in your project! You can check the deps folder, the blink.h code is there.

Didn't work? No problem, read or contact us in |biicode_forum_link|

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>



Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">Write us!</a>
