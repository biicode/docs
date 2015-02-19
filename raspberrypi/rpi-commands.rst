.. _bii_rpi_tools:

RPi commands
============

This section summarizes the **Raspberry Pi commands available to be used with the biicode client program**. You can see these tools if you execute:

.. code-block:: bash

	$ bii -h rpi

	SYNOPSIS:
	    $ bii COMMAND [options]
	For help about a command:
	    $ bii COMMAND --help
	To change verbosity, use options --quiet --verbose

	---------EXPERIMENTAL Raspberry Pi general tools commands--------
	  rpi:send        Send by scp the bin folder into the specified directory
	  rpi:settings    Configure Raspberry Pi project settings
	  rpi:ssh         Connect by ssh with the Raspberry Pi

.. _bii_rpi_send:

``bii rpi:send``: send a bin folder
-----------------------------------

Send your binaries automatically to your Raspberry Pi from your PC.

.. code-block:: bash

	$ bii rpi:send
	Sending with rsync -Pravdtze ssh [HIVE_DIRECTORY]/bin/* [RPI_USER]@[RPI_IP]:[DIRECTORY]/[HIVE_NAME]

	[RPI_USER]@[RPI_IP]'s password:

The Raspberry Pi user's password will be asked. If you have not changed your password, for Raspbian the default one is **raspberry**.

.. _bii_rpi_settings:

``bii rpi:settings``: configure your Raspberry Pi settings
-----------------------------------------------------------

This command provides an easy way to configure your Raspberry Pi settings.

.. code-block:: bash

	$ bii rpi:settings

	Define RPI settings for external C/C++ cross-building
	If you are working onboard the RPI, you don't need these settings
	RPI username (pi): [RPI_USER]
	RPI IP Address: [RPI_IP] #example 192.168.1.44
	RPI directory to upload (bin): [RPI_FOLDER] #This folder must exist into your Raspberry Pi.

* **RPI username (pi)**: Raspberry Pi user name. Default value is ``pi``.
* **RPI IP Address**: Raspberry Pi local IP address. Write here your Raspberry Pi network address, that you can find out executing the ``ifconfig`` in a console inside the RPi.
* **RPI directory to upload (bin)**: Raspberry Pi directory where you want your programs to be saved. Default value is the ``bin`` user home folder.

.. _bii_rpi_ssh:

``bii rpi:ssh``: connect by ssh with the Raspberry Pi
-------------------------------------------------------

If you want a remotely access to your Raspberry Pi you can get it with this command.

.. code-block:: bash

	$ bii rpi:ssh
	...
	Connecting with ssh <rpi_user>@<rpi_ip>
	<rpi_user>@<rpi_ip>'s password:

	pi@raspberrypi ~ $

``bii cpp:configure --toolchain or -t``: enable, disable or change the Raspberry Pi cross compilation.
------------------------------------------------------------------------------------------------------

If you want to enable the Raspberry Pi cross compilation use this command.

.. code-block:: bash

	$ bii cpp:configure --toolchain=rpi

If you need the default rpi-toolchain.cmake, execute ``bii rpi:settings`` first.

.. code-block:: bash

	$ bii rpi:settings
	...
	$ bii cpp:configure --toolchain=rpi

If you want to disable it, use this command.

.. code-block:: bash

	$ bii cpp:configure --toolchain=None

To **use a custom tool-chain** you need to **place it in the bii folder** of your project **with the name <my_toolchain_name>-toolchain.cmake**.

To use it, just pass it as argument of ``bii cpp:configure -t my_toolchain_name``.

.. code-block:: bash

	$ bii cpp:configure --toolchain=my_toolchain_name

.. container:: infonote

	:ref:`You can read more info about toolchains in the C++ section <custom_toolchains>`