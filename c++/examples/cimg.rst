CImg
====

The CImg Library is an open-source C++ toolkit for image processing.
It consists in a single header file 'CImg.h' providing a minimal set of C++
classes and methods that can be used in your own sources, to load/save,
process and display images. Very portable (Unix/X11,Windows, MacOS X, FreeBSD, .. ),
efficient, easy to use, it's a pleasant library for developping image processing
algorithms in C++.

The main CImg block is `here <https://www.biicode.com/tschumperle/cimg>`_ and contains several examples. Its generated
from this `github repo <https://github.com/lasote/cimg>`_.


General usage
----------------------------------

Just **#include "tschumperle/cimg/CImg.h"** in your cpp file, execute **bii find** to download the requirements and **bii cpp:build** for build your project.

.. container:: infonote
  
  If you're not using Windows OS, you might need the external X11 library dependency, check it!

  **Linux OS**:

  .. code-block:: bash

    $ sudo apt-get install libx11-dev

  **Mac OS**:

  Go to `XQuartz home page <http://xquartz.macosforge.org/landing/>`_, download the package and install it.

If you are directly depending to CImg (using the **#include "tschumperle/cimg/CImg.h"**) you might need to modify the CMakeLists.txt of your block in order to include the external X11 dependency in the linking process:

.. code-block:: cmake

    include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)

    INIT_BIICODE_BLOCK()

    ADD_BIICODE_TARGETS()

    IF(APPLE)
       FIND_PACKAGE(X11)
       TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGETS} PUBLIC ${X11_LIBRARIES})
       INCLUDE_DIRECTORIES(/opt/X11/include)
    ENDIF()

    IF(UNIX)
        IF(NOT APPLE)
            TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGETS} PUBLIC X11)
        ENDIF()
    ENDIF()


Usage example: Tron game
----------------------------------

This example is extracted from `examples/cimg/tron.cpp<http://www.biicode.com/examples/cimg>`_
It's a classic Tron game and shows how to load and manipulate images with Cimg library in a simple way.

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

.. container:: infonote

    Note that by opening the block, the CMakeLists.txt already includes the required modification. If you manually create the block the CMakeLists.txt has to be modified or a linking error will appear.

**tron.cpp**

.. literalinclude:: /_static/code/cpp/examples/cimg/tron.cpp
   :language: cpp
   :linenos:
   :emphasize-lines: 44
