.. _bii_configure_command:


**bii configure**: configure your project
---------------------------------------------

This command analyzes your project and process dependencies, then creates or updates the required project CMake files. You can use it to specify which CMake generator you want to use. 

This command accepts all CMake directives, you could say this command is basically a **cmake** invocation within the project *build* folder.

* Use **bii configure** to :ref:`configure a project for your IDE<generators_ide>`.

* You can also :ref:`delve into specifics about building with biicode<building>`.


.. container:: infonote
     
     **bii clean** command restores your project's minimum settings, here's more about :ref:`bii clean command<biiclean>`.

Passing variables to cmake
^^^^^^^^^^^^^^^^^^^^^^^^^^

You can define a variable in your *CMakeLists.txt* and pass the value from command line.
To do this, just pass the value as a parameter of **bii configure**.

Imagine you have defined a variable name FOO in your *CMakeList.txt* and you want to define it with TRUE or FALSE.

.. code-block:: cmake

   IF(FOO)
      message(STATUS "FOO Enabled!!")
   ELSE()
      message(STATUS "FOO Disabled!!")
   ENDIF()

Define the value of FOO with the flag ``-DFOO=TRUE`` or ``-DFOO=FALSE``:

.. code-block:: bash

   $ bii configure -DFOO=TRUE
   Running: cmake  -G "MinGW Makefiles" -Wno-dev -DFOO=TRUE ../cmake

   FOO Enabled!!

Define a tool-chain
^^^^^^^^^^^^^^^^^^^

**bii configure --toolchain** command define the tool-chain to use, here's more about the :ref:`custom tool-chains <custom_toolchains>`.