.. _compare_blocks:

Compare two blocks
===================

The ``bii diff`` command offers us this possibility. We have some cases to compare them.

Cases
--------

Imagine you are ``fenix`` user with an ``armadillo`` block in your current project and you published ``4`` different versions to ``master`` branch and ``5`` versions to ``develop`` branch. 
Let's see the different possibilities:

* Compare your current block with your last published current block version:

	.. code-block:: bash

		$ bii diff fenix/armadillo

* Compare your current block with a specific version:

	.. code-block:: bash

		$ bii diff fenix/armadillo fenix/armadillo:2


* Compare two specific versions of your current block:

	.. code-block:: bash

		$ bii diff fenix/armadillo:2 fenix/armadillo:3


* Compare your current block with a branch version:

	.. code-block:: bash

		$ bii diff fenix/armadillo fenix/armadillo(develop):5


Got any doubts? `Ask in our forum<http://forum.biicode.com>`_