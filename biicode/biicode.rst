.. _about_biicode:

What is biicode?
================

**Biicode is a file-oriented Dependencies Manager for C/C++ developers**:

* It's **simple**.
|
* **Manage dependencies at file level**. **No libraries**, **no packaging**. Reuse, integrate the files you need, with their transitive dependencies, to your project.
|
* **Code reuse from source code**. If the language requires it (as  sometimes in C++) artifacts like libraries are built locally.
|
* **Deduces your dependencies from source code**. Biicode scans your source files, and extracts relationships between those files.
|
* It also **manages updates**. You can easily upgrade your dependencies if new compatible versions that match your preferences are published.
|
* It's **fully deterministic**, it takes into account the compatible configuration of libraries.
|
* **Multi language (currently C/C++ and Node.js)**, **Multi-OS**. The work flow, the tool and the way you reuse code are exactly the same independently of the programming language or the OS you are using.
|
* Contribute to our collaborative community! Publishing your code is also very simple, so you can easily **share and reuse your code with others in all your projects**.
|
* **Configurable**: you can define (if desired) manually in configuration files many things, such as dependencies, your own CMakeLists.txt, etc.
|
* **Highly automated**. We can create projects and build scripts. But you'll never loose your building control.

.. _basic_concepts:

Basic concepts
--------------

biicode defines a very simple methodology, that helps you organize your projects and folders, by focusing on a *modular software development* to simplify code reuse.

For a description of how these concepts reflect on your disk's folders structure read our :ref:`project layouts<project_layout>`.

The basic concepts are:

* **biicode project**. You can have as many projects as you want.
* **block**, it's biicode basic code sharing unit. Any project can contain lots of code blocks; your own blocks, and other user's blocks.
|
Learn more about these concepts:

.. _project_definition:

Biicode project
^^^^^^^^^^^^^^^

It is very similar to a **conventional project**. In short, they are first level folders  and their contents. In these folders you edit, build and run your code. You can think of them as a sandbox where you can play around with your code before sharing it. 

**You can have as many projects as you want**. They are local to your computer, and each project is self-contained. You can publish, zip or email them... 

**Biicode is not a version control system, so you should use git, mercurial, svn** or whatever you prefer along with biicode if you want a real version control for your files. Biicode is completely compatible with those systems, and does not interfere with them.

You can read :ref:`here about the project folders structure<project_layout>`.

.. _block_definition:

Block
^^^^^

A block is a folder that contains a **group of files, that are logically related**. 

* The ``blocks`` folder contains the **blocks you are working on**. It is the code you are actually programming.

Your code is inside ``user_name/block_name``. A **block** name, has two parts, the **user name**, and the **name of the block**. You can see this structure under the ``blocks`` and ``deps`` folders, both for your own blocks and for the dependencies.

Usually, ``username`` is your biicode user name. But when you are editing code that was originally created by other_user (see :ref:`how you can edit other users' blocks <bii_open_command>` with the ``bii open`` command).

You can **publish and share blocks to reuse later**. It’s similar to C libraries, java jars, or python packages and modules, but not exactly the same, as they **always contain source code**, and without any real packaging or grouping other than the block name.  

There's always a ``bii`` folder in a block, and it has at least two files:

		* ``requirements.bii``: A list of the blocks you depend on. You can change it to push the system into using a specific version.
		* ``parents.bii``: lets us identify what version you are working on and which version is the last one published.

	You can create and edit these:

		* ``dependencies.bii``: This optional file allows you to set extra dependencies for your project such as license files. You can read about :ref:`dependencies configuration here <dependencies_bii>`.
		* ``mains.bii``: Is another optional configuration file for defining entry points to your code. You can :ref:`read more about this file following this link <mains_bii>`.
		* ``virtual.bii``: This optional file is used to configure :ref:`virtual resources <virtual_cells>`; those whose actual file implementation depends on certain conditions.


Remember that if you just need a certain file from a block and such file does not depend on any other one, only that file will be retrieved to reuse at your project.

