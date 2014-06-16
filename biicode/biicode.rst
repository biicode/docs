.. _about_biicode:

What is biicode?
================

**Biicode is a simple file oriented Dependencies Manager for C/C++ developers**, with many unique characteristics:

* **Dependencies are always managed at the file level**. **No libraries**, **no packaging**. If you need to reuse some files from previously developed code, just the required files, together with its transitive dependencies are integrated in your project.
|
* **Reuse of existing code is always done from source code**. If required by the language (as C++) artifacts like libraries are built locally.
|
* It also **manages updates**. You can easily upgrade your dependencies if new compatible versions that match your preferences are published.
|
* It is **fully deterministic**, the joint compatible configuration of libraries is computed.
|
* **Multilanguage (currently C/C++ and Node.js)**, **Multi-OS**. The work flow, the tool, the way you reuse code is exactly the same independently of the programming language or the OS you are using.
|
* Biicode is not just for reusing other's source code! Publishing your code is also very simple, so you can easily **share with others and reuse your code in all your projects**.
|
* **Dependencies deduced from source code**. Biicode scans your source files, and extracts relationships between those files.
|
* **Configurable**: you can define (if desired) manually in configuration files many things, such as dependencies, your own CMakeLists.txt, etc.
|
* **Highly automated**. We are able to create projects and build scripts.

.. container:: infonote

	Biicode is now in an early Beta stage but we are already open, also we have many users that are giving us a lot of feedback that we have to process and further improve the usability of the system. We are doing our best to quickly attend our current users feedback.

	We have many core innovations, and we are following the lean startup and MVP paradigms, i.e. we try to release very often and quickly and perform fast iterations on user feedback.


.. _basic_concepts:

Basic concepts
--------------

biicode defines a very simple methodology, that helps you to organize your projects and folders, putting a **strong focus on the software modularity** with the main goal of simplifying the code reutilization.

For a description of how these concepts are reflected on your disk folders structure read our :ref:`project layouts<project_layout>`.

In the following sections you will learn about four basic concepts:

* The **biicode project**. You could have as many projects as you desire.
* The **block**, or biicode basic code sharing unit. Any hive can contain multiple blocks of code; blocks of your own, and blocks of other users.

Now these concepts are explained in more detail:


.. _project_definition:

Biicode project
^^^^^^^^^^^^^^^

The concept is very similar to that of a **conventional project**. In short, they are first level folders  and their contents. In these folders you edit, build and run your code. You can think of them as a sandbox where you can play around with your code before sharing it. 

**You can have as many projects as you want**. They are local to your computer, and each project is self-contained. You can zip and send any project by email to lately unzip it on other other computer, or even share it using a Dropbox folder.

**Biicode is not a version control system, so you should use git, mercurial, svn** or whatever you prefer along with biicode if you want a real version control for your files. Biicode is completely compatible with those systems, and does not interfere with them.

You can read :ref:`here about the project folders structure<project_layout>`.

.. _block_definition:

Block
^^^^^

A block is a **group of files, that are logically related**. Every project contains two special folders:

* The ``blocks`` folder contains those **blocks that are being edited by you**. That is the code you are actually programming.
* The ``deps`` folder contains those blocks that are dependencies of the code contained in the ``blocks`` folder. They are automatically retrieved by the biicode client program, downloaded from our servers and stored locally on your computer. However, these blocks typically contain only those files required to meet the dependencies of your source files contained in the ``blocks`` folder.

A **block** name, ``<block_name>``, is composed by two parts, the **user name** of the block original creator, and the **name of the block**, which is a simple name: ``user_name/simple_name``. This structure is reflected under the ``blocks`` and ``deps`` folder structure, both for your own blocks and for the dependencies.

Blocks are the items you can **publish and share for later reuse**. It’s a similar concept to C libraries, java jars, or python packages and modules, but not exactly the same, as they **always contains source code**, and without any real packaging grouping them other than the block name.  

It is important to emphasize the fact that not all files within a block are to be reused together. If you need a certain file of a block and such file does not depend on any other one, only that file will be retrieved and reused in your project.

**Circular dependencies between blocks are not allowed**, as usually happens in other systems. If the files of a block **A** depend on the ones of block **B**, then, the files of block **B** cannot depend on ones belonging to block **A**.


Remember to name each block differently.
