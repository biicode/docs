.. _generators_ide:

Generators and IDEs
===================

Use CMake generators to **create biicode projects for many IDEs and platforms**. By default, biicode configures your projects with no IDE and MinGW (Windows) and UNIX Makefiles (MacOS and Linux).

Execute ``cmake --help`` to see the full list of CMake generators available in your system:

.. code-block:: bash

	$ cmake --help

Choose yours, and tell biicode to configure your project for that IDE:

.. code-block:: bash

	$ bii configure -G "CMake generator name"


``bii configure`` admits any other CMake directives. For example, to enable the **Debug** build configuration,(e.g. Visual Studio, Eclipse):

.. code-block:: bash

	$ bii configure -G "CMake generator name" -DCMAKE_BUILD_TYPE=Debug


.. container:: infonote

	**Note:** When you are working with an IDE (Visual, Eclipse, CLion), and you change your project structure, add/remove files or dependencies, you might need to run **bii configure** again.


.. _ide_eclipse:

Eclipse CDT
------------

To create an Eclipse CDT project, run:

.. code-block:: bash

  $ bii configure -G "Eclipse CDT4 - Unix Makefiles"


.. container:: infonote

    Windows users might configure it like this:

    .. code-block:: bash

      $ bii configure -G "Eclipse CDT4 - MinGW Makefiles"

Now, import your project into the Eclipse IDE.

#. From the main Eclipse menu choose: *File > import...*
#. Now, select *general > Existing Projects into Workspace*, and click next.
#. Select the root directory as the **root folder of your project**.
#. You should see a project already selected in the *projects* box. Click *finish*.

If you want to add new files to your block, just right-click on the folder of your block and create a new file.

You can build your application in *Project > Build project*

If you are using  Eclipse with **Mac OS X**, you will need some additional setup to execute your binaries within this IDE. :ref:`Read this troubleshooting section for more information <eclipse_osx_binaries>`.


.. _ide_visual:

Visual Studio
-------------

Generate a Microsoft Visual Studio 12 (2013) project:

.. code-block:: bash

   $ bii configure -G "Visual Studio 12"


**Open your project with Visual Studio**. Just **double-click on the .sln file inside the build folder** of your project and a VS project will open.

.. _ide_clion:

CLion
-----

Use |clion_link| - the intelligent cross-platform C/C++ IDE - with biicode.

Get into your project's folder and execute:

.. code-block:: bash

   $ bii init myproject -l=clion 

And configure your project to set the changes:

.. code-block:: bash

   $ bii configure

Open the biicode project with CLion *(File -> Open)*. 

Use biicode's commands from the embedded Terminal in CLion, open it with: **Alt+F12** or *View -> Tool Windows -> Terminal*.

.. container:: infonote
     
     Here's more info about :ref:`CLion's project layout <clion_layout>`
     
     
IDEs and VCS
==============

Eclipse or CLion IDEs need the classic biicode folder layout (can't handle your code directly in the root folder). Next steps cover how to use them when importing a project from a git repo.  Just clone/checkout the code at the corresponding folder.

* CLion:

  .. code-block:: bash

     $ bii init myproject -l=clion
     $ cd myproject
     $ git clone https://github.com...    blocks/username/blockname
     $ bii configure 
     
* Eclipse CDT projects:

  .. code-block:: bash

     $ bii init myproject
     $ cd myproject
     $ git clone https://github.com...    blocks/username/blockname
     $ bii configure -G "Eclipse CDT4 - MinGW Makefiles" (or Unix)

If you have any questions, we are available at |biicode_forum_link| and/or |biicode_stackoverflow_link|. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |biicode_stackoverflow_link| raw:: html

   <a href="http://stackoverflow.com/questions/tagged/biicode" target="_blank">StackOverflow tag</a>

.. |clion_link| raw:: html
 
   <a href="https://confluence.jetbrains.com/display/CLION/Early+Access+Program" target="_blank">CLion</a>
 

