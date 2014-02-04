================================
How to move your code to biicode
================================

``IMPORTANT:`` You can only have one language for Hive, so do not mix blocks with  Arduino and C/C++ Desktop apps.

If you have some existing Arduino projects, and want to start using them with Biicode, you need to take these simple **4 steps**:

**1st step**: Create a **new hive** in your biicode workspace using the ``bii new <hive_name>`` command (see the :ref:`reference for this coommand here<bii_new_command>`).

**2nd step**: Copy your source files into a block folder inside your hive (i.e. ``<your_hive>/blocks/<user_name>/<block_name>/`` folder).

**3rd step**: Include the following lines of code at he beginning of your source files:

.. code-block:: cpp

	#if ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif
	
**4th step**: Modify the ``filefilter.bii`` configuration file of your hive, located in ``<your_hive>/bii/`` folder, in order to indicate Biicode that must process all ``.ino`` files as ``.cpp`` files. To do so, add the following lines to the configuration (you can :ref:`learn more about the filefilter.bii file here<filefilter>`): ::

	ACCEPT    *.ino     *.cpp