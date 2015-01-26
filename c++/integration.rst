.. _integration:

Integrations
============

Biicode integrates with other technologies and tools. We're already working with the services below:

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

AppVeyor
---------

|appveyor_homepage| provides Continuous Integration and Deploy for Windows and it's compatible with both GitHub and BitBucket. Place an ``appveyor.ymĺ`` file in your repo and each time you push to your Github repository it will kick-off a new build in Windows, executing your tests and publishing this project to your biicode user account. 

Here's an ``appveyor.yml`` example file to automatically publish your block to biicode, including your version tags: ::

   version: 1.0.{build}

   install:
     - ps: wget https://s3.amazonaws.com/biibinaries/thirdparty/cmake-3.0.2-win32-x86.zip -OutFile cmake.zip
     - cmd: echo "Unzipping cmake..."
     - cmd: 7z x cmake.zip -o"C:\Program Files (x86)\" -y > nul
     - cmd: set PATH=%PATH:CMake 2.8\bin=%;C:\Program Files (x86)\cmake-3.0.2-win32-x86\bin
     - cmd: cmake --version
     - cmd: echo "Downloading biicode..."
     - ps: wget http://www.biicode.com/downloads/latest/win -OutFile bii-win.exe
     - cmd: bii-win.exe /VERYSILENT
     - cmd: set PATH=%PATH%;C:\Program Files (x86)\BiiCode\bii
     - cmd: bii -v
     - cmd: del bii-win.exe
     - cmd: del cmake.zip

   before_build:
     - cmd: bii init %project_name%
     - cmd: cd %project_name%
     - cmd: bii new %block_user%/%block_name%
       # move the files
     - cmd: for %%i in (../*) do if %%i NEQ "%project_name%" move "..\%%i" blocks\%block_user%\%block_name%\
     # move the directories -> there are none in this repo:
     # cmd: for /d %%i in (../*) do if %%i NEQ "%project_name%" move "..\%%i" blocks\%block_user%\%block_name%\
     - cmd: bii cpp:configure -G "Visual Studio 12"

   build_script:
     - cmd: bii cpp:build

   test_script:
     - cmd: cd bin
     - cmd: amalulla_cpp-expression-parser_test-shunting-yard.exe

   # to run your custom scripts instead of provider deployments
   deploy_script:
     - if defined APPVEYOR_REPO_TAG_NAME set VERSION=%APPVEYOR_REPO_TAG_NAME%
     - echo "Building tagged release %VERSION%"
     - if not defined APPVEYOR_REPO_TAG_NAME set VERSION=%no_version%
     - cmd: bii user %block_user% -p %secured_passwd%
     - cmd: bii publish --tag=%tag% --versiontag=%VERSION% #|| dir # Ignore output

   environment:
     project_name:
       "myproject"
     block_user:
       "amalulla"
     block_name:
       "cpp-expression-parser"
     secured_passwd:
       secure: ZMvgETfLAUo7kISnvrinBA==
     tag:
       "STABLE"
     no_version:
       ""

Just use your own ``test_script`` and ``environment`` values to start using it. You can see this live example here:

* |github_appveyor_parser| in GitHub
* |appveyor_build_parser| in AppVeyor
* |biicode_block_parser| with its automatically published releases

Learn more about AppVeyor visiting their `docs <http://www.appveyor.com/docs>`_.

Travis CI
---------

|travis_homepage| takes care of running your tests and deploying your apps. Like we work with VCS, many of the blocks published in our web have their ``.travis.yml`` files, that lets us pushing to our GitHub repository, and automatically build in Linux, execute and publish this project with your biicode user account thanks to this excellent service.

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

   Here's how to `automatically build and publish via Travis CI and Github  <http://blog.biicode.com/automatically-build-publish-via-travis-ci-github/>`_. You can also `deploy directly with biicode <http://docs.travis-ci.com/user/deployment/biicode/>`_. 


Koding
------

|koding_homepage| gives you the necessary environment to start developing your apps, run them, collaborate and share with the world. This amazing development tool helps you to work with a great environment everywhere, without installing or executing difficult commands, you've already all the necessary prepared in your Koding account.

If you're signed here and you wish to use biicode in your VMs, then execute:

.. code-block:: bash

	~$ wget http://apt.biicode.com/install.sh && chmod +x install.sh && ./install.sh
	~$ bii -h

Then, you'd ready to start using biicode and building all the projects you wish.

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

.. |appveyor_build_parser| raw:: html

   <a title="appveyor build cpp-expression-parser" href="https://ci.appveyor.com/project/MariadeAnton/cpp-expression-parser" target="_blank">cpp-expression-parser builds</a>

.. |biicode_block_parser| raw:: html

   <a href="http://www.biicode.com/amalulla/cpp-expression-parser" target="_blank">cpp-expression parser biicode block</a> 


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_
