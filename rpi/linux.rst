How to configure your linux for cross compiling 
===============================================

To use the cross compilers that are in the raspberry pi githab repository need to have the Linux OS installed or a virtual machine that contains it.
We recommend using ubuntu,but any debian distribution should work perfectly.
Now let's look all the tools we need to install to use the Raspberry Pi with biicode.

Install ia32-libs
-----------------

First, if you have 64-bit OS, you need to install the support for 32 bit applications. These libraries are required to use the cross compilers supplied Raspberry Pi from its repository on github.

.. code-block:: bash

	$ sudo apt-get install ia32-libs
	
It is possible that you encounter some of the following errors. 

If it does not find the package, you may need add a 32bits architecture to your package list:

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

Download Raspberry cross-compiler tools
---------------------------------------

Now, clone the Raspberry Pi repository with linux cross-compilers from github.

.. code-block:: bash

	$ cd /usr/local
	$ sudo git clone https://github.com/raspberrypi/tools.git
	
You don't need to compile or install anything. You can choose other directory where to clone `raspberry tools <https://github.com/raspberrypi/tools>`_ but then you will need to update :ref:`biicode settings <settings_bii>`.

Finally, you need to install biicode. Go to :ref:`Installations and setup <installation>` for instructions.
Once you have installed biicode, you can proceed to :ref:`configure your biicode raspberry project <config_raspberry_ws>`.