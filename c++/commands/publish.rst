.. _bii_publish_command:

``bii publish``: publish your blocks
=========================================

The ``bii publish`` command is used to publish your code into biicode. 

After your block has been published and uploaded to biicode servers, the program shows a message with information about the name of the block (``user_name/simple_name``), and the numeric ID of the published version.

.. code-block:: bash

	$ bii publish


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

There's a DEV zone to publish the code you're developing. The blocks published with DEV tag will always be the same version (version: 0). And by default, whenever you ``bii publish`` your code is tagged as DEV.

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

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_

.. container:: infonote

	Visit the section: :ref:`Merge command <bii_merge_command>`


