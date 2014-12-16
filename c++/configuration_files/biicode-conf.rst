.. _biicode_conf:

``biicode.conf``
================

**biicode.conf** is configuration file to --wait for it-- configurate your biicode projects.

Place it into your block, next to your source code: ::

	|-- my_project
	|    +-- bii
	|    +-- bin
	|    +-- blocks
	|    |	  +-- myuser
	|    |    |     +-- my_block
	|    |    |  	|     |-- main.cpp   
	|    |    |  	|     |-- biicode.conf


``biicode.conf`` can have 8 different sections to configure your project.


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
			# *.h + *.cpp
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

``[requirements]``
-------------------

``[requirements]`` section is fullfiled after executing ``bii find`` with the blocks and versions your block depends on.

You can manually specify the block to depend on with its corresponding version or override a dependency just writing the version you want and executing ``bii cpp:build`` after that.

``biicode.conf``

.. code-block:: text

	[requirements] 
	    # required blocks (with version)
		erincatto/box2d: 10

Take a look at the :ref:`docs about dependencies <cpp_dependencies>` to know more.

``[parent]``
------------

``[parent]`` section tells you  *"who is your parent version"*, the latest published version from your local block and looks like this:

.. code-block:: text

   [parent]
      myuser/myblock: 0

It comes in handy while :ref:`publishing <cpp_publishing>` take a look at it.

``[paths]``
------------
Use ``[paths]`` sections to tell biicode in which folders it has to look for the local files specified in your `#includes`. You only need to specify this when your project has `non-file-relative #include (s)`. 

.. _paths-common:

Common use case example
^^^^^^^^^^^^^^^^^^^^^^^

Libraries usually have a folder structure like this one ::

|-- library
|    +-- include
|    |    |-- tool.h
|    +-- test
|    |    |-- main1.cpp (#include "tool.h")

In which main1.cpp includes: ``#include "tool.h"`` that it is truly located into **/include** folder. The proper #include would be ``#include "../include/tool.h"``

If we execute ``bii deps`` on this example, we'll see ``#include "tool.h"`` as unresolved. Why is this happening? 
Biicode can't find the ``tool.h`` file unless we specify where they can find it. 

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

If we execute ``bii deps`` on this example, we'll see ``mylib.h`` as unresolved. Why is this happening? 
Biicode, considers the ``#include(s)`` relative to their location. So if there isn't a root folder they can refer to, when looking for ``mylib.h`` they will search it in the ``examples`` folder and they won't be able to find it.

What should we write on the ``paths.bii`` file?

.. code-block:: text

	[paths]
		# Local directories to look for headers (within block)
		/


Write ``/`` in ``paths`` section and biicode will know that it has to include the root directory on its search.