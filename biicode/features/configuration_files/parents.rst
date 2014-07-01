.. _parents_bii:

parents.bii
===========
``parents.bii`` is **created whenever you publish a block**, inside the ``bii`` block folder ::

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

It  provides insight about the origins of each of the blocks currently contained in the blocks folder of your project. 

For example, you have the above layout and you've already done your first publication, then your ``parents.bii`` would have the next content:

.. code-block:: text

	# This file contains your block ancestors versions
	* user25/my_hello_block: 0

What say us?

* Parent (previous publication to our editing block): ``user25/my_hello_block``
* Branch: ``master`` (in this case, it doesn't appear because it's the default branch)
* Version block: ``0``
|
.. container:: infonote

	Take a look at the asterisk, it indicates you who's your block parent.


Now, you decide to make a branch of this block named *my_pretty_branch*, and you have published two versions (versions 0 and 1), then your ``parents.bii`` would be like this:

.. code-block:: text

	# This file contains your block ancestors versions
	* user25/my_hello_block(my_pretty_branch): 1

It means:

* Parent: ``user25/my_hello_block`` 
* Branch: ``my_pretty_branch`` 
* Version block: ``1``
|
Finally, if you want to merge this branch to *master* branch, the ``parents.bii`` content would be:

.. code-block:: text

	# This file contains your block ancestors versions
	* user25/my_hello_block: 0
	user25/my_hello_block(my_pretty_branch): 1

So, information gives us:

* ``user25/my_hello_block(my_pretty_branch):1`` (merge branch) has been merged to ``user25/my_hello_block(master):0`` (parent branch).

.. container:: infonote

	Visit the section: :ref:`how to publish branches and make merges <publish_branch_merge>`

