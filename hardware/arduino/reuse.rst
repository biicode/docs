=================================================
The best part: share and reuse code with biicode!
=================================================
**And now, the best part, check how easy is to share and reuse code using the biicode platform.**

What you need?
--------------

* Arduino (any model)


The Blink library
-----------------

Suppose that based on the blinking example, you have in your block three files, a ``Blink_lib`` class and a main file ``blink.cpp`` which uses the first class. This could be such that:

**blink_lib class**

.. code-block:: cpp
	
	//blink_lib.h
	#include <stdint.h>

	/**
	 * Setup for blinking.
	 *
	 * @param pin - pin number
	 **/
	void blink_setup(uint8_t pin=13);

	/**
	 * Blink a single time for the specified duration.
	 *
	 * @param duration - duration in miliseconds
	 * @param pin      - pin number
	 **/
	void blink(unsigned long duration, uint8_t pin=13);

.. code-block:: cpp
	
	//blink_lib.cpp
	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif
	
	#include "blink_lib.h"
	
	void blink_setup(uint8_t pin) {
	  pinMode(pin, OUTPUT);     
	}
	
	void blink(unsigned long duration, uint8_t pin) {
	  digitalWrite(pin, HIGH);   // set the LED on
	  delay(duration);           // wait for a second
	  digitalWrite(pin, LOW);    // set the LED off
	  delay(duration);           // wait for a second
	}

**blink.cpp**	
	
.. code-block:: cpp
	
	//blink.cpp
	/*
	  Blink
	  Turns on an LED on for one second, then off for one second, repeatedly.
	  Example uses a static library to show off generate_arduino_library().
	 
	  This example code is in the public domain.
	 */
	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif

	#include "blink_lib.h"

	void setup() {                
		blink_setup(); // Setup for blinking
	}

	void loop() {
		blink(1000); // Blink for a second
	}

Publish your code
-----------------
It is probable that you might need to reuse the ``Blink_lib`` class  in other projects or you might want to share with the community so other Arduino users can reuse it easily in their projects.
This can be achieved with biicode, all you need to do is to publish your code:

.. code-block:: bash

	$ bii work
	...
	$ bii publish
	Introduce TAG: STABLE
	Introduce msg: Blinker class working (or whatever message you like)

Assuming that your user name is *your_user_name* and the block is named *your_block*, you could navigate to http://www.biicode.com, go to your profile and see your code there.

Reuse it!
---------

Reusing your ``Blink_lib`` class in other projects or blocks is straightforward. All you need to do is to include and do a *find*. 
You can use the Blink_lib class wherever you want in your own code, this is only an example.

.. code-block:: cpp
	:emphasize-lines: 7,8,9,10
	
	//blink.cpp
	
	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif

	#include "your_user_name/your_block/blink_lib.h"

	void setup() {                
		blink_setup(); // Setup for blinking
	}

	void loop() {
		blink(2000); // Blink for a two seconds
	}

Assuming that your user name is *your_user_name* and the block where you published the code was named *your_block*, you could navigate to http://www.biicode.com, go to your profile and see your code there.

Once you have the code, invoke ``find`` to resolve external dependencies, so the Blink_lib class is retrieved. Then, build and upload in your Arduino as usual. Not forget check your Arduino settings to upload correctly:

.. code-block:: bash

	$ bii find
	...
	$ bii arduino:build
	...
	$ bii arduino:upload

	Uploading...[ 90%] Built target uno_CORE
	[100%] Built target your_user_name_my_block_blink
	Scanning dependencies of target your_user_name_my_block_blink-upload

	avrdude.exe: AVR device initialized and ready to accept instructions

	Reading | ################################################## | 100% 0.00s

	avrdude.exe: Device signature = 0x1e950f
	avrdude.exe: reading input file "your_user_name_my_block_blink.hex"
	avrdude.exe: input file your_user_name_my_block_blink.hex auto detected as Intel Hex
	avrdude.exe: writing flash (1116 bytes):

	Writing | ################################################## | 100% 0.18s

	avrdude.exe: 1116 bytes of flash written
	avrdude.exe: reading input file "your_user_name_my_block_blink.eep"
	avrdude.exe: writing eeprom (0 bytes):

	Writing | ################################################## | 100% 0.00s

	avrdude.exe: 0 bytes of eeprom written

	avrdude.exe: safemode: Fuses OK

	avrdude.exe done.  Thank you.

	[100%] Built target your_user_name_my_block_blink-upload


	