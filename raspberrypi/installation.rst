.. _rpi_installation:

Installation
============

If you are here, that's because **you want to develop your Raspberry Pi (RPi) C++ projects with biicode**. To do so, it is assumed you already have a Raspberry Pi board available. 

Additionally, you will need a **Raspbian image** installed. That's because both the biicode client program (if you intend to develop directly on your RPi board), and the `RPi cross compilation tools <https://github.com/raspberrypi/tools>`_ (if you intend to cross-compile your programs, working on your desktop computer or laptop) are prepared for Debian-based distributions.

Here you will learn **how to set up your system for developing with biicode using the C++ programming language**. The steps involve:

#. Installing the biicode software on your machine
#. Installing a Raspbian distribution on your board.
#. Install some additional tools for cross-compiling from a Linux system.


1. Biicode initial setup
------------------------

First of all, **you need to complete the biicode general installation**. Follow :ref:`the instructions in the general documentation, following this link <first_steps>`. You must: 

* **Sign up** with biicode
* Download and install the **client binaries** for your operating system
* Create a biicode **workspace**

After you have complete these steps, proceed with the following sections:

.. include:: installation/raspbian.rst
.. include:: installation/cross-compiling.rst
