How to adapt your code
======================

This section describes **how to adapt your current Arduino projects to bicode**. The adaptation steps depend on the complexity of your project: whether it contains one single ``.ino`` file, or multiple ``.ino`` files. Simply follow the instructions contained in the section that best suits to your current project configuration.

1. Projects with one single .ino file
-------------------------------------

This is the simplest case. Adaptation is almost inmediate:

**General rules**

#. **Change** your ``.ino`` file **extension** to ``.cpp``. For example, the file ``sweep.ino`` would become ``sweep.cpp``.
#. **Include** the ``Arduino.h`` **library** in your code with the following line at the beginning of your file:

	.. code-block:: cpp

		#include "Arduino.h"

#. **Rewrite** the Arduino core library includes to **comply with the biicode includes format**. For the arduino core libraries this format is ``arduino/libraries/<path_to_file>`` (in general, all included files in biicode projects must follow the pattern ``<username>/<blockname>/<path_to_file>``, so here we are including files from the ``libraries`` block of the biicode ``arduino`` user). 

	For instance, if you are using the ``Servo.h`` library, you should write the following include directive:

	.. code-block:: cpp

		#include "arduino/libraries/servo/servo.h"

	Please, note that all letters are **lowercase**. You can browse `all available Arduino core libraries available in biicode <https://www.biicode.com/arduino/libraries>`_.
		
#. Declare all function prototypes at the beginning of your code. For example: ``void servo_loop();``.

Following there is an example of a full ``.ino`` file adaptation:

.. container:: tabs-section
	
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Original sweep.ino file

		.. code-block:: cpp
			:emphasize-lines: 1,12

			#include <Servo.h>

			void setup(){
			}

			void loop(){
			  servo_loop(9);
			}

			void servo_loop(int pin) {
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1){
				myservo.write(pos);
				delay(15);
			  }
			}

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Adapted sweep.cpp file

		.. code-block:: cpp
			:emphasize-lines: 1, 2, 4


			#include "Arduino.h"
			#include <arduino/libraries/servo/servo.h>

			void servo_loop();
			 
			void setup(){ 
			} 
			 
			void loop(){
			  servo_loop(9);
			}

			void servo_loop(int pin){
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1){
				myservo.write(pos);
				delay(15);
			  }
			}



2. Projects with multiple .ino files
------------------------------------

**General rules**

#. Change the extension to the main file to ``.cpp``. Also, change the extension of other ``.ino`` files to ``.h``. For example, if your project has the following layout, being ``sweep.ino`` the main file:

	.. code-block:: text

	   +-- sweep
	   |    +-- sweep.ino
	   |    +-- servo_functions.ino

	You should modify the extensions to the following biicode-compliant layout and file names:

	.. code-block:: text

	   +-- <biicode_block_name>
	   |    +-- sweep.cpp
	   |    +-- servo_functions.h

   Note that ``sweep.ino`` has been renamed to ``sweep.cpp``, and ``servo_functions.ino`` has been renamed to ``servo_functions.h``.

#. **Include** the ``Arduino.h`` **library** in your code with the following line at the beginning of your file:

	.. code-block:: cpp

		#include "Arduino.h"

#. **Rewrite** the Arduino core library includes to **comply with the biicode includes format**. For the arduino core libraries this format is ``arduino/libraries/<path_to_file>`` (in general, all included files in biicode projects must follow the pattern ``<username>/<blockname>/<path_to_file>``, so here we are including files from the ``libraries`` block of the biicode ``arduino`` user). 

	For instance, if you are using the ``Servo.h`` library, you should write the following include directive:

	.. code-block:: cpp

		#include "arduino/libraries/servo/servo.h"

	Please, note that all letters are **lowercase**. You can browse `all available Arduino core libraries available in biicode <https://www.biicode.com/arduino/libraries>`_.

#. Declare the function prototypes, if you need, at the beginning of your code. For example ``void servo_loop();``.

Following you will find an example of a full adaptation of an Arduino project containing multiple files. First tab shows the original project, while the second one displays the easy adaptation described befor. The third tab shows an alternative, more advanced adaptation, recommended for complex projects, and as a best practice for the general structure of your projects:

.. container:: tabs-section
	
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Original sweep Arduino project

		**sweep.ino**

		.. code-block:: cpp

			void setup(){
			}

			void loop(){
			  servo_loop(9);
			}

		**servo_functions.ino**

		.. code-block:: cpp
			:emphasize-lines: 1

			#include <Servo.h>

			void servo_loop(int pin){
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1){
				myservo.write(pos);
				delay(15);
			  }
			}

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Easy adaptation

		**sweep.cpp**

		.. code-block:: cpp
			:emphasize-lines: 1

			#include "servo_functions.h"

			void setup(){
			}

			void loop(){
			  servo_loop(9);
			}

		**servo_functions.h**

		.. code-block:: cpp
			:emphasize-lines: 1,2

			#include "Arduino.h"
			#include <arduino/libraries/servo/servo.h>

			void servo_loop(int pin){
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1){
				myservo.write(pos);
				delay(15);
			  }
			}

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			Advanced adaptation

		This is an alternative way to adapt your code to biicode. It is recommended as a **best practice** that splits your code into declarations, or interface, and implementations. This separation between **interface** (contained in *header* files, with ``.h`` extension) and **implementation** (contained in ``.cpp`` files) provides many benefits:

		* The header declares **what** the code does, while the implementation contains **how** to do it. This is somehow a nice way of structuring your code.
		* Compilation times are reduced, and also the need to recompile all your code when only some parts of the implementation have changed.

		**sweep.cpp**

		.. code-block:: cpp
			:emphasize-lines: 1

			#include "servo_functions.h"

			void setup(){
			}

			void loop(){
			  servo_loop(9);
			}

		**servo_functions.h**

		.. code-block:: cpp
			:emphasize-lines: 1

			#include "Arduino.h"

			void servo_loop(int pin);

		**servo_functions.cpp**

		.. code-block:: cpp
			:emphasize-lines: 1,2

			#include "servo_functions.h"
			#include <arduino/libraries/servo/servo.h>

			void servo_loop(int pin){
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1){
				myservo.write(pos);
				delay(15);
			  }
			}
