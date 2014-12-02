.. _dependencies_bii:

``dependencies.bii``: configuring custom file dependencies
===========================================================

The ``dependencies.bii`` file is used to **define those internal dependencies that cannot be automatically inferred from your code in a direct way**. This is an optional configuration file, and should be placed inside the ``bii`` folder contained in every block, as you can see in the :ref:`project layout <project_layout>` section. Optionally, you may specify custom dependencies making use of :ref:`tags inserted in the file comments, as explained in this section<bii_dependencies_tag>`.

The rules defined in each ``dependencies.bii`` file should affect only to cells contained in the block where the file is included. This means that a ``dependencies.bii`` configuration file **can only be locate inside a** ``block_name/bii`` **folder**, and makes no sense having a ``default_dependencies.bii`` file in the workspace ``bii`` folder.

The ``dependencies.bii`` file contains rules matching the following pattern: ::

	dependent_file_name [-+=] NULL|[[!]dependency_file ]+

The specific meaning of each rule depends on the operator located right after the ``dependent_file_name``:

* With the ``-`` operator all specified dependencies will be **deleted** from their dependent file.
* With the ``+`` operator all specified dependencies will be **added** to their dependent file.
* With the ``=`` operator all specified dependencies will **overwrite** existing dependencies.

If you mark a dependency with a ``!`` symbol you are declaring this file as a dependency, but **it should be excluded from the building process**. This is useful, for example, to define **license files** that must be downloaded along with your code, but must not be included in the compilation process.

Also, you can declare that a file has no dependencies using the ``NULL`` keyword.

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

The meaning of this configuration is as follows:

* We are declaring that ``test.cpp`` depends on both ``example.h`` and ``LICENSE``. However, ``LICENSE`` must be excluded from the compilation process.
* Also, we're declaring that all files with a ``.cpp`` extension depend on the ``README`` file, but this dependency mustn't be compiled.
* The line ``example.h = NULL`` informs biicode that all ``example.h`` dependencies are deleted.
* In the fourth line we add ``matrix32.h`` as dependency of the ``main.cpp`` file.
* In the next line we are deleting ``matrix16.h`` as a ``main.cpp`` dependency.
* In the last line we are declaring that both ``solver.h`` and ``type.h`` are ``calculator.cpp`` are the only dependencies of ``calculator.cpp``, overwriting any existing implicit dependencies.
