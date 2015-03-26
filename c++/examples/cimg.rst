CImg
====

The CImg Library is an open-source C++ toolkit for image processing.
It consists of a single header file "CImg.h" providing a minimal set of C++
classes and methods that can be used in your own sources, to load/save,
process and display images. Very portable (Unix/X11,Windows, MacOS X, FreeBSD, .. ),
efficient, easy to use, it's a pleasant library for developping image processing
algorithms in C++.

The main CImg block is at `tschumperle/cimg <https://www.biicode.com/tschumperle/cimg>`_ and contains several examples. Its generated
from this `github repo <https://github.com/lasote/cimg>`_.

Tron game
---------

This is a classic Tron game that shows how to load and manipulate images with Cimg library in a simple way.

Let's try it out!

Create a new project
^^^^^^^^^^^^^^^^^^^^

Init a new project and a new *tron.cpp* file inside and copy the code below:

.. code-block:: bash

 $ bii init tron_example -L
 $ cd tron_example
 $ # Create tron.cpp and copy the code

**tron.cpp**

.. literalinclude:: /_static/code/cpp/examples/cimg/tron.cpp
   :language: cpp
   :linenos:
   :emphasize-lines: 44

Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 INFO: Processing changes...
 your_user/cimg_example depends on:
       unresolved:
          CImg.h

Now, edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

.. code-block:: text

 [requirements]
     tschumperle/cimg: 4
 
 [includes]
     CImg.h: tschumperle/cimg

Now, checking again **bii deps** shows all resolved dependencies.

.. container:: infonote
  
  If you're not using Windows OS, you might need the external X11 library dependency, check it!

  **Linux OS**:

  .. code-block:: bash

    $ sudo apt-get install libx11-dev

  **Mac OS**:

  Go to `XQuartz home page <http://xquartz.macosforge.org/landing/>`_, download the package and install it.

You might need to modify the CMakeLists.txt of your block in order to include the external X11 dependency in the linking process:

.. code-block:: cmake

    include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)

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

Build the project
^^^^^^^^^^^^^^^^^

Now, build and run your Tron game!

.. code-block:: bash

 $ bii build
 $ cd bin
 $ # Run the executable

Open and build
--------------

This example is already in biicode: `examples/cimg <http://www.biicode.com/examples/cimg>`_. Give it a try, just open a new project and open the block.

.. code-block:: bash

    $ bii init cimg_example
    $ cd cimg_example
    $ bii open examples/cimg
    $ bii build
    $ cd bin
    $ # Run the generated executable
    $ ./examples_cimg_tron # on linux
    $ examples_cimg_tron.exe # on windows

.. container:: infonote

    Note that this example block  already includes all required modifications above in both *biicode.conf* and *CMakeLists.txt*.


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.