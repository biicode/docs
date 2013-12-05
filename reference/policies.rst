
.. _filefilter:

Policies
---------------

Policies are the rules followed when finding or updating dependencies. They can be configured globally in your_workspace/bii/default_policies.bii or individually in your_hive/bii/policies.bii.

policies.bii have this format as self-documented:::

	# This is the file for configuring your finds of dependencies. You can have
	# several policies defined, each one with its own name. The 'default' policy
	# will be use if you dont specify a policy name in your finds.
	#
	# Each policy is an ordered list of patterns, if the block name, matches the
	# 'block' field in a regex sense, then, the rules will be evaluated in order.
	# The first rule to be evaluated as True, returns its priority. Each rule has
	# three fields, the first one is a rule for the block, in which both the block
	# name and the branch can be checked. The second field is a version rule, you
	# can check here the 'tag' of the version, and even the version index 'v'

	default:
	- block: .  # Dot . is the pattern for all blocks
	rules:
	#First rule is accept with priority 1 all 'master' branches of the original
	#creator of the block, with category STABLE
	- [branch.name == "master" and branch.user == block.user, tag==STABLE, 1]
	#	Examples:
	# To accept with priority 1 all 'master' branches of the original creator of
	# the block with category STABLE, or with any category for my 'master' blocks
	# - [branch.name == "master" and branch.user == block.user, tag==STABLE or branch.user == YOUR_USERNAME, 1]

Notes:

* **Priorities are ascending**. A policy rule with priority 2 will be applied before a policy rule with priority 0
* branch.name, branch.user, block.user, block.name and tag are **internal variables** that will be evaluated by biicode
* tag can be compared against **STABLE**, **DEV** and **ALPHA** constants. The have a sorted relation so you can say tag >= DEV
