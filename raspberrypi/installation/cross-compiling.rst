.. _rpi_cross_compiling:

3. RPi cross-compiling set up
-----------------------------

This section describes how to **configure a Linux system for cross-compiling Raspberry Pi C++ programs with biicode**. You will need a Linux distribution installed on your development machine. You can also use a virtual machine. We recommend using `Ubuntu <http://www.ubuntu.com/>`_, but any Debian distribution should work just as fine. It is assumed that **(1)** you have already installed a Raspbian image on your RPi board, and **(2)** the biicode client program is installed on your Linux machine, as described in the previous steps.

Biicode provides with its client program a command-line utility that will download and install all needed tools for you. These tools are:

#. **CMake and some development tools**
#. The **Raspberry Pi tools** for cross-compiling

First, try the automatic installation provided by biicode. Only if something goes wrong, proceed with the manual installation described at the end of this section.

3.1 Automatic installation
..........................

To **automatically set up your system for cross-compiling Raspberry Pi projects**, **simply execute** the following commands:

#. ``bii setup:cpp``. This will install generic compilation tools for your Linux platform. Run the command and follow the instructions
#. ``bii setup:rpi``. This will install the cross-compiling tools. Again, run the command and follow the on-screen instructions.

**If something fails with the automatic installation**, please `contact us at our forum <http://forum.biicode.com/category/raspberry-pi>`_, and feel free to ask any questions. Then, **proceed with the alternative manual installation** described bellow.

3.2 Manual installation
.......................

This section describes the manual installation of the cross-compiling tools. You only need to go through this section if something failed during the automatic installation explained before. If you experience any issues during this manual installation, please `contact us at our forum <http://forum.biicode.com/category/raspberry-pi>`_, and we'll try to solve your problem as soon as possible.

**Note:** If your are using a **64-bit version of Linux** as development environment, :ref:`see this note about how to install 32-bit support on your machine <rpi_32bi_support>`.

3.2.a. C++ tools installation
+++++++++++++++++++++++++++++

Install the required development tools as root:

.. code-block:: bash

	$ sudo apt-get install build-essential cmake

.. _rpi_cc_tools:

3.2.b. Raspberry Pi tools installation
++++++++++++++++++++++++++++++++++++++

One essencial step for cross-compiling your programs is downloading `the Raspberry Pi tools from this Github repository <https://github.com/raspberrypi/tools/>`_. You'll need Git installed on your Linux system. You can install an existing package on your Ubuntu platform with the following command:

.. code-block:: bash

	$ sudo apt-get install git


Now, you need to clone this Git repo in this folder: ``~/.biicode_env/raspberry_cross_compilers``. To do so, execute the following command:

.. code-block:: bash

	$ git clone https://github.com/raspberrypi/tools.git ~/.biicode_env/raspberry_cross_compilers

After a while, the RPi cross-compiling tools will be available in your system. To verify that biicode is able to find and use the compilers, run the following command, and check that you receive a success output message:

.. code-block:: bash

	$ bii setup:rpi
	INFO: The arm gnu is already downloaded

4. What to do next?
-------------------

You have successfully set up your system for developing C++ RPi programs with biicode. These are some resources that will help you:

.. container:: todo
	
	* Read the :ref:`Raspberry Pi getting started guide <rpi_getting_started>`. You'll learn how to create, build and execute your first biicode hive project.
	* Visit the :ref:`Raspberry Pi examples section <raspberry_pi_examples>`.
	* Read the reference for :ref:`general biicode commands <biicode_reference>` and for :ref:`RPi specific biicode commands <bii_rpi_tools>`
	* `Visit our forum and make any questions <http://forum.biicode.com/category/raspberry-pi>`_


.. _rpi_32bi_support:

.. container:: infonote

	**Install ia32-libs (only for 64-bit linux versions)**

	To find if your Linux is 32 or 64 bits, just type:
	 
	.. code-block:: bash

		$ uname -m

	This command may throw one of the following outputs:

	* ``x86_64`` ==> 64-bit kernel
	* ``i686``   ==> 32-bit kernel

	If you are using a 64-bit OS, you need to install the support for 32 bit applications. These libraries are required to use the cross compilers supplied by Raspberry Pi from their Github repository.

	.. code-block:: bash

		$ sudo apt-get install lib32ncurses5 
		
	It is possible that you encounter some of the following errors:

	* If it does not find the package, you may need to add a 32-bits architecture to your package list:

		.. code-block:: bash

			$ sudo dpkg --add-architecture i386
			$ sudo apt-get update
			$ sudo apt-get install ia32-libs

	* If you get:

		.. code-block:: bash

			The following packages have unmet dependencies:
		 	 ia32-libs : Depends: ia32-libs-multiarch
			E: Unable to correct problems, you have held broken packages.

		execute:

		.. code-block:: bash

			$ sudo apt-get install libgl1-mesa-dri:i386
			$ sudo apt-get install ia32-libs-multiarch:i386
			$ sudo apt-get install ia32-libs-multiarch
			$ sudo apt-get install ia32-libs

	* If you get:

		.. code-block:: bash

			Some packages could not be installed. 
			This may mean that you have requested an impossible situation the following packages have unmet dependencies:
			ia32-libs : Depends: ia32-libs-multiarch

		just install the dependencies manually like any other package:

		.. code-block:: bash

			$ sudo apt-get install ia32-libs-multiarch
			$ sudo apt-get install ia32-libs