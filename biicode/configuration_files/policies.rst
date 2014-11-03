.. _policies:

``policies.bii``: defining the policies of the code you want to reuse
======================================================================

Policies are just **rules the smart finder applies when finding or updating external dependencies.** They can be configured in your_project/bii/policies.bii as you can see in the :ref:`layouts section <project_layout>`.

``policies.bii`` have this format as self-documented:::

	# This is the file to configure your finds of dependencies. You can have
	# several policies defined, each one with its own name. The 'default' policy
	# will be use if you don't specify a policy name in your finds.
	#
	# Each policy is an ordered list of rules, which will be evaluated in order.
	# Each rule has three fields:
	#    block: an expression that can be evaluated using "block" objects.
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
	# First rule: accept all your published blocks for all tags
	# with priority 1.
	- block: block.user == "YOUR_USER_NAME"
	  version: tag>=DEV
	  priority: 1

	# For all other users only accept STABLE blocks
	- block: ALL 
	  version: tag==STABLE
	  priority: 1

	# Examples:
	# Let's say that you (maya) introduce a dependency to some cell in willy/block and
	# you want to reuse as a Beta tester of such block, you should write a new rule:
	#- block: block == "willy/block"
	#  version: tag>=BETA
	#  priority: 1
	#
	# If you want to accept all ALPHA VERSIONS of another user's published
	# blocks with priority 1.
	#- block: block.user == "ANOTHER_USER"
	#  version: tag==ALPHA
	#  priority: 1
	

**Notes**:

* **Priorities are ascending**. A policy rule with priority 2 will be applied before a policy rule with priority 0
* block.user, block.name and tag are **internal variables** that will be evaluated by biicode
* tag can be compared against **STABLE**, **BETA**, **DEV** and **ALPHA** constants. The have a sorted relation so you can say tag >= DEV


Policies tutorial
-----------------

Start with a new project:

.. code-block:: bash

	$ bii init policies

Create a ``main.cpp`` file which includes the block ``policyadvanced`` to use the ``hello()`` method declared in the ``hello.h`` file. Given that the owner of this block is the ``tutorial`` user we should write the following code:

**main.cpp**

.. code-block:: cpp
	:linenos:

	#include "tutorial/policyadvanced/hello.h"
	 
	int main(void){
	   hello();
	   return 1;
	}

If you check the output after running the code:

.. code-block:: bash

	$ bii cpp:run
	...
	Hello STABLE

Examining the ``tutorial/policyadvanced`` block in biicode (`available in this location <https://www.biicode.com/tutorial/policyadvanced>`_), we find four published versions with different tags:

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

Being **index=0** the first uploaded version, each one has a different ``hello()`` method implementation depending on the block's version.

The reason why your program has executed ``hello()`` of the ``STABLE`` version is as follows. Check the contents of the ``policies.bii`` file located inside your ``~/your_bii_workspace/policies/bii/`` folder. This is a simple YAML file with the following appearance: ::

	default:
	# First rule is accept with priority 1 
	# a specific published block for all tags.
	- block: block == "[ANY_USER/BLOCK]"
	  version: tag>=DEV
	  priority: 1
	# Then, accept with priority 1 all STABLE VERSIONS of another 
	# user, with category STABLE
	- block: block.user == "[ANY_USER]"
	  version: tag==STABLE
	  priority: 1

So, your policy for this project will make your searches in all matching versions (higher than ``DEV`` tag) of an specific block and in all ``STABLE`` versions of a specific user.

**Note**: Make sure you have defined any policy name as ``default:`` or any you want, else you'll get an error.


Changing your policy name
-------------------------

If you have defined another policy name as "my_policy", like this example: ::
	
	my_policy:
	# Rule to accept with ``STABLE`` tag your published blocks
	# with priority 1.
	- block: block.user == "[YOUR_USER]"
	  version: tag==STABLE
	  priority: 1
	  
	default:
	# Rule to accept with ``DEV`` tag another user's published 
	# blocks with priority 1
	- block: block.user == "[ANY_USER]" 
	  version: tag==DEV
	  priority: 1

In this case, you have two names to call different policies. In this case, if you want to select "my_policy" to get the dependencies according it, you only have to write this command:

.. code-block:: bash
	
	$ bii find --policy my_policy
	
Or

.. code-block:: bash
	
	$ bii find -p my_policy

If you don't specify any policy name, you are calling to ``default`` policies.
	

Changing your policy tag
------------------------

Search BETA versions
^^^^^^^^^^^^^^^^^^^^

Modify the ``policies.bii`` file as shown here: ::

	- block: block.user == block.
	  version: tag==BETA
	  priority: 1

You have just modified your default policy file. Now, you only need to update your project to reflect the changes using the following command:

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

	- block: block.user == "ANY_USER"
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

	- block: block.user == "ANY_USER"
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


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_