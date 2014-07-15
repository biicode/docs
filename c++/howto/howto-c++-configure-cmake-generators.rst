.. _configure_cmake_generators:

Configure your IDE
===================

Biicode offers integration with some of **the most commonly used IDEs** for C++ programmers (**Microsoft Visual Studio**, **Eclipse** and **CodeBlocks**). By default, biicode configures your projects with MinGW Makefiles (Windows) or UNIX Makefiles (MacOS and Linux), to change it execute ``bii cpp:configure`` and the cmake command to change generators, for example:

.. code-block:: bash

	$ bii cpp:configure -G "Visual Studio 10"


.. code-block:: bash

	$ bii cpp:configure -G "Eclipse CDT4 - Unix Makefiles"


If you changes the default generator, it'll be saved in your ``settings.bii`` file each time, and it'll convert in your new default generator.

.. code-block:: bash

	$ bii cpp:configure -G "Visual Studio 9 2008"
	...
	$ bii cpp:configure
	#Calling to Visual Studio 9 2008 generator
