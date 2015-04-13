.. _cmakelists_txt:

Where is biicode´s *"magic"*?
-----------------------------

**bii configure** or **bii build** commands generate a *CMakeLists.txt* file in each block.

*CMakeLists.txt* has 1 line by default (stripping out comments):

.. code-block:: cmake

    ADD_BII_TARGETS()
..


  So biicode:

  + Detects how source code files are connected and builds a dependency graph (following #includes and searching for implementations). 
  + Generates, for each block, a *CMakeLists.txt* defining some variables in accordance to the detected dependency graph. These variables allow Biicode to "plug" your library to its cloud so it will be easily reused.
  + Builds a **library** for each block you have in your project (including each dependency).
  + Builds an **executable** for each file with a ``main()`` function.
  + Link the block's **library** to all **executables** within the block.
  + Builds the block's library **only** with the source code files needed, according to detected dependencies (how files are connected).


Define and prepare targets
---------------------------

In the *CMakeLists.txt*  file, before ``ADD_BII_TARGETS()`` you can adjust:

Which source code files are part of the **block's library**
===========================================================

``BII_LIB_SRC`` contains all the source code biicode adds to the library (through CMake *add_library*)

  **EXAMPLE**: Exclude *my_file.cpp* from being compiled in the block's library.

  .. code-block:: cmake

     # Remove my_file.cpp from being compiled in library
     LIST(REMOVE_ITEM BII_LIB_SRC my_file.cpp) 

     ADD_BII_TARGETS()


  **EXAMPLE**: Include **other_file.cpp** to be compiled in the block library.

  .. code-block:: cmake

     # Include my_file.cpp to be compiled in library
     LIST(APPEND BII_LIB_SRC other_file.cpp) 

     ADD_BII_TARGETS()

  .. container:: infonote

     **ESSENTIAL TIP**: If biicode didn't add a file needed to your block's library, you can specify this dependency in the ``[dependencies]`` section of the *biicode.conf* file. *Why?* This way you wire the dependency (fixing the dependency graph). If someone depends on your library, biicode will also download the missing file and will add it to ``BII_LIB_SRC`` automatically. Otherwise file won't be downloaded and their build will fail.


Choose STATIC or SHARED **library** 
===================================

``BII_LIB_TYPE`` value is empty by default (turns out it is STATIC in most cases). It can be either ``STATIC`` or ``SHARED``.  

  **EXAMPLE**: Making a *shared* library (.dll, .so):

  .. code-block:: cmake

      SET(BII_LIB_TYPE SHARED)

      ADD_BII_TARGETS()


Modify which executable targets are made
========================================

``BII_BLOCK_EXES`` List of executable targets (mains). Each "exe" matches this pattern: *path_to_mainfile*. 

For example, if the block *lasote/game* has a *main.cpp* in a folder named "src" the variable will have an element: "src_main"  

  **EXAMPLE**: Prevent biicode from creating an EXE target for *(examples/src/my_program.cpp)*:

  .. code-block:: cmake

      LIST(REMOVE_ITEM BII_BLOCK_EXES examples_src_my_program)

      ADD_BII_TARGETS()

  .. container:: infonote

     You can also do this by adding ``!examples_src_my_program`` line to ``[mains]`` :ref:`section <mains_conf>`.


Which source code files are part of each **executable**
=======================================================

``BII_exe_name_SRC`` contains all source code that will be added to the exe. "exe_name" matches this pattern: *path_to_mainfile*.

For example, if the block *lasote/game* has a *main.cpp* in a folder named "src" the variable will be: "BII_src_main_SRC"  
  
  **EXAMPLE**: Exclude *my_file.cpp* from being compiled with *examples/main.cpp* executable.

  .. code-block:: cmake

      LIST(REMOVE_ITEM BII_examples_main_SRC my_file.cpp) 

      ADD_BII_TARGETS()


Modify which test targets are made
==================================

``BII_BLOCK_TESTS`` is a subset of BII_BLOCK_EXES and contains the executables specified in [tests] section of *biicode.conf* file.

  **EXAMPLE**: Exclude *tests/one.cpp* from tests.

  .. code-block:: cmake

      LIST(REMOVE_ITEM BII_BLOCK_TESTS tests_one) 

      ADD_BII_TARGETS()

Configure targets
-----------------

Once we have selected which files belong to each target and the targets we want, we are ready to call **ADD_BII_TARGETS()**.

This will generate the block's **library** target and a target for each **executable**.

Configure **library** target
============================

``BII_LIB_TARGET`` contains the name of the block's library target. This target may be an ``INTERFACE`` target (no source files) if ``BII_LIB_SRC`` is empty before ``ADD_BIICODE_TARGETS`` call. For this reason we recommend you to always use ``BII_BLOCK_TARGET``.

``BII_BLOCK_TARGET``: :underline:`Use this better, instead of BII_LIB_TARGET`. Created to ease target configuration. It always exists and it's always a CMake **Interface**. Represents the whole block and it is applied to ``BII_LIB_TARGET`` and *each target executable*.

  **EXAMPLE**: Linking with pthread.

  .. code-block:: cmake
     
     # Link against the always existing BII_BLOCK_TARGET
     TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGET} INTERFACE pthread)
     # or link against the library (if it's not an interface we specify PUBLIC attribute to propagate the configuration)
     TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC pthread)

  .. container:: infonote

     You can also do this by adding pthread to ``${BII_LIB_DEPS}`` before calling ``ADD_BII_TARGETS()``


  **EXAMPLE**: Adding include directories to all targets of this block.

  .. code-block:: cmake
   
    TARGET_INCLUDE_DIRECTORIES(${BII_BLOCK_TARGET} INTERFACE myincludedir)

    # You can also add private include directories to the Lib (if existing)
    TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} PRIVATE myincludedir)

  .. container:: infonote

     You can also do this by adding ``myincludedir`` line to ``[paths]`` :ref:`section <paths_conf>`.


  **EXAMPLE**: How to activate C++11 for all targets (including lib target).

  .. code-block:: cmake
     
     IF(APPLE)
        TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11 -stdlib=libc++")
     ELSEIF (WIN32 OR UNIX)
        TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11")
     ENDIF(APPLE)

  **EXAMPLE**: Adding compile definitions to all targets (including lib target).

  .. code-block:: cmake

     TARGET_COMPILE_DEFINITIONS(${BII_BLOCK_TARGET} PUBLIC "MY_DEFINITION=1")


  **EXAMPLE**: Setting properties to lib target.

  .. code-block:: cmake
   
     SET_TARGET_PROPERTIES(${BII_LIB_TARGET} PROPERTIES COMPILE_DEFINITIONS "IOV_MAX=255")


  .. container:: infonote

     ``SET_TARGET_PROPERTIES`` only allows setting some white-listed properties to BII_BLOCK_TARGET, because it is an interface. Use ``BII_LIB_TARGET`` to set target properties.
     

