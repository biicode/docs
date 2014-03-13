.. _faqs_cpp:

FAQs
====

How do I configure my settings to build executables with Visual Studio Compiler?
---------------------------------------------------------------------------------

The tools biicode uses for building binaries and compiling the source code are specified into the settings.bii file, 
located inside the bii folder of the hive.

An example of how to write the settings to build executables with Visual Studio 10: ::

	cpp:
		builder: {family: NMake, version: '10.0'}
		compiler: {family: VC}
		build_type: release

Because it is based on the CMake tool, some versions of Visual Studio need an specific way for specifiyng the tool version: 

====================	=================================================== 
Visual version      	Builder 
====================	=================================================== 	
Visual Studio 6	 		{family: NMake, version: '6.0'}	    	
Visual Studio 7			{family: NMake, version: '7.0'}
Visual Studio .NET		{family: NMake, version: '7.0', code: ' .NET 2003'}
Visual Studio 8			{family: NMake, version: '8.0', code: ' 2005'}
Visual Studio 9			{family: NMake, version: '9.0', code: ' 2008'}
Visual Studio 10		{family: NMake, version: '10.0'}
====================	=================================================== 

