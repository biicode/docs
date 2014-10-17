.. _bii_open_command:

``bii open``: edit published blocks
=========================================

This command allows you to edit a published block.
You can use this command to edit **one of your dependency blocks** or any block you have seen on the web and you want to edit.
When you invoke this command the block is placed into the ``blocks`` folder within your project, and their cells become editable source files that can be modified by you and eventually published in a new version of the same block or into a new block. Check the :ref:`publish command<bii_publish_command>`to know how.

.. code-block:: bash

	$ bii open USER_NAME/BLOCK_NAME


.. _edit_dependecies:


Edit any published block
---------------------------

To **edit a block you are interested in or you depend on**, you've to follow the below steps.

1. Open a block
^^^^^^^^^^^^^^^^^^^^

Use ``bii open`` command and move any published block to your project:

.. code-block:: bash

	$ bii open "user_name/block_name: VERSION"

**Examples**

So if you want to open the |diego_ardunet_block| (version=lastest by default) and edit it:

.. |diego_ardunet_block| raw:: html

   <a href="http://www.biicode.com/diego/diego/ardunet/master" target="_blank">diego/ardunet block</a>

.. code-block:: bash

	$ bii open diego/ardunet

Then you can code on it as if it was yours and changes will be reflected in your code, at build time.

Suppose that the latest version of ``diego/ardunet`` is the "7" but you want to open version ``2`` , execute:

.. code-block:: bash

	$ bii open "diego/ardunet: 2"



2. Publish the changes
^^^^^^^^^^^^^^^^^^^^^^^^

Once you are happy with the changes, publish your own version of the block:

.. code-block:: bash

	$ bii publish user_name/block_name 

Check the :ref:`publish command<bii_publish_command>`to know more.


3. Close the block
^^^^^^^^^^^^^^^^^^^^^^

Then you can close the block to remove it from your blocks folder:

.. code-block:: bash

	$ bii close user_name/block_name

Your code will now depend on the version you have just published.

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_


.. container:: infonote

	If you don't know anything about publish or close command

	*	:ref:`Publish command <bii_publish_command>`
	*	:ref:`Close command <bii_close_command>`