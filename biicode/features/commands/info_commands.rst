.. _bii_info_commands:

Information commands
=====================

This section summarizes the general **commands available to be used with the biicode client program**. The biicode client is the main utility that allows you to:

* **manage** your hives and blocks locally, on your computer,
* determine their internal and external **dependencies**,
* **retrieve** any missing code dependencies from the biicode servers,
* **publish** your code, and
* **reuse** other users' code.

All these functionalities are achieved using appropriate commands that are explained and used in many examples along this documentation, and are compiled here in a list for your convenience and reference.


.. contents:: List of commands
   :local:
   :depth: 1



.. _bii_deps_command:

``bii deps``: Analyzing code dependencies
-----------------------------------------

This command allows you to check the dependencies of any hive in your workspace. It's basic form, with no parameters, provides two pieces of information, giving you a general idea of which are your code dependencies:

* The **Dependencies Table**: a list of the **blocks that contain cells your code depends on**.
* The full list of your cell dependencies.

The command can also be used combining a series of **additional parameters** (you can obtain the full list typing ``bii deps --help`` inside your workspace):

.. code-block:: bash
	
	$ bii deps --help
	usage: bii deps [-h] [--detail] [--unresolved] [--system] [--implicit]
	                [--explicit] [--data] [--blocks BLOCKS [BLOCKS ...]]
	                [--files FILES [FILES ...]] [--virtual] [--main] [--graph]

	...

* ``--detail``: Provides a detailed view of your hive's dependencies, grouping your source cells with their corresponding source blocks (those contained within the ``blocks`` folder of your hive). For each file, the command shows information about it's name and type, the presence or not of a ``main`` function, and the full list of dependencies for each particular cell, grouped under the *explicit* (those dependencies explicitly referenced in your code, as C++ includes or python imports), *implicit* (deduced from code inspection, i.e. C++ implementation files of symbols defined in a header file), and *system* (grouping all system dependencies of a file) sections.

* Parameters for **filtering the cells to be analyzed**, whose dependencies are to be displayed. The command provides 4 different options for filtering the results:

	* ``--blocks [BLOCKS]`` allows you to filter dependencies by block name. Example:

		.. code-block:: bash

			$ bii deps --blocks fenix/blink

	* ``--files [FILES]`` receives a list of cell names to be included in the result. Those files not contained in the list are omitted. Example:

		.. code-block:: bash

			$ bii deps --files fenix/blink/blink.h

	* ``--virtual`` indicates the client to show only those virtual cells contained in your hive.
	* ``--main`` is used for displaying information about cells that contain a ``main`` function or entry point to your code.

* Parameters for **filtering the dependencies**. These allow you to specify you want the client to show their dependencies:

	* ``--unresolved`` shows only your cells' unresolved dependencies; those that are unknown by biicode, and cannot be retrieved from our servers using the :ref:`find command<bii_find_command>`.
	* ``--system`` make the command show only system dependencies for your cells.
	* ``--implicit`` shows only implicit dependencies for your cells.
	* ``--explicit`` shows only those dependencies explicitly referenced in your files.
	* ``--data`` filters the results showing only data dependencies.

* ``--graph``: This last option provides a **visual representation** of your blocks and their dependencies. The client generates an interactive graph that is open in your web browser. Despite most of the code is saved on your local filesystem, you'll need an internet connection for loading some aditional libraries.

	Bellow you can see an example of these representations generated for a sample *'hello world'* block. In this case there are no external dependencies, and only those blocks contained in the ``blocks`` folder of your hive (the ``user/hello_world`` bock) are represented, and grouped under the 'SRC' element. There is also one system dependency. You can click on the different nodes to expand and show their content. You can also drag every node, or pan and zoom the whole graphic.

	.. raw:: html

		<iframe src="/_static/graphs/hello_world/hello_world.html" width="100%" height="600px"></iframe>

	* Double-clicking on any empty area **resets the pan and zoom** to their initial values.
	* All dependencies are represented as **colored connections** (red for implicit dependencies, blue for explicit dependencies, and yellow for all system dependencies). All unresolved dependencies are displayed in a dark grey color.
	* Virtual cells are related to their possible implementations using **green connections**.
	* You can show or hide any type of dependency just clicking on their corresponding toolbar buttons.
	* Dragging a node while holding the *shift* key allows you to move also all its descendant nodes (those folders and cells contained in that particular node, that are currently visible on the graph).
	* The outer color of each cell corresponds to the color of its block, while the inner color gives information about the particular cell type (cpp, python, etc.).



