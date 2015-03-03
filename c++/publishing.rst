.. _cpp_publishing:

Publishing 
==========

:ref:`bii publish<bii_publish_command>` command publishes your code to biicode. 

.. code-block:: bash

  $ bii publish


Tag's default value is ``DEV``, but all Release life-cycle TAG values are available: ``DEV``, ``ALPHA``, ``BETA`` and ``STABLE``:

.. code-block:: bash

  $ bii publish  --tag STABLE

 
``ALPHA``, ``BETA`` and ``STABLE`` versions, are frozen after publication to achieve full reproducibility. ``DEV`` versions are overridden by a new version on any tag. Let's understand its behavior with an example:

* Publish a ``DEV`` version. That's number ``0``.
* Publish a ``DEV`` version. That's still number ``0``.
* Publish a ``BETA`` version. That overwrites number ``0``.
* Publish a ``DEV`` version. That's number ``1``.
* Publish a ``ALPHA`` version. That overwrites number ``1``.
* Publish a ``STABLE`` version. That's number ``2``.

.. _version_tags:

Tag a version
--------------

Put a semantic name to your block versions. Once tagged, you can :ref:`depend on a version just knowing its semantic tag<tag_dependencies>`. Just execute:

.. code-block:: bash

  $ bii publish  --tag STABLE --versiontag=1.2rc3


.. container:: infonote

    ``DEV`` versions can not be tagged.

.. _git_commit:

Publish from git commit
-----------------------

``bii publish -r`` or ``bii publish --remote`` uses the git info within your block to publish it to biicode along with your block. This way everyone knows "who is" the git repo mantaining the biicode block and the specific commit creating each block version.


.. code-block:: bash

  $ bii publish  -r

This is how publishing with ``bii publish --remote`` looks like:

.. image:: /_static/img/c++/bii_publish_remote.png


.. container:: infonote

    You can mix ``bii publish`` parameters, for example: ``bii publish -r --tag STABLE --versiontag v1.0.2``




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

Now you have configured a track of your block.

In case you need a personalized fix over the original library from other user, just indicate it in the ``[parent]`` section like this:

*biicode.conf*

.. code-block:: text

	[parent]
  		lasote/libuv(myuser/track1): -1

This way, you have configured a track of other user whitout changing *includes*.

Execute ``bii publish`` and enter your profile *www.biicode.com/myuser* to check the new track. 

Read a bit more about how *tracks* work, visit our post in the blog about |biicode_blog_blocktracks|.

Private blocks
--------------

Upgrade your account to Premium, |biicode_write_us|, to use Private blocks. Store your code in private, choose who can see or edit your blocks.

Create private blocks in our web page. Just press **Add block button** and choose private.


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

.. |biicode_blog_blocktracks| raw:: html

   <a href="http://blog.biicode.com/new-feature-block-tracks/" target="_blank">block traks</a>

