.. _bii_merge_command:

``bii merge``: merge versions
===============================

This command allows you to **merge two different versions of the same block**. One of them must be available in a local project. The other must be a published version of the same block. In any case, both versions must have a common ancestor, being different implementations of the same block. **This feature is still experimental**.

.. code-block:: bash

	$ bii merge "user_name/block_name: VERSION"


Examples
--------

Merge with the last version from block ``user22/math_libs`` 

.. code-block:: bash

	$ bii merge user22/math_libs

Merge with version ``2`` from block ``user22/math_libs``

.. code-block:: bash

	$ bii merge "user22/math_libs: 2"


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_
