.. _hive_usage:

Hive usage
==========

A :ref:`hive<hive_definition>` provides you with a great advantage because of **you can move it to any PC and use it when you want**. You can compress it in a zip, save it, for example, in Dropbox, open it in other computer where you have a workspace and continue working.

**Note:** It's recommended to execute ``bii clean`` before moving the hive so that you delete all the cached junk and take up less space.

``CAUTION:`` Special attention if you are working in a same hive from different places because you could end up overwriting part of your code, if you have complex working flows we recommend using a VCS such as git or mercurial.

Here you can find some basic commands to apply to your hive.

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
	
	
.. _biiupload:

Uploading your hive
-------------------

When you perform a ``bii upload`` you are uploading the hive with your current blocks to biicode servers. In this case, there are some differences with respect to the blocks published. 

* These hives are only visible by you. No one can access them.
* There aren't any tag or publish messages involved.
* You cannot reuse any blocks which are in this hive from other hives unless they are published. This means your unpublished blocks do not exist outside of the hive where they lay.


.. code-block:: bash

	$ bii upload


.. _biidownload:

Downloading your hive
---------------------
You can download any hive you have previously uploaded. You only need to know the hive name and enter execute this command in your workspace directory.

.. code-block:: bash
	
	$ cd my_workspace
	$ bii download --hive your_hive_name

``CAUTION:`` Remember the downloaded hive is a copy. If you make changes in your hive and upload them later, it will overwrite the oldest files in biicode servers.
