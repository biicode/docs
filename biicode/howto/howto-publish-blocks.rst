.. _publish_blocks:

Publish blocks
===============

Use ``bii publish`` command into a **project** folder. Take a look at the different options to publish:

If your **project** contains multiple blocks under your ``blocks`` folder, you'll  which one of them (``user_name/block_name``) 

Available publishing options:
-----------------------------

* Tag's default value is DEV, but you can define different **tags** for the code you're publishing: 	

	* ``DEV``: The code you are publishing is ready to be reused by yourself (or maybe your dev team).
	|
	* ``ALPHA``: The code is ready to be reused by some friends or colleagues you explicitly invite to test your code.
	|
	* ``BETA``: The code can be used by anyone in the world willing to test others code.
	|
	* ``STABLE``: Ready to be reused by anyone in the world.

 They define the development state of your code. The :ref:`policies<policies>` file holds the tags and info about the blocks you're reusing from.
|
* Also, it's nice to **write a short message describing the code your are publishing**, and the new functionalities it provides (bugs fixed, or any other valuable information).


Publish using  DEV tag
-----------------------

There's a DEV zone to publish the code you're developing. The blocks published with DEV tag will always be the same version (version: 0), and you won't be able to publish branches while you are working with DEV tag. By default, whenever you ``bii publish`` your code is tagged as DEV.

.. code-block:: bash

	$ bii publish

Publish with other tags
------------------------

Publish your blocks with different tags:

.. code-block:: bash

	$ bii publish --tag STABLE


Publish with a descriptive message
-----------------------------------

Publish your blocks with a brief message:

.. code-block:: bash

	$ bii publish --msg "A brief block description"


Publish one of your project blocks
-----------------------------------

If you only have one block, you don't need to specify it, but if you have several ones:

.. code-block:: bash

	$ bii publish BLOCK_NAME



.. _publish_branches:

Publish a branch
---------------------

Publishing a branch is so simple. When you don't want to publish a version to ``master`` (default branch), only execute:

.. code-block:: bash

	$ bii publish --branch BRANCH_NAME

For example:

.. code-block:: bash

	$ bii publish --branch develop


.. container:: infonote

	*	**You can only publish a branch if you’ve made a previous publication with a tag different from DEV**
	*	Visit the section: :ref:`how to merge branches <merge_branches>`


Complete example
-----------------

Imagine you're ``fenix`` user and you're editing two blocks, ``fenix/vector`` and ``fenix/matrix``. Now you wish to publish them using DEV tag:

.. code-block:: bash

	$ bii publish fenix/vector --msg "Developing a vector C++ library"

.. code-block:: bash

	$ bii publish fenix/matrix --msg "Developing a matrix C++ library"

After a while, you are sure about publishing ``fenix/vector`` as STABLE version:

.. code-block:: bash

	$ bii publish fenix/vector --tag STABLE --msg "Vector C++ library v1.0"

You decide to follow improving ``fenix/vector`` block in another branch and publish it using DEV tag:

.. code-block:: bash

	$ bii publish fenix/vector --branch develop --msg "Branch develop from vector C++ library v1.0"


.. container:: infonote

	Visit the section: :ref:`how to merge branches <merge_branches>`