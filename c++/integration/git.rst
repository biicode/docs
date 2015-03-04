.. _git_integration:

VCS Git (GitHub, Bitbucket, etc.)
=================================

|github_homepage| and |bitbucket_homepage| are notorious Git (Bitbucket works with Mercurial too) repository web-based hosting service which offers the distributed revision control and source code management (SCM) functionality of Git as well as add their own features.

Biicode does not intend to be version control system. We recommend you using a control version system so you can keep your code safe and versioned. You can use also SVN or CVS.

With a new project
------------------

Just ``init`` the git repository in your block folder. As in the example:

.. code-block:: bash

  $ bii init project
  $ cd myproject 
  $ bii new myuser/myblock
  $ cd blocks/myuser/myblock
  $ git init .
  $ git add .
  $ git commit -m "my very first commit"

You can also add a remote repository:

.. code-block:: bash

  $ git remote add origin https://github.com/user/repo.git

With an existing git repo
--------------------------

With the usual project layout:

.. code-block:: bash

	~$ bii init mygitproject
	~$ cd mygitproject/blocks
	~/mygitproject/blocks$ mkdir myusername
	~/mygitproject/blocks/myusername$ git clone https://Your_Repo_URL.git
	~/mygitproject/blocks/myusername$ bii cpp:build

Using the simple layout custom_layout feature:

.. code-block:: bash

  ~$ git clone https://Your_Repo_URL.git
  ~$ cd your_repository
  ~/your_repository$ bii init -l simple

.. container:: infonote

    Here's a guide about :ref:`Creating a biicode block from a git repo <cpp_block_git>`
    and there's also a :ref:`git workflow guide<git_workflows>` 

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
