.. _advanced_build_configuration:

Advanced build configuration
--------------------------------------

Hello

Publish, share and reuse CMake scripts
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Now, biicode let's you publish, share and reuse CMake scripts.
You can reuse other user's CMake macros/functions and apply any content in your CMakeLists.txt.

Reusing CMake code is as simple as “#including” libraries in C++ with biicode. 

Edit your ``CMakeLists.txt`` file and include the CMake file from the block that you want:

.. code-block:: cmake

   INCLUDE(user/block/path_to_macros_file) # Without .cmake extension
   MACRO_NAME_TO_USE() # Macro defined in My_macros.cmake

   # Actually create targets: EXEcutables and libraries.
   ADD_BIICODE_TARGETS()
  

And execute the command:

.. code-block:: bash

  $ bii find


All the CMake dependencies will be downloaded into your project/deps/user/block folder


EXAMPLE: How to activate C++11 with already programmed macro?
_____________________________________________________________


**“biicode”** featured user has a block named |biicode_cmake_block| where you can find useful macros from the  **tools.cmake** file, like one to activate C++11 flags for any OS, or to link a OSX framework to a target, etc. 

Just edit your ``CMakeLists.txt`` file, include ``INCLUDE(biicode/cmake/tools)`` and use the Macros.

CMakeLists.txt

.. code-block:: bash

    # Including tools.cmake from biicode/cmake user block
    # see https://www.biicode.com/biicode/cmake
    INCLUDE(biicode/cmake/tools)

    ADD_BIICODE_TARGETS()

    # Calling specific macro to activate c++11 flags
    ACTIVATE_CPP11(INTERFACE ${BII_BLOCK_TARGET})


Remember to make ``bii find`` to download the dependency.

.. code-block:: bash

    $ bii find
 


Overriding dependencies build options and configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Why we need it?
_______________


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


You should not edit source code in deps directory, because it will be overwritten by biicode.
So we can't change the CMakeLists.txt files of our dependencies directly.


How does it work?
_________________


Create a file named ``bii_deps_config.cmake`` in your block (my_user/my_block) and write inside the CMake code you need.
You can act upon dependency target following this naming rule:

  ``[USER]_[BLOCK]_interface``


For example, if we have ``lasote/superlibrary`` block as a dependency, we can refer to it using this interface name:  

  ``lasote_superlibrary_interface``


- **EXAMPLE**: Activate C++ 11 in the dependency ``lasote/superlibrary`` block:

.. code-block:: cmake

  target_compile_options(lasote_superlibrary_interface INTERFACE -std=c++11)


- **EXAMPLE**: Change a compilation option:

.. code-block:: cmake

  SET(MY_OPTION OFF CACHE BOOL "MyCoolOption" FORCE)




Example: Boost
______________


Make sure you've installed Boost C++ library.
Below, we'll cover the basic steps for building a C++11 Boost example like |boost_cpp_link|

.. |boost_cpp_link| raw:: html

   <a href="http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/example/cpp11/allocation/server.cpp" target="_blank">server.cpp</a>


To start, create a new project and open the example block:

.. code-block:: bash

   $ bii init boost_project
   $ cd boost_project
   $ bii open phil/boost_example


You can take a look at |boost_block_link| too.


.. |boost_block_link| raw:: html

   <a href="http://www.biicode.com/phil/phil/boost_example/master" target="_blank">its code online</a>


The project's layout is:

.. code-block:: text

   |-- boost_project
   |    +-- blocks
   |    |    +-- phil
   |    |    |    +-- boost_example
   |    |    |    |    +-- biicode.conf
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- main.cpp
   |    |    |    |    +-- readme.md
   |    |    |    |    +-- server.h
   |    +-- deps

``CMakeLists.txt`` contains (main.cpp content is too large to be shown):

*-- CMakeLists.txt --*


.. code-block:: cmake

  set(Boost_USE_STATIC_LIBS ON)
  find_package(Boost REQUIRED COMPONENTS system)
  # Actually create targets: EXEcutables, STATIC libraries.
  ADD_BIICODE_TARGETS()

  if(Boost_FOUND)
      target_include_directories(${BII_BLOCK_TARGET} INTERFACE ${Boost_INCLUDE_DIRS})
      target_compile_options(${BII_BLOCK_TARGET} INTERFACE ${CPP_11_FLAGS})
      IF(APPLE)
          set(CPP_11_FLAGS "-std=c++11 -stdlib=libc++")
      ELSEIF (WIN32 OR UNIX)
          set(CPP_11_FLAGS "-std=c++11")
      ENDIF(APPLE)

      IF (WIN32)
          TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGET} INTERFACE "ws2_32" "wsock32" ${Boost_LIBRARIES})
      ELSEIF(APPLE OR UNIX)
          TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGET} INTERFACE ${Boost_LIBRARIES})
      ENDIF(WIN32)
  endif()


To ensure the program is working, build and execute:

.. code-block:: bash

   ~/boost_project$ bii build
   ~/boost_project$ bin/phil_boost_example_main
   Usage: server <port>


