
Arduino Serial Monitor
=======================

This example shows you how to run **biicode's Arduino Serial Monitor Interface** and turn ON/OFF one LED easily. If you don't know how to start using Arduino with biicode, check out our :ref:`getting started guide for Arduino<arduino_getting_started>`.

C++ code
--------

Put the following file in your ``~/project_name/blocks/your_user_name/block_name/``:

**monitor_led.cpp**

.. literalinclude:: ../../_static/code/arduino/examples/monitor_led.cpp
   :language: cpp


If you want, you can :download:`download the main file <../../_static/code/arduino/examples/monitor_led.cpp>`


Turn ON/OFF one LED
-------------------

First, **upload this firmware to your Arduino** with the following command:

.. code-block:: bash

    $ bii arduino:upload

    ...

    [100%] Built target [your_user_name]_monitor_led_main-upload

You shouldn't get any erros but if you do, please check that your Arduino is correctly connected, and check your settings (using the ``bii arduino:settings`` command).
If you still have any issues please contact us at our `forum <http://forum.biicode.com/category/arduino>`_.

Now, **open the Arduino monitor**. You only need to execute the following command:

.. code-block:: bash

    $ bii arduino:monitor

    ...

    Arduino detected on port [YOUR_PORT]


You'll see a window with an interface that allows you to communicate with the Arduino Serial Port. Here you can send ``1`` or ``0`` to turn the led ON or OFF, respectively.

.. image:: ../../_static/img/arduino/monitor_led_example.png

