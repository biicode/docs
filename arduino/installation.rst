.. _arduino_installation:

Installation
============

This section describes how to **work on Arduino projects with biicode**. The installation steps depend on you current development platform. Simply select your operating system from the options you will find in the sections bellow.

1. Biicode initial setup
------------------------

First of all, **you need to complete the biicode general installation**. Follow :ref:`the instructions in the general documentation, following this link <first_steps>`. You must: 

* **Sign up** with biicode
* Download and install the **client binaries** for your operating system
* Create a biicode **workspace**

After you have complete these steps, proceed with the following section:

2. Install the development tools
--------------------------------

**Just write** ``bii setup:arduino`` in your console and all needed tools will be installed automatically.

		.. code-block:: bash

		   $ bii setup:arduino

Type the previous command and follow the instructions. You might need to close your console and open a new one to reload the updated environment variables. In the new console window, re-run the ``bii setup:arduino`` command to verify everything is properly installed.

If something went wrong please notify us at our `forum <http://forum.biicode.com/category/arduino>`_, and  we'll try to solve your problem as soon as possible.

**Something went wrong & you are in a hurry? Try the manual installation:**

Install the development tools
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In order to configure and compile your Arduino projects with biicode, you need to install some additional tools. CMake is an open source tool that manages the software building process in a compiler-independent manner. Select your operating system bellow, and follow the instructions.

.. container:: tabs-section
	
	.. _arduino_cmake_linux:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Linux

		Install the required development tools as root:

		.. code-block:: bash

			$ sudo apt-get install build-essential cmake

		That's all!

	.. _arduino_cmake_mac:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			MacOS

		You need to get installed both XCode Developer Tools and CMake:

		#. The XCode Developer Tools

		   .. code-block:: bash

		   	$ xcode-select --install


		#. Download and install the appropriate `version of CMake <http://www.cmake.org/cmake/resources/software.html>`_ for your Mac OSX.

	.. _arduino_cmake_win:
	.. container:: tabs-item

		.. rst-class:: tabs-title

			Windows

		1. Download and install CMake. You can `download the latest version of CMake here <http://www.cmake.org/cmake/resources/software.html>`_.

		3. Add to your user ``PATH`` environment variable the path to CMake. We recommend `Rapid Environment Editor <http://www.rapidee.com/>`_ for editing environment variables. Otherwise, go to **My Computer**, click **Properties**, click **Advanced System Settings** and in the System Properties window click the **Environment Variables** button. then you will see a new window and in **User Variables** you'll find the variable ``PATH``:

		   .. image:: /_static/img/cpp_windows_path.png

		Add CMake binaries folders (i.e. ``C:\Program Files (x86)\CMake 2.8\bin``).

		You might need to close and open again any ``cmd`` windows in order to load the new value for the ``PATH`` variable.


Now, you can check CMake is working properly. Open a terminal window and run the following command. If the output message looks similar to this, CMake is successfully installed.

.. code-block:: bash

	$ cmake --version
	cmake version [version]


Install Arduino software
^^^^^^^^^^^^^^^^^^^^^^^^

You need to `download the Arduino software <http://arduino.cc/en/Main/Software>`_ first, it is important to choose a SDK compatible with your board. If you need more info visit the `official Arduino website <http://arduino.cc/en/Main/Software>`_.

You must install the SDK in the following path.

.. container:: tabs-section
	
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Linux

		.. code-block:: text

			/usr/share/arduino

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			MacOS

		.. code-block:: text
		
			/Applications/Arduino.app

	.. container:: tabs-item

		.. rst-class:: tabs-title

			Windows

		.. code-block:: text
			
			C:/Program Files(x86) /Arduino
