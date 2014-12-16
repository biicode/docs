.. _cpp_building:

Build configuration
===================

Biicode uses CMake to configure and build your projects.

As you could see, biicode knows how the source code files are connected each other.

So it allows biicode to construct a base CMake layout to build your project automatically.

But this automatic process does not prevent you having full control about your building process.
Here, you'll learn how to define your **CMakeLists.txt** to delve into full functionality.


.. container:: infonote
     
     If you want to use your IDE with biicode check the section :ref:`Generators and IDEs<generators_ide>`.


.. _cmake_introduction:
.. _cmakelists_txt:

CMakeLists.txt
----------------------

The command ``bii cpp:configure`` or ``bii cpp:build`` (which calls configure first), will generate all the build layout including your ``CMakeLists.txt`` file/s. 

``CMakeLists.txt`` is generated in the root directory of your block (or blocks) that you have in your biicode project.

Has 2 useful lines by default (stripping out comment lines):

.. code-block:: cmake

    # Initializes block variables
    INIT_BIICODE_BLOCK()

    # Actually create targets: EXEcutables and libraries.
    ADD_BIICODE_TARGETS()

INIT_BIICODE_BLOCK
__________________

This function exposes several variables so you can adapt the default behavior:

  + **${BII_BLOCK_NAME}** The name of the block, for block *myuser/myblock* its value is **myblock**
  + **${BII_BLOCK_USER}** The user name, for block *myuser/myblock* its value is **myuser**
  + **${BII_LIB_SRC}**  List of files belonging to library 
  + **${BII_LIB_TYPE}** Empty (default, STATIC most cases) STATIC or SHARED
  + **${BII_LIB_DEPS}** Dependencies to other libraries (user2_block2, user3_blockX)
  + **${BII_LIB_SYSTEM_HEADERS}** System linking requirements as windows.h, pthread.h, etc

After ``INIT_BIICODE_BLOCK()`` call, we can use, modify, or override the values of these variables. 

- **Example**: We want to exclude ``my_file.cpp`` to be compiled in the block library.

.. code-block:: cmake

    # Initializes block variables
    INIT_BIICODE_BLOCK()

    # Remove my_file.cpp to be compiled in library
    LIST(REMOVE_ITEM BII_LIB_SRC my_file.cpp) 
    MESSAGE(${BII_LIB_SRC}) # Print files

    # Actually create targets: EXEcutables and libraries.
    ADD_BIICODE_TARGETS()

- **Example**: make a shared library.

.. code-block:: cmake

    # Initializes block variables
    INIT_BIICODE_BLOCK()

    SET(BII_LIB_TYPE SHARED)

    # Actually create targets: EXEcutables and libraries.
    ADD_BIICODE_TARGETS()


ADD_BIICODE_TARGETS
__________________

This function creates the following variables:

    + **${BII_BLOCK_TARGET}**: CMake **Interface** that represents the whole block. Always exists and is applied both library and executables (each target). You can use it for configure block compilation globally: Link libraries, compile flags...etc 
    + **${BII_LIB_TARGET}**: Target library name, usually in the form "user_block". May not exist if BII_LIB_SRC is empty
    + **${BII_BLOCK_TARGETS}**: List of all targets defined in this block
    + **${BII_BLOCK_EXES}**: List of executables targets defined in this block
    + **${BII_exe_name_TARGET}**: Executable target (listed in ${BII_BLOCK_EXES}) (e.g. ${BII_main_TARGET}. You can also use directly the name of the executable target (e.g. user_block_main)

- **EXAMPLE**: Add include directories to all targets of this block.

  .. code-block:: cmake
   
      TARGET_INCLUDE_DIRECTORIES(${BII_BLOCK_TARGET} INTERFACE myincludedir)

  You can add private include directories to the Lib (if existing)

- **EXAMPLE**: Link with pthread.

  .. code-block:: cmake
     
     # Link agains the always existing BII_BLOCK_TARGET
     TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGET} INTERFACE pthread)
     # or link against library:
     TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC pthread)
     # or directly use the library target name:
     TARGET_LINK_LIBRARIES(user_block PUBLIC pthread)

.. container:: infonote

   This can be also done adding pthread to ${BII_LIB_DEPS} BEFORE calling ADD_BIICODE_TARGETS()


- **EXAMPLE**: how to activate C++11.

  .. code-block:: cmake
     
     IF(APPLE)
        TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11 -stdlib=libc++")
     ELSEIF (WIN32 OR UNIX)
        TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11")
     ENDIF(APPLE)

- **EXAMPLE**: Set properties to target.

  .. code-block:: cmake
   
     SET_TARGET_PROPERTIES(${BII_BLOCK_TARGET} PROPERTIES COMPILE_DEFINITIONS "IOV_MAX=255")


Binary dependencies: Boost
-----------------


.. container:: infonote
     
    Biicode now allows handle binary dependencies through hooks. Developers are currently uploading blocks that installs in your system the required binaries so you can ``#include`` as usual your header files and biicode will install all the libraries you need.



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
      IF(APPLE)
          set(CPP_11_FLAGS "-std=c++11 -stdlib=libc++")
          target_compile_options(${BII_BLOCK_TARGET} INTERFACE ${CPP_11_FLAGS})
      ELSEIF (WIN32 OR UNIX)
          set(CPP_11_FLAGS "-std=c++11")
          target_compile_options(${BII_BLOCK_TARGET} INTERFACE ${CPP_11_FLAGS})
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


CMake dependency manager
------------------------

Now, biicode works as a CMake dependency manager.
You can reuse other user's CMake macros/functions and apply any content in your CMakeLists.txt.

