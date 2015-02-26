.. _cpp_dependencies:

Manage your dependencies
=========================

Learn how to get the dependencies your project needs and how to handle their versions.


Dependencies
------------
The :ref:`getting started guide<cpp_getting_started>` explained basics on depending. To recall, these are the steps to depend on a library available in biicode:

* Search the library you want on biicode.

* Write the include line in your source code:

	.. code-block:: cpp
	    :emphasize-lines: 1

	   	    #include "erincatto/box2d/Box2D/Box2D.h"


	In a project like this one: ::

		|-- my_project
		|    +-- bii
		|    +-- bin
		|    +-- blocks
		|    |	  +-- myuser
		|    |    |     +-- box2d_example
		|    |    |  	|     |-- main.cpp   --->  #include "erincatto/box2d/Box2D/Box2D.h"
		|    |    |  	|     |-- biicode.conf


	.. container:: infonote

	    Here's more on this :ref:`Box2D example project <box2d>`.


* Execute :ref:`bii find command <bii_find_command>` to retrieve dependencies:

	.. code-block:: bash

		$ bii find

	And ``biicode.conf`` file is updated: 

	.. code-block:: text

		[requirements] 
		    # required blocks (with version)
			erincatto/box2d: 10


	That's because :underline:`myuser/box2d_example` depends on ``ericatto/box2d`` block ``version number 10``.

.. container:: infonote

 	* Here's more information about :ref:`requirements<requirements_conf>`.


Modifying the version you depend on
------------------------------------

Manually edit your **biicode.conf** file to depend on any version you want. For example, on Erin Catto's Box2D:
 
* ``Box2D v 2.3.1`` is available on ``erincatto/box2d version 10``

* ``Box2D v 2.3.0`` is available on ``erincatto/box2d version 8``

Biicode takes by default the latest version available.  To change it, just write the one you want in your ***biicode.conf**:

.. code-block:: text

	[requirements] 
		# required blocks (with version)
		erincatto/box2d: 8

|

Execute ``bii work`` command, once modified, to update a specific block version: 

.. code-block:: bash

	$ bii work

And you'll see the new dependencies retrieved in your ``deps folder``.


Checking dependencies
---------------------
 
Execute ``bii deps`` to get all information related to biicode’s dependency scanning. It shows all dependencies, system, local and biicode's.

.. code-block:: bash

	$ bii deps
	INFO: Processing changes...
	erincatto/box2d depends on:
       diego/glfw: 0
          include/GLFW/glfw3.h
       system:
          GL/gl.h
          GL/glu.h
          OpenGL/glu.h
          algorithm
          assert.h
          float.h
          inttypes.h
          limits.h
          math.h


``bii deps --detail`` comes in handy to locate unresolved dependencies. 

.. code-block:: bash

	$ bii deps --detail
	INFO: Processing changes...
	erincatto/box2d depends on:
	       diego/glfw: 0
	          include/GLFW/glfw3.h
	                Testbed/Framework/DebugDraw.cpp (E)
	                Testbed/Framework/Main.cpp (E)
	                Testbed/Framework/Test.h (E)
	       erincatto/box2d (self)
	          Box2D/Box2D.h
	                HelloWorld/HelloWorld.cpp (E)
	                Testbed/Framework/DebugDraw.h (E)
	                Testbed/Framework/Test.h (E)
	          Box2D/Collision/Shapes/b2ChainShape.cpp
	                Box2D/Collision/Shapes/b2ChainShape.h (I)
	       ...


``bii deps --files`` let's you check the dependant files extension.

.. code-block:: bash

	$ bii deps --files
	INFO: Processing changes...
	erincatto/box2d
	       Box2D/Box2D.h [CPP]
	           erincatto/box2d/Box2D/Collision/Shapes/b2ChainShape.h (E)
	           erincatto/box2d/Box2D/Collision/Shapes/b2CircleShape.h (E)
	           erincatto/box2d/Box2D/Collision/Shapes/b2EdgeShape.h (E)
	           erincatto/box2d/Box2D/Collision/Shapes/b2PolygonShape.h (E)
	           erincatto/box2d/Box2D/Collision/b2BroadPhase.h (E)
	       ...
	       Box2D/Box2DConfig.cmake.in [TEXT]
	       Box2D/CMakeLists.txt [TEXT]
	       Box2D/Collision/Shapes/b2ChainShape.cpp [CPP]
	           erincatto/box2d/Box2D/Collision/Shapes/b2ChainShape.h (E)
	           erincatto/box2d/Box2D/Collision/Shapes/b2EdgeShape.h (E)
	           new (S)
	           string.h (S)
	       ...

