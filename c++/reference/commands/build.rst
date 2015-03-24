.. _bii_build_command:

**bii build**: build your project
-------------------------------------

This command invokes the C++ compiler to build your project.

.. code-block:: bash

 $ bii build
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

   $ bii build --use-stderr
   
Building in a Linux or Mac OS X system or MinGW (with make). You can probably **speed up your builds using multiple jobs** (threads, cores):

Execute **bii build -jN** to run Makefile with this option and use the N cores of your machine: 

.. code-block:: bash

    $ bii build -j4 == cmake --build . -- -j4

This also works with Visual Studio compiler:

.. code-block:: bash

    $ bii build -j4 == cmake --build . -- /m:4

You can also use the **-jN make** option where N is the number of concurrent jobs desired (please note the - - before - jN): 

.. code-block:: bash

   $ bii build -- - j4
   
Building with Visual Studio compiler (even in the command line), the equivalent option is /m:N, so you can:

.. code-block:: bash

   $ bii build -- /m:4

