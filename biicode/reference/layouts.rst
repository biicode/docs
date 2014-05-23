.. _layouts:

Workspace and hives layouts
===========================

This section describes the **folders structure of a typical biicode workspace**, and the hives it contains. If you haven't done so, we recommend reading these :ref:`basic biicode concepts <basic_concepts>` first, understandig the conceps of workspace, hive, block and cell.

Some special biicode configuration files are also mentioned. You can read in detail about these files in the :ref:`configuration files section <config_files>`.

.. _workspace_layout:

Workspace layout
----------------

A biicode workspace is :ref:`the special folder you initialize<create_workspace>` using the ``bii init`` command. It contains cached data from server, general information about your machine, system and tools, and default configurations for your hives. It is also the **container for all your hives** or working projects.

Every biicode workspace contains a special ``bii`` folder with **configuration files** holding information about your development environment and programming preferences.

The workspace layout is as follows: ::

|-- myworkspace
|    |-- bii
|    |    |-- .bii.db
|    |    |-- ignore.bii
|    |    |-- default_policies.bii
|    +-- my_hive1
|    +-- my_hive2


As you can see there is a ``bii`` folder containing several files with ``.bii`` extension. These are global configuration files, and their contents affect all your hives.

* ``.bii.db``: is a local cache, that allows us to optimize dependencies retrieval for your hives. It contains information about previously downloaded dependencies, with the main purpose of accelerating future retrievals. You **must not edit or delete this file** under any circumstances.
* ``ignore.bii``: holds **default file filtering rules**. Its format is simmilar to a `.gitignore file <http://git-scm.com/docs/gitignore>`_, and indicates biicode **which files must be ignored** when processing and publishing your files. This configuration is applied hierarchically across all desdendant workspace folders, but can be overriden from any local block, creating custom specific configurations. :ref:`Learn more about ignore files following this link <ignore>`.
* ``default_policies.bii``: holds your workspace default `policies <http://docs.biicode.com/en/latest/reference/policies.html>`_ configuration. These policies define **how dependencies are found and which versions are retrieved** to your local filesystem. The contents of this file are copied to your hive's ``policies.bii`` configuration file whenever you create a new hive. You can think of this file as a template policies configuration for your new hives.

As we already know, the workspace folder is :ref:`the top-level container for all your hives<basic_concepts>`. Every single hive in your workspace as also a predefined folders structure that mus be observed, which is described below.

.. _hive_layout:

Hives and blocks layout
-----------------------

A biicode workspace can hold **as many hives as you want**. Rememeber that a biicode hive is no other thing that a working project: a special folder that contains both your code and your code dependencies, and some custom configuration files, specific for that hive.

A typical hive layout is as follows: ::

|-- my_hive
|    +-- bii
|    |    |-- .hive.db
|    |    |-- settings.bii
|    |    |-- policies.bii
|    +-- bin
|    +-- blocks
|    |	  +-- my_user_name
|    |    |     +-- my_block
|    |    |     |     +-- bii
|    |    |     |     |    |-- dependencies.bii
|    |    |     |     |    |-- mains.bii
|    |    |     |     |    +-- virtual.bii
|    |    |  	|     |-- hello.c
|    |    |     |     +-- hello.h
|    |    |     +-- my_other_block
|    |    |   	      |-- foo.c
|    |    |           +-- bar.h
|    |    +-- other_user_name
|    |          +-- block_im_editing
|	 |                +-- bii
|	 |                |    |-- mains.bii
|    |        	      |-- message.c
|    |                +-- message.h
|    +-- build
|    +-- cmake
|    |    |-- CMakeLists.txt
|    |    |-- bii_functions.cmake
|    |    |-- bii_targets.cmake
|    |    +-- bii_vars.cmake
|    +-- deps

As you can see, the **hive** contains a collection of folders. We will go through each one of them:

* The ``bii`` folder presents a similar structure and contents to the :ref:`workspace bii folder <workspace_layout>`. It contains these files:

	* ``.hive.db``: contains all your hive meta information. This file must not be manually modified or removed.
	* ``policies.bii``: contains custom policies for a given hive. Its contents are copied from the workspace ``default_policies.bii`` file when :ref:`you create a new hive<bii_new_command>`.
	* ``settings.bii``: stores information about the hive programming language, operating system, and other tools required for a particular project. Its contents are extracted from the workspace environment configuration when you create a new hive.
* The ``deps`` folder contains your hive **dependencies source code**. All files contained in this folder are downloaded using the ``bii find`` command after analyzing your source files contained under the ``blocks`` folder. These are all the strictly necessary cells for your hive to compile (when needed, if your are using a compiled language as *c* or *c++*) and run correctly.
* The ``blocks`` folder is very important, as it contains the **code of the blocks you are working on**; your source code. Code is listed under ``usernames/blockname``. In general, ``username`` will be your biicode user name. But in some cases you will be editing code originally created by other biicode user (see :ref:`how you can edit other users' blocks <bii_open_command>` with the ``bii open`` command). Under each ``username`` folder you can find all the blocks you are editing inside your hive. For version control systems, it is usually ok to ignore everything but this ``blocks`` folder, and the ``bii`` folder that holds the configuration and metadata.

	* ``bii``: Every block main contain its own configuration folder, with specific block-level settings and preferences. This folder and files are optional for a block, and not always needed. But sometimes you will need additional control over a block configuration:

		* ``dependencies.bii``: This optional file allows you to set extra dependencies for your project such as license files. You can read about :ref:`dependencies configuration here <dependencies_bii>`.
		* ``mains.bii``: Is another optional configuration file for defining entry points to your code. You can :ref:`read more about this file following this link <mains_bii>`.
		* ``virtual.bii``: This optional file is used to configure :ref:`virtual resources <virtual_cells>`; those whose actual file implementation depends on certain conditions.
* ``build``: Contains build files such as make scripts and compiled objects. You can safely delete it's contents
* ``cmake``: Contains autogenerated ``CMakeLists.txt`` as well as other files that allow you to define your own cmake.
* The ``bin`` folder contains any executables generated from hives containing programs in languages that must be compiled. You can safely delete its contents, as they will be generated with every new compilation.
