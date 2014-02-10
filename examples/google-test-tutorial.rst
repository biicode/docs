Google Test Tutorial
====================

This example uses the famous library `googletest, a Google C++ Testing Framework <http://code.google.com/p/googletest/>`_. If you are familiar with coding in C++, you probably know about this library and use it for testing your projects. Otherwise, you can learn more visiting the `googletest project Wiki page <http://code.google.com/p/googletest/w/list>`_.

Creating the hive
-----------------

Open your console and write the following command:

.. code-block:: bash

	$ cd ../biicode_workspace
	$ bii new maths

If the publication has been correctly created, you will see a message like the following:

.. code-block:: bash

	Created new Hive maths

Then, a hive folder named maths will be created in your workspace folder. Said folder will contain the following subfolders: bii, deps and blocks.

Compile and execute your block
------------------------------

We will start with a math example — the method to calculate the factorial of a non-negative integer which returns -1 if the number is negative and the factorial if the number is positive:

**math_ext.h**

.. literalinclude:: ../_static/code/cpp/examples/google-test-tutorial/math_ext.h
   :language: cpp
   :linenos:

**math_ext.cpp**

.. literalinclude:: ../_static/code/cpp/examples/google-test-tutorial/math_ext.cpp
   :language: cpp
   :linenos:

**Download all the files:** :download:`math_ext.cpp <../_static/code/cpp/examples/google-test-tutorial/math_ext.cpp>` :download:`math_ext.h <../_static/code/cpp/examples/google-test-tutorial/math_ext.h>`
   
   
Using Google Tests with biicode is very simple. You just have to include "google/gtest/gtest.h" which contains c files of gtest.

To check that the factorial function runs fine, make a main_test.cpp like this:

**main_test.cpp**

.. literalinclude:: ../_static/code/cpp/examples/google-test-tutorial/main_test.cpp
   :language: cpp
   :linenos:


**Download the file:** :download:`main_test.cpp <../_static/code/cpp/examples/google-test-tutorial/main_test.cpp>` 
   
Put every files into the folder ~/maths/blocks/your_user_name/maths/ and  execute them:

.. code-block:: bash
	
	$ bii work
	Saving files on disk
	Work done!

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

To run your tests:

.. code-block:: bash

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