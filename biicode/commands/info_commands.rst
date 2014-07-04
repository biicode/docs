.. _bii_info_commands:


Info commands
===============

.. _bii_deps_command:

``bii deps``: show block dependencies
--------------------------------------

This command allows you to check the dependencies of any project. It's basic form, with no parameters, provides two pieces of information, giving you a general idea of which are your code dependencies:

* The **Dependencies Table**: a list of the **blocks that contain cells your code depends on**.
* The full list of your cell dependencies.

.. code-block:: bash

	$ bii deps

.. container:: todo

	Visit the section: :ref:`how to view all the block dependencies <view_block_dependencies>`

.. _bii_status_command:

``bii status``: show block changes
-----------------------------------

``bii status`` command indicates you if there are changes in your code.

For example, if you have not changes:

.. code-block:: bash

	$ bii status
	INFO: Everything up to date

If you have changes in a ``main.cpp`` file:

.. code-block:: bash

	$ bii status
	[USER]/[BLOCK_NAME]

	  Modified:
	    [USER]/[BLOCK_NAME]/main.cpp


.. _bii_diff_command:

``bii diff``: compare between block versions
---------------------------------------------

Compare files and show differences with ``bii diff`` command. You can compare your current project with previous published versions or compare between published versions.

.. code-block:: bash

	$ bii diff BLOCK_VERSION_1 BLOCK_VERSION_2

.. container:: todo

	Visit the section: :ref:`how to compare two blocks <compare_blocks>`