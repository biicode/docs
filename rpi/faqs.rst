FAQs
====


This sections sumarizes some Frequently Asked Questions that our users hace posed up to this moment. If your particular inquiry is not in this list, please, don't hesitate to contact us so we can help you as soon as possible.

.. contents:: 
	:local:

General
-------

Volume control
^^^^^^^^^^^^^^
You can force the RPi to use a specific interface using the command amixer cset numid=3 N where the N parameter means the following: 0=auto, 1=analog, 2=hdmi.  Therefore, to force the Raspberry Pi to use the analog output:

.. code-block:: bash

	$ amixer cset numid=3 1

If you want to change the volume level:

.. code-block:: bash

	$ amixer cset numid=1 -- 20%
