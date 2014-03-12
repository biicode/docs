.. _rpi_installation:

Installation
============

If you are here, that's because **you want to develop your Raspberry Pi (RPi) C++ projects with biicode**. To do so, it is assumed you already have a Raspberry Pi board available. 

Additionally, you will need a **Raspbian image** installed. That's because both the biicode client program (if you intend to develop directly on your RPi board), and the `RPi cross compilation tools <https://github.com/raspberrypi/tools>`_ (if you intend to cross-compile your programs, working on your desktop computer or laptop) are prepared for Debian-based distributions.

Here you will learn **how to set up your system for developing with biicode using the C++ programming language**. The steps involve:

#. Installing a Raspbian distribution on your board.
#. Install some additional tools for cross-compiling from a Linux system.

.. toctree::
   :maxdepth: 1

   installation/raspbian
   installation/cross-compiling
