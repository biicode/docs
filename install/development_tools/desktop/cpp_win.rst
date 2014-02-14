.. _cpp_desktop_win:

C++ Windows
===========

To develop C/C++ in windows you need:

   #. `CMake <http://www.cmake.org/>`_. Open Source tool that manages the software building process in a compiler-independent manner

   #. Compilers and build system. This could be one of (among other existing ones)

      - `MinGW <http://www.mingw.org/>`_ (gcc, g++, mingw32-make)
      - Visual Studio C++

   #. IDE (optional, but very recommended to have one). Common IDEs

      - `Notepad++ <http://notepad-plus-plus.org/>`_. It is a very simple and lightweight code editor.
      - Eclipse CDT (C/C++ Development Tools). Works typicall together with MinGW as compiler
      - Visual Studio C++



Assisted installation
---------------------

The command ``bii setup:cpp´´ will try to automatically download, launch installer and configure the environment for you, for CMake, MinGW and Notepad++.
Execute the command and follow instructions. You might need to re-run the command after closing the console, to check everything went OK.

.. code-block:: bash

   $ bii setup:cpp

Manual installation
-------------------

   1. Download and install CMake
      You can `download the latest version of CMake from <http://www.cmake.org/cmake/resources/software.html>`_.

   2. Download and install "base, g++" packages of MinGW
      Follow `this link <http://sourceforge.net/projects/mingw/files/Installer/>`_ to get the installer, and choose while installing two additional packages, GCC and G++ package.

   3. Add to your user PATH environment variables the paths to these tools.
      We recommend `Rapid Environment Editor <http://www.rapidee.com/>`_ for editing environment variables.
      With your default windows tools, go to **My Computer**, click **Properties**, click **Advanced System Settings** and in the System Properties window click the **Environment Variables** button, then you will see a new window and in **User Variables** you'll find the variable ``PATH``), for example:

      Add your tools binaries folder, that could be of the form (the best is navigate to the folder, then copy and paste
      the path.
      * C:\MinGW\bin
      * C:\Program Files (x86)\CMake 2.8\bin

      .. image:: cpp_image/image_path.png

      You might need to close and open again your cmd windows in order to load the new value of PATH.

Check installation
------------------

Open a terminal and run the following commands. If your output looks like these, the tools are successfully installed.

.. code-block:: bash

	$ cmake --version
	cmake version [version]

.. code-block:: bash
	
	$ gcc --version
	gcc (GCC) [version]
	...

.. code-block:: bash
	
	$ g++ --version
	g++ (GCC) [version]
	...
	
.. code-block:: bash
	
	$ mingw32-make --version
	GNU Make [version]
	...