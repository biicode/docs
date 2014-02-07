Gmock (Google C++ Mocking Framework)
=====================================

Google C++ Mocking Framework (or Google Mock, or simply gmock for short) is a library for writing and using C++ mock classes. For more information about this library, visit their `official website <https://code.google.com/p/googlemock/>`_ or `wiki <https://code.google.com/p/googlemock/w/list>`_ 

You can find here the `Gmock biicode library site <https://www.biicode.com/google/blocks/google/gmock/branches/master>`_ .

The following example shows a simple use of gmock test. You can find this and other examples in `the biicode gmock samples block <https://www.biicode.com/google/blocks/google/gmocksamples/branches/master>`_ .

.. literalinclude:: ../_static/code/cpp/examples/gmock/main.cpp
   :language: cpp
   :linenos:


**Download the file:** :download:`main.cpp <../_static/code/cpp/examples/gmock/main.cpp>` 
	
First, you need to resolve all the dependencies of this *main.cpp*
	
.. code-block:: bash
	
	$ bii find

You will see next console output after executing the command:
	
.. code-block:: bash

	$ bii cpp:run
	
	...
	
	[==========] Running 3 tests from 1 test case.
	[----------] Global test environment set-up.
	[----------] 3 tests from LeakTest
	[ RUN      ] LeakTest.LeakedMockWithExpectCallCausesFailureWhenLeakCheckingIsEnabled
	
	ERROR: this mock object (used in test LeakTest.LeakedMockWithExpectCallCausesFailureWhenLeakCheckingIsEnabled) should be deleted but never is. Its address is @0x5d29e8.
	ERROR: 1 leaked mock object found at program exit.

