.. _wiringpi:

WiringPi: C GPIO library
========================

**WiringPi** is a C library that provides **easy access to the Raspberry Pi GPIO system**. It's designed to provide similar functionality to the Wiring package, core of the Arduino input/ouput system. The library supports the UART port, SPI, I2C and PWM. `In the project page <http://wiringpi.com/reference/>`_ you will find additional information.

+--------------------------------------------------------------------------------------------------+
| Author: `Gordon Henderson <https://projects.drogon.net/>`__                                      |
+--------------------------------------------------------------------------------------------------+
| `biicode library site <https://www.biicode.com/drogon/blocks/drogon/wiringpi/branches/master>`__ |
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

Note that the previous file includes the `main header file of drogon's WiringPi library, available from biicode <https://www.biicode.com/drogon/blocks/drogon/wiringpi/branches/master/versions/1/cells/wiringpi/wiringpi.h>`__. Now you are ready to build your program using the ``bii cpp:build`` command, and send it to your board using the ``bii rpi:send`` command, as described in the :ref:`biicode RPi getting started guide<rpi_getting_started>`. 

You must **execute this program on your Raspberry Pi with the sudo command**, because it needs to gain access to the board hardware. All needed hardware and wiring setup is explained in this `example available at the WiringPi creator's projects page <https://projects.drogon.net/raspberry-pi/gpio-examples/tux-crossing/gpio-examples-1-a-single-led/>`__.

How to use the RPi PWM output to control a motor
------------------------------------------------

With this example we will have a PWM sawtooth function on WiringPi pin 0 (:ref:`GPIO-10 <rpigpio>`). You need to **set pin 1 as PWM whit the pinMode function**: ``pinMode (1, PWM_OUTPUT)``. Once again, create a new ``project`` with an empty ``block``, as described in the :ref:`biicode RPi getting started guide<rpi_getting_started>`. Place the following example file inside your block, execute the ``bii find`` command to retreive all dependencies, and build and deply your program using the ``bii cpp:build`` and ``bii rpi:send`` commands. 

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

Note that in this example we only need to include the `WiringPi main header file <https://www.biicode.com/drogon/blocks/drogon/wiringpi/branches/master/versions/1/cells/wiringpi/wiringpi.h>`__. You must execute the binary on your Raspberry Pi using the ``sudo`` command.

How to use softServo to control a Servo
---------------------------------------

In this example we make use of the `WiringPi softservo.h header <https://www.biicode.com/drogon/blocks/drogon/wiringpi/branches/master/versions/1/cells/wiringpi/softservo.h>`__ to control a servo. **WiringPi** provides two basic functions to control servos:

* ``softServoSetup (int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)``. With this function we provide the number of pins to be used as controllers. For more information about the GPIO go to: :ref:`Raspberry Pi GPIO Pin Layout <rpigpio>`.
* ``softServoWrite (int servoPin, int value)``. With this function we assign to a pin configured previously the value that we want to move. The values that support has a range of **-250 to 1250**. In order to understand this range, we must analyze how this function works: the function adds 1000 to the value that is passed as a parameter, so the final range is from 750 to 2.250 and the average stay in 1500, which is the default value that the library gives servo 90 degrees.

With this example we set a servo in its central position using the WiringPi pin 0 (:ref:`GPIO-17 <rpigpio>`) as a control signal. Place the following example source file inside an empty block of a new project, and execute the ``bii:find`` :ref:`(command info) <bii_find_command>` to retrieve all dependencies.

The generated binary only works on your Raspberry Pi and must be run as sudo because it works on the hardware.

**Example: servo.c**

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
