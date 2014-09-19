Cimg
====

The CImg Library is an open-source C++ toolkit for image processing.
It consists in a single header file 'CImg.h' providing a minimal set of C++
classes and methods that can be used in your own sources, to load/save,
process and display images. Very portable (Unix/X11,Windows, MacOS X, FreeBSD, .. ),
efficient, easy to use, it's a pleasant library for developping image processing
algorithms in C++.

The main block is `here <https://www.biicode.com/tschumperle/cimg>`_ and contains several examples. Its generated
from this `github repo <https://github.com/lasote/cimg>`_


General usage
----------------------------------

Just **#include 'tschumperle/cimg/CImg.h'** in your cpp file, execute **bii find** for download the requirements and **bii cpp:build** for build your project.

Usage example: Tron game
----------------------------------

The following example is extracted from the /examples/tron.cpp
This examples implements classic Tron game and shows how to load and manipulate images with Cimg library in a simple way.


Simply open the examples/cimg block:

.. code-block:: bash

    $ bii init myproject
    $ cd myproject
    $ bii open examples/cimg
    $ bii cpp:build
    $ cd bin
    $ # Run the generated executable
    $ ./examples_cimg_tron # on linux
    $ examples_cimg_tron.exe # on windows


**tron.cpp**

.. literalinclude:: /_static/code/cpp/examples/cimg/tron.cpp
   :language: cpp
   :linenos:
   :emphasize-lines: 44
