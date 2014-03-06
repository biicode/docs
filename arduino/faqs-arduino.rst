.. _faqs_arduino:

FAQs about Arduino
===================

Launching Arduino IDE, I get an error **./arduino: 22: ./arduino: java: not found** in Ubuntu
-----------------------------------------------------------------------------------------------

You can do it this way:

.. code-block:: bash

	$ sudo apt-get install openjdk-7-jre librxtx-java 
	
Then you shouldn't have problems executing the IDE.

