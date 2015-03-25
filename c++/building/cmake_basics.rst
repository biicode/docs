.. _cmake_introduction:

CMake basics
---------------------------

If you don't know **CMake**, here are the tips you need to know before understand how biicode use it.

So CMake:

* Basically requires one thing, a ``CMakeLists.txt`` file.
* Allows to define ``targets`` which are each ``executable`` or ``library`` you want to build for your project.
* Is ``multi platform`` and will automatically generate needed files for your O.S/compiler for build your project.
* ``CMakeLists.txt`` basic example:

  .. code-block:: cmake

    # Specify the version being used (biicode makes it automatically)
    cmake_minimum_required(VERSION 2.6)
    # Name your project here (biicode makes it automatically)
    project(fibonacci)

    # This tells CMake to build an executable with fib.c and name it fibonacci
    add_executable(fibonacci fib.c) # Biicode automatically add detected targets in your source code

    # Sends the -std=c99 flag to the gcc compiler
    add_definitions(-std=c99)
