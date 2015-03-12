========================================
HTTP Server: how to control a led by web
========================================

This example use the :ref:`HTTP Server <httpserver>` library to control a LED.

How can i use it?
-----------------
* Just copy the following files to a new block.
* Find the dependencies and execute your code:

Once you have the code, invoke ``bii find`` to resolve external dependencies. Then, build and run in your Raspberry Pi as usual. Remember, the generated binary only work on your Raspberry Pi and have to run as sudo because it works on the hardware:

.. code-block:: bash

	$ bii find
	...
	$ bii configure --toolchain=rpi
	...
	$ bii build
	...
	$ bii rpi:send
	...
	$ bii rpi:ssh
	...
	pi@raspberrypi ~ $ cd [project_name]
	pi@raspberrypi ~/[project_name] $ ls
	[binary_name]
	pi@raspberrypi ~/[project_name] $ sudo ./[binary_name]

* Open your web browser and go to *http://localhost:9000*

.. image:: /_static/img/rpi/examples/httpserverrpi.png

main_server.cpp
^^^^^^^^^^^^^^^^
This file just instances the server and run it with a simple configuration parameters.

.. literalinclude:: /_static/code/rpi/examples/httpserver/main_server.cpp
   :language: cpp
   :linenos:



my_http_middle_ware.h
^^^^^^^^^^^^^^^^^^^^^

Defines your HttpMiddleware subclass.

.. literalinclude:: /_static/code/rpi/examples/httpserver/my_http_middle_ware.h
   :language: cpp
   :linenos:


my_http_middle_ware.cpp
^^^^^^^^^^^^^^^^^^^^^^^

Implements HttpMiddleware subclass.
With the call method you can turn on or turn off a LED using the request info of the request.

.. literalinclude:: /_static/code/rpi/examples/httpserver/my_http_middle_ware.cpp
   :language: cpp
   :linenos:


led.h
^^^^^

Defines a Led class for turn on/off the light.

.. literalinclude:: /_static/code/rpi/examples/httpserver/led.h
   :language: cpp
   :linenos:

led.cpp
^^^^^^^

Implements the Led class

.. literalinclude:: /_static/code/rpi/examples/httpserver/led.cpp
   :language: cpp
   :linenos:

   
**Download:** :download:`httpserver.zip </_static/code/rpi/examples/httpserver/httpserver.zip>`
