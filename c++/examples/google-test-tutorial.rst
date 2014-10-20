Google Test (GTest)
====================

|gtest_homepage| is a C++ library for testing your projects.

The main block is |bii_gtest|, which is generated from this |fork_gtest|.


Testing a factorial function
--------------------------------

You can check all the gtest examples which are uploaded in biicode and execute any of them. Then, create a new project and open the |examples_gtest|.

.. code-block:: bash

   ~$ bii init gtest_sample
   ~$ cd gtest_sample
   ~/gtest_sample$ bii open examples/gtest


We will start with a math example: a **simple function to calculate the factorial of an integer number**, which returns

* -1 if the number is negative,
* 1 if the number is zero, or
* the factorial if the number is positive, *(num)\*(num-1)\*(num-2)\*…\*1*.


**math_ext.h**

.. code-block:: cpp

	#pragma once
	//Function returns the factorial of an integer number
	int Factorial (int num);

**math_ext.cpp**

.. code-block:: cpp

	#include "math_ext.h"
	int Factorial (int num) {
	  if (!num)return 1;
	  if (num<0)return -1;
	  return num*Factorial(num-1);
	}

There are two examples to build and execute, a simple test and a test suites. In this part, we'll execute the simple test.

**simple_test.cpp**

.. code-block:: cpp

	#include "../math_ext.h"
	#include "google/gtest/include/gtest/gtest.h"
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


Now, we compile and execute the test:

.. code-block:: bash

	~/gtest_sample$ bii cpp:build
	~/gtest_sample$ bin/examples_gtest_simple_test_simple_test
	[==========] Running 3 tests from 1 test case.
	[----------] Global test environment set-up.
	[----------] 3 tests from FactorialTest
	[ RUN      ] FactorialTest.Negative
	[       OK ] FactorialTest.Negative (0 ms)
	[ RUN      ] FactorialTest.Zero
	[       OK ] FactorialTest.Zero (0 ms)
	[ RUN      ] FactorialTest.Positive
	[       OK ] FactorialTest.Positive (0 ms)
	[----------] 3 tests from FactorialTest (0 ms total)

	[----------] Global test environment tear-down
	[==========] 3 tests from 1 test case ran. (0 ms total)
	[  PASSED  ] 3 tests.
	

Test suites
------------

If you want to have multiple test classes and run them all together you don't need to create multiple main methods, you just have to indicate which tests you want to include in your suite. For example, we can split the ``simple_test.cpp`` in the following three files:


**test_factorial1.cpp**

.. code-block:: cpp

	#include "../math_ext.h"
	#include "google/gtest/include/gtest/gtest.h"
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


**test_factorial2.cpp**

.. code-block:: cpp

	#include "../math_ext.h"
	#include "google/gtest/include/gtest/gtest.h"
	#include "stdio.h"
	// Tests Factorial()
	// Tests factorial of positive numbers.
	TEST(FactorialTest, Positive) {
		EXPECT_EQ(1, Factorial(1));
		EXPECT_EQ(2, Factorial(2));
		EXPECT_EQ(6, Factorial(3));
		EXPECT_EQ(40320, Factorial(8));
	}


**test_suites.cpp**

.. code-block:: cpp

	#include "google/gtest/include/gtest/gtest.h"
	#include "stdio.h"
	// Tests Factorial()
	int main(int argc, char **argv) {
	  printf("Running main() from sample1\n");
	  testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
	}

Notice the ``dependencies.bii`` file in your bii block folder. This is telling biicode that the main file **test_suites.cpp depends on those test files**. You can read more about ``dependencies.bii`` file :ref:`here <dependencies_bii>`.

Now when we execute your tests we obtain exactly the same output:

.. code-block:: bash

	~/gtest_sample$ bin/examples_gtest_test_suites_test_suites
	[==========] Running 3 tests from 1 test case.
	[----------] Global test environment set-up.
	[----------] 3 tests from FactorialTest
	[ RUN      ] FactorialTest.Negative
	[       OK ] FactorialTest.Negative (0 ms)
	[ RUN      ] FactorialTest.Zero
	[       OK ] FactorialTest.Zero (0 ms)
	[ RUN      ] FactorialTest.Positive
	[       OK ] FactorialTest.Positive (0 ms)
	[----------] 3 tests from FactorialTest (0 ms total)
	
	[----------] Global test environment tear-down
	[==========] 3 tests from 1 test case ran. (0 ms total)
	[  PASSED  ] 3 tests.


You can aggregate as many tests as you want to a suite so you can organize your tests to fit your needs.

**Note:** You can find more google test samples in the `biicode gtestsamples block <https://www.biicode.com/google/gtestsamples>`_.


.. |gtest_homepage| raw:: html

   <a href="http://code.google.com/p/googletest/" target="_blank">Google C++ Testing Framework</a>

.. |bii_gtest| raw:: html

   <a href="http://www.biicode.com/google/gtest" target="_blank">here</a>

.. |fork_gtest| raw:: html

   <a href="https://github.com/davidsanfal/gtest" target="_blank">github repo</a>

.. |examples_gtest| raw:: html

   <a href="https://www.biicode.com/examples/examples/gtest/master" target="_blank">examples/gtest block</a>