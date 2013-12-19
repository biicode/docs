Servos
======

softServo.h
-----------

To control servos, **softServo** and **WiringPi** has two basic functions:

**int softServoSetup (int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)**

With the first function we pass the number of pins you want to use as controllers. For more information about the GPIO go to: :ref:`Raspberry Pi GPIO Pin Layout <rpigpio>`.

**softServoWrite (int servoPin, int value)**

With the second function we assign to a pin configured previously the value that we want to move. The values that support has a range of **-250 to 1250**. In order to understand this range,we must analyze how this function works.

This function adds 1000 to the value that is passed as a parameter, so the final range is from 750 to 2.250 and the average stay in 1500, which is the default value that the library gives servo 90 degrees.

Example: servo.c
----------------

With this example we put a servo in the center position using the pin 0 (:ref:`GPIO <rpigpio>` 17) as a control signal.

.. code-block:: cpp
	:linenos:

	#include <stdio.h>
	#include <errno.h>
	#include <string.h>

	#include <drogon/wiringpi/wiringpi/wiringpi.h>
	#include <drogon/wiringpi/wiringpi/softservo.h>

	int main ()
	{
	  if (wiringPiSetup () == -1)
	  {
		fprintf (stdout, "oops: %s\n", strerror (errno)) ;
		return 1 ;
	  }

	  softServoSetup (0, 1, 2, 3, 4, 5, 6, 7) ;

	  softServoWrite (0,  500) ;
	/*
	  softServoWrite (1, 1000) ;
	  softServoWrite (2, 1100) ;
	  softServoWrite (3, 1200) ;
	  softServoWrite (4, 1300) ;
	  softServoWrite (5, 1400) ;
	  softServoWrite (6, 1500) ;
	  softServoWrite (7, 2200) ;
	*/

	  for (;;)
		delay (10) ;

	}