.. _biipublish:

Publishing your code
====================

When you do a ``bii publish`` you are uploading the code of one of your current hive blocks to biicode servers. It means that such code is more or less ready to be reused, the level of the reuse can be defined by the ``tag``, which can be one of:

	* DEV: It means that the code you are publishing is ready to be reused by yourself (or maybe your dev team) in another projects or contexts.
	* ALPHA: The code is ready to be reused by some friends or colleagues you explicitly invite to test your code
	* BETA: The code could be used by anyone in the world willing to test others code
	* STABLE: Ready to be reused by anyone in the world. This is typically the tag you want to use for your usual dependencies, and it is the default in the find policies.

Every publish also has a publish message. It is somewhat similar to a commit message, it should be a short sentence summarizing the contents of the publication, what has been done. For example, you can develop a block called "geom" intended to code some geometric primitives. You develop the code for a sphere, and decide to publish it. Then your first publication could contain a message as "Sphere class basic functionality"

.. code-block:: bash

	$ bii publish

Publishing new versions of your code
------------------------------------
You can publish new versions of your code from the same hive you were working as you want. For each publication you can define its own tag and message. Nothing special has to be done. The picture is different if you published your block and you want to open the published version in a new hive. This can be currently done by creating a new empty hive, then doing a ``bii open`` of such block:

 .. code-block:: bash

	$ bii new mynewhive
	...
	$ cd mynewhive
	$ bii open myuser/myblock
	... (edit your block)
	$ bii publish

The name of the block has to include your user name. You can specify to open a different branch or different version number with optional arguments (--branch and --version), but this is not the usual flow. Furthermore, you can only publish a new version if you have opened the last one of the block, otherwise it can still be published but in other branch, which is a subject of advanced usage. You can also open a block of another user, but usually you will not have write permissions, so you could publish your modifications only in a different branch.

