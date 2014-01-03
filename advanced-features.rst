Advanced features
=================

This section describes some advanced functionalities provided by biicode. Using these features, you will able to have a better control of your projects, defining **virtual resources**, defining advanced **compilation rules**, or even taking deeper control of the way your **dependencies** are found and retrieved.

.. _settings:

The settings file
-----------------

Every hive contains a special file which allows yo to define some custom settings for your project. This file is located in the ``bii`` folder of your hive, and its name is ``settings.bii``.

The biicode client generates this file for you when you create a new hive. Initially, it contains only information regarding your platform: architecture, operating system, and version. When you compile your project som additional information is included regarding the builder, compiler and configurer to be used.

You can also specify your own settings for that particular project. This information will be used, for instance, for defining the virtual resources that will be explained in a few paragraphs. You can read more about :ref:`settings.bii <settings_bii>` :ref:`here <settings_bii>`


Virtual resources
-----------------

Virtual resources are those whose actual implementation depends on the current compilation platform, or any other conditions you may want to specify. These conditions are specified in a special ``virtual.bii`` file, for every block, using simple python code.

Imagine you want different code to be compiled or executed depending on different conditions, like whether you are in a production or a testing environment, Windows or Linux platforms, or even the compiler version. This is possible making use of **virtual resources**.

So, let's say you have this ``main.cpp`` and two different versions of ``sphere.h`` and its corresponding implementation file ``sphere.cpp``, under two separate folders called ``test`` and ``development``.

.. code-block:: cpp
	:linenos:

	#include "sphere.h"

	using namespace std;
	int main() {
		Sphere s(2.0f);
		cout << "Volume: " << s.volume() << endl;
		return 1;
	}

Note that the ``main.cpp`` file includes the ``sphere.h`` header file, but makes no reference to the actual location of this resource —and the corresponding implementation, ``sphere.cpp``—. In fact, there is no such file as ``sphere.h`` located in the same folder as ``main.cpp``. The actual file to be included in your code is determined by a spectial ``virtual.bii`` configuration file, written in python language. You need to create this file in your block's ``bii`` folder, and write the code that selects the virtual resource to be used in each case. **Every rule is implemented as a python function** —you can give it whatever name you want—, **whose docstring contains the list of resurces affected by that particular rule**.

In this example we are defining a function that decides which implementation of the ``sphere.h`` and ``sphere.cpp`` resurces is to be used depending on the presenece or not of the ``test`` key in our project secttings. **The return vale for this function must be the name of the folder containing the valid implementations of the virtual resources** for each condition —in our case, the ``test`` folder, or the ``develop`` folder—.

.. code-block:: python
	:linenos:

	def func(settings):
		"""sphere.h sphere.cpp"""
		if settings.user.get('test'):
			return "test"
		else:
			return "develop"

The ``virtual.bii`` file —as other biicode configuration files— is written in python language. It is not possible to make any imports, but you will have direct access to the project settings, received as a parameter. In this case a custom setting ``test`` is being used, and we are checking for its presence inside a python function.

.. _compilation_rules:

Compilation rules
-----------------

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


Edit dependencies
-----------------

If you want to edit a block you depend on, you can open it and move it to your hive. You can do so by executing:

.. code-block:: bash

	$ bii open BLOCK_NAME

Where BLOCK_NAME is DEP_OWNER/DEP_NAME

Then you can work as if the block was yours and the changes you make will be reflected in your code at build time.

Once you are happy with the changes you can publish your own version of the block:

.. code-block:: bash

	$ bii publish BLOCK_NAME --branch BRANCH_NAME

Unless the code is yours you will not be able to publish it to an existing branch, so you will need to specify a BRANCH_NAME.

Then you can close the block to remove it from your blocks folder:

.. code-block:: bash

	bii close BLOCK_NAME

Your code will now depend on the version you have just published.


Merge a branch
--------------

Imagine you have a published block and someone just published a bugfix in a new branch and you want to incorporate those changes to the master version of your block.

Merging a branch is very simple:

.. code-block:: bash

	$ bii merge --block BLOCK_NAME --version VERSION_NUMBER

Then you can review changes and publish your new version as usual.

.. code-block:: bash

	$ bii publish BLOCK_NAME

Manually configuring dependencies
---------------------------------

There are some special cases in which biicode can't detect some dependencies. In these cases **you can manually configure your dependencies**.

For this purpose you can use :ref:`dependencies.bii <dependencies_bii>`

.. _advanced_policies:

Policies
--------

Start with a new hive in your **biicode workspace** directory:

.. code-block:: bash

	$ bii new policies

Create a ``main.cpp`` file which includes the block ``policyadvanced`` to use the ``hello()`` method declared in the ``hello.h`` file. Given that the owner of this block is the ``tutorial`` user we should write the following code:

**main.cpp**

.. code-block:: cpp
	:linenos:

	#include "tutorial/policyadvanced/hello.h"
	 
	int main(void){
	   hello();
	   return 1;
	}

