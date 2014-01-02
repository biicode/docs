=======================================
How to configure your biicode workspace
=======================================

If you haven't done so, you must first :ref:`create a biicode workspace <create_workspace>`.

changes, if needed, the sketchbook on the **enviroment.bii**: ::

	arduino:
	  sketchbooks:
	  - {sketchbook: 'C:\Users\[USER_NAME]\Documents\Arduino'}

Create a new hive and code!
===========================

Creating a new hive with the ``bii new`` command.

Create all the files you need to start with the ``arduino:wizard`` command. With this command you create the next tree:

.. code-block:: text
	:emphasize-lines: 9, 10, 11, 12

	|-- my_hive
	|    +-- bii
	|    +-- bin
	|    +-- build
	|    +-- dep
	|    +-- blocks
	|         +-- my_user_name
	|         |     +-- my_block
	|         |     |	|-- my_block.ino
	|         |     |	|-- dependencies.h
	|         |   	|	+-- bii
	|         |     |		|-- dependencies.bii


These files have the following content:

my_block.ino
------------

This is the main project file and must have the same name as the block containing it.

.. code-block:: cpp
	:linenos:

	void setup() {

	}

	void loop() {

	}

dependencies.h
--------------

To maintain compatibility with the Arduino IDE, this file contains dependencies to other blocks. Thanks to this, the routes that have our files are IDE as required, putting relative paths with several levels deep only in the dependencies.h

.. code-block:: cpp
	:linenos:

	#my_block.ino external dependencies
	
dependencies.bii
----------------

With this file we make the connection between my_block.ino and dependencies.h. You have all the :ref:`info about dependencies.bii here <dependencies_bii>`.

.. code-block:: text
	:linenos:

	my_block.ino + dependencies.h
	
Copy your dependencies like Arduino libraries 
=============================================


To **use your dependencies in the Arduino IDE** you need to pass them as libraries. To do this you just have to use the ``bii arduino:copy`` command.

.. code-block:: bash
	:linenos:
	
	$ bii arduino:copy
	
	The libraries have been copied into your sketchbook

A message like the following will be printed if the path that appears in your environment.bii not exist.
	
.. code-block:: bash
	:linenos:
	
	$ bii arduino:copy
	
	The specified path of the sketchbook does not exist in the environment.bii



