.. _cpp_edit_update:


Edit and update blocks
=========================

After reusing your **sum function** explained at :ref:`previous section <cpp_publish_reuse>`, you could want to add some new functions to your published "math" block, e.g. a **subtract function**, and use it in your block **maya/calc** app. The next steps explain you how to do it.


1. Edit your dependencies
--------------------------

Now, your layout is something like this:

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- maya
  |    |    |    +-- calc
  |    |    |    |    +-- bii
  |    |    |    |        +-- requirements.bii 
  |    |    |    |    +-- main.cpp
  |    +-- deps
  |    |    +-- maya
  |    |    |    +-- math
  |    |    |    |    +-- addition.cpp
  |    |    |    |    +-- addition.h


We are going to add a new function, **subtract**, to our  published **maya/math** block. To edit the ``last version`` published and the ``master`` branch, execute:

.. code-block:: bash

  ~/mycalc$ bii open maya/math

This command retrieves the complete block uploaded in biicode and delete it from your ``deps`` folder.

.. container:: infonote

  Learn more about :ref:`editing your published blocks <edit_dependecies>`

Then your layout'll change to this:

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- maya
  |    |    |    +-- calc
  |    |    |    |    +-- bii
  |    |    |    |        +-- requirements.bii 
  |    |    |    |    +-- main.cpp
  |    |    |    +-- math
  |    |    |    |    +-- bii
  |    |    |    |        +-- parents.bii 
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- addition.cpp
  |    |    |    |    +-- addition.h
  |    +-- deps

So, we can already add the new functionality and unit test for **maya/math** block. Create the next files and change the main.cpp to test the **subtract function**.

**decrease.h**

.. code-block:: cpp

  #pragma once
  int subtract(int a, int b);


**decrease.cpp**

.. code-block:: cpp

  #include "decrease.h"
  int subtract(int a, int b){return a-b;}

**main.cpp**

.. code-block:: cpp
  :emphasize-lines: 3,7,8,9

  #include "google/gtest/gtest.h"
  #include "addition.h"
  #include "decrease.h"
  TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
  }
  TEST(Subtract, Normal) {
    EXPECT_EQ(-1, subtract(2, 3));
  }
  int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }


Build with ``bii cpp:build`` and run your project again to check everything is ok.


2. Publish your updated code
------------------------------

Then, if you are sure of your code, you could **upload it using the STABLE tag** and explain the block with a brief message:

.. code-block:: bash

  ~/mycalc$ bii publish maya/math --tag STABLE --msg "Simple C++ math functions library tested with GTest one"

Your block version would be ``1`` and its tag, ``STABLE``, and if you take a look to your :ref:`parents.bii file <parents_bii>`, this'll have updated automatically:

.. code-block:: bash

  # This file contains your block ancestors versions
  * maya/math: 1


3. Close the editing block 
----------------------------

When you've finished editing and publishing the **maya/math** block, you can "close" it and it'll return, with the code already updated, to your ``deps`` folder:

.. code-block:: bash

  ~/mycalc$ bii close maya/math

But what happens with **maya/calc** block? As its dependencies has been updated, your :ref:`requirements.bii <requirements_bii>` file's done too:

.. code-block:: text

  maya/math: 1

Then if you modify the content of your **maya/calc block main.cpp**:

**main.cpp**

.. code-block:: cpp
  :emphasize-lines: 3,8

  #include <iostream>
  #include "maya/math/addition.h"
  #include "maya/math/decrease.h"

  using namespace std;
  int main() {
    cout<<"2 + 3 = "<< sum(2, 3)<<endl;
    cout<<"2 - 3 = "<< subtract(2,3)<<endl;
  }


 and build it, biicode'll update your dependencies (look at your ``~/deps/maya/math`` folder and you'll see the new files decrease.h and decrease.cpp):

.. code-block:: bash

  ~/mycalc$ bii cpp:build
  ~/mycalc$ bin\maya_calc_main
  2 + 3 = 5
  2 - 3 = -1

**Congrats! You just edited your dependencies and updated the changes**. You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_write_us| for suggestions and feedback, they are always welcomed.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>