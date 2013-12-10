Blink
=====

With this example we will have a LED flash every half second on pin 0 (:ref:`GPIO <rpigpio>` 17).

Example: blink.c
----------------

.. code-block:: cpp
	:linenos:

	#include <stdio.h>
	#include <wiringPi.h>

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