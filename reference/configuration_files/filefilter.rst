
.. _filefilter:

The file filter
---------------

The ``filefilter.bii`` file allows you to specify which files will be processed and published by the Biicode client program. The concept is similar to the ``.gitignore`` files in a git repository, and allows you to define which extensions will be uploaded to our servers, and which ones will be excluded. The most important difference with a typical ``.gitignore`` file, is that the ``filefileter.bii`` file **must explicitly indicate which extensions must be included in your project, whitelisting them via appropriate configuration**. This is important to provide Biicode with information about which file containe source code, what is the language of that code, and how we must process your files and find their dependencies.

Here you can see an example of the ``defaul_filefilter.bii`` file located in the ``bii`` folder in the root of your workspace (as you can see in :ref:`layouts section <layouts>`). ::

	# You can edit this file to add accepted and ignored file extensions
	# Configuration is up to down hierarchical so first rule matched is the one applied.
	#
	# Format is as follows:
	#     <rule>    <pattern>    <desired_extension>
	# rule: can be 'ACCEPT' or 'IGNORE'
	# pattern: conforms Unix Filename Pattern Matching
	# desired_extension: This indicates you'd like matched files to be treated
	#                    as if they had that extension. It can be left blank
	#
	# Example: Accept files without extension to be treated as c headers
	# ACCEPT    [!.]*    .h

	# Compiled source #
	IGNORE     *.com
	IGNORE     *.class
	IGNORE     *.dll
	IGNORE     *.exe
	IGNORE     *.o
	IGNORE     *.so
	IGNORE     *.obj
	IGNORE     *.pyc
	IGNORE     *.dir

	# Editor backups
	IGNORE     *~

	# Hidden files
	IGNORE     *.*/*

	# OS generated files
	IGNORE    Thumbs.db
	IGNORE    ehthumbs.db
	IGNORE    .DS_STORE

	# Known source code
	ACCEPT    *.c
	ACCEPT    *.cpp
	ACCEPT    *.cc
	ACCEPT    *.h
	ACCEPT    *.hh
	ACCEPT    *.hxx
	ACCEPT    *.hpp
	ACCEPT    *.js
	ACCEPT    *.node
	ACCEPT    *.json
	ACCEPT    *.java
	ACCEPT    *.py
	ACCEPT    *.f
	ACCEPT    *.F
	ACCEPT    *.for
	ACCEPT    *.f90

	# Text and markup
	ACCEPT    *.txt
	ACCEPT    *.md
	ACCEPT    *.htm
	ACCEPT    *.html
	ACCEPT    *.xml
	ACCEPT    *.bii

	# Binaries, images
	ACCEPT    *.wav
	ACCEPT    *.mp3
	ACCEPT    *.gif
	ACCEPT    *.jpg
	ACCEPT    *.png
	ACCEPT    *.bmp

This file defines a **default set of files** to be included in yout hives, and a set of excluded files (usually configuration and temporary files). This file is **used as a template** that is copied to ``your_hive/bii`` folder whenever you create a new hive. However, it is up to you to modify this default configuration, setting the defaults that will be used in all your new hives, or even modify the ``filefilter.bii`` contained in the ``bii`` folder of one hive to apply a prticular configuration to a single given project.

The previous template file also shows the expected structure of each configuration line: ::

	ACCEPT|IGNORE <pattern> <desired_extension>

For example, if you want to use ``.ppm`` and ``.pgm`` images, not included by default in the previous whitelist, you would have to add the following lines to the ``filefilter.bii`` file in your hive: ::

	ACCEPT   *.ppm
	ACCEPT   *.pgm

In this case it is not necessary to specify how must be treated this files, as they contain binary information, of no relevante to the biicode processing. However, if for whatever reason you decided to write C++ code in files with a ``.kk`` extension, you could indicate so with the following line: ::

	ACCEPT   *.kk   *.cpp
