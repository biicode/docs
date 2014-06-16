.. _bii_core_commands:

.. _bii_setup_command:

bii setup
---------

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

bii new
-------

This is the command that **creates new block inside your project**. It must be invoked inside a biicode project folder, and **receives as the only parameter the name of the block to be created**. You can see :ref:`this basic 'hello world' example <cpp_getting_started>` to see how a typical block is created.

.. code-block:: bash

	$ bii new user/hello_block

The ``bii new <user_name/block_name>`` command creates a new folder within :ref:`your project<project_layout>` with the name of the block.

.. _biiwork:

bii work
--------

The ``bii work`` command is a very basic command that performs the main processing of biicode for your current project. It checks what files you have modified, analyzes and search dependencies among your project files (i.e. locally), and fills the ``deps`` folder. Most times it is not necessary to invoke this command explicitly, because it is automatically called by development commands as ``cpp:run``, ``cpp:build`` or ``cpp:configure``.

.. code-block:: bash

	$ bii work


.. _bii_publish_command:

bii publish
-----------

When your are happy with the state, functionality and performance of your code, you can **publish your blocks and share them** with other users thanks to ``bii publish`` command. This way they will be able to reuse your code, including references to your blocks cells in their source files, and making use of the ``bii find`` command, explained in this section.

The ``bii publish`` command must be invoked inside a **project** folder and has no parameters, but **will launch an assistant that will guide you** through the publishing process:

* In case your **project** contains multiple blocks under your ``blocks`` folder, it will ask you which of them (``user_name/block_name``) you wish to publish.
* You must define a **tag** for the published code. Available options are: 	

	* ``DEV``: The code you are publishing is ready to be reused by yourself (or maybe your dev team)
	* ``ALPHA``: The code is ready to be reused by some friends or colleagues you explicitly invite to test your code
	* ``BETA``: The code could be used by anyone in the world willing to test others code
	* ``STABLE``: Ready to be reused by anyone in the world.

 They define the state of the development for your code. This information is used in by the :ref:`policies<policies>` of the users that will use this blocks.
* Finally, you must provide a short message describing the code your are publishing, and the new functionalities it provides (bugs fixed, or any other valuable information).

After your block has been published and uploaded to the biicode servers, the program shows a message with information about the name of the block (``user_name/simple_name``), the name of the branch (``user_name/branch_name``), and the numeric ID of the version that has been published in that particular branch.

.. code-block:: bash

	$ bii publish
	*****************************
	***** Publishing public ****
	*****************************
	Introduce block (/o list options): [USER]/[BLOCK_NAME]
	Introduce tag (/o list options): STABLE
	Introduce msg : Optimized C library for graphs computation

	INFO: Successfully published [USER]/[BLOCK_NAME]([USER]/[BRANCH]): [VERSION]
	INFO: You can find your block at [URL_TO_YOUR_PUBLISHED_BLOCK]

Publishing new versions of your code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

What happens if you modify some code that you have just published? It is easy, you can publish
a new version of such code, and other projects that depend (because they did a ``find``) on it can
easily update so the new changes are obtained.


.. _bii_find_command:

bii find
--------

This commands allows you to retrieve any code dependencies from the biicode servers. The client analyzes your code, and find missing dependencies that cannot be resolved searching in your project contents. The client then communicates with the biicode server and tries to find code that is missing in your project, and retrieves the best matching version according with your :ref:`policies<policies>`.

.. code-block:: bash

	$ bii find

The retrieved files are copied on your file system, under the ``deps`` folder of your project, following a folder structure that reproduces the name of the retrieved blocks: ``<block_name> = <user_name>/<simple_name>`` (see the :ref:`basic concepts<basic_concepts>` and how a **block** is uniquely identified).

If you want to update already defined dependencies (as well as finding unresolved ones in the same step):

.. code-block:: bash

	$ bii find --update

Biicode uses user defined policies to resolve dependencies. The configuration file for configuring your policies for this is named "policies.bii" in your project "bii" folder. Note that all find commands depend on the values configured in such file. You can for example try to update your dependencies, but if there are no compatible versions that match your policies, you will not get such updates. E.g. a new ALPHA version for one of your dependencies will not be updated if you do not change your policy.

If you want to find compatible downgrades:

.. code-block:: bash

	$ bii find --downgrade

These options can be combined:

.. code-block:: bash

	$ bii find --update --downgrade

If you want to find any possible matching compatible version (not just updates or downgrades from your current one), type:

.. code-block:: bash

	$ bii find --modify

.. _biiclean:

bii clean
---------

The ``bii clean`` command cleans most of biicode internal project meta-information, keeping the strictly minimum required to reconstruct everything in a subsequent command. In theory, this command should not exist, but it is sometimes necessary, especially when new versions of biicode client are released that might have backwards incompatibilities.

.. code-block:: bash

	$ bii clean
