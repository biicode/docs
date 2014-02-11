Linux (cross compiling)
========================

How to configure your linux for cross compiling 
-----------------------------------------------

To use the cross compilers that are in the Raspberry Pi Github repository, you need to have a Linux OS installed or a virtual machine that contains it. We recommend using `Ubuntu <http://www.ubuntu.com/>`_, but any Debian distribution should work perfectly.

Now let's look at the tools we need to install to use the Raspberry Pi with biicode.

Install ia32-libs (only for 64bit OS)
-------------------------------------

To find if your Linux is 32 or 64 bits, just type:
 
.. code-block:: bash

	$ uname -m

This command may throw one of the following outputs:

* ``x86_64`` ==> 64-bit kernel
* ``i686``   ==> 32-bit kernel

Then, if you have 64-bit OS, you need to install the support for 32 bit applications. These libraries are required to use the cross compilers supplied by Raspberry Pi from their Github repository.

.. code-block:: bash

	$ sudo apt-get install ia32-libs
	
It is possible that you encounter some of the following errors: 

If it does not find the package, you may need to add a 32bits architecture to your package list:

.. code-block:: bash

	$ sudo dpkg --add-architecture i386
	$ sudo apt-get update
	$ sudo apt-get install ia32-libs

If you get:

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

If you get:

.. code-block:: bash

	Some packages could not be installed. 
	This may mean that you have requested an impossible situation the following packages have unmet dependencies:
	ia32-libs : Depends: ia32-libs-multiarch

just install the dependencies manually like any other package:

.. code-block:: bash

	$ sudo apt-get install ia32-libs-multiarch
	$ sudo apt-get install ia32-libs

Download the Raspberry Pi cross-compiler tools
----------------------------------------------

Automatic installation
^^^^^^^^^^^^^^^^^^^^^^

If you wish that biicode download and configure this for you, just need to use the ``setup:rpi`` command into your workspace folder. (you might need to install git with ``$ sudo apt-get install git``).

.. code-block:: bash

	$ sudo apt-get install git-core

For biicode download and configure everything for you, you just have to run the ``bii rpi:setup`` command:

.. code-block:: bash

	$ bii rpi:setup

	INFO: Cloning the ARM cross compiler into /usr/local/tools
	
	fatal: could not create work tree dir '/usr/local/tools'.: Permision denied
	INFO: Cloning the ARM cross compiler with sudo
	[sudo] password for [USER]:
	
	Cloning into '/usr/local/toos'
	
	Checking out files: 100% (10835/10835), done. 11% (1195/10835)
	
	...
	   
	done
	
If you already have downloaded the cross compilers the setup tool will indicate this with the following message:

.. code-block:: bash

	$ bii rpi:setup

	INFO: Cloning the ARM cross compiler into /usr/local/tools
	
	INFO: The tools are already Downloaded
	
If you want to download the cross compilers another folder or if you already have downloaded to another directory, you just have to indicate the directory  where you want it to clone or where it is.

.. code-block:: bash

	$ bii rpi:setup [directory]

	...
	
Once you have done this, a cross compilers will have downloaded and added to :ref:`enviroment.bii <layouts>`.

Manual installation
^^^^^^^^^^^^^^^^^^^

If you prefer to install manually the cross compiler, clone the Raspberry Pi repository with linux cross-compilers from Github (you might need to install git with ``$ sudo apt-get install git``).

.. code-block:: bash

	$ sudo apt-get install git-core
	$ cd /usr/local
	$ sudo git clone https://github.com/raspberrypi/tools.git

If you don't want to install git on your computer, you can also `download it in zip format <https://github.com/raspberrypi/tools/archive/master.zip>`_ and unzip into the folder you want.
	
You don't need to compile or install anything else. You can choose other directory where to clone the `Raspberry Pi tools <https://github.com/raspberrypi/tools>`_, but then you will need to take it into account in the next step when updating the :ref:`environment.bii <layouts>` file.

If you have reached this point, and you haven't installed biicode yet, visit :ref:`Installation and setup <installation>` for instructions.

Once you have installed biicode, you can proceed to :ref:`configure your biicode Raspberry Pi project <config_raspberry_ws>`.
