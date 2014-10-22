.. _cppdynamic:


CppDynamic
-----

|cppdynamic_homepage| is an open source C++ engine to use dynamic object which 
are useful, especially in rapid prototyping, non-performance critical 
situations, and situations in which data/functions -bags are needed 
(non schema specific data). Also when serializing and deserializing 
dynamic objects can be a very valuable asset.

The main block is |bii_cppdynamic|, which is generated from this |fork_cppdynamic|.

Testing dynamic variables
----------------------------

In this example, we will see a simple c++ program (test.cpp) where we use several dynamic variables (DynamicObject) working as a normal variable should do.

.. code-block:: bash

   ~$ bii init dynvar
   ~$ cd dynvar
   ~/dynvar$ bii new myuser/dynvar_example --hello cpp

Now **replace the main.cpp** file in ``blocks/myuser/dynvar_example`` with 
the following code:

.. code-block:: cpp

#include "jafroch/cppdynamic/include/cppdynamic/dynamic.h"
#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

  int main(){

	 dynamic::DynamicObject uut;
	 dynamic::DynamicObject uut2;
	 //fundamental types.	
	 uut=5;
	 //use it like a normal variable
	 for(int i=0;i++;i<(int)uut){
	 	// expando object
	 	switch (i){
	 		case 0 : uut2["test0"]="WELL";
	 		break;
	 		case 1 : uut2["test1"]=" ";
	 		break;
	 		case 2 : uut2["test2"]="DONE,";
	 		break;
	 		case 3 : uut2["test3"]=" ";
	 		break;
	 		case 4 : uut2["test4"]="WORKS!!";
	 		break;
	 	}
	 }
	 //reasignate value and type.
	 uut=((int)uut==5);
	 if((bool)uut){
		 std::cout << "We can see in the code the dynamic vars works almost in all cases.";
	}
}



Find your dependency to ``#include "jafroch/cppdynamic/include/cppdynamic/dynamic.h"`` and build the project:

.. code-block:: bash

  ~/box2d$ bii find

Before building we have to change the CmakeLists.txt, open it and write this instead of what is written:

.. code-block

  cmake_minimum_required(VERSION 2.8.7)
  project(core_dynamic)
  IF(BIICODE)
   include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
   # Initializes block variables
   INIT_BIICODE_BLOCK()
   SET(BII_CREATE_LIB TRUE)
    # Include base block dir
    ADD_BIICODE_TARGETS()
    TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
  IF(APPLE)
         SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -stdlib=libc++")
  ELSEIF (WIN32 OR UNIX)
         SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
  ENDIF(APPLE)
  ELSE()	
    # Previous CMakeLists.txt goes here
  if(CMAKE_COMPILER_IS_GNUCXX)
  	add_definitions(-std=c++0x)
  endif()
  file(GLOB_RECURSE files include/**.h)
  message("files ${files}")
  include_directories(include)
  add_executable(test test.cpp ${files})
  ENDIF()

Now we can build the projct:

.. code-block:: bash

  ~/box2d$ bii cpp:build

Execute the binary and this is how the output looks like:

.. code-block:: bash

  ~/box2d$ bin/myuser_dynvar_example_main


Didn't work? No problem, read or contact us in |biicode_forum_link|

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>



Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">Write us!</a>



.. |cppdynamic_homepage| raw:: html

   <a href="http://thetoeb.de/2014/10/08/an-implementation-of-the-dynamic-object-in-c/" target="_blank">Box2D</a>

.. |bii_cppdynamic| raw:: html

   <a href="http://www.biicode.com/jafroch/jafroch/cppdynamic/master" target="_blank">here</a>

.. |fork_cppdynamic| raw:: html

   <a href="https://github.com/toeb/cppdynamic" target="_blank">github repo</a>
