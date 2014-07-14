.. _cpp_getting_started:

C/C++
=====

This example shows **how to install biicode and code a C++ test with Google Test Library**. You don't need to install GTest, biicode will download and configure it automatically for you.

Use Gtest functions just by including the ``gtest.h`` file of the ``gtest`` block from ``google`` user, with the code line ``#include "google/gtest/gtest.h"`` .

1. Installing biicode and C/C++ tools
-------------------------------------

First of all, install biicode and a group of helpful external tools (CMake and MinGW, Visual Studio or GCC).

   - Download biicode installer.

+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|Latest version 1.0                                                                                                                                                                                                                                                                                                           |
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+
|`MacOS <https://www.biicode.com/downloads>`_        |`Raspberry Pi <https://www.biicode.com/downloads>`_ |`Ubuntu 32 <https://www.biicode.com/downloads>`_    |`Ubuntu 64 <https://www.biicode.com/downloads>`_    |`Windows <https://www.biicode.com/downloads>`_      |`Devian Wheezy <https://www.biicode.com/downloads>`_|
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+


   - Execute ``bii setup:cpp`` in your console and all the C++ tools will be installed automatically.

.. code-block:: bash

   ~$ bii setup:cpp

.. container:: infonote

    If you encounter any problem installing the C/C++ tools, check :ref:`how to install C/C++ tools manually <cpp_installation>`

2. Create your project
----------------------

To create a new project execute ``bii init <project_name>`` with the project name as a parameter.

.. code-block:: bash

   ~$ bii init cpp_hello_project

This command will create the following layout:

.. code-block:: text

   |-- cpp_hello_project
   |    +-- bii
   |    +-- blocks
   |    +-- deps

Now, create a block to place your code. Execute ``bii new anonymous/my_fist_block`` into the project folder to create a block.

.. code-block:: bash

   ~$ cd cpp_hello_project
   ~/cpp_hello_project$ bii new anonymous/my_first_block --hello=cpp

.. container:: infonote

    **why anonymous/my_first_block?**

    Because you distinguish a block by its owner's user-name and the block name. ``anonymous/my_first_block`` is what you write when you are not registered yet, but to publish your own blocks, you need to use your biicode user name.

    To change the user-name of a block, just edit the folders name: from anonymous to your user name.

This command creates the following layout:

.. code-block:: text

   +-- cpp_hello_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- anonymous
   |    |    |    +-- my_first_block
   |    |    |    |    +-- main.cpp
   |    +-- deps

.. container:: infonote

    **What's the reason behind this layout?**

    With this layout, biicode analyzes your block's dependencies and downloads them into the deps folder. It is also used to configure and build your project.

3. Resolve your dependencies
----------------------------

Copy the following code into the main.cpp file and execute ``bii find`` to download your dependencies:

**main.cpp**

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

.. code-block:: bash

   ~/cpp_hello_project$ bii find

Now, execute ``bii cpp:build``, this configures your project and compiles your code into the bin folder.

.. code-block:: bash

   ~/cpp_hello_project$ bii cpp:build

And that's all. Your program is working, you can open your bin folder and execute!

**Quick Tip** to execute your code in the terminal:

.. code-block:: bash

   ~/cpp_hello_project$ cd bin
   ~/cpp_hello_project/bin$ #execute your test

.. container:: todo

    To learn more about C/C++ & biicode, check the :ref:`C/C++ section <cpp-index>`.
