.. _cpp-index:

C/C++ Documentation
===================

**Biicode simplifies how you reuse C/C++ source code in your programs**.
With our technology, you only need to write #includes in your source files.
Biicode will automatically analyze your code, retrieve all missing dependencies and
store all the necessary source code files in your project.

In this context, biicode technology gives you several advantages to enrich your C++ experience:

   #. Reusing made easy: just ``#include`` the header file. No more copy and paste files from project to project or downloading and compiling external libraries.
   #. Great for rapid prototyping and trying out new libraries/versions.
   #. Smart management and finding of dependencies. We look for jointly compatible versions and allow `full control of your dependencies <http://docs.biicode.com/biicode/reference/configuration_files/policies.html?highlight=policies>`_.
   #. Many `examples <http://docs.biicode.com/c++/c++-examples.html>`_ to start now.
   #. Biicode uses **cmake**, if you know cmake you can `customize your builds <http://docs.biicode.com/c++/reference/cpp-build-files.html>`_, if you don't, biicode will automatically handle the builds for you.

.. toctree::
	:maxdepth: 2

	c++/c++-commands
	c++/c++-cmake
	c++/c++-examples
	c++/c++-howto
	c++/c++-troubleshooting
