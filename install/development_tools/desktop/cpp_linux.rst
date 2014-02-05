.. _cpp_desktop_linux:

C++ Linux
===========

**C++**: Install the required development tools as root:

.. code-block:: bash

	$ sudo apt-get install build-essential cmake
	$ sudo sudo dpkg -i bii-ubuntu[ARCH]_[VERSION].deb

For example, you want to install the new release biicode package *bii-ubuntu64_0_8.deb* in your Ubuntu 12.10 64 bits version, then you have to enter:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu64_0_8.deb
	
If you would have the 32 bits version:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu32_0_8.deb