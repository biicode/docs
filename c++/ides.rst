.. _generators_ide:

Generators and IDEs
===================

CMake can generate projects for many IDEs and platforms. By default, biicode configures your
projects with MinGW Makefiles (Windows) or UNIX Makefiles (MacOS and Linux) and no IDE.

To see the full list of CMake generators available in your system, you can execute:

.. code-block:: bash

	$ cmake --help


.. _ide_eclipse:

Eclipse CDT
-----------

To create an Eclipse CDT project (you should install it manually), you can run:

.. code-block:: bash

  $ bii cpp:configure -G "Eclipse CDT4 - Unix Makefiles"

Now, your are ready to import your project into the Eclipse IDE.

#. From the main Eclipse menu choose: *File > import...*
#. Now, select *general > Existing Projects into Workspace*, and click next.
#. Select the root directory as the **root folder of your project**.
#. You should see a project already selected in the *projects* box. Click *finish*.

If you want to add new files to your block, just right-click on the folder of your block and create a new file.

**Note:** If you add new dependencies to your project you'll need to manually invoke ``bii find``.

You can build your application in *Project > Build project* if you don't have automated builds set.

If you want to ``debug`` your project using gdb inside Eclipse CDT make sure you set -D CMAKE_BUILD_TYPE=DEBUG in ``bii cpp:configure`` command: 

.. code-block:: bash

  $ bii cpp:configure -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=DEBUG


.. container:: infonote

     ``bii clean`` command deletes Eclipse project's configuration, so execute ``bii cpp:configure`` after that to regenerate the configuration.


If you are using  Eclipse with **OS X** as development platform, you will need some additional setup to execute your binaries within this IDE. :ref:`Read this troubleshooting section for more information <eclipse_osx_binaries>`.


.. _ide_visual:

Visual Studio
-------------

You can also generate a Microsoft Visual Studio project, for example a Visual Studio 10 project:

.. code-block:: bash

   $ bii cpp:configure -G "Visual Studio 10"

When you specify a generator, it'll be saved in your project ``settings.bii`` file each time, and it'll convert in your new default generator for this project.
For example:

.. code-block:: bash

   $ bii cpp:configure -G "Visual Studio 9 2008"
   ...
   $ bii cpp:configure
   #Calling to Visual Studio 9 2008 generator


Finally, you are now ready to **open your project with Visual Studio**.
Just **double-click on the .sln file inside the build folder** of your project and a VS project will open


