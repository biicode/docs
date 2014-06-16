.. _policies:

policies.bii
============

Policies are the rules applied when finding or updating dependencies. They can be configured globally in your_workspace/bii/default_policies.bii or individually in your_hive/bii/policies.bii as you can see in the :ref:`layouts section <layouts>`.

``policies.bii`` have this format as self-documented:::

	# This is the file for configuring your finds of dependencies. You can have
	# several policies defined, each one with its own name. The 'default' policy
	# will be use if you dont specify a policy name in your finds.
	#
	# Each policy is an ordered list of rules, which will be evaluated in order.
	# Each rule has three fields:
	#    block: an expression that can be evaluated using "block" and "branch"
	#            objects.
	#    version: an expression that can be evaluated using "tag" and "v" objects
	#    priority: a integer number, with the resulting priority if the two
	#            above conditions are true. Maximum priority is 0, negative
	#            priorities means reject (do not admit) such as dependency
	#
	# The rules will be evaluated IN ORDER for each possible block that could
	# resolve your dependencies. If the "block" and "version" conditions of a
	# rule are met, then the priority is returned and NO more rules are
	# evaluated. If the conditions are not met, then it continues. THUS THE
	# ORDER OF RULES IS VERY IMPORTANT
	# The priority indicates the order of find, but it is not a guarantee that
	# that will be the solution. For same priority versions, then the newest
	# ones are checked first

	default:
	# First rule is accept with priority 1 all your published blocks (master branches)
	# for all tags.
	- block: block.user == "YOUR_USER_NAME" and branch == "YOUR_USER_NAME/master"
	  version: tag>=DEV
	  priority: 1
	# Then, accept with priority 1 all 'master' branches of the original
	# creator of the block, with category STABLE
	- block: branch.name == "master" and branch.user == block.user
	  version: tag==STABLE
	  priority: 1

	# Examples:
	# Lets say that you (maya) introduce a dependency to some cell in willy/block(willy/master)
	# and you want to become a Beta tester of such block, you should write a new rule:
	#- block: block == "willy/block" and branch == "willy/master"
	#  version: tag>=BETA
	#  priority: 1
	# If you (maya) make a contribution to willy/block and publish it as a branch, you might
	# want to depend on it, for any tag, and prioritizing your branch:
	#- block: block == "willy/block" and branch == "maya/mybranch"
	#  version: tag>=DEV
	#  priority: 0  # This will give higher priority in the find process wrt to
	#               # willy/block(willy/master) STABLE versions

**Notes**:

* **Priorities are ascending**. A policy rule with priority 2 will be applied before a policy rule with priority 0
* branch.name, branch.user, block.user, block.name and tag are **internal variables** that will be evaluated by biicode
* tag can be compared against **STABLE**, **DEV** and **ALPHA** constants. The have a sorted relation so you can say tag >= DEV


Policies tutorial
-----------------

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
	# First rule is accept with priority 1 all your published blocks (master branches)
	# for all tags.
	- block: block.user == "[USER]" and branch == "[USER]/master"
	  version: tag>=DEV
	  priority: 1
	# Then, accept with priority 1 all 'master' branches of the original
	# creator of the block, with category STABLE
	- block: branch.name == "master" and branch.user == block.user
	  version: tag==STABLE
	  priority: 1

Then, your policy for this hive makes your searches are in master branchs of anyone user block and all the blocks as ``STABLE`` versions.

**Note**: Make sure you have defined any policy name as ``default:`` or any you want, else you'll get an error.


Changing your policy name
-------------------------

If you have defined another policy name as "my_policy", like this example: ::
	
	my_policy:
	# First rule is accept with priority 1 all your published blocks (master branches)
	# for all tags.
	- block: block.user == "[USER]" and branch == "[USER]/master"
	  version: tag==STABLE
	  priority: 1
	  
	default:
	# First rule is accept with priority 1 all your published blocks (master branches)
	# for all tags.
	- block: block.user == "[USER]" and branch == "[USER]/master"
	  version: tag==DEV
	  priority: 1

Then, you have two names to call different policies. In this case, if you want to select "my_policy" to get the dependencies according it, you only have to write this command:

.. code-block:: bash
	
	$ bii find --policy my_policy
	
Or

.. code-block:: bash
	
	$ bii find -p my_policy

If you don't specify any policy name, you call to ``default:`` policies.
	

Changing your policy tag
------------------------

Search BETA versions
^^^^^^^^^^^^^^^^^^^^

Modify the ``policies.bii`` file as shown here: ::

	- block: branch.name == "master" and branch.user == block.user
	  version: tag==BETA
	  priority: 1

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

	- block: branch.name == "master" and branch.user == block.user
	  version: tag>DEV
	  priority: 1

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

	- block: branch.name == "master" and branch.user == block.user
	  version: tag==DEV
	  priority: 1

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

In your biicode workspace, inside the ``bii`` folder, you will find another policy file named ``default_policies.bii``. The changes that you make here will be copied to all new hives and not old hives.