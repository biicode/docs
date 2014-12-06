
.. _bii_new_command:

``bii new``: creates new blocks
---------------------------------

This is the command that **creates new block inside your project**. It must be invoked inside a biicode project folder, and **receives as the only parameter the name of the block to be created**. You can see :ref:`this basic 'hello world' example <cpp_getting_started>` to see how a typical block is created.

.. code-block:: bash

	$ bii new USER_NAME/BLOCK_NAME

The ``bii new <user_name/block_name>`` command creates a new folder within :ref:`your project<project_layout>` with the name of the block.

You can create a block with a default "Hello World" main file inside it:

.. code-block:: bash

	$ bii new USER_NAME/BLOCK_NAME --hello LANGUAGE

For example:

.. code-block:: bash

	$ bii new fenix/first_block --hello cpp

	...

	Successfully fenix/first_block folder created in your blocks directory!
	Successfully main.cpp file created in PROJECT_DIR/blocks/fenix/first_block


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_