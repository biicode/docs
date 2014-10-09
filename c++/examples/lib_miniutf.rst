Miniutf
=======

miniutf is a C++ implementation of several basic Unicode manipulation functions developed by `Dropbox <https://opensource.dropbox.com/>`_ .

The following example how-to use miniutf to do some format conversions. You can find this example in `the biicode miniutf samples block <http://www.biicode.com/examples/miniutf>`_ .

**miniutf.cpp**

.. literalinclude:: /_static/code/cpp/examples/miniutf/miniutf.cpp
   :language: cpp
   :linenos:

**Download:**
:download:`miniutf.cpp </_static/code/cpp/examples/miniutf/miniutf.cpp>`

Create a block:

.. code-block:: bash

	$ bii init my_project
	$ cd my_project
	$ bii new examples/miniutf


Unzip those files in your block, then you need to resolve all the dependencies of this ``miniutf.cpp``. Then you can compile it

.. code-block:: bash

	$ bii find
	$ bii cpp:build


You will see next console output after executing the command:

.. code-block:: bash

	$ ./bin/examples_miniutf_miniutf
	OK
