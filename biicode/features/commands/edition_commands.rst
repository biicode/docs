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

bii open
--------

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

bii close
---------

You can use ``bii close <block_name>`` command to close a block under edition in ``blocks``, i.e., a block that you have done a ``bii open`` and have be editing it. If it's a dependency of any block yours, moves it to ``deps`` folder.

.. code-block:: bash

	$ bii close martha/her_block

.. _bii_merge_command:

bii merge
---------

This command allows you to **merge two different versions of the same block**. One of them must be available in a local hive. The other must be a published branch of the same block. In any case, both versions must have a common ancestor, being different implementations of the same block. **This feature is still experimental**.

Imagine, for instance, your username is ``original`` and you are the original creator of a block named ``mathematyka``, and its last published version in the ``master`` branch is the number ``25``. That is, there is a ``original/mathematyka(original/master): 25`` version of your block published and available in the biicode servers. Now, let's assume another biicode user, with username ``improver``, :ref:`opens your block<bii_open_command>` in a new ``better_math`` branch, and makes some amazing improvements to your library. They are available in the ``original/mathematyka(improver/better_math): 5`` version, and they are so good that you decide to integrate those changes with your working branch of the library. You only need to use the ``bii merge`` command as follows, from the hive containing the last working copy of your block:

.. code-block:: bash

	$ bii merge --block original/mathematyka --branch improver/better_math
	INFO: Merging with: original/mathematyka(improver/better_math): 5
	...


In this case you indicate in the ``--block`` parameter the local version of the block where you desire to integrate the remote changes, and ``--branch`` is the name of the branch containing the new code to be merged locally. If no ``--version`` number is given, the last published version of the remote branch is used. In case of any conflict during the process, the *diff*  information will be included in the corresponding conflictive files, and a warning message will be generated by the client.
