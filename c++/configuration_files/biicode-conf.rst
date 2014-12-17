.. _biicode_conf:

``biicode.conf``
================

**biicode.conf** is a configuration file to --wait for it-- configurate your biicode projects.

Place it into your block, next to your source code: ::

	|-- my_project
	|    +-- bii
	|    +-- bin
	|    +-- blocks
	|    |	  +-- myuser
	|    |    |     +-- my_block
	|    |    |  	|     |-- main.cpp   
	|    |    |  	|     |-- biicode.conf


``biicode.conf`` has 8 different sections to configure your project.


*biicode.conf example*

.. code-block:: text

		# Biicode configuration file
		[requirements]
			# Blocks and versions this block depends on e.g.
			# user/depblock1: 3
			# user2/depblock2(track) @tag
			lasote/libuv(v0.11): 0
		[parent]
			lasote/haywire: 0
		[paths]
			# Local directories to look for headers (within block)
			# /
			include
			src
		[dependencies]
			# Manual adjust file implicit dependencies, add (+), remove (-), or overwrite (=)
			# hello.h + hello_imp.cpp hello_imp2.cpp
			*.h + *.cpp
		[mains]
			# Manual adjust of files that define an executable
			# !main.cpp # Do not build executable from this file
			# main2.cpp # Build it (it doesnt have a main() function, but maybe it includes it)
		[hooks]
			# These are defined equal to [dependencies],files names matching bii*stage*hook.py
			# will be launched as python scripts at stage = {post_process, clean}
			# CMakeLists.txt + bii/my_post_process1_hook.py bii_clean_hook.py
		[includes]
			# Mapping of include patterns to external blocks
			# hello*.h: user3/depblock # includes will be processed as user3/depblock/hello*.h
			uv.h: lasote/libuv/include
		[data]
			# Manually define data files dependencies, that will be copied to bin for execution
			# By default they are copied to bin/user/block/... which should be taken into account
			# when loading from disk such data
			# image.cpp + image.jpg # code should write open("user/block/image.jpg")

.. _requirements_conf:

[requirements]
-------------------

``[requirements]`` section is fullfiled after executing ``bii find`` with the blocks and versions your block depends on.

You can manually specify the block to depend on with its corresponding version or override a dependency just writing the version you want and executing ``bii cpp:build`` after that.

**biicode.conf**

.. code-block:: text

	[requirements] 
	    # required blocks (with version)
	    erincatto/box2d: 10

Take a look at the :ref:`docs about dependencies <cpp_dependencies>` to know more.

[parent]
------------

``[parent]`` section tells you  *"who is your parent version"*, the remote version corresponding to your local block and looks like this:

Indicates the version of the remote block being edited.

**biicode.conf**

.. code-block:: text

   [parent]
      myuser/myblock: 0

It comes in handy while :ref:`publishing <cpp_publishing>` take a look at it.

.. _paths_conf:

[paths]
------------
Use ``[paths]`` sections to tell biicode in which folders it has to look for the local files specified in your `#includes`. You only need to specify this when your project has `non-file-relative #include (s)`. 

See the :ref:`complete example <complete_example_conf>`.

.. _dependencies_conf:

[dependencies]
-------------------

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


Let's see a few examples:

* ``matrix32.h`` is dependency of the ``main.cpp`` file.

**biicode.conf**

.. code-block:: text

	[dependencies]
		main.cpp + matrix32.h

* Delete ``matrix16.h`` dependency to ``main.cpp``.

**biicode.conf**

.. code-block:: text

	[dependencies]
		main.cpp - matrix16.h


* ``test.cpp`` depends on both ``example.h`` and ``LICENSE``. And ``LICENSE`` will be excluded from the compilation process.

**biicode.conf**

.. code-block:: text

	[dependencies]
		test.cpp + example.h !LICENSE


* All files with ``.cpp`` extension depend on the ``README`` file, but this dependency won't be compiled.

**biicode.conf**

.. code-block:: text

	[dependencies]

		*.cpp + !README


* ``example.h = NULL`` tells biicode that ``example.h`` has no dependencies (even if it truly has).

**biicode.conf**

.. code-block:: text

	[dependencies]
		example.h = NULL


* Both ``solver.h`` and ``type.h`` are ``calculator.cpp`` are the only dependencies of ``calculator.cpp``, overwriting any existing implicit dependencies.

**biicode.conf**

.. code-block:: text

	[dependencies]
		calculator.cpp = solver.h type.h


.. _mains_conf:

[mains]
--------

Use ``[mains]`` section to define entry points in your code. 

