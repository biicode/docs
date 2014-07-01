.. _requirements_bii:

requirements.bii
================

You can find the ``requirements.bii`` file inside the ``bii`` block folder ::

|-- my_project
|    +-- bii
|    +-- bin
|    +-- blocks
|    |	  +-- user25
|    |    |     +-- my_hello_block
|    |    |     |     +-- bii
|    |    |     |     |    |-- requirements.bii
|    |    |  	|     |-- hello.c
|    |    |     |     |-- hello.h

And it can be created on several ocassions and it shows your block dependencies 

#. Block depends on other edition blocks
------------------------------------------

Your project could have a layout like this: ::

|-- my_project
|    +-- bii
|    +-- bin
|    +-- blocks
|    |	  +-- user25
|    |    |     +-- my_lib_block
|    |    |  	|     |-- hello.c
|    |    |     |     |-- hello.h
|    |    |     +-- my_main_block
|    |    |  	|     |-- main.c   --->  #include "user25/my_lib_block/hello.h"

Then, if you build your project, the block, which has the dependency to the other one, will have a bii folder with a ``requirements.bii`` file. Its content:

.. code-block:: text

	# This file contains your block external dependencies references
	user25/my_lib_block

What say us?

Block, *my_main_block*, have a dependency to other one (in this case *user25/my_lib_block*) which is in edition.


#. Block depends on other published blocks
------------------------------------------




This file is created when you use the ``bii find`` inside the ``bii`` block folder and provides the info about the dependencies of the block. The requirements information contains the version of your depencie blocks: ``<block_name>(branch_name): <version>``.

This file can be modify manually with the concrete version you need.

An example of this file can be as follows. Imagine that you have a dependency to version 4 of ``file.h`` of the block ``user_a/block_a``, you just write in your requirements.bii::

	user_a/block_a: 4