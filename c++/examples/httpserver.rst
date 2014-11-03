.. _httpserver:

HTTP Server
===========

You can write and extend your own multi-platform http server with the `lasote/httpserver <https://www.biicode.com/lasote/httpserver>`_ block.

How does it work?
-----------------

It allows you to implement just a subclass of httpserver::HttpMiddleware to attend browsers or other http client requests.

A method ``call`` from your subclass object will be called with a Request* object and a Response* object.

Just modify the body and/or headers of Response object in your method and the server will do all the work.


How can I use it?
-----------------

* Just copy the files contained in the following section to a new block.
* Find the dependencies and execute your code:

.. code-block:: bash

    $ bii find
    $ cd bin
	$ #run server executable

* Open your web browser and go to *http://localhost:9000*

The code
--------

These are the files you will need in your block to have your HTTP Server up and running:

**main_server.cpp**

This file just instanciates the server and runs it with simple configuration parameters.

.. literalinclude:: /_static/code/cpp/examples/httpserver/main_server.cpp
   :language: cpp
   :linenos:
        

**my_http_middle_ware.h**

Defines your HttpMiddleware subclass.

.. literalinclude:: /_static/code/cpp/examples/httpserver/my_http_middle_ware.h
   :language: cpp
   :linenos:


**my_http_middle_ware.cpp**

 Implements HttpMiddleware subclass. You should implement the ``call`` method, reading the header variables from the request, and modifying the response to return the output.

.. literalinclude:: /_static/code/cpp/examples/httpserver/my_http_middle_ware.cpp
   :language: cpp
   :linenos:

   
**Download:** :download:`httpserver.zip </_static/code/cpp/examples/httpserver/httpserver.zip>`
 

Supported Operating Systems
---------------------------

The previous code has been tested on:

* Linux with GCC
* Windows with Mingw
* Windows with Visual Studio
* MacOS with Clang

    
More information
----------------

You can find more information in the **readme.txt** file of `lasote/httpserver <https://www.biicode.com/lasote/httpserver>`_


List of dependencies
--------------------

* `melikyan/ptypes <https://www.biicode.com/melikyan/ptypes>`_: PTypes (C++ Portable Types Library) is a simple alternative to the STL that includes multithreading and networking. It defines dynamic strings, variants, character sets, lists and other basic data types along with portable thread and synchronization objects, IP sockets and named pipes. Its main 'target audience' is developers of complex network daemons, robots or non-visual client/server applications of any kind.
* `lasote/genericipserver <https://www.biicode.com/lasote/genericipserver>`_: Generic and extensible IP server.
* `lasote/thread_jobs <https://www.biicode.com/lasote/thread_jobs>`_: Execute your tasks in threads managed by a pool.
