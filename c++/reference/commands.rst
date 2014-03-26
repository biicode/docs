.. _bii_cpp_tools:

Commands list
=============

This section summarizes the **C/C++ commands available to be used with the biicode client program**. You can see these tools if you execute:

.. code-block:: bash

	$ bii cpp -h
	...
	---------Cpp tools commands--------
	  cpp:build       Build the project (with Make, Mingw32-make or NMake)
	  cpp:configure   Configure project with cmake
	  cpp:run         Runs a binary or script, processing changes and building if necessary
	  cpp:settings    Shows (initializes from default if not existing) hive settings
	  cpp:wizard      Create a default class with constructor/destructor and a main.cpp or main.c


**Note**: You need to have a cpp compiler :ref:`installed and configured <cpp_installation>`.

``bii cpp:configure``: Configure your project
----------------------------------------------

If you have configured your hive as a C/C++ project and you want to develop in cpp language, this command helps you! Enter it and configure your hive like an cpp project. It invokes cpp compiler and you are ready to start with your cpp.

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
	-- Build files have been written to: [YOUR_BII_WORKSPACE/YOUR_HIVE]/build


.. _bii_cpp_settings:

``bii cpp:settings``: Managing your hive settings
-------------------------------------------------

This command shows your settings about cpp or initializes the settings from default workspace settings in your hive if they are missing.

.. code-block:: bash

	$ bii cpp:settings
	INFO: These are your cpp settings for this hive
	INFO: build_type: Debug
	builder: {family: MINGW}
	compiler: {arch: 32bit, family: MINGW}
	configurer: {family: CMake}

	INFO: If you want to change it, you have to modify this file:
		[YOUR_BII_WORKSPACE/YOUR_HIVE]/bii/settings.bii


``bii cpp:run``: Process, build and run
---------------------------------------

You can process, build and run a main file with this command. This command is responsible for making the executable if your code is correct.

.. code-block:: bash

	$ bii cpp:run
	
``bii cpp:build``: Build the project
------------------------------------

This command invokes the C++ compiler to build your project.

.. code-block:: bash

	$ bii cpp:build
	
	...
	
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

	...

	[100%] Built target your_user_name_block_cpp_block
