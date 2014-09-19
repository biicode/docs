Use C++11 with biicode
======================

.. code-block:: bash

   $ bii init cpp11_hello_project

   $ cd cpp11_hello_project
   $ bii new cpp11_block --hello=cpp

The layout of your project will be as follows:

.. code-block:: text

   +-- cpp_hello_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- anonymous
   |    |    |    +-- cpp11_block
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- main.cpp
   |    +-- deps

**main.cpp**

.. code-block:: cpp
   :emphasize-lines: 1

   #include "google/gtest/gtest.h"
   int sum(int a, int b) {return a+b;}
   TEST(Sum, Normal) {
     EXPECT_EQ(5, sum(2, 3));
   }
   int main(int argc, char **argv) {
     testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
   }

**CMakeLists.txt**

.. container:: tabs-section

	.. container:: tabs-item

		.. rst-class:: tabs-title

			Windows & Linux

		.. code-block:: cmake

		   ################BIICODE MACROS################
		   include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
		   INIT_BIICODE_BLOCK()

		   ADD_BIICODE_TARGETS()
		   ##############################################

		   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

	.. container:: tabs-item

		.. rst-class:: tabs-title

			MacOS

		.. code-block:: cmake

		   ################BIICODE MACROS################
		   include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
		   INIT_BIICODE_BLOCK()

		   ADD_BIICODE_TARGETS()
		   ##############################################

		   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
