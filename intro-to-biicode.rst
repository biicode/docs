Introduction
============

What is biicode
---------------

Biicode is a new dependencies manager for Software developers, with many unique characteristics:

* It is **simple**. Everybody should be able to seamless integrate and reuse anybody else source code, quickly.
* Reuse of existing code is always done from source code. If required by the language (as C++) artifacts like libraries are built locally.
* Dependencies are always managed at the file level. No libraries, no packaging. If you need to reuse some files from previously developed code, just the required files, together with its transitive dependencies are integrated in your project.
* It also manages updates. You can easily upgrade your dependencies if new compatible versions that match your preferences are published.
* It is fully deterministic, the joint compatible configuration of libraries is computed.
* Multilanguage, multi OS. The work flow, the tool, the way you reuse code is exactly the same independently of the programming language or the OS you are using. Currently we are working mainly for C/C++, but we have many other languages in the pipeline.
* Biicode is not just for reusing other's source code! Publishing your code is also very simple, so you can easily share with others and reuse your code in all your projects.
* Dependencies deduced from source code. Just code as usual, write your #includes or imports in your source files. No need to explicitely write them in other files. Biicode scans your source files, and extract relationships between those files.
* Configurable: you can define (if desired) manually in configuration files many things: from dependencies and connections between your files, the policies to find new dependencies, or the rules to be applied while building.
* Highly automated. Based in just your source files, we are able to create projects and build scripts. For example in C++, we automatically create a CMakeLists.txt file with the configuration required to build your project.

Biicode BETA
------------

Biicode is now in an early Beta stage, we currently accept new users by invitation only and slowly, as we have many users that are giving us a lot of feedback that we have to process and further improve the usability of the system. Sorry if we cannot provide or response quickly to your invitation request, we are doing our best to quickly attend our current users feedback.

Biicode has many core innovations, and we are following the lean startup and MVP paradigms, we try to release very often and quickly and iterate quickly on user feedback. But this also means that much functionality you could expect is not as intuitive as you would desire, and errors and failures could arise often, specially on last features. Some things and features are probably on their way, maybe even implemented but not yet properly documented. Also, expect commands, processes and the like to change in the short term.

What problem does it solve?
---------------------------

We have proposed a C++ challenge in https://github.com/biicode/challenge, some source files that have to be built and run (both the application and the test).

These source files have dependencies to 3 well known open source libraries, which are quite simple to integrate in any project:

* Eigen http://eigen.tuxfamily.org is headers-only
* CSparse  http://www.cise.ufl.edu/research/sparse/CSparse/ is very simple, just a .h and some .c files
* Google GTest https://code.google.com/p/googletest/ is also very portable, independent and prepared to be integrated in other projects.

The challenge consists in doing the task, from sources, in Win, Linux and Mac with the same setup.

Try it yourself and then solve the problem with biicode! (proceed to Install and Get Started)


Some basic concepts
-------------------

Before getting your hands dirty you might want to learn a few basic concepts and how biicode sees the (development) world.

Cell
^^^^

A cell is the basic biicode processing and sharing unit. It corresponds to your files and it holds relevant metadata. 

Lets say the honey is the source code you put inside each one of your source files, and the cell structure is the metadata that relates such source file with the others. Actually, cells can be of any type (text, data, images), not just source code. In your code you can make references (includes, import) to your cells or cells from any other user. You just care about producing the honey, biicode will try to care for the rest.

.. comment
	.. image:: _static/img/test.png

Block
^^^^^

A block is a group of cells that are logically related and probably cooperate to perform some functions, or are just grouped according to some criteria. It’s a similar concept to C libraries, java packages or python packages and modules, but not exactly the same, as they are always from source code, and without any real packaging grouping them other than the block name. Cells belonging to published blocks can be reused pretty straightforwardly, just referencing them from other cells. A very important concept of blocks, is that not all cells within a block are to be reused together, if you need a certain cell of a block and such cell does not depend on anything else, only that cell will be retrieved and used. Published cells and blocks are stored in biicode cloud

Circular dependencies between blocks are not allowed, as usually happens in other existing systems. If the cells of a block A depends on the cells of block B; the cells of block B cannot depend on cells belonging to block A.

Hive
^^^^

The hive is very similar to a conventional "project". It is a folder inside your workspace in which you edit, build and run your code; a sandbox where you can play around with your code before sharing it. You can have as many hives as you want, they are private and you can save them in the cloud for later. Biicode is not a version control system, so you can use git, mercurial, svn or whatever you prefer along with biicode if you want a version control of your hives files.

Workspace
^^^^^^^^^

This is a special folder in your system that will hold your code, the code you depend on, your executables and buildscripts as well as biicode metadata. The concept is pretty much the same as in IDEs. Once created, you’ll perform the rest of tasks from within there