.. _cpp_publishing:

Publishing 
==========

:ref:`bii publish<bii_publish_command>` command, publishes your code to biicode. 

.. code-block:: bash

  $ bii publish


Tag's default value is ``DEV``, but all Release life-cycle TAG values are available: ``DEV``, ``ALPHA``, ``BETA`` and ``STABLE``:
.. code-block:: bash

  $ bii publish  --tag STABLE

 
``ALPHA``, ``BETA`` and ``STABLE`` versions, are frozen after publication to achieve full reproducibility. ``DEV`` versions are overridden by a new version on any tag. Let's understand its behavior with an example:

* Publish a ``DEV`` version. That's number ``0``.
* Publish a ``DEV`` version. That's still number ``0``.
* Publish a ``BETA`` version. That's number ``1``.
* Publish a ``DEV`` version. That's number ``2``.
* Publish a ``ALPHA`` version. That's number ``2``.
* Publish a ``STABLE`` version. That's number ``3``.


Tag a version
--------------

Put a semantic name to your block versions. Once tagged, you can :ref:`depend on a version just knowing its tagd<tag_dependencies>`. Just execute:

.. code-block:: bash

  $ bii publish  --tag STABLE --versiontag=1.2rc3


.. container:: infonote

    ``DEV`` versions can not be tagged.

Block Tracks
-------------

Use **Block Tracks** to publish different development *versions* of a block using the same block name-space. This way, dependent blocks can keep the same *#includes* in their source code.


Publish a new block Track
^^^^^^^^^^^^^^^^^^^^^^^^^^

Write the track name between brackets in the ``[parent]`` section of the **biicode.conf** file. Specify ``version -1`` because we want create a new block. 

*biicode.conf*

.. code-block:: text

	[parent]
  		myuser/myblock(track1): -1

with a real example:

*biicode.conf*

.. code-block:: text

	[parent]
  		lasote/libuv(v1.0): -1

Execute ``bii publish`` and enter your profile *www.biicode.com/myuser* to check the new track. 

Private blocks
--------------

Upgrade your account to Premium, |biicode_write_us|, to use Private blocks. Store your code in private, choose who can see or edit your blocks.

Create private blocks in our web page. Just press **Add block button** and choose private.


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

