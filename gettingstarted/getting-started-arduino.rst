.. _arduino_getting_started:

Arduino
=======

This example shows **how to install biicode and code a Arduino not blocking blink ith the blick library**. You don't need to have installed blick library, biicode will download and configure it automatically for you.

You will learn how to use the ``blink.h`` file of the ``blink`` block owner of ``fenix`` with the code line ``#include "fenix/blink/blink.h"`` .

1. Installing biicode and Arduino tools
---------------------------------------

First, install biicode and a group of external tools (Arduino SDK, CMake and MinGW or GCC).

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

.. container:: infonote

    **why anonymous/my_first_block?**

    Because you distinguish a block by its owner's user-name and the block name. ``anonymous/my_first_block`` is what you write when you are not registered yet, but to publish your own blocks, you need to use your biicode user name.

    If you want to change the user-name of a block into your blocks folder, just change the folder name where the block is at.

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

    **What's the reason behind this layout?**

    With this layout, biicode analyzes your block's dependencies and downloads them into the deps folder. It is also used to configure and build your project.

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

.. container:: todo

    If you want to learn more about Arduino & biicode, check the :ref:`Arduino section <arduino-index>`.
