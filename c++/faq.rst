.. _c++_troubleshooting:

Troubleshooting
===============

In this section you will find information and helpful resources, in case you encounter any problem while using our service. Don't panic, and try to find a solution for your problem bellow. If you can't find a solution, please `contact us at our forum <http://forum.biicode.com>`__ and describe your problem.


.. _eclipse_osx_binaries:

Eclipse projects: "Launch failed. Binary not found" (OS X)
----------------------------------------------------------

If you are using **OS X** as development platform, you will need some aditional setup for executing your biicode projects within Eclipse IDE. It could happen that after building your project, you cannot execute the binaries from the IDE toolbar, getting the following error:

.. image:: /_static/img/c++/binary_not_found.png

If you are getting this error, please proceed as follows:

#. Right-click on your project and select *Properties*.
#. Select *C/C++ Make project* and click on the *Binary Parser* subsection tab.
#. Unselect Mach-O Parser (deprecated).
#. Select Mach-O 64 Parser.
#. Click *OK*.

You can :ref:`read more in this section about configuring an IDE with your C/C++ projects <ide_configuration>`.

.. _cpp_installation:

Install C/C++ tools manually 
----------------------------

This section describes how to install, set up and verify some **tools needed for building C and C++ projects with biicode**. These tools are:

* MinGW or GCC.
* CMake. 

The steps for the installation of these tools vary from one operating system to another. Here you will find detailed instructions for your actual development platform.

1. C++ tools installation
^^^^^^^^^^^^^^^^^^^^^^^^^
First of all, **you need install biicode**.

Now, try the automatic installation. Only if something goes wrong, proceed with the manual installation described at the end of this section.

1.1 Automatic installation
..........................

**Just execute** ``bii setup:cpp``.

		.. code-block:: bash

		   $ bii setup:cpp

Type the previous command and follow the instructions. You might need to close your console and open a new one to reload the updated environment variables. In the new console window, re-run the ``bii setup:cpp`` command to verify everything is properly installed.

**If something fails with the automatic installation**, please `contact us at our forum <http://forum.biicode.com/category/arduino>`__, and feel free to ask any questions. Then, **proceed with the alternative manual installation** described bellow.

1.2. Manual installation
........................

This section describes the manual installation of the C/C++ tools. You only need to go through this section if something failed during the automatic installation explained before. If you experience any issues during this manual installation, please `contact us at our forum <http://forum.biicode.com/category/raspberry-pi>`_, and we'll try to solve your problem as soon as possible.

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


		These are the **steps for manual installation** of our recommended tools:

		1. Download and install CMake. You can `download the latest version of CMake here <http://www.cmake.org/cmake/resources/software.html>`_.

		2. Download and install "base, g++" packages of MinGW. Follow `this link <http://sourceforge.net/projects/mingw/files/Installer/>`_ to get the installer, and choose while installing two additional packages, GCC and G++ package.

		3. Add to your user ``PATH`` environment variable the paths to these tools. We recommend `Rapid Environment Editor <http://www.rapidee.com/>`_ for editing environment variables. Otherwise, go to **My Computer**, click **Properties**, click **Advanced System Settings** and in the System Properties window click the **Environment Variables** button. then you will see a new window and in **User Variables** you'll find the variable ``PATH``:

		   .. image:: /_static/img/cpp_windows_path.png

		Add your tools binaries folders (i.e. ``C:\MinGW\bin`` gor MiGW, and ``C:\Program Files (x86)\CMake 2.8\bin`` for CMake).

		You might need to close and open again any ``cmd`` windows in order to load the new value for the ``PATH`` variable.


2. Verify your installation
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Once you have installed the tools, **you should check they are working properly**. Open a terminal window and run the following commands. If the output messages look similar to these, the tools are successfully installed.

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


g++ doesn't compile simple code, using thread header
------------------------------------------------------

If you have a block that **links to pthread library** and you're using **Ubuntu 13.10 or 14.04**, you'll find this bug in g++ compiler:

.. code-block:: bash

	$ ./executable_file
	terminate called after throwing an instance of 'std::system_error'

**Create a CMakelists.txt inside your block that fails** and copy the following content:

**CMakeLists.txt**

.. code-block:: cmake

	#############BIICODE MACROS###################
	include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
	INIT_BIICODE_BLOCK()

	ADD_BIICODE_TARGETS()
	#############################################

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed")


.. container:: infonote

	Visit the section: :ref:`biicode project layout <project_layout>`