.. _bii_deps_command:

**bii deps**: show block dependencies
-------------------------------------

**bii deps** checks your project's dependencies. It gives a general idea of which are your code's depenencies. You can use several arguments and filters.

.. code-block:: bash

	$ bii deps


bii deps 
^^^^^^^^
Show the files your blocks depend on (with their corresponding blocks and versions), also shows system and unresolved dependencies:

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

Include the name of an specific block to see only that block's dependencies:

.. code-block:: bash
	
	$ bii deps phil/hello_world
	phil/hello_world depends on:
	    system:
	       stdio



bii deps --detail
^^^^^^^^^^^^^^^^^

Use **bii deps --detail** but to show the origin files where dependencies are used.

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
^^^^^^^^^^^^^^^^^^^^^^^^^^

Enter a filter to see something specific. For example, you can see just a file or a dependency with its origins:

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
^^^^^^^^^^^^^^^^

Use **bii deps --files** to know all block files (together with their types) and their dependencies.

.. code-block:: bash

	$ bii deps --files
	phil/math_example
	    CMakeLists.txt [TEXT]
	    biicode.conf [TEXT]
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
	
	Type of dependency information showed in files:

		* E: explicit file
		* I: implicit file
		* D: data file
		* S: system file
		* U: unresolved file
		

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_