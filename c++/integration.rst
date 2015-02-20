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

.. _appveyor_integration:

AppVeyor
---------

|appveyor_homepage| provides Continuous Integration and Deploy for Windows and it's compatible with both GitHub and BitBucket. Place an ``appveyor.ymĺ`` file in your repo and each time you push to your Github repository it will kick-off a new build in Windows, executing your tests and publishing this project to your biicode user account. 

Login AppVeyor and clic on ``+ NEW PROJECT`` and choose the repo you want to deploy with AppVeyor. Create an ``appveyor.yml`` file in your local project to automatically publish your block to biicode, including your version tags, here's an example file: ::

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
      - cmd: cd \
      - cmd: bii init %project_name%
      - cmd: cd %project_name%
      - cmd: bii new %block_user%/%block_name%
        # copy files and folders
      - cmd: xcopy "%APPVEYOR_BUILD_FOLDER%" blocks\%block_user%\%block_name%\ /e
      - cmd: bii cpp:configure -G "Visual Studio 12"

    build_script:
      - cmd: bii cpp:build

    test_script:
      - cmd: cd bin
      - cmd: amalulla_cpp-expression-parser_test-shunting-yard.exe
    
    deploy_script:
      - cmd: bii user %block_user% -p %secured_passwd%
      - if defined APPVEYOR_REPO_TAG_NAME set VERSION=%APPVEYOR_REPO_TAG_NAME%  
      - if defined APPVEYOR_REPO_TAG_NAME bii publish --tag=%tag% --versiontag=%VERSION% 
      - if not defined APPVEYOR_REPO_TAG_NAME bii publish --tag=%dev_tag% 

    on_success:
      - cmd: cd /%project_name%/blocks/%block_user%/%block_name%
      - ps: |    
            $new_biiconf = get-content biicode.conf
            $orig_biiconf = get-content "$env:APPVEYOR_BUILD_FOLDER\biicode.conf"     
            if (diff $new_biiconf $orig_biiconf){
               'different, updating biicode parents'
               git checkout "$env:APPVEYOR_REPO_BRANCH"
               git config --global core.autocrlf true
               git config --global credential.helper store 
               Add-Content "$env:USERPROFILE\.git-credentials" "https://$($env:access_token):x-oauth-basic@github.com`n"
               git remote add neworigin "$env:github_repo"
               git config --global user.email "$env:github_email"
               git config --global user.name "$env:github_user"
               git add biicode.conf
               git commit -m "Updated biicode parents [skip ci]"
               git push neworigin "$env:APPVEYOR_REPO_BRANCH"
               }Write-Host "Updated biicode parents" else {
                'equal, no parents update needed'
              }

    environment:
      project_name:
        "myproject"
      block_user:
        "amalulla"
      block_name:
        "cpp-expression-parser"
      secured_passwd:
        secure: ZMvgETfLAUo7kISnvrinBA==
      access_token:
        secure: GdIDIRkmsM9blqS143lQErkxguMYgJBs74GzWw+lgzjvl/NoLs4ErcOZ2JBAEmkr
      tag:
        "STABLE"
      dev_tag:
        "DEV"
      github_user:
        "MariadeAnton"
      github_email:
        "maria.deanton@biicode.com"
      github_repo:
        "git@github.com:MariadeAnton/cpp-expression-parser.git"

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


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_
