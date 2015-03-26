Multivariate Splines
====================

Multivariate Splines is a function approximation library implementing various multivariate splines in C++.

You can find here the `Multivariate splines original github page <https://github.com/bgrimstad/multivariate-splines>`_. 

.. container:: infonote

 This example does not compile in Windows. Please, use Linux or MacOS instead.


The following example demonstrates the use of Multivariate Splines. Note that there are no restrictions to the dimension of x (except that it has to be >= 1, of course).

**main_muparser.cpp**

.. literalinclude:: /_static/code/cpp/examples/splines/splines_main.cpp
   :language: cpp
   :linenos:


Project should be compiled with C++11 so you also need the CMakeLists which specify it:

**CMakeLists.txt**

.. literalinclude:: /_static/code/cpp/examples/splines/CMakeLists.txt
   :language: cpp
   :linenos:

* This example is `already in biicode <http://www.biicode.com/examples/multivariate_splines>`_, it's simple to run, just open the block and build it like this:

	.. code-block:: bash

		$ bii init my_project
		$ cd my_project
		$ bii open examples/multivariate_splines
		$ bii build


* **Only if you want to do it manually**, create a *cpp file* in your block, copy the code above and resolve all the dependencies of the ``main.cpp``. Create a ``CMakeLists.txt`` file with the content above too. Then you can compile it:

	.. code-block:: bash
		
		$ bii init my_project
		$ cd my_project
		$ bii new my_user/my_block
		$ # Create a main.cpp file in my_user/my_block and copy the code
		$ # Create a CMakeLists.txt file in my_user/my_block an copy the code
		$ bii find
		$ bii build

You will see next console output after executing the command:

.. code-block:: bash

	$ cd bin
	$ bin $ ././examples_multivariate_splines_splines_main
	Computing B-spline control points using dense solver.
	Computing B-spline control points using dense solver.
	Computing B-spline control points using dense solver.
	Computing RBF weights using dense solver.
	Error: 6.33755e-14
	-------------------------------------------------
	Function at x: 			3.23333
	Linear B-spline at x: 		3.23333
	Cubic B-spline at x: 		3.23333
	P-spline at x: 			3.23285
	Thin-plate spline at x:		3.23333
	-------------------------------------------------
