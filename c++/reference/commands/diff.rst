.. _bii_diff_command:

**bii diff**: compare block versions
-------------------------------------

Compare files and show their differences with **bii diff** command. You can compare your current local project against a previously published version or compare between published versions.

.. code-block:: bash

	$  bii diff [--short] [block_name] [v1it ] [v2]

Usage
^^^^^^

``fenix`` user has an ``armadillo`` block in a local project and ``4`` different published versions.

Let's see the different possibilities:

* Compare the local block against the latest published version:

	.. code-block:: bash

		$ bii diff

* Compare the local block against a specific version:

	.. code-block:: bash

		$ bii diff fenix/armadillo 2


* Compare two specific published versions (``2`` and ``3``) of your local block:

	.. code-block:: bash

		$ bii diff fenix/armadillo 2 3


* Show just a short diff in any of the previous examples:

	.. code-block:: bash

		$ bii diff --short

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_