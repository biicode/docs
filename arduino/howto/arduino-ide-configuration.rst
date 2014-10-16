IDE configuration
=================

Biicode offers integration with `Eclipse <https://www.eclipse.org/downloads/>`_ for Arduino programmers. This way you can work on your biicode project, using the underlying infrastructure and services provided by Eclipse.

Run this command (the CMake generator will change depending on your OS)

.. code-block:: bash

	$ bii arduino:configure -G "Eclipse CDT4 - Unix Makefiles"
	...
	A new Eclipse project has been generated for you. Open eclipse, select "File > Import > General > Existing project into Workspace"and select folder "path/to/your/project_folder"

.. container:: infonote

	It is important that you use a version of Eclipse that contains the C/C++ Toolkit. So we recommend using `Eclipse IDE for C/C++ Developers <https://www.eclipse.org/downloads/>`_.


How to import your project
--------------------------
The steps are:

*	From the main Eclipse menu choose: **File > import...**
*	Now, select *General > Existing Projects into Workspace**, and **clic next**.
*	Select the **root directory** as the **root folder of your project**.
*	You should see a project already selected in the *projects* box. **Click finish**.
|
If you want to add new files to your block, just right-click on the folder of your block and create a new file.

.. container:: infonote

	If you add new dependencies to your project you'll need to manually invoke ``bii find``.

You can build your application in *Project > Build project* if you don't have automated builds set.

If you are using **Mac** as developing platform, you will need some aditional setup:

*	**Right-click** on your project and select **Properties**.
*	Select **C/C++ Make project** and **click** on the **Binary Parser** subsection tab.
*	**Unselect Mach-O Parser (deprecated)**.
*	**Select Mach-O 64 Parser**.
*	**Click OK**.
|
And this is all you need to work as usual with the Eclipse IDE. You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_write_us| for suggestions and feeback, they are always welcomed.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>
