.. _bii_core_commands:


Core commands
===============


.. _bii_init_command:

bii init
--------

This is the command that **creates new project**. It can **receives as a parameter the name of the project to be created** or **create the project in the current folder where you execute the commnad**. If you pass the name of the project, this command create a folder with the name passed as parameter and initialize the project inside.

.. code-block:: bash

	$ bii init <project_name>

.. code-block:: bash

	$ bii init

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

.. _bii_work_command:

bii work
--------

The ``bii work`` command is a very basic command that performs the main processing of biicode for your current project. It checks what files you have modified, analyzes and search dependencies among your project files (i.e. locally), and fills the ``deps`` folder. Most times it is not necessary to invoke this command explicitly, because it is automatically called by development commands as ``cpp:build`` or ``cpp:configure``.

.. code-block:: bash

	$ bii work


.. _bii_publish_command:

bii publish
-----------

The ``bii publish`` command is used to publish your code into biicode. it must be invoked inside a **project** folder and has no parameters, but **will launch an assistant that will guide you** through the publishing process:

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


.. _bii_open_command:

bii open
--------

This command allows you to edit a published block.
You can use this command to edit **one of your dependency blocks** or any block you have seen on the web and you want to edit.
When you invoke this command the block is placed into the ``blocks`` folder within your project, and their cells become editable source files that can be modified by you and eventually published in a new version of the same branch (if you have writting permissions for that branch) or in a new branch (using the :ref:`publish command<bii_publish_command>`).

There are different ways of retrieving a block created by you or other biicode user to perform some modifications:

That block is a dependency of your code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is the most general scenario. In this case, you are **using some cells from a previously published block** (originally created by you, or by another biicode user) . This means that yout have executed the :ref:`find command<bii_find_command>` inside your project, and some external dependencies have been retrieved from the biicode servers, and copied to the ``deps`` folder of your project. Let's imagine your user name is ``peter``, and your block ``peter/my_block`` has dependencies on some files written by the user ``martha``. In particular your code contains references to the block ``martha/her_block``.  After calling the ``bii find`` command, only those files your block needs are copied under the ``deps`` folder of the project you are working on. 

If you decide to make some modifications to the code you are using, you must call the ``bii open`` command, passing as a parameter the name of the block you intend to modify:

.. code-block:: bash

	$ bii open martha/her_block

Then, the biicode client copies martha's full block to your ``blocks`` project folder, and you can perform any modifications you need, and eventually publish the modifications on a new branch for that block.

You have an empty project
^^^^^^^^^^^^^^^^^^^^^^^^^

We can directly call the ``bii open <block_name>`` command and retrieve any published block from the Biicode servers. The code is then copied to the ``blocks`` folder of the **project** we are working on, and we can modify it as any other source block.

Your project is not empty
^^^^^^^^^^^^^^^^^^^^^^^^^

This case is very similar to the empty project one except it may alter your current dependencies. If you already have edition blocks in your project and you open another one that is not related to your other blocks, its dependencies will prevail over your existing dependencies. This means your dependencies can be upgraded or downgraded to match the ones in the block you are opening. If you want to enforce specic versions you can always do it editing your :ref:`policies file<policies>`.


.. _bii_close_command:

bii close
---------

You can use ``bii close <block_name>`` command to close a block under edition in ``blocks``, i.e., a block that you have done a ``bii open`` and have be editing it. If it's a dependency of any block yours, moves it to ``deps`` folder.

.. code-block:: bash

	$ bii close martha/her_block

.. _bii_merge_command:

bii merge
---------

This command allows you to **merge two different versions of the same block**. One of them must be available in a local project. The other must be a published branch of the same block. In any case, both versions must have a common ancestor, being different implementations of the same block. **This feature is still experimental**.

Imagine, for instance, your username is ``original`` and you are the original creator of a block named ``mathematyka``, and its last published version in the ``master`` branch is the number ``25``. That is, there is a ``original/mathematyka(original/master): 25`` version of your block published and available in the biicode servers. Now, let's assume another biicode user, with username ``improver``, :ref:`opens your block<bii_open_command>` in a new ``better_math`` branch, and makes some amazing improvements to your library. They are available in the ``original/mathematyka(improver/better_math): 5`` version, and they are so good that you decide to integrate those changes with your working branch of the library. You only need to use the ``bii merge`` command as follows, from the project containing the last working copy of your block:

.. code-block:: bash

	$ bii merge --block original/mathematyka --branch improver/better_math
	INFO: Merging with: original/mathematyka(improver/better_math): 5
	...


In this case you indicate in the ``--block`` parameter the local version of the block where you desire to integrate the remote changes, and ``--branch`` is the name of the branch containing the new code to be merged locally. If no ``--version`` number is given, the last published version of the remote branch is used. In case of any conflict during the process, the *diff*  information will be included in the corresponding conflictive files, and a warning message will be generated by the client.