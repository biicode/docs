.. _requirements_bii:

requirements.bii
================

This file is created when you use the ``bii find`` inside the ``bii`` block folder and provides the info about the dependencies of the block. The requirements information contains the version of your depencie blocks: ``<block_name>(branch_name): <version>``.

This file can be modify manually with the concrete version you need.

An example of this file can be as follows. Imagine that you have a dependency to version 4 of ``file.h`` of the block ``user_a/block_a``, you just write in your requirements.bii::

	user_a/block_a: 4