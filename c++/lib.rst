.. _make_block:

Making your own library with biicode
=====================================

Follow this guide to develop your library along with biicode. 

biicode.conf
^^^^^^^^^^^^

Execute ``bii deps`` or ``bii deps --files`` to get all information related to biicode's dependency scanning. This tells you all the unresolved ``#include``. 

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

Check how to get the most of **bii test** command along with ``[tests]`` section.

Tests
-----

Sometimes your library includes some tests to check your its functionality. Your *biicode.conf* ``[tests]`` section is here to cover these tests.

Just write the test files specifically or the path to the folder that contains them like this:


.. code-block:: text

	[tests]

		projects/SelfTest/*
		tests/unit_test.cpp

Run **bii test** command and you're ready to go. 

.. container:: infonote

    You can specify in your ``[mains]`` section that your tests aren't mains. 
    :ref:`Here's more on [mains] section. <mains_conf>`


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.