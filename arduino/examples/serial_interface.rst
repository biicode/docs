Arduino Serial Interface
========================

With this serial interface you can define your own commands for the arduino. You will be able to send commands from a console in your PC to the arduino.
In this example we use a desktop console app to move a servo attached to the Arduino, we just have to send the "servo" command  and the angle.

How does it work?
-----------------

Just need to use the methods ``read`` and ``write`` to communicate with the device through serial port. Those functions are defined in `david/serial_arduino <https://www.biicode.com/david/blocks/david/serial_arduino/branches/master>`_ and `david/serial_cpp <https://www.biicode.com/david/blocks/david/serial_cpp/branches/master>`_ libraries.
You can find the whole api definition in the blocks web!

How do I use it?
-----------------

* You need to create two projects arduino_app and cpp_app, one will contain the code that will be uploaded to arduino and the other one the client application that will run in your PC.
* Copy the example code, C++ app code goes into your pc project and arduino code goes into the project with arduino code.

C++ code
--------

At this moment, the following code is only compatible with Windows OS.

**main_cpp.cpp**

.. literalinclude:: ../../_static/code/arduino/examples/serial_interface/main_cpp.cpp
   :language: cpp

**Download**: :download:`main_cpp.cpp <../../_static/code/arduino/examples/serial_interface/main_cpp.cpp>`

Arduino code
------------

**main_arduino.cpp**

.. literalinclude:: ../../_static/code/arduino/examples/serial_interface/main_arduino.cpp
   :language: cpp

**Download**: :download:`main_arduino.cpp <../../_static/code/arduino/examples/serial_interface/main_arduino.cpp>`

Just run your code!
-------------------

Execute following commands in each project:

**Arduino App**

.. code-block:: bash

    $ bii find
    $ bii arduino:upload

**C++ App**

.. code-block:: bash

    $ bii find
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
