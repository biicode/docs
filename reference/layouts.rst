.. _layouts:

Workspace and hives layout
==========================

In this section we are going to explain the structure of biicode projects in disk. If you haven't done so, we recommend reading :ref:`Basic Concepts <basic_concepts>` first. If you want to read in detail about any of these files you can check :ref:`configuration files section <config_files>`.

.. _workspace_bii:

Workspace layout
----------------

Top level directory is the **workspace**, it contains cached data from server, information about your machine, system and tools, default configurations and hives.
Workspace layout is as follows:::

|-- myworkspace
|    |-- bii
|    |    |-- .local.db
|    |    |-- default_filefilter.bii
|    |    |-- default_settings.bii
|    |    |-- default_policies.bii
|    |    +-- environment.bii
|    +-- my_hive1
|    +-- my_hive2


As you see there is a ``bii`` folder containing a bunch of files and all your hives. We will explain later hive directory structure so let's focus on files within ``bii`` folder.

* **.local.db**: is the local cache, to optimize retrieval of dependencies. You don`t need to touch or modify this file, but don`t delete it either, it is necessary.
* **default_filefilter**: holds default `filefilter <http://docs.biicode.com/en/latest/reference/filefilter.html>`_ configuration, . The filefilter is a file that allows to define which files are analyzed by biicode, and which files are just ignored.
* **default_settings**: holds default `settings <http://docs.biicode.com/en/latest/reference/settings.html>`_ configuration. The settings files define things as the OS, the tools as compilers, IDEs, etc., and are used to define at each hive how the things are build or run. 
* **default_policies**: holds default `policies <http://docs.biicode.com/en/latest/reference/policies.html>`_ configuration. The policies define how dependencies are found, what versions you want to use, etc.
* **environment.bii**: Holds information about your system and tools such as your operating system and installed compilers. You can edit a path if the tool is not in your $PATH. You can have, for example, many IDEs defined in your environment, but only one can be defined in the default_settings.bii, as only one IDE can be used at the same time for each hive.

The *default* files are copied to new hives as an initial template at the moment of creation of the hive, and they can be latter customized for such new hives, but **note that changes to default_xxx.bii files in the workspace bii folder are not propagated to already existing hives**

.. _hive_layout:

Hive layout
-----------

Inside the workspace you can hold **many hives**. Each hive layout is as follows:::

|-- my_hive
|    +-- bii
|    |    |-- .hive.db
|    |    |-- filefilter.bii
|    |    |-- settings.bii
|    |    |-- policies.bii
|    +-- bin
|    +-- blocks
|    |	  +-- my_user_name
|    |    |     +-- my_block
|    |    |     |       +-- bii
|    |    |     |   	|    |-- dependencies.bii
|    |    |     |   	|    └── virtual.bii
|    |    |     |       |-- cpp_rules.bii
|    |    |  	|       |-- hello.c
|    |    |     |       |-- hello.h
|    |    |     +-- my_other_block
|    |    |   	        |-- foo.c
|    |    |             └── bar.h
|    |    +-- other_user_name
|    |          +-- block_im_editing
|    |        	       |-- message.c
|    |                 └── message.h
|    +-- build
|    +-- cmake
|    |    |-- CMakeLists.txt
|    |    ├── bii_functions.cmake
|    |    ├── bii_targets.cmake
|    |    └── bii_vars.cmake
|    +-- deps

As you can see, the hive contains a collection of folders. We will go through each one of them:

* **bii**: It has a similar structure to the :ref:`workspace folder <workspace_bii>`. It also contains some additional files:

	* **.hive.db**: It contains all your hive meta information

* **bin**: When you build your project, if there are any generated executables, they will be placed here. You can safely delete it's contents
* **blocks**: Contains the code of the blocks you are working on. Code is listed under usernames/blockname folders as you can be editing other person's blocks. Under each username folder you can find all the blocks you are editing at the moment. For version control systems, it is usually ok to ignore everything but this ``src`` folder, together with the ``bii`` one that holds the configuration and metadata. Inside your block folder you can also have a `rules file <http://docs.biicode.com/en/latest/advanced-features.html?highlight=cpp_rules#compilation-rules>`_ to configure your build.

	* **bii**:

		* **dependencies.bii**: Optional file. Allows you to set extra dependencies for your project such as license files. You can read about it :ref:`here <dependencies_bii>`.
		* **virtual.bii**: Optional file. Used to configure `virtual resources <http://docs.biicode.com/en/latest/advanced-features.html?highlight=cpp_rules#virtual-resources>`_
* **build**: Contains build files such as make scripts and compiled objects. You can safely delete it's contents
* **cmake**: Contains autogenerated ``CMakeLists.txt`` as well as other files that allow you define your own cmake
* **deps**: Contains your hive dependencies source code. All the code contained in the ``deps`` folder is automatically downloaded by the biicode client after analyzing your source files contained under the ``blocks`` folder. These are all the strictly necessary cells for your hive to compile and run correctly.

