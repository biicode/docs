.. _cmake_introduction:

Generated CMake files
======================

To understand the generated CMake files, assume that your user name is **maya**, the project is called **myproject**, and the block's name is **hello**. 
To create and generate this project, just execute this commands in your console:

.. code-block:: bash

	$ bii init myproject
	$ cd myproject
	~/myproject$ bii new maya/hello --hello cpp
	~/myproject$ bii cpp:build


Then your layout is: ::

	|-- myproject
	|    +-- bin
	|    +-- blocks
	|    |	  +-- maya
	|    |         +-- hello (block maya/hello)
	|    |       	    |-- CMakeLists.txt
	|    |              +-- main.cpp
	|    +-- build
	|    +-- cmake
	|    |    |-- CMakeLists.txt
	|    |    |-- biicode.cmake
	|    |    +-- bii_maya_hello_vars.cmake


The ``cmake folder`` is created whenever you execute ``bii cpp:build``.

If you have any doubts about this, take a look at a :ref:`biicode project layout <project_layout>`

Keep reading to take a look into a ``cmake folder``'s content.

General CMakeLists.txt 
-----------------------

**CMakeLists.txt** is a flat file into your ``cmake folder``. It has all the things needed to create your project (depending on which configuration you select). With the layout above, the generated CMakeLists.txt is like this:

.. code-block:: cmake

	PROJECT( maya )
	cmake_minimum_required(VERSION 2.8)

	# inclusion of general biicode macros, biicode.cmake 
	set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake")
	INCLUDE(biicode.cmake) 

	#artifact to allow upstream configurations
	BII_PREBUILD_STEP(blocks/maya/hello)

	# Inclusion of the blocks affected by the build
	BII_INCLUDE_BLOCK(blocks/maya/hello)

biicode.cmake
--------------

This file has CMake macros and functions so you can use your own **CMakelists** in your blocks. 

bii_block_name_vars.cmake
-------------------------

This CMake file has the following information: target name, source, header, resource and data files, block dependencies, etc.

In our example, this is the ``bii_maya_hello_vars.cmake``:

.. code-block:: cmake

	#target enumeration
	#create this var to create the lib target with BII_jpeg_jpeg_SRC and BII_jpeg_jpeg_DEPS
	SET(BII_maya_hello_LIB False )
	#target list without the block lib
	SET(BII_maya_hello_TARGETS main)
	#FILES RETRIEVED FROM BIICODE #####################################
	#BLOCK maya_hello_main ##################################################

	SET(BII_maya_hello_main_SRC main.cpp)
	SET(BII_maya_hello_main_DATA_FILES  )
	SET(BII_maya_hello_main_RESOURCES )
	SET(BII_maya_hello_main_BLOCK_DEPS )
	SET(BII_maya_hello_main_SYSTEM_DEPS )
	SET(BII_maya_hello_main_INTERFACE_LIB False)


Block CMakeLists.txt 
----------------------

Whenever you execute the ``bii cpp:build`` command in your project, if there is no **CMakeLists.txt** in your existing blocks, biicode creates one automatically:

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

You can edit **CMakeLists.txt** as you want. In the following sections, we explain some examples about how to edit this file and an advanced use of it.