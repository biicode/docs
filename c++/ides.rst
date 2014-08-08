.. _cpp_ides:

Using an IDE
=============

Biicode offers **integration with some of the most commonly used IDEs** for C++ programmers. By default, biicode configures your projects with MinGW Makefiles (Windows) or UNIX Makefiles (MacOS and Linux), to change it execute ``bii cpp:configure`` and the cmake command to change generators.


.. _ide_eclipse:

1. Eclipse CDT
----------------

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


.. container:: infonote

     ``bii clean`` command deletes Eclipse project's configuration, so execute ``bii cpp:configure`` after that to regenerate the configuration.


If you are using  Eclipse with **OS X** as development platform, you will need some additional setup to execute your binaries within this IDE. :ref:`Read this troubleshooting section for more information <eclipse_osx_binaries>`.


.. _ide_visual:

2. Visual Studio
----------------------

.. code-block:: bash

  $ bii cpp:configure -G "Visual Studio 10"

If you changes the default generator, it'll be saved in your ``settings.bii`` file each time, and it'll convert in your new default generator.

.. code-block:: bash

  $ bii cpp:configure -G "Visual Studio 9 2008"
  ...
  $ bii cpp:configure
  #Calling to Visual Studio 9 2008 generator


Finally, you are now ready to **open your project with Visual Studio**. Just **double-click on the .sln file inside the build folder** of your project and a VS project will open with the folder structure that appears below. Your source code is located in the third folder:

.. image:: /_static/img/visual_studio_tree.jpg



  