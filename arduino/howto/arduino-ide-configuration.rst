.. _bii_arduino_ide:

Eclipse IDE configuration
=========================

Biicode offers integration with `Eclipse <https://www.eclipse.org/downloads/>`_ for Arduino.

First of all, you need to configure your project for arduino and **Eclipse IDE for C/C++**:

.. code-block:: bash

	$ bii arduino:settings
	Enter SDK path (/../biicode_env/arduino-1.0.6): [ENTER]
	Enter board (/o list supported options): uno
	Arduino detected on port COM14
	$ bii configure -G "Eclipse CDT4 - Unix Makefiles"
	...
	A new Eclipse project has been generated for you.
	Open eclipse, select "File > Import > General > Existing project into Workspace" and select folder "YOUR_PROJECT_FOLDER"


Depending on your OS and desired compiler you can use different Eclipse generators:

* ``"Eclipse CDT4 - MinGW Makefiles"`` Generate with MinGW Makefiles.
* ``"Eclipse CDT4 - Unix Makefiles"`` Generate with Unix Makefiles.

Now you are ready to import your project into the Eclipse IDE. It is important that you use a version of Eclipse that contains the C/C++ Toolkit. So we recommend using `Eclipse IDE for C/C++ Developers <https://www.eclipse.org/downloads/>`_.

How to import your project
--------------------------

#. From the main Eclipse menu choose: *File > import...*
#. Now, select *general > Existing Projects into Workspace*, and clic next.
#. Select the root directory as the **root folder of your project**.
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

How to fix "Unresolved inclusion: Arduino.h"
--------------------------------------------

1. Open the project settings and go to C/C++ General -> Paths and Symbols
2. Click "Add external include path" and add:

* For Arduino IDE installed with biicode:

	- MAC: ``~/.biicode_env/arduino-1.0.6/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino``
	- Linux: ``~/.biicode_env/arduino-1.0.6/hardware/arduino/cores/arduino``
	- Windows: ``C:\biicode_env\arduino-1.0.6\hardware\arduino\cores\arduino``

* For manually installed Arduino IDE, just add the equivalent route.

And this is all you need to work as usual with the Eclipse IDE. **Any doubts?** Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.
