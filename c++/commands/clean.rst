.. _biiclean:

**bii clean**: delete meta-information
------------------------------------------

``bii clean`` command cleans most of biicode internal project meta-information, keeping the  minimum required to reconstruct everything in a subsequent command.

It's an all purpose command, especially useful to restore your default project settings or when upgrading to a major release. 

.. code-block:: bash

	$ bii clean

You can delete user cache too:

.. code-block:: bash

	$ bii clean --cache

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_