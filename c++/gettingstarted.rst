.. _cpp_getting_started:


Getting started
===============

This example shows how to install biicode, build your first C/C++ program, and also run a unit test using the |google_test_link|. You don't need to install GTest, biicode will download and configure it automatically for you, |google_test_biicode_link|


.. |google_test_link| raw:: html

   <a href="https://code.google.com/p/googletest" target="_blank">Google Test Framework</a>

.. |google_test_biicode_link| raw:: html

   <a href="https://www.biicode.com/google/gtest target="_blank">it is already in biicode!</a>


1. Installing biicode and C/C++ tools
-------------------------------------

First |downloads_link| and install biicode

.. |downloads_link| raw:: html

   <b><a href="https://www.biicode.com/downloads" target="_blank">download</a></b>
   

Then, open the console and type

.. code-block:: bash

   ~$ bii setup:cpp

This will help you to install required tools as CMake. We recommend starting with a plain editor (Notepad++, Sublime, Gedit) and GNU based compilers (MinGW for Windows, Gcc in Nix).

.. container:: infonote

    If any problem installing the C/C++ tools, check :ref:`how to install C/C++ tools manually <cpp_installation>`

2. Create your project
----------------------

First, create a project:

.. code-block:: bash

  ~$ bii init myproject

Then we can use the convenience ``new`` command to create some folders and a "Hello World" C++ main file. Of course, you can do it manually too.

.. code-block:: bash

  ~$ cd myproject
  ~/myproject$ bii new myuser/myblock --hello=cpp

.. container:: infonote

    You can directly type ``myuser``, there's no need to register an account to use biicode, only
    to upload and share contents. You can use other name too. 
    If you have already registered you might want to replace ``myuser``
    with your real biicode username.

This should be the resulting layout:

.. code-block:: text

  +-- myproject
  |    +-- bii
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- myblock
  |    |    |    |    +-- main.cpp
  |    +-- deps


3. Build and run your program
-----------------------------
Lets check that everything is fine by building and running the hello world application.

.. code-block:: bash

  ~/myproject$ bii cpp:build
  ...
  ~/myproject$ bin\myuser_myblock_main
  Hello World!

.. container:: infonote

    Please take into account that Linux/Mac users might run as:

    .. code-block:: bash

      ~/myproject$ ./bin/myuser_myblock_main



4. Depending on Google Test
---------------------------

Copy the following code containing a simple sum function and a test into the **main.cpp** file

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

This code requires the googletest framework. If you try to ``cpp:build`` you will get a build error.

Execute the following command to find unresolved dependencies and retrieve necessary files from servers:

.. code-block:: bash
  
  ~/myproject$ bii find


Now you can build and run it:

.. code-block:: bash

  ~/myproject$ bii cpp:build
  ...
  ~/myproject$ bin\myuser_myblock_main
  [==========] Running 1 test from 1 test case.
  ...
  [----------] Global test environment tear-down
  [==========] 1 test from 1 test case ran. (15 ms total)
  [  PASSED  ] 1 test.


That's it, if you see that output Google Test was downloaded, configured and built in your project!
You can check the ``deps`` folder, the googletest code is there.

Didn't work? Read or contact us in |biicode_forum_link|

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>



Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">Write us!</a>

