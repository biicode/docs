Continuous Integration
----------------------

.. _appveyor_integration:

AppVeyor
^^^^^^^^

|appveyor_homepage| provides Continuous Integration and Deploy for Windows and it is compatible with both |github_homepage| and |bitbucket_homepage|. 

Place an ``appveyor.yml`` file in your repository and each time you push to your Github repository it will kick-off a new build in Windows, executing your tests and publishing it as a biicode block into your biicode user account. 

Login AppVeyor and click on ``+ NEW PROJECT`` and choose the repository you want to deploy with. Create an ``appveyor.yml`` file in your local project to automatically publish your block to biicode, including your version tags, here's an example file:

.. literalinclude:: /_static/code/cpp/integration/appveyor-basic.yml
   :language: text

Encrypt your biicode password and your access token using |appveyor_encrypt_data|, copy the values generated and put them it in your  environment like ``secured_password: secure:``.
Use your own ``test_script`` and ``environment`` values to start deploying with it.

Here's an appveyor guide about how to |appveyor_git_push|. Following this Appveyor Guide we're using it as credentials with Git commands. Use this GitHub guide to create your |github_access_token|. This is a full *appveyor.yml* file to automatically publish to biicode DEV and STABLE versions:

.. literalinclude:: /_static/code/cpp/integration/appveyor.yml
   :language: text


What's going on the ``appveyor.yml`` file?

   * ``install:`` This part installs all tools required to deploy your biicode projects in AppVeyor.
   * ``before_build:`` Moves your project's files into the biicode project and configures it to use Visual Studio 12 via ``bii configure``.  Check biicode docs and  your project's settings in Appveyor to use other build configurations. **Also note** that there's a commented line here you should also write if your project contains folders.
   * ``test_script:`` cd bin and execute your project. Ensure about your project's executable, build and execute it locally with  ``bii build``.
   * ``deploy_script:`` This script publishes your block to biicode, including your version tag only when it's tagged.
   * ``on_success:`` If your biicode.conf file is updated commit its changes to github without launching a new build. Else do nothing.
   * ``environment:`` Replace all environment variables here with your values: project_name, tag, default version tag value... Also your encrypted variables.

You can see this example live:

* |github_appveyor_parser| in GitHub
* |appveyor_build_parser| in AppVeyor
* |biicode_block_parser| with its automatically published releases

Learn more about AppVeyor visiting their `docs <http://www.appveyor.com/docs>`_.

.. container:: infonote

   Here's a blog-post about `using Appveyor CI <http://blog.biicode.com/appveyor-ci-windows-biicode/>`_ and Deploy for Windows 

.. _travis_integration:

Travis CI
^^^^^^^^^

|travis_homepage| takes care of running your tests and deploying your apps. Like we work with VCS, many of the blocks published in our web have their ``.travis.yml`` files, that lets us pushing to our |github_homepage| repository, and automatically build in Linux, execute and publish this project with your biicode user account thanks to this excellent service.

If you're working with it, the ``.travis.yml`` file format will help to automatically publish to your biicode account with DEV tag: 

.. literalinclude:: /_static/code/cpp/integration/travis-basic.yml
   :language: text

Here's a way to automatically publish to your biicode account with DEV tag unless your github repository is tagged, in this case, imports the tag and publishes as STABLE to biicode: 

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


Check our |biicode_forum_link| and/or |biicode_stackoverflow_link| for questions and answers. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |biicode_stackoverflow_link| raw:: html

   <a href="http://stackoverflow.com/questions/tagged/biicode" target="_blank">StackOverflow tag</a>

.. |appveyor_homepage| raw:: html

   <a href="https://ci.appveyor.com/" target="_blank">AppVeyor</a>

.. |github_homepage| raw:: html

   <a href="https://github.com/" target="_blank">GitHub</a>

.. |bitbucket_homepage| raw:: html

   <a href="https://bitbucket.org/" target="_blank">Bitbucket</a>

.. |travis_homepage| raw:: html

   <a href="https://travis-ci.com/" target="_blank">Travis CI</a>

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
