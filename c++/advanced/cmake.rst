.. _advanced_build_configuration:

Advanced build configuration
============================

Apart from all the building with CMake tips available in :ref:`custom build configuration guide<building>`, there's also a few things that may come in handy while using biicode with CMake.

.. _reuse_cmake:

Publish, share and reuse CMake scripts
--------------------------------------

Now, biicode lets you publish, share and reuse CMake scripts.
You can reuse other user's CMake macros/functions and apply any content in your *CMakeLists.txt*.

Reusing CMake code is as simple as *#including* libraries in C++ with biicode. 

Edit your *CMakeLists.txt* file and include the CMake file from the block that you want:

.. code-block:: cmake

   INCLUDE(user/block/path_to_macros_file) # Without .cmake extension
   MACRO_NAME_TO_USE() # Macro defined in My_macros.cmake

   # Actually create targets: EXEcutables and libraries.
   ADD_BIICODE_TARGETS()
  

And run **bii find** command:

.. code-block:: bash

  $ bii find


All CMake dependencies will be downloaded into your project/deps/user/block folder

EXAMPLE: How to activate C++11 with a macro already programmed?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**biicode** featured user has a block named |biicode_cmake_block| where you can find useful macros from the  *tools.cmake* file, like one to activate C++11 flags for any OS, or to link a OSX framework to a target, etc. 

Just edit your *CMakeLists.txt* file, include ``INCLUDE(biicode/cmake/tools)`` and use the Macros.

CMakeLists.txt

.. code-block:: bash

    # Including tools.cmake from biicode/cmake user block
    # see https://www.biicode.com/biicode/cmake
    INCLUDE(biicode/cmake/tools)

    ADD_BIICODE_TARGETS()

    # Calling specific macro to activate c++11 flags
    ACTIVATE_CPP11(INTERFACE ${BII_BLOCK_TARGET})

Remember to run **bii find** to download the dependency.

.. code-block:: bash

    $ bii find

Overriding dependencies build options and configuration
-------------------------------------------------------

Sometimes you need to override some configuration of how your dependency libraries are built. 

This is the project layout when you have dependencies:

.. code-block:: text

   |-- my_project
   |    +-- blocks
   |    |    +-- my_user
   |    |    |    +-- my_block
   |    |    |    |    +-- biicode.conf
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- main.cpp
   |    +-- deps
   |    |    +-- lasote
   |    |    |    +-- superlibrary
   |    |    |    |    +-- biicode.conf
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- library.h
   |    |    |    |    +-- library.cpp
   |    |    +-- sara
   |    |    |    +-- coollibrary
   |    |    |    |    +-- biicode.conf
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- tool.h
   |    |    |    |    +-- tool.cpp


You should not edit the source code in deps directory because it will be overwritten by biicode.
As can't change the CMakeLists.txt files of our dependencies directly, here's a way to override their build configuration.  

How does it work?
^^^^^^^^^^^^^^^^^

Create a file named *bii_deps_config.cmake* in your block *(my_user/my_block/)* and write into it the CMake code you need.

You can act upon dependency target following this naming rule:

  ``[USER]_[BLOCK]_interface``


For example, if we have *lasote/superlibrary* block as a dependency, we can refer to it using this interface name:  

  ``lasote_superlibrary_interface``


- **EXAMPLE**: Activate C++ 11 in the dependency ``lasote/superlibrary`` block:

.. code-block:: cmake

  target_compile_options(lasote_superlibrary_interface INTERFACE -std=c++11)


- **EXAMPLE**: Change a compilation option:

.. code-block:: cmake

  SET(MY_OPTION OFF CACHE BOOL "MyCoolOption" FORCE)
  

We are available at |biicode_forum_link| for any issues. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>


.. |biicode_cmake_block| raw:: html

   <a href="https://www.biicode.com/biicode/cmake" target="_blank">cmake</a>