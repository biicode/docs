PTypes
======

PTypes is a simple alternative to the STL that includes multithreading and networking. It defines dynamic strings, character sets, lists and other basic data types along with threads, synchronization primitives, named pipes and IP sockets.

The following example demonstrates how to use `PTypes streams to write to a file <http://www.biicode.com/examples/ptypes>`_ .

**stream.cpp**

.. literalinclude:: /_static/code/cpp/examples/ptypes/stream.cpp
   :language: cpp
   :linenos:

Create a block:

.. code-block:: bash

	$ bii init my_project
	$ cd my_project
	$ bii open examples/ptypes


Compile ``stream.cpp`` file:

.. code-block:: bash

	$ bii build


Now you can run it and check it generates a file:

.. code-block:: bash

	$ cd bin
	$ ./examples_ptypes_stream

This creates a ``stmtest.txt`` file with something written inside. Just open it and you'll see its content:

.. code-block:: bash

	This is a test file


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.
