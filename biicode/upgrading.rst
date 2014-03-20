.. _upgrading:

Upgrading
=========

Biicode software updates are straightforward: **download** the new package and **install** it over the existing package. The installer will handle the work of removing old files.

However, as biicode is an evolving technology, sometimes you will need to perform some workspace, hives and blocks upgrades manually.


Updating your workspace from older versions
-------------------------------------------

0.11.1
^^^^^^
**Important:** in this version there's no :ref:`enviroment.bii` file. 

There are new installation wizards for C/C++, Arduino and Raspberry Pi. You don’t need to manually download external tools anymore. To set them up you only need to execute one of the following commands in your console: 
C/C++: ``bii setup:cpp`` 
Arduino:``bii setup:arduino`` 
Raspberry Pi: ``bii setup:rpi`` 

Whenever you are establishing or changing your settings, just write 
bii arduino:settings or bii rpi:settings and answer the wizard’s questions!

Also, **it automatically detects which port is your Arduino connected**.

Any trouble, `check our troubleshooting for Biicode version 0.11.1 <http://docs.biicode.com/biicode/troubleshooting.html>`_ 


0.6.2
^^^^^

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