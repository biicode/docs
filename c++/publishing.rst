.. _cpp_publishing:

Publishing 
==========

:ref:`bii publish<bii_publish_command>` command publishes your code to biicode. 

.. code-block:: bash

  $ bii publish


Tag's default value is ``DEV``.

.. code-block:: bash

  $ bii publish  --tag STABLE

 ``STABLE`` versions are frozen after publication and ``DEV`` versions are overridden by a new version. Each time you publish to biicode your local ``[parent]`` value updates to the latest one you just published. 

 Let's understand this behavior with an example:

* Publish your first **DEV** version.

  Its ``[parent]`` section should be empty or with its first value like this:

    .. code-block:: text
      :emphasize-lines: 2

       [parent]
          user_name/block_name: -1

Once published, your ``[parent]`` updates to version ``0`` and that's also number ``0`` in biicode. 

* Publish a ``DEV`` version. That's still number ``0``.
* Publish a ``STABLE`` version. That's still number ``0``.
* Publish another ``STABLE`` version. That's number ``1`` in biicode.

.. _version_tags:

Tag a version
--------------

Put a semantic name to your block versions. Once tagged, you can :ref:`depend on a version just knowing its semantic tag<tag_dependencies>`. Just execute:

.. code-block:: bash

  $ bii publish  --tag STABLE --versiontag=1.2rc3


.. container:: infonote

    ``DEV`` versions can not be tagged.


Private blocks
--------------

Upgrade your account to Premium, |biicode_write_us|, to use Private blocks. Store your code in private, choose who can see or edit your blocks.

Create private blocks in our web page. Just press **Add block button** and choose private.


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>


