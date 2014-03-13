
Process and clean your hive
===========================
These are some basic commands to apply to your hive.

.. _biiwork:

Processing the code
-------------------

The ``bii work`` command is a very basic command that performs the main processing of biicode for your current hive. It checks what files you have modified, analyzes and search dependencies among your hive files (i.e. locally), and fills the ``deps`` folder. Most times it is not necessary to invoke this command explicitly, because it is automatically called by development commands as ``cpp:run``, ``cpp:build`` or ``cpp:configure``.

.. code-block:: bash

	$ bii work


.. _biiclean:

Cleaning meta-information
-------------------------

The ``bii clean`` command cleans most of biicode internal hive meta-information, keeping the strictly minimum required to reconstruct everything in a subsequent command. In theory, this command should not exist, but it is sometimes necessary, especially when new versions of biicode client are released that might have backwards incompatibilities.

.. code-block:: bash

	$ bii clean
	