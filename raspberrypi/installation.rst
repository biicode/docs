.. _rpi_installation:

Installation
============

If you are here, that's because **you want to develop your Raspberry Pi (RPi) C++ projects with biicode**. To do so, it is assumed you already have a Raspberry Pi board available. 

Additionally, you will need a **Raspbian image** installed. That's because both the biicode client program (if you intend to develop directly on your RPi board), and the `RPi cross compilation tools<https://github.com/raspberrypi/tools>`_ (if you intend to cross-compile your programs, working on your desktop computer or laptop) are prepared for Debian-based distributions.

Here you will learn **how to set up your system for developing with biicode using the C++ programming language**.

1. Raspbian installation
------------------------

First of all, you need a `Raspbian<http://www.raspbian.org/>`_ image running on your RPi board. The easiest path is to `download and install the New Out Of Box (NOOB) software provided by the Raspberry Pi foundation<http://www.raspberrypi.org/downloads>`_.

Once you have installed the Raspbian distribution on your board, you are ready to start using biicode. After all, you have just installed a Linux distribution. So you can work on your RPi board as with any other Linux operating system. Check the :ref:`documentation for biicode C++<cpp-index>` programming, :ref:`install the development tools<cpp_installation>`, and start programming!

However, you can also work on your desktop computer or laptop, and cross-compile your programs for your RPi. 

.. toctree::
   :maxdepth: 2

   installation/rpi_raspbian
   installation/rpi_linux