.. container:: infonote

 	* Here's more information about :ref:`bii deps command<bii_deps_command>`.


Depending on a block track
---------------------------

**Block Tracks** are different development *versions* of a block using the same block name-space. This way, you can switch between different development versions or **block tracks**, keeping the same *#includes* in your source code. Let's see an example with **libuv library**. 

Currently, **libuv** keeps 3 mantained versions or **block tracks**:

		* |libuv_0_10| (Stable, used by Nodejs)

		* |libuv_0_11| (Non stable, but commonly used)

		* |libuv_1_0| (Made stable few days ago)

Depend on one or another to fit your needs:

* Write this *#include line* in your source code:

	.. code-block:: cpp
	    :emphasize-lines: 1

	   	#include "lasote/libuv/include/uv.h"


* And depend on |libuv_0_11|, write in your **biicode.conf** file ``[requirements]`` :

	*biicode.conf*

	.. code-block:: text

		[requirements] 
			# required blocks (with version)
			lasote/libuv(v0.11): 1

* Execute ``bii cpp:build`` and you're ready to go. 

Let's switch to |libuv_1_0|:

* Modify ``[requirements]`` section :

	*biicode.conf*

	.. code-block:: text

		[requirements]
			# required blocks (with version)
			lasote/libuv(v1.0): 0

* Execute ``bii cpp:build`` and it's switched.

And now, switch to |libuv_0_10|:

* Modify ``[requirements]`` section :

	*biicode.conf*

	.. code-block:: text

		[requirements] 
			# required blocks (with version)
			lasote/libuv(v0.10): 1

* Execute ``bii cpp:build`` and it's switched.

.. _tag_dependencies:

Depending on a tagged version
-----------------------------
Use a specific block version using just its version tag. Write in your **biicode.conf** file ``[requirements]``:
*biicode.conf*

.. code-block:: text

	[requirements] 
		# required blocks (with version)
		Maria/oscpack @v1.1.0

Execute ``bii cpp:build`` and biicode will retrieve the latest version with that tag and update the ``[requirements]`` section:

*biicode.conf*


.. code-block:: text

	[requirements] 
		# required blocks (with version)
		Maria/oscpack: 0 @v1.1.0


.. _override_deps:

Override a dependency
----------------------

Let's say you depend on: 

* ``erincatto/box2d:10`` that depends on ``diego/glfw:0``. 

|

And you'd rather depend on:

*  ``erincatto/box2d:10`` and ``diego/glfw:1``. 

|

Write your preferred versions in your **biicode.conf** and biicode will use those versions in your project: 

.. code-block:: text

	[requirements] 
		# required blocks (with version)
		erincatto/box2d: 10
		diego/glfw:1

Execute ``bii cpp:build`` and it's updated.


Override a dependency with block tracks
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Create a block track when you need a personalized fix over the original library**.

Let's create a block track from **diego/glfw** block:

* Open the block:

.. code-block:: bash

	~$ bii init myproject
	~$ cd myproject
	~/myproject$ bii open diego/glfw

* Code, adjust it to your needs.

* Write the track name between brackets in the ``[parent]`` section of the **biicode.conf** file. Specify ``version -1`` because we want create a new block. 

*biicode.conf*

.. code-block:: text

	[parent]
  		diego/glfw(myuser/glfw): -1

* Execute ``bii publish`` and enter your profile *www.biicode.com/myuser* to check the new track. 

**Depend on that new block track:**

* Write in your **biicode.conf** file ``[requirements]`` :

		*biicode.conf*

		.. code-block:: text

			[requirements] 
				# required blocks (with version)
				diego/glfw(myuser/glfw): 1

* Execute ``bii cpp:build`` and it's updated.

.. container:: infonote

    What if you want to get back again to the original library? 
    	
    * Write in your **biicode.conf** file ``[requirements]`` :

	    .. code-block:: text

		    [requirements] 
		        # required blocks (with version)
			    diego/glfw: 0
		
    * Execute ``bii cpp:build`` and it's updated.

**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

.. |libuv_0_11| raw:: html

   <a href="http://www.biicode.com/lasote/lasote/libuv/v0.11" target="_blank"><strong>Libuv library v0.11</strong></a>

.. |libuv_0_10| raw:: html

   <a href="http://www.biicode.com/lasote/lasote/libuv/v0.10" target="_blank"><strong>Libuv libary v0.10</strong></a>

.. |libuv_1_0| raw:: html

   <a href="http://www.biicode.com/lasote/lasote/libuv/v1.0" target="_blank"><strong>Libuv library v1.0</strong></a>