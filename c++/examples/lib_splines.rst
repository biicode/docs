Multivariate Splines
====================

Multivariate Splines is a function approximation library implementing various multivariate splines in C++.

You can find here the `Multivariate splines original github page <https://github.com/bgrimstad/multivariate-splines>`_ .

The following example demonstrates the use of Multivariate Splines. Note that there is no restrictions to the dimension of x (except that it has to be >= 1, of course).

**main_muparser.cpp**

.. literalinclude:: /_static/code/cpp/examples/splines/splines_main.cpp
   :language: cpp
   :linenos:


Project should be compiled with C++11 so you also need the CMakeLists which specify it:

**CMakeLists.txtp**

.. literalinclude:: /_static/code/cpp/examples/splines/CMakeLists.txt
   :language: cpp
   :linenos:


**Download:**
:download:`splines_main.cpp </_static/code/cpp/examples/splines/splines_main.cpp>`
:download:`CMakeLists.txt </_static/code/cpp/examples/splines/CMakeLists.txt>`

Create a block:

.. code-block:: bash

	$ bii init my_project
	$ cd my_project
	$ bii new examples/multivariate_splines


Copy the cpp file in your block, then you need to resolve all the dependencies of this ``main.cpp``. Then you can compile it

.. code-block:: bash

	$ bii find
	$ bii cpp:build


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
