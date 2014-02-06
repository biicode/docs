.. _faqs_rpi:

FAQs about Raspberry Pi
========================

Installing the biicode package from downloads page is too slow
------------------------------------------------------------------
	
You can do it this alternative way:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu[ARCH]_[VERSION].deb

For example, you want to install the new release biicode package *bii-ubuntu64_0_7_2.deb* in your Ubuntu 12.10 64 bits version, then you have to enter:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu64_0_7_2.deb
	
If you would have the 32 bits version:

.. code-block:: bash
	
	$ sudo dpkg -i bii-ubuntu32_0_7_2.deb


Output selection and volume control
------------------------------------

**You can force the RPi to use a specific interface** using the command ``amixer cset numid=3 N``, where the ``N`` parameter can take the following values:

* ``0`` for **auto** selection
* ``1`` for **analog** output
* ``2`` for **hdmi** output

Therefore, to force the Raspberry Pi to use the analog output, you can use the following command:

.. code-block:: bash

	$ amixer cset numid=3 1

If you want to change the volume level:

.. code-block:: bash

	$ amixer cset numid=1 -- 20%