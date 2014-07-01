.. _freeglut:

Freeglut
========

This example demonstrates how to get started using **OpenGL** with biicode. **Freeglut** is an `open source alternative to the OpenGL Utility Toolkit (GLUT) library <http://freeglut.sourceforge.net/>`_. It allows you to create and manage windows containing OpenGL contexts on a wide range of platforms, and dealing with user input from mouse, keyboard and joystick devices. You can visit the following pages to learn more about OpenGL and GLUT (and hence freeglut):

   1. `The Official Guide to Learning OpenGL v1.1 <http://glprogramming.com/red/>`_
   2. `List of OpenGL methods <http://www.talisman.org/opengl-1.1/Reference.html>`_
   3. `The Free OpenGL Utility Toolkit <http://freeglut.sourceforge.net/>`_
   4. `List of GLUT methods <http://www.opengl.org/documentation/specs/glut/spec3/node1.html>`_

1. Create a new project
-------------------------

First, create a new project as described in the :ref:`hello world example <cpp_getting_started>`, using the following options:

.. code-block:: bash

   ~$ cd cpp_freeglut_project
   ~/cpp_freeglut_project$ bii new anonymous/cpp_freeglut --hello=cpp


2. Creating reusable code
--------------------------

This is some example conde that makes use of GLUT functions. Note that **you must include a reference to a biicode GLUT wrapper** library. This is the only information biicode needs to fetch the required files when needed, taking into account your actual development platform. We'll see how this happens in the next step.

Now, simply put the following code into your ``cpp_freeglut`` block folder (you can also download these files here: :download:`sphere-glut.zip </_static/code/cpp/examples/freeglut/sphere-glut.zip>`, unzip and copy them into your block folder):

**sphere.h**

.. literalinclude:: /_static/code/cpp/examples/freeglut/sphere.h
   :language: cpp
   :emphasize-lines: 2


**sphere.cpp**

.. literalinclude:: /_static/code/cpp/examples/freeglut/sphere.cpp
   :language: cpp


**main.cpp**

.. literalinclude:: /_static/code/cpp/examples/freeglut/main.cpp
   :language: cpp


3. Find dependencies
--------------------

Now is when the biicode magic takes place. The previous code needs to link with some library implementing the drawing functions being used. You can resolve all missing dependencies for your platform using the ``bii find`` command. **From your project's folder location** execute:

.. code-block:: bash

   $ bii find

**This will find and retrieve all missing files** from the biicode servers to your local filesystem, under the ``deps`` folder of your project. You should see a success message confirming that all dependencies have been resolved.


4. Build and run
----------------

Now it is time to see the result of the previous steps. You can build your main file with the ``bii cpp:run`` command and and run the executable inside the bin folder.

.. code-block:: bash

   $ bii cpp:build
   $ cd bin
   $ #run your executable

**That's it!** You should see a new window named "My World", containing a single white sphere in its center. Just like this!:

.. image:: /_static/img/sphere_freeglut.png

If you experience any difficulties during the coding process, or get any errors during the program execution, visit `our forum <http://forum.biicode.com/>`_ and feel free to ask any questions.

