Arduino Serial Interface
========================

With this serial interface you'll be able to send commands from a console in your PC to the arduino. You can also define your own commands for the arduino.

In this example we use a **desktop console app** and an **arduino program** to move a servo attached to the Arduino.

Send the "servo" command from our desktop app to the arduino program, and type the desired angle. The arduino board connected via USB will do the rest!

How does it work?
-----------------

Just need to use the methods ``read`` and ``write`` to communicate with the device through serial port. Those functions and the whole API definition are defined in `david/serial_arduino <https://www.biicode.com/david/serial_arduino>`_ and `david/serial_cpp <https://www.biicode.com/david/serial_cpp>`_ libraries.


How do I use it?
----------------

* You need to create **two projects** arduino_app and cpp_app, one will contain the code that will be uploaded to arduino and the other one the client application that will run in your PC.

    .. code-block:: bash
     
     $ bii init cpp_app

    .. code-block:: bash
     
     $ bii init arduino_app

* Open the examples: `C++ app code <http://www.biicode.com/examples/serial_interface_cpp>`_ goes into your pc project and `arduino code <http://www.biicode.com/examples/serial_interface_arduino>`_ goes into the arduino's project.

    .. code-block:: bash

     $ cd cpp_app
     $ bii open examples/serial_interface_cpp

    .. code-block:: bash

     $ cd arduino_app
     $ bii open examples/serial_interface_arduino


C++ code
--------

Change the **Serial Port ID** in the *main_cpp.cpp* file with the one you are using with the arduino.

**main_cpp.cpp**

.. literalinclude:: ../../_static/code/arduino/examples/serial_interface/main_cpp.cpp
   :language: cpp

Arduino code
------------

**main_arduino.cpp**

.. literalinclude:: ../../_static/code/arduino/examples/serial_interface/main_arduino.cpp
   :language: cpp


Build and run!
--------------

Execute following commands in each project:

**Arduino App**

.. code-block:: bash

    $ bii arduino:settings
    ...
    $ bii cpp:configure -t arduino
    ...
    $ bii cpp:build
    ...
    $ bii arduino:upload

**C++ App**

.. code-block:: bash

    $ bii cpp:build
    $ cd bin
    $ #run solver executable
    Enter: servo
    servo
    Enter: 180
    180
    Enter: servo
    servo
    Enter: 90
    ...

Now you can start hacking your own commands!