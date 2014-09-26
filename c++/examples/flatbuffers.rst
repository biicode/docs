Flatbuffers
============

|flatbuffers_homepage| is an efficient cross platform serialization library for C++, with support for Java and Go. It was created at Google specifically for game development and other performance-critical applications.

The main block is |bii_flatbuffers|, which is generated from this |fork_flatbuffers|.



Charge a \*.fbs file and generate a C++ header
-----------------------------------------------

You can check all the flatbuffers examples which are uploaded in biicode and execute any of them. Then, create a new project and open the |examples_flatbuffers|.

.. code-block:: bash

   ~$ bii init flatb_sample
   ~$ cd flatb_sample
   ~/flatb_sample$ bii open examples/flatbuffers
   ~/flatb_sample$ bii cpp:build

Now, you could charge the file "monster.fbs" and generate a C++ header for tables/structs:

.. code-block:: bash

   ~/flatb_sample$ cd bin
   ~/flatb_sample/bin$ examples_flatbuffers_flatc -c ../blocks/examples/flatbuffers/monster.fbs

Now, you'll see one single file "monster_generated.h" in your current folder that has been created correctly.



.. |flatbuffers_homepage| raw:: html

   <a href="http://google.github.io/flatbuffers/" target="_blank">Flatbuffers</a>

.. |bii_flatbuffers| raw:: html

   <a href="http://www.biicode.com/fenix/flatbuffers" target="_blank">here</a>

.. |fork_flatbuffers| raw:: html

   <a href="https://github.com/franramirez688/flatbuffers" target="_blank">github repo</a>

.. |examples_flatbuffers| raw:: html

   <a href="https://www.biicode.com/examples/examples/flatbuffers/master" target="_blank">examples/flatbuffers block</a>