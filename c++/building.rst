.. _cpp_building:

Build configuration
===================

Biicode uses CMake to configure and build your projects.

Biicode knows how the source code files connect to each other, with this information, biicode constructs a base CMake layout to build your project automatically.

But this automatic process is just a feature, **you can have full control over the building process**.

Here, you'll learn how to define your **CMakeLists.txt** to delve into full functionality.


.. container:: infonote
     
     Use your IDE with biicode, check the section :ref:`Generators and IDEs<generators_ide>`.


.. _cmake_introduction:
.. _cmakelists_txt:

CMakeLists.txt
----------------------

``bii cpp:configure`` command or ``bii cpp:build`` (which calls configure first), will generate all the build layout including your ``CMakeLists.txt`` file/s (one per block).

.. container:: infonote
     
     Use ``bii clean`` command to restore most of your project's meta-information. Here's more about :ref:`bii clean command<biiclean>`.


``CMakeLists.txt`` is generated in the root directory of your block (or blocks) that you have in your biicode project.

``CMakeLists.txt`` has 2 useful lines by default (stripping out comments):

.. code-block:: cmake

    # Initializes block variables
    INIT_BIICODE_BLOCK()

    # Actually create targets: EXEcutables and libraries.
    ADD_BIICODE_TARGETS()

INIT_BIICODE_BLOCK
__________________

This function initializes several variables that you can use to adapt the default behavior:

  + **${BII_BLOCK_NAME}** The name of the block, for block *myuser/myblock* its value is **myblock**
  + **${BII_BLOCK_USER}** The user name, for block *myuser/myblock* its value is **myuser**
  + **${BII_LIB_SRC}**  List of files belonging to library 
  + **${BII_LIB_TYPE}** Empty (default, STATIC most cases) STATIC or SHARED
  + **${BII_LIB_DEPS}** Dependencies to other libraries (user2_block2, user3_blockX)
  + **${BII_LIB_SYSTEM_HEADERS}** System linking requirements as windows.h, pthread.h, etc
  + **${BII_exe_name_SRC}**  List of files belonging to an exe. "exe_name" has this pattern: **path_to_mainfile**. EX: For the block *lasote/game* if there is a main.cpp in a folder named "src" the variable will be: "BII_src_main_SRC"  
  + **${BII_BLOCK_EXES}**: List of targets that represent the executables (mains) defined in this block. If you want to prevent biicode to create an EXE target, remove first from this list.

After ``INIT_BIICODE_BLOCK()`` call, we can use, modify, or override the values of these variables. 

- **EXAMPLE**: Exclude ``my_file.cpp`` to be compiled in the block library.

.. code-block:: cmake

    # Initializes block variables
    INIT_BIICODE_BLOCK()

    # Remove my_file.cpp to be compiled in library
    LIST(REMOVE_ITEM BII_LIB_SRC my_file.cpp) 
    MESSAGE(${BII_LIB_SRC}) # Print files

    # Actually create targets: EXEcutables and libraries.
    ADD_BIICODE_TARGETS()

- **EXAMPLE**: Make a *shared* library.

By default biicode builds a *static* library (.a, .lib). Let's see how to get a *shared* library (.dll, .so):

.. code-block:: cmake

    # Initializes block variables
    INIT_BIICODE_BLOCK()

    SET(BII_LIB_TYPE SHARED)

    # Actually create targets: EXEcutables and libraries.
    ADD_BIICODE_TARGETS()


ADD_BIICODE_TARGETS
___________________

This function creates the following variables:

    + **${BII_BLOCK_TARGET}**: CMake **Interface** that represents the whole block. Always exists and is applied both library and executables (each target). You can use it to configure block building configuration: Link libraries, compile flags...etc 
    + **${BII_LIB_TARGET}**: Target library name, usually in the form "user_block". May not exist if BII_LIB_SRC is empty, so use *${BII_BLOCK_TARGET}* as a general rule. 
    + **${BII_BLOCK_TARGETS}**: List of all targets defined in this block
    + **${BII_exe_name_TARGET}**: Executable target (listed in ${BII_BLOCK_EXES}) (e.g. ${BII_main_TARGET}. You can also use directly the name of the executable target (e.g. user_block_main)

- **EXAMPLE**: Add include directories to all targets of this block.

  .. code-block:: cmake
   
      TARGET_INCLUDE_DIRECTORIES(${BII_BLOCK_TARGET} INTERFACE myincludedir)

  You can add private include directories to the Lib (if existing)

- **EXAMPLE**: Link with pthread.

  .. code-block:: cmake
     
     # Link against the always existing BII_BLOCK_TARGET
     TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGET} INTERFACE pthread)
     # or link against library:
     TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC pthread)
     # or directly use the library target name:
     TARGET_LINK_LIBRARIES(user_block PUBLIC pthread)

.. container:: infonote

   This can be also done adding pthread to ${BII_LIB_DEPS} BEFORE calling ADD_BIICODE_TARGETS()


- **EXAMPLE**: How to activate C++11.

  .. code-block:: cmake
     
     IF(APPLE)
        TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11 -stdlib=libc++")
     ELSEIF (WIN32 OR UNIX)
        TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11")
     ENDIF(APPLE)

- **EXAMPLE**: Set properties to target.

  .. code-block:: cmake
   
     SET_TARGET_PROPERTIES(${BII_BLOCK_TARGET} PROPERTIES COMPILE_DEFINITIONS "IOV_MAX=255")


Binary dependencies
-------------------

You can link your block with any library that you have installed in your hard drive, although library are not in bicode.


