.. _first_steps:

Installation
============

This section describes the **first basic steps that are mandatory in order to use the biicode technology on any computer**, regardless the target platform (desktop, raspberry Pi, Arduino…) or operating system.

.. _download_client_binaries:

1. Download Biicode Installer
-----------------------------

Now, `download the appropriate installer for your development platform <https://www.biicode.com/downloads>`_, execute the setup program and follow the instructions.

**Biicode is an evolving technology**, and many modifications and improvements are introduced weekly with our releases. Rememeber to check frequently for new versions of the client, consult the :ref:`release notes <changelog>`.


.. _alternative_install_debian:

.. container:: infonote


    **Alternative install for Debian based distributions (Ubuntu, Raspbian)**

    You can use the ``apt-get`` program for installing biicode using our APT repository:

    Quick install: 

    .. code-block:: bash

        wget http://apt.biicode.com/install.sh && chmod +x install.sh && ./install.sh


    Step by step install:

    .. code-block:: bash

        # 1. Create a file named '/etc/apt/sources.list.d/biicode.list' and put the line corresponding to your linux distribution:
        
	Ubuntu 12:
        	deb http://apt.biicode.com precise main

	Ubuntu 13:
		deb http://apt.biicode.com saucy main

	Ubuntu 14:
		deb http://apt.biicode.com trusty main
		
	Debian Wheezy:
		deb http://apt.biicode.com wheezy main
		

	# 2. Add our public key executing:
	sudo wget -O /etc/apt/trusted.gpg.d/biicode.gpg http://apt.biicode.com/keyring.gpg       
 
        # 3. Execute apt-get update:
        sudo apt-get update 
        
        # 4. Execute apt-get install: 
        sudo apt-get -y install biicode
        

.. _alternative_install_archlinux:

.. container:: infonote


    **Alternative install for Archlinux based distributions (Manjaro, Arch Linux ARM, etc)**

    Biicode maintains a package at the Arch User Repository (AUR). You can install it using your preferred package manager:

    .. code-block:: bash

        sudo yaourt -S biicode


    Since the package is maintained in the AUR, your package manager will notify you automatically when we update the package.


2. Choose the development tools
--------------------------------

Finally, **you may need to install some additional tools dependending on your development language**. Select your language from the list bellow. You will be redirected to the specific documentation section for that particular language, where you will find more information and resources. Don't forget to come back to this general section, and learn more about :ref:`advanced features <advanced_features>`.


.. container:: todo

    * :ref:`C/C++ Getting Started <cpp_getting_started>`
    * :ref:`Arduino Getting Started <arduino_getting_started>`
    * :ref:`Raspberry Pi (cross compiling) Getting Started <rpi_getting_started>`
    * :ref:`Node.js Getting Started <node_getting_started>`
