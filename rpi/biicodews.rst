.. _config_raspberry_ws:

How to configure your biicode workspace
=======================================

If you haven't done so, you must first  :ref:`create a biicode workspace <create_workspace>`.

Add the cross compilers to biicode
----------------------------------

Add the cross compilers to **enviroment.bii** like shown in the last four lines: ::

        cpp:
          builders:
            - path: make
              tool: {family: MAKE}
          compilers:
            - path: null
              tool: {family: GNU}
            - path: /user/local/tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc
              tool: {family: GNU, subfamily: C, arch: ARM}
            - path: /user/local/raspberry_pi/tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-g++
              tool: {family: GNU, subfamily: CPP, arch: ARM}
	  
Create a new hive and code!
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Creating a new hive with the ``bii new`` command.

Copy the code that you want to compile into your ``block folder``. For example:

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

	$ bii rpi:build

Note that the ``bii rpi:build`` command needs to be executed from a folder containing a hive like any other biicode project. After some messages showing information about the compiling process, the binaries will created in your ``bin folder``.

Remember that when generating the binary by cross compilation, you can only run on the Raspberry Pi.

Send your binaries
------------------

To send your binary to Raspberry Pi, you just execute the ``rpi:send`` command and the file will be sent by scp to the address that appears in your **settings.bii**:

.. code-block:: bash

	$ bii rpi:send

	...
	
	Sending with scp -r [HIVE_DIRECTORY]/bin [RPI_USER]@[RPI_IP]:[DIRECTORY]/[HIVE_NAME]

	[RPI_USER]@[RPI_IP]'s password:

Finally, the Raspberry Pi user's password will be asked. If you have not changed your password, for raspbian is **raspberry**.

If you want to send files to another Raspberry Pi or specify a different directory that appears in your **settings.bii**, you have the option of passing these parameters to the ``bii:send``. These parameters are not obligatory, can be passed only a new directory and use the other parameters of **settings.bii**.

.. code-block:: bash

	$ bii rpi:send [directory] [user] [ip]
	
	...
	
	$ bii rpi:send [directory]
	
	
You just have to go to your Raspberry Pi and execute the binaries as any computer.
