.. _rpi_getting_started:



Getting started
===============

This example shows **how to install biicode, code a C++ led blink with |wiringpi_link|, make the cross compilation and send the executable to your Raspberry Pi**. You don't need to have WiringPi installed in your computer or the rpi. Biicode will download and configure it automatically for you, |wiringpi_biicode_link|.


.. |wiringpi_link| raw:: html

   <a href="http://wiringpi.com/" target="_blank">WiringPi</a>

.. |wiringpi_biicode_link| raw:: html

   <a href="https://www.biicode.com/drogon/drogon/wiringpi/master" target="_blank">it is already in biicode!</a>


1. Installing biicode and C/C++ cross-building tools
----------------------------------------------------

.. container:: infonote

    **Debian linux distribution required**

    You need to use a native debian linux or in a virtual machine to use the cross compilation tools.

First |downloads_link| and install biicode

.. |downloads_link| raw:: html

   <b><a href="https://www.biicode.com/downloads" target="_blank">download</a></b>


Then, open the console and type

.. code-block:: bash

   ~$ bii setup:rpi

.. container:: infonote

    If any problem installing the C/C++ cross-building tools, you can see :ref:`how to install RPi cross-compiling tools manually <rpi_installation>`


2. Create your project
----------------------

First, create a project:

.. code-block:: bash

  ~$ bii init myproject

Then we can use the convenience ``new`` command to create some folders and a "Hello World" C++ main file. Of course, you can do it manually too.

.. code-block:: bash

  ~$ cd myproject
  ~/myproject$ bii new myuser/myblock --hello=cpp

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


3. Build and run your program (cross-compiling)
-----------------------------------------------

Configure your project to the cross compiling running ``bii rpi:settings``:

.. code-block:: bash

   ~$ cd myproject
   ~/myproject$ bii rpi:settings
   Define RPI settings for external C/C++ cross-building
   If you are working on board the RPI, you don't need these settings:
   RPI username (pi): [ENTER]
   RPI IP Address: 192.168.1.44
   RPI directory to upload (bin): [ENTER] #This folder must exist into your Raspberry Pi.
   Creating toolchain for Raspberry PI
   Run "$bii cpp:configure --toolchain=rpi" to activate it
   Run "$bii cpp:configure --toolchain=None" to disable it

Activate the toolchain for Raspberry PI with ``bii cpp:configure --toolchain=rpi``:

.. code-block:: bash

   bii cpp:configure --toolchain=rpi

Lets check that everything is fine by building and trying to run the hello world aplication. It could fail the execution because it is compiled to Raspberry PI. 

.. code-block:: bash

  ~/myproject$ bii cpp:build
  ...
  ~/myproject$ ./bin/user_myblock_main
  ./bin/user_myblock_main: cannot execute binary file

4. Send your executable to your Raspberry Pi
--------------------------------------------

To **send the binary to your Raspberry Pi**, you just need to execute the ``bii rpi:send`` command and the file will be sent using `rsync <http://en.wikipedia.org/wiki/Rsync>`_ to the address provided in your settings.

.. code-block:: bash

  $ bii rpi:send
  Sending with rsync -Pravdtze ssh [PROJECT_DIRECTORY]/bin/* [RPI_USER]@[RPI_IP]:[DIRECTORY]/[PROJECT_NAME]

  [RPI_USER]@[RPI_IP]'s password:

The Raspberry Pi user's password will be asked. If you have not changed your password, for Raspbian the default one is **raspberry**.

Finally, to **execute your program on your Raspberry Pi**, you need to establish a connection. You can use the ``rpi:ssh`` command if you want remote access. You'll find your program deployed in the path configured in your settings:

.. code-block:: bash

  $ bii rpi:ssh
  ...
  Connecting with ssh <rpi_user>@<rpi_ip>
  <rpi_user>@<rpi_ip>'s password:

  pi@raspberrypi ~ $ cd hello_rpi
  pi@raspberrypi ~/hello_rpi $ ls
  myuser_myblock_main
  pi@raspberrypi ~/hello_rpi $ ./user_myblock_main
  Hello world!

5. Depending on WiringPi
------------------------

Copy the following code containing a simple sum function and a test into the **main.cpp** file

.. code-block:: cpp
   :emphasize-lines: 1

   #include "drogon/wiringpi/wiringpi/wiringpi.h"
   #define LED 0
   int main (void){
       wiringPiSetup () ;
       pinMode (LED, OUTPUT) ;
       digitalWrite (LED, HIGH) ; // On
   }


Execute the following command to find unresolved dependencies and retrieve necessary files from servers:

.. code-block:: bash

   ~/myproject$ bii find

Now you are ready to compile and deploy your new application. First, **cross-compile your program** and make sure the binary is generated running ``bii cpp:build`` from your project location:

.. code-block:: bash

	$ bii cpp:build
	...
	Configuring cross compiler for ARM architecture:
	...
	[100%] Built target myuser_myblock_main

The binaries are created in ``bin`` folder, but remember that **you cannot run this program locally, as it has been compiled for a different architecture** using the cross-compiling tools. You need to send the binary to your Raspberry Pi before executing it.

Didn't work? No problem, read or contact us in |biicode_forum_link|

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>



Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">Write us!</a>


.. container:: todo

    Visit the section: :ref:`Upload and reuse code (C/C++) <upload-your-code>`