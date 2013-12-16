Arduino
=======

Arduino is an open-source electronics prototyping platform based on flexible, easy-to-use hardware and software. It's intended for artists, designers, hobbyists and anyone interested in creating interactive objects or environments.

Arduino info
------------

Arduino IDE
^^^^^^^^^^^

** `Download the Arduino software <http://arduino.cc/en/Main/Software>`_

Getting Started with Arduino
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

** `Getting Started with Arduino <http://arduino.cc/en/Guide/HomePage>`_

Getting Started with Arduino Yún and Arduino Due boards
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* `Getting started with the Arduino Due <http://arduino.cc/en/Guide/ArduinoDue>`_
* `Guide to the Arduino Yún <http://arduino.cc/en/Guide/ArduinoYun>`_

Getting Started with Intel Galileo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* `Arduino IDE for Intel Galileo <https://communities.intel.com/community/makers/software/drivers>`_
* `Getting started with the Arduino Due <http://arduino.cc/en/ArduinoCertified/IntelGalileo>`_

How to configure your biicode workspace
---------------------------------------

changes, if needed, the notebook sketchbook on the **enviroment.bii**: ::

	arduino:
	  sketchbooks:
	  - {sketchbook: 'C:\Users\[USER_NAME]\Documents\Arduino'}

Create a new hive and code!
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Creating a new hive with the ``bii new`` command.

Create all the files you need to start with the ``arduino:wizard`` command.

With this command you create the next tree: ::

|-- my_hive
|    +-- bii
|    +-- bin
|    +-- build
|    +-- dep
|    +-- blocks
|         +-- my_user_name
|         |     +-- my_block
|         |     |       |-- my_block.ino
|         |     |       |-- dependencies.h
|         |   	|       +-- bii
|         |     |       	|-- dependencies.bii


These files have the following content:

**my_block.ino**

This file 

.. code-block:: cpp
	:linenos:

	void setup() {

	}

	void loop() {

	}

**dependencies.h**

.. code-block:: cpp
	:linenos:

	#my_block.ino external dependencies
	
**dependencies.bii**

.. code-block:: text
	:linenos:

	my_block.ino + dependencies.h
	
Create a Arduino library
^^^^^^^^^^^^^^^^^^^^^^^^

Create all the files you need to start with the ``arduino:wizard --lib`` command. If you are in a block folderIf you are inside a hive, but not in a block folder:

.. code-block:: bash

	$ biidev arduino:wizard --lib

	Class name: lib

	Creating a new class named "lib"

	These files have been created:
		lib.h
		lib.cpp
		
If you are inside a hive, but not in a block folder, a warning message will appear:

.. code-block:: bash

	WARN:
	You're not in a valid block.
	All files will be saved in your default directory [...]

.. toctree::
   :maxdepth: 2
