.. _integration:

Integrations
============

Biicode is easy to integrate with other technologies and tools. We're already working with the services below:

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


Travis CI
---------

|travis_homepage| takes care of running your tests and deploying your apps. Like we work with VCS, many of the blocks published in our web have their ``.travis.yml`` files, that it lets us to make a push to our GitHub repository, and automatically build, execute and publish this project with your biicode user account thanks to this excellent service.

If you're working with it, the ``.travis.yml`` file format will help you to get automatic publications in your biicode account, in this case, with DEV tag: ::

   language: cpp
   compiler:
   - gcc
   before_install:
   - sudo apt-get update -qq
   install:
   - wget http://www.biicode.com/downloads/latest/ubuntu64
   - mv ubuntu64 bii-ubuntu64.deb
   - (sudo dpkg -i bii-ubuntu64.deb) && sudo apt-get -f install
   - rm bii-ubuntu64.deb
   - wget https://s3.amazonaws.com/biibinaries/thirdparty/cmake-3.0.2-Linux-64.tar.gz
   - tar -xzf cmake-3.0.2-Linux-64.tar.gz
   - sudo cp -fR cmake-3.0.2-Linux-64/* /usr
   - rm -rf cmake-3.0.2-Linux-64
   - rm cmake-3.0.2-Linux-64.tar.gz
   script:
   - cmake --version
   - bii init biicode_project
   - mkdir -p ./biicode_project/blocks/myusername/myblockname
   - mv !(biicode_project) ./biicode_project/blocks/myusername/myblockname
   - cd biicode_project
   - bii find -um
   - bii cpp:build
   - cd bin
   - ./myusername_myblockname_main
   after_success:
   - bii user myuser -p $BII_MYUSER_PASSWORD
   - bii publish
   env:
     global:
       secure: MY_GENERATED_KEY_PASSWORD

To learn more about Travis using C++ language, visit its `documentation <http://docs.travis-ci.com/user/languages/cpp/>`_.

.. container:: infonote

   Here's how to `automatically build and publish via Travis CI and Github  <http://blog.biicode.com/automatically-build-publish-via-travis-ci-github/>`_.


Koding
------

|koding_homepage| gives you the necessary environment to start developing your apps, run them, collaborate and share with the world. This amazing development tool helps you to work with a great environment everywhere, without installing or executing difficult commands, you've already all the necessary prepared in your Koding account.

If you're signed here and you wish to use biicode in your VMs, then execute:

.. code-block:: bash

	~$ wget http://apt.biicode.com/install.sh && chmod +x install.sh && ./install.sh
	~$ bii -h

Then, you'd ready to start using biicode and building all the projects you wish.


.. |github_homepage| raw:: html

   <a href="https://github.com/" target="_blank">GitHub</a>

.. |bitbucket_homepage| raw:: html

   <a href="https://bitbucket.org/" target="_blank">Bitbucket</a>

.. |travis_homepage| raw:: html

   <a href="https://travis-ci.com/" target="_blank">Travis CI</a>

.. |koding_homepage| raw:: html

   <a href="https://koding.com/Home" target="_blank">Koding</a>



**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_
