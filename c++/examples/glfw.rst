GLFW
====

`GLFW <http://www.glfw.org/>`__ is a free, Open Source, multi-platform library for OpenGL and OpenGL ES application development.
It provides a simple, platform-independent API for creating windows and contexts, reading input, handling events, etc.

It is a great library, if you want to build OpenGL applications it is highly recommended.

You can find it ready for simple use `in biicode <http://www.biicode.com/diego/glfw>`__


Running the examples
--------------------

It is very simple. Create a **new project**, open the examples, build and run them:

.. code-block:: bash

   $ bii init glfwexamples
   $ cd glfwexamples
   $ bii open examples/glfw
   $ bii cpp:build
   $ ./bin/examples_glfw_particles
   
   
.. container:: infonote

    **Ubuntu users may need to install some additional software**

   If you are using Ubuntu Linux, you may need to install some additional packages. To do so, execute:

   .. code-block:: bash

      sudo apt-get install mesa-common-dev libglu1-mesa-dev libxi-dev 
        
You should see in your screen:
   
.. image:: /_static/img/c++/examples/glfw_particles.png

There are also other examples that have been built! Enjoy them and GLFW!


Of course, you can also do your own GLFW programs from your own block:

.. code-block:: bash

   $ bii init myproject
   $ cd myproject
   $ bii new yourusername/yourblock
 
Then copy your source files to yourusername/yourblock folder, change your includes to: 

.. code-block:: cpp

   #include <diego/glfw/deps/glad/glad.h>
   #include <diego/glfw/include/GLFW/glfw3.h>

And then, find and retrieve dependencies, build and run your program:

.. code-block:: bash

   $ bii find
   $ bii cpp:build
 


