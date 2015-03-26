.. _arduino_getting_started:


Getting started
===============

This section shows the first steps to use biicode with your Arduino.

Here we will learn:

* :ref:`How to install biicode <installing_biicode_arduino>`.
* :ref:`Code your first "blink" <create_your_project>`.
* :ref:`Code a "non blocking blink" reusing from the blink library <depending_on_fenix_blink>`.

  You don't need to install the blink library, biicode will download and configure it automatically for you, |fenix_blink_biicode_link|

.. |fenix_blink_biicode_link| raw:: html

   <a href="https://www.biicode.com/fenix/fenix/blink/master" target="_blank">it is already in biicode!</a>

.. _installing_biicode_arduino:

Installing biicode and Arduino tools
------------------------------------

First |downloads_link| and :ref:`install biicode<arduino_installation>`.

.. |downloads_link| raw:: html

   <a href="https://www.biicode.com/downloads" target="_blank">download</a>

Then, open the console and type:

.. code-block:: bash

   ~$ bii setup:arduino

This will help you to install a group of external tools (Arduino SDK, CMake and MinGW or GCC).

.. container:: infonote

    If any problem installing the Arduino tools, check :ref:`how to install Arduino tools manually <arduino_installation>`.

.. _create_your_project:

Create your project
-------------------

First, create a project:

.. code-block:: bash

  ~$ bii init myproject

Then we can use the convenience ``new`` command to create some folders and a "Simple Blink" Arduino main file. Of course, you can do it manually too.

.. code-block:: bash

  ~$ cd myproject
  ~/myproject$ bii new myuser/myblock --hello=arduino

.. container:: infonote

    You can directly type ``myuser``, there's no need to register an account to use biicode, only
    to upload and share contents. You can use other name too. 
    If you have already registered you might want to replace ``myuser``
    with your real biicode username.

This should be the resulting layout:

.. code-block:: text

  +-- myproject
  |    +-- bii
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- myblock
  |    |    |    |    +-- main.cpp
  |    +-- deps

Define your board
-----------------

Just, define your Arduino board using the ``arduino:settings`` command. In this example we use an Arduino Uno, but you can use another like *Mega2560*.

.. code-block:: bash

   ~/myproject$ bii arduino:settings
   Enter SDK path (/../biicode_env/arduino-1.0.6): [ENTER]
   Enter board (/o list supported options):uno
   Using arduino port: COM4

Build and upload your program
-----------------------------
Let's specify the toolchain to use, build and check that everything is fine by building and uploading the blink application to your Arduino.

.. code-block:: bash

   ~/myproject$ bii configure -t arduino
   ~/myproject$ bii build
   ...
   [100%] Built target myuser_myblock_main
   
   ~/myproject$ bii arduino:upload
   ...
   Writing | ################################################## | 100% 0.00s
   
   avrdude.exe: 0 bytes of eeprom written
   
   avrdude.exe: safemode: Fuses OK
   
   avrdude.exe done.  Thank you.
   
   [100%] Built target myuser_myblock_main-upload
   Upload finished

.. _depending_on_fenix_blink:

Depending on Fenix Blink
------------------------

Now we're going to implement a non blocking blink in arduino. Copy the following code containing the new blink into the *main.cpp* file:

**main.cpp**

.. code-block:: cpp
  :emphasize-lines: 1, 2

  #include "Arduino.h"
  #include "fenix/blink/blink.h"
  Blink my_blink;
  void setup() {
    //pin = 13, interval = 1000 ms
    my_blink.setup(13, 1000);
  }
  void loop() {
    my_blink.loop();
  }

This code requires the *fenix's* **blink.h** *file* (You can see it in the ``include`` section). 

If you try to ``build`` you will get a **build error**, that's because your project doesn't have the *fenix/blink/blink.h* dependency.

Execute the following command to **find unresolved dependencies** and **retrieve necessary files** from servers:

.. code-block:: bash

   ~/myproject$ bii find

Build and upload
----------------

Now can now build your firmware and upload it to your Arduino:

.. code-block:: bash

  ~/arduino_hello_project$ bii build
  ...
  [100%] Built target myuser_myblock_main

  ~/arduino_hello_project$ bii arduino:upload
	...
  Writing | ################################################## | 100% 0.00s

  avrdude.exe: 0 bytes of eeprom written

  avrdude.exe: safemode: Fuses OK

  avrdude.exe done.  Thank you.

  [100%] Built target myuser_myblock_main-upload
  Upload finished

**That’s it!** If you see that output it means that fenix's blink.h was downloaded and uploaded in your project.

Now your Arduino board should be blinking! You have just reused a `non blocking blink <https://www.biicode.com/fenix/blink>`_!

You can also check the deps folder, the *blink.h* code is there.

Didn't work? No problem, read or contact us in |biicode_forum_link|. Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">Write us!</a>
