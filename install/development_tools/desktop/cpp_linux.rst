.. _cpp_desktop_linux:

C++ Linux
===========

**C++**: Install the required development tools as root:

.. code-block:: bash

	$ sudo apt-get install build-essential cmake

	

**NOTE:** If you have not installed the client binaries from `here <https://www.biicode.com/downloads>`_ yet, you can do it this way too:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu[ARCH]_[VERSION].deb

For example, you want to install the new release biicode package *bii-ubuntu64_0_7_2.deb* in your Ubuntu 12.10 64 bits version, then you have to enter:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu64_0_7_2.deb
	
If you would have the 32 bits version:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu32_0_7_2.deb