Use a custom tool-chain
=======================

When you build your projects, biicode automatically generates a default tool-chain to build projects.
To **use a custom tool-chain** you need to **place it in the bii folder** of your project **with the name <your_toolchain_name>-toolchain.cmake**.

To use it, just pass it as argument of ``bii cpp:configure -t your_toolchain_name``.

For example, I want to write a program to my coffee machine that has an Arduino inside and I have a toolchain. First, copy my toolchain with the name coffe-toolchain.cmake into the bii folder. Then, execute ``bii cpp:configure`` with ``-t`` or ``--toolchain`` flag whith the name ``coffe``:

.. code-block:: bash

    $ bii init my_coffe_machine
    $ cd my_coffe_machine
    $ #copy coffe-toolchain.cmake into init my_coffe_machine/bii
    $ bii cpp:configure -t coffe

If you want to change the toolchain that you are using, just execute ``bii cpp:configure -t my_new_toolchain_name``

If you want to use the default environment, just execute ``bii arduino:settings`` and ``bii cpp:configure -t arduino``.

You can edit the ``arduino-toolchain.cmake`` if you want to use the default settings but with all your changes.

If you use a custom toolchain, remember that you need to use the ``bii cpp:build`` to compile your projects.


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>


.. |biicode_cmake_block| raw:: html

   <a href="https://www.biicode.com/biicode/cmake" target="_blank">cmake</a>

.. |cmake_build_type| raw:: html

   <a href="http://www.cmake.org/cmake/help/v3.0/variable/CMAKE_BUILD_TYPE.html" target="_blank"> CMake Build Type</a>
