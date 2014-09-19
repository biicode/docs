SQLite
======

SQLite is a software library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine. SQLite is the most widely deployed SQL database engine in the world. For more information about this library, visit their `official website <http://www.sqlite.org/>`_.

You can find here the `SQLite library site <http://www.biicode.com/sqlite/sqlite/sqlite/master/5>`_ .

The following example how-to use the SQLite++ wrapper. You can find this example in `the biicode SQLite samples block <http://www.biicode.com/examples/sqlite>`_ .

**main_mili.cpp**

.. literalinclude:: /_static/code/cpp/examples/sqlite/main.cpp
   :language: cpp
   :linenos:

**Download:**
:download:`sqlite_example.zip </_static/code/cpp/examples/sqlite/sqlite_example.zip>`

Create a block:

.. code-block:: bash

	$ bii new examples/sqlite


Unzip those files in your block, then you need to resolve all the dependencies of this ``main.cpp``. Then you can compile it

.. code-block:: bash

	$ bii find
	$ bii cpp:build


You will see next console output after executing the command:

.. code-block:: bash

	$ cd bin
	$ bin $ ./examples_sqlite_main
	SQLite database file 'examples/sqlite/example.db3' opened successfully
	SQLite table 'test' exists=1
	execAndGet=second line
	SQLite statement 'SELECT id as test_id, value as test_val, weight as test_weight FROM test WHERE weight > ?' compiled (3 	columns in the result)
	binded with integer value '2' :
	aliased result ["test_id", "test_val", "test_weight"]
	row (1, "first word" 10 bytes, 2.3)
	row (2, "second line" 11 bytes, 6.7)
	row (3, "and a last one" 14 bytes, 9.5)
	row (4, "" 0 bytes, 18)
	...
