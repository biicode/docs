.. _wiringpi:

WiringPi: C GPIO library
========================

**WiringPi** is a C library that provides **easy access to the Raspberry Pi GPIO system**. It's designed to provide similar functionality to the Wiring package, core of the Arduino input/ouput system. The library supports the UART port, SPI, I2C and PWM. `In the project page <http://wiringpi.com/reference/>`_ you will find additional information.

+--------------------------------------------------------------------------------------------------+
| Author: `Gordon Henderson <https://projects.drogon.net/>`__                                      |
+--------------------------------------------------------------------------------------------------+
| `biicode library site <https://www.biicode.com/drogon/wiringpi>`__ |
+--------------------------------------------------------------------------------------------------+
| `WiringPi library reference page <http://wiringpi.com/reference/>`__                             |
+--------------------------------------------------------------------------------------------------+
| `WiringPi home page <http://wiringpi.com/>`__                                                    |
+--------------------------------------------------------------------------------------------------+

Now we present some examples using this library with biicode projects. The first one is a **simple blinking LED**. The second one shows how to **use the PWM output to control a motor**.

How to make a LED blink with Raspberry Pi
-----------------------------------------

With this example we will have a **LED flashing every half second using the WiringPi pin 0** (or RPi GPIO-17; it's physical location is pin 11 on the GPIO connector). You can learn more about the :ref:`Raspberry Pi GPIO pin layout in this documentation<rpigpio>`, or reading `the Embedded Linux Wiki <http://elinux.org/RPi_Low-level_peripherals>`__.

You must create a new ``project`` and a new empty ``block``, as explained in the :ref:`biicode RPi getting started guide<rpi_getting_started>`. Then, place the following source file inside your ``block``, and execute the ``bii find`` command. All needed source files will be downloaded to the ``deps`` folder of your ``project`` (you can also read the :ref:`reference for the bii find command<bii_find_command>`).

**Example: blink.c**

.. literalinclude:: /_static/code/rpi/examples/wiringpi/blink.c
   :language: cpp
   :linenos:


**Download:** :download:`blink.c </_static/code/rpi/examples/wiringpi/blink.c>`

Note that the previous file includes the `main header file of drogon's WiringPi library, available from biicode <https://www.biicode.com/drogon/drogon/wiringpi/master/1/wiringpi/wiringpi.h>`__. Now you are ready to build your program using the ``bii cpp:build`` command, and send it to your board using the ``bii rpi:send`` command, as described in the :ref:`biicode RPi getting started guide<rpi_getting_started>`. 

You must **execute this program on your Raspberry Pi with the sudo command**, because it needs to gain access to the board hardware. All needed hardware and wiring setup is explained in this `example available at the WiringPi creator's projects page <https://projects.drogon.net/raspberry-pi/gpio-examples/tux-crossing/gpio-examples-1-a-single-led/>`__.

How to use the RPi PWM output to control a motor
------------------------------------------------

With this example we will have a PWM sawtooth function on WiringPi pin 0 (:ref:`GPIO-10 <rpigpio>`). You need to **set pin 1 as PWM whit the pinMode function**: ``pinMode (1, PWM_OUTPUT)``. Once again, create a new ``project`` with an empty ``block``, as described in the :ref:`biicode RPi getting started guide<rpi_getting_started>`. Place the following example file inside your block, execute the ``bii find`` command to retreive all dependencies, and build and deply your program using the ``bii cpp:build`` and ``bii rpi:send`` commands. 

**Example: pwm.c**


.. literalinclude:: /_static/code/rpi/examples/wiringpi/pwm.c
   :language: cpp
   :linenos:

**Download:** :download:`pwm.c </_static/code/rpi/examples/wiringpi/pwm.c>`


Note that in this example we only need to include the `WiringPi main header file <https://www.biicode.com/drogon/drogon/wiringpi/master/2/wiringPi/wiringPi.h>`__. You must execute the binary on your Raspberry Pi using the ``sudo`` command.

How to use softServo to control a Servo
---------------------------------------

In this example we make use of the `WiringPi softservo.h header <https://www.biicode.com/drogon/drogon/wiringpi/master/2/wiringPi/softServo.h>`__ to control a servo. **WiringPi** provides two basic functions to control servos:

* ``softServoSetup (int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)``. With this function we provide the number of pins to be used as controllers. For more information about the GPIO go to: :ref:`Raspberry Pi GPIO Pin Layout <rpigpio>`.
* ``softServoWrite (int servoPin, int value)``. With this function we assign to a pin configured previously the value that we want to move. The values that support has a range of **-250 to 1250**. In order to understand this range, we must analyze how this function works: the function adds 1000 to the value that is passed as a parameter, so the final range is from 750 to 2.250 and the average stay in 1500, which is the default value that the library gives servo 90 degrees.

With this example we set a servo in its central position using the WiringPi pin 0 (:ref:`GPIO-17 <rpigpio>`) as a control signal. Place the following example source file inside an empty block of a new project, and execute the ``bii:find`` :ref:`(command info) <bii_find_command>` to retrieve all dependencies.

The generated binary only works on your Raspberry Pi and must be run as sudo because it works on the hardware.

**Example: servo.c**

.. literalinclude:: /_static/code/rpi/examples/wiringpi/servo.c
   :language: cpp
   :linenos:

**Download:** :download:`servo.c </_static/code/rpi/examples/wiringpi/servo.c>`
