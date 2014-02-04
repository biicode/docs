.. _config_raspberry_ws:

How to configure your biicode workspace
=======================================

If you haven't done so, you must first :ref:`install bicode <installation>` and :ref:`create a biicode workspace <create_workspace>`.

Let biicode download the cross compilers and configure your workspace
---------------------------------------------------------------------

First, Install git-core if it is not installed:

.. code-block:: bash

	$ sudo apt-get install git-core

For biicode download and configure everything for you, you just have to run the ``bii rpi:setup`` command:

.. code-block:: bash

	$ bii rpi:setup

	INFO: Cloning the ARM cross compiler into /usr/local/tools
	
	fatal: could not create work tree dir '/usr/local/tools'.: Permision denied
	INFO: Cloning the ARM cross compiler with sudo
	[sudo] password for [USER]:
	
If you already have downloaded the cross compilers the setup tool will indicate this with the following message:

.. code-block:: bash

	$ bii rpi:setup

	INFO: Cloning the ARM cross compiler into /usr/local/tools
	
	INFO: The tools are already Downloaded
	
If you want to download the cross compilers another folder or if you already have downloaded to another directory, you just have to indicate the directory  where you want it to clone or where it is

.. code-block:: bash

	$ bii rpi:setup [directory]

	...
	
Once you have done this, a cross compilers will have downloaded and added to :ref:`enviroment.bii <layouts>`.


Add the cross compilers to biicode by yourself
----------------------------------------------

If you have not used the ``bii rpi:setup`` command, add the cross compilers to :ref:`enviroment.bii <layouts>` like shown in the last four lines : 

.. code-block:: text
    :emphasize-lines: 8,9,10,11
    
    cpp:
        builders:
            - path: make
              tool: {family: MAKE}
        compilers:
            - path: null
              tool: {family: GNU}
            - path: /usr/local/tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc
              tool: {family: GNU, subfamily: C, arch: ARM}
            - path: /usr/local/tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-g++
              tool: {family: GNU, subfamily: CPP, arch: ARM}
    	
		
Create a new hive and code!
---------------------------

Creating a new hive with the ``bii new`` command. :ref:`(command info) <bii_new_command>`

Configure your settings
^^^^^^^^^^^^^^^^^^^^^^^

Update your :ref:`settings.bii <settings>` or :ref:`default_settings.bii <layouts>` with the info of your Raspberry Pi ::
	
	rpi: {directory: /home/pi, ip: 192.168.1.68, password: raspberry, user: pi}
	
* **directory**: Raspberry Pi directory where you want to save the files you send for SCP
* **ip**: Raspberry Pi IP address. You can find it under ``inet addr`` field executing ``ifconfig`` in a console inside the raspberry.
* **user**: Raspberry Pi user name
* **password**: Raspberry Pi password

Change the architecture of the cpp compiler on the ``settings.bii``. Where you see::

	cpp:
	  builder: {family: MAKE}
	  compiler: {amily: GNU}
	  configurer: {family: CMake}
	 
add ``arch: ARM``::
	 
	cpp:
	  builder: {family: MAKE}
	  compiler: {arch: ARM, family: GNU}
	  configurer: {family: CMake}

Code as usual
^^^^^^^^^^^^^
 
Copy the code that you want to compile into your :ref:`block folder <layouts>`. For example:

**hello.h**

.. code-block:: cpp
	:linenos:

	#include  <iostream>
	using namespace std;
	 
	void hello(){
	 cout<<"Hello World"<<endl;
	}

**main.cpp**

.. code-block:: cpp
	:linenos:

	#include "hello.h"
	 
	int main() {
	  hello();
	  return 1;
	}

Compile your code
^^^^^^^^^^^^^^^^^

Once you have completed all the coding process, you are ready to make the cross-compilation:

.. code-block:: bash

	$ bii cpp:build

Note that the ``bii cpp:build`` command needs to be executed from a folder containing a hive like any other biicode project. After some messages showing information about the compiling process, the binaries will created in your ``bin folder``.

Remember that when generating the binary by cross compilation, you can only run on the Raspberry Pi.

.. _bii_rpi_send:

Send your binaries
------------------

To send your binary to Raspberry Pi, you just execute the ``rpi:send`` command and the file will be sent by rsync to the address that appears in your **settings.bii**:

.. code-block:: bash

	$ bii rpi:send

	...
	
	Sending with rsync -Pravdtze ssh [HIVE_DIRECTORY]/bin/* [RPI_USER]@[RPI_IP]:[DIRECTORY]/[HIVE_NAME]

	[RPI_USER]@[RPI_IP]'s password:

Finally, the Raspberry Pi user's password will be asked. If you have not changed your password, for raspbian is **raspberry**.

If you want to send files to another Raspberry Pi or specify a different directory that appears in your **settings.bii**, you have the option of passing these parameters to the ``bii:send``. These parameters are not obligatory, can be passed only a new directory and use the other parameters of **settings.bii**.

.. code-block:: bash

	$ bii rpi:send [directory] [user] [ip]
	
	...
	
	$ bii rpi:send [directory]
	

You just have to go to your Raspberry Pi and execute the binaries as any computer.

.. _bii_rpi_ssh:

Connect with your Raspberry Pi
------------------------------

You can use the ``rpi:ssh`` command if you want a remotely access to your Raspberry Pi. With this command you **can run your binaries**.

.. code-block:: bash

	$ bii rpi:ssh

	...
	
	Connecting with ssh [RPI_USER]@[RPI_IP]

	[RPI_USER]@[RPI_IP]'s password:
	
	pi@raspberrypi ~ $ cd bin
	pi@raspberrypi ~/bin $ ls
	[binary_name]
	pi@raspberrypi ~/bin $ ./[binary_name]
	Hello world!
	
If you want to send files to another Raspberry Pi that appears in your **settings.bii**, you have the option of passing these parameters to the ``bii:ssh``.

.. code-block:: bash

	$ bii rpi:ssh [user] [ip]
	


