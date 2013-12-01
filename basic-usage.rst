Basic usage
==============

Finding dependencies
--------------------

External dependencies to your hive are retrieved from biicode servers when found to your dep folders. The configuration file for configuring your policies for this is named "policies.bii" in your hive "bii" folder. 

If you simply want to find missing dependencies, type:

.. code-block:: bash

	$ bii find

If you want to update already defined dependencies (as well as finding unresolved ones in the same step): 

.. code-block:: bash

	$ bii find --update

Note that all find commands depend on the values configured in such file. You can for example try to update your dependencies, but if there are no compatible versions that match your policies, you will not get such updates. E.g. a new ALPHA version for one of your dependencies will not be updated if you do not change your policy.

If you want to find compatible downgrades:

.. code-block:: bash

	$ bii find --downgrade

These options can be combined:

.. code-block:: bash

	$ bii find --update --downgrade

If you want to find any possible matching compatible version (not just updates or downgrades from your current one), type:

.. code-block:: bash

	$ bii find --modify



Using an IDE
-------------

Eclipse
^^^^^^^

First of all, you need to configure your project. Initialize your default C++ settings writting: ::

	$ bii cpp:settings
	...
	These are your default settings for this Hive
	Builder: MINGW
	Compiler: MINGW
	 
	If you want to change it, you have to modify this file:
	 
	 ./hive_name/bii/settings.bii

Inside the bii  folder of you hive, change the file settings.bii: ::

	cpp:
		builder: {family: MINGW}
		compiler: {family: MINGW}
	os: {arch: 32bit, family: Windows, subfamily: '8', version: 6.2.9200}

includes the following lines: ::

	cpp:
		builder: {family: MINGW}
		compiler: {family: MINGW}
		ide: {family: ECLIPSE, subfamily: CDT}
		build_type: debug
	os: {arch: 32bit, family: Windows, subfamily: '8', version: 6.2.9200}

Now, copy the code from your hello word tutorial into the block folder and write.Now, if you configure the project with these settings, the output in the console would be: ::

	$ bii cpp:configure

	...

	invoking cmake -G "Eclipse CDT4 - MinGW Makefiles" -Wno-dev ../src
	-- The C compiler identification is GNU 4.6.2
	-- The CXX compiler identification is GNU 4.6.2
	-- Could not determine Eclipse version, assuming at least 3.6 (Helios). Adjust CMAKE_ECLIPSE_VERSION if this is wrong.
	-- Check for working C compiler: C:/MinGW/bin/gcc.exe
	-- Check for working C compiler: C:/MinGW/bin/gcc.exe -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Check for working CXX compiler: C:/MinGW/bin/g++.exe
	-- Check for working CXX compiler: C:/MinGW/bin/g++.exe -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Configuring done
	-- Generating done
	-- Build files have been written to: [hive_build_folder]

if you write ``$ bii cpp:run``, you will see the following message: ::

	invoking cmake -G "Eclipse CDT4 - MinGW Makefiles" -Wno-dev ../src
	-- Could not determine Eclipse version, assuming at least 3.6 (Helios). Adjust CMAKE_ECLIPSE_VERSION if this is wrong.
	-- Configuring done
	-- Generating done
	-- Build files have been written to: [hive_build_folder]
	[!] You have configured an IDE setup
	[!] Use ECLIPSE to build your project
	[!] Use ECLIPSE to run your project

Note: when you define other IDE type, you have to compile and execute with this new one as indicated in the last two lines of the output console.

Finally, you are ready to open your project with Eclipse. The first step is to import the project:

#. File > import...
#. general > Existing Projects into Workspace and clic next.
#. Select root directory:  find the build folder of your hive and click accept.
#. Into the projects box, you should see a project already selected. Click finish

Now you have your project in eclipse workspace with a following folder tree like this:

.. image:: _static/img/eclipse_tree.png

For this tutorial our user name is tutorial and our block name is eclipse.

If you want to add any file, just click right mouse button on the folder on your block and create a new file

You only have to change the run configuration, for this:

#. Right click on your_blockname@build.
#. Run As > Run Configurations
#. New launch configuration
#. In the Application C/C++ box insert .../blockname/bin/username_blockname_main.exe
#. Click on Arguments tab.
#. In Working directory section clieck on File System
#. Select .../blockname/bin folder
#. Click on Run button.

And this is all you need to work as usual in eclipse.


Microsoft Visual Studio
^^^^^^^^^^^^^^^^^^^^^^^

First of all, you need to inicialize your default C++ settings with the following command: ::

	$ bii cpp:settings 
	... 
	These are your default settings for this Hive 

	Builder: MINGW
	Compiler: MINGW
	 
	If you want to change it, you have to modify this file:
	 
	  ./hive_name/bii/settings.bii

The settings.bii is a YAML file which contains: ::

	cpp:
	  builder: {family: MINGW}
	  compiler: {family: MINGW}
	os: {arch: 32bit, family: Windows, subfamily: '7', version: 6.1.7601}

If you want change your IDE to build your project with Visual Studio you should add the following command line and take care with the spaces you write because it must be written perfect (look at builder and compiler definitions lines): ::

	cpp:
	  ide: {family: VISUAL, version: 10.0}
	  builder: {family: MINGW}
	  compiler: {family: MINGW}
	os: {arch: 32bit, family: Windows, subfamily: '7', version: 6.1.7601}

Now, copy the code from your hello word tutorial into the block folder. You just choose Visual Studio as IDE with the version 10.0, i.e Visual Studio 2010. Now, if you configure the project with these settings, the output in the console would be: ::

	$bii cpp:configure

	...

	invoking cmake  -G "Visual Studio 10" -Wno-dev ../src
	-- The C compiler identification is MSVC 16.0.40219.1
	-- The CXX compiler identification is MSVC 16.0.40219.1
	-- Check for working C compiler using: Visual Studio 10
	-- Check for working C compiler using: Visual Studio 10 -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Check for working CXX compiler using: Visual Studio 10
	-- Check for working CXX compiler using: Visual Studio 10 -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Configuring done
	-- Generating done
	-- Build files have been written to: [hive_build_folder]

If you write $ bii cpp:run, you will see the following message: ::

	invoking cmake  -G "Visual Studio 10" -Wno-dev ../src
	-- Configuring done
	-- Generating done
	-- Build files have been written to: [hive_build_folder]
	[!] You have configured an IDE setup
	[!] Use VISUAL to build your project
	[!] Use VISUAL to run your project

Note: when you define other IDE type, you have to compile and execute with this new one as indicated in the last two lines of the output console.
 
Finally, you are ready to open your project with Visual Studio. Just run the .sln file inside the build folder of your hive and will open a project with the following folder structure. Your code is located in the third folder:

.. image:: _static/img/visual_studio_tree.jpg

