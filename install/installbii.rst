.. _installation:

Install biicode client
======================

In this section you will learn how to download the biicode client and install it on your system.

.. contents::
	:local:

Download and install the client binaries
----------------------------------------

First of all, `download the appropriate client binaries for your system <https://www.biicode.com/downloads>`_, execute the setup program and follow the instructions.
Then you'll need to set up the development tools you're going to use as described :ref:`below <dev_tools_installation>`.

**Note**: You'll need to `register <https://www.biicode.com/accounts/signup>`_ in orther to use the client.

Here is the :ref:`changelog <changelog>`.


.. _upgrading:


Upgrading
---------

Upgrades of biicode are straightforward:
download the new package, install it over the existing package.
The installer will handle the work of removing old files.


Updating your workspace from older versions
-------------------------------------------

0.6.2
^^^^^^
**Important note users upgrading from previous versions to 0.6**: in this version  :ref:`policies configuration file <policies>` has changed so you'll need to re-add your custom policies


0.5
^^^^^^

**Important note users upgrading from previous versions to 0.3.4**: in this 0.3.4 version the :ref:`hive layout <hive_layout>` has changed so you need to follow next steps to upgrade it:

* rename YOUR_HIVE/src to YOUR_HIVE/blocks
* rename YOUR_HIVE/dep to YOUR_HIVE/deps
* delete YOUR_HIVE/blocks/CMakeLists.txt
* delete YOUR_HIVE/build
* execute ``bii:clean``
* execute ``bii cpp:configure``
