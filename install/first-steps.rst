.. _first_steps:

First Steps
===========
These are the right steps to start using biicode without problems.

1. Sign up
-------------
Sign up in our biicode website for an account. It will take you less than 1 minute. Click `here to sign up <https://www.biicode.com/accounts/signup>`_.

.. _download_client_binaries:

2. Download the client binaries
----------------------------------

Now, `download the appropriate client binaries for your system <https://www.biicode.com/downloads>`_, execute the setup program and follow the instructions.

For more information, check our evolution in the :ref:`changelog <changelog>`.

If you are a biicode user, you may have to :ref:`upgrade<upgrading>`.

	
3. Choose your development tool
----------------------------------

Then you'll need to set up the development tools you're going to use as described in :ref:`development tools installation <desktop_installation>`, select it and go to the final step.


.. _create_workspace:

4. Create your first workspace
---------------------------------

The first step is creating your own **biicode workspace**. This is the
place where all your hives will be located. In general, this step
needs to be done only once after the initial setup.

**NOTE:** Please **avoid creating biicode workspaces in paths with spaces or colons ':'**.

.. code-block:: bash

	$ mkdir biicode_workspace
	$ cd ~/biicode_workspace
	$ bii init
	Username: your_user_name
	Password for your_user_name: your_password
	Would you like to set a default programming language? (cpp/None)
	Introduce lang:
	Would you like to set a default IDE? (eclipse/None)
	Introduce ide:
	Initialization correct, now you can create your first hive


As you can see, it's possible to set a default programming language as well as a default IDE. Now you have created the biicode workspace that will contain all your code!

