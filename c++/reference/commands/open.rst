.. _bii_open_command:

**bii open**: edit published blocks
=========================================

Use ``bii open`` command to use and edit any published block locally.

You can use this command to edit **any block** you've seen on the web and you want to edit.
Just create a new project and once in it, open the block:

.. code-block:: bash

	  $ bii init myproject
	  $ cd myproject
	  ~/myproject$ bii open USER_NAME/BLOCK_NAME


You can find the block you just opened in the ``blocks`` folder within your project.

Take a look at :ref:`Workflows<cpp_workflows>` section to learn how to modifify its source files and publish a new version.

If you are updating or creating a block from another service, check the :ref:`integration guide<integration>` to know how to proceed.




