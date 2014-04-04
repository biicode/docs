.. _faqs_arduino:

FAQs
====

Launching Arduino IDE, I get an error **./arduino: 22: ./arduino: java: not found** in Ubuntu
---------------------------------------------------------------------------------------------

You can do it this way:

.. code-block:: bash

	$ sudo apt-get install openjdk-7-jre librxtx-java 
	
Then you shouldn't have problems executing the IDE.

I have unplugged my Arduino, ¿How can I re-detect it?
-----------------------------------------------------
Port detection is automatic, so whenever you execute ``bii arduino:upload`` the port is redetected.

It will also ask your board model. 

How can I change my Arduino project properties?
-----------------------------------------------------
With your console locate inside the hive folder whose properties you want to change.

Now, just execute ``bii arduino:settings`` and fill requested info with the new data.

