Servo and lcd 2x16
==================

With this example we display the angle of a servo into a LCD. We use the servo.h library to control the servo and the liquidcrystal.h library to display the angle of the servo into a LCD 2x16.

What do we need?
----------------

* One standard servo.
* One display lcd 2x16.
* One potentiometer.

Scheme
------

.. image:: ../../_static/img/arduino/lcd_servo.png

The code: Display the servo angle into a LCD 
--------------------------------------------

**lcd_and_servo.cpp**

.. literalinclude:: ../../_static/code/arduino/examples/lcd_and_servo/lcd_and_servo.cpp
   :language: cpp

**Download**: :download:`lcd_and_servo.cpp <../../_static/code/arduino/examples/lcd_and_servo/lcd_and_servo.cpp>`