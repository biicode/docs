.. _cpp_building:

Build configuration
===================

Biicode uses CMake to configure and build your projects. The :ref:`basics on building configuration and IDE's<generators_ide>` is a great place to start.

Here, you'll learn how to define your **CMakeLists.txt** to delve into full functionality.


.. _cmake_introduction:

Define build targets
----------------------

``bii cpp:build`` creates a CMakeLists.txt file with default settings and tips to use it. Take ``myproject`` to check it and learn how to adapt it to your needs. To create ``my project`` follow  :ref:`the Getting Started Guide<cpp_create_project>`. Its layout is: ::


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


The ``cmake`` folder is created whenever you execute a ``bii cpp:`` command.

Your block ``myuser/math`` has a **CMakeLists.txt** file, which is the place to configure the 
building of your block, and initially has 3 useful lines (stripping out comment lines):

.. code-block:: cmake

   include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
   INIT_BIICODE_BLOCK()
   
   ADD_BIICODE_TARGETS()
   
It is usual that we want to maintain a totally independent build, so our code can be also compiled without biicode.
This is fairly simple, we have defined a variable that can be used to check it:

.. code-block:: cmake

   if(BIICODE)
      include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
      INIT_BIICODE_BLOCK()    
      ADD_BIICODE_TARGETS()  
   ELSE()
      # Your regular project configuration here
   ENDIF() 
   
Or:

.. code-block:: cmake

   if(NOT BIICODE)
      # Your regular project configuration here
      Project(...)
      cmake_minimum_required(VERSION ...)
      add_executable(...)
   ELSE()
      include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
      INIT_BIICODE_BLOCK()    
      ADD_BIICODE_TARGETS()  
   ENDIF() 
   
You can use the BIICODE cmake variable to check this in many places, or maybe just restricting a small
part of the project:

.. code-block:: cmake

   Project(...)
   cmake_minimum_required(VERSION ...)
   
   IF(BIICODE)
      include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
      INIT_BIICODE_BLOCK()     
   ENDIF() 
   
   # Lots of stuff, setting CMAKE_CXX_FLAGS, detecting environment...
   
   if(NOT BIICODE)
      add_library(...)   
      add_executable(...)
   ELSE() 
      ADD_BIICODE_TARGETS()  
   ENDIF() 


Libraries and executables
-------------------------

``CMakeLists.txt`` comments have useful tips to use it. Some variables come in handy to configure your build.
Previous example doesn't build a library as there is only 1 executable requiring those files. To build
a library anyway, we can write:

.. code-block:: cmake

   include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
   INIT_BIICODE_BLOCK()
   SET(BII_CREATE_LIB True)   
   ADD_BIICODE_TARGETS()
   
Run ``bii cpp:build`` and check that the library is indeed created.
Create a SHARED library with ``SET(BII_LIB_TYPE SHARED)`` (note that
it default creates a STATIC library, and extra work might be needed to properly build
a shared library).

When there is more than 1 executable, biicode's default CMakeLists.txt will also have``SET(BII_CREATE_LIB True)`` to create a STATIC libary. 

Check if the current block is being edited or it's a dependency using ``BII_BLOCK_PREFIX``
variable, which can be referring "blocks" or "deps" respectively.


Variables
^^^^^^^^^^

Variables are defined in the **bii_myuser_math_vars.cmake** file, it is located in the ``cmake`` folder.

``BII_BLOCK_EXES`` variable contains all the executables biicode found in the block. If ``main_win.cpp`` generates an OS specific executable, you can exclude it from building on Windows:

.. code-block:: cmake

   include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
   INIT_BIICODE_BLOCK()
   IF(NOT WIN32)
      list(REMOVE_ITEM BII_BLOCK_EXES main_win)
   ENDIF()  
   ADD_BIICODE_TARGETS()


.. container:: infonote

    `Open Sound Control Library <http://blog.biicode.com/upload-to-biicode-oscpack/>`_  adaptation is an example to understand how is CMake useful.


.. _custom_toolchains:

Using a custom toolchain
------------------------

When you bii cpp:build your projects, biicode automatically generates a default toolchain to build projets.
You can use a custom toolchain to 
To use a custom toolchain you need to place it in your block folder (and add it as a dependency in :ref:`dependencies.bii<dependencies_bii>`)
and then specify you want to use that toolchain in your :ref:`settings.bii<settings_bii>`.

For example:

.. code-block:: none

  cpp: {cross_build: ARM, generator: Unix Makefiles,
        toolchain: {path:fenix/armadillo/rpi_toolchain.cmake}}
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
        toolchain: {path: fenix/armadillo/rpi_toolchain.cmake,
                    replacements: {COMPILER_PATH: /home/julia/raspberry_cross_compilers/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian,
                                   COMPILER_NAME: gcc-linaro-arm-linux}
                   }}
  os: {arch: 64bit, family: Linux, subfamily: Ubuntu, version: '13.10'}
  rpi: {directory: armadillo, ip: 192.168.1.101, user: pi}


