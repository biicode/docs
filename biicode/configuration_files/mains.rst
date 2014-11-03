.. _mains_bii:

``mains.bii``: defining entry points in your code
==================================================

Biicode automatically detects entry points to your programs by examining which files contain a ``main`` function definition —or the equivalent one in your programming language—. However, there are certain cases where a specific framework requires a more complex setup. In those cases you might want to **explicitly tell biicode where are your entry points**. 

You can do so making use of the ``mains.bii`` file located in ``your_block/bii/`` folder as you can see in the :ref:`project layout <project_layout>` section. Optionally, you can use the biicode tag ``#bii:entry_point`` described in :ref:`this section<bii_entry_point_tag>`.

Any ``mains.bii`` file contains lines with rules matching the following structure: ::

	[[!]file ]

* If you write the **name of a file**, it will be considered as an entry point.
* If the filename is **preceded by an exclamation mark** (``!``), you are declaring this file should not be considered an entry point (despite the fact that biicode could find a ``main`` function or any other indicator that may lead to consider this file as an entry point to your program).

This is an example of a ``mains.bii`` file: ::

	funct.cpp
	!no_main.cpp

In this case we are declaring that ``funct.cpp`` is an entry point to the application, but ``no_main.h`` is not, even in the case it contained a ``main`` function implementation in its contents.

Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.