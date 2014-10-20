PTypes
======

PTypes is a simple alternative to the STL that includes multithreading and networking. It defines dynamic strings, character sets, lists and other basic data types along with threads, synchronization primitives, named pipes and IP sockets.

The following example demonstrates how to use `PTypes streams to write to a file <http://www.biicode.com/examples/ptypes>`_ .

**stream.cpp**

.. literalinclude:: /_static/code/cpp/examples/ptypes/stream.cpp
   :language: cpp
   :linenos:

**Download:**
:download:`stream.cpp </_static/code/cpp/examples/ptypes/stream.cpp>`

Create a block:

.. code-block:: bash

	$ bii init my_project
	$ cd my_project
	$ bii new user/ptypes


Copy stream.cpp in your block (ptypes folder), and resolve ``stream.cpp`` dependencies. Then you can compile it:

.. code-block:: bash

	$ bii find
	$ bii cpp:build


Now you can run it and check it generates a file:

.. code-block:: bash

	$ cd bin
	$ ./examples_ptypes_stream
	$ cat stmtest.txt
	This is a test file
