.. _cpp-index:

C/C++ Documentation
===================

**Biicode simplifies how you reuse C/C++ source code in your programs**. 
With our technology, you only need to write #includes in your source files.
Biicode will automatically analize your code, and retrieve from biicode all missing dependencies,
storing all the necessary source code files in your project.

In this context, biicode technology gives you several advantages for enriching your C++ experience:

   #. Reusing made easy: just ``#include`` the file you need and you get it. No more copy and paste files from project to project or dowloading and compiling external libraries.
   #. Great for rapid prototyping and trying out new libraries/versions.
   #. Smart management and finding of dependencies. We look for jointly compatible versions and allow `full control of your dependencies <http://docs.biicode.com/biicode/reference/configuration_files/policies.html?highlight=policies>`_.
   #. Many of `examples <http://docs.biicode.com/c++/c++-examples.html>`_ to get started with.
   #. Biicode uses `cmake <http://web.biicode.com/blog/meta-configuration-of-cc-projects-with-cmake-1>`_, if you know cmake you can `customize your builds <http://docs.biicode.com/c++/reference/cpp-build-files.html>`_, if you don't, biicode will automatically handle builds for you.


.. toctree::
	:maxdepth: 2

	c++/c++-getting-started
	c++/c++-howto
	c++/c++-features
	c++/c++-examples
	c++/c++-faqs
	c++/c++-troubleshooting