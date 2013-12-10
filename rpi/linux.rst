How to configure your linux for cross compiling 
===============================================


To use the cross compilers that are in the raspberry pi githab repository need to have the Linux OS installed or a virtual machine that contains it.
We recommend using ubuntu,but any debian distribution should work perfectly.
Now let's look all the tools we need to install to use the Raspberry Pi with biicode.

Install and download some tools
-------------------------------

First, if you have 64-bit OS, you need to install the support for 32 bit applications. These libraries are required to use the cross compilers supplied Raspberry Pi from its repository on github.

.. code-block:: bash

	$ sudo apt-get install ia32-libs
	
If it finds no the package, you may need to add a package:

.. code-block:: bash

	$ sudo dpkg --add-architecture i386
	$ sudo apt-get update
	$ sudo apt-get install ia32-libs

It is possible that you encounter this problem. 

.. code-block:: bash

	Some packages could not be installed. 
	This may mean that you have requested an impossible situation the following packages have unmet dependencies:
	ia32-libs : Depends: ia32-libs-multiarch

If so, just install the dependencies manually like any other package

.. code-block:: bash

	$ sudo apt-get install ia32-libs-multiarch

Now, clone the Raspberry Pi repository with linux cross-compilers from github.


.. code-block:: bash

	$ cd /user/local
	$ sudo git clone https://github.com/raspberrypi/tools.git
	
Finally, it only remains to biicode installed. For a complete description go to: :ref:`Installations and setup <installation>`.