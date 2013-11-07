Advanced Features
=================

Virtual Resources
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

        if "matrix.cpp" in target.filenames:
           target.add_definition("OPTMIZE_MATRIX")


Edit Dependencies
-----------------

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


Merge a Branch
--------------

Imagine you have a published block and someone just published a bugfix in a new branch and you want to incorporate those changes to the master version of your block.

Merging a branch is very simple: ::

	$ bii merge --block BLOCK_NAME --version VERSION_NUMBER

Then you can review changes and publish your new version as usual. ::

	$ bii publish BLOCK_NAME

Dependencies Configuration
--------------------------

There are cases in which biicode can't detect some dependencies. In these cases you can manually configure your dependencies.

For this purpose you should create a new folder within your src and inside of this bii folder a file named dependencies.bii.

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

Declaring example.h NULL all example.h dependencies are deleted.

In the forth line we add matrix32.h as a main.cpp dependency.

In the next line we are deleting matrix16.h as a main.cpp dependency.

Finally, we're declaring that solver.h and type.h are calculator.cpp dependencies, ovewriting all existing implicit dependencies.


C++ Compiling Options
---------------------

In your settings.bii file you can add compiler definiotions, specify C++ version and so on. ::

	cpp:
		builder: {family: MAKE}
		compiler: {family: GNU}
		std: c++11
		defines:
			MY_VAR: 1

* builder family valid values are 'MSBUILD', 'MAKE', 'MINGW' and 'NMake'
* compiler family valid values are 'GNU', 'MINGW' and 'VC'
* valid std are "c++11" and  "c++0x"
