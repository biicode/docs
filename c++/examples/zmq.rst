.. _zmq_examples:

ZMQ
===

`ZMQ <http://zeromq.org/>`_  is a multiplatform high level socket library (sockets with steroids), that implements many
paradigms as multicast, broadcast, client-server, etc. in a new and brilliant way.
It is very actively developed, with a great community and used in many real projects.
Are you thinking in building your own distributed application? Don't think more, use ZMQ.

The main block is `here <http://www.biicode.com/diego/libzmq>`_, which is generated
from this `github repo <https://github.com/drodri/libzmq>`_

You can read a post about this example and the ZMQ project in
`our blog <http://blog.biicode.com/zeromq-cpp-biicode/>`_


Simple client-server with C++ binding
-------------------------------------

This example uses the C++ binding, published in `this block <http://www.biicode.com/diego/zmqcpp>`_
which in turn depends on the main libzmq block explained above.

Of course it is possible to just copy the source code files as explained in
`the blog post <http://blog.biicode.com/zeromq-cpp-biicode/>`_, if you want to check that running
them is as simple as copying the code inside a biicode project.

But as this example is `already in biicode <http://www.biicode.com/examples/zmq_cpp>`_,
it is very simple to build it, by just opening the block

.. code-block:: bash

   $ bii init clientserver
   $ cd clientserver
   $ bii open examples/zmq_cpp

If in windows, it is necessary to specify VS (it doesnt work with MinGW), otherwise, you can skip this step

.. code-block:: bash

   $ bii cpp:configure -G “Visual Studio 12”


Then build and run, first the server, then the client (you need to open another console,
in the same folder)

.. code-block:: bash

   $ bii cpp:build
   $ bin/examples_zmq_cpp_hwserver
   // another console
   $ bin/examples_zmq_cpp_hwclient


You should see how the client send "Hello"s to the server and the server respond back "World"
