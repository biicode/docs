Servo and lcd 2x16
==================

With this example we display the angle of a servo into a LCD. We use the servo.h library to control the servo and the liquidcrystal.h library to display the angle of the servo into a LCD 2x16.

What do we need?
----------------

* Standard servo.
* Display lcd 2x16.
* Potentiometer.

Scheme
------

.. image:: ../../_static/img/arduino/lcd_servo.png

The code: Display the servo angle into a LCD 
--------------------------------------------

**main.cpp**

.. code-block:: cpp
	:linenos:
	
	#include "Arduino.h"
	#include <arduino/libraries/liquidcrystal/liquidcrystal.h>
	#include <arduino/libraries/servo/servo.h> 
	LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
	Servo myservo;

	void write_angle_lcd(int pos){
	    lcd.setCursor(0, 1);
	    lcd.print(pos);
	    lcd.print(" ");
	}

	void setup() {
	  myservo.attach(10);
	  lcd.begin(16, 2);
	  lcd.print("SERVO ANGLE");
	  lcd.setCursor(0, 1);
	}
	void loop() {
	  int pos; 
	  for(pos = 0; pos <= 180; pos += 1)
	  {
	    myservo.write(pos);
	    write_angle_lcd(pos);
	    delay(50);
	  } 
	  for(pos = 180; pos >= 0; pos -= 1)
	  {                       
	    myservo.write(pos);
	    write_angle_lcd(pos);
	    delay(50);
	  } 
	}