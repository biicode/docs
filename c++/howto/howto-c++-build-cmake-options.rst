.. _build_cmake_options:

Build projects with different CMake options
============================================

You can build your projects with the parameters, depending on your OS, that CMake offers us.

.. code-block:: bash

	$ cmake --build
	Usage: cmake --build <dir> [options] [-- [native-options]]
	Options:
		...

Now, using biicode, for example:

.. code-block:: bash

	$ bii cpp:build --use-stderr

