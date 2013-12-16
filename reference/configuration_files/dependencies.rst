
.. _dependencies-bii:

Dependencies configuration
--------------------------

The ``dependencies.bii`` file defines explicit dependencies that do not appear in code a common or direct way. Filling this configuration file you can add a :ref:`compilation rules <compilation_rules>` or license file to be downloaded and/or used whenever someone reuses your code. This file should be placed it in ``YOUR_HIVE/blocks`` as you can see in the :ref:`hive layout <hive_layout>` section.

``dependencies.bii`` contains rules matching the following structure: ::

	dependent_file_name [-+=] NULL|[[!]dependency_file ]+

Depending on specified operator after the ``dependent_file_name``, it will behave differently:

* With the ``-`` operator all specified dependencies will be deleted from their dependent file.
* With the ``+`` operator all specified dependencies will be added to their dependent file.
* With the ``=`` operator all specified dependencies will overwrite existing dependencies.

If you mark a dependency with a ``!`` symbol you are declaring this file a dependency but **it should be excluded from the building process.**

Also, you can declare that a file doesn't depend on nothing using the ``NULL`` keyword.

The ``dependent_file_name`` may be defined using **Unix filename pattern matching**.

==========	========================================
Pattern 	Meaning
==========	========================================
``*``			Matches everything
``?``			Matches a single character
``[seq]``		Matches any character in seq
``[!seq]``		Matches any character not in seq
==========	========================================

This is an example of a ``dependencies.bii`` file: ::

	test.cpp + example.h !LICENSE
	*.cpp + !README
	example.h = NULL
	main.cpp + matrix32.h
	main.cpp - matrix16.h
	calculator.cpp = solver.h type.h

* In this example we're declaring that ``test.cpp`` depends on both ``example.h`` and ``LICENSE``. However, ``LICENSE`` must be excluded from the compilation process.
* Also, we're declaring that all files with a ``.cpp`` extension depend on the ``README`` file but it mustn't be compiled.
* Declaring ``example.h = NULL`` all ``example.h`` dependencies are deleted.
* In the fourth line we add ``matrix32.h`` as a ``main.cpp`` dependency.
* In the next line we are deleting ``matrix16.h`` as a ``main.cpp`` dependency.
* Finally, we're declaring that ``solver.h`` and ``type.h`` are ``calculator.cpp`` dependencies, ovewriting all existing implicit dependencies.
