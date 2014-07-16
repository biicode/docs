.. _build_cmake_options:

Build projects with different CMake options
============================================

You can build your projects with the parameters, depending on your OS, that CMake offers us.

.. code-block:: bash

	$ cmake --build
	Usage: cmake --build <dir> [options] [-- [native-options]]
	Options:
	  <dir>          = Project binary directory to be built.
	  --target <tgt> = Build <tgt> instead of default targets.
	  --config <cfg> = For multi-configuration tools, choose <cfg>.
	  --clean-first  = Build target 'clean' first, then build.
	                   (To clean only, use --target 'clean'.)
	  --use-stderr   = Don't merge stdout/stderr output and pass the
	                   original stdout/stderr handles to the native
	                   tool so it can use the capabilities of the
	                   calling terminal (e.g. colored output).
	  --             = Pass remaining options to the native tool.

Now, using biicode, for example:

.. code-block:: bash

	$ bii cpp:build --use-stderr