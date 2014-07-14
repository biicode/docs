Let’s Get Started
=================

To start, run ``bii:init`` inside your project folder to create the project layout. Here’s a simple example to get you started wwith GTest.

.. code-block:: bash

	~/<project_name>$ bii init


Next, add ``<project_name>/blocks/anonymous/test/main.cpp`` to your project.

.. code-block:: cpp

	#include "google/gtest/gtest.h"
	int sum(int a, int b) {return a+b;} 
	TEST(Sum, Normal) {
	  EXPECT_EQ(5, sum(2, 3));
	} 
	int main(int argc, char **argv) {
	  testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
	}

You have the following layout.

.. code-block:: text

   +-- <project_name>
   |    +-- bii
   |    +-- blocks
   |    |    +-- anonymous
   |    |    |    +-- test
   |    |    |    |    +-- main.cpp
   |    +-- deps

Resolve the dependencie to ``#include "google/gtest/gtest.h"``.

.. code-block:: bash

	~/<project_name>$ bii find

Now you have the gtest files you need into the deps folder.

Compile it.

.. code-block:: bash

	~/<project_name>$ bii cpp:build

Now you just open the bin folder and run ``anonymous_test_main.exe``