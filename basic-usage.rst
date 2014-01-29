.. _basic_usage:

Basic usage
===========

This section describes **the most common use cases that you will find when using Biicode with your hives**. Biicode is a powerfull tool that automates the resolution of code dependencies, downloading all needed missing files to your computer. To do so, it is able to analyze and understand your code, and find on our servers any missing dependencies. It is clear that all this process relies on two very important activities that are at the very basis of Biicode philosophy and purpose as a service: **sharing and reusing of source code**.

* Some people share their code, publishing their blocks, and uploading the source code to our servers. We analyze avery single block, establishing all internal and external dependencies, and making it available to other biicode users.
* Some people want to reuse that code. These are developers that have the need to reused previously published version of their own blocks, or simply want to take advantage of the code shared by other users.

Biicode provides the tools for analyzing, publishing and reusing code. The basic commands of the :ref:`client binary<installation>` for these activites are explained in the following lines (a more detailed description of some of these commands can be found in the :ref:`commands reference<bii_commands>`):

Web access
----------

One of the most important things is **how can I see my blocks or any user blocks?** You don´t really need to sign in biicode to see it. It´s so fast an easy, you only have to enter the URL:

	``www.biicode.com/user_name``
	
And you'll be able to see all the blocks published and profile about this user.

For example, try the `sbaker user <https://www.biicode.com/sbaker>`_

	
Checking your dependencies
--------------------------

There is one command that, when executed inside any hive in your workspace, is able to determine all dependencies affecting your source code for that particular hive. This is the ``bii deps`` command.

.. code-block:: bash

	$ bii deps

With this command you can **check your hive dependencies**, the versions of external blocks you are depending on (in your deps folder) and also the dependencies internal to your own hive. This is an important source of information, we are working on it to make it more navigable and informative.

Processing the code
-------------------

The ``bii work`` command is a very basic command that performs the main processing of biicode for your current hive. It checks what files you have modified, analyzes and search dependencies among your hive files (i.e. locally), and fills the ``deps`` folder. Most times it is not necessary to invoke this command explicitly, because it is automatically called by development commands as ``cpp:run``, ``cpp:build`` or ``cpp:configure``.

.. code-block:: bash

	$ bii work

Cleaning meta-information
-------------------------

The ``bii clean`` command cleans most of biicode internal hive meta-information, keeping the strictly minimum required to reconstruct everything in a subsequent command. In theory, this command should not exist, but it is sometimes necessary, especially when new versions of biicode client are released that might have backwards incompatibilities.

.. code-block:: bash

	$ bii clean

.. _biipublish:

Publishing your code
--------------------

When you do a ``bii publish`` you are uploading the code of one of your current hive blocks to biicode servers. It means that such code is more or less ready to be reused, the level of the reuse can be defined by the ``tag``, which can be one of:

	* DEV: It means that the code you are publishing is ready to be reused by yourself (or maybe your dev team) in another projects or contexts.
	* ALPHA: The code is ready to be reused by some friends or colleagues you explicitly invite to test your code
	* BETA: The code could be used by anyone in the world willing to test others code
	* STABLE: Ready to be reused by anyone in the world. This is typically the tag you want to use for your usual dependencies, and it is the default in the find policies.

Every publish also has a publish message. It is somewhat similar to a commit message, it should be a short sentence summarizing the contents of the publication, what has been done. For example, you can develop a block called "geom" intended to code some geometric primitives. You develop the code for a sphere, and decide to publish it. Then your first publication could contain a message as "Sphere class basic functionality"

.. code-block:: bash

	$ bii publish

Publishing new versions of your code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
You can publish new versions of your code from the same hive you were working as you want. For each publication you can define its own tag and message. Nothing special has to be done. The picture is different if you published your block and you want to open the published version in a new hive. This can be currently done by creating a new empty hive, then doing a ``bii open`` of such block:

 .. code-block:: bash

	$ bii new mynewhive
	...
	$ cd mynewhive
	$ bii open myuser/myblock
	... (edit your block)
	$ bii publish

The name of the block has to include your user name. You can specify to open a different branch or different version number with optional arguments (--branch and --version), but this is not the usual flow. Furthermore, you can only publish a new version if you have opened the last one of the block, otherwise it can still be published but in other branch, which is a subject of advanced usage. You can also open a block of another user, but usually you will not have write permissions, so you could publish your modifications only in a different branch.


Hive usage
----------

A :ref:`hive<hive_definition>` provides you with a great advantage because of **you can move it to any PC and use it when you want**. You can compress it in a zip, save it, for example, in Dropbox, open it in other computer where you have a workspace and continue working.

**Note:** It's recommended to execute ``bii clean`` before moving the hive so that you delete all the cached junk and take up less space.

``CAUTION:`` Special attention if you are working in a same hive from different places because you could end up overwriting part of your code, if you have complex working flows we recommend using a VCS such as git or mercurial.

.. _bii_upload:

Uploading your hive
^^^^^^^^^^^^^^^^^^^

When you perform a ``bii upload`` you are uploading the hive with your current blocks to biicode servers. In this case, there are some differences with respect to the blocks published. 

* These hives are only visible by you. No one can access them.
* There aren't any tag or publish messages involved.
* You cannot reuse any blocks which are in this hive from other hives unless they are published. This means your unpublished blocks do not exist outside of the hive where they lay.


.. code-block:: bash

	$ bii upload


.. _bii_download:

Downloading your hive
^^^^^^^^^^^^^^^^^^^^^	
You can download any hive you have previously uploaded. You only need to know the hive name and enter execute this command in your workspace directory.

.. code-block:: bash
	
	$ cd my_workspace
	$ bii download --hive your_hive_name

``CAUTION:`` Remember the downloaded hive is a copy. If you make changes in your hive and upload them later, it will overwrite the oldest files in biicode servers.
	
.. _biifind:

Finding dependencies
--------------------

External dependencies of your hive are retrieved from biicode servers when found to your dep folders.
If you simply want to find missing dependencies, type:

.. code-block:: bash

	$ bii find

If you want to update already defined dependencies (as well as finding unresolved ones in the same step):

.. code-block:: bash

	$ bii find --update

Biicode uses user defined policies to resolve dependencies. The configuration file for configuring your policies for this is named "policies.bii" in your hive "bii" folder. Note that all find commands depend on the values configured in such file. You can for example try to update your dependencies, but if there are no compatible versions that match your policies, you will not get such updates. E.g. a new ALPHA version for one of your dependencies will not be updated if you do not change your policy.

If you want to find compatible downgrades:

.. code-block:: bash

	$ bii find --downgrade

These options can be combined:

.. code-block:: bash

	$ bii find --update --downgrade

If you want to find any possible matching compatible version (not just updates or downgrades from your current one), type:

.. code-block:: bash

	$ bii find --modify
