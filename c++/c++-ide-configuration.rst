.. _ide_configuration:

IDE configuration
=================

Biicode offers **integration with some of the most commonly used IDEs** for C++ programmers. It is able to do the appropriate project setup on your behalf. This way you can work on your biicode hive, using the underlying infrastructure and services provided by standard IDEs. In fact, this configuration can be established from the very first momment, when you create a new hive with the ``bii new`` command (see :ref:`the commands reference for more information<bii_new_command>`).

This section details the steps you should follow to achieve this integration.

First of all, you need to configure your hive for the particular IDE of your choice. If you already did so when creating the hive with the help of the ``bii new`` command, you can skip this section. Otherwise, you can define your preferences in the ``settings.bii`` configuration of your hive.

Change your default C++ settings writting:

.. code-block:: bash

	$ bii cpp:settings

	Introduce ide (default:None) (/o list options): eclipse

Choose one of the available options. This will automatically update your hive ``settings.bii`` file. This is an example for this file with *Eclipse* as the chosen IDE.

.. code-block:: text

	cpp:
	  build_type: Debug
	  builder: {family: make, subfamily: mingw}
	  ide: {family: eclipse, subfamily: CDT}
	os: {arch: 32bit, family: Windows, subfamily: '8', version: 6.2.9200}

You can learn more about this command in the :ref:`commands reference section <bii_cpp_settings>`.

After modifying this file, you must execute the ``bii cpp:configure`` command to apply all chantes and **generate the project files**.

Some particular configuration options for **Eclipse**, **Visual Studio** and **CodeBlocks** are detailed in the following subsections:

.. container:: tabs-section

	.. _ide_eclipse:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Eclipse

		If you have cofigured your hive ``settings.bii`` file as in the previous example, your are ready to import your project into the Eclipse IDE.

		#. From the main Eclipse menu choose: *File > import...*
		#. Now, select *general > Existing Projects into Workspace*, and clic next.
		#. Select the root directory as the **root folder of your hive**.
		#. You should see a project already selected in the *projects* box. Click *finish*.

		If you want to add new files to your block, just right-click on the folder of your block and create a new file.

		**Note:** If you add new dependencies to your project you'll need to manually invoke ``bii find``.

		You can build your application in *Project > Build project* if you don't have automated builds set.

		If you are using **Mac** as developing platform, you will need some aditional setup:

		#. Right-click on your project and select *Properties*.
		#. Select *C/C++ Make project* and click on the *Binary Parser* subsection tab.
		#. Unselect Mach-O Parser (deprecated).
		#. Select Mach-O 64 Parser.
		#. Click *OK*.

		And this is all you need to work as usual with the Eclipse IDE.

	.. _ide_visual:
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Microsoft Visual Studio

		First of all, you need to inicialize your default C++ settings with the ``bii cpp:settings`` command, as explained before. The generated ``settings.bii`` is a YAML file with the following contents:

		.. code-block:: text

			cpp:
			  builder: {family: MINGW}
			  compiler: {family: MINGW}
			os: {arch: 32bit, family: Windows, subfamily: '7', version: 6.1.7601}

		If you want to change your IDE to build your project with Microsoft Visual Studio, you need to add the following command lines to this config file. Copy them exactly as it appears on screen (same indentation and blank spaces). Note that **builder and compiler definition lines are not required any more**:


		.. code-block:: text

			cpp:
			  ide: {family: VISUAL, version: 10.0}
			os: {arch: 32bit, family: Windows, subfamily: '7', version: 6.1.7601}

		Now, copy the code from your hello word tutorial into the block folder. You have just chosen Visual Studio 10.0 version as IDE, i.e Visual Studio 2010. If you now configure the project with these settings, the output in the console would be:

		.. code-block:: bash

			$ bii cpp:configure

			...

			invoking cmake  -G "Visual Studio 10" -Wno-dev ../blocks
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


		Finally, you are now ready to open your project with Visual Studio. Just double-click on the .sln file inside the build folder of your hive and a VS project will open with the folder structure that appears below. Your source code is located in the third folder:

		.. image:: /_static/img/visual_studio_tree.jpg

		
	.. _ide_codeblocks:
	.. container:: tabs-item

		.. rst-class:: tabs-title

			CodeBlocks

		First of all, you need to configure your project. Initialize your default C++ settings as explained before, using the ``bii cpp:settings`` command from your hive folder.

		Inside the ``bii`` folder of you hive, change the file ``settings.bii`` including the following lines for the ``ide`` family and ``build_type``:

		.. code-block:: text

			cpp:
				builder: {family: MINGW}
				compiler: {family: MINGW}
				ide: {family: CodeBlocks}
				build_type: debug
			os: {arch: 32bit, family: Windows, subfamily: '8', version: 6.2.9200}

		Now, copy the code from your hello word tutorial into the block folder and write. Now, if you configure the project with these settings using the ``bii cpp:configure`` command, the output in the console would be:

		.. code-block:: bash

			$ bii cpp:configure

			...

			invoking cmake -D CMAKE_BUILD_TYPE=Debug -G "CodeBlocks - MinGW Makefiles" -Wno-dev ../blocks
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


		Finally, you are ready to open your project with CodeBlocks. The first step is to open the project:

		#. From the main menu, select *File > open...*
		#. Find the ``build`` folder of your hive and select the ``hive_name.cbp`` file.
		#. Click *open*.

		Now you have your project in the CodeBlocks workspace showing a folders tree similar to this one:

		.. image:: /_static/img/codeblocks_tree.png

		For this tutorial our user name is *tutorial* and our block simple name is *codeblocks*.

		If you want to add any file, just click on *File > New > Empty file* and create a new file in the ``blocks/username/block`` folder.

		To run your project you need to select the main file on build target:

		.. image:: /_static/img/codeblocks_build_target.png
		

		And this is all you need to work as usual in CodeBlocks.
