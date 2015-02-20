.. _cpp_blocks:


What is a block?
================

A block (also known as 'repo' or 'repository') is the place to put your code in biicode. 

Each block has a name, version, tag and owner. For example,|openssl_link| block has an owner (lasote) and latest version is 3 DEV.

.. |openssl_link| raw:: html

   <a href="http://www.biicode.com/lasote/openssl" target="_blank">OpenSSL</a>

Here's an example block structure:

.. code-block:: text

  +-- block_name/
  |   +-- src/
  |   |   +-- main.cpp
  |   +-- test/
  |   |   +-- test1.cpp 
  |   +-- biicode.conf
  |   +-- CMakeLists.txt
  |   +-- README

These are the main components of a block (under the ``block_name/`` directory):

  - Your repo's code, with its sources and folders.
  - ``CMakeLists.txt`` file, to specify your build config.
  - ``biicode.conf`` file with information about your block and its dependencies.
  - a README 

* :ref:`More information on the biicode.conf file<biicode_conf>`

* :ref:`Building Configuration your own Block <cpp_building>`

Create a block
==============

Blocks live in Biicode projects, each biicode projects can have in it as many blocks as you want. 

A project is a combination of meta-data and folders containing your blocks, dependencies and files like policies.bii to apply when finding or updating your dependencies.

Each project follows the same standard structure:

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    |    +-- policies.bii
  |    +-- blocks/
  |    |    +-- owner1/
  |    |    |    +-- blockA/
  |    |    |    |    +-- src/
  |    |    |    |    +-- include/
  |    |    |    |    +-- test/   
  |    |    |    |    +-- biicode.conf
  |    |    |    |    +-- CMakeLists.txt
  |    |    |    +-- blockB/
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- biicode.conf
  |    |    |    |    +-- CMakeLists.txt
  |    |    +-- owner2/
  |    |    |    +-- blockC/
  |    |    |    |    +-- tool.h
  |    |    |    |    +-- tool.cpp
  |    |    |    |    +-- biicode.conf
  |    |    |    |    +-- CMakeLists.txt
  |    +-- deps/
  
This structure empowers consistency between the blocks published in biicode, it also enables working with different owner/blocks at the same time.

.. container:: infonote
     
     Tips naming your block:
        * Use underscores for multiple words
        * Use lowercase letters (Newbies will thank this as OS X and Windows have case-insensitive filesystems by default)
        * ref:`Tag your STABLE versions <version_tags>`_





biicode.conf
^^^^^^^^^^^^

This is an example of a biicode.conf file: ::

      # Biicode configuration file

      [requirements]
        # Blocks and versions this block depends on
        diego/glfw: 1
        google/gtest: 9

      [parent]
        owner/block: 0

      [paths]
          # Local directories to look for headers (within block)
          include
          src

      [dependencies]
          # Manual adjust file implicit dependencies, add (+), remove (-), or overwrite (=)
          # hello.h + hello_imp.cpp hello_imp2.cpp
          # *.h + *.cpp

      [mains]
          # Manual adjust of files that define an executable
          # !main.cpp  # Do not build
          # main2.cpp # Build it 

      [hooks]
          #  add (+), remove (-), or overwrite (=) files names matching bii*stage*hook.py
          # biicode launches them as python scripts at stage = {post_process, clean}
          # CMakeLists.txt + bii/my_post_process1_hook.py bii_clean_hook.py

      [includes]
          # Mapping of include patterns
          gtest/gtest.h: google/gtest/include/gtest
          GLFW/glfw3.h: diego/glfw/include

      [data]
          # Manually define data files dependencies, that will be copied to bin for execution
          # By default they are copied to bin/user/block/...
          # image.cpp + image.jpg  # code should write open("user/block/image.jpg")

CMakeLists.txt
^^^^^^^^^^^^^^



Create a block from a git repository
------------------------------------





**Publish** your source code to biicode:

.. code-block:: bash

   ~/myproject$ bii publish --tag=STABLE


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

      You can also directly write them in the **biicode.conf** file. 
      This example depends on your published block **myuser/math**, and it only has one version (number 0). 
      Create a **biicode.conf** file inside your block:

      .. code-block:: text

        +-- mycalc
          |    +-- blocks
          |    |    +-- myuser
          |    |    |    +-- calc
          |    |    |    |    +-- biicode.conf
          |    |    |    |    +-- main.cpp

      Open **biicode.conf** file with any text editor and write in it:

      .. code-block:: bash

         [requirements]
            myuser/math:0


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



