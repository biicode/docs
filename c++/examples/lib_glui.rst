GLUI User Interface Library
===========================

`GLUI <http://glui.sourceforge.net/>`__ s a **GLUT-based C++ user interface library** which provides controls such as buttons, checkboxes, radio buttons, and spinners to OpenGL applications. It is window-system independent, relying on `GLUT <http://www.opengl.org/resources/libraries/glut/>`__ to handle all system-dependent issues, such as window and mouse management.

For more information about this library, visit their `official website <http://glui.sourceforge.net/>`__.

This is the `biicode library site <https://www.biicode.com/glui/blocks/glui/glui/branches/master>`__.

Following, there is an example using this library with biicode technology.

GLUI Window Template
--------------------

This example is a small modification of the code originaly programmed by `Ali Bader Eddin <http://www.codeproject.com/Members/Ali-BaderEddin>`__, avaliable from `the Code Project <http://www.codeproject.com/Articles/20286/GLUI-Window-Template>`__. In words of the author:

*"To avoid having to write the same code every time you want to create an OpenGL graphical application with GUI components, this program code can be used as a template to get you directly started".*

You can `explore the source code block for this example following this link <https://www.biicode.com/luispedraza/blocks/luispedraza/glui_example/branches/master>`__. In order to try this example, you only need to follow these steps:

1. Create a **new hive with and empty block** in your biicode workspace. Provide ``none`` as the name of your first block (this way no block will be created) and the ``<hive_name>`` of your preference:

.. code-block:: bash

		PATH_TO_WORKSPACE$ bii new <hive_name>
		Select language: (java/node/fortran/python/cpp/arduino/None)
		Introduce lang (/o list options): cpp
		INFO: Selected lang: cpp
		How would you like to name your first block?
		Introduce block name : none
		INFO: No block will be created
		Select IDE: (eclipse/visual/none)
		Introduce ide (default:None) (/o list options): none
		Successfully created new hive test2


2. **Open this block**. It will be downloaded to your hive's `block` folder. Inside your hive folder, execute the command:

.. code-block:: bash

		PATH_TO_WORKSPACE/<hive_name>$ bii open luispedraza/glui_example


3. **Retrieve all missing dependencies** using the ``bii find`` command. This way all missing dependencies will be downloaded into the ``deps`` folder of your hive.

.. code-block:: bash

		PATH_TO_WORKSPACE/<hive_name>$ bii find


4. Finally, **compile your program** using the ``bii cpp:build`` command:

.. code-block:: bash

		PATH_TO_WORKSPACE/<hive_name>$ bii cpp:build

If there were no errors during compilation, you'll find a new executable file inside your hive's ``bin`` folder. If you run this program, you should see something similar to this screen capture. If you found any problems, `please contact us at our forum <http://forum.biicode.com/category/c-c>`__.

.. image:: /_static/img/c++/examples/glui_example.png

