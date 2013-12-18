
.. _mains-bii:

Executables configuration
-------------------------

Biicode automatically detects entry points to your programs by examining which files contain a main function definition. However there are certain cases where you are using frameworks that have a more complex setup. In those cases you might want to tell biicode where are your entry points. You can do so in the ``mains.bii`` file that should be placed in ``YOUR_HIVE/bii`` folder as you can see in the :ref:`hive layout <hive_layout>` section.


mains.bii contains rules matching the following structure: ::

	[[!]file ]

If you add a file, it will be considered as an entry point.
If you add a file with a ``!`` symbol you are declaring this file file should not be considered an entry point.


This is an example of a ``mains.bii`` file: ::

	funct.cpp
	!funct.h

* In this example we're declaring that ``funct.cpp`` is an entry point to the application but ``funct.h`` is not even if it declared a main function
