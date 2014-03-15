.. _rpi_installation:

Raspberry Pi set up
===================

If you are here, that's because **you want to develop your Raspberry Pi (RPi) C++ projects with biicode**. To do so, it is assumed you already have a Raspberry Pi board available. 

Additionally, you will need a **Raspbian image** installed. That's because both the biicode client program (if you intend to develop directly on your RPi board), and the `RPi cross compilation tools <https://github.com/raspberrypi/tools>`_ (if you intend to cross-compile your programs, working on your desktop computer or laptop) are prepared for Debian-based distributions.

Here you will learn **how to set up your system for developing Raspberry Pi software with biicode using the C++ programming language**. The steps involve:

1. Installing a **Raspbian distribution** on your board
2. Installing the **biicode software** on your development platform, which can be:

	- Your Raspberry Pi, if you intend programming and compiling directly on your board
	- Your laptop or desktop PC, with a Linux OS, if you intend cross-compiling your C++ programs
3. If you want to **cross-compile your programs for the RPi ARM architecture**, while working on your usual (Linux) PC or laptop, you also need to install some additional tools for **cross-compiling** from a Linux system.

**Note:** If you are new to cross-compiling, or have never heard of this concept, you'll find interesting this `Wikipedia entry about cross compilers <http://en.wikipedia.org/wiki/Cross_compilation>`_.

These 3 steps are explained bellow:

.. _raspbian_installation:

1. Raspbian installation
------------------------

First of all, you need a `Raspbian <http://www.raspbian.org/>`_ image running on your RPi board. The easiest path is to `download and install the New Out Of Box Software (NOOBS) provided by the Raspberry Pi foundation <http://www.raspberrypi.org/downloads>`_.


2. Biicode initial setup
------------------------

Once you have installed the Raspbian distribution on your board, you are ready to start programming. And hence, you can also start using biicode. After all, you have just installed a Linux distribution. So **you can work on your RPi board as with any other Linux** operating system.

Whether you intend to develop on your RPi board, or on your usual Linux Development Environment (**LDE**) cross-compiling your code, **you need to install the biicode software**. Read the :ref:`instructions in the general section of this documentation <first_steps>`. There you'll learn how to:

* **Sign up** with biicode
* Download and install the **client binaries** for your operating system (Raspbian in your RPi board, or a Debian-based distro for cross-compiling)
* Create a biicode **workspace**

.. container:: infonote

	If you intend to **develop, compile and run your programs directly on your RPi**, you only need to install the biicode software on your board. In this case you are referred to the standard :ref:`C++ biicode documentation <cpp-index>` to start programming, and you are finished with this section.

	On the other side, if you prefer **cross-compiling your programs**, you only need to install the biicode software on your LDE :moreinfo:`Linux Development Environment`, and not on your Raspberry Pi. Instead, you simply develop and cross-compile on your desktop or laptop envilonment, and transfer the binaries to your RPi board.

As mentioned before, :underline_bold:`you can work on your Linux desktop computer or laptop, and cross-compile your programs for your RPi`. This way the compilation process will be faster, and you can benefit from other advantages your usual LDE :moreinfo:`Linux Development Environment` provides.

If you want to learn how **biicode simplifies the cross-compiling process for your Raspberry Pi** board, continue reading!

.. include:: installation/cross-compiling.rst
