================================
How to move your code to biicode
================================

If you want to use your code into biicode, you just put the following lines in all yours files:

.. code-block:: cpp

	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif
	
An change the ``.ino`` files to ``.cpp``.