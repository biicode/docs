libuv 
=====

`libuv <https://github.com/joyent/libuv>`_ i a multi-platform library for asynchronous, event-driven style of programming. It offers core utilities like timers, non-blocking networking support, asynchronous file system access, child processes and more.

libuv libraries available at biicode are:

  * libuv v0.10 at `lasote/libuv (v0.10) <https://www.biicode.com/lasote/lasote/libuv/v0.10>`_.

  * libuv v0.11 at `lasote/libuv (v0.11) <https://www.biicode.com/lasote/lasote/libuv/v0.11>`_.

  * libuv v1.x at `lasote/libuv (v1.x) <https://www.biicode.com/lasote/lasote/libuv/v1.x>`_.

Blocks are generated for this `github repo <https://github.com/lasote/libuv-1>`_.

Http client/server application
------------------------------

In this example we'll show a **Http client/server** application.

Creating a new project
^^^^^^^^^^^^^^^^^^^^^^

This example is already in biicode at `examples/libuv(v0.11) <https://www.biicode.com/examples/examples/libuv/v0.11>`_. So just open the block:

.. code-block:: bash

 $ bii init libuvproject
 $ cd libuvproject
 $ bii open examples/libuv(v.11)

Check dependencies
^^^^^^^^^^^^^^^^^^

Let's check the dependecies of this example:

.. code-block:: bash

 $ bii deps
 INFO: Processing changes...
 examples/libuv depends on:
       lasote/libuv(v0.11): 2
          include/uv.h
       system:
          stdio.h
          stdlib.h
          string.h

Now take a look at *biicode.conf* file:

.. code-block:: text
 
 [requirements]
     lasote/libuv (v0.11): 2

 [parent]
     examples/libuv(v0.11): 1

 [includes]
     uv.h: lasote/libuv/include


**Note** that the original ``[includes]`` are mapped, so you just have to ``#include "uv.h"`` to add libuv to the project.

Build the project
^^^^^^^^^^^^^^^^^

Now execute **bii build** to build the project.

.. code-block:: bash
 
 $ bii build

Go to bin directory and execute:

.. code-block:: bash
 
 $ cd bin
 $ examples_libuv_network_server.exe

And in other terminal/console:

.. code-block:: bash
 
 $ cd bin
 $ examples_libuv_network_client.exe

And you'll see the next output:

+----------------------+-------------------------+
| Server               | Client                  |
+======================+=========================+
|Connection ok!        |  Writing: Ping...       |
|                      |                         |
|Received: Ping...     |  Write ok!              |
|                      |                         |
|Sending: Ping... Pong!|  Received: Ping... Pong!|
|                      |                         |
|Closed ok!            |                         |
+----------------------+-------------------------+

Hey! That's your ping-pong client/server application!

Change libuv's version
----------------------

You can change among libuv's versions with just a single mod in *biicode.conf* file:

* To depend on **libuv v0.10**:

    .. code-block:: text

     [requirements]
         lasote/libuv (v0.10): 3

* To depend on **libuv v0.11**:

    .. code-block:: text

     [requirements]
         lasote/libuv (v0.11): 2

* To depend on **libuv v1.x**:

    .. code-block:: text

     [requirements]
         lasote/libuv (v1.x): 7

Try the example above switching versions!

Got any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_, visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.