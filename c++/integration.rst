.. _integration:

Integrations
============

Biicode integrates with other technologies and tools. We're already working with the services below:


.. toctree::
   :maxdepth: 2

   ides

.. _git_integration:

VCS Git (GitHub, Bitbucket, etc.)
---------------------------------

|github_homepage| and |bitbucket_homepage| are notorious Git (Bitbucket works with Mercurial too) repository web-based hosting service which offer the distributed revision control and source code management (SCM) functionality of Git as well as add their own features.

Biicode has some commands similar to VCS management but we recommend greatly to work with Git and host in any web you want. GitHub and Bitbucket work brilliantly and you can work painless with your repositories and building your project with biicode to reuse or share later. You only have to ``init`` your repository into your block folder. As in the example:

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
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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
From now, Mike just needs to make ``git pull`` command to fetch and merge the remote changes.



Continuous Integration
----------------------

.. _appveyor_integration:

AppVeyor
^^^^^^^^

|appveyor_homepage| provides Continuous Integration and Deploy for Windows and it's compatible with both GitHub and BitBucket. Place an ``appveyor.ymĺ`` file in your repo and each time you push to your Github repository it will kick-off a new build in Windows, executing your tests and publishing this project to your biicode user account. 

Login AppVeyor and clic on ``+ NEW PROJECT`` and choose the repo you want to deploy with AppVeyor. Create an ``appveyor.yml`` file in your local project to automatically publish your block to biicode, including your version tags, here's an example file:


.. literalinclude:: /_static/code/cpp/integration/appveyor.yml
   :language: text

Use your own ``test_script`` and ``environment`` values to start deploying with it.

Here's an appveyor guide about how to |appveyor_git_push|. Following this Appveyor Guide we're using it as credentials with Git commands. Use this GitHub guide to create your |github_access_token|.

Encrypt your biicode password and your access token using |appveyor_encrypt_data|, copy the values generated and put them it in your  environment like ``secured_password: secure:``.

What's going on the ``appveyor.yml`` file?

   * ``install:`` This part installs all tools required to deploy your biicode projects in AppVeyor.
   * ``before_build:`` Moves your project's files into the biicode project and configures it to use Visual Studio 12 via ``bii cpp:configure``.  Check biicode docs and  your project's settings in Appveyor to use other build configurations. **Also note** that there's a commented line here you should also write if your project contains folders.
   * ``test_script:`` cd bin and execute your project. Ensure about your project's executable, build and execute it locally with  ``bii cpp:build``.
   * ``deploy_script:`` This script publishes your block to biicode, including your version tag only when it's tagged.
   * ``on_success:`` If your biicode.conf file is updated commit its changes to github without launching a new build. Else do nothing.
   * ``environment:`` Replace all environment variables here with your values: project_name, tag, default version tag value... Also your encrypted variables.

You can see this live example here:

* |github_appveyor_parser| in GitHub
* |appveyor_build_parser| in AppVeyor
* |biicode_block_parser| with its automatically published releases

Learn more about AppVeyor visiting their `docs <http://www.appveyor.com/docs>`_.

.. _travis_integration:

Travis CI
^^^^^^^^^

|travis_homepage| takes care of running your tests and deploying your apps. Like we work with VCS, many of the blocks published in our web have their ``.travis.yml`` files, that lets us pushing to our GitHub repository, and automatically build in Linux, execute and publish this project with your biicode user account thanks to this excellent service.

If you're working with it, the ``.travis.yml`` file format will help to automatically publish to your biicode account with DEV tag unless your github repo is tagged, in this case, imports the tag and publishes as STABLE to biicode.


.. literalinclude:: /_static/code/cpp/integration/travis.yml
   :language: text

What's going on the ``.travis.yml`` file?

    * ``language and compiler`` are totally clear (this is where you choose the language and compiler that Travis CI will use).
    * ``before_installing``, stablishes our automatic commit must be ignored and configures git to push later, on the after_success part.
    * ``install`` provides the tools necessary to test our code with BIICODE.
    * ``script``, creates, builds and runs the project and checks if the project successes.
    * ``after_success`` part is to publish your project to biicode as STABLE with VERSION_TAG if tagged in github, otherwise it publishes as DEV. Also, if your biicode.conf file is updated, this commits its changes to github without launching a new build.
    * ``env:`` replace all environment values with your own ones. Don’t delete the ***travis*** text, as it is the one needed to specify that commit should skip build, avoiding entering an endless build loop.


To learn more about Travis using C++ language, visit its `documentation <http://docs.travis-ci.com/user/languages/cpp/>`_.


.. container:: infonote

   Here's how to `automatically build and publish via Travis CI and Github  <http://blog.biicode.com/automatically-build-publish-via-travis-ci-github/>`_. You can also `deploy directly with biicode <http://docs.travis-ci.com/user/deployment/biicode/>`_. 


Koding
------

|koding_homepage| gives you the necessary environment to start developing your apps, run them, collaborate and share with the world. This amazing development tool helps you to work with a great environment everywhere, without installing or executing difficult commands, you've already all the necessary prepared in your Koding account.

If you're signed here and you wish to use biicode in your VMs, then execute:

.. code-block:: bash

	~$ wget http://apt.biicode.com/install.sh && chmod +x install.sh && ./install.sh
	~$ bii -h

Then, you'd ready to start using biicode and building all the projects you wish.

Doxygen
-------

