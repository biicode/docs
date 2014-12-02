.. _bii_open_command:

``bii open``: edit published blocks
=========================================

This command allows you to edit a published block.
You can use this command to edit one of your dependency blocks or **any block** you've seen on the web and you want to edit.
When you invoke this command the block is placed into the ``blocks`` folder within your project, and the source files that can be modified by you and eventually published in a new version of the same block or into a new block. If you are updating or creating a code block from another service, check the :ref:`integration guide<integration>` to know how to proceed.


.. code-block:: bash

	  $ bii init myproject
	  $ cd myproject
	  ~/myproject$ bii open USER_NAME/BLOCK_NAME


