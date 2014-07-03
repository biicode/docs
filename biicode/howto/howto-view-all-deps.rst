.. _view_block_dependencies:

View all the block dependencies
=================================

The ``bii deps command`` has a lot of possibilities to show. Here, you'll see all the different possibilities.

The command can also be used combining a series of **additional parameters** (you can obtain the full list typing ``bii deps --help``):

.. code-block:: bash
	
	$ bii deps --help
	usage: bii deps [-h] [--detail] [--unresolved] [--system] [--implicit]
	                [--explicit] [--data] [--blocks BLOCKS [BLOCKS ...]]
	                [--files FILES [FILES ...]] [--virtual] [--main] [--graph]

Detailed view of your project's dependencies
---------------------------------------------

This option groups your source files with their corresponding source blocks (those contained within the ``blocks`` folder of your project). 

.. code-block:: bash

	$ bii deps --detail

For each file, the command shows information about its name and type, the presence or not of a ``main`` function, and the full list of dependencies for each particular file.


Filtering the blocks/files to be analyzed
------------------------------------------

The command provides 4 different options for filtering the results:

* ``--blocks [BLOCKS]`` allows you to filter dependencies by block name. Example:
|
.. code-block:: bash

	$ bii deps --blocks fenix/blink

* ``--files [FILES]`` receives a list of file names to be included in the result. Those files not contained in the list are omitted. Example:
|
.. code-block:: bash

	$ bii deps --files fenix/blink/blink.h

Filtering the type of files
----------------------------

Show some special type of files:

* ``--virtual`` indicates the client to show only those virtual files contained in your project.
|
.. code-block:: bash

	$ bii deps --virtual

* ``--main`` is used for displaying information about files that contain a ``main`` function or entry point to your code.
|
.. code-block:: bash

	$ bii deps --main

Filtering the dependencies
----------------------------

These allow you to specify you want the client to show their dependencies:

* ``--unresolved`` shows only your files' unresolved dependencies; those that are unknown by biicode, and cannot be retrieved from our servers using the :ref:`find command<bii_find_command>`.
|
.. code-block:: bash

	$ bii deps --unresolved

* ``--system`` make the command show only system dependencies for your files.
|
.. code-block:: bash

	$ bii deps --system

* ``--implicit`` shows only implicit dependencies for your files.
|
.. code-block:: bash

	$ bii deps --implicit

* ``--explicit`` shows only those dependencies explicitly referenced in your files.
|
.. code-block:: bash

	$ bii deps --explicit

* ``--data`` filters the results showing only data dependencies.
|
.. code-block:: bash

	$ bii deps --data


.. container:: infonote

	You can combinate as many chances as you want:

		$ bii deps --unresolved --system --main


Visual representation (blocks and their dependencies)
------------------------------------------------------

The client generates an interactive graph that is open in your web browser. Despite most of the code is saved on your local filesystem, you'll need an internet connection for loading some aditional libraries.

.. code-block:: bash

	$ bii deps --graph

Bellow you can see an example of these representations generated for a sample *'hello world'* block. In this case there are no external dependencies, and only those blocks contained in the ``blocks`` folder of your project (the ``user/hello_world`` bock) are represented, and grouped under the 'SRC' element. There is also one system dependency. You can click on the different nodes to expand and show their content. You can also drag every node, or pan and zoom the whole graphic.					

.. raw:: html

	<iframe src="/_static/graphs/hello_world/hello_world.html" width="100%" height="600px"></iframe>

* Double-clicking on any empty area **resets the pan and zoom** to their initial values.
|
* All dependencies are represented as **colored connections** (red for implicit dependencies, blue for explicit dependencies, and yellow for all system dependencies). All unresolved dependencies are displayed in a dark grey color.
|
* Virtual files are related to their possible implementations using **green connections**.
|
* You can show or hide any type of dependency just clicking on their corresponding toolbar buttons.
|
* Dragging a node while holding the *shift* key allows you to move also all its descendant nodes (those folders and files contained in that particular node, that are currently visible on the graph).
|
* The outer color of each file corresponds to the color of its block, while the inner color gives information about the particular file type (cpp, python, etc.).
