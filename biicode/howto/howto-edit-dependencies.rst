.. _edit_dependecies:


Edit something you depend on
================================

If you want to edit a block you depend on, you can do it with the ``bii open command`` it and move it to your project. You can do so by executing:

.. code-block:: bash

	$ bii open BLOCK_NAME

Where BLOCK_NAME is DEP_OWNER/DEP_NAME

Then you can work as if the block was yours and the changes you make will be reflected in your code at build time.

Once you are happy with the changes you can publish your own version of the block:

.. code-block:: bash

	$ bii publish BLOCK_NAME --branch BRANCH_NAME

Unless the code is yours you will not be able to publish it to an existing branch, so you will need to specify a BRANCH_NAME.

Then you can close the block to remove it from your blocks folder:

.. code-block:: bash

	bii close BLOCK_NAME

Your code will now depend on the version you have just published.


Manually configuring dependencies
---------------------------------

There are some special cases in which biicode can't detect some dependencies. In these cases **you can manually configure your dependencies**.

For this purpose you can use :ref:`dependencies.bii <dependencies_bii>`


