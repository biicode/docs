.. _biiclean:

**bii clean**: delete meta-information
------------------------------------------

``bii clean`` command cleans most of biicode internal project meta-information, keeping the  minimum required to reconstruct everything in a subsequent command.

It's an all purpose command, especially useful to restore your default project settings or when upgrading to a major release. 

``bii clean`` also restores your project's settings to no IDE and MinGW (Windows) or Unix Makefiles with no IDE (MacOS and Linux). 

.. code-block:: bash

	$ bii clean

You can delete user cache too:

.. code-block:: bash

	$ bii clean --cache

Deleting cache is useful to ensure a clean reconfiguration of biicode. It is used when experiencing troubles with temporal and build files in your projects. 

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_