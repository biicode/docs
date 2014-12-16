How to use the Arduino Yun
==========================

**Adapt your current Arduino projects and sketches to biicode**. Next steps depend on whether your project contains one single ``.ino`` file, or multiple ``.ino`` files. Just follow the guide that suits best your current project:


1. Download Arduino 1.5
-----------------------

Download the Arduino 1.5 zip file `from Arduino download page <http://arduino.cc/en/Main/Software>`_ and unzip it.

2. Configure your settings
--------------------------

Insert the new SDK path and the board as yun. In this example we have unzip our SDK into `c:/biicode_env/arduino-1.5.8`.

.. code-block:: bash

	$ bii arduino:settings
	Enter SDK path (/../biicode_env/arduino-1.0.6): c:/biicode_env/arduino-1.5.8
	Enter board (/o list supported options): yun
	Using arduino port: COM13
