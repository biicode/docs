.. _publish_blocks:

Publish blocks
==================

The ``bii publish command`` must be invoked inside a **project** folder. It has some options to complement your publication:

* In case your **project** contains multiple blocks under your ``blocks`` folder, you'll select which of them (``user_name/block_name``) you wish to publish.
|
* If you want, you can define a **tag** for the published code. Available options are: 	

	* ``DEV``: The code you are publishing is ready to be reused by yourself (or maybe your dev team)
	|
	* ``ALPHA``: The code is ready to be reused by some friends or colleagues you explicitly invite to test your code
	|
	* ``BETA``: The code could be used by anyone in the world willing to test others code
	|
	* ``STABLE``: Ready to be reused by anyone in the world.

 They define the state of the development for your code. This information is used in by the :ref:`policies<policies>` of the users that will use this blocks.
|
* Finally, you could provide a short message describing the code your are publishing, and the new functionalities it provides (bugs fixed, or any other valuable information).



Publish using  DEV tag
-----------------------

Now, if you're not sure to share the code with all developers, biicode offers you a DEV zone to publish the code. The blocks published with DEV tag will be always the same version (version: 0), and you won't be able to publish branches while you will be working with this tag. By default, when you execute the command, the tag is DEV:

.. code-block:: bash

	$ bii publish

Publish using any tag
----------------------

To publish your blocks with different tags:

.. code-block:: bash

	$ bii publish --tag TAG_NAME


Publish with a descriptive message
-----------------------------------

To publish your blocks with different tags:

.. code-block:: bash

	$ bii publish --msg "A brief block description"


Publish one of your project blocks
-----------------------------------

If you only have one block, you don't need to specify it, but if you have several ones:

.. code-block:: bash

	$ bii publish --block BLOCK_NAME


.. _publish_branches:

Publish a branch
---------------------

To publish a branch is so simple. When you don't want to publish a version to ``master`` (default branch), only execute:

.. code-block:: bash

	$ bii publish --branch BRANCH_NAME

For example:

.. code-block:: bash

	$ bii publish --branch develop


.. container:: infonote

	*	**You can only publish a branch if you've made a previous publication with different tag to DEV**
	*	Visit the section: :ref:`how to merge branches <merge_branches>`


Complete example
-----------------

Imagine you're ``fenix`` user and you're editing two blocks, ``fenix/vector`` and ``fenix/matrix``. Now you wish to publish them using DEV tag:

.. code-block:: bash

	$ bii publish --block fenix/vector --msg "Developing a vector C++ library"

.. code-block:: bash

	$ bii publish --block fenix/matrix --msg "Developing a matrix C++ library"

After a while, you are sure about publishing ``fenix/vector`` as STABLE version:

.. code-block:: bash

	$ bii publish --block fenix/vector --tag STABLE --msg "Vector C++ library v1.0"

You decide to follow improving ``fenix/vector`` block in another branch and publish it using DEV tag:

.. code-block:: bash

	$ bii publish --block fenix/vector --branch develop --msg "Branch develop from vector C++ library v1.0"


.. container:: infonote

	Visit the section: :ref:`how to merge branches <merge_branches>`