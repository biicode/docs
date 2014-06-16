.. _parents_bii:

parents.bii
===========

This file is created when you publish a block inside the ``bii`` block folder and provides insight about the origins of each of the blocks currently contained in the blocks folder of your hive, which are being edited by you and are susceptible of being shared in a new publication. This is the block, branch and version of the code you are currently editing. This information can find its origin in three different types of events regarding your blocks:

* You have published at least one version of a block, and you continue working on it. In this case the parent information contains the last published version of your code: ``<block_name>(branch_name): <version>``.
|
* You have performed an open of a given block in order to make some modifications or adaptations. In this case the source code of this block is automatically copied by the biicode client to the blocks folder of your hive, and the parent information reflects the fact that the code contained in this particular block is based on the code of the opened block.
|
* You have just created a new unpublished block in your hive. In this case, no parent information is available. You’ll have to publish your block first!

In the first two scenarios, the parent information provides details about the code that serves as the basis for your edition. You can think of this information as the code that is in the same track as your unpublished block, just one step before. When you perform a new publication of your block this information will be updated precisely with the name of the branch and version just published.

This file can be modify manually with the concrete version you need.