
Workspace and hives layout
==========================

.. _layouts:


In this section we are going to explain the structure of biicode projects in disk.
Top level directory is the workspace, it contains cached data from server, information about your machine, system and tools, default configurations and hives.

Workspace layout
----------------

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

.. _workspace_bii:

As you see there is a bii folder containing a bunch of files and all your hives. We will explain later hive directory structure so let's focus on files within bii folder.

* **.local.db**: is the local cache, it keeps published blocks you have read from server
* **default_filefilter**: holds default `filefilter <http://docs.biicode.com/en/latest/reference/filefilter.html>`_ configuration, it is copied to all hives and can be edited globaly or in an individual hive
* **default_settings**: holds default `settings <http://docs.biicode.com/en/latest/reference/settings.html>`_ configuration, hives use that information and you can override it in every hive
* **default_policies**: holds default `policies <http://docs.biicode.com/en/latest/reference/policies.html>`_ configuration, it is copied to all hives and can be edited globaly or in an individual hive
* **environment.bii**: Holds information about your system and tools such as your operating system and tools. You can edit a path if the tool is not in your $PATH

Hive layout
-----------

Hive layout is as follows:::

|-- my_hive
|    |-- bii
|    |    |-- .hive.db
|    |    |-- filefilter.bii 
|    |    |-- settings.bii
|    |    |-- policies.bii
|    |    |-- dependencies.bii
|    |    |-- virtual.bii
|    +-- bin
|    +-- build
|    +-- dep
|    +-- src
|         |-- CMakeLists.txt
|    	  +-- my_user_name
|         |     +-- my_block
|		  |     |       |-- cpp_rules.bii
|         |   	|       |-- hello.c
|         |     |       |-- hello.h
|         |     +-- my_other_block
|         |   	|       |-- foo.c
|         |     |       |-- bar.h
|         +-- other_user_name
|         |     +-- block_im_editing
|         |   	|       |-- message.c
|         |     |       |-- message.h		

As you see, the hive contains a collections of folders, we will go through each of them:

* **bii**: I has a similar structure to workspace bii folder described before in :ref:`workspace_bii`. It also contains some extra files:

	* **.hive.db**: It contains all your hive information
	* **dependencies.bii**: Optional file. Allows you to set extra dependencies for yor project such as licese files. You can read about it `here <http://docs.biicode.com/en/latest/advanced-features.html?highlight=cpp_rules#edit-dependencies>`_
	* **virtual.bii**: Optional file. Used to configure `virtual resources <http://docs.biicode.com/en/latest/advanced-features.html?highlight=cpp_rules#virtual-resources>`_
* **bin**: When you build your project, if there are any generated executables, they will be placed here. You can safely delete it's contents
* **build**: Contains build files such as make scripts and compiled objects. You can safely delete it's contents
* **dep**: Contains your hive dependencies source code, but only the files you're using.
* **src**: Contains the code you are working on, code is listed under usernames folders as you can be editing other person's code. Under each username folder you can find all the blocks you are editing at the moment. Inside your src folder you can also have a `rules file <http://docs.biicode.com/en/latest/advanced-features.html?highlight=cpp_rules#compilation-rules>`_ to configure your build.

