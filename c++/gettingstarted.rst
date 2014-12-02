.. _cpp_getting_started:


Getting started
===============

Build your first C/C++ program and run a unit test using the |google_test_link| on biicode. You don't need to install GTest, biicode downloads and configures it automatically for you, |google_test_biicode_link|.


.. |google_test_link| raw:: html

   <a href="https://code.google.com/p/googletest" target="_blank">Google Test Framework</a>

.. |google_test_biicode_link| raw:: html

   <a href="https://www.biicode.com/google/gtest target="_blank">GTest is already in biicode!</a>



.. _cpp_create_project:

Building and running a program
-------------------------------
Make sure :ref:`biicode is installed<first_steps>`.

Create a project
^^^^^^^^^^^^^^^^

``bii init`` a folder to create a new project:

.. code-block:: bash

    ~$ bii init myproject

Use ``new`` command to create some folders and a "Hello World" C++ main file. Of course, you can do it manually too.

.. code-block:: bash

  ~$ cd myproject
  ~/myproject$ bii new myuser/myblock --hello=cpp

.. container:: infonote

    You can directly type ``myuser``, there's no need to register an account to use biicode.
    To upload and share contents, replace ``myuser`` with your real biicode username.

This is the resulting layout:

.. code-block:: text

  +-- myproject
  |    +-- bii
  |    +-- blocks
  |    |    +-- myusers
  |    |    |    +-- myblock
  |    |    |    |    +-- main.cpp
  |    +-- deps


Build and run it
^^^^^^^^^^^^^^^^
Build and run the hello world application, your first C/C++ program, to check everything works:

.. code-block:: bash

  ~/myproject$ bii cpp:build
  ...
  ~/myproject$ bin\myuser_myblock_main
  Hello World!

.. container:: infonote

    Linux/Mac users might run as:

    .. code-block:: bash

      ~/myproject$ ./bin/myuser_myblock_main



Depending on Google Test
---------------------------

Copy the following code into the **main.cpp** file:

.. code-block:: cpp
  :emphasize-lines: 1

  #include "google/gtest/gtest.h"
  
  int sum(int a, int b) {return a+b;}
  
  TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
  }
  
  int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }

This code contains a simple sum function and a test. It requires Google Test framework. If you try to ``cpp:build`` you will get a build error.

Execute ``bii find`` to find unresolved dependencies and retrieve all necessary files from servers:

.. code-block:: bash
  
  ~/myproject$ bii find


Now you're ready to build and run it:

.. code-block:: bash

  ~/myproject$ bii cpp:build
  ...
  ~/myproject$ bin\myuser_myblock_main
  [==========] Running 1 test from 1 test case.
  ...
  [----------] Global test environment tear-down
  [==========] 1 test from 1 test case ran. (15 ms total)
  [  PASSED  ] 1 test.


**That's it**, that output means Google Test was downloaded, configured and built in your project!

Check your ``deps`` folder, the GoogleTest code is there.


.. _cpp_publish_reuse:


Publishing
-----------

**Publish** to make your libs available on biicode.

.. code-block:: bash

   ~/myproject$ bii publish

   INFO: *****************************
   INFO: ***** Publishing public ****
   INFO: *****************************
   INFO: Successfully published myuser/math: 0


Enter your profile **www.biicode.com/myuser** to check what you've just uploaded.

``bii publish`` publishes your code as ``DEV``, for development and testing. 
Every time you publish over ``DEV``, you overwrite the latest ``DEV`` version.
Tags available are: **DEV, ALPHA, BETA, STABLE**. Use them with ``bii publish --tag=STABLE``.

Take a look into your **block's bii folder** (~/myproject/blocks/myuser/math/bii/parents.bii). ``parents.bii`` file tells you "who" is your parent (indicated with ``*`` symbol), it stands for the latest published version of your block.

``parents.bii`` looks like this:

.. code-block:: bash

   # This file contains your block ancestors versions
   * myuser/math: 0


