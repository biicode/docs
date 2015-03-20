.. _biicode_conf:

**biicode.conf**: configure your biicode projects
=================================================

**biicode.conf** is a configuration file to --wait for it-- configure your biicode projects.

Place it into your block, next to your source code: ::

	|-- my_project/
	|    +-- bii/
	|    +-- bin/
	|    +-- blocks
	|    |	  +-- myuser
	|    |    |     +-- my_block
	|    |    |  	|     |-- main.cpp   
	|    |    |  	|     |-- biicode.conf

*biicode.conf* has 9 different sections to configure your project.

Here's a *biicode.conf* example:

.. code-block:: text

		# Biicode configuration file
		[requirements]
			# Blocks and versions this block depends on e.g.
			# user/depblock1: 3
			# user2/depblock2(track) @tag

		[parent]
		    # The parent version of this block. Must match folder name. E.g.
		    # user/block  # No version number means not published yet
		    # You can change it to publish to a different track, and change version, e.g.
		    # user/block(track): 7

		[paths]
		    # Local directories to look for headers (within block)
		    # /
		    # include

		[dependencies]
		    # Manual adjust file implicit dependencies, add (+), remove (-), or overwrite (=)
		    # hello.h + hello_imp.cpp hello_imp2.cpp
		    # *.h + *.cpp

		[mains]
		    # Manual adjust of files that define an executable
		    # !main.cpp  # Do not build executable from this file
		    # main2.cpp # Build it (it doesnt have a main() function, but maybe it includes it)

		[tests]
		    # Manual adjust of files that define a CTest test
		    # test/* pattern to evaluate this test/ folder sources like tests

		[hooks]
		    # These are defined equal to [dependencies],files names matching bii*stage*hook.py
		    # will be launched as python scripts at stage = {post_process, clean}
		    # CMakeLists.txt + bii/my_post_process1_hook.py bii_clean_hook.py

		[includes]
		    # Mapping of include patterns to external blocks
		    # hello*.h: user3/depblock  # includes will be processed as user3/depblock/hello*.h

		[data]
		    # Manually define data files dependencies, that will be copied to bin for execution
		    # By default they are copied to bin/user/block/... which should be taken into account
		    # when loading from disk such data
		    # image.cpp + image.jpg  # code should write open("user/block/image.jpg")

.. _requirements_conf:

[requirements]
-------------------

``[requirements]`` section is fullfiled after executing **bii find** with the blocks and versions your block depends on.

You can manually specify the block to depend on with its corresponding version or override a dependency just writing the version you want and executing **bii build** after that.

.. code-block:: text

	[requirements] 
	    # required blocks (with version)
	    erincatto/box2d: 10

Take a look at the :ref:`docs about dependencies <cpp_dependencies>` to know more.

[parent]
------------

``[parent]`` section tells you  *"who is your parent version"*. Indicates the version of the remote block being edited and looks like this:

.. code-block:: text

   [parent]
        myuser/myblock: 0

This section is fullfilled automatically when publishing or opening a block and comes in handy while :ref:`publishing <cpp_publishing>` take a look at it.

.. container:: infonote

 **When publishing a new block** this section should be blank or referenced as -1 version:
 
 .. code-block:: text
    
    [parent]
        # Comments like this are ignored

 or

 .. code-block:: text
    
    [parent]
        myuser/my_new_block: -1

.. _paths_conf:

[paths]
------------
Use ``[paths]`` section to tell biicode in which folders it has to look for the local files specified in your `#includes`. You only need to specify this when your project has `non-file-relative #include (s)`. 

.. _paths-common:

Common use case example
^^^^^^^^^^^^^^^^^^^^^^^

Libraries usually have a folder structure like this one ::

