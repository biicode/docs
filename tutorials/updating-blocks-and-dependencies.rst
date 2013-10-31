Updating blocks and dependencies
================================

If you want to make changes to your block you only need to publish a new version: ::

	$ bii work
	$ bii publish

It will be published to a master branch by default. It is possible to create a new branch with the --branch option: ::

	bii publish --branch branchname

If you wish to update your existing dependencies to newer versions you will need to do the following: ::

	bii find --modify-existing

Biicode will automatically update your dependencies if there's a compatible set with newer versions.

If you wish to move to a new branch you will need to edit your policies file.