FAQs
====


This sections sumarizes some Frequently Asked Questions that our users hace posed up to this moment. If your particular inquiry is not in this list, please, don't hessitate to contact us so web can help you as soon as possible.

General
----------

Is biicode free?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Yes, and it will be free forever for open source projects. As long as you share code, you will have biicode with its full functionality, totally free. If you want to have private code that only you and your collaborators can see and user, you have to upgrade to a premium account (not yet available, we are working on it).

Is biicode a editor in the cloud?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
No. In biicode, you develop as usual, with your computer and tools. Biicode is simply a tool that is installed in your system, that together with a very simple project layout (bin, build, src) can manage very easily your source code, so you can reuse any single file of any of your projects in any other project. So you can use your favourite IDE, builder, debugger... Now we have some fixed settings, that allow to define some tools as Visual, Eclipse, Mingw, CMake, but it will be soon generalized to all settings, and in any case, you have always the source code very well structured in your hive (project).

Is biicode a VCS?
^^^^^^^^^^^^^^^^^^^
No. If you want real version control for your projects, you must use one (git, svn, plasticscm). However, biicode does track and manage versions of the published code in order to provide a powerful, deterministic and scalable dependency manager that also allows easy collaboration on the platform without relaying on other tools.

Can I use biicode with my favourite VCS?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Yes, but still very experimental. You can manage any of your biicode hives (projects) as a separate project under version control. You can zip and send by email, sync with dropbox, or put it into a VCS repository. But we store meta-information in a DB in binary format, as it doesnt allow straightforward merging by VCS. We are working in the merge process of such meta-information in case of conflicts that will likely arise, but it is still not available.

Can I use biicode for the XXX programming language?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
We have released our beta with a strong focus on C++, which lacks a multiOS dependency manager, and we are experimenting with other languages as Python, Node, Java and Fortran. These languages will mature in the next months, and new languages will enter the pipeline too.

How does biicode relates to Maven, NPM, PyPI...?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Biicode manage and retrieve code from a central repository, to your machine. But with some differences. For example, it always retrieve source code; if necessary artifacts (libs, jars) will be built locally for efficiency, but all the management is done with source code. In this way it is easier to develop, debug and collaborate on that source code if necessary. Furthermore, it only retrieves the necessary files, there is no such concept of package in biicode. If you need just one file of biicode, just one file is retrieved. Obviously if such file has dependencies to other files, those files are also retrieved. The retrieved files are always managed at the hive (project) level, thus, it is very easy to have and develop with different versions of dependencies in different projects, in a similar way to a virtualenv compared with a global dependency (as packages with apt-get or similar). Moreover, biicode makes a strong effort on determinism and compatibility. As the version of each file is tracked, we know when an upgrade is totally safe because it does not affect the specific files you are depending on. Biicode can even handle different versions of the same block (repo) if the dependency tree reaches such different versions but the affected files are not altered in such versions, i.e. we do not have to opt for the (typically) latest version (that can break code that rely on previous versions), but we can even mix in certain cases contents from different versions. In that way, the code that was published depending on specific versions of other code, is always compiled using exactly those versions, achieving fully determinism. Although upgrading version usually does not break code in case of mature libraries and packages, this is not true for more young and dynamic code. In this way, biicode works more as a CI system, in which developers quickly move forward their dependencies.
Said that, biicode does not try to compete against the power of such established systems nor tries to directly replace them, but to coexist with them as another source, and we are working hard for such purpose.


What is a workspace, a block, a hive?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Go to :ref:`Introduction: Basic concepts <basic_concepts>`.

Other
--------------------
How do I configure my settings to build executables with Visual Studio Compiler?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The tools biicode uses for building binaries and compiling the source code are specified into the settings.bii file, 
located inside the bii folder of the hive. ::

An example of how to write the settings to build executables with Visual Studio 10: ::
 
	cpp:
		builder: {family: NMake, version: '10.0'}
		compiler: {family: VC}
		build_type: release

Because it is based on the CMake tool, some versions of Visual Studio need an specific way for specifiyng the tool version: 



====================	=================================================== 
Visual version      	Builder 
====================	=================================================== 	
Visual Studio 6	 	{family: NMake, version: '6.0'}	    	
Visual Studio 7		{family: NMake, version: '7.0'}
Visual Studio .NET	{family: NMake, version: '7.0', code: ' .NET 2003'}
Visual Studio 8		{family: NMake, version: '8.0', code: ' 2005'}
Visual Studio 9		{family: NMake, version: '9.0', code: ' 2008'}
Visual Studio 10	{family: NMake, version: '10.0'}
====================	=================================================== 
