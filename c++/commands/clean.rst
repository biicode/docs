

.. _biiclean:

``bii clean``: delete meta-information
------------------------------------------

The ``bii clean`` command cleans most of biicode internal project meta-information, keeping the strictly minimum required to reconstruct everything in a subsequent command.

In theory, this command should not exist, but it is sometimes necessary, especially when new versions of biicode client are released that might have backwards incompatibilities.

.. code-block:: bash

	$ bii clean

This has an option to delete user cache too:

.. code-block:: bash

	$ bii clean --cache

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_