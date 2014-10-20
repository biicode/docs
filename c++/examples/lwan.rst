lwan Web Server
===============

Lwan is a high-performance & scalable web server for glibc/Linux platforms. For more information about this project, visit their `official website <http://lwan.ws/>`_.


Hello World Example
^^^^^^^^^^^^^^^^^^^^
This example creates a very simple web service which greets you by your name.

How to replicate
-----------------
This example is `already in biicode <http://www.biicode.com/examples/lwan>`_, it's simple to run, just open the block and build it like this:

.. code-block:: bash

   $ bii init lwan
   $ cd lwan
   $ bii open examples/lwan
   $ bii cpp:build

This example needs three files, first one that defines the server configuration:

**lwan.conf**

.. literalinclude:: /_static/code/cpp/examples/lwan/lwan.conf
   :language: json
   :linenos:


The actual soruce code:

**lwan_example.c**

.. literalinclude:: /_static/code/cpp/examples/lwan/lwan_example.c
   :language: c
   :linenos:


And the Cmake lists that copies config file to bin folder:

**CMakeLists.txt**

.. literalinclude:: /_static/code/cpp/examples/lwan/CMakeLists.txt
   :language: cmake
   :linenos:


**Download:**
:download:`lwan.zip </_static/code/cpp/examples/lwan/lwan.zip>`


Now, run the hello example.

.. code-block:: bash

   $ cd bin
   $ ./examples_lwan_lwan_example

You can see the server running:


.. code-block:: bash


		62528 lwan-job.c:76 lwan_job_thread_init() Initializing low priority job thread.
		62528 lwan-response.c:75 lwan_response_init() Initializing default response.
		62528 lwan-tables.c:44 lwan_tables_init() Uncompressing MIME type table.
		62528 lwan.c:58 lwan_module_init() Initializing module registry.
		62528 lwan.c:73 lwan_module_register() Registering module "serve_files".
		62528 lwan.c:73 lwan_module_register() Registering module "redirect".
		62528 lwan.c:360 setup_from_config() Loading configuration file: examples_lwan_lwan_example.conf.
		62528 lwan.c:476 lwan_init() Initializing lwan web server.
		62528 lwan.c:487 lwan_init() Using 2 threads, maximum 2048 sockets per thread.
		62528 lwan-thread.c:393 lwan_thread_init() Initializing threads.
		62528 lwan-socket.c:212 lwan_socket_init() Initializing sockets.
		62528 lwan-socket.c:197 _setup_socket_normally() Listening on http://0.0.0.0:8080.
		62528 lwan.c:561 lwan_main_loop() Ready to serve.
		62531 lwan-thread.c:290 _thread_io_loop() Starting IO loop on thread #2.
		62530 lwan-thread.c:290 _thread_io_loop() Starting IO loop on thread #1.


Now you can go to any browser and navigate to http://localhost:8080?name=fred