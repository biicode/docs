.. _cpp_blocks:

Publish a block track
=====================

Each block has an *owner, name, version* and *tag*. For example, the |openssl_link| block has an **owner** (lasote) and latest version is **4 DEV**.

Use **Block Tracks** to publish different development *versions* of a block using the same block name-space. This way, dependent blocks can keep the same *#includes* in their source code.



Publish a new block Track
--------------------------

Write the track name between brackets in the ``[parent]`` section of the *biicode.conf* file. Specify ``version -1`` because we want create a new block. 

.. code-block:: text

  [parent]
      myuser/myblock(track1): -1

Now you have configured a track of your block.

In case you need a personalized fix over the original library from other user, just indicate it in the ``[parent]`` section like this:

.. code-block:: text

  [parent]
      lasote/libuv(myuser/track1): -1

This way, you have configured a track of other user whitout changing *includes*.

Execute **bii publish** and enter your profile *www.biicode.com/myuser* to check the new track. 

Read a bit more about how *tracks* work, visit our post in the blog about |biicode_blog_blocktracks|.

Private blocks
==============

Upgrade your account to Premium, |biicode_write_us|, to use Private blocks. Store your code in private, choose who can see or edit your blocks.

Create private blocks in our web page. Just press **Add block button** and choose private.


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |biicode_blog_blocktracks| raw:: html

   <a href="http://blog.biicode.com/new-feature-block-tracks/" target="_blank">block traks</a>

.. |openssl_link| raw:: html
  
   <a href="http://www.biicode.com/lasote/openssl" target="_blank">OpenSSL block</a>
