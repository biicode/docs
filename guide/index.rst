Main Title: a Simple reStructuredText (reST) Tutorial
=====================================================

This is a simple reST and sphinx tutorial for writing the biicode documentation, maintaining and homogeneus style throughout the documents.

.. _first-section:

This is a Section Title: basic usage
------------------------------------

Please, first of all, clone locally the documentation sources, `available here <https://github.com/biicode/docs>`_.

A better way of writting the previous paragraph would be:

Please, first of all, clone locally `the biicode docs sources available in GitHub <https://github.com/biicode/docs>`_. Try to convey **as much information as possible** with any included link.

In order to compile locally this documentation, you will need to have installed ``sphinx``:

.. code-block:: bash

	$ pip install sphinx

Then, you can compile the documentation into ``html`` executing:

.. code-block:: bash

	$ make html
	sphinx-build -b html -d _build/doctrees   . _build/html
	Making output directory...
	Running Sphinx v1.1.3
	loading pickled environment... not yet created
	building [html]: targets for 19 source files that are out of date
	updating environment: 19 added, 0 changed, 0 removed
	reading sources... [100%] tutorials/updating-blocks-and-dependencies                                                                                               
	looking for now-outdated files... none found
	pickling environment... done
	checking consistency... /Users/Luis/Workspace/ReadTheDocs/biicode/rst_tutorial/index.rst:: WARNING: document isn't included in any toctree
	done
	preparing documents... done
	writing output... [100%] tutorials/updating-blocks-and-dependencies                                                                                                
	writing additional files... genindex search
	copying images... [100%] _static/img/eclipse_tree.png                                                                                                              
	copying static files... done
	dumping search index... done
	dumping object inventory... done
	build succeeded, 1 warning.

	Build finished. The HTML pages are in _build/html.

You can also clean the ``_build`` directory with the following command:

.. code-block:: bash

	$ make clean
	rm -rf _build/*

Some useful links:

* `Sphinx documentation <http://sphinx-doc.org/>`_
	
	* `Brief introduction to reST concepts <http://sphinx-doc.org/rest.html>`_
	* `Inline Markup <http://sphinx-doc.org/markup/inline.html>`_

* The `reST documentation <http://docutils.sourceforge.net/rst.html>`_

	* `reST markup specification <http://docutils.sourceforge.net/docs/ref/rst/restructuredtext.html>`_


This is an example of cpp code. All code snippets should include number lines with the ``:linenos:`` modifier.

.. code-block:: cpp
	:linenos:

	using namespace std;
	int main() {
	    Sphere s(2.0f);
	    cout << "Volume: " << s.volume() << endl;
	        return 1;
	}

This is another code snippet, this time written in python:

.. code-block:: python
	:linenos:

	# prints recursive count of lines of python source code from current directory
	# includes an ignore_list. also prints total sloc

	import os
	cur_path = os.getcwd()
	ignore_set = set(["__init__.py", "count_sourcelines.py"])

	loclist = []

	for pydir, _, pyfiles in os.walk(cur_path):
	    for pyfile in pyfiles:
	        if pyfile.endswith(".py") and pyfile not in ignore_set:
	            totalpath = os.path.join(pydir, pyfile)
	            loclist.append( ( len(open(totalpath, "r").read().splitlines()),
	                               totalpath.split(cur_path)[1]) )

	for linenumbercount, filename in loclist: 
	    print "%05d lines in %s" % (linenumbercount, filename)

	print "\nTotal: %s lines (%s)" %(sum([x[0] for x in loclist]), cur_path)


Terminal examples can be highlighted parsing the commands with the ``bash`` pygments lexer. In this case, avoid including line numbers:

.. code-block:: bash

	$ bii find --update --downgrade

If the example corresponds to a Windows terminal, please, use the BatchLexer. A `complete list of available pygments lexers can be found here <http://pygments.org/docs/lexers/>`_.

.. code-block:: bat

	Do you want to compress or decompress a file (to exit 'CTRL+C')? <comp|decomp>
	comp
	Enter file source name:
	C:\Users\Usuario\Desktop\file.txt
	Enter file destination name:
	file.gz
	The original file size is: 16944
	The file size after being compressed is: 5152

For plain text examples or configuration files, use the marker for literal code blocks, ``::``: ::

	This is a literal blocks
	APP: 123



Anohter section: linking
------------------------

Links to web pages. `This is a link to biicode.com <http://www.biicode.com>`_

Links to document sections. :ref:`This is a link to a the first section of this document <first-section>`.

This is the title of a subsection
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Adding tabs
===========

You can add tabs to document using a simple hack. Just add the class to a document second-level section using the ``rst-class`` tag:

.. code-block:: text
	
	.. rst-class:: tabbed

	First section
	-------------

	contents for this section that will appear in a tab.

	.. rst-class:: tabbed

	Second section
	--------------

	contents for this section that will appear in a tab.

	.. rst-class:: tabbed

	Third section
	-------------

	contents for this section that will appear in a tab.

here, you can see an example:

.. rst-class:: tabbed

First section
-------------

contents for this section that will appear in a tab.

.. rst-class:: tabbed

Second section
--------------

contents for this section that will appear in a tab.

.. rst-class:: tabbed

Third section
-------------

contents for this section that will appear in a tab.