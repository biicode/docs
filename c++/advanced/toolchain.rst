.. _custom_toolchains:

Toolchains
----------

When you build your projects, biicode automatically generates a default tool-chain to build it.
To **use a custom tool-chain** you need to **place it in the bii folder** of your project *with the name <your_toolchain_name>-toolchain.cmake*.

To use it, just pass it as argument of **bii configure -t your_toolchain_name**.

For example, I want to write a program to my armv7 and I have a toolchain named armv7-toolchain.cmake. First, copy my toolchain with the name armv7-toolchain.cmake into the bii folder. Then, execute **bii configure** with **-t** or **--toolchain** flag with the name **armv7**:

.. code-block:: bash

    $ bii init my_armv7_machine
    $ cd my_armv7_machine
    $ #copy armv7-toolchain.cmake into init my_armv7_machine/bii
    $ bii configure -t armv7

To change the toolchain you are using, just execute **bii configure -t my_new_toolchain_name**

If you want to use the native environment, execute **bii configure -t** without any toochain name or use *None* as name.

There are two toolchains you can use by default, the *arduino-toolchain.cmake* and the *rpi-toolchain.cmake*. If you want to use one of it, just use **bii arduino:settings** and **bii configure -t arduino** or **bii rpi:settings** and **bii configure -t rpi**.

.. container:: infonote

    More information about toolchains is available in `CMake's docs <http://www.cmake.org/cmake/help/v3.0/manual/cmake-toolchains.7.html>`_  .
    
We are available at |biicode_forum_link| for any issues. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>