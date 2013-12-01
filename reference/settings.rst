Settings
---------------

The settings.bii  file defines the tools that you want to use and their corresponding settings. It is important to keep the file format for correct interpretation. This file is created when you create a new hive in the bii folder, its parameters are as follows:

Common settings:
^^^^^^^^^^^^^^^^^^^^^^^^^^

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
* valid std are "c++11" and  "c++0x"

* Builder:

	* Builder type: to define the different types of builder you want to use:

		* None, Debug, Release, RelWithDebInfo, MinSizeRel

An example of how to write the settings to cpp is the following: ::
 
	cpp:
		builder: {family: MINGW}
		compiler: {family: MINGW}
		ide: {family: ECLIPSE, subfamily: CDT}
		std: c++11
		build_type: debug