|doxygen_homepage| is the standard tool for generating documentation from annotated C++ sources. You can download it from its |doxygen_downloads|.

   * It can generate an on-line documentation browser (in HTML) and/or an off-line reference manual (in LaTeX) from a set of documented source files. There is also support for generating output in RTF (MS-Word), PostScript, hyperlinked PDF, compressed HTML, and Unix man pages. The documentation is extracted directly from the sources, which makes it much easier to keep the documentation consistent with the source code.

   * You can configure doxygen to extract the code structure from undocumented source files. This is very useful to quickly find your way in large source distributions. Doxygen can also visualize the relations between the various elements by means of include dependency graphs, inheritance diagrams, and collaboration diagrams, which are all generated automatically.

Create a Doxyfile template
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    ~$ cd /blocks/[USER]/[BLOCK]
    ~/blocks/[USER]/[BLOCK]$ mkdir docs
    ~/blocks/[USER]/[BLOCK]$ cd docs
    ~/blocks/[USER]/[BLOCK]/docs$ doxygen -g

Edit your Doxyfile
^^^^^^^^^^^^^^^^^^

The minimal info that you need to change in your Doxyfile is the following tags: ::

    PROJECT_NAME           = "My Project"

    OUTPUT_DIRECTORY       = .

    INPUT                  = ../

    FILE_PATTERNS          = *.c \
                             *.cc \
                             *.cxx \
                             *.cpp \
                             *.c++ \
                             *.h \
                             *.hh \
                             *.hxx \
                             *.hpp \
                             *.h++ \

Generate the Documentation
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    ~/docs$ doxygen Doxyfile

    #Open the /docs/html/index.html with your web browser.

.. container:: infonote

   All the info of the previous examples have been written taking as reference a ``docs`` folder inside your ``block``.

   However, you can create your Doxyfile where you want changing the INPUT tag in your Doxyfile.

   For example, to generate the docs folder in you ``project``, you need to specify: ``INPUT = ../blocks/[USER]/[BLOCK_NAME]/``.

   Read more info about doxygen in the `official documentation. <http://www.stack.nl/~dimitri/doxygen/manual/index.html>`_

If you want to make your own main page, you can create a ``DoxygenMainpage.h`` in the docs folder with the following sections: ::

    /**
    @mainpage  TITLE_OF_YOUR_HOME_PAGE
    
    @author YOUR_USER_NAME and all the info about the author

    Description of you block

    @section TITLE

    Section info
    */

A good example is |doxygen_doxygenmainpage|:

.. image:: ../_static/img/c++/doxygen.png


.. literalinclude:: /_static/code/cpp/integration/doxyfile.cpp
   :language: cpp
   :emphasize-lines: 2,3,9,17,30


.. |doxygen_homepage| raw:: html

   <a href="http://www.stack.nl/~dimitri/doxygen/" target="_blank">Doxygen</a>

.. |doxygen_downloads| raw:: html

   <a href="http://www.stack.nl/~dimitri/doxygen/download.html" target="_blank">downloads page</a>

.. |doxygen_doxygenmainpage| raw:: html

   <a href="https://www.biicode.com/david/david/libfreenect/master/0/doc/DoxygenMainpage.h" target="_blank">libfreenect/doc/DoxygenMainpage.h</a>

.. |appveyor_homepage| raw:: html

   <a href="https://ci.appveyor.com/" target="_blank">AppVeyor</a>

.. |github_homepage| raw:: html

   <a href="https://github.com/" target="_blank">GitHub</a>

.. |bitbucket_homepage| raw:: html

   <a href="https://bitbucket.org/" target="_blank">Bitbucket</a>

.. |travis_homepage| raw:: html

   <a href="https://travis-ci.com/" target="_blank">Travis CI</a>

.. |koding_homepage| raw:: html

   <a href="https://koding.com/Home" target="_blank">Koding</a>

.. |github_appveyor_parser| raw:: html
   
   <a href="https://github.com/MariadeAnton/cpp-expression-parser" target="_blank">Forked cpp-expresion-parser repo</a>

.. |github_access_token| raw:: html
   
   <a title="github personal access token" href="https://help.github.com/articles/creating-an-access-token-for-command-line-use/" target="_blank">GitHub Personal Access Token</a>

.. |appveyor_build_parser| raw:: html

   <a title="appveyor build cpp-expression-parser" href="https://ci.appveyor.com/project/MariadeAnton/cpp-expression-parser" target="_blank">cpp-expression-parser builds</a>

.. |appveyor_encrypt_data| raw:: html

   <a title="appveyor encrypt data tool" href="https://ci.appveyor.com/tools/encrypt" target="_blank">Encrypt Data tool</a>


.. |appveyor_git_push| raw:: html

   <a title="appveyor git push from build" href="http://http://www.appveyor.com/docs/how-to/git-push" target="_blank">Git push from Appveyor Build</a>
   

.. |biicode_block_parser| raw:: html

   <a href="http://www.biicode.com/amalulla/cpp-expression-parser" target="_blank">cpp-expression parser biicode block</a> 

.. |github_remote| raw:: html
    
    <a href="https://help.github.com/articles/adding-a-remote/" target="_blank">github here</a>


.. |bitbucket_remote| raw:: html
    
    <a href="https://confluence.atlassian.com/display/BITBUCKET/Create+a+repository" target="_blank">bitbucket here</a>


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_
