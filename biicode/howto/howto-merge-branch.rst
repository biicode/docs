.. _merge_branches:

Merge branches
=================

If you have published a branch and you wish to merge this branch with your current branch, you only have to execute:

.. code-block:: bash

	$ bii merge BLOCK_VERSION


Examples
--------

Merging the version ``2`` from block ``user22/math_libs`` and branch ``master``

.. code-block:: bash

	$ bii merge user22/math_libs:2


Merging the version ``7`` from block ``user22/math_libs`` and branch ``develop``

.. code-block:: bash

	$ bii merge user22/math_libs(develop):7


Merging the last version from block ``user22/math_libs`` and branch ``master``

.. code-block:: bash

	$ bii merge user22/math_libs

Merging the last version from block ``user22/math_libs`` and branch ``develop``

.. code-block:: bash

	$ bii merge user22/math_libs(develop)

.. container:: infonote

	Visit the section: :ref:`how to publish branches <publish_branches>`