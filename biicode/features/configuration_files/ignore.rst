.. _ignore:

ignore.bii
==========

The ``ignore.bii`` file allows you to specify which files will be ignored by biicode when processing and publishing your blocks. The concept is similar to the ``.gitignore`` files in a git repository (`explained here <http://git-scm.com/docs/gitignore>`_), and allows you to define which local files will be excluded from publication to our servers. 

Here you can see the contents of the default ``ignore.bii`` file located in your workspace ``bii`` folder (as you can see in :ref:`layouts section <layouts>`). ::

	# You can edit this file to add accepted and ignored file extensions
	# The format is similar to gitignore files.
	# Rules are evaluated in order.
	#
	# Format is as follows:
	#    <pattern>
	# pattern: conforms Unix Filename Pattern Matching, if preceded by ! it is negated, thus accepts
	#            instead of ignoring (previously ignored by a precedent rule)
	#

	# Compiled source #
	*.com
	*.class
	*.dll
	*.exe
	*.o
	*.so
	*.obj
	*.pyc
	*.dir

	# Editor backups
	*~

	# Hidden files
	.*
	*/.*

	# OS generated files
	Thumbs.db
	ehthumbs.db
	.DS_STORE


These rules are propagated hierarchically across all your hives and blocks. However, you can override these settings for any particular block. You only need to place additional ``ignore.bii`` files insider any block folder or subfolder. Those rules will be applied to all files contained in descendant folders. 

**Note:** There is no sense in placing ``ignore.bii`` configuration files insed a block ``bii`` folder, as it never contains source code files.


