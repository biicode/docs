GLUI User Interface Library
===========================

`GLUI <http://glui.sourceforge.net/>`__ s a **GLUT-based C++ user interface library** which provides controls such as buttons, checkboxes, radio buttons, and spinners to OpenGL applications. It is window-system independent, relying on `GLUT <http://www.opengl.org/resources/libraries/glut/>`__ to handle all system-dependent issues, such as window and mouse management.

For more information about this library, visit their `official website <http://glui.sourceforge.net/>`__.

This is the `biicode library site <https://www.biicode.com/glui/glui>`__.

Following, there is an example using this library with biicode technology.

GLUI Window Template
--------------------

This example is a small modification of the code originaly programmed by `Ali Bader Eddin <http://www.codeproject.com/Members/Ali-BaderEddin>`__, avaliable from `the Code Project <http://www.codeproject.com/Articles/20286/GLUI-Window-Template>`__. In words of the author:

*"To avoid having to write the same code every time you want to create an OpenGL graphical application with GUI components, this program code can be used as a template to get you directly started".*

You can `explore the source code block for this example following this link <https://www.biicode.com/examples/glui_example>`__. In order to try this example, you only need to follow these steps:

.. container:: infonote

    **Ubuntu users may need to install some additional software**

	If you are using Ubuntu Linux, you may need to install some additional packages. To do so, execute:

	.. code-block:: bash

		sudo apt-get install mesa-common-dev libglu1-mesa-dev libxi-dev	


1. Create a **new project**:

.. code-block:: bash

   $ bii init <project_name>
   $ cd <project_name>

2. **Open "examples/glui_example" block**. Download the ``examples/glui_example`` block to your project's `blocks` folder. Inside your project folder, execute the command:

.. code-block:: bash

		<project_name>$ bii open examples/glui_example


3. **Retrieve all missing dependencies** using the ``bii find`` command. This way all missing dependencies will be downloaded into the ``deps`` folder of your project.

.. code-block:: bash

		<project_name>$ bii find


4. Finally, **compile your program** using the ``bii cpp:build`` command:

.. code-block:: bash

		<project_name>$ bii cpp:build

If there were no errors during compilation, you'll find a new executable file inside your project's ``bin`` folder. If you run this program, you should see something similar to this screen capture. If you found any problems, `please contact us at our forum <http://forum.biicode.com/category/c-c>`__.

.. image:: /_static/img/c++/examples/glui_example.png

