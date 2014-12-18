
.. _bii_new_command:

**bii new**: creates new blocks
---------------------------------

``bii new`` command **creates a new biicode block inside your project**. 
|
Use it inside a biicode project folder like this:

.. code-block:: bash

	$ bii new USER_NAME/BLOCK_NAME


Take a look at :ref:`the Getting Started guide<cpp_getting_started>` to know more.


``bii new user_name/block_name`` command creates new folders in your blocks folder:

.. code-block:: text

  +-- myproject
  |    +-- bii
  |    +-- blocks
  |    |    +-- user_name
  |    |    |    +-- block_name
  |    +-- deps


It's useful to create a block with a default "Hello World" main file into it:

.. code-block:: bash

	$ bii new USER_NAME/BLOCK_NAME --hello LANGUAGE

For example:

.. code-block:: bash

	$ bii new fenix/first_block --hello cpp

	...

	Successfully fenix/first_block folder created in your blocks directory!
	Successfully main.cpp file created in PROJECT_DIR/blocks/fenix/first_block

Resulting layout:

.. code-block:: text

  +-- myproject
  |    +-- bii
  |    +-- blocks
  |    |    +-- fenix
  |    |    |    +-- first_block
  |    |    |    |    +-- main.cpp
  |    +-- deps



**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_