.. _first_steps:

Installation
============

This section describes the **first basic steps that are mandatory in order to use the biicode technology on any computer**, regardless the target platform (desktop, raspberry Pi, Arduino…) or operating system.

1. Sign up
----------

First of all, `sign up in our biicode website <https://www.biicode.com/accounts/signup>`_ and **get your own user account**. It will take you less than 1 minute!

.. _download_client_binaries:

2. Download Biicode Installer
-----------------------------

Now, `download the appropriate client binaries for your development platform <https://www.biicode.com/downloads>`_, execute the setup program and follow the instructions.

**Biicode is an evolving technology**, and many modifications and improvements are introduced weekly with our releases. Rememeber to check frequently for new versions of the client, consult the :ref:`ChangeLog <changelog>`, and **make sure you are not using a deprecated version** reading our :ref:`upgrading section <upgrading>`.

.. container:: infonote

    **Alternative install for Debian based distributions (Ubuntu, Raspbian)**

    You can use the ``apt-get`` program for installing biicode using our APT repository:

    Quick install: 

    .. code-block:: bash

        wget http://apt.biicode.com/install.sh && chmod +x install.sh && ./install.sh


    Step by step install:

    .. code-block:: bash

        # 1. Add this line to your /etc/apt/sources.list file
        deb http://apt.biicode.com/debian/ stable non-free
        
        # 2. Add our public key executing:
        wget -qO- http://apt.biicode.com/packages.biicode.key | sudo apt-key add -
        
        # 3. Execute apt-get update:
        sudo apt-get update 
        
        # 4. Execute apt-get install: 
        sudo apt-get install biicode

.. _create_workspace:

3. Create your first workspace
------------------------------

Now you are ready to create your first **biicode workspace**. This is the place where all your :ref:`hives <hive_definition>` will be located. In general, this step needs to be done only once after the initial setup.

**Note:** Please **avoid creating biicode workspaces in paths with spaces or colons ':'**.

The following example shows a workspace created by the biicode user ``phil``. Take into account that you need to provide your own user name and password, chosen in the *Sign up* step:

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7621.js" id="asciicast-7621" async data-speed="2"></script>

As you can see, it is possible to set a default programming language as well as a default IDE. Now you have created the biicode workspace that will contain all your code!

4. Install the development tools
--------------------------------

Finally, **you may need to install some additional tools dependending on your development language**. Select your language from the list bellow. You will be redirected to the specific documentation section for that particular language, where you will find more information and resources. Don't forget to come back to this general section, and learn more about biicode :ref:`basic <basic_usage>` and :ref:`advanced <advanced_features>` features, and check the :ref:`reference <biicode_reference>`.

* :ref:`C/C++ development tools installation <cpp_installation>`
* :ref:`Arduino development tools installation <arduino_installation>`
* :ref:`Raspberry Pi development tools installation <rpi_installation>`
* :ref:`Node.js development tools installation <node_installation>`

