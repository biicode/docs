.. _bii_commands:

Global commands
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

.. _bii_init_command:

``bii init``: Workspace initialization
--------------------------------------

This is the first command you should invoke after installing the biicode client program, and allows the biicode :ref:`workspace initialization in a folder of your choice<create_workspace>`.

This command creates a special ``bii`` folder in the root of your workspace, that contains :ref:`default configuration files<config_files>` for the biicode client. These default files are used as templates when you create a new **hive**, and copied to the corresponding ``bii`` configuration folders for each hive.

.. _bii_new_command:

``bii new``: Creating new hives
-------------------------------------------

This is the command that **creates new hives inside your workspace**. It must be invoked inside a biicode workspace folder, and **receives as the only parameter the name of the hive to be created**. You can see :ref:`this basic 'hello world' example <hello_world>` to see how a typical hive is created.

The ``bii new <hive_name>`` command creates a new folder within :ref:`your workspace<workspace_layout>` with the name of the hive. It also creates :ref:`the full folders structure where your blocks and cells will be located<hive_layout>`. After invoking the command, some questions are asked to the user:

* The **programming language** of your code. This information is used to define the project configuration, making use of the default settings defined in your workspace configuration default files. Available options are: *java*, *node*, *fortran*, *python*, *cpp*, *arduino* or *None*.
* The name of the **first block** in your hive. A hive, as any other software project, is a logical structure that contains your source files. From a functional point of view, :ref:`your source files are grouped in blocks<block_definition>`. Any hive can hold as many blocks as you want, but at least on of them must be placed in the ``blocks`` folder of your hive, and contain the original code your are creating (or the modifications applied to other users blocks). In other works, **every hive must contain at least on block of code** under the ``blocks`` folder.

In case you choose **cpp** as your programming language, there are some additional options that are supported by the client program, and help you to configure your project and build settings:

