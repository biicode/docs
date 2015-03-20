.. _cpp_getting_started:

Getting started
===============

Welcome to biicode. This guide will help you get your first biicode block off the ground.
Let's run a block with a unit test using the |google_test_link| in biicode. There's no need to install GTest, biicode downloads and configures it for you, |google_test_biicode_link| is already in biicode!

.. |google_test_link| raw:: html

   <a href="https://code.google.com/p/googletest" target="_blank">Google Test Framework</a>

.. |google_test_biicode_link| raw:: html

   <a href="https://www.biicode.com/google/gtest" target="_blank">GTest</a>

.. _cpp_create_project:

Basics
------

Make sure :ref:`biicode is installed<first_steps>`. Execute ``bii setup:cpp`` to ensure you've got all tools required.

Create your first project
-------------------------

**bii init -L** a folder to create a new project. The command below creates and inits *unit_test/* folder as a biicode project containing a block. 

.. code-block:: bash

    ~$ bii init unit_test -L
    ~$ cd unit_test
    ~/unit_test$ #create a main.cpp and a biicode.conf

Create a *main.cpp* and a *biicode.conf* file into *unit_test/* folder.

.. code-block:: text

  unit_test/
        ├── bii/
        ├── biicode.conf
        └── main.cpp

Place this code into the *main.cpp* file:

.. code-block:: cpp
  :emphasize-lines: 1

  #include "gtest/gtest.h"
  
  int sum(int a, int b) {return a+b;}
  
  TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
  }
  
  int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }

This is just a sum function and a test using Google Test framework. 
Executing **bii deps** you can see there's an unresolved dependency for *"gtest/gtest.h"*. 

Let's retrieve |google_test_biicode_link| block. It has an **owner: google** and latest version is **10 tagged STABLE**.

.. image:: /_static/img/c++/gtest_include.png

Now write the specs to retrieve this dependency in your *biicode.conf* file:

.. code-block:: text

  [requirements]
     google/gtest: 10

  [includes]
      gtest/gtest.h: google/gtest/include

.. container:: infonote

    You can also use patterns:

    .. code-block:: text

          [includes]
              gtest/*.h: google/gtest/include
    
    Or the whole #include route, executing **bii find**: 
    ``#include "google/gtest/include/gtest/gtest.h"``

Build and run it
----------------

Build and run your Unit Test, check it works:

.. code-block:: bash

  ~/$ cd unit_test
  ~/unit_test$ bii build
  ...
  ~/unit_test$ bin\user_unit_test_main
  [==========] Running 1 test from 1 test case.
  ...
  [----------] Global test environment tear-down
  [==========] 1 test from 1 test case ran. (15 ms total)
  [  PASSED  ] 1 test.

.. container:: infonote

    Linux/Mac users might run as:

    .. code-block:: bash

      ~/unit_test$ ./bin/user_unit_test_main

**That's it**, that output means Google Test was downloaded, configured and built in your project!

Check in your ``bii/deps`` folder, GoogleTest block is there:

.. code-block:: text
    :emphasize-lines: 1,2,5,6,7

    unit_test/
          ├── bii
          │   ├── build/
          │   ├── cmake/
          │   ├── deps
          │   │   └── google
          │   │       └── gtest/
          │   ├── layout.bii
          │   ├── lib/
          │   ├── policies.bii
          │   └── settings.bii
          ├── biicode.conf
          ├── bin
          │   └── user_unit_test_main
          ├── CMakeLists.txt
          └── main.cpp

Congrats! You have just used GoogleTest within your project. You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_write_us| for suggestions and feedback.

Using an IDE
------------
biicode configures your default settings to no IDE and MinGW (Windows) or UNIX Makefiles (MacOS and Linux). You can change these values executing **bii configure** before **bii build**:

  .. code-block:: bash

    ~/unit_test$ bii configure -G "Eclipse CDT4 - Unix Makefiles"
    ~/unit_test$ bii configure -G "Visual Studio 10"

Here's more about :ref:`configuring your IDE <generators_ide>`.

.. _upload-your-code:

Publishing
----------

**Publish** to make your libs available in biicode.

  * Execute **$ bii user your_username**. 

.. code-block:: bash

   ~/unit_test$ bii publish

   INFO: *****************************
   INFO: ***** Publishing public ****
   INFO: *****************************
   INFO: Successfully published your_username/unit_test: 0


Go to your profile at **www.biicode.com/your_username** to check what you've just uploaded.

.. image:: /_static/img/c++/unit_test_publishing.png


.. container:: infonote

     * Log in to edit the block's web description. 
     * Make sure you've |biicode_signup| to publish. It's **free**.

Take a look into your **block's biicode.conf file** *(~/unit_test/biicode.conf)*. ``[parent]`` section tells you  *"who is your parent version"*, the latest published version of your block and looks like this:

.. code-block:: bash

   [parent]
      your_username/unit_test: 0

Celebrate! You've just published your first block in biicode. You know that we are available at |biicode_forum_link| for any issues. You can also |biicode_write_us| for suggestions and feedback.


.. |biicode_signup| raw:: html
   
   <b><a href="https://www.biicode.com/accounts/signup" target="_blank">got an account</a></b>

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>



