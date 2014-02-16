.. _hive_usage:

Hive usage
==========

We :ref:`already know that a hive is basically a container for our blocks<hive_definition>`; or more simply said, a **biicode project**. Every single folder located inside your biicode workspace folder —other than the special ``bii`` workspace configuration folder— contains an individual hive, and these folders always exhibit :ref:`the same internal structure <hive_layout>`.

One consequence of this workspace and hives hierarchical configuration (all hives are folders contained directly inside your workspace) is that **you can copy any hive from one workspace to another simply by moving the hive folder with all its contents**. You can zip it and send it, or even share a hive in a `Dropbox folder <https://www.dropbox.com>`_ with your friends or collaborators, and then copy these contents into a different workspace and continue working.

**Note:** It's recommended to execute the ``bii clean`` command before copying or moving a hive, in order to delete all the cached unncessary information. Also, **be specially careful when working on a same hive from different workspaces!** You could end up overwriting part of your own code. If you have complex working flows we recommend using a SCM system such as `git <http://git-scm.com/>`_ or `mercurial <http://mercurial.selenic.com/>`_ .

	
.. _biiupload:

Uploading your hive
-------------------

The ``bii upload`` command allows you to upload any hive with all its contained blocks to the biicode servers. **This is not the same as publishing a block** with the ``bii publish`` command:

* Any uploaded hive **is private**; only you can see them on your biicode profile web page, and no other biicode user has access to them.
* There aren no *tags* or *publish messages* involved.
* You cannot reuse any blocks which are in this hive from other hives; :ref:`you must publish them first <biipublish>` using the :ref:`bii publish command<bii_publish_command>`. This means that your unpublished blocks do not exist outside of the hive where they lay.

.. code-block:: bash

	$ bii upload


.. _biidownload:

Downloading your hive
---------------------

You can download any hive you have previously uploaded. You only need the **name of the uploaded hive** and the help of the ``bii download`` command, that must be executed inside a biicode workspace:

.. code-block:: bash
	
	$ cd my_workspace
	$ bii download --hive <your_hive_name>

**Note:** Remember **any downloaded hive is just a copy of the original one**. If you make changes to your hive and upload them later, it will overwrite the oldest files in biicode servers.
