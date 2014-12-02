.. _cpp_workflows:


Workflows
==========

Working with your own blocks
------------------------------

You've built a program and reused your **sum function** in the :ref:`Getting Started <cpp_publish_reuse>`. Now it's time to add new functionality to your published **myuser/math** block, like a **substract function**, and use it in your block **myuser/calc**.

The layout is:

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

Opening your block
^^^^^^^^^^^^^^^^^^^
Open the block **myuser/math** for editing on the same project, execute:

.. code-block:: bash

  ~/mycalc$ bii open myuser/math

``bii open command`` retrieves the complete block to your ``blocks`` folder, and deletes it from your ``deps`` folder.
In this case, it will open the specific version you depend on. 

The resulting layout is:

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

Now, add the new function, **substract** and use it on your main.cpp

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


Build, ``bii cpp:build`` and run your tests ``myuser_math_main`` to check everything is working.


Publishing updated code
^^^^^^^^^^^^^^^^^^^^^^^

Publish the math block again. As you now have 2 blocks opened (calc, math), specify the name of the block you want to publish:

.. code-block:: bash

   ~/mycalc$ bii publish myuser/math

By default, ``bii publish`` uses the DEV tag. Check on your online biicode profile it's been published.

Using ``DEV`` tag, the latest ``DEV`` version is overrided, so **parents.bii** file remains unmodified:

.. code-block:: bash

   # This file contains your block ancestors versions
   * myuser/math: 0


Closing edited block
^^^^^^^^^^^^^^^^^^^^

You can now close **myuser/math** block, it and it will return, with the code already updated, to your ``deps`` folder:

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

.. _edit_dependecies:


Working with any published block
---------------------------------

To **edit a published block**, follow the steps below:

Open a block
^^^^^^^^^^^^

Open a block locally to modify and publish a new version of a block.

.. code-block:: bash

  ~/$ bii init myproject
  ~/$ cd myproject
  ~/myproject$ bii open username/blockname:VERSION


**Example**

Let's open |example_block| (version=lastest by default) to edit it:

.. |example_block| raw:: html

   <a href="http://www.biicode.com/lasote/json11" target="_blank">lasote/json11 block</a>

.. code-block:: bash

  $ bii open lasote/json11 

Then you can code on it as if it was yours and changes will be reflected in your code, at build time.

Suppose that you want to open version ``1`` instead of the latest ``lasote/json11`` version, you should execute: 

.. code-block:: bash

  $ bii open lasote/json:1


Publish the changes
^^^^^^^^^^^^^^^^^^^

Once your changes build, publish your own version of the block. 

If **the block in edition isn't yours**:

  * Rename **lasote** folder with your **username**. 
  * Delete the ``parents.bii`` file.

.. container:: infonote

    Remember to ``bii cpp:build`` before publishing!

And publish:

.. code-block:: bash

  $ bii publish  

.. container:: infonote
  
  Check :ref:`bii:publish command<bii_publish_command>` to know more.


Close the block
^^^^^^^^^^^^^^^

Then you can close the block to remove it from your blocks folder:

.. code-block:: bash

  $ bii close user_name/block_name

If you're following the **Example**, execute:

.. code-block:: bash

  $ bii close user_name/json11


Depend on the block you've just published
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Now, if you want to depend on the block you've just published:

  * Update your #include (s) to the ones referring to your new published version
  * If you didn't publish it as STABLE, do it or update your :ref:`policies.bii <policies>` file to accept DEV versions.
  * Execute ``bii find`` and you're ready to build as usual. Here's :ref:`bii find command documentation<bii_find_command>`.


.. container:: infonote

  If you need more information about publish or close command:

  * :ref:`Publish command <bii_publish_command>`
  * :ref:`Close command <bii_close_command>`


**Got any doubts?** Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.