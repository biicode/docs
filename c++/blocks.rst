.. _cpp_blocks:

What is a block?
================

**A block** (also known as 'repo' or 'repository') is the place to put your code in biicode. 

Each block has an *owner, name, version* and *tag*. For example, the |openssl_link| block has an **owner** (lasote) and latest version is **3 DEV**.

Here's an example block structure:

.. code-block:: text

  +-- block_name/
  |   +-- src/
  |   |   +-- main.cpp
  |   +-- test/
  |   |   +-- test1.cpp 
  |   +-- biicode.conf
  |   +-- CMakeLists.txt
  |   +-- README

These are the main components of a block (under the ``block_name/`` directory):

  - Your repo's code, with its sources and folders.
  - ``CMakeLists.txt`` file, to specify your build config.
  - ``biicode.conf`` file with information about your block and its dependencies.
  - a README 

* :ref:`More information on the biicode.conf file<biicode_conf>`

* :ref:`Building Configuration your own Block <cpp_building>`

Create a block
--------------

Blocks live in Biicode projects, each biicode project can have in it as many blocks as you want. 

**A project** is a combination of meta-data and folders containing your blocks, dependencies and files like ``policies.bii`` to apply when finding or updating your dependencies.

Each project follows the same standard structure:

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    |    +-- policies.bii
  |    +-- blocks/
  |    |    +-- owner1/
  |    |    |    +-- blockA/
  |    |    |    |    +-- src/
  |    |    |    |    +-- include/
  |    |    |    |    +-- test/   
  |    |    |    |    +-- biicode.conf
  |    |    |    |    +-- CMakeLists.txt
  |    |    |    +-- blockB/
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- biicode.conf
  |    |    |    |    +-- CMakeLists.txt
  |    |    +-- owner2/
  |    |    |    +-- blockC/
  |    |    |    |    +-- tool.h
  |    |    |    |    +-- tool.cpp
  |    |    |    |    +-- biicode.conf
  |    |    |    |    +-- CMakeLists.txt
  |    +-- deps/
  
This structure empowers consistency between the blocks published in biicode, it also enables working with different owner/blocks at the same time.

.. container:: infonote
     
     Tips naming your block:
        * Use underscores for multiple words
        * Use lowercase letters (Newbies will thank this. OS X and Windows have case-insensitive filesystems by default)
        * :ref:`Tag your STABLE versions <version_tags>`


Create a block from a git repository
------------------------------------

The code
^^^^^^^^

Put your code into a biicode block:

.. code-block:: bash

  $~ bii init project_name
  $~ cd project_name/blocks
  $~ mkdir username
  $~ cd username
  $~ git clone https://Your_Repo_URL.git

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

* For projects with no ``CMakeLists.txt`` just execute ``bii cpp:build``. 
* Had a previous ``CMakeLists.txt``? Adapt it like this:

.. code-block:: cmake

   IF(BIICODE)
      INIT_BIICODE_BLOCK()    
      ADD_BIICODE_TARGETS()  
   ELSE()
      # Your regular CMakeLists configuration here
   ENDIF() 



* Follow this :ref:`Build Config Guide <cpp_building>` for specifics.

* There's also a post series explaining how to |upload_to_biicode|.

   
.. container:: infonote

    **Are you using boost?** :ref:`Check how to use boost features with biicode <boost_examples>`.


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


