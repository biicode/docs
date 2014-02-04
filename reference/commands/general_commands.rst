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

We know that whenever we create a new hive, a default new block is created for as with the name provided to the assistant. If we manually remove that block from the ``blocks`` folder of the hive, we can directly call the ``bii open <block_name>`` command and retrieve any published block from the Biicode servers. The code is then copied to the ``blocks`` folder of the **hive** we are working on, and we can modify it as any other source block.
