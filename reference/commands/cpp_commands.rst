.. _bii_cpp_tools:

C/C++ command list
================
This section summarizes the **C/C++ commands available to be used with the biicode client program**. You can see these tools if you execute:

.. code-block:: bash

	$ bii cpp -h
	...
	---------Cpp tools commands--------
	  cpp:build       Build the project (with Make, Mingw32-make or NMake)
	  cpp:configure   Configure project with cmake
	  cpp:exe         Run a binary or script, without any processing changes nor building
	  cpp:run         Runs a binary or script, processing changes and building if necessary
	  cpp:settings    Shows (initializes from default if not existing) hive settings
	  cpp:wizard      Create a default class with constructor/destructor and a main.cpp or main.c


**Note**: You need to have a cpp compiler :ref:`installed and configured <dev_tools_installation>`.

``bii cpp:configure``: Configure your project
---------------------------------------------
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

``bii cpp:settings``: Shows the hive settings
-----------------------------------------
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
----------------------------------------
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

``bii cpp:exe``: Run a binary or script
---------------------------------------
This command executes directly a created binary file. For example, if you have several binary files named *user_block_hello_pretty*, *user_block_hello* and *user_block_maths*, and the first shows in console "Hello pretty", then if you want to execute it:

.. code-block:: bash

	$ bii cpp:exe pretty

	...

	Hello pretty

**Note**: Pay attention to the executable name because you don't need to enter the full name, only the part that's different from the others.

.. _bii_cpp_wizard:

``bii cpp:wizard``: Create default classes or main files
--------------------------------------------------------

This command has several utilities. It's a very simple way to create us a default class or main.cpp/main.c for your project. You have this options to execute the command:

Without options
^^^^^^^^^^^^^^^
By default it is called to create a new default class.

.. code-block:: bash

	$ bii cpp:wizard
	Class name (default: newclass): my_lib

	Creating a new class named "my_lib"
	WARN:
	You're not in a valid block
	INFO: You can save it in a block of your choice.
	For example: 'my_block2' or 'user25/my_block4'
	Block name (default:my_block): other_block
	All files will be saved in your default directory [YOUR_HIVE]/your_user_name/other_block

	These files have been created:
		my_lib.h
		my_lib.cpp

With options
^^^^^^^^^^^^
Creating a default class into a default block:

.. code-block:: bash

	$ bii cpp:wizard --newclass my_lib

	Creating a new class named "my_lib"
	WARN:
	You're not in a valid block
	INFO: You can save it in a block of your choice.
	For example: 'my_block2' or 'user25/my_block4'
	Block name (default:my_block): [ENTER]
	All files will be saved in your default directory [YOUR_HIVE]/your_user_name/my_block

	These files have been created:
		my_lib.h
		my_lib.cpp

Creating a default main.cpp file into a new or existing block named cpp_block:

.. code-block:: bash

	$ bii cpp:wizard --newclass my_main
	INFO: Default extension file is '.cpp'. You can use '.c' extension too.

	Creating a main file "my_main.cpp"
	WARN:
	You're not in a valid block
	INFO: You can save it in a block of your choice.
	For example: 'my_block2' or 'user25/my_block4'
	Block name (default:my_block): cpp_block
	All files will be saved in your default directory [YOUR_HIVE]/your_user_name/cpp_block

	File my_main.cpp has been created in [YOUR_HIVE]/your_user_name/cpp_block/my_main.cpp


Creating a default main.c file into a new or existing block named cpp_block:

.. code-block:: bash

	$ bii cpp:wizard --newclass my_main.c

	Creating a main file "my_main.c"
	WARN:
	You're not in a valid block
	INFO: You can save it in a block of your choice.
	For example: 'my_block2' or 'user25/my_block4'
	Block name (default:my_block): cpp_block
	All files will be saved in your default directory [YOUR_HIVE]/your_user_name/cpp_block

	File my_main.c has been created in [YOUR_HIVE]/your_user_name/cpp_block/my_main.c
