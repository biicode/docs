Google Test Tutorial
====================

This example uses the famous library `googletest, a Google C++ Testing Framework <http://code.google.com/p/googletest/>`_. If you are familiar with coding in C++, you probably know about this library and use it for testing your projects. Otherwise, you can learn more visiting the `googletest project Wiki page <http://code.google.com/p/googletest/w/list>`_.

Creating the hive
-----------------

Open your console and write the following command: ::

	$ cd ../biicode_workspace
	$ bii new maths

If the publication has been correctly created, you will see a message like the following: ::

	Created new Hive maths

Then, a hive folder named maths will be created in your workspace folder. Said folder will contain the following subfolders: bii, deps and blocks.

Compile and execute your block
------------------------------

We will start with a math example — the method to calculate the factorial of a non-negative integer which returns -1 if the number is negative and the factorial if the number is positive:

**math_ext.h**

.. code-block:: cpp
	:linenos:
	
	int Factorial (int num);

**math_ext.cpp**

.. code-block:: cpp
	:linenos:

	#include "math_ext.h"
	 
	int Factorial (int num) {
	  if (!num)return 1;
	  if (num<0)return -1;
	  return num*Factorial(num-1);
	}

Using Google Tests with biicode is very simple. You just have to include "google/gtest/gtest.h" which contains c files of gtest.

To check that the factorial function runs fine, make a main.cpp like this:

**main.cpp**

.. code-block:: cpp
	:linenos:

	#include "math_ext.h"
	#include "google/gtest/gtest.h"
	#include "stdio.h"
	 
	// Tests Factorial()
	 
	// Tests factorial of negative numbers.
	TEST(FactorialTest, Negative) {
	    // This test is named "Negative", and belongs to the "FactorialTest"
	    // test case  
	    EXPECT_EQ(-1, Factorial(-5));
	    EXPECT_EQ(-1, Factorial(-1));
	    EXPECT_LT(Factorial(-10), 0);
	}
	 
	// Tests factorial of 0.
	TEST(FactorialTest, Zero) {
	    EXPECT_EQ(1, Factorial(0));
	}
	 
	// Tests factorial of positive numbers.
	TEST(FactorialTest, Positive) {
	    EXPECT_EQ(1, Factorial(1));
	    EXPECT_EQ(2, Factorial(2));
	    EXPECT_EQ(6, Factorial(3));
	    EXPECT_EQ(40320, Factorial(8));
	}
	 
	int main(int argc, char **argv) {
	  printf("Running main() from sample1\n");
	  testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
	}

Put every files into the folder ~/maths/blocks/your_user_name/maths/ and  execute them: ::

	$ bii work
	Saving files on disk
	Work done!

::

	$ bii find
	Finding missing dependencies in server
	Looking for google/gtest...
	  >> Block candidate: google/google/gtest/master
	  >> Version google/google/gtest/master:#0 (STABLE) valid due your policy!
	  Found blocks: google/google/gtest/master:#0
	Analyzing compatibility for found dependencies...
	  Resolved block!
	Dependencies resolved in server:
	Find resolved new dependencies:
	    google/google/gtest/master:#0
	All dependencies resolved

To run your tests: ::

	$ bii cpp:run main
	Running main() from sample1
	[==========] Running 3 tests from 1 test case.
	[----------] Global test environment set-up.
	[----------] 3 tests from FactorialTest
	[ RUN ] FactorialTest.Negative
	[ OK ] FactorialTest.Negative (0 ms)
	[ RUN ] FactorialTest.Zero
	[ OK ] FactorialTest.Zero (0 ms)
	[ RUN ] FactorialTest.Positive
	[ OK ] FactorialTest.Positive (0 ms)
	[----------] 3 tests from FactorialTest (0 ms total)

	[----------] Global test environment tear-down
	[==========] 3 tests from 1 test cases ran. (0 ms total)
	[ PASSED ] 3 tests.

You can find more google test samples in the `biicode gtestsamples block <https://www.biicode.com/google/blocks/google/gtestsamples/branches/master>`_.