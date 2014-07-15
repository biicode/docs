.. _bii_core_commands:


Core commands
===============


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