Reusing CMake code is as simple as “#including” libraries in C++. 

Edit your ``CMakeLists.txt`` file and include the cmake file from the block that you want:


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


All the CMake dependencies will download into your  project/deps/user/block folder


EXAMPLE: How to activate C++11 with already programmed macro?
__________________


Featured user **“biicode”** has a block named |biicode_cmake_block| where you can try useful macros from the  **tools.cmake** file, like to activate C++11 flags for any OS, link a OSX framework to a target, etc. 

Just edit your ``CMakeLists.txt`` file, include ``INCLUDE(biicode/cmake/tools)`` and use the Macros.

CMakeLists.txt

.. code-block:: bash

    INIT_BIICODE_BLOCK()

    # Including tools.cmake from biicode/cmake user block
    # see https://www.biicode.com/biicode/cmake
    INCLUDE(biicode/cmake/tools)

    ADD_BIICODE_TARGETS()

    # Calling specific macro to activate c++11 flags
    ACTIVATE_CPP11()


Remember to make ``bii find`` to download the dependency.

.. code-block:: bash

    $ bii find
 


.. _custom_toolchains:

Using a custom toolchain
------------------------

When you bii cpp:build your projects, biicode automatically generates a default toolchain to build projets.
To use a custom toolchain you need to place it in your block folder (and add it as a dependency in :ref:`dependencies.bii<dependencies_bii>`)
and then specify you want to use that toolchain in your :ref:`settings.bii<settings_bii>`.

For example:

.. code-block:: none

  cpp: {cross_build: ARM, generator: Unix Makefiles,
        toolchain: {"path":fenix/armadillo/rpi_toolchain.cmake}}
  os: {arch: 64bit, family: Linux, subfamily: Ubuntu, version: '13.10'}
  rpi: {directory: armadillo, ip: 192.168.1.101, user: pi}


As you can see you define the path to the toolchain, that path includes a block which can be in blocks or deps folders.

You can also make your toolchain customizable by defining replacements tokens, for example:

.. code-block:: none

  INCLUDE(CMakeForceCompiler)
  SET(CMAKE_SYSTEM_NAME Linux)
  SET(CMAKE_SYSTEM_VERSION 1)
  SET(CMAKE_C_COMPILER COMPILER_PATH/bin/COMPILER_NAME-gcc)
  SET(CMAKE_CXX_COMPILER COMPILER_PATH/bin/COMPILER_NAME-g++)


and then in your :ref:`settings.bii<settings_bii>`:

.. code-block:: none

  cpp: {cross_build: ARM, generator: Unix Makefiles,
        toolchain: {"path": fenix/armadillo/rpi_toolchain.cmake,
                    "replacements": {COMPILER_PATH: /home/julia/raspberry_cross_compilers/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian,
                                   COMPILER_NAME: gcc-linaro-arm-linux}
                   }}
  os: {arch: 64bit, family: Linux, subfamily: Ubuntu, version: '13.10'}
  rpi: {directory: armadillo, ip: 192.168.1.101, user: pi}


So people reusing your block can redefine the tokens as they need.


.. container:: infonote

    `Customizing CMake toolchain <http://blog.biicode.com/custom-cmake-toolchain/>`_  explanation in our blog.



Override dependency build configuration
----------------------------------------


Sometimes you need to override some configuration of how your dependency libraries are built. 

Create a file named ``bii_deps_config.cmake`` and write inside the cmake code you need.
You can act upon dependency target following this naming rule:

  ``[USER]_[BLOCK]_interface``


For example, if we have ``mrpotato/parts`` block, we can refer it using this interface name:  

  ``mrpotato_parts_interface``



- **EXAMPLE**: Activate C++ 11 in the dependency mrpotato/parts block.

.. code-block:: cmake

  target_compile_options(mrpotato_parts_interface PUBLIC -std=c++11)


- **EXAMPLE**: Change a compilation option:

.. code-block:: cmake

  SET(MY_OPTION OFF CACHE BOOL "MyCoolOption" FORCE)



Project Integration
-------------------

Independent build
_________________


It is usual that we want to maintain a totally independent build, so our code can be also compiled without biicode.
This is fairly simple, we have defined a variable that can be used to check it:

.. code-block:: cmake

   if(BIICODE)
      INIT_BIICODE_BLOCK()    
      ADD_BIICODE_TARGETS()  
   ELSE()
      # Your regular project configuration here
   ENDIF() 



Independent project
_________________

Biicode builds a stand alone project that can be perfectly compiled without biicode client.
This is the complete layout of a biicode project: ::


  +-- myproject
    |    +-- blocks
    |    |    +-- myuser (remember: your actual username here)
    |    |    |    +-- math
    |    |    |    |    +-- CMakeLists.txt
    |    |    |    |    +-- main.cpp
    |    |    |    |    +-- operations.cpp
    |    |    |    |    +-- operations.h
    |    +-- cmake
    |    |    +-- biicode.cmake
    |    |    +-- CMakeLists.txt
    |    |    +-- bii_myuser_math_vars.cmake


You can zip ``myproject`` folder and compile in other computer without biicode, just execute:

.. code-block:: bash

  $ cd myproject/cmake
  $ cmake ../build
  $ cmake --build ../build


.. container:: infonote

    `Open Sound Control Library <http://blog.biicode.com/upload-to-biicode-oscpack/>`_  adaptation is an example to understand how is CMake useful.





**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>


.. |biicode_cmake_block| raw:: html

   <a href="https://www.biicode.com/biicode/cmake" target="_blank">cmake</a>