|-- library
|    +-- include
|    |    |-- tool.h
|    +-- test
|    |    |-- main1.cpp (#include "tool.h")

In which main1.cpp includes: ``#include "tool.h"`` that it is truly located into */include* folder. The proper #include would be ``#include "../include/tool.h"``

If we execute **bii deps** on this example, we'll see ``#include "tool.h"`` as unresolved. Why is this happening? 
Biicode can't find the *tool.h* file unless we specify where they can find it. 

Let's fix this write into the ``[paths]`` section:


.. code-block:: text

	[paths]
		# Local directories to look for headers (within block)
		/include


Root directory example
^^^^^^^^^^^^^^^^^^^^^^

Let's imagine now that we have a folder with the following structure into it ::

|-- mylib.h
|-- mylib.cpp
|    +-- examples
|    |	  |-- main.cpp (#include "mylib.h")

If we execute **bii deps** on this example, we'll see *mylib.h* as unresolved. Why is this happening? 
Biicode, considers the ``#include(s)`` relative to their location. So if there isn't a root folder they can refer to, when looking for *mylib.h* they will search it in the *examples* folder and they won't be able to find it.

What should we write on the ``[paths]`` section?


.. code-block:: text

	[paths]
		# Local directories to look for headers (within block)
		/


Write ``/`` in ``[paths]`` section and biicode will know that it has to include the root directory on its search.

.. _dependencies_conf:

[dependencies]
-------------------
Biicode knows how the source code files connect to each other. It parses the source code files and deduces some things.
But sometimes, this mechanism can detect non existent dependencies or can fail detecting existent dependencies.

Use ``[dependencies]`` section to manually define rules to adjust file implicit dependencies. 

``[dependencies]`` rules match the following pattern:

.. code-block:: text

		#dependent_file_name [operator] NULL|[[!]dependency_file ]

The Operator establishes the meaning of each rule:

* ``-`` operator to **delete** all specified dependencies from their dependent file.
* ``+`` operator to **add** all specified dependencies to their dependent file.
* ``=`` operator to **overwrite** all specified dependencies with existing dependencies.

You can declare that a file has no dependencies using the ``NULL`` keyword.

Mark a dependency with a ``!`` symbol to declare a dependency, but **excude it from the building process**. This is sometimes used to define **license files** that must be downloaded along with your code, but shouldn't be included in the compilation process.


The ``dependent_file_name`` may be defined using **Unix filename pattern matching**.

==========	========================================
Pattern 	Meaning
==========	========================================
``*``			Matches everything
``?``			Matches a single character
``[seq]``		Matches any character in seq
``[!seq]``		Matches any character not in seq
==========	========================================

Examples
^^^^^^^^

Let's see a few examples:

* *matrix32.h* is dependency of the *main.cpp* file.

.. code-block:: text

	[dependencies]
	    main.cpp + matrix32.h


* Delete *matrix16.h* dependency to *main.cpp*.


.. code-block:: text

	[dependencies]
	    main.cpp - matrix16.h


* *test.cpp* depends on both *example.h* and *LICENSE*. And *LICENSE* will be excluded from the compilation process.


.. code-block:: text

	[dependencies]
	    test.cpp + example.h !LICENSE


* All files with *.cpp* extension depend on the *README* file, but this dependency won't be compiled.


.. code-block:: text

	[dependencies]
	     *.cpp + !README


* ``example.h = NULL`` tells biicode that *example.h* has no dependencies (even if it truly has).


.. code-block:: text

	[dependencies]
         example.h = NULL


* Both *solver.h* and *type.h* are the only dependencies of *calculator.cpp*, overwriting any existing implicit dependencies.


.. code-block:: text

	[dependencies]
	    calculator.cpp = solver.h type.h


.. _mains_conf:

[mains]
--------

Use ``[mains]`` section to define entry points in your code. 

Biicode automatically detects entry points to your programs by examining which files contain a **main function** definition. But when that's not enough you can **explicitly tell biicode where are your entry points**. 

``[mains]`` has the following structure: ::

	[[!]file ]

An example:

* Write the **name of the file** you want to be the entry point.
* Exclude an entry point writing an **exclamation mark, !** before the name of the file.


.. code-block:: text

	[mains]
		funct.cpp
		!no_main.cpp

.. _test_conf:

[tests]
-------

Tests section is useful to define specific tests for your code. Adjust files manually that define a CTest test.

Indicate the patter to your test files:

.. code-block:: text
 
 [tests]
     test/*
     test/simple_test.cpp

Those test are excluded from the normal building and are built and executed only when doing :ref:`bii test<bii_test_command>`.

.. _hooks_conf:

[hooks]
-------

Use ``[hooks]`` section to link to certain python scripts that will be executed, for example, before building your project. They can be used to download and install a package needed. 

This scripts have ".py" extension and name matches:

+ ``bii*post_process*hook.py``: For scripts that will be launched before project building (**bii build** or **bii configure**)
+ ``bii*clean*hook.py``: For scripts that will be launched before a **bii clean** command.

These are defined like :ref:`[dependencies] <dependencies_conf>`. 

In the following example we define that *CMakeLists.txt* depends on two hooks:

.. code-block:: text

	[hooks]
	    CMakeLists.txt + bii/my_post_process1_hook.py bii_clean_hook.pyw

Use ``bii`` variable inside hook scripts to:

+ Print text:

.. code-block:: textg

	bii.out.debug("error_msg")
	bii.out.info("error_msg")
	bii.out.warn("error_msg")
	bii.out.error("error_msg")


+ Download files:

.. code-block:: text

	bii.download(url, tmp_path)


+ Read your project settings:

.. code-block:: text
	
	bii.settings.cpp.cross_build


Check an example in this block: |maria_bitscope|.


[includes]
----------


Enables mapping include patterns to external blocks.

+ For example you can tell biicode: Whenever you read ``uv.h`` in my code, it means ``lasote/libuv/include/uv.h``:


.. code-block:: text

	[requirements]
	    lasote/libuv(v1.0): 0

	[includes]
	    uv.h: lasote/libuv/include 

In the previous example, the [requirements] section has a line specifying a dependency to ``lasote/libuv(v1.0): 0`` version, so, lasote/libuv #includes will be matched against these block.


+ You can also specify complex patterns. To process ``hello*.h`` #includes as ``user3/depblock/hello*.h``


.. code-block:: text

	[includes]
	    hello*.h: user3/depblock  

This is pretty useful when using already existing libraries and you don't want to change all the includes.


[data]
--------
Use ``[data]`` to specify a link with any file (.h, .cpp, ...) with any data (.txt, .jpg, ...) in your block.

Once ``[data]`` section is specified and the code is built (**bii build**), the data files will be saved, by default, in your *project/bin/user/block* folder.

**Example:**

You have in your main code this line:

*main.cpp*

.. code-block:: cpp

	CImg<unsigned char> image("phil/cimg_example/lena.jpg")


Then, add to your configuration file:


.. code-block:: text

	[data]
	    main.cpp + lena.jpg


This will copy *lena.jpg* to *project/bin/user/block/* when *main.cpp* is built.


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.


.. |maria_bitscope| raw:: html

   <a href="https://www.biicode.com/Maria/bitscope" target="_blank">Maria/bitscope</a>


