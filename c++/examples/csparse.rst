CSparse
=======

CSparse is a C library which implements a number of direct methods for sparse linear systems, by Timothy Davis. 

Csparse libary can be used form |bii_csparse|, this block is generated from this |fork_csparse|.

Read a matrix and solve a linear system
---------------------------------------

With this example you can read a matrix saved in a file and solve a linear system.

You need *cs_demo.h* and *cs_demo.c* to encampsule some functions to use in the example and a matrix file *t1*. Then, *cs_demo2.c* implements the main function. Let's do it!

Create a new project
--------------------

.. code-block:: bash

 $ bii init csparse_example -L 
 $ cd csparse_example
 $ # copy the files below

**cs_demo.h**

.. literalinclude:: /_static/code/cpp/examples/csparse/cs_demo.h
   :language: cpp
   :linenos:

**cs_demo.c**

.. literalinclude:: /_static/code/cpp/examples/csparse/cs_demo.c
   :language: cpp
   :linenos:

**cs_demo2.c**

.. literalinclude:: /_static/code/cpp/examples/csparse/cs_demo2.c
   :language: cpp
   :linenos:

Place *t1* file in a new folder called *Matrix*:

**Matrix/t1**

.. literalinclude:: /_static/code/cpp/examples/csparse/Matrix/t1
   :language: text
   :linenos:


Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Create a *biicode.conf* file in the project folder. Add your ``[requirements]`` depending on ``tdavis/csparse`` and map your ``[includes]``:

.. code-block:: text

 [requirements]
     tdavis/csparse: 1
 
 [includes]
     *.h: tdavis/csparse/Include

Check with **bii deps** to show all dependencies are resolved.

Build the project
^^^^^^^^^^^^^^^^^

Now, build and run the example

.. code-block:: bash

 $ bii build
 $ cd bin
 $ your_user_csparse_example_cs_demo2 < ../Matrix/t1
 $ # NOTE "your_user" should be your user's name

   --- Matrix: 4-by-4, nnz: 10 (sym: 0: nnz 0), norm: 1.11e+001
   blocks: 1 singletons: 0 structural rank: 4
   QR   natural    time:     0.00 resid: 1.15e-017
   QR   amd(A'*A)  time:     0.00 resid: 1.53e-017
   LU   natural    time:     0.00 resid: 1.04e-017
   LU   amd(A+A')  time:     0.00 resid: 4.94e-018
   LU   amd(S'*S)  time:     0.00 resid: 4.94e-018
   LU   amd(A'*A)  time:     0.00 resid: 4.94e-018


Open and build
--------------

You can check all the csparse examples in |examples_csparse|.

Give it a quick try following the next steps.

Create a new project and open the examples.

.. code-block:: bash

  ~$ bii init csparse_example
  ~$ cd csparse_example
  ~$ bii open examples/csparse
  ~$ bii build

Execute any you want, for example, read a matrix saved in a file and solve a linear system:

.. code-block:: bash

  $ cd bin
  $ examples_csparse_cs_demo2 < ../blocks/examples/csparse/Matrix/t1

  --- Matrix: 4-by-4, nnz: 10 (sym: 0: nnz 0), norm: 1.11e+001
  blocks: 1 singletons: 0 structural rank: 4
  QR   natural    time:     0.00 resid: 1.15e-017
  QR   amd(A'*A)  time:     0.00 resid: 1.53e-017
  LU   natural    time:     0.00 resid: 1.04e-017
  LU   amd(A+A')  time:     0.00 resid: 4.94e-018
  LU   amd(S'*S)  time:     0.00 resid: 4.94e-018
  LU   amd(A'*A)  time:     0.00 resid: 4.94e-018


.. |bii_csparse| raw:: html

   <a href="https://www.biicode.com/tdavis/tdavis/csparse/master" target="_blank">tdavis/csparse</a>

.. |fork_csparse| raw:: html

   <a href="https://github.com/davidsanfal/csparse" target="_blank">github repo</a>

.. |examples_csparse| raw:: html

   <a href="https://www.biicode.com/examples/examples/csparse/master" target="_blank">examples/csparse block</a>