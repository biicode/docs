Installation and Setup
======================

In this section you will learn how to get the biicode client and install it on your system.

.. toctree::
	:hidden:

	changelog

Download and install the client binaries
----------------------------------------

First of all, download the appropriate client binaries for your system, execute the setup program and follow the instructions. 

+----------------+----------------------------------+------------------------+-----------------------+
|    VERSION     |              UBUNTU              |      WINDOWS           |       MAC OS          |
+----------------+----------------------------------+------------------------+-----------------------+
| 0.1.12.3       | `bii-ubuntu32.deb`_              | `bii-win-setup.exe`_   | `bii-macos64.pkg`_    |
|                +----------------------------------+                        |                       |
|                | `bii-ubuntu64.deb`_              |                        |                       |
+----------------+----------------------------------+------------------------+-----------------------+
| 0.1.11         | Deprecated version. Please, upgrade to 0.1.12.3                                   |
+----------------+-----------------------------------------------------------------------------------+

.. _bii-ubuntu32.deb: https://s3.amazonaws.com/biibinaries/release/0.1.12.3/bii-ubuntu32.deb
.. _bii-ubuntu64.deb: https://s3.amazonaws.com/biibinaries/release/0.1.12.3/bii-ubuntu64.deb
.. _bii-win-setup.exe: https://s3.amazonaws.com/biibinaries/release/0.1.12.3/bii-win-setup_0.1.12.3.exe
.. _bii-macos64.pkg: https://s3.amazonaws.com/biibinaries/release/0.1.12.3/bii-macos64.pkg

Here is the :doc:`changelog`.

Install the development tools
-----------------------------

Now, you need to install some development tools in your machine.

Linux
^^^^^

**C++**: Install the required development tools as root:

.. code-block:: bash

	$ sudo apt-get install build-essential cmake

Windows
^^^^^^^

**C++**: You need to install the following elements:

* `MinGW, the minimalist GNU for Windows <http://www.mingw.org/>`_. This project provides an Open Source minimalist development environment for native Microsoft Windows applications. Follow `this link <http://sourceforge.net/projects/mingw/files/Installer/>`_ to get the installer.
* `CMake, an Open Source tool that manages the software building process in a compiler-independent manner <http://www.cmake.org/>`_. You can `download the latest version of CMake from this location <http://www.cmake.org/cmake/resources/software.html>`_.

Max OS
^^^^^^

**C++**: You need to install:

* The XCode Developeer Tools
* The appropriate `version of CMake <http://www.cmake.org/cmake/resources/software.html>`_ for your Mac OSX.

Create a workspace
------------------

The final step is creating your own biicode workspace. This is the place where all your hives will be located. In general, this steps needs to be done only once after the initial setup.

.. code-block:: bash

	$ mkdir biicode_workspace 
	$ cd ~/biicode_workspace
	$ bii init
	$ Username: your_user_name
	$ Password for your_user_name: your_password 

