.. _settings_bii:

Settings
--------

The ``settings.bii`` file defines the tools that you want to use and their corresponding settings. This file is created when you create a new hive inside the ``bii`` folder, as you can see in the examples in the :ref:`layouts section <layouts>`. Its contents are copied from the ``default_settings.bii`` template file located in the ``bii`` folder of your workspace. While this template contains common settings for all supported languages, the ``settings.bii`` file for your hive is particularized for the actual language of your project. It is important to keep the file format for correct interpretation. Format is as follows:

Common settings:
^^^^^^^^^^^^^^^^

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
^^^^^^^^^^^^^
* Builder:

	* Builder type: to define the different types of builder you want to use:

		* None, Debug, Release, RelWithDebInfo, MinSizeRel

An example of how to write the settings to cpp is the following: ::
 
	cpp:
		builder: {family: MINGW}
		compiler: {family: MINGW}
		ide: {family: ECLIPSE, subfamily: CDT}
		build_type: debug
