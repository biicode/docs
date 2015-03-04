
Doxygen
-------

|doxygen_homepage| is the standard tool for generating documentation from annotated C++ sources. You can download it from its |doxygen_downloads|.

   * It can generate an on-line documentation browser (in HTML) and/or an off-line reference manual (in LaTeX) from a set of documented source files. There is also support for generating output in RTF (MS-Word), PostScript, hyperlinked PDF, compressed HTML, and Unix man pages. The documentation is extracted directly from the sources, which makes it much easier to keep the documentation consistent with the source code.

   * You can configure doxygen to extract the code structure from undocumented source files. This is very useful to quickly find your way in large source distributions. Doxygen can also visualize the relations between the various elements by means of include dependency graphs, inheritance diagrams, and collaboration diagrams, which are all generated automatically.

Create a Doxyfile template
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    ~$ cd /blocks/[USER]/[BLOCK]
    ~/blocks/[USER]/[BLOCK]$ mkdir docs
    ~/blocks/[USER]/[BLOCK]$ cd docs
    ~/blocks/[USER]/[BLOCK]/docs$ doxygen -g

Edit your Doxyfile
^^^^^^^^^^^^^^^^^^

The minimal info that you need to change in your Doxyfile is the following tags: ::

    PROJECT_NAME           = "My Project"

    OUTPUT_DIRECTORY       = .

    INPUT                  = ../

    FILE_PATTERNS          = *.c \
                             *.cc \
                             *.cxx \
                             *.cpp \
                             *.c++ \
                             *.h \
                             *.hh \
                             *.hxx \
                             *.hpp \
                             *.h++ \

Generate the Documentation
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    ~/docs$ doxygen Doxyfile

    #Open the /docs/html/index.html with your web browser.

.. container:: infonote

   All the info of the previous examples have been written taking as reference a ``docs`` folder inside your ``block``.

   However, you can create your Doxyfile where you want changing the INPUT tag in your Doxyfile.

   For example, to generate the docs folder in you ``project``, you need to specify: ``INPUT = ../blocks/[USER]/[BLOCK_NAME]/``.

   Read more info about doxygen in the `official documentation. <http://www.stack.nl/~dimitri/doxygen/manual/index.html>`_

If you want to make your own main page, you can create a ``DoxygenMainpage.h`` in the docs folder with the following sections: ::

    /**
    @mainpage  TITLE_OF_YOUR_HOME_PAGE
    
    @author YOUR_USER_NAME and all the info about the author

    Description of you block

    @section TITLE

    Section info
    */

A good example is |doxygen_doxygenmainpage|:

.. image:: ../../_static/img/c++/doxygen.png


.. literalinclude:: /_static/code/cpp/integration/doxyfile.cpp
   :language: cpp
   :emphasize-lines: 2,3,9,17,30


.. |doxygen_homepage| raw:: html

   <a href="http://www.stack.nl/~dimitri/doxygen/" target="_blank">Doxygen</a>

.. |doxygen_downloads| raw:: html

   <a href="http://www.stack.nl/~dimitri/doxygen/download.html" target="_blank">downloads page</a>

.. |doxygen_doxygenmainpage| raw:: html

   <a href="https://www.biicode.com/david/david/libfreenect/master/0/doc/DoxygenMainpage.h" target="_blank">libfreenect/doc/DoxygenMainpage.h</a>
