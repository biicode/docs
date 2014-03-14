.. _rpi_cross_compiling:

3. Raspberry Pi Cross-compiling: automatic set up
-------------------------------------------------

This section describes how to **configure a Linux system for cross-compiling Raspberry Pi C++ programs with biicode**. You will need a Linux distribution installed on your machine (you can also use a virtual machine). We recommend using `Ubuntu <http://www.ubuntu.com/>`_, but any Debian distribution should work just as fine. It is assumed :ref:`you have already installed a Raspbian image on your RPi board <raspbian_installation>`.

Biicode provides with its client program a command-line tool that will download and install all needed tools for your. These tools are:

#. **CMake and some development tools**

	To get them installed, simply execute the ``bii setup:cpp``.
#. The **Raspberry Pi tools** for cross-compiling

These three steps are described bellow. If you experience any issues, please `contact us using our forum <http://forum.biicode.com/category/raspberry-pi>`_, and feel free to ask any questions.

**Note:** If your are using a **64-bit version of Linux** as development environment, :ref:`see this note about how to install 32-bit support on your machine <rpi_32bi_support>`.


3.1. C++ tools installation
...........................

Install the required development tools as root:

.. code-block:: bash

	$ sudo apt-get install build-essential cmake

.. _rpi_cc_tools:

3.2. Raspberry Pi tools installation
.....................................

One essencial step for cross-compiling your programs is downloading and installing `the Raspberry Pi tools from this Github repository <https://github.com/raspberrypi/tools/>`_. You'll need Git installed on your Linux system. You can install an existing package on your Ubuntu platform with the following command:

.. code-block:: bash

	$ sudo apt-get install git

Now, let biicode do all the work for you with the **automatic installation**. If you have any problem, try to do the manual installation. 

.. container:: tabs-section

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Automatic installation

		The biicode client program is able to automatically download and configure the tools on your system. You just need to use the ``setup:rpi`` command from your workspace path:

		.. code-block:: bash

			$ sudo bii setup:rpi
			[sudo] password for <username>:
			INFO: Cloning the ARM cross compiler into /usr/local/tools
			
			Cloning into '/usr/local/toos'
			...
			done

		After a while (this time varies dependending on your connection speed, so be patient) all necessary files will be downloaded into your ``/usr/local/tools`` folder.
			
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Manual installation

		If you prefer to manually download and install the cross compiler, just clone the Raspberry Pi repository into the desired location, for example your home folder (you can also `download it in zip format <https://github.com/raspberrypi/tools/archive/master.zip>`_ and unzip the files):

		.. code-block:: bash

			$ cd ~
			$ sudo git clone https://github.com/raspberrypi/tools.git

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

		$ sudo apt-get install ia32-libs
		
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