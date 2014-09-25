.. _bii_merge_command:

``bii merge``: merge branches
===============================

This command allows you to **merge two different versions of the same block**. One of them must be available in a local project. The other must be a published branch of the same block. In any case, both versions must have a common ancestor, being different implementations of the same block. **This feature is still experimental**.

.. code-block:: bash

	$ bii merge "user_name/block_name(user/branch): VERSION"


Examples
--------

Merge the last version from block ``user22/math_libs`` and ``master`` branch

.. code-block:: bash

	$ bii merge user22/math_libs

Merge version ``2`` from block ``user22/math_libs`` and ``master`` branch 

.. code-block:: bash

	$ bii merge "user22/math_libs: 2"


Merge version ``7`` from block ``user22/math_libs`` and ``develop`` branch 

.. code-block:: bash

	$ bii merge "user22/math_libs(develop): 7"


Merge the last version from block ``user22/math_libs`` and ``develop`` branch 

.. code-block:: bash

	$ bii merge "user22/math_libs(develop)"


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_