.. _bii_info_command:

``bii info``: Hive information
------------------------------

This command shows some **general information about the hive you are currently working on**. This information comprehends two fundamental aspects of the blocks contained in your hive:

* The :ref:`tracking info<bii_info_tracking>`, or the last published version of the code you are editing in your block.
* The :ref:`merges info<bii_info_merges>`, showing the published code that has been merged into your edition blocks, before they are published.

.. _bii_info_tracking:

Tracking information
^^^^^^^^^^^^^^^^^^^^

The tracking information **provides insight about the origins of each of the blocks** currently contained in the ``blocks`` folder of your hive, which are being edited by you and are susceptible of :ref:`being shared in a new publication<bii_publish_command>`. This is the block, branch and version of the code you are currently editing. This information can find its origin in three different types of events regarding your blocks:

* You have **published** at least one version of a block, and you continue working on it. In this case the tracking information contains the last published version of your code: ``<block_name>(branch_name): <version>``.

* You have performed an :ref:`open of a given block<bii_open_command>` in order to make some modifications or adaptations. In this case the source code of this block is automatically copied by the biicode client to the ``blocks`` folder of your hive, and the tracking information reflects the fact that the code contained in this particular block is based on the code of the opened block.

* You have just **created** a new unpublished block in your hive. In this case, no tracking information is available. You'll have to publish your block first!

In the first two scenarios, **the tracking information provides details about the code that serves as the basis for your edition**. You can think of this information as the code that is in the same *track* as your *unpublished block*, just one step before. When you perform a new publication of your block this information will be updated precisely with the name of the branch and version just published.

Imagine you are the original creator of the ``dummy`` block, and your are working on the ``master`` branch of this block, where you have performed 10 publications (from 0 to 9). This means that your last published version is ``username/dummy(username/master): 9`` (where ``username`` is, as you could expect, your username). This is the tracking block version for your local ``dummy`` block, contained in your hive. Executing the ``bii info`` command you would see the following output on your console:

.. code-block:: bash

	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/master): 9

	Merges info:
	============
	No merges found in this hive.

Now, let's suppose you decide to open in the same hive a dependency block ``simple``, owned by one of your biicode buddies, with username ``buddy``. To accomplish this, you should use the ``bii open`` command as follows:

.. code-block:: bash

	$ bii open buddy/simple

Reached this point, your hive should contain both a ``dummy`` block (in ``your_hive/blocks/username/dummy)``), and a editable copy of the ``simple`` block (in ``your_hive/blocks/buddy/simple``). Moreover, if you check again your hive info, you will get a different ouput reflecting the changes in your hive:

.. code-block:: bash

	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/master): 9
	[B]: buddy/simple
	  Tracking: buddy/simple(buddy/master): 3

	Merges info:
	============
	No merges found in this hive.

Given that you didn't specify any branch or version information in the ``bii open``, the client has retrieved the last published version (``3``, in this case) available in the master branch of the owner user (``buddy/master``).

Now, after having worked for a while in your hive, you are happy with the results and decide to share your code with other biicode users. As you can only pubish one block at a time, let's suppose you decide to publish first your modifications to your local copy of the ``buddy/simple`` block. In this case you must specify the ``--branch`` information to create your own branch with the modifications of another user's block:

.. code-block:: bash

	$ bii publish --block buddy/simple --branch my_simple_branch
	...
	...
	INFO: Successfully published buddy/simple(username/my_simple_branch): 0

The output of the previous command indicates that the first (``0``) version of the ``username/my_simple_branch`` branch of ``buddy/simple`` block has just been published. Your hive information has also been updated:

.. code-block:: bash

	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/master): 9
	[B]: buddy/simple
	  Tracking: buddy/simple(username/my_simple_branch): 0

	Merges info:
	============
	No merges found in this hive.

Note that your local copy of the ``buddy/simple`` block **is now tracking a different branch and version; the one that you just published**.

