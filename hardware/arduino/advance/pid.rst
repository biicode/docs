===================
Arduino PID library
===================


This library of PIDs have all the tools necessary for you to make a good control over your systems.

* Anti-WindUp.

* Mode Manual/Auto with reset.

* change the Kp, Ki and Kd parameters of the PID.

* Change the minimum output and maximum output.

Main functions
==============

* ``PID( double kp, double ki, double kd, double outMin, double outMax)``

This function is responsible for initializing all the parameters of the PID: Kp, Ki, Kd, minimum output and maximum output.

* ``float Compute(float Setpoint, float Input)``

This function return the output to the system depending on the input and the setpoint.

* ``SetTunings(double Kp, double Ki, double Kd)``

This function change the Kp, Ki and Kd parameters of the PID.

* ``SetOutputLimits(double Min, double Max)``

This function change the minimum output and maximum output of the PID.

* ``SetMode(int Mode)``

This function change the mode between automatic and manual. In automatic mode the output is calculated as a function of the PID and in manual mode the PID stops acting.

Example of use (Control a Servo)
================================

.. code-block:: cpp
	:linenos:
	
	setup(){
		PID pid_servo(6.0, 0.0, 0.0, 0, 180);
		
		...
		
	}
	
	loop(){
		input = analogRead(pin_input);
		input = map(input, 0, 1023, 0, 180);
		output = pid_servo.Compute(setpoint, input);
		servo.write(output);
		
		...
	
	}