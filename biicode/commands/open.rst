.. _bii_open_command:

``bii open``: edit published blocks
=========================================

This command allows you to edit a published block.
You can use this command to edit **one of your dependency blocks** or any block you have seen on the web and you want to edit.
When you invoke this command the block is placed into the ``blocks`` folder within your project, and their cells become editable source files that can be modified by you and eventually published in a new version of the same branch (if you have writting permissions for that branch) or in a new branch (using the :ref:`publish command<bii_publish_command>`).

.. code-block:: bash

	$ bii open USER_NAME/BLOCK_NAME

To open someone's branch, you will place the branch's user and block in brackets after its creator's user name and block name, like this:

.. code-block:: bash

	$ bii open USER_NAME/BLOCK_NAME(BRANCH_USER_NAME/BRANCH_BLOCK_NAME)


.. _edit_dependecies:


Edit any published block
---------------------------

To **edit a block you are interested in or you depend on**, you've to follow the below steps.

1. Open a block
^^^^^^^^^^^^^^^^^^^^

Use ``bii open`` command and move any published block to your project:

.. code-block:: bash

	$ bii open "user_name/block_name(user/branch): VERSION"

**Examples**

So if you want to open the |diego_ardunet_block| (branch=master and version=lastest by default) and edit it:

.. |diego_ardunet_block| raw:: html

   <a href="http://www.biicode.com/diego/diego/ardunet/master" target="_blank">diego/ardunet block</a>

.. code-block:: bash

	$ bii open diego/ardunet

Then you can code on it as if it was yours and changes will be reflected in your code, at build time.

Suppose the last version of ``diego/ardunet`` and ``master`` branch is the "7" but you want to open the ``2`` version, execute:

.. code-block:: bash

	$ bii open "diego/ardunet: 2"

Imagine that "diego/ardunet" has published a branch named ``improvements`` and you're interested in ``5`` version. So if you want to edit it:

.. code-block:: bash

	$ bii open "diego/ardunet(improvements): 5"


Finally, you could open the ``last version`` of a branch, e.g. ``release``, whose owner is other user, e.g. ``phil``:

.. code-block:: bash

	$ bii open "diego/ardunet(phil/release)"


2. Publish the changes
^^^^^^^^^^^^^^^^^^^^^^^^

Once you are happy with the changes, publish your own version of the block:

.. code-block:: bash

	$ bii publish user_name/block_name --branch BRANCH_NAME

**Unless the code is yours you will not be able to publish it to an existing branch**, so you need to specify a BRANCH_NAME.


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