* The option to create a default **'hello world'** block for your language. The sample code is placed inside the first block whose name is defined in the previous step.
* The name of the **IDE** you will be using when writing your code. This way, the command will be able to automatically create the project configuration for your favourite IDE. Available options are: *Visual*, *CodeBlocks*, *Eclipse*, *NetBeans*, or *None* (in case you don't need this configuration).
* Finally, the client asks for a **build type** for your code. Available options are: *None*, *Debug*, *Release*, *RelWithDebInfo*, or *MinSizeRel*.


.. _biiwork:

``bii work``: Processing the code
---------------------------------

The ``bii work`` command is a very basic command that performs the main processing of biicode for your current hive. It checks what files you have modified, analyzes and search dependencies among your hive files (i.e. locally), and fills the ``deps`` folder. Most times it is not necessary to invoke this command explicitly, because it is automatically called by development commands as ``cpp:run``, ``cpp:build`` or ``cpp:configure``.

.. code-block:: bash

	$ bii work


.. _bii_publish_command:

``bii publish``: Sharing your code
----------------------------------

When your are happy with the state, functionality and performance of your code, you can **publish your blocks and share them** with other users thanks to ``bii publish`` command. This way they will be able to reuse your code, including references to your blocks cells in their source files, and making use of the ``bii find`` command, explained in this section. The level of the reuse can be defined by the ``tag``, which can be one of:

	* ``DEV``: It means that the code you are publishing is ready to be reused by yourself (or maybe your dev team) in another projects or contexts.
	* ``ALPHA``: The code is ready to be reused by some friends or colleagues you explicitly invite to test your code
	* ``BETA``: The code could be used by anyone in the world willing to test others code
	* ``STABLE``: Ready to be reused by anyone in the world. This is typically the tag you want to use for your usual dependencies, and it is the default in the find policies.

The ``bii publish`` command must be invoked inside a **hive** folder and has no parameters, but **will launch an assistant that will guide you** through the publishing process:

* In case your **hive** contains multiple blocks under your ``blocks`` folder, it will ask you which of them you wish to publish. Remember that the name of a block is composed by the name of the original creator, and the simple name of the block joined by a *slash* (``/``) character: ``user_name/simple_name``.
* You must define a **tag** for the published code. Available options are: *DEV*, *ALPHA*, *BETA* or *STABLE*, and they define the state of the development for your code. This information is used in by the :ref:`policies<policies>` of the users that will use this blocks, allowing them to define which versions of your code are their preference.
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

This commands allows you to retrieve any code dependencies from the Biicode servers. The client analyzes your code, and find missing dependencies that cannot be resolved searching in your hive contents. The client then communicates with the biicode server and tries to find code that is missing in your workspace, and retrieves the best matching version according with your :ref:`policies<policies>`.

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


.. _bii_deps_command:

``bii deps``: Analyzing code dependencies
-----------------------------------------

This command allows you to check the dependencies of any hive in your workspace. It's basic form, with no parameters, provides two pieces of information, giving you a general idea of which are your code dependencies:

* The **Dependencies Table**: a list of the **blocks that contain cells your code depends on**.
* The full list of your cell dependencies.

The command can also be used combining a series of **additional parameters** (you can obtain the full list typing ``bii deps --help`` inside your workspace):

.. code-block:: bash

	usage: bii deps [-h] [--detail] [--unresolved] [--system] [--implicit]
	                [--explicit] [--data] [--blocks BLOCKS [BLOCKS ...]]
	                [--files FILES [FILES ...]] [--virtual] [--main] [--graph]

	...

* ``--detail``: Provides a detailed view of your hive's dependencies, grouping your source cells with their corresponding source blocks (those contained within the ``blocks`` folder of your hive). For each file, the command shows information about it's name and type, the presence or not of a ``main`` function, and the full list of dependencies for each particular cell, grouped under the *explicit* (those dependencies explicitly referenced in your code, as C++ includes or python imports), *implicit* (deduced from code inspection, i.e. C++ implementation files of symbols defined in a header file), and *system* (grouping all system dependencies of a file) sections.

* Parameters for **filtering the cells to be analyzed**, whose dependencies are to be displayed. The command provides 4 different options for filtering the results:

	* ``--blocks [BLOCKS]`` allows you to filter dependencies by block name. Example:

		.. code-block:: bash

			$ bii deps --blocks fenix/blink

	* ``--files [FILES]`` receives a list of cell names to be included in the result. Those files not contained in the list are omitted. Example:

		.. code-block:: bash

			$ bii deps --files fenix/blink/blink.h

	* ``--virtual`` indicates the client to show only those virtual cells contained in your hive.
	* ``--main`` is used for displaying information about cells that contain a ``main`` function or entry point to your code.

* Parameters for **filtering the dependencies**. These allow you to specify you want the client to show their dependencies:

	* ``--unresolved`` shows only your cells' unresolved dependencies; those that are unknown by biicode, and cannot be retrieved from our servers using the :ref:`find command<bii_find_command>`.
	* ``--system`` make the command show only system dependencies for your cells.
	* ``--implicit`` shows only implicit dependencies for your cells.
	* ``--explicit`` shows only those dependencies explicitly referenced in your files.
	* ``--data`` filters the results showing only data dependencies.

* ``--graph``: This last option provides a **visual representation** of your blocks and their dependencies. The client generates an interactive graph that is open in your web browser. Despite most of the code is saved on your local filesystem, you'll need an internet connection for loading some aditional libraries.

	Bellow you can see an example of these representations generated for a sample *'hello world'* block. In this case there are no external dependencies, and only those blocks contained in the ``blocks`` folder of your hive (the ``user/hello_world`` bock) are represented, and grouped under the 'SRC' element. There is also one system dependency. You can click on the different nodes to expand and show their content. You can also drag every node, or pan and zoom the whole graphic.

	.. raw:: html

		<iframe src="/_static/graphs/hello_world/hello_world.html" width="100%" height="600px"></iframe>

	* Double-clicking on any empty area **resets the pan and zoom** to their initial values.
	* All dependencies are represented as **colored connections** (red for implicit dependencies, blue for explicit dependencies, and yellow for all system dependencies). All unresolved dependencies are displayed in a dark grey color.
	* Virtual cells are related to their possible implementations using **green connections**.
	* You can show or hide any type of dependency just clicking on their corresponding toolbar buttons.
	* Dragging a node while holding the *shift* key allows you to move also all its descendant nodes (those folders and cells contained in that particular node, that are currently visible on the graph).
	* The outer color of each cell corresponds to the color of its block, while the inner color gives information about the particular cell type (cpp, python, etc.).


.. _bii_open_command:

``bii open``: Editing code
------------------------------

This command allows you to edit a published block.
You can use this command to edit **one of your dependency blocks** or any block you have seen on the web and you want to edit.
When you invoke this command the block is placed into the ``blocks`` folder within your hive, and their cells become editable source files that can be modified by you and eventually published in a new version of the same branch (if you have writting permissions for that branch) or in a new branch (using the :ref:`publish command<bii_publish_command>`).

There are different ways of retrieving a block created by you or other biicode user to perform some modifications:

That block is a dependency of your code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is the most general scenario. In this case, you are **using some cells from a previously published block** (originally created by you, or by another biicode user) . This means that yout have executed the :ref:`find command<bii_find_command>` inside your hive, and some external dependencies have been retrieved from the biicode servers, and copied to the ``deps`` folder of your hive. Let's imagine your user name is ``peter``, and your block ``peter/my_block`` has dependencies on some files written by the user ``martha``. In particular your code contains references to the block ``martha/her_block``.  After calling the ``bii find`` command, only those files your block needs are copied under the ``deps`` folder of the hive you are working on. 

If you decide to make some modifications to the code you are using, you must call the ``bii open`` command, passing as a parameter the name of the block you intend to modify:

.. code-block:: bash

	$ bii open martha/her_block

Then, the biicode client copies martha's full block to your ``blocks`` hive folder, and you can perform any modifications you need, and eventually publish the modifications on a new branch for that block.

You have an empty hive
^^^^^^^^^^^^^^^^^^^^^^

We can directly call the ``bii open <block_name>`` command and retrieve any published block from the Biicode servers. The code is then copied to the ``blocks`` folder of the **hive** we are working on, and we can modify it as any other source block.

Your hive is not empty
^^^^^^^^^^^^^^^^^^^^^^

This case is very similar to the empty hive one except it may alter your current dependencies. If you already have edition blocks in your hive and you open another one that is not related to your other blocks, its dependencies will prevail over your existing dependencies. This means your dependencies can be upgraded or downgraded to match the ones in the block you are opening. If you want to enforce specic versions you can always do it editing your :ref:`policies file<policies>`.


.. _bii_close_command:

``bii close``: Finish editing the code
----------------------------------------

You can use ``bii close <block_name>`` command to close a block under edition in ``blocks``, i.e., a block that you have done a ``bii open`` and have be editing it. If it's a dependency of any block yours, moves it to ``deps`` folder.

.. code-block:: bash

	$ bii close martha/her_block


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

.. _bii_info_command:

``bii info``: Hive information
------------------------------

This command shows some **general information about the hive you are currently working on**. This information comprehends two fundamental aspects of the blocks contained in your hive:

* The :ref:`tracking info<bii_info_tracking>`, or the last published version of the code you are editing in your block.
* The :ref:`merges info<bii_info_merges>`, showing the published code that has been merged into your edition blocks, before they are published.

.. _bii_info_tracking:

Tracking information
^^^^^^^^^^^^^^^^^^^^

The tracking information **provides insight about the origins of each of the blocks** currently contained in the ``blocks`` folder of your hive, which are being edited by you and are susceptible of :ref:`being shared in a new publication<bii_publish_command>`. This is the block, branch and version of the code you are currently editing. This information can find its origin in three different types of events regarding your blocks:

* You have **published** at least one version of a block, and you continue working on it. In this case the tracking information contains the last published version of your code: ``<block_name>(branch_name): <version>``.

* You have performed an :ref:`open of a given block<bii_open_command>` in order to make some modifications or adaptations. In this case the source code of this block is automatically copied by the biicode client to the ``blocks`` folder of your hive, and the tracking information reflects the fact that the code contained in this particular block is based on the code of the opened block.

* You have just **created** a new unpublished block in your hive. In this case, no tracking information is available. You'll have to publish your block first!

In the first two scenarios, **the tracking information provides details about the code that serves as the basis for your edition**. You can think of this information as the code that is in the same *track* as your *unpublished block*, just one step before. When you perform a new publication of your block this information will be updated precisely with the name of the branch and version just published.

Imagine you are the original creator of the ``dummy`` block, and your are working on the ``master`` branch of this block, where you have performed 10 publications (from 0 to 9). This means that your last published version is ``username/dummy(username/master): 9`` (where ``username`` is, as you could expect, your username). This is the tracking block version for your local ``dummy`` block, contained in your hive. Executing the ``bii info`` command you would see the following output on your console:

.. code-block:: bash

	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/master): 9

	Merges info:
	============
	No merges found in this hive.

