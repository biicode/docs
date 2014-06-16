.. _bii_core_commands:

Core commands
================

This section summarizes the general **commands available to be used with the biicode client program**. The biicode client is the main utility that allows you to:

* **manage** your hives and blocks locally, on your computer,
* determine their internal and external **dependencies**,
* **retrieve** any missing code dependencies from the biicode servers,
* **publish** your code, and
* **reuse** other users' code.

All these functionalities are achieved using appropriate commands that are explained and used in many examples along this documentation, and are compiled here in a list for your convenience and reference.


.. contents:: List of commands
   :local:
   :depth: 1



.. _bii_setup_command:

``bii setup``: Set Up tool
-----------------------------

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

``bii new``: Creating new hives
-------------------------------------------

This is the command that **creates new hives inside your workspace**. It must be invoked inside a biicode workspace folder, and **receives as the only parameter the name of the hive to be created**. You can see :ref:`this basic 'hello world' example <hello_world>` to see how a typical hive is created.

.. code-block:: bash

	$ bii new hello_hive

The ``bii new <hive_name>`` command creates a new folder within :ref:`your workspace<workspace_layout>` with the name of the hive. It also creates :ref:`the full folders structure where your blocks and cells will be located<hive_layout>`. After invoking the command, **some questions are asked to the user**:

* The **programming language** of your code. Available options are: ``node``, ``fortran``, ``python``, ``cpp``, ``arduino`` or ``None``.

* The name of the **first block** in your hive. From a functional point of view, :ref:`your source files are grouped in blocks<block_definition>`. Any hive can hold as many blocks as you want but **every hive must contain at least one block of code** under the ``blocks`` folder.

* The option to create a default **'hello world'** file for your language. The sample code is placed inside the first block whose name is defined in the previous step.

Then some specific questions, depending on the chosen programming language, could be:

