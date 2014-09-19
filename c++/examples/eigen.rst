Eigen
=======

|eigen_homepage| is a high-level C++ library of template headers for linear algebra, matrix and vector operations, numerical solvers and related algorithms.

The main block is |bii_eigen|, which is generated from this |fork_eigen|.



Examples
-----------

Now, you can check all the eigen examples which are uploaded in biicode and execute any of them. Then, create a new project and open the |examples_eigen|.

.. code-block:: bash

   ~$ bii init eigen_sample
   ~$ cd eigen_sample
   ~/eigen_sample$ bii open examples/eigen
   ~/eigen_sample$ bii cpp:build

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

   <a href="http://www.biicode.com/eigen/eigen" target="_blank">here</a>

.. |fork_eigen| raw:: html

   <a href="https://github.com/franramirez688/eigen" target="_blank">github repo</a>

.. |examples_eigen| raw:: html

   <a href="https://www.biicode.com/examples/examples/eigen/master" target="_blank">examples/eigen block</a>