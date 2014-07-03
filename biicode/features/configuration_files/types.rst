.. _types_bii:

``types.bii``: configuring non-standar file extensions
=======================================================

This is a special configuration file that **allows you to specify how your files are interpreted and processed by biicode**. In some cases, we find projects containing —for some reason— non-standard extensions for certain file types. 

Consider, for instance, a block containing c++ code in files with a non-standard file extension, such as ``.mycpp``. In this case, you must explicitly indicate biicode to process those files as c++ files. This is simple placing a ``types.bii`` folder in the root of you block folder: ::

	# my special c++ files extension:
	*.mycpp		cpp

As you can see, this file contains rules of the form: ::

	<pattern> 	<desired_extension>

where ``<pattern>`` is a wildcard for the file types you desire to apply the rule, and ``<desired_extension>`` is the corresponding standard file extension for that particular type. In the previous example, we are informing biicode that all files contained in our block (and that includes the current folder, and all its descendants) must be interpreted as ``cpp`` files.

**Note:** The ``<desired_extension>`` expression contains only the desired extension string, *without the dot symbol*.

These rules **are always applied hierarchically**. So you can override your type settings using additional ``types.bii`` place in descendat folders (this is, however, a more exceptional scenario, but illustrates the powefull capabilities biicode offers to the programmer).
