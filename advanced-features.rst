Advanced features
=================

Virtual resources
-----------------

Imagine you want different code to be compiled or executed depending on whether you are in a production or testing environment, Windows or Linux or compiler version. This is possible with virtual resources.

So, let's say you have this main.cpp and you have two versions of sphere.h and its implementation under a couple of files called "test" and "development".

.. code-block:: cpp
	:linenos:

	using namespace std;
	int main() {
	    Sphere s(2.0f);
	    cout << "Volume: " << s.volume() << endl;
	        return 1;
	}

Then you can write a virtual.bii file in your block's bii folder to select which one is going to be used:

.. code-block:: python
	:linenos:

	def func(settings):
	    if settings.user.get('test'):
	    return "test"
	    else:
	    return "develop"

virtual.bii files —as other configuration files— are written in python, so it is not possible to make any imports, but you will have direct access to settings. In this case a custom setting 'test' is being used and we are checking for it's presence.

Compilation rules
-----------------

Sometimes your project need to define some preprocessor variables or maybe you need to link with some dynamic library provided by the system. Biicode gives you the option to define these special compilation needs.

You can define rules file for each executable target. Rules files can be placed anywhere in your src directory with a filename following the next regular expression:

:regexp:`\*cpp_rules*\.bii`

These files are written in Python, a small subset of it. You can interact with hive settings and target properties.

You can see an example of this kind of files.

.. code-block:: python
	:linenos:

        target.std = "c++11"

        if "matrix.cpp" in target.filenames:
           target.add_definition("OPTMIZE_MATRIX=1")

        if settings.os.family == "MacOS":
           target.add_package("OpenGL",[])
           target.add_library("${OPENGL_LIBRARIES}")

.. _dependencies_edition:

Dependencies edition
--------------------

If you want to edit a block you depend on, you can open it and move it to your hive. You can do so by executing: ::

	bii open BLOCK_NAME

Where BLOCK_NAME is DEP_OWNER/DEP_NAME

Then you can work as if the block was yours and the changes you make will be reflected in your code at build time.

Once you are happy with the changes you can publish your own version of the block: ::

	bii publish BLOCK_NAME --branch BRANCH_NAME

Unless the code is yours you will not be able to publish it to an existing branch, so you will need to specify a BRANCH_NAME.

Then you can close the block to remove it from your src folder: ::

	bii close BLOCK_NAME

Your code will now depend on the version you have just published.


Merge a branch
--------------

Imagine you have a published block and someone just published a bugfix in a new branch and you want to incorporate those changes to the master version of your block.

Merging a branch is very simple: ::

	$ bii merge --block BLOCK_NAME --version VERSION_NUMBER

Then you can review changes and publish your new version as usual. ::

	$ bii publish BLOCK_NAME

Dependencies configuration
--------------------------

There are cases in which biicode can't detect some dependencies. In these cases you can manually configure your dependencies.

For this purpose you should create a new folder within your src and inside of this bii folder a file named **dependencies.bii**.

The format of this file is: ::

	dependent_file_name [-+=] NULL|[[!]dependency_file ]+

It's a file separated by spaces.

Depending on specified operator after the dependent file name, it will behave differently:

* With the - operator all specified dependencies will be deleted from their dependent file.
* With the + operator all specified dependencies will be added to their dependent file.
* With the = operator all specified dependencies will overwrite existing dependencies.

If you mark a dependency with a ! symbol you are declaring this file a dependency but it should be excluded from the building process.

Also, you can declare that a file doesn't depend on nothing using NULL keyword.

Dependent_file_name could be defined using Unix filename pattern matching.

==========	========================================
Pattern 	Meaning
==========	========================================
\*			Matches everything
?			Matches a single character
[seq]		Matcches any character in seq
[!seq]		Matches any character not in seq
==========	========================================

