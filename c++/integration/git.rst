.. _git_integration:

Git (GitHub, Bitbucket, etc.)
=================================

|github_homepage| and |bitbucket_homepage| are notorious Git (Bitbucket works with Mercurial too) repository web-based hosting service which offers the distributed revision control and source code management (SCM) functionality of Git as well as add their own features.

Biicode does not intend to be version control system. We recommend you using a control version system so you can keep your code safe and versioned. You can use also SVN or CVS.

With a new repository
---------------------

Just ``init`` the git repository in your block folder. As in the example:

.. code-block:: bash

  $ bii init my_block -L
  $ cd my_block
  $ git init .
  $ git add .
  $ git commit -m "my very first commit"

You can also add a remote repository:

.. code-block:: bash

  $ git remote add origin https://github.com/user/repo.git

.. _cpp_block_git:

Create a block from a git repository
------------------------------------

The code
^^^^^^^^

Put your code into a biicode block, as usual:

.. code-block:: bash

  ~$ git clone https://Your_Repo_URL.git
  ~$ cd your_repository
  ~/your_repository$ bii init -L

And follow this :ref:`guide to adapt your library to biicode <adapt_library>`.

biicode status badge
^^^^^^^^^^^^^^^^^^^^

The biicode satus badge is a dynamically generated image displaying your block's latest published :ref:`version<cpp_publishing>` in biicode.

.. image:: /_static/img/c++/biicode_badge.png

This badge lets developers know your code is available to reuse at biicode. It is something determinant in the use of a dependency manager and you can place it in the *readme files* of your :ref:`VCS repository <git_integration>` and in the biicode block.

.. container:: infonote

 Get your badge in your block's **settings**.

Let people know your code can be reused easily!

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


Check our |biicode_forum_link| and/or |biicode_stackoverflow_link| for questions and answers. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |biicode_stackoverflow_link| raw:: html

   <a href="http://stackoverflow.com/questions/tagged/biicode" target="_blank">StackOverflow tag</a>

.. |github_homepage| raw:: html

   <a href="https://github.com/" target="_blank">GitHub</a>

.. |bitbucket_homepage| raw:: html

   <a href="https://bitbucket.org/" target="_blank">Bitbucket</a>

.. |github_remote| raw:: html
    
    <a href="https://help.github.com/articles/adding-a-remote/" target="_blank">github here</a>

.. |bitbucket_remote| raw:: html
    
    <a href="https://confluence.atlassian.com/display/BITBUCKET/Create+a+repository" target="_blank">bitbucket here</a>
