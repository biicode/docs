.. _arduino_getting_started:

Getting Started
===============

This example shows **how to install biicode and code a Arduino not blocking blink ith the blick library**. You don't need to have installed blick library, biicode will download and configure it automatically for you.

You will learn how to use the ``blink.h`` file of the ``blink`` block owner of ``fenix`` with the code line ``#include "fenix/blink/blink.h"`` .

1. Installing biicode and Arduino tools
---------------------------------------

To reuse code, you need to install biicode and a group of external tools (Arduino SDK, CMake and MinGW or GCC).

   - Download the biicode installer.

+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|Latest version 1.0                                                                                                                                                                                                                                                                                                           |
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+
|`MacOS <https://www.biicode.com/downloads>`_        |`Raspberry Pi <https://www.biicode.com/downloads>`_ |`Ubuntu 32 <https://www.biicode.com/downloads>`_    |`Ubuntu 64 <https://www.biicode.com/downloads>`_    |`Windows <https://www.biicode.com/downloads>`_      |`Devian Wheezy <https://www.biicode.com/downloads>`_|
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+


   - Execute ``bii setup:arduino`` in your console and all the Arduino tools will be installed automatically.

.. code-block:: bash

   ~$ bii setup:arduino

.. container:: infonote

    If you encounter any problem installing the Arduino tools, you can see :ref:`how to install Arduino tools manually <arduino_installation>`

2. Create your project
----------------------

To create a new project runn ``bii init <project_name>`` with the project name as a parameter.

.. code-block:: bash

   ~$ bii init arduino_hello_project

This command will create the following layout:

.. code-block:: text

   |-- arduino_hello_project
   |    +-- bii
   |    +-- blocks
   |    +-- deps

Now, we will create a block. a block is the place where you must place your code. Execute ``bii new anonymous/my_fist_block`` into the project folder to create a block.

.. code-block:: bash

   ~$ cd arduino_hello_project
   ~/arduino_hello_project$ bii new anonymous/my_first_block --hello=arduino

This command will create the following layout:

.. code-block:: text

   +-- arduino_hello_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- anonymous
   |    |    |    +-- my_first_block
   |    |    |    |    +-- main.cpp
   |    +-- deps

.. container:: infonote

    **What is the reason behind this layout?**

    This layout is enforced because biicode analyzes the dependencies of your blocks and downloads them into de deps folder. It is important because biicode configures and build your project following this layout.

    For this reason, all the code you want to be analyzed must be placed into a block inside the blocks folder.

    The structure of these blocks is composed by two parts, the owner (username) and the block name. In this example we use an anonymous user, but if you want to publish your own blocks in the future, you will need to register and user your username.

    If you want to change the user of a block into your blocks folder, just change the name of the owner folder where this block lies.

3. Resolve your dependencies
----------------------------

Now, edit your main.cpp file with the following code and execute ``bii find``. With this command, all your dependencies will be downloaded.

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

.. code-block:: bash

   ~/arduino_hello_project$ bii find

4. Build and upload
-------------------

You can now build your firmware and upload it to your Arduino with the command ``arduino:upload``.
If you just want to build it execute ``arduino:build``.

.. code-block:: bash

	~/arduino_hello_project$ bii arduino:upload
	...
	Writing | ################################################## | 100% 0.00s

And that's all. Your program is working!