.. container:: infonote
     
    Biicode now allows handle binary dependencies through hooks. Developers are currently uploading blocks that installs in your system the required binaries so you can ``#include`` as usual your header files and biicode will install all the libraries you need.


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

  # Define block variables
  INIT_BIICODE_BLOCK() 

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

   ~/boost_project$ bii cpp:build
   ~/boost_project$ bin/phil_boost_example_main
   Usage: server <port>


Publish, share and reuse CMake scripts
--------------------------------------

Now, biicode let's you publish, share and reuse CMake scripts.
You can reuse other user's CMake macros/functions and apply any content in your CMakeLists.txt.

Reusing CMake code is as simple as “#including” libraries in C++ with biicode. 

Edit your ``CMakeLists.txt`` file and include the CMake file from the block that you want:

.. code-block:: cmake

   # Initializes block variables
   INIT_BIICODE_BLOCK()

   INCLUDE(user/block/path_to_macros_file) # Without .cmake extension
   MACRO_NAME_TO_USE() # Macro defined in My_macros.cmake

   # Actually create targets: EXEcutables and libraries.
   ADD_BIICODE_TARGETS()
  

And execute the command:

.. code-block:: bash

  $ bii find


All the CMake dependencies will be downloaded into your project/deps/user/block folder


EXAMPLE: How to activate C++11 with already programmed macro?
______________________________________________________________


**“biicode”** featured user has a block named |biicode_cmake_block| where you can find useful macros from the  **tools.cmake** file, like one to activate C++11 flags for any OS, or to link a OSX framework to a target, etc. 

Just edit your ``CMakeLists.txt`` file, include ``INCLUDE(biicode/cmake/tools)`` and use the Macros.

CMakeLists.txt

.. code-block:: bash

    INIT_BIICODE_BLOCK()

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
-------------------------------------------------------

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

  target_compile_options(lasote_superlibrary_interface PUBLIC -std=c++11)


- **EXAMPLE**: Change a compilation option:

.. code-block:: cmake

  SET(MY_OPTION OFF CACHE BOOL "MyCoolOption" FORCE)



Maintaining independent builds
-------------------------------

Independent build
_________________


It is usual that you want to maintain a totally independent build, so your code can be also compiled without biicode.
This is fairly simple, there's a variable you can use to check it:

.. code-block:: cmake

   if(BIICODE)
      INIT_BIICODE_BLOCK()    
      ADD_BIICODE_TARGETS()  
   ELSE()
      # Your regular project configuration here
   ENDIF() 



Independent project
____________________

Biicode builds a stand alone project that can be perfectly compiled without biicode client.
This is the complete layout of a biicode project: ::


  +-- myproject
    |    +-- blocks
    |    |    +-- myuser (remember: your real username here)
    |    |    |    +-- math
    |    |    |    |    +-- CMakeLists.txt
    |    |    |    |    +-- main.cpp
    |    |    |    |    +-- operations.cpp
    |    |    |    |    +-- operations.h
    |    +-- cmake
    |    |    +-- biicode.cmake
    |    |    +-- CMakeLists.txt
    |    |    +-- bii_myuser_math_vars.cmake


Zip ``myproject`` folder and compile in other computer without biicode, just execute:

.. code-block:: bash

  $ cd myproject/cmake
  $ cmake ../build
  $ cmake --build ../build


.. container:: infonote

    `Open Sound Control Library <http://blog.biicode.com/upload-to-biicode-oscpack/>`_  adaptation is an example to understand how is CMake useful.



Build type: Debug or Release
----------------------------

You can set the build type with -D option in ``bii cpp:configure`` command:


.. code-block:: sh

    $ bii cpp:configure -DCMAKE_BUILD_TYPE=DEBUG
    $ bii cpp:build

Possible values are: **DEBUG**, **RELEASE**, **RELWITHDEBINFO**, **MINSIZEREL**

Check official docs from |cmake_build_type|.

.. _custom_toolchains:

Using a custom tool-chain
-------------------------

When you build your projects, biicode automatically generates a default tool-chain to build it.
To **use a custom tool-chain** you need to **place it in the bii folder** of your project **with the name <your_toolchain_name>-toolchain.cmake**.

To use it, just pass it as argument of ``bii cpp:configure -t your_toolchain_name``.

For example, I want to write a program to my coffee machine and I have a toolchain. First, copy my toolchai with the name coffe-toolchain.cmake into the bii folder. Then, execute ``bii cpp:configure`` with ``-t`` or ``--toolchain`` flag whith the name ``coffe``:

.. code-block:: bash

    $ bii init my_coffe_machine
    $ cd my_coffe_machine
    $ #copy coffe-toolchain.cmake into init my_coffe_machine/bii
    $ bii cpp:configure -t coffe

If you want to change the toolchain that you are using, just execute ``bii cpp:configure -t my_new_toolchain_name``

If you want to use the native environment, just execute ``bii cpp:configure -t`` without any toochain name.

There are two default toolchains you can use, the ``arduino-toolchain.cmake`` and the ``rpi-toolchain.cmake``. If you want to use one of it, just use ``bii arduino:settings`` and ``bii cpp:configure -t arduino`` or ``bii rpi:settings`` and ``bii cpp:configure -t rpi``.

.. container:: infonote

    You can learn more about the toolchains in `the CMake's docu <http://www.cmake.org/cmake/help/v3.0/manual/cmake-toolchains.7.html>`_  .


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>


.. |biicode_cmake_block| raw:: html

   <a href="https://www.biicode.com/biicode/cmake" target="_blank">cmake</a>

.. |cmake_build_type| raw:: html

   <a href="http://www.cmake.org/cmake/help/v3.0/variable/CMAKE_BUILD_TYPE.html" target="_blank"> CMake Build Type</a>
