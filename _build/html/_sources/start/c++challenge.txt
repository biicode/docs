Solving the C++ Challenge
=========================

In this section we explain, step by step, how to solve the C++ challenge with the help of biicode.

Create a New Hive
-----------------

Open your console, move to your biicode workspace and create a new hive named "hello": ::

	$ cd ../biicode_workspace
	$ bii new challenge
	$ cd challenge

Copy the code
-------------

Download the code from github or better challenge.zip and copy the source code into challenge/src/your_user_name/challenge

You will be able to check the dependencies of the current hive (and see if some are still unresolved) with: ::

	$ bii deps
	...
	Unresolved
	 eigen/eigen/Dense
	 google/gtest/include/gtest/gtest.h
	 tdavis/csparse/include/cs.h
	...

Find and retrieve dependencies
------------------------------

::

	$ bii find
	...
	Dependencies resolved in server:
	Find resolved new dependencies:
	 google/google/gtest/master:#1
	 eigen/eigen/eigen/master:#0
	 tdavis/tdavis/csparse/master:#0
	All dependencies resolved
	...
	Retrieving resources from server
	Saving dependences on disk

Build and run
-------------

Running the app is really easy. ::

	$ bii cpp:run solver
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

Running the tests is really easy too (note that one of the tests fails due to sparse solver accuracy, but the execution of the tests works!). ::

	$ bii cpp:run gtest
	[==========] Running 2 tests from 1 test case.
	[----------] Global test environment set-up.
	[----------] 2 tests from Solver
	[ RUN ] Solver.BasicDiagonalSparse
	\src\eigen\challenge\test1.cpp:21: Failure
	Value of: 1./(i+1)
	 Actual: 0.5
	Expected: sol[i]
	Which is: 0.5
	\src\eigen\challenge\test1.cpp:21: Failure
	Value of: 1./(i+1)
	 Actual: 0.333333
	Expected: sol[i]
	Which is: 0.333333
	[ FAILED ] Solver.BasicDiagonalSparse (1 ms)
	[ RUN ] Solver.BasicDiagonalDense
	[ OK ] Solver.BasicDiagonalDense (0 ms)
	[----------] 2 tests from Solver (1 ms total)
	[----------] Global test environment tear-down
	[==========] 2 tests from 1 test case ran. (1 ms total)
	[ PASSED ] 1 test.
	[ FAILED ] 1 test, listed below:
	[ FAILED ] Solver.BasicDiagonalSparse 1 FAILED TEST