
.. _bii_deps_command:

``bii deps``: show block dependencies
--------------------------------------

This command allows you to check the dependencies of any project. It's basic form, with no parameters, provides two pieces of information, giving you a general idea of which are your code dependencies. You can use several arguments and filters.

bii deps
^^^^^^^^^^

It shows the files that your blocks depend on (with block versions where they are located), and, system and unresolved dependencies respectively.

.. code-block:: bash

	$ bii deps
	phil/math depends on:
	    phil/math_lib: 4
	        algorithm.h
	        lib.h
	    system:
	        iostream
	    unresolved:
	        fake_lib.h
	phil/hello_world depends on:
	    system:
	        stdio

If you'd wish to see only one block, simply choose it:

.. code-block:: bash
	
	$ bii deps phil/hello_world
	phil/hello_world depends on:
	    system:
	       stdio



bii deps --detail
^^^^^^^^^^^^^^^^^^^^^^^^

It's so similar to *bii deps* but it shows the origin files where the dependencies are used.

.. code-block:: bash

	$ bii deps --detail
	phil/math_example depends on:
	    phil/math_lib: 4
	        algorithm.h
	            phil/math/main.cpp
	        lib.h
	            phil/math/main.cpp
	        system:
	            iostream
	                phil/math/main.cpp
	        unresolved:
	            fake_lib.h
	                phil/math/main.cpp
	phil/hello_world depends on:
	    system:
	        stdio
	            phil/hello_world/hello.cpp


bii deps --detail [FILTER]
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can enter a filter, i.e., you could see only a file or a dependency with its origins

.. code-block:: bash

	$ bii deps --detail fake_lib.h
	phil/math_example depends on:
	    phil/math_lib: 4
	    system:
	    unresolved:
	        fake_lib.h
	            phil/math/main.cpp
	phil/hello_world depends on:
	    system:

		 
bii deps --files
^^^^^^^^^^^^^^^^^^

It's used to know all the block files (and their types) and their dependencies.

.. code-block:: bash

	$ bii deps --files
	phil/math_example
	    CMakeLists.txt [TEXT]
	    bii/requirements.bii [TEXT]
	    phil/math/main.cpp [CPP][M]
	        phil/math_lib/algorithm.h (E)
	        phil/math_lib/adafruit_sensor.h (E)
	        iostream (S)
	        fake_lib.h (U)
	phil/hello_world
	    CMakeLists.txt [TEXT]
	    phil/hello_world/hello.cpp [CPP][M]
	        stdio (S)

.. container:: infonote
	
	Type of dependency tags:
		* E: explicit file
		* I: implicit file
		* D: data file
		* S: system file
		* U: unresolved file
		

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_