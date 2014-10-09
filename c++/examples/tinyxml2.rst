TinyXML2
========

TinyXML-2 is a simple, small, efficient, C++ XML parser that can be easily integrating into other programs.. For more information about this library, visit their `official website <http://www.grinninglizard.com/tinyxml2/>`_ or `online documentation <http://www.grinninglizard.com/tinyxml2docs/index.html>`_ 

You can find here the `TinyXML2 biicode library site <http://www.biicode.com/lthomason/lthomason/tinyxml2/master>`_ .

The following example shows how to read and look for elements in an XML file.

**tinyxml2.cpp**

.. literalinclude:: /_static/code/cpp/examples/tinyxml2/tinyxml2.cpp
   :language: cpp
   :linenos:

**Download:** :download:`tinyxml2.zip </_static/code/cpp/examples/tinyxml2/tinyxml2.zip>` 


Create a block:

.. code-block:: bash

	$ bii init my_project
	$ cd my_project
	$ bii new examples/tinyxml2


Unzip the code and the xml files in your block, then you need to resolve all the dependencies of this ``tinyxml2.cpp``. Then you can compile it

.. code-block:: bash

	$ bii find
	$ bii cpp:build


You will see next console output after executing the command:

.. code-block:: bash

	$ cd bin
	$ bin $ ./examples_tinyxml2_tinyxml2
	Name of play (1): A Midsummer Night´s Dream
	Name of play (2): A Midsummer Night´s Dream

