.. _requirements_bii:

``requirements.bii``: configure the version of your dependencies
================================================================

``requirements.bii`` contains **your block's dependencies**, it's a file located into the ``bii`` block folder (see the :ref:`layouts section <project_layout>`).

Examples
---------

your block depends on a block in edition
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

And if you build your project, the block that depends on the other one, will have a bii folder with a ``requirements.bii`` file. Its content:

.. code-block:: text

	# This file contains your block external dependencies references
	user25/my_lib_block

What does it mean?

* *my_main_block* has a dependency to ``user25/my_lib_block``. 
* The *user25/my_lib_block* block is in ``edition`` (there's no version number, you're still modifying it)

your block depends on published blocks
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you have external dependencies and want depend to a C++ library already uploaded to biicode ::

|-- my_project
|    +-- bii
|    +-- bin
|    +-- blocks
|    |	  +-- user25
|    |    |     +-- my_main_block
|    |    |  	|     |-- main.c   --->  #include "google/gtest/gtest.h"

Execute :ref:`bii find command <bii_find_command>` as in this example: `Google GTest Library <https://www.biicode.com/google/gtest>`_, 

.. code-block:: bash

	$ bii find

your ``requirements.bii`` would be similar to this:

.. code-block:: text

	# This file contains your block external dependencies references
	google/gtest: 4

It tells us that:

* *my_main_block* has a dependency to ``google/gtest`` block.
* You depend on the google/gtest block, ``version number 4``.

.. _edit_requirements_bii:

Editing your requirements.bii
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can manually **specify which block version you want to depend on**, making your own ``requirements.bii`` or editing it.

For example, if you wish to reuse the ``pretty_algorithm.h`` file from a block named ``fenix/pretty_block`` whose last published version is ``7``. And  you execute :ref:`bii find command <bii_find_command>` to retrieve your dependencies, it takes the latest compatible version so your ``requirements.bii``

content will be :

.. code-block:: text

	fenix/pretty_block: 7

It means:

* You have a dependency to ``fenix/pretty_block`` block.
* You depend on the fenix/pretty_block block, version number ``7``.


If you prefer to reuse from version number ``6``, update your ``requirements.bii``.

Write into it :

.. code-block:: text

	fenix/pretty_block: 6

Then:

* You have a dependency to ``fenix/pretty_block`` block.
* You depend on fenix/pretty_block block, version number ``6``.
|
To edit your ``requirements.bii`` to find specific block versions, just execute the :ref:`bii work command <bii_work_command>`, instead of executing :ref:`bii find command <bii_find_command>` as usual. 

.. code-block:: bash

	$ bii work

And you'll see the new dependencies retrieved in your ``deps folder``.

.. container:: infonote

	* Editing your dependencies could lead you to incompatibles versions between blocks.

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_