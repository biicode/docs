FAQs about Raspberry Pi
========================

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