.. _cmake_introduction:

CMake basics
------------

If you're a **CMake** newbie, these are the tips you need to know before understanding how biicode uses CMake.

So CMake:

* Basically requires one thing, a *CMakeLists.txt* file.
* Allows defining ``targets`` which are each **executable** or **library** you want to build for your project.
* Is **multi-platform** and automatically generates the files your O.S./compiler needs to build your project.
* *CMakeLists.txt* basic example (without biicode):

.. code-block:: cmake

	# Specify the CMake version used (biicode makes this automatically)
	cmake_minimum_required(VERSION 2.6)
	# Name your project here (biicode names it automatically)
	project(fibonacci)

	# This tells CMake to build a library with other.c and file.c and name it mylib
	# (biicode automatically creates a library for each block)
	add_library(mylib other.c file.c) 

	# Sends the -std=c99 flag to the gcc compiler
	add_definitions(-std=c99)

	# This tells CMake to build an executable with fib.c and name it fibonacci
	# (biicode automatically adds detected targets in your source code)
	add_executable(fibonacci fib.c) 

	# Links mylib to the fibonacci executable
	# (biicode automatically links block's library to each executable)
	target_link_libraries(fibonacci PUBLIC mylib)


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>