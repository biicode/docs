.. _types_bii:

``types.bii``: configuring non-standard file extensions
=======================================================

This is a special configuration file that **allows you to specify how your files are interpreted and processed by biicode**. In some cases, we find projects containing —for some reason— non-standard extensions for certain file types. 

Consider, for instance, a block containing c++ code in files with a non-standard file extension, such as ``.mycpp``, or without extension. In this case, you must explicitly indicate biicode to process those files as c++ files. This is  as simple as placing a ``types.bii`` file in the root of your block folder: ::

	# my special c++ files extension:
	*.mycpp		cpp
	NOEXT 		cpp


As you can see, this file contains rules of the form: ::

	<pattern> 	<desired_extension>

Where ``<pattern>`` is a wild-card for the file types you desire to apply the rule, and ``<desired_extension>`` is the corresponding standard file extension for that particular type. In the previous example, we are telling biicode that all files with ``mycpp`` extension contained in the source folder (and that includes the current folder, and all its descendants) must be interpreted as ``cpp`` files.

**Note:** The ``<desired_extension>`` expression contains only the desired extension string, *without the dot symbol*.

These rules **are always applied hierarchically**. So you can override your type settings using additional ``types.bii`` place in descendant folders (this is, however, a more exceptional scenario, but illustrates the powerful capabilities biicode offers to the programmer).

The default file extensions understood by biicode are:

	* CPP : ``.h``, ``.hh``, ``.hpp``, ``.c``, ``.cc``, ``.cpp``, ``.cxx``, ``.inl``, ``.ino``, ``.ipp``
	* TEXT: ``.txt``, ``.bii`` , ``.md`` 
	* XML: ``.xml``
	* HTML: ``.html``, ``.htm``
	* SOUND: ``.wav``
	* IMAGE: ``.jpeg``, ``.jpg``, ``.gif``, ``.png``, ``.bmp``
	* JSON: ``.json``
	* PYTHON: ``.py``
	* JS : ``.js``, ``.node``
	* JAVA: ``.java``
	* FORTRAN: ``.f90``, ``.for``, ``.f``

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_