.. _c-challenge:

Solving the C++ Challenge
=========================

In this section we explain, step by step, how to solve `the C++ challenge <http://web.biicode.com/challenge>`_ with the help of biicode.

Create a new hive
-----------------

Open your console, move to your biicode workspace and create a new hive named "challenge":

.. code-block:: bash

	$ cd ../biicode_workspace
	$ bii new challenge
	$ cd challenge

Copy the code
-------------

Download the `challenge sources from github <https://github.com/biicode/challenge>`_ or in `zipped format from this link <https://biicorporateproduction.s3.amazonaws.com/media/uploads/challenge.zip>`_. Copy all the files into ``challenge/blocks/your_user_name/challenge``.
If you got the sources from github, you need to replace the #include directives as follows: (#include "sparse/cs.h" => #include "tdavis/sparse/cs.h", #include <eigen/Dense> => #include <eigen/eigen/Dense>, #include "gtest/include/gtest/gtest.h" => #include "google/gtest/include/gtest/gtest.h")

Now you can check for all the code dependencies of the current hive using the ``bii deps`` command. Please, note that while most of the dependencies are correctly solved, three of them are not. Theses **unresolved dependencies** have been highlighted in the following figure:

.. code-block:: bash
	:emphasize-lines: 18,19,20,21

	$ bii deps
	Detected 5 files created, 0 updated
	Processing hive
	  Cell your_user_name/challenge/systemsolver.h is implemented by set([\'your_user_name/challenge/systemsolver.cpp\'])

	Find resources with include to gtest ['your_user_name/challenge/test1.cpp']

	Adding resources to your_user_name/challenge/gtest_main.cc
	Saving files on disk
	DepTable: 
	Declarations: 
	  Resolved
	    map
	    vector
	    iostream
	    your_user_name/challenge/systemsolver.h
	    fstream
	  Unresolved
	    eigen/eigen/Dense
	    google/gtest/include/gtest/gtest.h
	    tdavis/csparse/include/cs.h
	Files deps: 
	  System
	    map
	    vector
	    iostream
	    fstream
	  Explicit
	    your_user_name/challenge/systemsolver.h
	  Implicit
	    your_user_name/challenge/test1.cpp
	    your_user_name/challenge/systemsolver.cpp

Find and retrieve dependencies
------------------------------

Now that we know that our hive has some missing dependencies, we'll show you how easily biicode helps you to automatically retrieve all of them. You only need to write the ``bii find`` command. You'll be asked to provide your biicode password, and the client will find and retrieve from our servers any missing dependencies:

.. code-block:: bash
	:emphasize-lines: 23,24,25,26,27,28

	$ bii find
	Finding missing dependencies in server
	Password for your_user_name: 
	Looking for eigen/eigen...
	  >> Block candidate: eigen/eigen(eigen/master)
	  >> Version eigen/eigen(eigen/master): 0 (STABLE) valid due your policy!
	  Found blocks: eigen/eigen(eigen/master): 0
	Looking for tdavis/csparse...
	  >> Block candidate: tdavis/csparse(tdavis/master)
	  >> Version tdavis/csparse(tdavis/master): 0 (STABLE) valid due your policy!
	  Found blocks: tdavis/csparse(tdavis/master): 0
	Looking for google/gtest...
	  >> Block candidate: google/gtest(google/master)
	  >> Version google/gtest(google/master): 2 (STABLE) valid due your policy!
	  >> Version google/gtest(google/master): 1 (STABLE) valid due your policy!
	  >> Version google/gtest(google/master): 0 (DEV) discarded due your policy!
	  Found blocks: google/gtest(google/master): 2
	  Found blocks: google/gtest(google/master): 1
	Analyzing compatibility for found dependencies... 
	  Resolved block!
	  Resolved block!
	  Resolved block!
	Dependencies resolved in server:
	Find resolved new dependencies:
		eigen/eigen(eigen/master): 0
		google/gtest(google/master): 2
		tdavis/csparse(tdavis/master): 0
	All dependencies resolved
	Saving files on disk
	Computing dependencies
	Retrieving resources from server
	Retrieving resources from server
	Retrieving resources from server
	Retrieving resources from server
	Saving dependences on disk

At this point, you'll find some new folders and files in your ``challenge/dep`` folder. These are the blocks that biicode considers as needed for compiling the hive.

Build and run
-------------

The final step is to actually compile and run the app. You can accomplish this task with the ``bii cpp:run`` command. As this hive contains more than one executable binary, you also need to provide the name of the task you wish to execute:

.. code-block:: bash

	$ bii cpp:run solver
	No deps to find
	...
	...
	*************** SPARSE ***************
	0: 1
	1: 0.5
	2: 0.333333
	3: 0.25
	4: 0.2
	5: 0.166667
	6: 0.142857
	7: 0.125
	8: 0.111111
	9: 0.1
	*************** DENSE *************** 
	0: 1
	1: 0.5
	2: 0.333333
	3: 0.25
	4: 0.2
	5: 0.166667
	6: 0.142857
	7: 0.125
	8: 0.111111
	9: 0.1

Running the tests is really easy too. Note that in this case one of the tests fails due to sparse solver accuracy, but the execution of the test itself works just fine!.

.. code-block:: bash

	$ bii cpp:run gtest
	No deps to find
	...
	...
	Running main() from gtest_main.cc
	[==========] Running 2 tests from 1 test case.
	[----------] Global test environment set-up.
	[----------] 2 tests from Solver
	[ RUN      ] Solver.BasicDiagonalSparse
	challenge/blocks/your_user_name/challenge/test1.cpp:21: Failure
	Value of: 1./(i+1)
	  Actual: 0.5
	Expected: sol[i]
	Which is: 0.5
	challenge/blocks/your_user_name/challenge/test1.cpp:21: Failure
	Value of: 1./(i+1)
	  Actual: 0.333333
	Expected: sol[i]
	Which is: 0.333333
	[  FAILED  ] Solver.BasicDiagonalSparse (0 ms)
	[ RUN      ] Solver.BasicDiagonalDense
	[       OK ] Solver.BasicDiagonalDense (1 ms)
	[----------] 2 tests from Solver (1 ms total)

	[----------] Global test environment tear-down
	[==========] 2 tests from 1 test case ran. (1 ms total)
	[  PASSED  ] 1 test.
	[  FAILED  ] 1 test, listed below:
	[  FAILED  ] Solver.BasicDiagonalSparse

	1 FAILED TEST
