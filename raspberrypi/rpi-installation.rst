.. _rpi_installation:

Installation
============

**Biicode** is a file-oriented Dependencies Manager for C and C++ developers. Install both 
Biicode and the cross compiling tools for Raspberry PI to get started.

Install Biicode
-----------------

**Download** `Biicode Installer <https://www.biicode.com/downloads>`_ and double-click the downloaded package to install it.

Open the terminal and **make sure biicode is installed**:


.. code-block:: bash

   ~$ bii --version

.. container:: infonote

    Check alternative installations for:

    *  :ref:`Debian based distrobutions <alternative_install_debian>`
    *  :ref:`Arch based distrobutions <alternative_install_archlinux>`


Install RPI tools
------------------

To start, install required tools like CMake or GCC:

        .. code-block:: bash

           $ bii setup:rpi


 Re-run ``bii setup:rpi`` command to verify everything is installed.

**Any issues**, `contact us at our forum <http://forum.biicode.com/category/arduino>`__, and feel free to ask any questions. 


Install RPI cross-compiling tools manually
------------------------------------------

Manually install the cross-compiling tools. Go through this section if something failed during the automatic installation explained before. Any issues, please `contact us at our forum <http://forum.biicode.com/category/raspberry-pi>`_, and we'll try to solve it as soon as possible.

C++ tools installation
^^^^^^^^^^^^^^^^^^^^^^

Install the required development tools as root:

.. code-block:: bash

    $ sudo apt-get install build-essential cmake

.. _rpi_32bi_support:

.. container:: infonote

    If your are using a **64-bit version of Linux** as development environment, follow the next steps.

    **Install lib32z1 (only for 64-bit linux versions)**

    To find if your Linux is 32 or 64 bits, just type:
     
    .. code-block:: bash

        $ uname -m

    This command may throw one of the following outputs:

    * ``x86_64`` ==> 64-bit kernel
    * ``i686``   ==> 32-bit kernel

    If you are using a 64-bit OS, you need to install the support for 32 bit applications. These libraries are required to use the cross compilers supplied by Raspberry Pi from their Github repository.

    .. code-block:: bash

        $ sudo apt-get install lib32z1
        
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

.. _rpi_cc_tools:

Raspberry Pi tools installation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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



If you have any questions, we are available at |biicode_forum_link|. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>
