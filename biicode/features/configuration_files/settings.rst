.. _settings_bii:

settings.bii
============

The ``settings.bii`` file defines your preferred tools and specific configurations for one given hive. This file is created when you create a new hive, inside the ``bii`` folder, as you can see in the examples in the :ref:`layouts section <layouts>`.

A hive's ``settings.bii`` file stores preferences for any given project (language, compiler and other tools and configurations for that particular scenario). It is important to keep the file yaml format for correct interpretation.

You don't need to manually edit this file. **Each language or platform provides its own command for settings customization**:

* :ref:`bii cpp:settings for C/C++ hives<bii_cpp_settings>`
* :ref:`bii arduino:settings for Arduino hives<bii_arduino_settings>`
* :ref:`bii rpi:settings for Raspberry Pi hives<bii_rpi_settings>`

Format is as follows:

Common settings:
----------------

Configurable parameters common (may exist or not) for all languages. 

* Compiler:

	* Family: GNU, MINGW, VC, JAVAC

* Runner

	* Family: Java, Node, Python

* Builder:

	* Family: MSBUILD, MAKE, MINGW, NMake, ANT, MAVEN

* Configurer:

	* Family: CMake

* IDE:

	* Family: ECLIPSE, NETBEANS, VISUAL, CODEBLOCKS
	* Subfamily: CDT, PYDEV, JAVA, J2EE


C++ settings:
-------------
* Builder:

	* Builder type: to define the different types of builder you want to use:

		* None, Debug, Release, RelWithDebInfo, MinSizeRel

An example of how to write the settings to cpp is the following: ::
 
	cpp:
		builder: {family: MINGW}
		compiler: {family: MINGW}
		ide: {family: ECLIPSE, subfamily: CDT}
		build_type: debug
