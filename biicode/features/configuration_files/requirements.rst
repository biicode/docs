.. _requirements_bii:

``requirements.bii``: configure the version of your blocks
=============================================================

You can find the ``requirements.bii`` file inside the ``bii`` block folder (see the :ref:`layouts section <project_layout>`) and **shows your block dependencies**.

Examples
---------

Block depends on other edition blocks
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you have a layout like this: ::

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

* *my_main_block* has a dependency to ``user25/my_lib_block``. 
* The *user25/my_lib_block* block is in ``edition`` (you're still modifying it)


Block depends on other published blocks
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You could have external dependencies too and reuse a C++ library uploaded to biicode ::

|-- my_project
|    +-- bii
|    +-- bin
|    +-- blocks
|    |	  +-- user25
|    |    |     +-- my_main_block
|    |    |  	|     |-- main.c   --->  #include "google/gtest/gtest.h"

As in this case, `Google GTest Library <https://www.biicode.com/google/blocks/google/gtest/branches/master#.U7QO3flv6QA>`_, then if you execute the :ref:`bii find command <bii_find_command>`:

.. code-block:: bash

	$ bii find

your requirements would be similar to this:

.. code-block:: text

	# This file contains your block external dependencies references
	google/gtest: 4

It tell us that:

* You have a dependency to ``google/gtest`` block.
* The branch of this block is ``master`` (default branch).
* You depend on the google/gtest block version number ``4``.

.. _edit_requirements_bii:

Editing your requirements.bii
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

biicode offers you the possibility to choose any branch and version block to depend on, making your own ``requirements.bii`` or editing it.

For example, you wish to reuse the ``pretty_algorithm.h`` file from a block named ``fenix/pretty_block`` whose last published version is ``7`` and has a ``develop`` branch too whose last version is ``4``. Then, if ``requirements.bii`` file doesn't exist yet, you could create it (including "bii" folder).

Its content could be:

.. code-block:: text

	fenix/pretty_block: 6

It means:

* You have a dependency to ``fenix/pretty_block`` block.
* The branch of this block is ``master`` (default branch).
* You depend on the fenix/pretty_block block version number ``6``.
|
Or something different:

.. code-block:: text

	fenix/pretty_block(develop): 3

Then:

* You have a dependency to ``fenix/pretty_block`` block.
* The branch of this block is ``develop`` (default branch).
* You depend on the fenix/pretty_block block version number ``3``.
|
This method, to download your dependencies, is different. In the other previous cases, you have to execute :ref:`bii find command <bii_find_command>`, but when you want to edit your ``requirements.bii`` to find these specific block versions you only have to execute the :ref:`bii work command <bii_work_command>`:

.. code-block:: bash

	$ bii work

And you'll see the new dependencies in your ``deps folder``.

.. container:: infonote

	* Editing your dependencies could lead you to incompatibles versions between blocks.
	* Visit the section: :ref:`how to publish branches <publish_branches>`
	* Visit the section: :ref:`how to merge branches <merge_branches>`