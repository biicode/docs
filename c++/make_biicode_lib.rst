.. _make_block:

Developing with biicode
=======================

Follow this guide to develop your library along with biicode wether if it's tiny or huge. These are basic steps to go. 

.. code-block:: bash

  ~$ cd your_lib_directory
  ~/your_lib_directory$ bii init -L
  ~/your_lib_directory$ #create a biicode.conf file

If you haven't got yours yet, create a *biicode.conf* file.

biicode.conf
------------

Fill ``[requirements]``,  and ``[includes]`` sections to retrieve the libs you need (Box2D, OpenSSl, OpenCV, Libuv, GTest ...) as shown in :ref:`dependencies<cpp_dependencies>` section.

Paths 
^^^^^

After that, write ``[paths]`` section to tell biicode in which folders it has to look for the local files from your includes.
You only need to specify your paths when your project has non-file-relative ``#include (s)``.

For example:

.. code-block:: text

      [paths]
          # Local directories to look for headers in your block
          include
          /

.. container:: infonote

    More information on :ref:`[paths] section<paths_conf>`

Tests
^^^^^

Sometimes your library includes some tests to check your its functionality. Your *biicode.conf* ``[tests]`` section is here to cover these tests.

Just write the test files specifically or the path to the folder that contains them like this:

.. code-block:: text

  [tests]

    projects/SelfTest/*
    tests/unit_test.cpp

Run **bii test** command and you're ready to go. 

.. container:: infonote

    You can specify in your ``[mains]`` section that which tests aren't mains. 
    :ref:`Here's more on [mains]<mains_conf>` and :ref:`[tests] <test_conf>` sections.
    

CMakeLists.txt
--------------

* For projects with no *CMakeLists.txt* just execute **bii build** and biicode will create a default one. 
* Had a previous *CMakeLists.txt*? There are different approaches: 

    You can adapt your *CMakeLists.txt* like this: 

    .. code-block:: cmake

       IF(BIICODE)   
          ADD_BIICODE_TARGETS()  
       ELSE()
          # Your regular CMakeLists configuration here
       ENDIF() 

    Or being less intrusive:

    .. code-block:: cmake

        if (BIICODE)
        include(biicode.cmake)
        return()
        endif ()

    And write in that macro the specific cmake config for biicode, like:

    .. code-block:: cmake

        #biicode.cmake file

        ADD_BIICODE_TARGETS()


* Follow this :ref:`Build Config Guide <cpp_building>` to understand in depth building with biicode and CMake.

* There's also a post series explaining how to |upload_to_biicode| and a blogpost explaining how to |reuse_cmake_macros|.

   
.. container:: infonote

    **Are you using boost?** :ref:`Check how to use boost features with biicode <boost_examples>`.


Got any doubts? We are available at |biicode_forum_link| for any problems. You can also |biicode_stackoverflow| and |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |biicode_stackoverflow| raw:: html

   <a href="http://stackoverflow.com/questions/tagged/biicode" target="_blank">tag your question in StackOverflow</a>

.. |upload_to_biicode| raw:: html

   <a href="http://blog.biicode.com/tag/upload-libraries-to-biicode/" target="_blank">Upload libraries to Biicode</a>

.. |reuse_cmake_macros| raw:: html

   <a href="http://blog.biicode.com/publish-share-reuse-cmake-macros/" target="_blank">reuse CMake macros</a>
