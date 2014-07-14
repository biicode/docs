.. _edit_dependecies:


Edit something you depend on
=============================

To edit a block you depend on, use ``bii open``command and move it to your project:

.. code-block:: bash

	$ bii open USERNAME/BLOCK_NAME

Where USERNAME/BLOCK_NAME is DEPENDINGBLOCK_OWNER/DEPENDINGBLOCK_NAME

Then you can code on it as if it was yours and changes will be reflected in your code, at build time.

Once you are happy with the changes, publish your own version of the block:

.. code-block:: bash

	$ bii publish USERNAME/BLOCK_NAME --branch BRANCH_NAME

Unless the code is yours you will not be able to publish it to an existing branch, so you need to specify a BRANCH_NAME.

Then you can close the block to remove it from your blocks folder:

.. code-block:: bash

	$ bii close USERNAME/BLOCK_NAME

Your code will now depend on the version you have just published.


Manually configuring dependencies
---------------------------------

There are some special cases in which biicode can't detect some dependencies. In these cases **you can manually configure your dependencies**.

For this purpose you can use :ref:`dependencies.bii <dependencies_bii>`

Got any doubts? `Ask in our forum<http://forum.biicode.com>`_


