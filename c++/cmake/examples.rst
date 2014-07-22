.. _cmake_examples:

.. raw:: html

    <script>
     $(window).bind("load", function() {
         mixpanel.track("PageDoc", { "Language": "C++", "Section": "CMakeExamples" });
      });
    </script>

Examples
===============

Activate C++11
---------------------

This example shows you how to compile a simple C++11 code with the C++11 compilation flag.


Create a new project
^^^^^^^^^^^^^^^^^^^^^^

First, create a new project to follow the example

.. code-block:: bash

   ~$ bii init cpp11_project
   ~$ cd cpp11_project
   ~/cpp11_project$ 

Download the example block
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Now, :download:`download the complete example block </_static/code/cpp/cmake/cpp_11_example.zip>` and unzip it into your ``~/cpp11_project/blocks/`` folder. You can take a look at |cpp11_block_link| too.


.. |cpp11_block_link| raw:: html

   <a href="http://www.biicode.com/phil/phil/cpp_11_example/master" target="_blank">this example block in our website</a>


The layout of your project will be as follows:

.. code-block:: text

   |-- cpp11_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- phil
   |    |    |    +-- cpp_11_example
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- main.cpp
   |    +-- deps

The block contains:

**main.cpp**

.. code-block:: cpp

	#include <ctype.h>
	#include <iostream>
	#include <algorithm> // std::for_each

	using namespace std;

	int main()
	{
		char s[]="Hello World!";
		int Uppercase = 0; //modified by the lambda
		for_each(s, s+sizeof(s), [&Uppercase] (char c) {
		if (isupper(c))
		    Uppercase++;
		});
		cout<< Uppercase<<" uppercase letters in: "<< s<<endl;
	}

**CMakeLists.txt**

.. code-block:: cmake

	# HEADER
	include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
	INIT_BIICODE_BLOCK()

	# ACTIVATING C++11 FLAG
	IF(APPLE)
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
	ELSEIF (WIN32 OR UNIX)
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	ENDIF(APPLE)

	# MACRO TO ADD TARGETS
	ADD_BIICODE_TARGETS()

Build and run
^^^^^^^^^^^^^^^^

Make sure the program works well:

.. code-block:: bash

   ~/cpp11_project$ bii cpp:build
   ~/cpp11_project$ bin\phil_cpp_11_example_main
   2 uppercase letters in: Hello World!

.. container:: infonote

    Linux/MacOS users:

    .. code-block:: bash

      ~/cpp11_project$ ./bin/phil_cpp_11_example_main


Configure the CMake file of dependencies
-----------------------------------------

In this section, it explain the way to write cmake files for your dependencies.

Just make a file with the name ``biicode.configure`` inside your project with the biicode macro ``BII_ADD_INTERFACE(user-name block-name)``.

For example, if you want to compile the block mrpotato/parts with the C++ 11 flag on Linux, just write a file like followwing.
 
**biicode.configure**

.. code-block:: cmake

	#############BIICODE MACROS############
	BII_ADD_INTERFACE(mrpotato parts)
	#######################################

	target_compile_options(interface_mrpotato_parts_lib PUBLIC -std=c++11)


Add Boost dependency
------------------------

If you have installed Boost C++ library and you want to build some C++11 Boost example as |boost_cpp_link|, we teach you bellow as make it.

.. |boost_cpp_link| raw:: html

   <a href="http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/example/cpp11/allocation/server.cpp" target="_blank">server.cpp</a>

Create a new project
^^^^^^^^^^^^^^^^^^^^^^

First, create a new project to follow the example

.. code-block:: bash

   $ bii init boost_project
   $ cd boost_project
   ~/boost_project$ 


Download the example block
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Now, :download:`download the complete example block </_static/code/cpp/cmake/boost_example.zip>` and unzip it into your ``~/boost_project/blocks/`` folder. You can take a look at |boost_block_link| too.


.. |boost_block_link| raw:: html

   <a href="http://www.biicode.com/phil/phil/boost_example/master" target="_blank">this example block in our website</a>


The layout of your project will be as follows:

.. code-block:: text

   |-- boost_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- phil
   |    |    |    +-- boost_example
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- main.cpp
   |    +-- deps

The CMakeLists.txt contains (main.cpp content is too large to be showed):

**CMakeLists.txt**

.. code-block:: cmake

	include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
	INIT_BIICODE_BLOCK() 

	#Activating c++11 compilation flag
	IF(APPLE)
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
	ELSE () #WIN32 OR UNIX
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	ENDIF(APPLE)

	set( Boost_USE_STATIC_LIBS ON )
	# Find Boost package
	find_package(Boost REQUIRED COMPONENTS system)

	# Actually create targets: EXEcutables, STATIC libraries.
	ADD_BIICODE_TARGETS()

	# Linking with Boost libraries and including its include folders
	if(Boost_FOUND)
		INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
		IF (WIN32)
			TARGET_LINK_LIBRARIES(${BII_main_TARGET} "ws2_32" "wsock32" ${Boost_LIBRARIES})
		ELSEIF(APPLE OR UNIX)
			TARGET_LINK_LIBRARIES(${BII_main_TARGET} ${Boost_LIBRARIES})
		ENDIF(WIN32)
	endif()


Build and run
^^^^^^^^^^^^^^^^

Make sure the program works well:

.. code-block:: bash

   ~/boost_project$ bii cpp:build
   ~/boost_project$ bin\phil_boost_example_main
   Usage: server <port>

.. container:: infonote

    Linux/MacOS users:

    .. code-block:: bash

      ~/boost_project$ ./bin/phil_boost_example_main

