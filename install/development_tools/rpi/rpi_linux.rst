.. _rpi_corss_compiling:

Linux (cross compiling)
=======================

This section describes how to **configure a Linux system for cross-compiling your Raspberry Pi programs with biicode**. You will need a Linux distribution installed on your machine (or you can use a virtual machine). We recommend using `Ubuntu <http://www.ubuntu.com/>`_, but any Debian distribution should work just as fine.

Basically, you must :ref:`(1) download the Raspberry Pi tools <rpi_cc_tools>` from this `Github repository <https://github.com/raspberrypi/tools>`_, and :ref:`(2) configure your workspace default settings <rpi_default_settings>`.

If you experiment any issues, please `contact us using our forum <http://forum.biicode.com/category/cross-platform-support/raspberry-pi>`_, and feel free to ask any questions.

**Note:** If your are using a **64-bit version of Linux** as development environment, :ref:`see this note about how to install 32-bit support on your machine <rpi_32bi_support>`.

.. _rpi_cc_tools:

1. Download the Raspberry Pi tools
----------------------------------

One essencial step for cross-compiling your programs is downloading and installing `the Raspberry Pi tools from this Github repository <https://github.com/raspberrypi/tools/>`_. You'll need Git installed on your Linux system. You can install an existing package on your Ubuntu platform using ``apt-get``:

.. code-block:: bash

	$ sudo apt-get install git


Automatic installation
^^^^^^^^^^^^^^^^^^^^^^

The biicode client program is able to automatically download and configure the tools on your system. You just need to use the ``setup:rpi`` command from your workspace path:

.. code-block:: bash

	$ sudo bii setup:rpi
	[sudo] password for <username>:
	INFO: Cloning the ARM cross compiler into /usr/local/tools
	
	Cloning into '/usr/local/toos'
	...
	done

After a while (this time varies dependending on your connection speed, so be patient) all necessary files will be downloaded into your ``/usr/local/tools`` folder. Also, your workspace ``bii/environment.bii`` file will be updated with this information:

.. code-block:: text

	cpp:
	  compilers:
        - path: /usr/local/tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc
          tool: {arch: ARM, family: GNU, subfamily: C}
        - path: /usr/local/tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-g++
          tool: {arch: ARM, family: GNU, subfamily: CPP}
	
If you want to download the cross compilers into a different location, or if you already have downloaded them, simply indicate this information to the configuration program. For example, to download and configure the tools into your home folder, type:

.. code-block:: bash

	$ bii setup:rpi ~/tools

Manual installation
^^^^^^^^^^^^^^^^^^^

If you prefer to manually download and install the cross compiler, just clone the Raspberry Pi repository into the desired location, for example your home folder (you can also `download it in zip format <https://github.com/raspberrypi/tools/archive/master.zip>`_ and unzip the files):

.. code-block:: bash

	$ cd ~
	$ sudo git clone https://github.com/raspberrypi/tools.git

Now you  only need to configure you workspace ``bii/environment.bii`` file as explained before, making use of the ``bii setup:rpi`` utility providing the location of the corss-compiling tools.

.. code-block:: bash

	$ bii setup:rpi <tools_path>

.. _rpi_default_settings:

2. Board configuration
----------------------

Now, you need to update your workspace ``bii/environment.bii`` file with some information about your Raspberry Pi. This information will be used for deploying your program into an appropriate location of your card file system, and will eventually be copied to your hive ``settings.bii`` configuration file. Just look for this line in your workspace ``environment.bii`` file and fill in the correct values: ::
	
	rpi: {directory: /home/pi, ip: 127.0.0.8, password: raspberry, user: pi}
	
* **directory**: Raspberry Pi directory where you want your programs to be saved.
* **ip**: Raspberry Pi local IP address. Write here your Raspberry Pi network address, that you can find out executing the ``ifconfig`` in a console inside the raspberry.
* **user**: Raspberry Pi user name.
* **password**: Raspberry Pi password.

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
