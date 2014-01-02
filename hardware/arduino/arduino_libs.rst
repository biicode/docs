==============================
How to make an Arduino library
==============================

If you do not know how to write a library, you have a very `complete tutorial here <http://arduino.cc/en/Hacking/LibraryTutorial>`_.

Create an Arduino library with biicode
======================================

Create all the files you need to start with the ``arduino:wizard --lib`` command. With this command you create the next tree:

.. code-block:: text
	:emphasize-lines: 9, 10, 11, 12, 13, 14

	|-- my_hive
	|    +-- bii
	|    +-- bin
	|    +-- build
	|    +-- dep
	|    +-- blocks
	|         +-- my_user_name
	|         |     +-- my_block
	|         |     |	|-- library_name.h
	|         |     |	|-- library_name.cpp
	|         |     |	|-- keywords.txt
	|         |   	|	+-- Examples
	|         |     |		|-- my_block
	|         |     |			|-- my_block.ino


If you are in a block folder:

.. code-block:: bash

	$ biidev arduino:wizard --lib

	Class name: lib

	Creating a new class named "lib"

	These files have been created:
		lib.h
		lib.cpp		
		keywords.txt
		Example/my_block/my_block.ino
		
If you are inside a hive, but not in a block folder, a warning message will appear:

.. code-block:: bash

	You're not in a valid block.
	All files will be saved in your default directory [...]

How to convert your code in a library
=====================================

