.. _git_integration:

Git integration
================

Biicode is not a version control system but there are may reasons you might want to use one with biicode. One reason might be you want a finer grained version control than the linear, publish driven, one biicode offers. Other reason is that you already have your code in Github or Bitbucket and want to keep it there as well as in biicode. Biicode offers an **experimental** git integration.

The integration we offer is at hive level, so you can keep **version control of both the source code and the associated information**. The reason you cannot do this manually is because we store metainformation in binary format so conflicts in ``hivedb`` cannot be solved.

**If you just want to version source code** you can manually initialize a git repository inside each block folder (or the whole blocks folder) and work as usal.

Publishing your hive in git
-----------------------------
To publish your existing hive in a git repository you must have an account in `Bitbucket <https://bitbucket.org>`_, `Github <https://github.com/>`_, `Gitlab <https://gitlab.com>`_, any other provider or a local repository, the only thing **we need is the repository address**.

First of all you need to execute **bii git:init**, that will initialize git and create ``.gitignore`` and ``.gitattributes`` in your :ref:`hive folder <hive_layout>`. Then you need to configure your repository.

Bitbucket
^^^^^^^^^
Execute **bii git:add_bitbucket** and a wizard will do the configuration for you.

Other services
^^^^^^^^^^^^^^
You need to edit `.git/config` file and configure your repository.


Wrapper commands
----------------
These are some commands that will simplify your git experience if you are not and advanced user.

* ``git:load``: Loads specified version of the hive
* ``git:pull``: EXPERIMENTAL: Loads the hive in local new version
* ``git:push``: EXPERIMENTAL: Saves the hive in remote repository
* ``git:save``: Saves the hive to a new version
* ``git:versions``: List saved versions
