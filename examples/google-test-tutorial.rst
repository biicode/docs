Google Test Tutorial
====================

This example uses the famous library `googletest, a Google C++ Testing Framework <http://code.google.com/p/googletest/>`_. If you are familiar with coding in C++, you probably know about this library and use it for testing your projects. Otherwise, you can learn more visiting the `googletest project Wiki page <http://code.google.com/p/googletest/w/list>`_.

In this example **we are going to create a factorial function and a test for it**. This video shows the whole process described below:

.. raw:: html

    <script type="text/javascript" src="https://asciinema.org/a/7763.js" id="asciicast-7763" async></script>


1. Create a new hive
---------------------

Create a new hive as described in the :ref:`hello world example <hello_world>`.
For this example we should select ``cpp`` as programming language, name our hive ``gtest_hive`` and the block ``factorial``.
We don't need to generate a default hello world.


2. Create a function and a test for it
---------------------------------------

We will start with a math example: a **simple function to calculate the factorial of an integer number**, which returns

* -1 if the number is negative,
* 1 if the number is zero, or
* the factorial if the number is positive, *(num)\*(num-1)\*(num-2)\*…\*1*.

Put these files inside ``YOUR_WORKSPACE/gtest_hive/blocks/YOUR_USERNAME/factorial``

**math_ext.h**

.. literalinclude:: ../_static/code/cpp/examples/google-test-tutorial/math_ext.h
   :language: cpp
   :linenos:

**math_ext.cpp**

.. literalinclude:: ../_static/code/cpp/examples/google-test-tutorial/math_ext.cpp
   :language: cpp
   :linenos:

**Download all the files:** :download:`math_ext.cpp <../_static/code/cpp/examples/google-test-tutorial/math_ext.cpp>` :download:`math_ext.h <../_static/code/cpp/examples/google-test-tutorial/math_ext.h>`
   
   
**Now than we have our factorial function, we can test it with Google Test**. You just have to include ``google/gtest/gtest.h``.
To check that the factorial function behaves as expected put main_test.cpp with the rest of source files:

**main_test.cpp**

.. literalinclude:: ../_static/code/cpp/examples/google-test-tutorial/main_test.cpp
   :language: cpp
   :linenos:

**Download the file:** :download:`main_test.cpp <../_static/code/cpp/examples/google-test-tutorial/main_test.cpp>` 


3. Find dependencies
--------------------

Now **we have to ask biicode to find our dependencies**. This will download Google Test to your machine, into your hive's ``deps`` folder.

.. code-block:: bash

	$ bii find
	INFO: Detected 3 files created, 0 updated
	INFO: Settings changed
	INFO: Compiler configuration changed, cleaning build
	INFO: Finding missing dependencies in server
	INFO: Looking for google/gtest...
	INFO: Analyzing compatibility for found dependencies...
	INFO: Dependencies resolved in server:
	Find resolved new dependencies:
		google/gtest(google/master): 2
	All dependencies resolved
	INFO: Saving files on disk
	INFO: Retrieving resources from server
	INFO: Computing dependencies
	INFO: Saving dependences on disk


4. Run your tests
-----------------

Finally, we are ready to unit-test our factorial function:

.. code-block:: bash

	$ bii cpp:run test
	Building[ 77%] Built target google_gtest
	[100%] Built target hithwen_factorial_main_test
	Running "hithwen_factorial_main_test"
	Running main() from sample1
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
	

**Note:** You can find more google test samples in the `biicode gtestsamples block <https://www.biicode.com/google/blocks/google/gtestsamples/branches/master>`_.