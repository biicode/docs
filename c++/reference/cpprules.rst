.. _compilation_rules:

Build rules
===========

Sometimes your project need to define some preprocessor variables or maybe you need to link with some dynamic library provided by the system. Biicode gives you the option to define these special compilation needs.

You can define rules files for each executable target. Rules files can be placed anywhere in your blocks directory with a filename following the next regular expression:

:regexp:`\*cpp_rules*\.bii`

These files are written in Python, a small subset of it. You can interact with hive settings and target properties. This is an example of this kind of files:

.. code-block:: python
	:linenos:
		
        if settings.os.family == "linux":
           target.add_library("dl")
		
        target.std = "c++11"

        if "matrix.cpp" in target.filenames:
           target.add_definition("OPTMIZE_MATRIX=1")

        if settings.os.family == "MacOS":
           target.add_package("OpenGL",[])
           target.add_library("${OPENGL_LIBRARIES}")

.. _dependencies_edition:

Once you've written your file you should add it to your :ref:`dependencies.bii <dependencies_bii>`
