.. _cmake_introduction:

Generated CMake files
======================

To understand this section, then execute this commands in your console:

.. code-block:: bash

	$ bii init myproject
	$ cd myproject
	~/myproject$ bii new maya/hello --hello cpp
	~/myproject$ bii cpp:build


So let's assume for these example that your user name is **maya**, the project is called **myproject**, and the block name in this case is **hello**. Then your layout will be ::

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


If you have any doubt about this, take a look to :ref:`biicode project layout <project_layout>`


General CMakeLists.txt 
-----------------------

This CMakeLists.txt is that you can find in your ``cmake folder``. It has all the necessary to create your project (depending on the selected configuration). With above layout, the generated CMakeLists.txt would be so:

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

This file has CMake macros and functions to make possible the use of your own CMakelists created in your blocks. 

bii_block_name_vars.cmake
-------------------------

This CMake file has the information (target name, source, header, resource and data files, block dependencies, etc.)

In this case, the ``bii_maya_hello_vars.cmake`` could be like this:

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

When you execute the ``bii cpp:build`` command in your project, if you haven't any CMakeLists.txt created inside your existing blocks, biicode creates automatically one. Here an example:

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

This CMakeLists.txt can be edited and replaced with the code you want. Into the following sections, we explain you some examples about how to edit this file and an advanced use of this.