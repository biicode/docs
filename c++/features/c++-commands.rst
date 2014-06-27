.. _bii_cpp_tools:

Commands list
=============

This section summarizes the **C/C++ commands available to be used with the biicode client program**. You can see these the full list of commands for C/C++ language as follows:

.. code-block:: bash

	$ bii cpp -h
	...
	---------Cpp tools commands--------
	  cpp:build       Build the project (with Make, Mingw32-make or NMake)
	  cpp:configure   Configure project with cmake
	  cpp:settings    Project settings configuration


bii cpp:configure
-----------------

This command configure your project as a C/C++ project automatically and adding the characteristics of your CMake files if you have it.

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


.. _bii_cpp_settings:

bii cpp:settings
----------------

This command helps you to configure the IDE you'll use to build your project:

	*	``visual``: **Microsoft Visual Studio** (avaliable **versions** between **6-12**, 32 and 64 bits)
	*	``eclipse``: **Eclipse IDE**
	*	``none``: you are going to work with your console

.. code-block:: bash

	$ bii cpp:settings

	Introduce ide (default:None) (/o list options): /o
	Available options:
	--------------------------
  	  eclipse
  	  visual
  	  none
	--------------------------
	Introduce ide (default:None) (/o list options): visual
	Visual version (6-12)? : 10

Just introduce your desired IDE, and your project ``settings.bii`` file will be updated in accordance.

.. container:: infonote


    **Working with Visual Studio 64 bits version**

    By default, the ``bii cpp:settings`` command selects the 32 bits version of VIsual Studio compiler. If you want to use the 64 bits version, you need to manually edit your project ``settings.bii`` file as follows:

    #. Go to ``your_project/bii/`` folder
    #. Open the ``settings.bii`` file
    #. Modify your IDE declaration line updating the ``arch`` parameter as follows, writing the ``Win64`` option:

    .. code-block:: text

    	ide: {family: visual, version: '10', arch: Win64}

	
bii cpp:build
-------------

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