**Circular dependencies between blocks are not allowed**, as usually happens in other systems. If the files of a block **A** depend on the ones of block **B**, then, the files of block **B** cannot depend on ones belonging to block **A**.

.. container:: infonote

    **Remember to name each block differently**


.. _project_layout:

Project layout
--------------

Store in a biicode project **as many blocks as you want**. It contains both your code and your code dependencies, and some custom configuration files, specific for that project.
Check these :ref:`basic biicode concepts <basic_concepts>` first, to become familiar with projects and blocks.

This is a complete example project layout: ::

|-- my_project
|    +-- bii
|    |    |-- .hive.db
|    |    |-- settings.bii
|    |    |-- policies.bii
|    +-- bin
|    +-- blocks
|    |	  +-- phil
|    |    |     +-- hello (block name phil/hello)
|    |    |     |     +-- bii
|    |    |     |     |    |-- requirements.bii
|    |    |     |     |    |-- parents.bii
|    |    |     |     |    |-- dependencies.bii
|    |    |     |     |    |-- mains.bii
|    |    |     |     |    |-- virtual.bii
|    |    |  	|     |-- CmakeLists.txt
|    |    |  	|     |-- hello.cpp
|    |    |     |     |-- hello.h
|    |    |     |     |-- main.cpp
|    |    |     |     |-- ignore.bii
|    |    |     +-- pretty_hello (block name phil/pretty_hello)
|    |    |   	      |-- pretty_hello.cpp
|    |    |           |-- pretty_hello.h
|    |    |           |-- types.bii
|    |    +-- diego
|    |          +-- suma (block name diego/suma)
|    |                +-- bii
|    |		     	  |    |-- requirements.bii
|    |		     	  |    |-- parents.bii
|    |        	      |-- test.cpp
|    |        	      |-- suma.h
|    |                |-- suma.cpp.h
|    +-- build
|    +-- cmake
|    |    |-- CMakeLists.txt
|    |    |-- biicode.cmake
|    |    |-- bii_phil_hello_vars.cmake
|    |    |-- bii_phil_pretty_hello_vars.cmake
|    |    |-- bii_diego_suma_vars.cmake
|    +-- deps
|    |	  +-- google
|    |    |     +-- gtest
|    |    |     |     +-- bii
|    |    |     |     |    |-- parents.bii
|    |    |     |     +-- src
|    |    |     |     +-- include
|    |    |  	|     |-- gtest.h
|    |    |     |     |-- readme.md


As you can see, the **project** contains a collection of folders. Take a look at them:

``bii``: folder contains these files.

		* ``.hive.db``: contains all your project meta information. This file must not be manually modified or removed.
		* ``policies.bii``: contains custom policies of the current project.
		* ``settings.bii``: stores information about the project programming language, operating system, and other tools required for a particular project.

``deps``: This folder is filled with your project **dependencies source code** whenever you use the ``bii find`` command. These files, just the ones you need, are automatically retrieved, downloaded from our servers and stored locally on your computer.

``blocks``: Contains the **code of the blocks you are working on**, your source code. For more information check the :ref:`blocks definition <block_definition>` .

``build``: Contains these **temporary build and project files**. Usually, this folder can be safely deleted, as it is fully automatically generated. In this folder you can find for example the Visual Studio solution files (.sln), Eclipse .project and .cproject files, etc. 

``cmake``: Contains several files generated by biicode that define the build process, ``CMakeLists.txt``, ``biicode.cmake`` and ``bii_block_name_vars.cmake`` (as much as blocks you have). From these files and the project settings, the CMake tool creates the actual project, that can be a Eclipse one (with MinGW in win or GNU Make - gcc in linux), a Visual one,  plain Makefiles, etc.

``bin``: folder contains the executables generated by biicode and data files from projects containing programs in languages that must be compiled. You can safely delete its contents, as they will be generated with every new compilation.

You can read in detail about the special :ref:`configuration files section <config_files>`.

