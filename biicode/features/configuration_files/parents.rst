.. _parents_bii:

parents.bii
===========

This file is **automatically created**, **when you publish a block**, inside the ``bii`` block folder ::

|-- my_project
|    +-- bii
|    +-- bin
|    +-- blocks
|    |	  +-- user25
|    |    |     +-- my_hello_block
|    |    |     |     +-- bii
|    |    |     |     |    |-- parents.bii
|    |    |  	|     |-- hello.c
|    |    |     |     |-- hello.h

It  provides insight about the origins of each of the blocks currently contained in the blocks folder of your project. For example, you have the above layout and you've already done your first publication, then your ``parents.bii`` would have the next content:

.. code-block:: text

	# This file contains your block ancestors versions
	* user25/my_hello_block: 0

**What say us?**

* Parent (previous publication to our editing block): user25/my_hello_block 
* Branch: ``master`` 
* Version block: ``0``

Now, you decide to make a branch of this block named *my_pretty_branch*, and you have published two versions (versions 0 and 1), then your parents.bii would be like this:

.. code-block:: text

	# This file contains your block ancestors versions
	* user25/my_hello_block(my_pretty_branch): 1

It means:

* Parent: user25/my_hello_block 
* Branch: ``my_pretty_branch`` 
* Version block: ``1``

Finally, if you want to merge this branch to *master* branch, the parents.bii content would be:

.. code-block:: text

	# This file contains your block ancestors versions
	* user25/my_hello_block: 0
	user25/my_hello_block(my_pretty_branch): 1

So, information give us is: ``user25/my_hello_block(my_pretty_branch):1`` merged to ``user25/my_hello_block(master):0`` 


This is the block, branch and version of the code you are currently editing. This information can find its origin in three different types of events regarding your blocks:

* You have published at least one version of a block, and you continue working on it. In this case the parent information contains the last published version of your code: ``<block_name>(branch_name): <version>``.
|
* You have performed an open of a given block in order to make some modifications or adaptations. In this case the source code of this block is automatically copied by the biicode client to the blocks folder of your project, and the parent information reflects the fact that the code contained in this particular block is based on the code of the opened block.
|
* You have just created a new unpublished block in your project. In this case, no parent information is available. You’ll have to publish your block first!

In the first two scenarios, the parent information provides details about the code that serves as the basis for your edition. You can think of this information as the code that is in the same track as your unpublished block, just one step before. When you perform a new publication of your block this information will be updated precisely with the name of the branch and version just published.

This file could be modify manually with the concrete version you need.