.. _git_integration:

VCS Git (GitHub, Bitbucket, etc.)
=================================

|github_homepage| and |bitbucket_homepage| are notorious Git (Bitbucket works with Mercurial too) repository web-based hosting service which offers the distributed revision control and source code management (SCM) functionality of Git as well as add their own features.

Biicode does not intend to be version control system. We recommend you using a control version system so you can keep your code safe and versioned. You can use also SVN or CVS.

In a new project
----------------

Just ``init`` the git repository in your block folder. As in the example:

.. code-block:: bash

	~$ bii init mygitproject
	~$ cd mygitproject/blocks
	~/mygitproject/blocks$ mkdir myusername
	~/mygitproject/blocks/myusername$ git clone your_repository
	~/mygitproject/blocks/myusername$ bii cpp:build

Versioning your code
^^^^^^^^^^^^^^^^^^^^

The natural way to work is maintaining a correspondence between a *biicode block* and a *Git repository*.
Just go to your block folder (**calc** and **math** if you followed the getting started) and initialize a new git repository.

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    |    |    +-- math
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h
  |    +-- deps

Go to the block's folder and initialize the git repository. Then add the changes to index and commit them:

.. code-block:: bash

  $ cd mycalc/blocks/myuser/calc
  $ git init .
  $ git add .
  $ git commit -m "Added new operation to operations.cpp"

You can also add a remote repository:

.. code-block:: bash

  $ git remote add origin https://github.com/user/repo.git

And push your commits: 

.. code-block:: bash

  $ git push origin master


.. container:: infonote
    
  You can learn more about adding remote repositories on |github_remote| or on |bitbucket_remote|. 


.. container:: infonote
    
  You can push to git the whole biicode project folder if you want to keep the building folder and project configuration. But, generally it's not necessary or recommended. Each computer may need their specific project settings, ant the you can regenerate all build layout with ``bii cpp:configure`` or ``bii cpp:build`` command. 

As usual, you can publish your code to biicode when you want to, generally when you have a version to share.

.. code-block:: bash

  $ bii publish

That's all! Now you have your code under version control.


Ignoring files
_______________

Maybe you want to have all files on git, but there are some files you don't want to publish to biicode.
Use :ref:`ignore.bii file<ignore_bii>` to specify which files should be ignored and not published to biicode.


Working with published blocks
-----------------------------

In previous sections, it's explained how to work with any published block just using biicode (you would run ``bii open`` command). 

Well, that's still available, but when working with Git, it's best to ``clone`` the github repository.

Let's see an example:

User ``mike`` has pushed to github and published a block named ``mike/math`` to biicode. 
He was working at home, with Linux.

Next day Mike wants to develop further his block at work, with Windows.
If Mike executes ``bii open`` the source code is not a github repository, is only a copy of his block in biicode. 
So Mike should better init a new biicode project and run:

.. code-block:: bash

  $ bii init work_project
  $ cd work_project
  $ bii new mike/math
  $ cd blocks/mike/math
  $ git clone https://github.com/mike_on_github/math.git .

Now Mike has the github repository to continue developing his biicode block under a control version system.
From now on, Mike just needs to make ``git pull`` command to fetch and merge the remote changes.

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