If you check the output after runnig the code:

.. code-block:: bash

	$ bii cpp:run
	...
	Hello STABLE

Examining the ``tutorial/policyadvanced`` block in biicode (`available in this location <https://www.biicode.com/tutorial/blocks/tutorial/policyadvanced/branches/master>`_), we find four published versions with different tags:

.. raw:: html

	<div class="table-responsive"><table border="1" class="docutils">
	<colgroup>
	<col width="22%">
	<col width="22%">
	<col width="55%">
	</colgroup>
	<thead valign="bottom">
		<tr class="row-odd">
			<th class="head">Published index</th>
			<th class="head">Version</th>
			<th class="head">Output of hello() method</th>
		</tr>
	</thead>
	<tbody valign="top">
		<tr class="row-even">
			<td>3</td>
			<td>DEV</td>
			<td>“Hello DEVELOP”</td>
		</tr>
		<tr class="row-odd">
			<td>2</td>
			<td>ALPHA</td>
			<td>“Hello ALPHA”</td>
		</tr>
		<tr class="row-even">
			<td>1</td>
			<td>BETA</td>
			<td>“Hello BETA”</td>
		</tr>
		<tr class="row-odd">
			<td>0</td>
			<td>STABLE</td>
			<td>“Hello STABLE”</td>
		</tr>
	</tbody>
	</table>
	</div>

Being **index=0** the first uploaded version, each one has a different ``hello()`` method implementation depending on its version.

The reason why your program has executed ``hello()`` of ``STABLE`` version is as follows. Check the contents of the ``policies.bii`` file located inside your ``~/your_bii_workspace/policies/bii/`` folder. This is a simple YAML file with the following appearance: ::

	default:
	- block: . # Dot . is the pattern for all blocks
	 rules:
	 #First rule is accept with priority 1 all 'master' branches of the original
	 #creator of the block, with category STABLE
	 - [branch.name == "master" and branch.user == block.user, tag==STABLE, 1]

Then, your policy for this hive makes your searches are in master branchs of anyone user block and all the blocks as ``STABLE`` versions.

Changing your policy tag
------------------------

Search BETA versions
^^^^^^^^^^^^^^^^^^^^

Modify the ``policies.bii`` file as shown here: ::

 - [branch.name == "master" and branch.user == block.user, tag==BETA, 1]

You have just modified your default policy file. Now, you only need to update your hive to reflect the changes using the following command:

.. code-block:: bash

	$ bii find --update

	Finding missing dependencies in server
	Analyzing compatibility for found dependencies...
	   Updated block!
	Dependencies resolved in server:
	All dependencies resolved
	Updated dependencies:
	tutorial/tutorial/policyadvanced/master:#1

	Saving files on disk
	Computing dependencies
	Saving dependences on disk

Now, you can run your code:

.. code-block:: bash

	$ bii cpp:run
	...
	Hello BETA

As you can see, now you are using the ``BETA`` version of the ``tutorial/policyadvanced`` block!

Advanced tag selection
^^^^^^^^^^^^^^^^^^^^^^

Finally, you could look for by published order with your tags. For example, if you write: ::

	- [branch.name == "master" and branch.user == block.user, tag>DEV, 1]

This type will look for any blocks with any tag published before ``DEV`` version block uploaded to biicode.

Update the dependencies again and run the code:

.. code-block:: bash

	$ bii find --update
	...
	$ bii cpp:run
	...
	Hello ALPHA

Given that the ``ALPHA`` version was published before the ``DEV`` one, this is the one chosen to resolve your dependency.

Special attention
^^^^^^^^^^^^^^^^^

Modify your ``policies.bii`` file again to get the last version (in this example ``DEV`` version) ::

	- [branch.name == "master" and branch.user == block.user, tag==DEV, 1]

Once more find the dependencies and execute your code:

.. code-block:: bash

	$ bii find --update
	...
	$ bii cpp:run
	...
	Hello DEVELOP

However if you try to change the policies to link with an older version (for example, ``BETA`` version), you will get this output:

.. code-block:: bash

	$ bii find --update

	Finding missing dependencies in server
	Analyzing compatibility for found dependencies...
	Everything was up to date
	Computing dependencies
	Saving dependences on disk

You could get an older version after using an updated one just like this:

.. code-block:: bash

	$ bii find --update --downgrade

	Analyzing compatibility for found dependencies...
	   Updated block!
	Dependencies resolved in server:
	All dependencies resolved
	Updated dependencies:
	   tutorial/tutorial/policyadvanced/master:#1

	Saving files on disk
	Computing dependencies
	Saving dependences on disk

Changing your policy file for all your new hives
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You could be sure to keep a specified policies for all the new hives. It is possible!

In your biicode workspace, inside the ``bii`` folde, you will find another policy file named ``default_policies.bii``. The changes that you make here will be copied to all new hives and not old hives.
