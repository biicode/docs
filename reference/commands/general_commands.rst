Client command list
====================

.. _bii_init_command:

``bii init``: Workspace initialization
--------------------------------------

This is the first command you should invoke after installing the biicode client program, and allows the biicode :ref:`workspace initialization in a folder of your choice<create_workspace>`.

This command creates a special ``bii`` folder in the root of your workspace, that contains :ref:`default configuration files<config_files>` for the biicode client. These default files are used as templates when you create a new **hive**, and copied to the corresponding ``bii`` configuration folders for each hive.

.. _bii_new_command:

``bii new <hive_name>``: Creating new hives
-------------------------------------------

This is the command that **creates new hives inside your workspace**. It must be invoked inside a biicode workspace folder, and receives as the only parameter the name of the hive to be created. You can see :ref:`this basic 'hello world' example <hello_world>` to see how a typical hive is created.

The command creates a new folder with the name of the hive, and the full folders structure where your blocks and cells will be located. After invoking the command, some questions are asked to the user:

* The programming **language** of your code. This information is used to define the project configuration, making use of the default settings defined in your workspace configuration default files. Available options are: *java*, *node*, *fortran*, *python*, *cpp*, *arduino* or *None*.
* The name of the **first block** in your hive. A hive, as any other software project, is a logical structure that contains your source files. From a functional point of view, your source files are grouped in blocks. Any hive can hold as many blocks as you want, but at least on of them must be placed in the ``blocks`` folder of your hive, and contain the original code your are creating (or the modifications applied to other users blocks). In other works, **every hive must contain at least on block of code** under the ``blocks`` folder.

In case you choose **cpp** as your programming language, there are some additional options that are supported by the client program, and help you to configure your project and build settings:

* The option to create a default **'hello world'** for your language. These files are placed inside the first block whose name is defined in the previous step.
* The name of the **IDE** you will be using when writing your code. This way, the command will be able to automatically create the project configuration for your favourite IDE. Available options are: *Visual*, *CodeBlocks*, *Eclipse*, *NetBeans*, or *None* if you don't need this configuration.
* Finally, the client asks for a **build type** for your code. Available options are: *None*, *Debug*, *Release*, *RelWithDebInfo*, or *MinSizeRel*.

.. _bii_publish_command:

``bii publish``: Sharing your code
----------------------------------

When your are happy with the state, functionality and performance of your code, you can publish your blocks and share them with other users. This way they will be able to reuse your code, including references to your blocks cells in their source files, and making use of the ``bii find`` command, explained bellow.

The ``bii publish`` command must be invoked inside a **hive** folder and has no parameters, but **will launch an assistant that will guide you** through the publishing process:

* In case your **hive** contains multiple blocks under your ``blocks`` folder, it will ask you which of them you wish to publish. Remember that the name of a block is composed by the name of the original creator, and the simple name of the block joined by a *slash* (``/``) character: ``user_name/simple_name``.
* You must define a **tag** for the published code. Available options are: *DEV*, *ALPHA*, *BETA* or *STABLE*, and they define the state of thevelopment for your code. This information is used in by the :ref:`policies<policies>` of the users that will use this blocks, allowing them to define which versions of your code are their preference.
* Finally, you must provide a short message describing the code your are publishing, and the new functionalities it provides (bugs fixed, or any other valuable information).

After your block has been published and uploaded to the Biicode servers, the program shows a message with information about the name of the block (``user_name/simple_name``), the name of the branch (``user_name/branch_name``), and the numeric ID of the version that has been published in that particular branch.

.. _bii_deps_command:

``bii deps``: Analyzing code dependencies
-----------------------------------------

This command allows you to check the dependencies of any hive in your workspace.

.. _bii_find_command:

``bii find``: Retrieveing dependencies
--------------------------------------

This commands allows you to retrieve any code dependencies from the Biicode servers. The client analyzes your code, and find missing dependencies that cannot be resolved searching in your hive contents. The client then communicates with the biicode server and tries to find code that is missing in your workspace, and retrieves the best matching version according with your :ref:`policies<policies>`.

The retrieved files are copied on your file system, under the ``deps`` folder of your hive, following a folder structure that reproduces the name of the retrieved blocks: ``<block_name> = <user_name>/<simple_name>`` (see the :ref:`basic concepts<basic_concepts>` and how a **block** is uniquely identified).

.. _bii_open_command:

``bii open <block_name>``: Reusing the code
-------------------------------------------

This command is tipically used when you decide you want to do some modifications to one of your dependency blocks (those blocks contained in the ``deps`` folder of your hive). There are two ways of retrieving a block created by you or other biicode user to perform some modifications:

That block is a dependency of your code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In this case, you are using some files from other user's block. This means that when you execute a ``bii find`` command those files are copied to the ``deps`` folder of your hive. Let's imagine your user name is ``peter``, and your block ``peter/my_block`` dependes on the code written by the user ``martha``. In particular it dependes from the block ``martha/her_block``.  After calling the ``bii find`` command, the files your block needs are copied under the ``deps`` folder of the hive you are working on. If you decide to make some modifications to the code you are using, you must call the ``bii open`` command, passing as a parameter the name of the block you intend to modify:

.. code-block:: bash

	bii open martha/her_block

Then, the biicode client copies martha's block to your ``blocks`` hive folder, and you can perform your modifications and publish that code as any other block.

You have an empty hive
^^^^^^^^^^^^^^^^^^^^^^

We know that whenever we create a new hive, a default new block is created for us with the name provided to the assistant. If we manually remove that block from the ``blocks`` folder of the hive, we can directly call the ``bii open <block_name>`` command and retrieve any published block from the Biicode servers. The code is then copied to the ``blocks`` folder of the **hive** we are working on, and we can modify it as any other source block.

``bii info``: Hive information
------------------------------

This command shows some **general information about the hive you are currently working on**. This information comprehends two fundamental aspects of the blocks contained in your hive:

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

Reached this point, your hive should cointain both a ``dummy`` block (in ``your_hive/blocks/username/dummy)``), and a editable copy of the ``simple`` block (in ``your_hive/blocks/buddy/simple``). Moreover, if you check again your hive info, you will get a different ouput reflecting the changes in your hive:

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
