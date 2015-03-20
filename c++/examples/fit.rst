.. _fit:


fit
===

|fit_homepage| is a C++11 header-only library that provides utilities for functions and function objects. Fit is divided into three components: 

  1. Function Adapters: These take functions and return a new function that provides an additional capability to the previous function.

  2. Functions: These return functions that achieve a specific purpose.

  3. Utilities: These are general utilities that are useful when defining or using functions.

The main block is |bii_fit|, which is generated from this |fork_fit|.

Tests
^^^^^

Calculate giving the coordinates, the angles and sides length of a polygon between 3 and 10 vertex. To start, create a project, open the example and execute:

**Note:** If you are using CLANG you may need to use  ``clang --version`` to check it's higher than 3.5.

.. code-block:: bash

   ~$ bii init fit
   ~$ cd fit
   ~/fit$ bii open examples/fit
   ~/fit$ bii build
   ~/fit$ #execute the tests on bin folder


Now let's check the code, **open one of the test files (test/always.cpp)** :

.. code-block:: cpp

  #include <fit/always.h>
  #include <memory>
  #include "test.h"

  FIT_TEST_CASE()
  {
      static const int ten = 10;
     FIT_STATIC_TEST_CHECK(fit::always(ten)(1,2,3,4,5) == 10);
     FIT_TEST_CHECK( fit::always(ten)(1,2,3,4,5) == 10 );
  }



Execute the binary and this is how the output looks like:

.. code-block:: bash

  ~/fit$ bin/examples_fit_test_always
  **CORRECT** fit::always(ten)(1,2,3,4,5) == 10


The output is what always.cpp file is testing, if successes it writes **CORRECT**, if it doesn't it writes **FAILED**. 


Didn't work? No problem, read or contact us in |biicode_forum_link|.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>



Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">Write us!</a>

.. |fit_homepage| raw:: html

   <a href="http://pfultz2.github.io/Fit/doc/html/" target="_blank">fit</a>

.. |bii_fit| raw:: html

   <a href="https://www.biicode.com/examples/fit" target="_blank">FIT block</a>

.. |fork_fit| raw:: html

   <a href="https://github.com/pfultz2/Fit" target="_blank">github repo</a>
.. _estl-teaser: