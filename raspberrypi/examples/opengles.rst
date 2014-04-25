.. _opengles:

============================================
OpenGL ES: How to cross compile with biicode
============================================

Introduction
------------

As you know, when you are using biicode to develop your RaspberryPi applications
you are compiling using a cross compiler in your develop machine. So, when you
want to develop an OpenGLES application is necessary to obtain some files from
your RaspberryPi for being able to cross compile in your develop machine, like headers
with OpenGLES interfaces an shared libraries files. Biicode allows you to do
this almost automatically.

How can I do it?
-----------------

First of all make sure that your RaspberryPi is connected to your local network,
and you have permissions grants to access it. Then you should create a new hive,
let's call it triangle.

.. code-block:: bash

    you@yourmachine ~/bii_ws $ bii new triangle
    ..
    you@yourmachine ~/bii_ws $ cd triangle

When you have your shining new hive, you should execute the following command:

.. code-block:: bash

    you@yourmachine ~/bii_ws/triangle $ bii rpi:initopengles pi 192.168.1.69
    pi@192.168.1.69's password:
    receiving incremental file list
    ..
    INFO: OpenGLES necessary files downloaded.
    you@yourmachine ~/bii_ws/triangle $

If you don't provide arguments, biicode takes values provided in settings.bii
configuration file for user and IP address of RaspberryPi.

Once executed this command you are ready to develop your awesome OpenGLES
applications as usual with biicode. 

Example
-------

**Download all the files**
	
:download:`OpenGLES_examples.zip </_static/code/rpi/OpenGLES_examples.zip>`

Just need to replace [USER]/[BLOCK] into the triangle.c file whit the info of your user and block name.