So people reusing your block can redefine the tokens as they need.


.. container:: infonote

    `Customizing CMake toolchain <http://blog.biicode.com/custom-cmake-toolchain/>`_  explanation in our blog.


Examples
--------------

Activate C++11
^^^^^^^^^^^^^^^^

This example shows you how to compile a simple C++11 code with the C++11 compilation flag.

To start, create a new project:

.. code-block:: bash

   ~$ bii init cpp11_project
   ~$ cd cpp11_project
   ~/cpp11_project$ 

You can :download:`download the complete example block </_static/code/cpp/cmake/cpp_11_example.zip>` and unzip it into your ``~/cpp11_project/blocks/`` folder. You can take a look at |cpp11_block_link| too.


.. |cpp11_block_link| raw:: html

   <a href="http://www.biicode.com/phil/phil/cpp_11_example/master" target="_blank">its code online</a>


The layout of the project is as follows:

.. code-block:: text

   |-- cpp11_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- phil
   |    |    |    +-- cpp_11_example
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- main.cpp
   |    +-- deps

The block contains:

*-- main.cpp --*

.. code-block:: cpp

  #include <ctype.h>
  #include <iostream>
  #include <algorithm> // std::for_each

  using namespace std;

  int main()
  {
    char s[]="Hello World!";
    int Uppercase = 0; //modified by the lambda
    for_each(s, s+sizeof(s), [&Uppercase] (char c) {
    if (isupper(c))
        Uppercase++;
    });
    cout<< Uppercase<<" uppercase letters in: "<< s<<endl;
  }


*-- CMakeLists.txt --*

.. code-block:: cmake

  # HEADER
  include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
  INIT_BIICODE_BLOCK()

  # ACTIVATING C++11 FLAG
  IF(APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
  ELSEIF (WIN32 OR UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  ENDIF(APPLE)

  ADD_BIICODE_TARGETS()


Make sure your program is working:

.. code-block:: bash

   ~/cpp11_project$ bii cpp:build
   ~/cpp11_project$ bin\phil_cpp_11_example_main
   2 uppercase letters in: Hello World!


Configure the CMake file of dependencies
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Learn how to write cmake files for your dependencies.

Just make a file named ``biicode.configure`` inside your project with the biicode macro ``BII_ADD_INTERFACE(user-name block-name)``.

For example, to compile the block mrpotato/parts with the C++ 11 flag on Linux, write a file like following:
 
*-- biicode.configure --*

.. code-block:: cmake

  #############BIICODE MACROS############
  BII_ADD_INTERFACE(mrpotato parts)
  #######################################

  target_compile_options(interface_mrpotato_parts_lib PUBLIC -std=c++11)



Add Boost dependency
^^^^^^^^^^^^^^^^^^^^^^

Make sure you've installed  Boost C++ library.
Below, we'll cover the basic steps for building a C++11 Boost example like |boost_cpp_link|:

.. |boost_cpp_link| raw:: html

   <a href="http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/example/cpp11/allocation/server.cpp" target="_blank">server.cpp</a>


To start, create a new project:

.. code-block:: bash

   $ bii init boost_project
   $ cd boost_project
   ~/boost_project$ bii new myuser/boost_project


Now, :download:`download the complete example block </_static/code/cpp/cmake/boost_example.zip>` and unzip it into your ``~/boost_project/blocks/`` folder. You can take a look at |boost_block_link| too.


.. |boost_block_link| raw:: html

   <a href="http://www.biicode.com/phil/phil/boost_example/master" target="_blank">its code online</a>


The project's layout is:

.. code-block:: text

   |-- boost_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- phil
   |    |    |    +-- boost_example
   |    |    |    |    +-- CMakeLists.txt
   |    |    |    |    +-- main.cpp
   |    +-- deps

``CMakeLists.txt`` contains (main.cpp content is too large to be shown):

*-- CMakeLists.txt --*


.. code-block:: cmake

  include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
  INIT_BIICODE_BLOCK() 

  #Activating c++11 compilation flag
  IF(APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
  ELSE () #WIN32 OR UNIX
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  ENDIF(APPLE)

  set( Boost_USE_STATIC_LIBS ON )
  # Find Boost package
  find_package(Boost REQUIRED COMPONENTS system)

  # Actually create targets: EXEcutables, STATIC libraries.
  ADD_BIICODE_TARGETS()

  # Linking with Boost libraries and including its include folders
  if(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    IF (WIN32)
      TARGET_LINK_LIBRARIES(${BII_main_TARGET} "ws2_32" "wsock32" ${Boost_LIBRARIES})
    ELSEIF(APPLE OR UNIX)
      TARGET_LINK_LIBRARIES(${BII_main_TARGET} ${Boost_LIBRARIES})
    ENDIF(WIN32)
  endif()


To ensure the program is working, build and execute:

.. code-block:: bash

   ~/boost_project$ bii cpp:build
   ~/boost_project$ bin\phil_boost_example_main
   Usage: server <port>


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

