.. _cpp_installation:

Installation
============

1. Install the development tools
--------------------------------

In order to use biicode with your C and C++ projects, you need to install on your system some additional tools. Follow the instructions bellow to install these tools for your particular development platform:

.. container:: tabs-section
	
	.. _cpp_desktop_linux:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Linux

		Install the required development tools as root:

		.. code-block:: bash

			$ sudo apt-get install build-essential cmake

	.. _cpp_desktop_mac:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			MacOS

		You need to get installed both XCode Developer Tools and CMake:

		#. The XCode Developer Tools

		   .. code-block:: bash

		   	$ xcode-select --install


		#. Download and install the appropriate `version of CMake <http://www.cmake.org/cmake/resources/software.html>`_ for your Mac OSX.

	.. _cpp_desktop_win:
	.. container:: tabs-item

		.. rst-class:: tabs-title

			Windows

		To develop C/C++ programs in Windows you need:

		#. `CMake <http://www.cmake.org/>`_. Open Source tool that manages the software building process in a compiler-independent manner.

		#. Compilers and build system. This could be one of (among other existing ones):

		   - `MinGW <http://www.mingw.org/>`_ (make sure to include gcc, g++, and mingw32-make with your installation)
		   - Visual Studio C++
		   
		#. IDE (optional, but recommended). Common IDEs are:

		   - `Notepad++ <http://notepad-plus-plus.org/>`_. It is a very simple and lightweight code editor.
		   - `Eclipse CDT <https://www.eclipse.org/cdt/>`_ (C/C++ Development Tools). Works typicall together with MinGW as compiler.
		   - Visual Studio C++.

		Assisted installation
		---------------------

		The command ``bii setup:cpp`` will try to automatically download and install the tools, and configure the environment for you. In this case CMake, MinGW and Notepad++ will be installed.

		Execute the command and follow the instructions. You might need to re-run the command after closing the console, to check everything went OK.

		.. code-block:: bash

		   $ bii setup:cpp

		Manual installation
		-------------------

		1. Download and install CMake. You can `download the latest version of CMake from <http://www.cmake.org/cmake/resources/software.html>`_.

		2. Download and install "base, g++" packages of MinGW. Follow `this link <http://sourceforge.net/projects/mingw/files/Installer/>`_ to get the installer, and choose while installing two additional packages, GCC and G++ package.

		3. Add to your user ``PATH`` environment variable the paths to these tools. We recommend `Rapid Environment Editor <http://www.rapidee.com/>`_ for editing environment variables. Otherwise, go to **My Computer**, click **Properties**, click **Advanced System Settings** and in the System Properties window click the **Environment Variables** button. then you will see a new window and in **User Variables** you'll find the variable ``PATH``:

		   .. image:: /_static/img/cpp_windows_path.png

		   Add your tools binaries folders (i.e. ``C:\MinGW\bin``, ``C:\Program Files (x86)\CMake 2.8\bin``).


		You might need to close and open again any ``cmd`` windows in order to load the new value of ``PATH``.


2. Verify your installation
---------------------------

Open a terminal and run the following commands. If the output messages look like these, the tools are successfully installed.

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