Now, let's suppose you decide to open in the same hive a dependency block ``simple``, owned by one of your biicode buddies, with username ``buddy``. To accomplish this, you should use the ``bii open`` command as follows:

.. code-block:: bash

	$ bii open buddy/simple

Reached this point, your hive should contain both a ``dummy`` block (in ``your_hive/blocks/username/dummy)``), and a editable copy of the ``simple`` block (in ``your_hive/blocks/buddy/simple``). Moreover, if you check again your hive info, you will get a different ouput reflecting the changes in your hive:

.. code-block:: bash

	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/master): 9
	[B]: buddy/simple
	  Tracking: buddy/simple(buddy/master): 3

	Merges info:
	============
	No merges found in this hive.

Given that you didn't specify any branch or version information in the ``bii open``, the client has retrieved the last published version (``3``, in this case) available in the master branch of the owner user (``buddy/master``).

Now, after having worked for a while in your hive, you are happy with the results and decide to share your code with other biicode users. As you can only pubish one block at a time, let's suppose you decide to publish first your modifications to your local copy of the ``buddy/simple`` block. In this case you must specify the ``--branch`` information to create your own branch with the modifications of another user's block:

.. code-block:: bash

	$ bii publish --block buddy/simple --branch my_simple_branch
	...
	...
	INFO: Successfully published buddy/simple(username/my_simple_branch): 0

