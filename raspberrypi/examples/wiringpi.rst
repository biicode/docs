.. _wiringpi:

WiringPi: C GPIO library
========================

With the WiringPi library you can use your Raspberry Pi GPIO in a simple way. It is designed to be familiar to Arduino users.

+--------------------------------------------------------------------------------------------------+
| Author: **Gordon Henderson**                                                                     |
+--------------------------------------------------------------------------------------------------+
| `biicode library site <https://www.biicode.com/drogon/blocks/drogon/wiringpi/branches/master>`_  |
+--------------------------------------------------------------------------------------------------+
| `WiringPi library reference page <http://wiringpi.com/reference/>`_                              |
+--------------------------------------------------------------------------------------------------+
| `WiringPi home page <http://wiringpi.com/>`_                                                     |
+--------------------------------------------------------------------------------------------------+

WiringPi tutorials
------------------

How to make a led blink
^^^^^^^^^^^^^^^^^^^^^^^

With this example we will have a LED flash every half second on pin 0 using the  (:ref:`WiringPi library <rpigpio>` 17).

Remember to execute the ``bii:find`` command :ref:`(command info) <biifind>`.

The generated binary only work on your Raspberry Pi and have to run as sudo because it works on the hardware.

**Example: blink.c**

.. code-block:: cpp
	:linenos:

	#include <stdio.h>
	#include <drogon/wiringpi/wiringpi/wiringpi.h>

	// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

	#define	LED	0

	int main (void)
	{
	  printf ("Raspberry Pi blink\n") ;

	  wiringPiSetup () ;
	  pinMode (LED, OUTPUT) ;

	  for (;;)
	  {
		digitalWrite (LED, HIGH) ;	// On
		delay (500) ;		// mS
		digitalWrite (LED, LOW) ;	// Off
		delay (500) ;
	  }
	  return 0 ;
	}

How to use the PWM to control a motor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

With this example we will have a PWM sawtooth function on pin 0 (:ref:`GPIO <rpigpio>` 18).

Just have to set pin 1 as PWM whit the pinMode function `pinMode (0, PWM_OUTPUT)`.

Remember to execute ``bii:find`` :ref:`(command info) <biifind>`.

The generated binary only work on your Raspberry Pi and have to run as sudo because it works on the hardware.

**Example: pwm.c**

.. code-block:: cpp
	:linenos:

	#include <drogon/wiringpi/wiringpi/wiringpi.h>

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdint.h>

	int main (void)
	{
	  int bright ;

	  printf ("Raspberry Pi wiringPi PWM test program\n") ;

	  if (wiringPiSetup () == -1)
		exit (1) ;

	  pinMode (1, PWM_OUTPUT) ;

	  for (;;)
	  {
		for (bright = 0 ; bright < 1024 ; ++bright)
		{
		  pwmWrite (1, bright) ;
		  delay (1) ;
		}

		for (bright = 1023 ; bright >= 0 ; --bright)
		{
		  pwmWrite (1, bright) ;
		  delay (1) ;
		}
	  }

	  return 0 ;
	}

How to use softServo to control a Servo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

softServo.h
~~~~~~~~~~~

To control servos, **softServo** and **WiringPi** has two basic functions:

**int softServoSetup (int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)**

With the first function we pass the number of pins you want to use as controllers. For more information about the GPIO go to: :ref:`Raspberry Pi GPIO Pin Layout <rpigpio>`.

**softServoWrite (int servoPin, int value)**

With the second function we assign to a pin configured previously the value that we want to move. The values that support has a range of **-250 to 1250**. In order to understand this range,we must analyze how this function works.

This function adds 1000 to the value that is passed as a parameter, so the final range is from 750 to 2.250 and the average stay in 1500, which is the default value that the library gives servo 90 degrees.

**Example: servo.c**

With this example we put a servo in the center position using the pin 0 (:ref:`GPIO <rpigpio>` 17) as a control signal.

Remember to execute ``bii:find`` :ref:`(command info) <biifind>`.

The generated binary only work on your Raspberry Pi and have to run as sudo because it works on the hardware.

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
