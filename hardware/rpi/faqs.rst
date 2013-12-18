Raspberry PI FAQs
=================

This sections sumarizes some Frequently Asked Questions that our users have posed up to this moment. If your particular inquiry is not in this list, please, don't hesitate to contact us so we can help you as soon as possible.

.. contents:: 
	:local:

General
-------

Output selection and volume control
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
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
