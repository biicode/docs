Cross Compilation Getting Started
=================================

This example shows **how to install biicode, code a C++ led blink with WiringPi, make the cross compillation and send the executable to your Raspberry Pi**. You don't need to have installed WiringPi, biicode will download and configure it automatically for you.

You will learn how to use the ``wiringpi.h`` file of the ``wiringpi/wiringpi`` block owner of ``drogon`` with the code line ``#include "drogon/wiringpi/wiringpi/wiringpi.h"``.

1. Installing biicode and C/C++ cross compilation tools
-------------------------------------------------------

.. container:: infonote

    **Debian linux distribution required**

    You need to use a native debian linux or in a virtual machine because the cross compillation tools need it.

For reuse code, you need to install biicode and a group of external tools.

   - Download the biicode installer.

+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|Latest version 1.0                                                                                                                                                                                                                                                                                                           |
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+
|`MacOS <https://www.biicode.com/downloads>`_        |`Raspberry Pi <https://www.biicode.com/downloads>`_ |`Ubuntu 32 <https://www.biicode.com/downloads>`_    |`Ubuntu 64 <https://www.biicode.com/downloads>`_    |`Windows <https://www.biicode.com/downloads>`_      |`Devian Wheezy <https://www.biicode.com/downloads>`_|
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+


   - Execute ``bii setup:rpi`` in your console and all the C/C++ cross compilation tools will be installed automatically.

.. code-block:: bash

   ~$ bii setup:rpi

.. container:: infonote

    If you have any problem installing the C/C++ cross compilation tools, you can see :ref:`how to install C/C++ cross compilation tools manually <cpp_installation>`

2. Create your project
----------------------

To create a new project running ``bii init`` with the project name as a parameter.

.. code-block:: bash

   ~$ bii init rpi_hello_project
   
This command will create the following layout:

.. code-block:: text

   |-- rpi_hello_project
   |    +-- bii
   |    +-- blocks
   |    +-- deps

Now, we will create a block. a block is the place where you must place your code. Execute ``bii new anonymous/my_fist_block`` into the project folder to create a block.

.. code-block:: bash

   ~$ cd rpi_hello_project
   ~/rpi_hello_project$ bii new anonymous/my_first_block --hello=cpp

This command will create the following layout:

.. code-block:: text

   +-- rpi_hello_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- anonymous
   |    |    |    +-- my_first_block
   |    |    |    |    +-- main.cpp
   |    +-- deps

.. container:: infonote

    **why this layout?**

    This layout is because biicode analyse the dependencies of yours blocks and download it into de deps folder. It is important because biicode configure and build your project following this layout.

    For this reason, all the code you want to be analyzed must place into a block inside the blocks folder.

    The structure of this blocks is composed by two parts, the user owner and the block name. In this example we use the anonymous user, but if you want to publish your own blocks in the future, you need to create a biicode user and use that user name.


    If you want to change the user of a block into your blocks folder, just change the name folder where are this block.

3. Resolve your dependencies and send your executable to your Raspberry Pi
--------------------------------------------------------------------------

Now, edit your main.cpp file with the following code and execute ``bii find``. With this command, all your dependencies will be downloaded.

**main.cpp**

.. code-block:: cpp
   :emphasize-lines: 1

   #include "drogon/wiringpi/wiringpi/wiringpi.h"
   #define LED 0
   int main (void){
       wiringPiSetup () ;
       pinMode (LED, OUTPUT) ;
       digitalWrite (LED, HIGH) ; // On
   }

.. code-block:: bash

   ~/rpi_hello_project$ bii find

Now you are ready to compile and deploy your new application. First, **cross-compile your program** and make sure the binary is generated running ``bii cpp:build`` from your hive location:

.. code-block:: bash

	$ bii cpp:build
	...
	Configuring cross compiler for ARM architecture:
	...
	[100%] Built target username_hello_rpi_main

The binaries are created in your hive's ``bin`` folder, but remember that **you cannot run this program locally, as it has been generated for a different architecture** using the cross-compiling tools. You need to send the binary to your Raspberry Pi to be executed.

To **send the binary to your Raspberry Pi**, you only need to execute the ``bii rpi:send`` command and the file will be sent by `rsync <http://en.wikipedia.org/wiki/Rsync>`_ to the address provided in your settings.

.. code-block:: bash

	$ bii rpi:send
	Sending with rsync -Pravdtze ssh [HIVE_DIRECTORY]/bin/* [RPI_USER]@[RPI_IP]:[DIRECTORY]/[HIVE_NAME]

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
	username_hello_rpi_main
	pi@raspberrypi ~/hello_rpi $ ./username_hello_rpi_main
	Hello world!
	
And that's all. Your program is working!