How to adapt your code
======================

**Adapt your current Arduino projects and sketches to biicode**. Next steps depend on whether your project contains one single ``.ino`` file, or multiple ``.ino`` files. Just follow the guide that suits best your current project:

1. Projects with one single .ino file
-------------------------------------

This is the simplest case. Adaptation is almost immediate:

**General rules**

#. `Put your code into a biicode block <http://docs.biicode.com/arduino/gettingstarted.html#create-your-project>`_ .

#. **Change** ``.ino`` file **extensions** to ``.cpp``. For example, ``sweep.ino`` file would be ``sweep.cpp``.

#. **Include** the ``Arduino.h`` **library** in the very beginning of your code:

	.. code-block:: cpp

		#include "Arduino.h"
		
#. Declare all function prototypes at the beginning of your code. For example: ``void servo_loop();``.

#. If you're using 3rd party (external) libraries, search for them in biicode and **rewrite** the library includes to the ones available on biicode. Usually, all included files in biicode projects follow this pattern: ``<username>/<blockname>/<path_to_file>``.

	For example, if you are using  `Tiny GPS Library <http://www.biicode.com/mikalhart/tinygps>`_ , ``tinygps.h`` , you should update the include directive like this:

	.. code-block:: cpp

		#include "mikalhart/tinygps/tinygps.h" 

Full ``.ino`` file adaptation Sample:

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
			#include <Servo.h>

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

#. `Put your code into a biicode block <http://docs.biicode.com/arduino/gettingstarted.html#create-your-project>`_.

#. Change ``.ino`` main file extension to ``.cpp``. Also, change the extension of the other ``.ino`` files to ``.h``.

	For example, if your project has the following layout, being ``sweep.ino`` your main file:

	.. code-block:: text

	   +-- sweep
	   |    +-- sweep.ino
	   |    +-- servo_functions.ino

	Rename ``sweep.ino`` to ``sweep.cpp``, and ``servo_functions.ino`` to ``servo_functions.h``. Put them into your ``project/blocks/username/biicode_block_name`` directory like this:

	.. code-block:: text

	   +-- <biicode_block_name>
	   |    +-- sweep.cpp
	   |    +-- servo_functions.h


#. **Include** the ``Arduino.h`` **library** in the very beginning of your code:

	.. code-block:: cpp

		#include "Arduino.h"

#. If you're using 3rd party (external) libraries, search for them in biicode and **rewrite** the library includes to the ones available on biicode. Usually, all included files in biicode projects follow this pattern: ``<username>/<blockname>/<path_to_file>``.

	For example, if you are using  `Tiny GPS Library <http://www.biicode.com/mikalhart/tinygps>`_ , ``tinygps.h`` , you should update the include directive like this:

	.. code-block:: cpp

		#include "mikalhart/tinygps/tinygps.h" 

#. Declare all function prototypes at the beginning of your code. For example ``void servo_loop();``.

Find below a full multiple ``.ino`` files adaptation sample. Easy adaptation is the one described before and advanced adaptation is the one biicode recommends for complex projects o nice practice:

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
			#include <Servo.h>

			void servo_loop(int pin){
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1){
				myservo.write(pos);
				delay(15);
			  }
			}
