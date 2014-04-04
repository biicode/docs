.. _faqs_arduino:

FAQs
====

Launching Arduino IDE, I get an error **./arduino: 22: ./arduino: java: not found** in Ubuntu
---------------------------------------------------------------------------------------------

You can do it this way:

.. code-block:: bash

	$ sudo apt-get install openjdk-7-jre librxtx-java 
	
Then you shouldn't have problems executing the IDE.

I changed my Arduino's port, what happens now?
----------------------------------------------
Port detection is automatic, so whenever you execute ``bii arduino:upload`` the port is redetected.

Anyway, if you experience any trouble changing your port or your arduino board, just execute ``bii arduino:settings``


How can I change my Arduino project properties?
-----------------------------------------------------

Just execute ``bii arduino:settings`` and fill the requested info with the new data.

