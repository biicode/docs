.. _git_integration:

VCS Git (GitHub, Bitbucket, etc.)
=================================

|github_homepage| and |bitbucket_homepage| are notorious Git (Bitbucket works with Mercurial too) repository web-based hosting service which offers the distributed revision control and source code management (SCM) functionality of Git as well as add their own features.

Biicode does not intend to be version control system. We recommend you using a control version system so you can keep your code safe and versioned. You can use also SVN or CVS.

With a new project
------------------

Just ``init`` the git repository in your block folder. As in the example:

.. code-block:: bash

  $ bii init my_block
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

biicode.conf
^^^^^^^^^^^^

Now execute ``bii deps`` or ``bii deps --files`` to get all information related to biicode's dependency scanning. This tells you all the unresolved ``#include``. 

Create a ``biicode.conf`` file and fill the ``[requirements]``,  and ``[includes]`` section to retrieve the libs you need (Box2D, OpenSSl, OpenCV, Libuv, GTest ...)

Also, write the ``[paths]`` section to tell biicode in which folders it has to look for the local files from your includes (You only need to specify this when your project has non-file-relative ``#include (s)``). 

* :ref:`More information on the biicode.conf file<biicode_conf>` and on :ref:`[paths] section<biicode_conf>`

This is an example of a biicode.conf file: ::

      # Biicode configuration file

      [requirements]
        # Blocks and versions this block depends on
        diego/glfw: 1
        lasote/openssl(v1.0.2): 0
        google/gtest: 9

      [parent]
        owner/block: 0

      [paths]
          # Local directories to look for headers (within block)
          include
          /

      [dependencies]
          # Manual adjust file implicit dependencies, add (+), remove (-), or overwrite (=)
          # hello.h + hello_imp.cpp hello_imp2.cpp
          # *.h + *.cpp

      [mains]
          # Manual adjust of files that define an executable
          # !main.cpp  # Do not build
          # main2.cpp # Build it

      [hooks]
          #  add (+), remove (-), or overwrite (=) files names matching bii*stage*hook.py
          # biicode launches them as python scripts at stage = {post_process, clean}
          # CMakeLists.txt + bii/my_post_process1_hook.py bii_clean_hook.py

      [includes]
          # Mapping of include patterns
          gtest/gtest.h: google/gtest/include/gtest
          GLFW/glfw3.h: diego/glfw/include
          openssl/.h: lasote/openssl/include

      [data]
          # Manually define data files dependencies, that will be copied to bin for execution
          # By default they are copied to bin/user/block/...
          # image.cpp + image.jpg  # code should write open("user/block/image.jpg")

CMakeLists.txt
^^^^^^^^^^^^^^

* For projects with no ``CMakeLists.txt`` just execute ``bii build``. 
* Had a previous ``CMakeLists.txt``? Adapt it like this:

.. code-block:: cmake

   IF(BIICODE)   
      ADD_BIICODE_TARGETS()  
   ELSE()
      # Your regular CMakeLists configuration here
   ENDIF() 


* Follow this :ref:`Build Config Guide <cpp_building>` for specifics.

* There's also a post series explaining how to |upload_to_biicode|.

   
.. container:: infonote

    **Are you using boost?** :ref:`Check how to use boost features with biicode <boost_examples>`.

biicode status badge
^^^^^^^^^^^^^^^^^^^^

The biicode satus badge is a dynamically generated image displaying your block's latest published :ref:`version<cpp_publishing>` in biicode.

.. image:: /_static/img/c++/biicode_badge.png

This badge lets developers know your code is available to reuse at biicode. It is something determinant in the use of a dependency manager and you can place it in the *readme files* of your :ref:`VCS repository <git_integration>` and in the biicode block.

.. container:: infonote

 Get your badge in your block's **settings**.

Let people know your code can be reused easily!



You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_stackoverflow| and |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

.. |biicode_stackoverflow| raw:: html

   <a href="http://stackoverflow.com/questions/tagged/biicode" target="_blank">tag your question in StackOverflow</a>

.. |upload_to_biicode| raw:: html

   <a href="http://blog.biicode.com/tag/upload-libraries-to-biicode/" target="_blank">Upload libraries to Biicode</a>

.. |openssl_link| raw:: html

   <a href="http://www.biicode.com/lasote/openssl" target="_blank">OpenSSL</a>

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
