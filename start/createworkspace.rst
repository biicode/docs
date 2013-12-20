.. _create_workspace:

Create a workspace
------------------

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


As you can see, it's possible to set a default programming language as
well as a default IDE. Now you have created the biicode workspace that
will containt all your code!
