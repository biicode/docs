.. _basic_concepts:

Basic concepts
--------------

This section describes some basic concepts regarding your Biicode workspace and projects. Biicode defines a very simple methodology, that helps you to organize your projects and folders, putting a **strong focus on the software modularity** with the main goal of simplifying the code reutilization.

For a description of how these concepts are reflected on your disk folders structure read our :ref:`reference, workspace and hives layouts<layouts>`.

In the following sections you will learn about four basic concepts:

* The **workspace**, a special folder that holds all your code.
* The **hive**, or biicode project. A workspace can contain as many hives as you desire.
* The **block**, or biicode basic code sharing unit. Any hive can contain multiple blocks of code; blocks of your own, and blocks of other users.
* The **cell**, or file. Blocks are made up of one or more cells that contain source code and other resources (images, data files, etc.)

Now these concepts are explained in more detail:

.. _workspace_definition:

Workspace
^^^^^^^^^

This is a **special folder** which is created on your system during the :ref:`installation process <installation>`. The concept is pretty much the same as in IDEs; **the place where all your projects —which in biicode terminology are called hives— are located**. The workspace contains all your code and related metadata, so keep it private under your system user account, and do not share it with untrusted people.

Simply speaking, your workspace **will hold your hives**, or projects.

While you create a new Workspace, the ``bii init`` command will generate a special folder, ``bii``. This folder contains some important :ref:`configuration files section<config_files>` for the client program and general settings for your hives, so do not remove it!

:ref:`Here can learn more about the workspace folders layout<workspace_layout>`.

.. _hive_definition:

Hive
^^^^

The concept of hive is very similar to that of a **conventional project**. In short, they are first level folders —other than the ``bii`` folder— in your workspace, and their contents. In these hive folders you edit, build and run your code. You can think of them as a sandbox where you can play around with your code before sharing it. 

**You can have as many hives as you want** inside your workspace. They are local to your computer, and each hive is self-contained. You can zip and send any hive by email to lately unzip it on other workspace (e.g. other computer), or even share it using a Dropbox folder. Hives can also be directly uploaded to biicode (although this is, at this moment, an experimental feature).

**Biicode is not a version control system, so you should use git, mercurial, svn** or whatever you prefer along with biicode if you want a real version control for your files. Biicode is completely compatible with those systems, and does not interfere with them.

You can read :ref:`here about the hives folders structure<hive_layout>`.

.. _block_definition:

Block
^^^^^

A block is a **group of files, or cells in biicode terminology, that are logically related**. Every hive contains two special folders:

* The ``blocks`` folder contains those **blocks that are being edited by you**. That is the code you are actually programming.
* The ``deps`` folder contains those blocks that are dependencies of the code contained in the ``blocks`` folder. They are automatically retrieved by the biicode client program, downloaded from our servers and stored locally on your computer. However, these blocks typically contain only those files required to meet the dependencies of your source files contained in the ``blocks`` folder.

A **block** name, ``<block_name>``, is composed by two parts, the **user name** of the block original creator, and the **name of the block**, which is a simple name: ``user_name/simple_name``. This structure is reflected under the ``blocks`` and ``deps`` folder structure, both for your own blocks and for the dependencies.

Blocks are the items you can **publish and share for later reuse**. It’s a similar concept to C libraries, java jars, or python packages and modules, but not exactly the same, as they **always contains source code**, and without any real packaging grouping them other than the block name.  

It is important to emphasize the fact that not all cells (files) within a block are to be reused together. If you need a certain cell of a block and such cell does not depend on any other file, only that cell will be retrieved and reused in your hive.

**Circular dependencies between blocks are not allowed**, as usually happens in other systems. If the cells of a block **A** depend on the cells of block **B**, then, the cells of block **B** cannot depend on cells belonging to block **A**.


Remember to name each block differently.

.. _cell_definition:


Cell
^^^^

A cell is the **basic biicode processing and reuse unit**, and is composed of **both the file contents and metadata information**. 

Let's say the honey is the source code you put inside each one of your source files, and the cell structure is the metadata that relates such source file with the others. Actually, cells can be of any type (text, data, images), not just source code. In your code you can make references (includes, imports) to your cells or cells from any other user. 

You just care about producing the honey, biicode will try to care for the rest.
