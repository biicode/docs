Reference
==============

.. _filefilter:

The File Filter
---------------

The file below is the **File Filter**. The information included in this file determines the types of files that you want to include in your Hive. ::

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


Settings
---------------

The settings.bii  file defines the tools that you want to use and their corresponding settings. This file is created when you create a new hive in the bii folder, its parameters are as follows:

cpp settings:
^^^^^^^^^^^^^

Configurable parameters are as shown below. It is important to keep the file format for correct interpretation:

* Compiler:

	* Family: GNU, MINGW, VC, JAVAC

* Runner

	* Family: Java, Node, Python

* Builder:

	* Family: MSBUILD, MAKE, MINGW, NMake, ANT, MAVEN
	* Builder type: to define the different types of builder you want to use:

		* None, Debug, Release, RelWithDebInfo, MinSizeRel

* Configurer:

	* Family: CMake

* IDE:

	* Family: ECLIPSE, NETBEANS, VISUAL, CODEBLOCKS
	* Subfamily: CDT, PYDEV, JAVA, J2EE

An example of how to write the settings to cpp is the following: ::
 
	cpp:
		builder: {family: MINGW}
		compiler: {family: MINGW}
		ide: {family: ECLIPSE, subfamily: CDT}
		build_type: debug
