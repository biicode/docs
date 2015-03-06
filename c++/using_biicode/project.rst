.. _cpp_project:

Project Layout
--------------

Blocks live in Biicode projects, each biicode project can have in it as many blocks as you want.

**A project** is a combination of meta-data and folders containing your blocks, dependencies and files like ``policies.bii`` to apply when finding or updating your dependencies.

``bii init myproject`` creates a simple folder structure:

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    |    +-- policies.bii
  |    |    +-- settings.bii

And executing:

.. code-block:: bash

  ~$ cd myproject
  ~/myproject$ bii new username/blockname --hello=cpp

Creates this structure into *myproject*: 

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    |    +-- policies.bii
  |    |    +-- settings.bii
  |    +-- blocks/
  |    |    +-- username/
  |    |    |    +-- blockname/
  |    |    |    |    +-- main.cpp

Each project follows the same standard structure, for example:

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    +-- blocks/
  |    |    +-- owner1/
  |    |    |    +-- blockA/
  |    |    |    |    +-- src/
  |    |    |    |    +-- include/
  |    |    |    |    +-- test/   
  |    |    |    |    +-- biicode.conf
  |    |    |    |    +-- CMakeLists.txt
  |    +-- deps/
  
This structure empowers consistency between the blocks published in biicode, it also enables working with *different owner/blocks* at the same time:

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    |    +-- policies.bii
  |    |    +-- settings.bii
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

.. _custom_layout:

Customize your layout
----------------------

Use ``bii init -l`` or ``bii init --layout`` command to use a different folder structure.

.. _simple_layout:

Simple Layout
^^^^^^^^^^^^^

Place your repo's code directly in your project's folder. Use ``bii init -l simple`` .

.. code-block:: bash

  ~$ bii init -l simple myproject

Creates a simple folder structure in which *deps/ , build/ and cmake/ folders - all auxiliary folders but bin/ - are inside bii/* folder:

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    |    +-- layout.bii
  |    |    +-- policies.bii
  |    |    +-- settings.bii

in which ``layout.bii`` content is:

.. code-block:: text

    # Minimal layout, with all auxiliary folders inside "bii" and
    # The binary "bin" folder as is, and enabled code edition in the project root
    cmake: bii/cmake
    lib: bii/lib
    build: bii/build

    deps: bii/deps
    # Setting this to True enables directly editing in the project root
    # instead of blocks/youruser/yourblock
    # the block will be named as your project folder
    auto-root-block: True

For example, this is **a project with simple layout** :

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    |    +-- layout.bii
  |    |    +-- policies.bii
  |    |    +-- settings.bii
  |    |    +-- build/
  |    |    +-- cmake/
  |    |    +-- deps/
  |    +-- bin/
  |    +-- src/  
  |    +-- biicode.conf
  |    +-- CMakeLists.txt

A project's layout is fully customizable via **layout.bii** file, you can place the auxiliary folders wherever you want, just specify the relative routes to the folders you want to use instead.

TMP Layout
^^^^^^^^^^
Looking for an even cleaner layout? Use ``bii init -l tmp``.

This layout option redirects *deps/ , build/ and cmake/ folders to tmp/myproject/ -all aux folders but bin/* - and places your repo's code directly in your project's folder. 

.. -block:: bash

  ~$ bii init -l simple myproject

Creates a simple folder structure in which *deps/,build/ and cmake/ folders (all auxiliary folders but bin/ are inside bii/* folder:

.. code-block:: text

  +-- myproject/
  |    +-- bii/
  |    |    +-- layout.bii
  |    |    +-- policies.bii
  |    |    +-- settings.bii

in which ``layout.bii`` content is:

.. code-block:: text

    # Layout that redirect aux folders to your tmp/project folder
    cmake: $TMP/cmake
    lib: $TMP/lib
    build: $TMP/build
    deps: $TMP/deps
    auto-root-block: True

For example, this is **a project with simple layout** :

.. code-block:: text

    +-- myproject/
    |    +-- bii/
    |    |    +-- layout.bii
    |    |    +-- policies.bii
    |    |    +-- settings.bii
    |    +-- bin/
    |    +-- src/  
    |    +-- biicode.conf
    |    +-- CMakeLists.txt


.. _clion_layout:

CLion Layout
^^^^^^^^^^^^
Use |clion_link| with biicode, just like the regular biicode layout but with a ``bii/layout.bii`` to integrate biicode with the C/C++ IDE.

This layout places your repo's code as usual, in your ``project_name/blocks/owner/blockname`` directory:

.. -block:: bash

  ~$ bii init -l clion myproject

This working project looks like this:

.. code-block:: text

    +-- myproject/
    |    +-- bii/
    |    |    +-- policies.bii
    |    |    +-- settings.bii
    |    |    +-- layout.bii  
    |    +-- blocks/
    |    |    +-- owner1/
    |    |    |    +-- blockA/
    |    |    |    |    +-- src/
    |    |    |    |    +-- include/
    |    |    |    |    +-- test/   
    |    |    |    |    +-- biicode.conf
    |    |    |    |    +-- CMakeLists.txt
    |    +-- deps/


in which ``layout.bii`` content is:

.. code-block:: text

    # Layout for CLion IDE with root CMakeLists at project root
    # This layout DOES NOT allow root-block, as it will overwrite the project CMakeLists
    cmake: /

.. container:: infonote
     
     Here's more info about :ref:`working with CLion <ide_clion>`


Check our |biicode_forum_link| and/or |biicode_stackoverflow_link| for questions and answers. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |biicode_stackoverflow_link| raw:: html

   <a href="http://stackoverflow.com/questions/tagged/biicode" target="_blank">StackOverflow tag</a>
   
.. |clion_link| raw:: html
 
   <a href="https://confluence.jetbrains.com/display/CLION/Early+Access+Program" target="_blank">CLion</a>
