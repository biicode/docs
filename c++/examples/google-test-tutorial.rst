Google Test (GTest)
====================

|gtest_homepage| is a C++ library for testing your projects.

The main block is at |bii_gtest| and it is generated from this |fork_gtest|.

You can check all the `gtest examples <https://www.biicode.com/google/gtestsamples>`_ which are uploaded in biicode and execute any of them.

Testing a factorial function: Simple test
-----------------------------------------

There are two examples to build and execute, a simple test and a test suites.
In this part, you'll run a simple test for a simple "math example code".

Creating a new project
^^^^^^^^^^^^^^^^^^^^^^

Create a new project and *math_ext.h*, *math_ext.cpp* files:

.. code-block:: bash

   $ bii init gtest_example -L
   $ cd gtest_example
   $ # Create files manually

Our math example is a simple function to **calculate the factorial of an integer number**, which returns

* -1 if the number is negative,

* 1 if the number is zero, or

* The factorial if the number is positive: *(num)\*(num-1)\*(num-2)\*…\*1*.

|

Copy the code for each file:

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


Okay, now create a new directory *simple_test* with *simple_test.cpp* file and copy its content:

**simple_test/simple_test.cpp**

.. code-block:: cpp

	#include "../math_ext.h"
	#include "gtest/gtest.h"
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

Configure biicode.conf
^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 INFO: Processing changes...
 your_user/gtest_example depends on:
       system:
          stdio.h
       unresolved:
          gtest/gtest.h

Now, edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

**biicode.conf**