Configure **executable** target
===============================

``BII_exe_name_TARGET`` contains the name of the target for each executable target. Each "exe" matches this pattern: *path_to_mainfile*.

  **EXAMPLE**: Linking pthread to an executable target (file: *examples/one.cpp*):

  .. code-block:: cmake
     
     TARGET_LINK_LIBRARIES(${BII_examples_one_TARGET} PUBLIC pthread)

  **EXAMPLE**: Adding compile definitions to an executable target (file: *my_main.cpp*).

  .. code-block:: cmake

     TARGET_COMPILE_DEFINITIONS(${BII_my_main_TARGET} PUBLIC "MY_DEFINITION=1")

  .. container:: infonote

     When someone depends on your library, biicode only downloads the required files (according to the dependency graph). So you can't assume that ``${BII_my_main_TARGET}`` target will exist. If you reference a target that doesn't exist build will fail. Whenever it is possible it's better to not act upon EXE targets. Remember that ``BII_BLOCK_TARGET`` will be applied to each target in your block. 

     It's best to act upon ``BII_BLOCK_TARGET``.


Select build type: Debug or Release
-----------------------------------

You can set the build type with *-D option* in **bii configure** command:

.. code-block:: sh

    $ bii configure -DCMAKE_BUILD_TYPE=DEBUG
    $ bii build

Possible values are: **DEBUG**, **RELEASE**, **RELWITHDEBINFO**, **MINSIZEREL**

Check official docs from |cmake_build_type|.

If you are using *Visual Studio* or any other IDE with a select list box for build type use:

.. code-block:: sh
    
    $ bii build --config=DEBUG


.. container:: infonote
     
     Use ``bii clean`` command to restore most of your project's meta-information. Here's more about :ref:`bii clean command<biiclean>`.

Complete variable reference
----------------------------

:``BII_LIB_SRC``:  List of files belonging to the library .
:``BII_LIB_TYPE``: Empty by default, (STATIC in most cases) STATIC or SHARED.
:``BII_LIB_DEPS``: Dependencies to other libraries (user2_block2, user3_blockX).
:``BII_LIB_SYSTEM_HEADERS``: System linking requirements as windows.h, pthread.h, etc.
:``BII_LIB_INCLUDE_PATHS``: List of directories that the library target will include through a call to TARGET_INCLUDE_DIRECTORIES
:``BII_BLOCK_EXES``: List of targets that represent the executables (mains) defined in this block. If you want to prevent biicode from creating an EXE target, first remove it from this list.
:``BII_exe_name_SRC``: List of files belonging to an "exe". "exe_name" matches this pattern: *path_to_mainfile*. For example, if the block *lasote/game* has a *main.cpp* in a folder named "src" the variable will be: ``BII_src_main_SRC``  
:``BII_exe_name_DEPS``: Dependencies of this "exe" target to other libraries, including its own block library if any (user2_block2, user3_blockX). 
:``BII_BLOCK_TESTS``: List of executables specified in ``[tests]`` section of *biicode.conf* file. Will be excluded from **bii build** compilation and compiled with **bii test** command. add_test

.. code-block:: cmake

    ADD_BII_TARGETS()
..

:``BII_LIB_TARGET``: Target library name, usually in the form "user_block". It may not exist if ``BII_LIB_SRC`` is empty, so better use ``${BII_BLOCK_TARGET}`` as a general rule. 
:``BII_BLOCK_TARGET``: CMake **Interface** that represents the whole block. It always exists and it's applied both library and executables (each target). You can use it to configure a block's building configuration: Link libraries, compile flags...etc 
:``BII_BLOCK_TARGETS``: List of all targets defined in the block
:``BII_exe_name_TARGET``: Executable target (listed in ``${BII_BLOCK_EXES}``) (e.g. ``${BII_main_TARGET}``. You can also use directly the name of the executable target (e.g. user_block_main)


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>


.. |cmake_build_type| raw:: html

   <a href="http://www.cmake.org/cmake/help/v3.0/variable/CMAKE_BUILD_TYPE.html" target="_blank"> CMake Build Type</a>
