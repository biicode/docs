Code your christmas with Raspberry Pi and biicode
=================================================

.. raw:: html

	<iframe width="640" height="480" src="//www.youtube.com/embed/S_oIqUt_CBo" frameborder="0" allowfullscreen></iframe>

You just need paper, scissors, a servo, a Raspberry Pi and biicode!
---------------------------------------------------

* Sing Up `biicode <https://www.biicode.com/>`_
* :ref:`installation <installation>`
* To use your :ref:`Raspberry pi with biicode <raspberry_pi>`, you have here all the info.
* To move the servo, we use :ref:`wiringpi<wiringpi>` that is already ready to be used in biicode.

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

	  softServoWrite (0,  500);
	  
	  int range = 500;
	  int vel = 10;

	  for (;;)
		softServoWrite (0,  range);
		range += vel;
		if (range > 1250 || range < -250)
		{
			vel = -vel;
		{
		delay (10);

	}

Choose the paper doll that you like
-----------------------------------

`cubeecraft heisenberg <http://www.cubeecraft.com/cubee/heisenberg>`_

+-----------------------------------------+------------------------------------------+
|.. image:: raspberry_pi_christmas/01.jpg | .. image:: raspberry_pi_christmas/02.jpg |
+-----------------------------------------+------------------------------------------+

Mount it with some small modifications
--------------------------------------

.. image:: raspberry_pi_christmas/1.jpg

Paste the head to the servo and put the servo in the body
---------------------------------------------------------

+----------------------------------------+-----------------------------------------+
|.. image:: raspberry_pi_christmas/2.jpg | .. image:: raspberry_pi_christmas/3.jpg |
+----------------------------------------+-----------------------------------------+
|.. image:: raspberry_pi_christmas/4.jpg | .. image:: raspberry_pi_christmas/6.jpg |
+----------------------------------------+-----------------------------------------+
|.. image:: raspberry_pi_christmas/7.jpg | .. image:: raspberry_pi_christmas/8.jpg |
+----------------------------------------+-----------------------------------------+

Connected to the 5v , GPIO17 and 0v pins
----------------------------------------

:ref:`GPIO Reference <rpigpio>`.

+-------+--------+
|Signal | GPIO17 |
+-------+--------+
| \+    |     5v | 
+-------+--------+
| \-    |     0v |
+-------+--------+

+------------+------------------+------------+
| GPIO Rev.1 | GPIO Pin Layout  | GPIO Rev.2 |
+------------+------------------+------------+
| .. image:: ../_static/img/rpi/gpios.png    |
+--------------------------------------------+

.. image:: raspberry_pi_christmas/servo.jpg

