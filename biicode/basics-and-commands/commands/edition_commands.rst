.. _bii_edition_commands:

Edition commands
================

This section summarizes the general **commands available to be used with the biicode client program**. The biicode client is the main utility that allows you to:

* **manage** your hives and blocks locally, on your computer,
* determine their internal and external **dependencies**,
* **retrieve** any missing code dependencies from the biicode servers,
* **publish** your code, and
* **reuse** other users' code.

All these functionalities are achieved using appropriate commands that are explained and used in many examples along this documentation, and are compiled here in a list for your convenience and reference.


.. contents:: List of commands
   :local:
   :depth: 1

.. _bii_open_command:

``bii open``: Editing code
------------------------------

This command allows you to edit a published block.
You can use this command to edit **one of your dependency blocks** or any block you have seen on the web and you want to edit.
When you invoke this command the block is placed into the ``blocks`` folder within your hive, and their cells become editable source files that can be modified by you and eventually published in a new version of the same branch (if you have writting permissions for that branch) or in a new branch (using the :ref:`publish command<bii_publish_command>`).

There are different ways of retrieving a block created by you or other biicode user to perform some modifications:

That block is a dependency of your code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is the most general scenario. In this case, you are **using some cells from a previously published block** (originally created by you, or by another biicode user) . This means that yout have executed the :ref:`find command<bii_find_command>` inside your hive, and some external dependencies have been retrieved from the biicode servers, and copied to the ``deps`` folder of your hive. Let's imagine your user name is ``peter``, and your block ``peter/my_block`` has dependencies on some files written by the user ``martha``. In particular your code contains references to the block ``martha/her_block``.  After calling the ``bii find`` command, only those files your block needs are copied under the ``deps`` folder of the hive you are working on. 

If you decide to make some modifications to the code you are using, you must call the ``bii open`` command, passing as a parameter the name of the block you intend to modify:

.. code-block:: bash

	$ bii open martha/her_block

Then, the biicode client copies martha's full block to your ``blocks`` hive folder, and you can perform any modifications you need, and eventually publish the modifications on a new branch for that block.

You have an empty hive
^^^^^^^^^^^^^^^^^^^^^^

We can directly call the ``bii open <block_name>`` command and retrieve any published block from the Biicode servers. The code is then copied to the ``blocks`` folder of the **hive** we are working on, and we can modify it as any other source block.

Your hive is not empty
^^^^^^^^^^^^^^^^^^^^^^

This case is very similar to the empty hive one except it may alter your current dependencies. If you already have edition blocks in your hive and you open another one that is not related to your other blocks, its dependencies will prevail over your existing dependencies. This means your dependencies can be upgraded or downgraded to match the ones in the block you are opening. If you want to enforce specic versions you can always do it editing your :ref:`policies file<policies>`.


.. _bii_close_command:

``bii close``: Finish editing the code
----------------------------------------

You can use ``bii close <block_name>`` command to close a block under edition in ``blocks``, i.e., a block that you have done a ``bii open`` and have be editing it. If it's a dependency of any block yours, moves it to ``deps`` folder.

.. code-block:: bash

	$ bii close martha/her_block

