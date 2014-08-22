.. _cpp_edit_update:


Editing published code
======================

After reusing your **sum function** explained at :ref:`previous section <cpp_publish_reuse>`, 
you could want to add some new functions to your published "math" block, e.g. a **substract function**, and use it in your block **myuser/calc** app.

You could do it in your **myproject** project, and publish from it. But imagine that you develop such project
in a different computer, and you do not have a copy.

Biicode let you open, modify and publish a new version of an already published block in your current project.
Next steps explain how to do it.


1. Open and edit your dependencies
----------------------------------

Following with the previous example, your layout is something like this:

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    +-- deps
  |    |    +-- myuser
  |    |    |    +-- math
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h


We are going to add a new function, **substract**, to our published **myuser/math** block.
To open the block **myuser/math** for edition, execute:

.. code-block:: bash

  ~/mycalc$ bii open myuser/math

This command retrieves the complete block to your ``blocks`` folder, and deletes it from your ``deps`` folder.
In this case, it will open the specific version you depend on. 

Then your layout will change to this:

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    |    |    +-- math
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h
  |    +-- deps

Now, we can add the new functionality and change the main.cpp to test the **substract** function.

**operations.h**

.. code-block:: cpp

   #pragma once
   int sum(int a, int b);
   int substract(int a, int b);

**operations.cpp**

.. code-block:: cpp

   #include "operations.h"
   int sum(int a, int b) {return a+b;}
   int substract(int a, int b){return a-b;}


**main.cpp**

.. code-block:: cpp

   #include "google/gtest/gtest.h"
   #include "operations.h"
   
   TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
   }
   TEST(Subtract, Normal) {
    EXPECT_EQ(-1, substract(2, 3));
   }
   int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
   }


You can build with ``bii cpp:build`` and run your tests ``myuser_math_main`` again to check everything is fine.


2. Publish updated code
-----------------------

Now we can publish the math block again. As now we have 2 opened blocks (calc, math), we have
to specify the name of the block that we want to publish:

.. code-block:: bash

   ~/mycalc$ bii publish myuser/math

Remember that publish by default is done with the DEV tag, so it overwrites your last published version.
You can check that it has been updated in your biicode web profile.
A new version is not created and thus **parents.bii** file remains unmodified:

.. code-block:: bash

   # This file contains your block ancestors versions
   * myuser/math: 0


3. Close edited block
---------------------

You can now close the **myuser/math** block, it and it will return, with the code already updated, to your ``deps`` folder:

.. code-block:: bash

   ~/mycalc$ bii close myuser/math


Then you can modify the content of your **myuser/calc**:

**main.cpp**

.. code-block:: cpp
   
   #include <iostream>
   #include "myuser/math/operations.h"
   
   using namespace std;
   int main() {
      cout<<"2 + 3 = "<< sum(2, 3)<<endl;
      cout<<"2 - 3 = "<< substract(2,3)<<endl;
   }


and build it, reusing also the new function:

.. code-block:: bash

   ~/mycalc$ bii cpp:build
   ~/mycalc$ bin\myuser_calc_main
   2 + 3 = 5
   2 - 3 = -1

Congrats! You just edited your dependencies and updated the changes. 
You know that we are available at |biicode_forum_link| for any problems.
You can also |biicode_write_us| for suggestions and feedback, they are always welcomed.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>