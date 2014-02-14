.. _first_steps:

First Steps
===========


1. Sign up
-------------
Sign up in our biicode website for an account. It will take you less than 1 minute. Click `here to sign up <https://www.biicode.com/accounts/signup>`_.

.. _download_client_binaries:

2. Download the client binaries
----------------------------------
Now, `download the appropriate client binaries for your system <https://www.biicode.com/downloads>`_, execute the setup program and follow the instructions.

For more information, check our evolution in the :ref:`changelog <changelog>`.

If you are a biicode user, you may have to :ref:`upgrade<upgrading>`.

Alternative install for Debian based distributions (Ubuntu, Raspbian)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can use *apt-get* for install biicode using our APT repository:

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

	
3. Choose your development tool
----------------------------------

Then you'll need to set up the development tools you're going to use as described in :ref:`development tools installation <desktop_installation>`, select it and go to the final step.


.. _create_workspace:

4. Create your first workspace
---------------------------------

The first step is creating your own **biicode workspace**. This is the place where all your hives will be located. In general, this step needs to be done only once after the initial setup.

**NOTE:** Please **avoid creating biicode workspaces in paths with spaces or colons ':'**.

This example is created by a biicode user named "phil", you will have to enter the user name and password which you have chosen in the *Sign up* step:

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7621.js" id="asciicast-7621" async data-speed="2"></script>

As you can see, it's possible to set a default programming language as well as a default IDE. Now you have created the biicode workspace that will contain all your code!

