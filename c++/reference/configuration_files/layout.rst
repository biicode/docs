.. _layout:

**layout.bii**: define your project layout 
==========================================

Specify your project layout config with ``layout.bii`` file.

With ``layout.bii`` you can place the auxiliary folders *(cmake/ build/ deps/ and lib/)*wherever you want, just specify the relative routes to the folders you want to use instead.

**bii init -l simple** creates a default ``layout.bii`` content that places all auxiliary folders in your project's *bii/* folder:

.. code-block:: text

    # Minimal layout, with all auxiliary folders inside "bii" and
    # The binary "bin" folder as is, and enabled code edition in the project root
    cmake: bii/cmake
    lib: bii/lib
    build: bii/build
    deps: bii/deps
    # Setting this to True enables directly editing in the project root
    # instead of blocks/youruser/yourblock
    # the block will be named as your project folder
    auto-root-block: True
    # Parent blockname (if exists)

But you can customize it anyway you want. 

Check our |biicode_forum_link| and/or |biicode_stackoverflow_link| for questions and answers. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |biicode_stackoverflow_link| raw:: html

   <a href="http://stackoverflow.com/questions/tagged/biicode" target="_blank">StackOverflow tag</a>