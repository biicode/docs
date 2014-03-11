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

	  
	  
``bii rpi:send``: Send a bin folder
-----------------------------------

Send your binaries automatically to your Raspberry Pi from your PC. See the command usage  :ref:`here<bii_rpi_send>`.


``bii rpi:ssh``: Connect by ssh with the Raspberry Pi
-----------------------------------------------------

If you want a remotely access to your Raspberry Pi you can get it with this command. See its usage :ref:`here<bii_rpi_ssh>`.
	

``bii rpi:initopengles``: Init OpenGLES project
-----------------------------------------------

This command lets you develop OpenGLES applications in the Raspberry Pi. See the command usage :ref:`here<opengles>`.