The output of the previous command indicates that the first (``0``) version of the ``username/my_simple_branch`` branch of ``buddy/simple`` block has just been published. Your hive information has also been updated:

.. code-block:: bash

	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/master): 9
	[B]: buddy/simple
	  Tracking: buddy/simple(username/my_simple_branch): 0

	Merges info:
	============
	No merges found in this hive.

Note that your local copy of the ``buddy/simple`` block **is now tracking a different branch and version; the one that you just published**.

Now, you are ready to understand the following sequence of commands. Otherwise, do not hesitate to check our forum and get some answers in the `Client section of the biicode forum <http://forum.biicode.com/category/client>`_.

.. code-block:: bash

	$ bii publish --block username/dummy
	...
	...
	INFO: Successfully published username/dummy(username/master): 10
	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/master): 10
	[B]: buddy/simple
	  Tracking: buddy/simple(username/my_simple_branch): 0

	...
	... some code modifications, building and verifying your program
	...
	$ bii publish --block username/dummy --branch sampling
	...
	...
	INFO: Successfully published username/dummy(username/sampling): 0
	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/sampling): 0
	[B]: buddy/simple
	  Tracking: buddy/simple(username/my_simple_branch): 0

	...
	... some code modifications, building and verifying your program
	...

	$ bii publish --block buddy/simple
	...
	...
	INFO: Successfully published buddy/simple(username/my_simple_branch): 1
	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/sampling): 0
	[B]: buddy/simple
	  Tracking: buddy/simple(username/my_simple_branch): 1

	...
	... and so on ...
	...

.. _bii_info_merges:

Merges information
^^^^^^^^^^^^^^^^^^

This part of the ``bii info`` command output shows information **only in case you have performed any merges in your current hive**. Following the example introduced in the :ref:`section that exaplined the merge command<bii_merge_command>`, let's assume you have just merged a ``original/mathematyka(improver/better_math): 5`` version into your local copy of the ``mathematyka`` block, with branch and version: ``original/mathematyka(original/master): 25``. Now, the output of the client info utility would be as follows:

.. code-block:: bash

	$ bii info

	Tracking info:
	==============
	[B]: original/mathematyka
	  Tracking: original/mathematyka(original/master): 25

	Merges info:
	============
	[B]: original/mathematyka
	  Merged: original/mathematyka(improver/better_math): 5

This information about the merges performed in your code is only available locally, and while you haven't published the modifications to your edition block. See the ouput of the ``bii info`` command after you have published the changes, and try to understand its meaning:

.. code-block:: bash

	$ bii publish --block original/mathematyka
	...
	INFO: Successfully published original/mathematyka(original/master): 26

	$ bii info

	Tracking info:
	==============
	[B]: original/mathematyka
	  Tracking: original/mathematyka(original/master): 26

	Merges info:
	============
	No merges found in this hive.


.. _bii_status_command:

``bii status``: Hive status
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

``bii diff``: Compare files
------------------------------

Compare files and show differences with ``bii diff <block_name>`` command. You can compare your current hive with previous published versions or compare between published versions.

For example, if you want to see the changes in your local block with the saved last current version.

.. code-block:: bash

	$ bii diff [user]/[block]

Now you have published new two versions and you'd want to know the ``diff`` between your ``current local block`` with the first version (``version=0``) published in biicode:

.. code-block:: bash

	$ bii diff [user]/[block] --v1 0

Now, if you'd want to know the ``diff`` between the ``version=0`` and ``version=1`` published:

.. code-block:: bash

	$ bii diff [user]/[block] --v1 0 --v2 1


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


.. _bii_settings_command:

``bii settings``: Hive settings 
----------------------------------

This command shows your current hive settings. This is an example about a hive with Arduino language:

.. code-block:: bash

	$ bii settings
	INFO: These are your settings for this hive
	INFO: arduino:
	  board: uno
	  builder: {family: make, subfamily: mingw}
	  port: None
	  programmer: usbtinyisp
	os: {arch: 32bit, family: Windows, subfamily: '8', version: 6.2.9200}

	INFO: If you want to change it, you have to modify this file:
	    [HIVE_PATH]/[USER]/bii/settings.bii
