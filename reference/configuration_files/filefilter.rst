
.. _filefilter:

Filefilter
---------------

The file below is ``filefilter.bii``. It is placed under YOUR_WORKSPACE/bii YOUR_HIVE/bii as you can see in :ref:`layouts section <layouts>`. Information included in this file determines the types of files that you want to include in your Hive. ::

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

For example, if you want to use .ppm and .pgm images, you would have to add the following lines: ::

	ACCEPT *.ppm
	ACCEPT *.pgm
