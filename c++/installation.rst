.. _cpp_installation:

Installation
============

This section describes how to install, set up and verify some **tools needed for building C and C++ projects with biicode**. These tools are:

* a compiler, and
* `CMake <http://www.cmake.org/>`_ , used by biicode for managing the compilation process. 

Also, **it is suggested installing some IDE** for better management of your hives. Supported C++ IDEs are Eclipse, and Visual Studio C++ in Windows. However, it is up to you whether to install an IDE or not. If you do so, you will find additional instructions in the :ref:`IDE configuration section <ide_configuration>` of this documentation.

The steps for the installation of these tools vary from one operaing system to another. Here you will find detailed instructions for your actual development platform.

1. Biicode initial setup
------------------------

First of all, **you need to complete the biicode general installation**. Follow :ref:`the instructions in the general documentation, following this link <first_steps>`. You must: 

* **Sign up** with biicode
* Download and install the **client binaries** for your operating system
* Create a biicode **workspace**

After you have complete these steps, proceed with the following sections:

2. Install the development tools
--------------------------------

Follow the instructions bellow to install these tools for your particular development platform:

.. container:: tabs-section
	
	.. _cpp_desktop_linux:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Linux

		Install the required development tools as root:

		.. code-block:: bash

			$ sudo apt-get install build-essential cmake

		That's all!

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

		- `CMake <http://www.cmake.org/>`_. Open Source tool that manages the software building process in a compiler-independent manner.

		- Compilers and build system. This could be one of the following (among other alternatives):

		   - `MinGW <http://www.mingw.org/>`_ (make sure to include gcc, g++, and mingw32-make with your installation)
		   - Visual Studio C++

		.. container:: infonote

			The command ``bii setup:cpp`` is able to automatically download and install CMake and MinGW, and configure the environment for you.

			.. code-block:: bash

			   $ bii setup:cpp

			Execute the command and follow the instructions. You might need to close your console and re-run the command after the installation, to check everything went fine.

		These are the **steps for manual installation** of our recommended tools:

		1. Download and install CMake. You can `download the latest version of CMake here <http://www.cmake.org/cmake/resources/software.html>`_.

		2. Download and install "base, g++" packages of MinGW. Follow `this link <http://sourceforge.net/projects/mingw/files/Installer/>`_ to get the installer, and choose while installing two additional packages, GCC and G++ package.

		3. Add to your user ``PATH`` environment variable the paths to these tools. We recommend `Rapid Environment Editor <http://www.rapidee.com/>`_ for editing environment variables. Otherwise, go to **My Computer**, click **Properties**, click **Advanced System Settings** and in the System Properties window click the **Environment Variables** button. then you will see a new window and in **User Variables** you'll find the variable ``PATH``:

		   .. image:: /_static/img/cpp_windows_path.png

		Add your tools binaries folders (i.e. ``C:\MinGW\bin`` gor MiGW, and ``C:\Program Files (x86)\CMake 2.8\bin`` for CMake).

		You might need to close and open again any ``cmd`` windows in order to load the new value for the ``PATH`` variable.


3. Verify your installation
---------------------------

Once you have installed the tools, you should check they are working properly. Open a terminal window and run the following commands. If the output messages look similar to these, the tools are successfully installed.

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


