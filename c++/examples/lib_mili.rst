MiLi
====

MiLi is a collection of useful C++ libraries, composed only by headers. For more information about this library, visit their `official website <https://code.google.com/p/mili/>`_ or `wiki <https://code.google.com/p/mili/w/list>`_ 

You can find here the `MiLi biicode library site <https://www.biicode.com/danielgutson/blocks/danielgutson/mili/branches/master>`_ .

The following example shows a simple use for doing type-safe bitwise operations. You can find this and other examples in `the biicode MiLi samples block <https://www.biicode.com/danielgutson/blocks/danielgutson/milisamples/branches/master>`_ .

**main_mili.cpp**

.. literalinclude:: /_static/code/cpp/examples/mili/main_mili.cpp
   :language: cpp
   :linenos:

**Download the file:** :download:`main_mili.cpp </_static/code/cpp/examples/mili/main_mili.cpp>` 


First, you need to resolve all the dependencies of this ``main_mili.cpp``
	
.. code-block:: bash
	
	$ bii find


You will see next console output after executing the command:
	
.. code-block:: bash

	$ cd bin
	$ #run executable
	
	...
	
	kOne   turned on
	kTwo   turned on
	kFour  turned on

	kOne   turned on

	kOne   turned on
	kThree turned on

	<< Operator test: 0x4
	Normal Enum: 0x18
	Normal Enum: 0x20

