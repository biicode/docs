.. _bii_commands:

Commands
==========

This section summarizes the general **commands available in biicode**. You can:

* **manage** your project and blocks locally, on your computer,
* determine their internal and external **dependencies**,
* **retrieve** any missing code dependencies from the biicode servers,
* **publish** your code, and
* **reuse** from other user's code.


.. _bii_init_command:

``bii init``: creates a new project
------------------------------------

This is the command that **creates new project**. It can **receives as a parameter the name of the project to be created** or **create the project in the current folder where you execute the command**. If you pass the name of the project, this command create a folder with the name passed as parameter and initialize the project inside.

Create a folder named *project_name* to init your project inside:

.. code-block:: bash

	$ bii init <project_name>

Init a project in your current folder:

.. code-block:: bash

	$ bii init

.. _bii_setup_command:

``bii setup``: install necessary tools
---------------------------------------

This command helps you to set up all the necessary tools to start to use biicode.

Setup for installing cpp third party tools

.. code-block:: bash

	$ bii setup:cpp

Setup for installing cpp third party tools and Arduino SW

.. code-block:: bash

	$ bii setup:arduino

Setup cross compiler tools for Raspberry Pi (must be linux)

.. code-block:: bash

	$ bii setup:rpi



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


.. _bii_publish_command:

``bii publish``: publish your blocks
-------------------------------------

The ``bii publish`` command is used to publish your code into biicode. 

After your block has been published and uploaded to the biicode servers, the program shows a message with information about the name of the block (``user_name/simple_name``), the name of the branch (``user_name/branch_name``), and the numeric ID of the version that has been published in that particular branch.

.. code-block:: bash

	$ bii publish

.. container:: todo

	* It's explained in detail in the section: :ref:`how to publish blocks <publish_blocks>`


.. _bii_find_command:

``bii find``: find your external dependencies
-----------------------------------------------

This commands allows you to retrieve any code dependencies from the biicode servers. The client analyzes your code, and find missing dependencies that cannot be resolved searching in your project contents. The client then communicates with the biicode server and tries to find code that is missing in your project, and retrieves the best matching version according with your :ref:`policies<policies>`.

.. code-block:: bash

	$ bii find

The retrieved files are copied on your file system, under the ``deps`` folder of your project.

.. container:: todo

	* Visit the section: :ref:`how to update your dependencies <update_dependencies>`
	* Visit the section: :ref:`requirements.bii <requirements_bii>`
	* Visit the section: :ref:`your project layout<project_layout>`


.. _biiclean:

``bii clean``: delete meta-information
------------------------------------------

The ``bii clean`` command cleans most of biicode internal project meta-information, keeping the strictly minimum required to reconstruct everything in a subsequent command. In theory, this command should not exist, but it is sometimes necessary, especially when new versions of biicode client are released that might have backwards incompatibilities.

.. code-block:: bash

	$ bii clean


.. _bii_open_command:

``bii open``: edit published blocks
-------------------------------------

This command allows you to edit a published block.
You can use this command to edit **one of your dependency blocks** or any block you have seen on the web and you want to edit.
When you invoke this command the block is placed into the ``blocks`` folder within your project, and their cells become editable source files that can be modified by you and eventually published in a new version of the same branch (if you have writting permissions for that branch) or in a new branch (using the :ref:`publish command<bii_publish_command>`).

.. code-block:: bash

	$ bii open USER_NAME/BLOCK_NAME

To open someone's branch, you will place the branch's user and block in brackets after its creator's user name and block name, like this:

.. code-block:: bash

	$ bii open USER_NAME/BLOCK_NAME(BRANCH_USER_NAME/BRANCH_BLOCK_NAME)

.. container:: todo

	Visit the section: :ref:`how to edit something you depend on <edit_dependecies>`


.. _bii_close_command:

``bii close``: finish editing published blocks
-----------------------------------------------

You can use ``bii close <block_name>`` command to close a block under edition in ``blocks``, i.e., a block that you have done a ``bii open`` and have be editing it. If it's a dependency of any block yours, moves it to ``deps`` folder.

.. code-block:: bash

	$ bii close USER_NAME/BLOCK_NAME

.. _bii_merge_command:

``bii merge``: merge branches
-------------------------------

