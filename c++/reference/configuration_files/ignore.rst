.. _ignore_bii:

**ignore.bii**: filtering your files
=====================================

Specify in **ignore.bii** which files you want biicode to ignore when processing and publishing your blocks. It's a similar approach to *.gitignore* files in a `git repository <http://git-scm.com/docs/gitignore>`_, and allows you to define which local files will be excluded from publication to our servers. 

Here's the general *ignore.bii* file biicode generates by default, you can find it in your *.biicode* folder which is in your user folder.

.. code-block:: text

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


Place additional *ignore.bii* files insider any block folder or subfolder to ignore specific files and/or override the general ignore rules. 

Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.
