.. _generators_ide:

Generators and IDEs
===================

Basics to generate biicode projects for many IDEs and platforms with CMake. To delve into the specifics of building with CMake visit :ref:`building guide<cpp_building>`. By default, biicode configures your projects with MinGW Makefiles (Windows) or UNIX Makefiles (MacOS and Linux) and no IDE.

Execute ``cmake --help`` to see the full list of CMake generators available in your system:

.. code-block:: bash

	$ cmake --help

Choose yours, and tell biicode to configure your project for that IDE:

.. code-block:: bash

	$ bii cpp:configure -G "CMake Generator Name"


``bii cpp:configure`` admits any CMake directives. ``bii cpp:configure`` directives are stored in your project's ``settings.bii`` file as the default settings for that project. 

.. container:: infonote

     
     ``bii clean`` command restores your project's settings to MinGW Makefiles (Windows) or UNIX Makefiles (MacOS and Linux) and no IDE. 


.. _ide_eclipse:

Eclipse CDT
------------

To create an Eclipse CDT project, run:

.. code-block:: bash

  $ bii cpp:configure -G "Eclipse CDT4 - Unix Makefiles"

Now, import your project into the Eclipse IDE.

#. From the main Eclipse menu choose: *File > import...*
#. Now, select *general > Existing Projects into Workspace*, and click next.
#. Select the root directory as the **root folder of your project**.
#. You should see a project already selected in the *projects* box. Click *finish*.

If you want to add new files to your block, just right-click on the folder of your block and create a new file.

**Note:** If you add new dependencies to your project you'll need to manually invoke ``bii find``.

You can build your application in *Project > Build project* if you don't have automated builds set.

``debug`` your project using gdb inside Eclipse CDT. Make sure you set -D CMAKE_BUILD_TYPE=DEBUG in ``bii cpp:configure`` command: 

.. code-block:: bash

  $ bii cpp:configure -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=DEBUG
  $ bii cpp:build



If you are using  Eclipse with **OS X** as development platform, you will need some additional setup to execute your binaries within this IDE. :ref:`Read this troubleshooting section for more information <eclipse_osx_binaries>`.


.. _ide_visual:

Visual Studio
-------------

Generate a Microsoft Visual Studio project, for a Visual Studio 10 project:

.. code-block:: bash

   $ bii cpp:configure -G "Visual Studio 10"

For example:

.. code-block:: bash

   $ bii cpp:configure -G "Visual Studio 9 2008"
   ...
   $ bii cpp:configure
   #Calling to Visual Studio 9 2008 generator

**Open your project with Visual Studio**. Just **double-click on the .sln file inside the build folder** of your project and a VS project will open.

``debug`` your project setting -D CMAKE_BUILD_TYPE=DEBUG in ``bii cpp:configure`` command: 

.. code-block:: bash

  $ bii cpp:configure -G "Visual Studio 9 2008" -D CMAKE_BUILD_TYPE=DEBUG
  $ bii cpp:build


If you have any questions, we are available at |biicode_forum_link|. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>
