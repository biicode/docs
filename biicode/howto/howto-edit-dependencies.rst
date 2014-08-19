.. _edit_dependecies:


Edit any published block
===========================

To edit a block you like it or you depend on, you've to follow the below steps.

1. Open a block
^^^^^^^^^^^^^^^^^^^^

Use ``bii open`` command and move any published block to your project:

.. code-block:: bash

	$ bii open "user_name/block_name(user/branch): VERSION"

**Examples**

So if you want to open the |diego_ardunet_block| and edit it:

.. |diego_ardunet_block| raw:: html

   <a href="http://www.biicode.com/diego/diego/ardunet/master" target="_blank">diego/ardunet block (branch=master and version=lastest by default)</a>

.. code-block:: bash

	$ bii open diego/ardunet

Then you can code on it as if it was yours and changes will be reflected in your code, at build time.

Suppose the last version of ``diego/ardunet`` and ``master`` branch is the "7" and you want to open the ``2`` version, execute:

.. code-block:: bash

	$ bii open "diego/ardunet: 2"

Imagine that "diego/ardunet" has published a branch named ``improvements`` and the last version of this one is the ``5``. So if you want to edit it:

.. code-block:: bash

	$ bii open "diego/ardunet(improvements): 5"


Finally, if you could open the ``last version`` of a branch, e.g. ``release``, but the owner is other user, e.g. ``phil``:

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