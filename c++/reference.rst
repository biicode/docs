.. _bii_cpp_tools:

Reference
============

This section summarizes the **C/C++ commands available to be used with the biicode client program**. You can see these the full list of commands for C/C++ language as follows:

.. code-block:: bash

	$ bii -h cpp
	
	SYNOPSIS:
	    $ bii COMMAND [options]
	For help about a command:
	    $ bii COMMAND --help
	To change verbosity, use options --quiet --verbose

	---------C/C++ commands--------
	  cpp:build       Build the project (with Make, Mingw32-make or NMake)
	  cpp:configure   Configure project with cmake



``bii cpp:configure``: configure your project
---------------------------------------------

This command configures your project as a C/C++ project automatically and adding the characteristics of your CMake files if you have it.

.. code-block:: bash

	$ bii cpp:configure

	invoking cmake -D CMAKE_BUILD_TYPE=Debug  -G "MinGW Makefiles" -Wno-dev ../cmake
	-- The C compiler identification is GNU 4.8.1
	-- The CXX compiler identification is GNU 4.8.1
	-- Check for working C compiler: C:/MinGW/bin/gcc.exe
	-- Check for working C compiler: C:/MinGW/bin/gcc.exe -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Check for working CXX compiler: C:/MinGW/bin/g++.exe
	-- Check for working CXX compiler: C:/MinGW/bin/g++.exe -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Configuring done
	-- Generating done
	-- Build files have been written to: [YOUR_BII_WORKSPACE/YOUR_PROJECT]/build


.. _cmake_generator:

Configure your CMake Generator
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This section explains how to configure your CMake generator, just execute:

.. code-block:: bash

	$ bii cpp:configure -G "CMake generator"


Useful operations
~~~~~~~~~~~~~~~~~

To see the full list of CMake generators available in your system, execute this:

.. code-block:: bash

	$ cmake --help


For example, to use Visual Studio 2010 for projects in Windows you should write:

.. code-block:: bash

	$ bii cpp:configure -G "Visual Studio 10"


If you got any questions left, you can ask them at our `forum <http://forum.biicode.com/>`_.


``bii cpp:build``: build your project
-------------------------------------

This command invokes the C++ compiler to build your project.

.. code-block:: bash

	$ bii cpp:build
	
	invoking cmake -D CMAKE_BUILD_TYPE=Debug  -G "MinGW Makefiles" -Wno-dev ../cmake
	-- The C compiler identification is GNU 4.8.1
	-- The CXX compiler identification is GNU 4.8.1
	-- Check for working C compiler: C:/MinGW/bin/gcc.exe
	-- Check for working C compiler: C:/MinGW/bin/gcc.exe -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Check for working CXX compiler: C:/MinGW/bin/g++.exe
	-- Check for working CXX compiler: C:/MinGW/bin/g++.exe -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done


	[100%] Built target your_user_name_block_cpp_block

Visit the section: :ref:`how to build a project with different CMake options <build_cmake_options>`
