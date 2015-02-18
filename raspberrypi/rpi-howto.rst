.. _howto_rpi:

How to
======

Use a custom tool-chain
-----------------------

When you build your projects, biicode automatically generates a default tool-chain to build projects.
To **use a custom tool-chain** you need to **place it in the bii folder** of your project **with the name <your_toolchain_name>-toolchain.cmake**.

To use it, just pass it as argument of ``bii cpp:configure -t your_toolchain_name``.

For example, I want to write a program to my coffee machine that has an Raspberry Pi inside and I have a toolchain. First, copy my toolchain with the name coffe-toolchain.cmake into the bii folder. Then, execute ``bii cpp:configure`` with ``-t`` or ``--toolchain`` flag whith the name ``coffe``:

.. code-block:: bash

    $ bii init my_coffe_machine
    $ cd my_coffe_machine
    $ #copy coffe-toolchain.cmake into init my_coffe_machine/bii
    $ bii cpp:configure -t coffe

If you want to change the toolchain that you are using, just execute ``bii cpp:configure -t my_new_toolchain_name``

If you want to use the default environment, just execute ``bii rpi:settings`` and ``bii cpp:configure -t rpi``.

You can edit the ``rpi-toolchain.cmake`` if you want to use the default settings but with all your changes.

Installing the biicode package from downloads page is too slow
---------------------------------------------------------------
	
You can do it this alternative way:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu[ARCH]_[VERSION].deb

For example, you want to install the new release biicode package, for example, *0.7.2* in your Ubuntu 12.10 64 bits version, then you have to enter:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu64_0_7_2.deb
	
If you would have the 32 bits version:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu32_0_7_2.deb


Output selection and volume control
------------------------------------

**You can force the RPi to use a specific interface** using the command ``amixer cset numid=3 N``, where the ``N`` parameter can take the following values:

* ``0`` for **auto** selection
* ``1`` for **analog** output
* ``2`` for **hdmi** output

Therefore, to force the Raspberry Pi to use the analog output, you can use the following command:

.. code-block:: bash

	$ amixer cset numid=3 1

If you want to change the volume level:

.. code-block:: bash

	$ amixer cset numid=1 -- 20%

.. _rpigpio:

Raspberry Pi GPIO Pin Layout
----------------------------

`The definitive Parspberry Pi pinout by pighixxx <http://pighixxx.tumblr.com/>`_

.. image:: ../_static/img/rpi/rpi_gpio.png
