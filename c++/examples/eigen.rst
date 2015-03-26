Eigen
=======

|eigen_homepage| is a high-level C++ library of template headers for linear algebra, matrix and vector operations, numerical solvers and related algorithms.

Eigen library is at |bii_eigen|, which is generated from this |fork_eigen|.

Middle rows from a matrix
-------------------------

This example shows the way to generate a random matrix, print it and then print only he middle rows.

Create a project
^^^^^^^^^^^^^^^^

Create a simple project and the following file inside it.

.. code-block:: bash
 
 $ bii init eigen_example -L 
 $ cd eigen_example
 $ # copy DenseBase_middleRows_int.cpp

**DenseBase_middleRows_int.cpp**

.. literalinclude:: /_static/code/cpp/examples/eigen/DenseBase_middleRows_int.cpp
   :language: cpp
   :linenos:

Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 INFO: Processing changes...
 your_user/eigen_example depends on:
       system:
          iostream
       unresolved:
          Eigen/Core

Edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

.. code-block:: text

 [requirements]
     eigen/eigen: 6
 
 [includes]
     Eigen/*: eigen/eigen

Check again with **bii deps** to show all dependencies are now resolved.

Build the project
^^^^^^^^^^^^^^^^^

Now, build and run the code.

.. code-block:: bash
 
 $ bii build
 $ cd bin
 $ # run executable
   A =
   -16343   -660 -10679 -15893  16007
     2083  -4906  11761 -13389  -1780
   -10050  12974   6897  -4442 -12482
    10116  10578    443 -11557 -16231
     2785   8080  -6423 -10948 -16092

   A(2..3,:) =
   -10050  12974   6897  -4442 -12482
    10116  10578    443 -11557 -16231

Open and build
--------------

You can check all the Eigen examples uploaded in biicode and execute any of them, just have to open |examples_eigen|.

Create a project and open the examples:

.. code-block:: bash

   ~$ bii init eigen_example
   ~$ cd eigen_example
   ~$ bii open examples/eigen
   ~$ bii build

Execute any you want, for example, show the matrix's middle rows:

.. code-block:: bash

   ~/eigen_sample$ bin/examples_eigen_DenseBase_middleRows_int
   A =
   -16343   -660 -10679 -15893  16007
     2083  -4906  11761 -13389  -1780
   -10050  12974   6897  -4442 -12482
    10116  10578    443 -11557 -16231
     2785   8080  -6423 -10948 -16092

   A(2..3,:) =
   -10050  12974   6897  -4442 -12482
    10116  10578    443 -11557 -16231



.. |eigen_homepage| raw:: html

   <a href="http://eigen.tuxfamily.org" target="_blank">Eigen</a>

.. |bii_eigen| raw:: html

   <a href="http://www.biicode.com/eigen/eigen" target="_blank">eigen/eigen</a>

.. |fork_eigen| raw:: html

   <a href="https://github.com/franramirez688/eigen" target="_blank">github repo</a>

.. |examples_eigen| raw:: html

   <a href="https://www.biicode.com/examples/examples/eigen/master" target="_blank">examples/eigen block</a>