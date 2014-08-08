.. _cmake_generators:

Configure your CMake Generator
==============================
This section explains how to define your cmake generator, to configure it you should execute:

.. code-block:: bash

	$ bii cpp:configure -G "CMake generator"


Useful operations
---------------------

Execute this to know the generators available in your system:

.. code-block:: bash

	$ cmake --help


For example, to use Visual Studio 2010 for projects in Windows you should write:

.. code-block:: bash

	$ bii cpp: configure -G "Visual Studio 10"


If you got any questions left, you can ask them at our `forum <http://forum.biicode.com/>`_.
