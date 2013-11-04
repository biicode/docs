Frequently Asked Questions
==========================

How do I configure my settings to build executables with Visual Studio Compiler?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The tools biicode uses for building binaries and compiling the source code are specified into the settings.bii file, 
located inside the bii folder of the hive. ::

An example of how to write the settings to build executables with Visual Studio 10: ::
 
	cpp:
		builder: {family: NMake, version: '10.0'}
		compiler: {family: VC}
		build_type: release

Because it is based on the CMake tool, some versions of Visual Studio need an specific way for specifiyng the tool version: ::
