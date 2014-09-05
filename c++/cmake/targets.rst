.. _cmake_introduction:

Define build targets
====================

Biicode uses CMake to configure and build your projects. A CMakeLists.txt file has been automatically
created for you in the previous examples. Lets return back to the original ``myproject`` to check
it and learn how to adapt it to your needs. The layout is: ::

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
As explained in the CMakeLists.txt comments, there are some useful variables that you can easily use to configure your build.
In the previous example, biicode decides not to build a library as there is only 1 executable requiring those files. If we want to build
a library anyway, we can do:

.. code-block:: cmake

   include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
   INIT_BIICODE_BLOCK()
   SET(BII_CREATE_LIB True)   
   ADD_BIICODE_TARGETS()
   
You can run ``bii cpp:build`` and check that the library is indeed created. Similarly,
you can decide to create a SHARED library with ``SET(BII_LIB_TYPE SHARED)`` (note however that
the default is the STATIC library, and extra work might be needed in some cases to properly build
a shared library).

If there is more than 1 executable, biicode will decide to set to True the variable. Of course you
can deactivate it, but note that doing it inconditionally can make your block not reusable. You can
check for example if the current block is being edited or it is a dependency using the ``BII_BLOCK_PREFIX``
variable, which can be "blocks" or "deps" respectively.

There are some variables summarized in the file comments. You can read the file where these 
variables are defined, it is located in ``cmake`` folder, and named **bii_myuser_math_vars.cmake**.

For example, there is a ``BII_BLOCK_EXES`` variable that contains all the executables found in 
this block. Suppose for example, that one executable ``main_win.cpp`` is OS especific, you can exclude it from building:

.. code-block:: cmake

   include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
   INIT_BIICODE_BLOCK()
   IF(NOT WIN32)
      list(REMOVE_ITEM BII_BLOCK_EXES main_win)
   ENDIF()  
   ADD_BIICODE_TARGETS()






