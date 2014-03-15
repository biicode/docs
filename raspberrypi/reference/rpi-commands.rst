.. _bii_rpi_tools:

Command list
============

This section summarizes the **Raspberry Pi commands available to be used with the biicode client program**. You can see these tools if you execute:

.. code-block:: bash
	
	$ bii -h rpi
	
	...

	---------EXPERIMENTAL Raspberry Pi general tools commands--------
	  rpi:initopengles Init OpenGLES project.
	  rpi:send        Send by scp the bin folder into the specified directory
	  rpi:ssh         Connect by ssh with the Raspberry Pi


``bii rpi:settings``: Configure your Raspberry Pi settings
-----------------------------------------------------------

If you want an easy way to configure your Raspberry Pi settings you can get it with this command. 

.. code-block:: bash
	
	$ bii rpi:settings

	Define RPI settings for external C/C++ cross-building
	If you are working onboard the RPI, you don't need these settings

	RPI username (pi): [RPI_USER]
	RPI IP Address: [RPI_IP]
	RPI directory to upload (bin): [RPI_FOLDER]
	Cross building? (NO/yes): yes
	
* **RPI username (pi)**: Raspberry Pi user name. Default value is ``pi``.
* **RPI IP Address**: Raspberry Pi local IP address. Write here your Raspberry Pi network address, that you can find out executing the ``ifconfig`` in a console inside the RPi.
* **RPI directory to upload (bin)**: Raspberry Pi directory where you want your programs to be saved. Default value is the ``bin`` user home folder.
* **Cross building?**: Activate the croos building. Default value is ``NO``.

	  
``bii rpi:send``: Send a bin folder
-----------------------------------

Send your binaries automatically to your Raspberry Pi from your PC.

.. code-block:: bash

	$ bii rpi:send
	Sending with rsync -Pravdtze ssh [HIVE_DIRECTORY]/bin/* [RPI_USER]@[RPI_IP]:[DIRECTORY]/[HIVE_NAME]

	[RPI_USER]@[RPI_IP]'s password:

The Raspberry Pi user's password will be asked. If you have not changed your password, for Raspbian the default one is **raspberry**.


``bii rpi:ssh``: Connect by ssh with the Raspberry Pi
-----------------------------------------------------

If you want a remotely access to your Raspberry Pi you can get it with this command.

.. code-block:: bash

	$ bii rpi:ssh
	...
	Connecting with ssh <rpi_user>@<rpi_ip>
	<rpi_user>@<rpi_ip>'s password:
	
	pi@raspberrypi ~ $
	

``bii rpi:initopengles``: Init OpenGLES project
-----------------------------------------------

This command lets you develop OpenGLES applications in the Raspberry Pi. See the command usage :ref:`here<opengles>`.
