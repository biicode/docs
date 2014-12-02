.. _bii_diff_command:

``bii diff``: compare between block versions
---------------------------------------------

Compare files and show differences with ``bii diff`` command. You can compare your current project with previous published versions or compare between published versions.

.. code-block:: bash

	$  bii diff [--short] [block_name] [v1] [v2]

Cases
^^^^^^

Imagine you are ``fenix`` user with an ``armadillo`` block in your current project and you published ``4`` different versions.

Let's see the different possibilities:

* Compare your current block with your last published current block version:

	.. code-block:: bash

		$ bii diff

* Compare your current block with a specific version:

	.. code-block:: bash

		$ bii diff fenix/armadillo 2


* Compare two specific versions (``2`` and ``3``) of your current block:

	.. code-block:: bash

		$ bii diff fenix/armadillo 2 3


* You have the possibility to see a short diff output in any previous cases:

	.. code-block:: bash

		$ bii diff --short

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_