* The name of the **IDE** you will be using when writing your code. This way, the command will be able to automatically create the project configuration for your favourite IDE. Available options are (depending on language): ``Visual``, ``CodeBlocks``, ``Eclipse``, ``NetBeans``, or ``None`` (in case you don't need this configuration).
* The **build type** for your code. Available options are: ``None``, ``Debug``, ``Release``, ``RelWithDebInfo``, or ``MinSizeRel``.


.. _biiwork:

``bii work``: Processing the code
---------------------------------

The ``bii work`` command is a very basic command that performs the main processing of biicode for your current hive. It checks what files you have modified, analyzes and search dependencies among your hive files (i.e. locally), and fills the ``deps`` folder. Most times it is not necessary to invoke this command explicitly, because it is automatically called by development commands as ``cpp:run``, ``cpp:build`` or ``cpp:configure``.

.. code-block:: bash

	$ bii work


.. _bii_publish_command:

``bii publish``: Sharing your code
----------------------------------

When your are happy with the state, functionality and performance of your code, you can **publish your blocks and share them** with other users thanks to ``bii publish`` command. This way they will be able to reuse your code, including references to your blocks cells in their source files, and making use of the ``bii find`` command, explained in this section.

The ``bii publish`` command must be invoked inside a **hive** folder and has no parameters, but **will launch an assistant that will guide you** through the publishing process:

* In case your **hive** contains multiple blocks under your ``blocks`` folder, it will ask you which of them (``user_name/block_name``) you wish to publish.
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
a new version of such code, and other hives that depend (because they did a ``find``) on it can
easily update so the new changes are obtained.


.. _bii_find_command:

``bii find``: Finding dependencies
----------------------------------

This commands allows you to retrieve any code dependencies from the biicode servers. The client analyzes your code, and find missing dependencies that cannot be resolved searching in your hive contents. The client then communicates with the biicode server and tries to find code that is missing in your workspace, and retrieves the best matching version according with your :ref:`policies<policies>`.

.. code-block:: bash

	$ bii find

The retrieved files are copied on your file system, under the ``deps`` folder of your hive, following a folder structure that reproduces the name of the retrieved blocks: ``<block_name> = <user_name>/<simple_name>`` (see the :ref:`basic concepts<basic_concepts>` and how a **block** is uniquely identified).

If you want to update already defined dependencies (as well as finding unresolved ones in the same step):

.. code-block:: bash

	$ bii find --update

Biicode uses user defined policies to resolve dependencies. The configuration file for configuring your policies for this is named "policies.bii" in your hive "bii" folder. Note that all find commands depend on the values configured in such file. You can for example try to update your dependencies, but if there are no compatible versions that match your policies, you will not get such updates. E.g. a new ALPHA version for one of your dependencies will not be updated if you do not change your policy.

If you want to find compatible downgrades:

.. code-block:: bash

	$ bii find --downgrade

These options can be combined:

.. code-block:: bash

	$ bii find --update --downgrade

If you want to find any possible matching compatible version (not just updates or downgrades from your current one), type:

.. code-block:: bash

	$ bii find --modify


.. _biiupload:

``bii upload``: Uploading your hive
------------------------------------

The ``bii upload`` command allows you to upload any hive with all its contained blocks to the biicode servers. **This is not the same as publishing a block** with the ``bii publish`` command:

* Any uploaded hive **is private**; only you can see them on your biicode profile web page, and no other biicode user has access to them.
* There aren no *tags* or *publish messages* involved.
* You cannot reuse any blocks which are in this hive from other hives; **you must publish them first** using the :ref:`bii publish command<bii_publish_command>`. This means that your unpublished blocks do not exist outside of the hive where they lay.

.. code-block:: bash

	$ bii upload

.. _biidownload:

``bii download``: Downloading your hive
----------------------------------------

You can download any hive you have previously uploaded. You only need the **name of the uploaded hive** and the help of the ``bii download`` command, that must be executed inside a biicode workspace:

.. code-block:: bash
	
	$ cd my_workspace
	$ bii download --hive <your_hive_name>

**Note:** Remember **any downloaded hive is just a copy of the original one**. If you make changes to your hive and upload them later, it will overwrite the oldest files in biicode servers.


.. _biiclean:

``bii clean``: Cleaning meta-information
-----------------------------------------

The ``bii clean`` command cleans most of biicode internal hive meta-information, keeping the strictly minimum required to reconstruct everything in a subsequent command. In theory, this command should not exist, but it is sometimes necessary, especially when new versions of biicode client are released that might have backwards incompatibilities.

.. code-block:: bash

	$ bii clean



.. _bii_merge_command:

``bii merge``: Mixing the code
------------------------------

This command allows you to **merge two different versions of the same block**. One of them must be available in a local hive. The other must be a published branch of the same block. In any case, both versions must have a common ancestor, being different implementations of the same block. **This feature is still experimental**.

Imagine, for instance, your username is ``original`` and you are the original creator of a block named ``mathematyka``, and its last published version in the ``master`` branch is the number ``25``. That is, there is a ``original/mathematyka(original/master): 25`` version of your block published and available in the biicode servers. Now, let's assume another biicode user, with username ``improver``, :ref:`opens your block<bii_open_command>` in a new ``better_math`` branch, and makes some amazing improvements to your library. They are available in the ``original/mathematyka(improver/better_math): 5`` version, and they are so good that you decide to integrate those changes with your working branch of the library. You only need to use the ``bii merge`` command as follows, from the hive containing the last working copy of your block:

.. code-block:: bash

	$ bii merge --block original/mathematyka --branch improver/better_math
	INFO: Merging with: original/mathematyka(improver/better_math): 5
	...


In this case you indicate in the ``--block`` parameter the local version of the block where you desire to integrate the remote changes, and ``--branch`` is the name of the branch containing the new code to be merged locally. If no ``--version`` number is given, the last published version of the remote branch is used. In case of any conflict during the process, the *diff*  information will be included in the corresponding conflictive files, and a warning message will be generated by the client.

