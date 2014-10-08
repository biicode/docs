CSparse
=======

CSparse is a concise Sparse Matrix C-library.

The main block is |bii_csparse|, which is generated from this |fork_csparse|.



Read a matrix and solve a linear system
-----------------------------------------

Now, you can check all the csparse examples which are uploaded in biicode and execute any of them. Then, create a new project and open the |examples_csparse|.

.. code-block:: bash

  ~$ bii init csparse_sample
  ~$ cd csparse_sample
  ~/csparse_sample$ bii open examples/csparse
  ~/csparse_sample$ bii cpp:build

Execute any you want, for example, read a matrix saved in a file and solve a linear system:

.. code-block:: bash

  ~/csparse_sample$ bin/examples_csparse_cs_demo2 < blocks/examples/csparse/Matrix/t1
 
  --- Matrix: 4-by-4, nnz: 10 (sym: 0: nnz 0), norm: 1.11e+001
  blocks: 1 singletons: 0 structural rank: 4
  QR   natural    time:     0.00 resid: 1.15e-017
  QR   amd(A'*A)  time:     0.00 resid: 1.53e-017
  LU   natural    time:     0.00 resid: 1.04e-017
  LU   amd(A+A')  time:     0.00 resid: 4.94e-018
  LU   amd(S'*S)  time:     0.00 resid: 4.94e-018
  LU   amd(A'*A)  time:     0.00 resid: 4.94e-018


.. |bii_csparse| raw:: html

   <a href="https://www.biicode.com/tdavis/tdavis/csparse/master" target="_blank">here</a>

.. |fork_csparse| raw:: html

   <a href="https://github.com/davidsanfal/csparse" target="_blank">github repo</a>

.. |examples_csparse| raw:: html

   <a href="https://www.biicode.com/examples/examples/csparse/master" target="_blank">examples/csparse block</a>