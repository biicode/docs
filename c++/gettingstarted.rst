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


Congrats! You have just used GoogleTest within  your project. You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

