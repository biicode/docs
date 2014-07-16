.. _cmake_introduction:

Generated CMake files
======================


:ref:`Project Layout <project_layout>`

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

Now, using biicode, you could execute, for example:

.. code-block:: bash

	$ bii cpp:build --use-stderr



CMakeLists.txt 
---------------


biicode.cmake
--------------



bii_blockname_vars.cmake
-------------------------



Generated CMakeLists.txt
--------------------------

.. code-block:: cmake

	# This CMakeLists.txt file helps defining your block building and compiling
	#Include the main biicode macros and functions
	include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
	# Define block variables
	INIT_BIICODE_BLOCK() 

	# Manipulate here targets files, e.g.: removing or adding files depending on MacOS
	# This has to be done BEFORE target definition in ADD_BIICODE_TARGETS
	# You can add INCLUDE_DIRECTORIES here too

	# Actually create targets: EXEcutables, STATIC libraries.
	ADD_BIICODE_TARGETS()

	#Example: how to activate C++11. Uncomment one of this
	#set(CMAKE_CXX_FLAGS -std=c++11) # Win, or linux if not gcc problems
	#set(CMAKE_CXX_FLAGS -std=c++11-stdlib=libc++) # MacOS
	#set(CMAKE_CXX_FLAGS -std=c++11-Wl,--no-as-needed) # Ubuntu if gcc problems