Now, you are ready to understand the following sequence of commands. Otherwise, do not hesitate to check our forum and get some answers in the `Client section of the biicode forum <http://forum.biicode.com/category/client>`_.

.. code-block:: bash

	$ bii publish --block username/dummy
	...
	...
	INFO: Successfully published username/dummy(username/master): 10
	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/master): 10
	[B]: buddy/simple
	  Tracking: buddy/simple(username/my_simple_branch): 0

	...
	... some code modifications, building and verifying your program
	...
	$ bii publish --block username/dummy --branch sampling
	...
	...
	INFO: Successfully published username/dummy(username/sampling): 0
	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/sampling): 0
	[B]: buddy/simple
	  Tracking: buddy/simple(username/my_simple_branch): 0

	...
	... some code modifications, building and verifying your program
	...

	$ bii publish --block buddy/simple
	...
	...
	INFO: Successfully published buddy/simple(username/my_simple_branch): 1
	$ bii info

	Tracking info:
	==============
	[B]: username/dummy
	  Tracking: username/dummy(username/sampling): 0
	[B]: buddy/simple
	  Tracking: buddy/simple(username/my_simple_branch): 1

	...
	... and so on ...
	...

.. _bii_info_merges:

Merges information
^^^^^^^^^^^^^^^^^^

This part of the ``bii info`` command output shows information **only in case you have performed any merges in your current hive**. Following the example introduced in the :ref:`section that exaplined the merge command<bii_merge_command>`, let's assume you have just merged a ``original/mathematyka(improver/better_math): 5`` version into your local copy of the ``mathematyka`` block, with branch and version: ``original/mathematyka(original/master): 25``. Now, the output of the client info utility would be as follows:

.. code-block:: bash

	$ bii info

	Tracking info:
	==============
	[B]: original/mathematyka
	  Tracking: original/mathematyka(original/master): 25

	Merges info:
	============
	[B]: original/mathematyka
	  Merged: original/mathematyka(improver/better_math): 5

This information about the merges performed in your code is only available locally, and while you haven't published the modifications to your edition block. See the ouput of the ``bii info`` command after you have published the changes, and try to understand its meaning:

.. code-block:: bash

	$ bii publish --block original/mathematyka
	...
	INFO: Successfully published original/mathematyka(original/master): 26

	$ bii info

	Tracking info:
	==============
	[B]: original/mathematyka
	  Tracking: original/mathematyka(original/master): 26

	Merges info:
	============
	No merges found in this hive.


.. _bii_status_command:

``bii status``: Hive status
-----------------------------------

``bii status`` command indicates you if there are changes in your code.

For example, if you have not changes:

.. code-block:: bash

	$ bii status
	INFO: Everything up to date

If you have changes in a ``main.cpp`` file:

.. code-block:: bash

	$ bii status
	[USER]/[BLOCK_NAME]

	  Modified:
	    [USER]/[BLOCK_NAME]/main.cpp


.. _bii_diff_command:

``bii diff``: Compare files
------------------------------

Compare files and show differences with ``bii diff <block_name>`` command. You can compare your current hive with previous published versions or compare between published versions.

For example, if you want to see the changes in your local block with the saved last current version.

.. code-block:: bash

	$ bii diff [user]/[block]

Now you have published new two versions and you'd want to know the ``diff`` between your ``current local block`` with the first version (``version=0``) published in biicode:

.. code-block:: bash

	$ bii diff [user]/[block] --v1 0

Now, if you'd want to know the ``diff`` between the ``version=0`` and ``version=1`` published:

.. code-block:: bash

	$ bii diff [user]/[block] --v1 0 --v2 1


.. _bii_settings_command:

``bii settings``: Hive settings 
----------------------------------

This command shows your current hive settings. This is an example of a hive with Arduino language:

.. code-block:: bash

	$ bii settings
	INFO: These are your settings for this hive
	INFO: arduino:
	  board: uno
	  builder: {family: make, subfamily: mingw}
	  port: None
	  programmer: usbtinyisp
	os: {arch: 32bit, family: Windows, subfamily: '8', version: 6.2.9200}

	INFO: If you want to change it, you have to modify this file:
	    [HIVE_PATH]/[USER]/bii/settings.bii
