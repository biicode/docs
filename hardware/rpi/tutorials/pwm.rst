PWM
===

With this example we will have a PWM sawtooth function on pin 0 (:ref:`GPIO <rpigpio>` 18).

Just have to set pin 1 as PWM whit the pinMode function `pinMode (0, PWM_OUTPUT)`.

Remember to execute ``bii:find`` :ref:`(command info) <biifind>`.

The generated binary only work on your Raspberry Pi and have to run as sudo because it works on the hardware

Example: pwm.c
----------------

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