.. _compare_blocks:

Compare two blocks
===================

The ``bii diff`` command offers us this possibility. We have some cases to compare them.

Cases
--------

Imagine you are ``fenix`` user, you have ``armadillo`` block in your current project and you have already published ``4`` versions to branch ``master`` and ``5`` versions to branch ``develop``. Now, we'll see the different possibilities:

* Comparing your current block with your last published current block version.

	.. code-block:: bash

		$ bii diff fenix/armadillo

* Comparing your current block with a specific version 

	.. code-block:: bash

		$ bii diff fenix/armadillo fenix/armadillo:2


* Comparing two specific versions of your current block

	.. code-block:: bash

		$ bii diff fenix/armadillo:2 fenix/armadillo:3


* Comparing your current block with a branch version

	.. code-block:: bash

		$ bii diff fenix/armadillo fenix/armadillo(develop):5