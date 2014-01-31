===================
Arduino PID library
===================

This library of PIDs have all the tools necessary that you need to make a good control over your systems.

Characteristic of the library:

* Anti-WindUp.
* Mode Manual/Auto with reset.
* Change the Kp, Ki and Kd parameters of the PID.
* Change the minimum output and maximum output.

How does it work?
=================

Just need to use the methods ``Compute`` to control your devices. These are defined in `david/pid_arduino <https://www.biicode.com/david/blocks/david/pid_arduino/branches/master>`_  library.
You can find the whole library definition in the blocks web!

How can i use it?
=================

* You need include ``david/pid_arduino/pid.h`` in your code.
* Create a pid object with the paraneters of the controller and their max and min limits.
* ``Compute`` returns the correct value you need for your device in function of the input and the setpoint.

The code: Control a Servo
=========================

This code is an example of the layout of your code. We read the input and define the setpoint value. Our PID calcule the correct output and return it, you just need to pass this value to the servo.

**main.cpp**

.. code-block:: cpp
	:linenos:
	
	void setup(){
		PID pid_servo(6.0, 0.0, 0.0, 0, 180);
		
		...
		
	}
	
	void loop(){
		input = analogRead(pin_input);
		input = map(input, 0, 1023, 0, 180);
		output = pid_servo.Compute(setpoint, input);
		servo.write(output);
		
		...
	
	}
	
**mains.bii**

biicode use this file to define main.cpp like a main file. You have all the :ref:`info about mains.bii here <mains-bii>`. You need to create this file into [BLOCK_NAME]/bii/mains.bii

.. code-block:: text
	:linenos:

	main.cpp