This command allows you to **merge two different versions of the same block**. One of them must be available in a local project. The other must be a published branch of the same block. In any case, both versions must have a common ancestor, being different implementations of the same block. **This feature is still experimental**.

.. code-block:: bash

	$ bii merge BLOCK_VERSION


.. container:: todo

	Visit the section: :ref:`how to merge branches <merge_branches>`


.. _bii_user_command:

``bii user``: shows or change your current biicode user
---------------------------------------------------------

If you use it without parameter, it will show the current user, that can be None (anonymous).

.. code-block:: bash

	$ bii user
	INFO: Current user: None (anonymous)


If you pass a parameter, that will be the new biicode user. Such user should be already registered in `our website <https://www.biicode.com/>`_

.. code-block:: bash

	$ bii user phil
	INFO: Change user from None to phil


.. _bii_deps_command:

``bii deps``: show block dependencies
--------------------------------------

This command allows you to check the dependencies of any project. It's basic form, with no parameters, provides two pieces of information, giving you a general idea of which are your code dependencies. You can use several arguments and filters.

bii deps
^^^^^^^^^^

It shows the files that your blocks depend on (with block versions where they are located), and, system and unresolved dependencies respectively.

.. code-block:: bash

	$ bii deps
	phil/math depends on:
	    phil/math_lib: 4
	        algorithm.h
	        lib.h
	    system:
	        iostream
	    unresolved:
	        fake_lib.h
	phil/hello_world depends on:
	    system:
	        stdio

If you'd wish to see only one block, simply choose it:

.. code-block:: bash
	
	$ bii deps phil/hello_world
	phil/hello_world depends on:
	    system:
	       stdio



bii deps --detail
^^^^^^^^^^^^^^^^^^^^^^^^

It's so similar to *bii deps* but it shows the origin files where the dependencies are used.

.. code-block:: bash

	$ bii deps --detail
	phil/math_example depends on:
	    phil/math_lib: 4
	        algorithm.h
	            phil/math/main.cpp
	        lib.h
	            phil/math/main.cpp
	        system:
	            iostream
	                phil/math/main.cpp
	        unresolved:
	            fake_lib.h
	                phil/math/main.cpp
	phil/hello_world depends on:
	    system:
	        stdio
	            phil/hello_world/hello.cpp


bii deps --detail [FILTER]
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can enter a filter, i.e., you could see only a file or a dependency with its origins

.. code-block:: bash

	$ bii deps --detail fake_lib.h
	phil/math_example depends on:
	    phil/math_lib: 4
	    system:
	    unresolved:
	        fake_lib.h
	            phil/math/main.cpp
	phil/hello_world depends on:
	    system:

		 
bii deps --files
^^^^^^^^^^^^^^^^^^

It's used to know all the block files (and their types) and their dependencies.

.. code-block:: bash

	$ bii deps --files
	phil/math_example
	    CMakeLists.txt [TEXT]
	    bii/requirements.bii [TEXT]
	    phil/math/main.cpp [CPP][M]
	        phil/math_lib/algorithm.h (E)
	        phil/math_lib/adafruit_sensor.h (E)
	        iostream (S)
	        fake_lib.h (U)
	phil/hello_world
	    CMakeLists.txt [TEXT]
	    phil/hello_world/hello.cpp [CPP][M]
	        stdio (S)

.. container:: infonote
	
	Type of dependency tags:
		* E: explicit file
		* I: implicit file
		* D: data file
		* S: system file
		* U: unresolved file


.. _bii_status_command:

``bii status``: show block changes
-----------------------------------

``bii status`` command indicates you if there are changes in your code.

For example, if you have not changes:

.. code-block:: bash

	$ bii status
	INFO: Everything up to date

If you have changes in a ``main.cpp`` file:

.. code-block:: bash

	$ bii status
	[USER]/[BLOCK_NAME]

	  Modified:
	    [USER]/[BLOCK_NAME]/main.cpp


.. _bii_diff_command:

``bii diff``: compare between block versions
---------------------------------------------

Compare files and show differences with ``bii diff`` command. You can compare your current project with previous published versions or compare between published versions.

.. code-block:: bash

	$ bii diff BLOCK_VERSION_1 BLOCK_VERSION_2

.. container:: todo

	Visit the section: :ref:`how to compare two blocks <compare_blocks>`