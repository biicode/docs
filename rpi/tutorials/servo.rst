Servos with WiringPi
===================

To control servos, **softServo** and **WiringPi** has two basic functions:

**int softServoSetup (int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)**

With the first function we pass the number of pins you want to use as controllers. For more information about the GPIO go to: :ref:`Raspberry Pi GPIO Pin Layout <rpigpio>`.

.. code-block:: cpp
	:linenos:

	int softServoSetup (int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)
	{
	  int servo ;

	  if (p0 != -1) { pinMode (p0, OUTPUT) ; digitalWrite (p0, LOW) ; }
	  ...
	  if (p7 != -1) { pinMode (p7, OUTPUT) ; digitalWrite (p7, LOW) ; }

	  pinMap [0] = p0 ;
	  ...
	  pinMap [7] = p7 ;

	  for (servo = 0 ; servo < MAX_SERVOS ; ++servo)
		pulseWidth [servo] = 1500 ;		// Mid point
	  
	  return piThreadCreate (softServoThread) ;
	}

**softServoWrite (int servoPin, int value)**

With the second function we assign to a pin configured previously the value that we want to move. The values that support has a range of **-250 to 1250**. In order to understand this range,we must analyze how this function works.

This function adds 1000 to the value that is passed as a parameter, so the final range is from 750 to 2.250 and the average stay in 1500, which is the default value that the library gives servo 90 degrees.

.. code-block:: cpp
	:linenos:

	void softServoWrite (int servoPin, int value)
	{
	  int servo ;

	  servoPin &= 63 ;

	  /**/ if (value < -250)
		value = -250 ;
	  else if (value > 1250)
		value = 1250 ;

	  for (servo = 0 ; servo < MAX_SERVOS ; ++servo)
		if (pinMap [servo] == servoPin)
		  pulseWidth [servo] = value + 1000 ; // uS
	}
**servo.c**

.. code-block:: cpp
	:linenos:

	#include <stdio.h>
	#include <errno.h>
	#include <string.h>

	#include <wiringPi.h>
	#include <softServo.h>

	int main ()
	{
	  if (wiringPiSetup () == -1)
	  {
		fprintf (stdout, "oops: %s\n", strerror (errno)) ;
		return 1 ;
	  }

	  softServoSetup (0, 1, 2, 3, 4, 5, 6, 7) ;

	  softServoWrite (0,  0) ;
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