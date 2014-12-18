
.. _bii_new_command:

``bii new``: creates new blocks
---------------------------------

``bii new`` command **creates new biicode block inside your project**. Use it inside a biicode project folder like this:

.. code-block:: bash

	$ bii new USER_NAME/BLOCK_NAME


You can see :ref:`this basic 'hello world' example <cpp_getting_started>` to see how a typical block is created.


The ``bii new <user_name/block_name>`` command creates new folders within with your username and the name of the block in blocks folder.

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