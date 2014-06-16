.. _comments_tags:

Comments tags
=============

One of the reason why biicode is a powerful tool for any software developer, is that not only automatically configures your project and builds it if needed, but also **provides the tools that allow you to take full control of the project configuration and settings**. This control is provided on one hand via specific :ref:`configuration files<config_files>`. On the other hand, you can make use of **special tags included in your code comments**, that provide Biicode with valuable information about your specific necessities and desires about any project or block. 

You can think of these tags as inline configuration instructions that are placed inside your files, and in most cases the instructions syntax is identical to the respective configuration files. Please, take into account that this configuration flavour is complementary to the use of :ref:`configuration files<config_files>`; it is up to you to use the most convenient one for your necessities. Hovever, try not to include incompatible declarations in your configuration files, and in your code comments tags.

.. _bii_dependencies_tag:

The ``bii:#dependencies`` tag
-----------------------------

This tag provides the same functionality as the ``dependencies.bii`` :ref:`configuration files<dependencies_bii>`. It allows you to define the dependencies configuration for any given file, simply including this information inside the comments of the source code. The syntaxis for this command is:

.. code-block:: text

	bii:#dependencies(list_of_dependencies)

where ``list_of_dependencies`` is a string containing informacion about that particular file dependencies, with a similar structure to the one used in the ``dependencies.bii`` files. Take, for instance, this example displayed in the :ref:`section describing the dependencies.bii file<dependencies_bii>`: ::

	test.cpp + example.h !LICENSE
	*.cpp + !README
	example.h = NULL
	main.cpp + matrix32.h
	main.cpp - matrix16.h
	calculator.cpp = solver.h type.h

This same behavior can be achieved making use of the ``bii:#dependencies``, including the appropriate parameters for each dependent code file.

In your ``test.cpp`` file:

.. code-block:: cpp

	/* Begin of test.cpp file.
		bii:#dependencies(+ example.h !LICENSE)
	*/

	... some code here ...
	/* end of test.cpp */

Similarly, in the comments of your ``calculator.cpp`` file:

.. code-block:: cpp

	/* Begin of calculator.cpp */

	// Biicode tag configuration in a single line C++ comment:
	// bii:#dependencies(= solver.h type.h)

	... come code here ...
	/* end of calculator.cpp */

And so on.

.. _bii_entry_point_tag:

The ``bii:#entry_point`` tag
----------------------------

This tag provides similar functionality to the ``mains.bii`` :ref:`configuration file<mains_bii>`. When included in the comments of a given file, determines wether or not that particular file contains an entry point for your code, and its type. The syntaxis for this command is as follows:

.. code-block:: text
	
	bii:#entry_point([type]) 

The optional parameter ``type`` can take one of the following values:

* *None*, that is, the empty string, indicates that this particular file is an executable, and must be considered as such int he configuration and possible compilation of your project.
* ``EXCLUDE``, indicates that this file must not be considered as an entry point for your program.

Consider the following example for a ``mains.bii`` file contained in a C++ block: ::

	funct.cpp
	!no_main.cpp

The same configuration can be achieve making use of comment tags, simply inserting the following text in the respective files. 

In the ``funct.cpp`` you could write:

.. code-block:: cpp

	/* This is the file: funct.cpp
		bii:#entry_point()
	*/

	... some code here ...

	/* end of the funct.cpp file */

And similarly, in you ``no_main.cpp`` file:

.. code-block:: cpp

	/* This is the file: no_main.cpp
		
	*/

	// bii:#entry_point(EXCLUDE)

	int main() {
		return 0;
	}

	/* end of the no_main.cpp file */

