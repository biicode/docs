Basic concepts
---------------------

.. _basic_concepts:

This section briefly describes some basic concepts regarding your workspace and projects. For a complete description go to: :ref:`Reference: Workspace and hives layouts <layouts>`.

Workspace
^^^^^^^^^
This is a **special folder** which is created on your system during the :ref:`installation process <installation>`. The concept is pretty much the same as in IDEs; the place where all your projects —which in biicode terminology are called *hives*— are located. This workspace contains all your code and related metadata, so keep it private under your user account, and do not share it with untrusted people. 

Simply speaking, your workspace **will hold your hives**, or projects.

Your workspace containes a special ``bii`` folder, created when you call the ``bii init`` command during the biicode instalation process. This folder contains some important information for the client program and general settings for your hives, so do not remove it!

Hive
^^^^
The concept of hive is very similar to that of a **conventional project**. In short, they are first level folders —other than the ``bii`` folder— in your workspace, and their contents. In these hive folders you edit, build and run your code. You can think of them as a sandbox where you can play around with your code before sharing it. 

**You can have as many hives as you want** inside your workspace. They are local to your computer, and each hive is self-contained. You can zip and send any hive by email to lately unzip it on another workspace (e.g. another computer), or even share it using a Dropbox folder. Hives can also be directly uploaded to biicode (althoug this is, at this moment, an experimental feature). 

**Biicode is not a version control system, so you should use git, mercurial, svn or whatever** you prefer along with biicode if you want a real version control of your hives files. Biicode is completelly compatible with thoses systems, and does not interfere with them.

Every hive has some or all of these subfolders:

* The ``bii`` folder: contains configuration files for that particular hive.
* The ``build`` folder: contains temporal build files (if necessary) as ``CMakeCache`` and object files for C++. Can be safely deleted, as it will be recreated if required.
* The ``bin`` folder: is the location for output binary files. It is usually a *result* folder, so it might be safely deleted.
* The ``src`` folder: is the main folder where you place all your source code blocks and data that are currently under edition in this hive.
* The ``dep`` folder: contains the blocks of source code and data that are required by this hive. That is, **your hive's dependencies**. These files are not under edition (though they could be modified, as exmplained in the :ref:`Dependencies edition section in Advanced Features <dependencies_edition>`), so it is usually not required to touch this folder.

In summary: **the most important component of any hive is the** ``src`` **folder**. For version control systems, it is usually ok to ignore everything but this ``src`` folder, together with the ``bii`` one that holds the configuration and metadata.


Block
^^^^^

A block is a **group of files, or cells in biicode terminology, that are logically related**. Inside the ``src`` and ``dep`` folders, the source code is organized in **blocks**. Each **block** name is composed by two parts, a username of the block creator, and the simple block name, in the form: ``user_name/block_name``.

Blocks are the items you can publish and share for later reuse. It’s a similar concept to C libraries, java jars, or python packages and modules, but not exactly the same, as they are always from source code, and without any real packaging grouping them other than the block name.  An important concept of blocks, is that not all cells (files) within a block are to be reused together. If you need a certain cell of a block and such cell does not depend on anything else, only that cell will be retrieved and reused in your hive.

**Circular dependencies between blocks are not allowed**, as usually happens in other existing systems. If the cells of a block **A** depend on the cells of block **B**, then, the cells of block **B** cannot depend on cells belonging to block **A**.


Cell
^^^^

A cell is the **basic biicode processing and reuse unit**. It is basically each file together with its metadata. 

Let's say the honey is the source code you put inside each one of your source files, and the cell structure is the metadata that relates such source file with the others. Actually, cells can be of any type (text, data, images), not just source code. In your code you can make references (includes, imports) to your cells or cells from any other user. 

You just care about producing the honey, biicode will try to care for the rest.


Example of a basic layout
^^^^^^^^^^^^^^^^^^^^^^^^^

This is an example of a basic layout for a biicode user with user name ``john1983``. This workspace contains a single hive (``superhive``). Inside this hive we find a block (``newblock``) that belongs to ``john1983``. The hive has also some dependencies with the blocks ``john1983/oldblock`` and ``mary/miniblock``: ::

	workspace
        |- bii (contains default configuration files)
        |- superhive
             |- bii (contains configuration files for this hive)
             |- src
             |   |- john1983
             |       |- newblock
             |          |- bii      (configuration files for this block)
             |          |- file.h 	(you put your code for block1 here)
             |- dep
                |- mary
                |   |- miniblock
                |- john1983 (you can also reuse your own code!)
                    |- oldblock		  


All the code contained in the ``dep`` folder is automatically downloaded by the biicode client after analyzing your source files contained under the ``src`` folder. These are all the strictly necessary cells for your hive to compile and run correctly.

