.. _cmakelists_txt:

Where is the biicode "magic"?
-----------------------------

``bii configure`` command or ``bii build``, will generate a ``CMakeLists.txt`` file in each block.

``CMakeLists.txt`` has 1 line by default (stripping out comments):

.. code-block:: cmake

    ADD_BIICODE_TARGETS()
..


  So Biicode:

  + detects how source code files are connected and build a dependency graph. (following #includes and searching for implementations). 
  + generate a CMakeLists.txt for each block defining some variables in accordance to detected dependency graph. These variables allows Biicode to "plug" your library to cloud so it can be easily reused.
  + builds a **library** for each block you have in your project (including each dependency).
  + builds an **executable** for each file with a ``main()`` function.
  + link the block **library** to all block **executables**.
  + builds the block library **only** with the source code files that are needed, according to detected dependencies (how files are connected).


Define and prepare targets
---------------------------

In ``CMakeLists.txt``  file, before **ADD_BIICODE_TARGETS()** you can adjust:

Which source code files are part of the block **library**
===========================================================

  **BII_LIB_SRC** contains all source code that will be added to library (through CMake *add_library*)

  **EXAMPLE**: Exclude ``my_file.cpp`` to be compiled in the block library.

  .. code-block:: cmake

     # Remove my_file.cpp to be compiled in library
     LIST(REMOVE_ITEM BII_LIB_SRC my_file.cpp) 

     ADD_BIICODE_TARGETS()


  **EXAMPLE**: Include ``other_file.cpp`` to be compiled in the block library.

  .. code-block:: cmake

     # Remove my_file.cpp to be compiled in library
     LIST(APPEND BII_LIB_SRC other_file.cpp) 

     ADD_BIICODE_TARGETS()

  .. container:: infonote

     **IMPORTANT TIP**: In case that biicode has not added a needed file to your your block library, you better specify the dependency in [dependencies] section of ``biicode.conf`` file. Why? This way you wire the dependency (fixes the dependency graph). If someone depends on your library, biicode will download the missing file and will add it to ``BII_LIB_SRC`` automatically. Otherwise file won't be downloaded and build will fail.


Select STATIC or SHARED **library** 
===================================

  **BII_LIB_TYPE** Empty by default (STATIC most cases). STATIC or SHARED  

  **EXAMPLE**: Make a *shared* library (.dll, .so):

  .. code-block:: cmake

      SET(BII_LIB_TYPE SHARED)

      ADD_BIICODE_TARGETS()


Modify which executable targets are made
========================================

  **BII_BLOCK_EXES** List of executables targets (mains). Each "exe" has this pattern: **path_to_mainfile**. EX: For the block *lasote/game* if there is a main.cpp in a folder named "src" the variable will have an element: "src_main"  

  **EXAMPLE**: Prevent biicode to create an EXE target (examples/src/my_program.cpp):

  .. code-block:: cmake

      LIST(REMOVE_ITEM BII_BLOCK_EXES examples_src_my_program)

      ADD_BIICODE_TARGETS()

Which source code files are part of each **executable**
=======================================================

  **BII_exe_name_SRC** contains all source code that will be added to the exe. "exe_name" has this pattern: **path_to_mainfile**. EX: For the block *lasote/game* if there is a main.cpp in a folder named "src" the variable will be: "BII_src_main_SRC"  
  
  **EXAMPLE**: Exclude ``my_file.cpp`` to be compiled with *examples/main.cpp* executable.

.. code-block:: cmake

    LIST(REMOVE_ITEM BII_examples_main_SRC my_file.cpp) 

    ADD_BIICODE_TARGETS()
..


Modify which test targets are made
==================================
  **BII_BLOCK_TESTS** is a subset of BII_BLOCK_EXES and contains the executables specified in [tests] section of ``biicode.conf`` file.

  **EXAMPLE**: Exclude *tests/one.cpp* from tests.

.. code-block:: cmake

    LIST(REMOVE_ITEM BII_BLOCK_TESTS tests_one) 

    ADD_BIICODE_TARGETS()
..

Configure targets
----------------------------

Well, once we have selected with files belongs to each target and which targets we want, we are ready to call **ADD_BIICODE_TARGETS()**.
This will generate the block **library** target and a target for each **executable**.

Configure **library** target
============================

  **BII_LIB_TARGET** contains the name of the block library target. This target can be an ``INTERFACE`` target (no source files) if ``BII_LIB_SRC`` is empty before ``ADD_BIICODE_TARGETS`` call. For this reason we recommend to always use ``BII_BLOCK_TARGET``

  **BII_BLOCK_TARGET**: :underline:`Use it instead of using BII_LIB_TARGET`. Created for ease target configuration. Always exists and is always a CMake **Interface**. Represents the whole block, its applied to BII_LIB_TARGET and each target executable.

  **EXAMPLE**: Link with pthread.

  .. code-block:: cmake
     
     # Link against the always existing BII_BLOCK_TARGET
     TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGET} INTERFACE pthread)
     # or link against library (if its not an interface we specify PUBLIC attribute for propagate the configuration)
     TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC pthread)

  .. container:: infonote

     This can be also done adding pthread to ${BII_LIB_DEPS} BEFORE calling ADD_BIICODE_TARGETS()


  **EXAMPLE**: Add include directories to all targets of this block.

  .. code-block:: cmake
   
    TARGET_INCLUDE_DIRECTORIES(${BII_BLOCK_TARGET} INTERFACE myincludedir)
    # You can also add private include directories to the Lib (if existing)
    TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} PRIVATE myincludedir)


  **EXAMPLE**: How to activate C++11 for all targets (including lib target).

  .. code-block:: cmake
     
     IF(APPLE)
        TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11 -stdlib=libc++")
     ELSEIF (WIN32 OR UNIX)
        TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11")
     ENDIF(APPLE)


  **EXAMPLE**: Add compile definitions to all targets (including lib target).

  .. code-block:: cmake

     TARGET_COMPILE_DEFINITIONS(${BII_BLOCK_TARGET} PUBLIC "MY_DEFINITION=1")


  **EXAMPLE**: Set properties to lib target.

  .. code-block:: cmake
   
     SET_TARGET_PROPERTIES(${BII_LIB_TARGET} PROPERTIES COMPILE_DEFINITIONS "IOV_MAX=255")


  .. container:: infonote

     ``SET_TARGET_PROPERTIES`` only allows set some whitelisted properties. Use BII_LIB_TARGET for set target properties.
     



