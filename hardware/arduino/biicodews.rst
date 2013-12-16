How to configure your biicode workspace
=======================================

If you haven't done so, you must first  :ref:`create a biicode workspace <create_workspace>`.

changes, if needed, the sketchbook on the **enviroment.bii**: ::

	arduino:
	  sketchbooks:
	  - {sketchbook: 'C:\Users\[USER_NAME]\Documents\Arduino'}

Create a new hive and code!
---------------------------

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
------------------------

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