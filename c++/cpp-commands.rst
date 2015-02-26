.. _bii_cpp_tools:


**bii cpp:configure**: configure your project
---------------------------------------------

This command calls ``bii work`` command to analyze your project and process dependencies, then creates or updates the required project CMake files. You can use it to specify which CMake generator you want to use. 

This command accepts all CMake directives, you could say this command is basically a ``cmake .`` invocation within the project ``build`` folder.

* Use ``bii cpp:configure`` to :ref:`configure a project for your IDE<generators_ide>`.

* You can also :ref:`delve into specifics about building with biicode.<cpp_building>`


.. container:: infonote
     
     ``bii clean`` command restores your project's minimum settings, here's more about :ref:`bii clean command<biiclean>`.

Passing variables to cmake
^^^^^^^^^^^^^^^^^^^^^^^^^^

You can define a variable in your CMakeLists.txt and pass the value from command line.
To do this, just pass the value as a parameter of ``bii cpp:configure``.

Imagine you have defined a variable name FOO in your ``CMakeList.txt`` and you want to define it with TRUE or FALSE.

.. code-block:: cmake

   IF(FOO)
      message(STATUS "FOO Enabled!!")
   ELSE()
      message(STATUS "FOO Disabled!!")
   ENDIF()

Define the value of ``FOO`` with the flag ``-DFOO=TRUE`` or ``-DFOO=FALSE``:

.. code-block:: bash

   $ bii cpp:configure -DFOO=TRUE
   Running: cmake  -G "MinGW Makefiles" -Wno-dev -DFOO=TRUE ../cmake

   FOO Enabled!!

Define a tool-chain
^^^^^^^^^^^^^^^^^^^

``bii configure --toolchain`` command define the tool-chain to use, here's more about the :ref:`custom tool-chains <custom_toolchains>`.

**bii cpp:build**: build your project
-------------------------------------

This command invokes the C++ compiler to build your project.

.. code-block:: bash

	$ bii cpp:build	
	Building: cmake --build .
   ...

	[100%] Built target myuser_myblock_main


.. _build_cmake_options:

You can build your projects with the parameters, depending on your OS, that CMake offers us.

.. code-block:: bash

   $ cmake --build
   Usage: cmake --build <dir> [options] [-- [native-options]]
   Options:
     <dir>          = Project binary directory to be built.
     --target <tgt> = Build <tgt> instead of default targets.
     --config <cfg> = For multi-configuration tools, choose <cfg>.
     --clean-first  = Build target 'clean' first, then build.
                      (To clean only, use --target 'clean'.)
     --use-stderr   = Don't merge stdout/stderr output and pass the
                      original stdout/stderr handles to the native
                      tool so it can use the capabilities of the
                      calling terminal (e.g. colored output).
     --             = Pass remaining options to the native tool.

Now, using biicode, for example:

.. code-block:: bash

   $ bii cpp:build --use-stderr
   
   
If you got any questions left, you can ask them at our `forum <http://forum.biicode.com/>`_.