An example of this file is: ::

	test.cpp + example.h !LICENSE
	*.cpp + !README
	example.h = NULL
	main.cpp + matrix32.h
	main.cpp - matrix16.h
	calculator.cpp = solver.h type.h

In this example we're declaring that test.cpp depends on example.h and LICENSE, but LICENSE mustn't be compiled.

Also, we're declaring that all files with a cpp extension depend on the README file but it mustn't be compiled.

Declaring example.h = NULL all example.h dependencies are deleted.

In the forth line we add matrix32.h as a main.cpp dependency.

In the next line we are deleting matrix16.h as a main.cpp dependency.

Finally, we're declaring that solver.h and type.h are calculator.cpp dependencies, ovewriting all existing implicit dependencies.


Policies
--------

Start with a new hive in your Biicode workspace directory: ::

	$bii new policies

Create a main.cpp which includes the block policyadvanced to use hello() method and its owner is tutorial user. It would be like this:

**main.cpp**

.. code-block:: cpp
	:linenos:

	#include "tutorial/policyadvanced/hello.h"
	 
	int main(void){
	   hello();
	   return 1;
	}

If you check the output after runnig the code ::

	$bii cpp:run
	...
	Hello STABLE

Examining the user tutorial/policyadvanced block in Biicode, there are published four versions with different tags:

================	========== 	====================================
Published index 	Version 	Output method hello() 
================	========== 	====================================
3	 				DEV	    	"Hello DEVELOP"
2	 				ALPHA	    "Hello ALPHA"
1	 				BETA		"Hello BETA"
0	 				STABLE		"Hello STABLE"
================	========== 	====================================

Being index=0 the first version uploaded, each one has a different method hello() depending on its version.

The reason why your program has executed hello() of STABLE version is as follows. Look at folder  ~/your_bii_workspace/your_hive/bii/ named policies.bii which is a YAML file and has this appearance: ::

	default:
	- block: . # Dot . is the pattern for all blocks
	 rules:
	 #First rule is accept with priority 1 all 'master' branches of the original
	 #creator of the block, with category STABLE
	 - [branch.name == "master" and branch.user == block.user, tag==STABLE, 1]

Then, your policy for this hive makes your searches are in master branchs of anyone user block and all the blocks as STABLE versions.

Changing your policy tag
------------------------

Search BETA versions
^^^^^^^^^^^^^^^^^^^^

Modify the policies.bii ::

 - [branch.name == "master" and branch.user == block.user, tag==BETA, 1]

You have just modified your default policy file, then you have to write in console: ::

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

Run your code: ::

	$ bii cpp:run
	...
	Hello BETA

Like you can see, you are using BETA version!

Advanced tag selection
^^^^^^^^^^^^^^^^^^^^^^

Finally, you could look for by published order with your tags. For example, if you write: ::

	- [branch.name == "master" and branch.user == block.user, tag>DEV, 1]

This type will look for any block with any tag published before DEV version block uploaded to Biicode.

Update the dependencies again and run the code: ::

	$ bii find --update
	...
	$ bii cpp:run
	...
	Hello ALPHA

Given that the ALPHA version was published before the DEV one, it is the chosen to resolve your dependency.

Special attention
^^^^^^^^^^^^^^^^^

Modify your policies.bii again to get the last version (in this example DEV version) ::

	- [branch.name == "master" and branch.user == block.user, tag==DEV, 1]

Once more find the dependencies and execute: ::

	$bii find --update
	...
	$bii cpp:run
	...
	Hello DEVELOP

However if you try to change the policies to link with an older version (for example, BETA version), you will get this output: ::

	$ bii find --update

	Finding missing dependencies in server
	Analyzing compatibility for found dependencies...
	Everything was up to date
	Computing dependencies
	Saving dependences on disk

You could get an older version after using an updated one just like that: ::

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

In your Biicode workspace, at folder bii, you have another policy file named default_policies.bii. The changes that you make here will be copied to all new hives and not old hives.

