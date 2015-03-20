.. _cpp_blocks:

What is a block?
----------------

**A block** (also known as 'repo' or 'repository') is the place to put your code in biicode. 

Each block has an *owner, name, version* and *tag*. For example, the |openssl_link| block has an **owner** (lasote) and latest version is **3 DEV**.

Here's an example block structure:

.. code-block:: text

  +-- block_name/
  |   +-- src/
  |   |   +-- main.cpp
  |   +-- test/
  |   |   +-- test1.cpp 
  |   +-- biicode.conf
  |   +-- CMakeLists.txt
  |   +-- README

These are the main components of a block (under the ``block_name/`` directory):

  - Your repo's code, with its sources and folders.
  - ``CMakeLists.txt`` file, to specify your build config.
  - ``biicode.conf`` file with information about your block and its dependencies.
  - a README 

* :ref:`More information on the biicode.conf file<biicode_conf>`

* :ref:`Building Configuration your own Block <cpp_building>`

Block's web view
^^^^^^^^^^^^^^^^

As you know, a block is where you place your code in biicode. Blocks available in the web are the ones you can depend on.

Take a look at blocks in a `profile main page <https://www.biicode.com/examples>`_:

.. image:: /_static/img/c++/profile_view.png

As you see, blocks are organized in the web as ``owner/block_name`` too.

You can create a public or private block in the web by clicking on "Create block" and add directly a description.

.. image:: /_static/img/c++/create_block.png

Start working with the block you just created, type in your project folder:

.. code-block:: bash
 
  $ bii open owner/block_name

In the block's view you see the code, structure and information:

.. image:: /_static/img/c++/block_view.png

In the header you see:

  * **Block's name**
  * :ref:`Version<cpp_publishing>`
  * **Last time published**
  * **Description**: A brief description of the block. For longer description it's recommended to add a README file.
  * **Tags**: topics your block is related to.
  * **Settings**: Edit your block's settings by giving a description or tagging the block.

Below the header there are some tabs showing:

.. container:: tabs-section
    
    .. _block_web_tabs_code:
    .. container:: tabs-item

        .. rst-class:: tabs-title
            
            Code Browser

        This is the default view.
        You have the structure of your project and you can check the code or the files inside directories, as well as download all the block in a ZIP file.

    .. _block_web_tabs_requirements:
    .. container:: tabs-item

        .. rst-class:: tabs-title
            
            Block requirements

        This section shows blocks and versions your block depends on. You can view here the reuses of your block too.

        .. image:: /_static/img/c++/block_requirements.png

    .. _block_web_tabs_dependencies:
    .. container:: tabs-item

        .. rst-class:: tabs-title

           Block dependencies

        Block's dependencies of all kind: system, resolved and unresolved ones.

        .. image:: /_static/img/c++/block_dependencies.png

    .. _block_web_tabs_graph:
    .. container:: tabs-item

        .. rst-class:: tabs-title

            Dependencies graph

        Visual representation of block's dependencies.

        .. image:: /_static/img/c++/dependency_graph.png

Block Tracks
-------------

Use **Block Tracks** to publish different development *versions* of a block using the same block name-space. This way, dependent blocks can keep the same *#includes* in their source code.


Publish a new block Track
^^^^^^^^^^^^^^^^^^^^^^^^^^

Write the track name between brackets in the ``[parent]`` section of the **biicode.conf** file. Specify ``version -1`` because we want create a new block. 

.. code-block:: text

  [parent]
      myuser/myblock(track1): -1

Now you have configured a track of your block.

In case you need a personalized fix over the original library from other user, just indicate it in the ``[parent]`` section like this:

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


