.. _cpp_dependencies:

Manage your dependencies
=========================

Depending on a lib on biicode
---------------------------------
Search the library you want on biicode and depend on it:

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


.. container:: infonote

    Here's more on this :ref:`Box2D example project <box2d>`.


Execute :ref:`bii find command <bii_find_command>` to retrieve dependencies:

.. code-block:: bash

	$ bii find

and your ``requirements.bii`` will look like this:

.. code-block:: text

	# This file contains your block external dependencies references
	erincatto/box2d: 10


That's because :underline:`myuser/box2d_example` depends on ``ericatto/box2d`` block ``version number 4``.

.. container:: infonote

 	* Here's more information about :ref:`requirements.bii <requirements_bii>`.


Modifying the version you depend on
------------------------------------

Manually edit your requirements.bii to depend on any version you want. For example, on Erin Catto's Box2D:
 
* ``Box2D v 2.3.1`` is available on ``erincatto/box2d version 10``
* ``Box2D v 2.3.0`` is available on ``erincatto/box2d version 8``

Biicode takes by default the latest version available.  To change it, just write the one you want on your ``requirements.bii``:

.. code-block:: text

	erincatto/box2d: 8

|
Execute ``bii work`` command, once modified your ``requirements.bii`` to update a specific block version: 

.. code-block:: bash

	$ bii work

And you'll see the new dependencies retrieved in your ``deps folder``.

.. container:: infonote

	Careful, editing your dependencies can lead you to incompatibilities.


.. _override_deps:

Override a dependency
----------------------

Let's say you depend on: 

* ``erincatto/box2d:10`` that depends on ``diego/glfw:0``. 
|
And you'd rather depend on:

*  ``erincatto/box2d:10`` and ``diego/glfw:1``. 
|
Write your preferred versions on your ``requirements.bii`` and biicode will use those versions on your project: 

.. code-block:: text

	# This file contains your block external dependencies references
	erincatto/box2d: 10
	diego/glfw:1

Checking dependencies
----------------------
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


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