.. code-block:: text

 [requirements]
     google/gtest: 10
 
 [includes]
     gtest/*.h: google/gtest/include

Type **bii deps** again to check all dependencies are resolved.

To configure the *simple_test.cpp* you have to include it in ``[tests]`` section like this:

**biicode.conf**

.. code-block:: text

 [tests]
     simple_test/simple_test.cpp


Build and run the test
^^^^^^^^^^^^^^^^^^^^^^

Compile and execute the test, the convenient command for that is **bii test**:

.. code-block:: bash

	$ bii test
	 INFO: Processing changes...
	 INFO: Saving files from: google/gtest
	 ...
	test 1
	    Start 1: examples_gtest_example_simple_test_simple_test
	1: Running main() from sample1
	1: [==========] Running 3 tests from 1 test case.
	1: [----------] Global test environment set-up.
	1: [----------] 3 tests from FactorialTest
	1: [ RUN      ] FactorialTest.Negative
	1: [       OK ] FactorialTest.Negative (0 ms)
	1: [ RUN      ] FactorialTest.Zero
	1: [       OK ] FactorialTest.Zero (0 ms)
	1: [ RUN      ] FactorialTest.Positive
	1: [       OK ] FactorialTest.Positive (0 ms)
	1: [----------] 3 tests from FactorialTest (0 ms total)
	1:
	1: [----------] Global test environment tear-down
	1: [==========] 3 tests from 1 test case ran. (1 ms total)
	1: [  PASSED  ] 3 tests.
	1/1 Test #1: examples_gtest_example_simple_test_simple_test ...   Passed    0.04 sec
	
	100% tests passed, 0 tests failed out of 1
	
	Total Test time (real) =   0.06 sec
	[100%] Built target check

Great! Your math code passed the simple test.

Testing a factorial function: Test suites
-----------------------------------------

To have multiple test classes and run them all together you don't need to create multiple main methods, you just have to indicate which tests you want to include in your suite.

For example, you can split the *simple_test.cpp* in the following three files.

Place these three files in a new directory called *test_suites* inside your project.

**test_suites/test_factorial1.cpp**

.. code-block:: cpp

	#include "../math_ext.h"
	#include "gtest/gtest.h"
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


**test_suites/test_factorial2.cpp**

.. code-block:: cpp

	#include "../math_ext.h"
	#include "gtest/gtest.h"
	#include "stdio.h"
	// Tests Factorial()
	// Tests factorial of positive numbers.
	TEST(FactorialTest, Positive) {
		EXPECT_EQ(1, Factorial(1));
		EXPECT_EQ(2, Factorial(2));
		EXPECT_EQ(6, Factorial(3));
		EXPECT_EQ(40320, Factorial(8));
	}


**test_suites/test_suites.cpp**

.. code-block:: cpp

	#include "gtest/gtest.h"
	#include "stdio.h"
	// Tests Factorial()
	int main(int argc, char **argv) {
	  printf("Running main() from sample1\n");
	  testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
	}

Configure biicode.conf
^^^^^^^^^^^^^^^^^^^^^^

You have to indicate in the ``[dependencies]`` section in your **biicode.conf** file that the main file *test_suites.cpp* **depends on those test files**: *test_factorial1.cpp* and *test_factorial2.cpp*.

.. container:: infonote
 
 Read more about ``[dependencies]`` section :ref:`here <dependencies_conf>`.

And you have to indicate the new test in the ``[tests]`` section.

Edit your *biicode.conf* like this:

**biicode.conf**

.. code-block:: text

 [dependencies]
	 test_suites/test_suites.cpp + test_suites/test_factorial1.cpp
	 test_suites/test_suites.cpp + test_suites/test_factorial2.cpp
 
 [tests]
     simple_test/simple_test.cpp
     test_suites/test_suites.cpp

Build and run the tests
^^^^^^^^^^^^^^^^^^^^^^^

Now execute your tests and you'll obtain the following output:

.. code-block:: bash

	$ bii test
	INFO: Processing changes...
	INFO: Saving files from: google/gtest
	...
	test 1
	    Start 1: examples_gtest_example_simple_test_simple_test
	1: Running main() from sample1
	1: [==========] Running 3 tests from 1 test case.
	1: [----------] Global test environment set-up.
	1: [----------] 3 tests from FactorialTest
	1: [ RUN      ] FactorialTest.Negative
	1: [       OK ] FactorialTest.Negative (0 ms)
	1: [ RUN      ] FactorialTest.Zero
	1: [       OK ] FactorialTest.Zero (0 ms)
	1: [ RUN      ] FactorialTest.Positive
	1: [       OK ] FactorialTest.Positive (0 ms)
	1: [----------] 3 tests from FactorialTest (0 ms total)
	1:
	1: [----------] Global test environment tear-down
	1: [==========] 3 tests from 1 test case ran. (0 ms total)
	1: [  PASSED  ] 3 tests.
	1/2 Test #1: examples_gtest_example_simple_test_simple_test ...   Passed    0.04 sec
	
	test 2
	    Start 2: examples_gtest_example_test_suites_test_suites
	2: Running main() from sample1
	2: [==========] Running 3 tests from 1 test case.
	2: [----------] Global test environment set-up.
	2: [----------] 3 tests from FactorialTest
	2: [ RUN      ] FactorialTest.Positive
	2: [       OK ] FactorialTest.Positive (0 ms)
	2: [ RUN      ] FactorialTest.Negative
	2: [       OK ] FactorialTest.Negative (0 ms)
	2: [ RUN      ] FactorialTest.Zero
	2: [       OK ] FactorialTest.Zero (0 ms)
	2: [----------] 3 tests from FactorialTest (0 ms total)
	2:
	2: [----------] Global test environment tear-down
	2: [==========] 3 tests from 1 test case ran. (0 ms total)
	2: [  PASSED  ] 3 tests.
	2/2 Test #2: examples_gtest_example_test_suites_test_suites ...   Passed    0.03 sec

	100% tests passed, 0 tests failed out of 2

	Total Test time (real) =   0.09 sec
	[100%] Built target check

Congrats! Your math code passed both "simple_test" and "test_suites".

You can aggregate as many tests as you want to a suite so you can organize your tests to fit your needs.

**Note:** You can find more google test samples in the `google/gtestsamples <https://www.biicode.com/google/gtestsamples>`_ block.

Quick way
---------

This example is already in biicode: `examples/gtest <http://www.biicode.com/examples/gtest>`_.

To give it a try and see how it's configured, create a new project and open the block:

.. code-block:: bash

 $ bii init gtest_example
 $ cd gtest_example
 $ bii open examples/gtest

Have a look at the *biicode.conf* file:

**biicode.conf**

.. code-block:: bash

	[requirements]
		 google/gtest: 10

	[parent]
		examples/gtest: 1
	[paths]

	[dependencies]
		test_suites/test_suites.cpp + test_suites/test_factorial1.cpp
		test_suites/test_suites.cpp + test_suites/test_factorial2.cpp

	[mains]

	[hooks]

	[includes]
	    gtest/*.h: google/gtest/include

	[data]

	[tests]
	    simple_test/simple_test.cpp
	    test_suites/test_suites.cpp


.. container:: infonote
 
 Read more about :ref:`biicode.conf <dependencies_conf>`.

Now execute the tests:

.. code-block:: bash

 $ bii test
 ...
 100% tests passed, 0 tests failed out of 2
	
	Total Test time (real) =   0.09 sec
	[100%] Built target check

Got any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_, visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.


.. |gtest_homepage| raw:: html

   <a href="http://code.google.com/p/googletest/" target="_blank">Google C++ Testing Framework</a>

.. |bii_gtest| raw:: html

   <a href="http://www.biicode.com/google/gtest" target="_blank">google/gtest</a>

.. |fork_gtest| raw:: html

   <a href="https://github.com/davidsanfal/gtest" target="_blank">github repo</a>

.. |examples_gtest| raw:: html

   <a href="https://www.biicode.com/examples/examples/gtest/master" target="_blank">examples/gtest block</a>