Configure **executable** target
===============================

  **BII_exe_name_TARGET** contains the name of the target for each executable target. Each "exe" has this pattern: **path_to_mainfile**.

  **EXAMPLE**: Link pthread to an executable target (file examples/one.cpp):

  .. code-block:: cmake
     
     TARGET_LINK_LIBRARIES(${BII_examples_one_TARGET} PUBLIC pthread)

  **EXAMPLE**: Add compile definitions to an executable target (file my_main.cpp).

  .. code-block:: cmake

     TARGET_COMPILE_DEFINITIONS(${BII_my_main_TARGET} PUBLIC "MY_DEFINITION=1")

  .. container:: infonote

     If someone depends on your library, biicode will download only the required files (according to dependency graph). So you can't assume that ${BII_my_main_TARGET} target will exist. If you reference a target that doesn't exist build will fail. Whenever possible don't act upon EXE targets. Remember that **BII_BLOCK_TARGET** will be applied to each target in your block. Act upon **BII_BLOCK_TARGET**.


Select build type: Debug or Release
-----------------------------------

You can set the build type with -D option in ``bii configure`` command:


.. code-block:: sh

    $ bii configure -DCMAKE_BUILD_TYPE=DEBUG
    $ bii build

Possible values are: **DEBUG**, **RELEASE**, **RELWITHDEBINFO**, **MINSIZEREL**

Check official docs from |cmake_build_type|.

.. container:: infonote
     
     Use ``bii clean`` command to restore most of your project's meta-information. Here's more about :ref:`bii clean command<biiclean>`.



Complete variable reference
----------------------------

:**BII_LIB_SRC**:  List of files belonging to library .
:**BII_LIB_TYPE**: Empty (default, STATIC most cases) STATIC or SHARED.
:**BII_LIB_DEPS**: Dependencies to other libraries (user2_block2, user3_blockX).
:**BII_LIB_SYSTEM_HEADERS**: System linking requirements as windows.h, pthread.h, etc.
:**BII_LIB_INCLUDE_PATHS**: List of directories that the library target will include through a call to TARGET_INCLUDE_DIRECTORIES
:**BII_BLOCK_EXES**: List of targets that represent the executables (mains) defined in this block. If you want to prevent biicode to create an EXE target, remove first from this list.
:**BII_exe_name_SRC**: List of files belonging to an exe. "exe_name" has this pattern: **path_to_mainfile**. EX: For the block *lasote/game* if there is a main.cpp in a folder named "src" the variable will be: "BII_src_main_SRC"  
:**BII_BLOCK_TESTS**: List of executables specified in [tests] section of ``biicode.conf`` file. Will be excluded from ``bii build`` compilation and compiled with ``bii test`` command. add_test


.. code-block:: cmake

    ADD_BIICODE_TARGETS()
..

:**BII_LIB_TARGET**: Target library name, usually in the form "user_block". May not exist if BII_LIB_SRC is empty, so use *${BII_BLOCK_TARGET* as a general rule. 
:**BII_BLOCK_TARGET**: CMake **Interface** that represents the whole block. Always exists and is applied both library and executables (each target). You can use it to configure block building configuration: Link libraries, compile flags...etc 
:**BII_BLOCK_TARGETS**: List of all targets defined in this block
:**BII_exe_name_TARGET**: Executable target (listed in ${BII_BLOCK_EXES}) (e.g. ${BII_main_TARGET}. You can also use directly the name of the executable target (e.g. user_block_main)




**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>


.. |biicode_cmake_block| raw:: html

   <a href="https://www.biicode.com/biicode/cmake" target="_blank">cmake</a>

.. |cmake_build_type| raw:: html

   <a href="http://www.cmake.org/cmake/help/v3.0/variable/CMAKE_BUILD_TYPE.html" target="_blank"> CMake Build Type</a>