Biicode automatically detects entry points to your programs by examining which files contain a ``main`` function definition. But when that's not enough you can **explicitly tell biicode where are your entry points**. 

``[mains]`` has the following structure: ::

	[[!]file ]

An example:

* Write the **name of the file** you want to be the entry point.
* Exclude an entry point writing an **exclamation mark, !** before the name of the file.

**biicode.conf**

.. code-block:: text

	[mains]
		funct.cpp
		!no_main.cpp

.. _hooks_conf:

[hooks]
-------

Use ``[hooks]`` section to link to certain python scripts that will be executed, for example, before building your project. They can be used to download and install a package needed. 

These are defined like :ref:`[dependencies] <dependencies_conf>`. Files whose names match ``bii*stage*hook.py`` will be launched as python scripts at **stage = {post_process, clean}**:

**biicode.conf**

.. code-block:: text

	[hooks]
	    CMakeLists.txt + bii/my_post_process1_hook.py bii_clean_hook.py

.. _includes_conf:

[includes]
----------

Use ``[includes]`` to tell biicode a pattern whereby it should be understood by other include name to avoid change your original code include names.

An example:

You've downloaded a library which has a lot of dependencies to OpenCV C++ library (it's uploaded in 
`diego/opencv <https://www.biicode.com/diego/opencv>`_), then, how do you change all the "#include" names to the form **diego/opencv/any_header.h** or **diego/opencv/any_header.hpp** without rewriting all of them in your original code?


**biicode.conf**

.. code-block:: text

	[includes]
		opencv*.h: diego/opencv
		opencv*.hpp: diego/opencv

.. _data_conf:

[data]
--------

Use ``[data]`` to specify a link with any file (.h, .cpp, etc.) with any data one (.txt, .jpg, etc.) in your block. When it's specified and the code is built, the image'll be saved, by default, in your *project/bin/user/block* folder.

Example:

You have in your main code this line:

**main.cpp**

.. code-block:: cpp

	CImg<unsigned char> image("phil/cimg_example/lena.jpg")

Then, if you want that all'll be OK when you run your code, you should add to your configuration file:

**biicode.conf**

.. code-block:: text

    [data]
    	main.cpp + lena.jpg


.. _complete_example_conf:

Complete use case example
^^^^^^^^^^^^^^^^^^^^^^^

This is the structure of a possible block ::

	+-- myuser
	|    +-- myblock
	|    |    +-- bii
	|    |    |    |-- post_process_hook.py
	|    |    +-- library
	|    |    |    +-- include
	|    |    |    |    |-- tool.h (#include "myblock_lib.hpp")
	|    |    |    |    |-- tool.cpp
	|    |    |    +-- test
	|    |    |    |    |-- test_1.cpp (#include "tool.h")
	|    |    |    |    |-- test_2.cpp (save data in "data_values.txt" file)
	|    |    |    |    |-- data_values.txt
	|    |    |    |    |-- test_3.cpp (#include <wx/xml/xml.h>)
	|    |    |-- myblock_lib.hpp (#include <wx/wx.h>)
	|    |    |-- sample.cpp
	|    |    |-- biicode.conf
	|    |    |-- CMakeLists.txt
	|    |    |-- README.md
	|    |    |-- LICENSE


Then, you want the following configuration:

* Biicode marks as resolved the includes: ``#include "myblock_lib.hpp"`` (root directory), ``#include "myblock_lib.hpp"`` (include folder directory).
|
* Execute my ``post_process_hook.py`` when I build the project.
|
* ``test_2.cpp`` uses the data file, ``data_values.txt``.
|
* Exclude ``sample.cpp`` like entry point.
|
* Create a dependency between ``CMakeLists.txt``, ``README.md`` and ``LICENSE`` files, but the last ones'll be exclude from compilation.
|
* Specify that your block depends on ``fenix/wxwidgets`` block, version ``0`` and version tag ``v3.0.2``.
|
* Treat all the ``#include <wx/any_wxwidgets_header.h>`` as ``#include <fenix/wxwidgets/wx/any_wxwidgets_header.h>``
|
So, your configuration file would be:

**biicode.conf**

.. code-block:: text

		# Biicode configuration file
		[requirements]
			fenix/wxwidgets(v3.0.2): 0
		[parent]
			myuser/myblock: 0
		[paths]
			/
			include
		[dependencies]
			CMakeLists.txt + !README.md !LICENSE
		[mains]
			!sample.cpp
		[hooks]
			CMakeLists.txt + bii/post_process_hook.py
		[includes]
			wx*.h: fenix/wxwidgets
		[data]
			test_2.cpp + data_values.txt


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.