Make sure you've |biicode_signup| to publish. It's **free**.

.. |biicode_signup| raw:: html
   
   <b><a href="https://www.biicode.com/accounts/signup" target="_blank">got an account</a></b>


Reusing
--------

Write reusable code
^^^^^^^^^^^^^^^^^^^
On the same project :ref:`created before<cpp_create_project>` containing ``myuser/myblock`` folders, **rename myuser folder** to your username. 
Explanations will use **"myuser"**, just replace its occurrences with your real biicode username.

It's best to also **rename "myblock" folder** to something more meaningful, like **math**, because we are building some mathematical library.

Good code-reuse practices tell us to put **sum** function in its own files:


**main.cpp**

.. code-block:: cpp

  #include "google/gtest/gtest.h"
  #include "operations.h"
  
  TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
  }
  int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }


**operations.h**

.. code-block:: cpp

  #pragma once
  int sum(int a, int b);


**operations.cpp**

.. code-block:: cpp

  #include "operations.h"
  int sum(int a, int b) {return a+b;}

And the expected layout is:

.. code-block:: text

  +-- myproject
    |    +-- blocks
    |    |    +-- myuser (remember: your actual username here)
    |    |    |    +-- math
    |    |    |    |    +-- main.cpp
    |    |    |    |    +-- operations.cpp
    |    |    |    |    +-- operations.h


Build and run your project again to check everything is ok:

.. code-block:: bash

   ~/myproject$ bii cpp:build
   ~/myproject$ bin\myuser_math_main  (your username here instead of myuser)
   ...
   [==========] 1 test from 1 test case ran. (2 ms total)
   [  PASSED  ] 1 test.


Publish your code
^^^^^^^^^^^^^^^^^

**Publish** your source code to biicode:

.. code-block:: bash

   ~/myproject$ bii publish


Check in your profile **www.biicode.com/myuser** what you've just uploaded.


Reuse your code
^^^^^^^^^^^^^^^^
Once the code is in biicode, you can **reuse it in any project**, even in a different computer. Let's **create a new project to try it**.

Let's build a sum calculator and reuse the published **sum** function to build it:

.. code-block:: bash

   ~/myproject$ cd ..  (get out of current project)
   ~$ bii init mycalc   (create new project mycalc)
   ~$ cd mycalc
   ~/mycalc$ bii new myuser/calc --hello=cpp

Change the **main.cpp** file created with the following content:

.. code-block:: cpp

   #include <iostream>
   #include "myuser/math/operations.h" //NOTE: Replace myuser!

   using namespace std;
   int main() {
      cout<<"2 + 3 = "<< sum(2, 3)<<endl;
   }


Use ``bii find`` to let biicode find a suitable (compatible) version of our dependencies. 

.. container:: infonote

      You can also directly write them in the **bii/requirements.bii** file. 
      This example depends on your published block **myuser/math**, and it only has one version (number 0). 
      Create a folder named **bii** inside your ``~/mycalc/blocks/myuser/calc/`` and a **requirements.bii** file into it.

      .. code-block:: text

        +-- mycalc
          |    +-- blocks
          |    |    +-- myuser
          |    |    |    +-- calc
          |    |    |    |    +-- bii
          |    |    |    |    |    +-- requirements.bii
          |    |    |    |    +-- main.cpp

      Open the **requirements.bii** with any text editor and write in it:

      .. code-block:: bash

         myuser/math: 0


Build and run your application:

.. code-block:: bash

   ~/mycalc$ bii cpp:build
   ~/mycalc$ bin\myuser_calc_main
    2 + 3 = 5


.. container:: infonote

   Look into your **deps** folder, your source code is in it. And what about Google Test? Shouldn't it be there? Not really. The **sum** function does not require Google Test at all, so Google Test is not required as dependency in your new calculator project (unless you also add it to define your own unit tests of this calculator, of course)



Congrats! You have just reused your **sum** function in a new project. You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

