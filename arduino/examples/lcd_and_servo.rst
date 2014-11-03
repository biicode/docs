Servo and lcd 2x16
==================

With this example you will display the angle of a servo into a LCD 2x16. It uses the Servo, ``servo.h``, library to control the servo and the Liquidcrystal, ``liquidcrystal.h``, library to display the angle on the LCD.

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