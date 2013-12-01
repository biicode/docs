Basic concepts
---------------------

.. _basic_concepts:

This section briefly describes basic concepts of your workspace and projects. For a complete description go to: :ref:`Reference: Workspace and hives layouts <layouts>`.

Workspace
^^^^^^^^^
This is the special **folder** in your system that you have just created in the installation step. This workspace **will hold your hives** (projects). The concept is pretty much the same as in IDEs, the place where all your projects (hives) are located. This workspace contains all your code and metadata, so keep it private under your user account, and do not leave it in public computers. 

Hive
^^^^
The hive is very similar to a **conventional "project"**. Hives are the first level folders in your workspace (except the "bii" one). In these hive folders you edit, build and run your code; they are a sandbox where you can play around with your code before sharing it. **You can have as many hives as you want** in your workspace. They are local to your computer, and each hive is self-contained. You can zip it and send by email to lately unzip it in another workspace (e.g. another computer), or put it in a dropbox folder. Hives can also be directly uploaded to biicode (experimental feature). **Biicode is not a version control system, so you should use git, mercurial, svn or whatever** you prefer along with biicode if you want a real version control of your hives files.

Every hive has some or all of these subfolders:

- **bii**: Contains configuration files for this hive
- **build**: temporal build files (if necessary) as CMakeCache and object files for C++. Can be safely deleted, as it will be recreated when required.
- **bin**: location of output binary files. It is usually a "result" folder, so it might be safely deleted.
- **src**: the main folder with the blocks of source code and data that are currently under edition in this hive.
- **dep**: the folder with the blocks of source code and data that are required by this hive. These files are not under edition (though they could be modified, see in Advanced Features), so it is usually not required to touch this folder.

In summary: the most important folder of the hive is the **src** one. For version control systems, it is usually ok to ignore everything but this **src** folder, together with the **bii** one that holds the configuration and metadata.


Block
^^^^^

Inside **src** and **dep** folders, things are organized in **blocks**. Each **block** name is composed by two parts, a username and the simple block name, in the form:
	
	user/block


A block is a **group of cells** (files) that are logically related. Blocks are the items you can publish and share for later reuse. It’s a similar concept to C libraries, java jars or python packages and modules, but not exactly the same, as they are always from source code, and without any real packaging grouping them other than the block name.  An important concept of blocks, is that not all cells (files) within a block are to be reused together, if you need a certain cell of a block and such cell does not depend on anything else, only that cell will be retrieved and reused.

**Circular dependencies between blocks are not allowed**, as usually happens in other existing systems. If the cells (files) of a block "A" depends on the cells of block "B"; the cells of block "B" cannot depend on cells belonging to block "A".


Cell
^^^^

A cell is the basic biicode processing and reuse unit. It is basically each file together with its metadata. 

Lets say the honey is the source code you put inside each one of your source files, and the cell structure is the metadata that relates such source file with the others. Actually, cells can be of any type (text, data, images), not just source code. In your code you can make references (includes, import) to your cells or cells from any other user. You just care about producing the honey, biicode will try to care for the rest.



Basic layout
^^^^^^^^^^^^^^

Layout for user *user*: ::

	workspace
	| - bii (default configuration files)
	| - hive1
		 | - bii (configuration files for this hive)
		 | - src
			  | - user
			  |    - block1
			  |        | - bii (configuration files for this block)
			  |        | - file.h (you put your code for block1 here)
			  | - user2 (only in case of editing other user blocks)
		 | - dep
			  | - user3
			  |    - block3			  
			  | - user (you can also reuse your own code!)
			  |    - block2			  



