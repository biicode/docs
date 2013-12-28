==============================
How to make an Arduino library
==============================

Library layout
==============

Library files
-------------

Example files
-------------

The keywords file
-----------------

Create an Arduino library with biicode
======================================

Create all the files you need to start with the ``arduino:wizard --lib`` command. With this command you create the next tree: ::

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

	WARN:
	You're not in a valid block.
	All files will be saved in your default directory [...]

How to convert your code in a library
=====================================

