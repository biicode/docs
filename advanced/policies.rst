.. _advanced_policies:

Policies (tutorial)
======================

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
