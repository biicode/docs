.. _bii_buzz_command:

**bii buzz:** init, find and build
------------------------------

**bii buzz** is an all-in-one purpose command that combines different actions: initialize project, find dependencies and build the block.

**bii buzz** automates the following commands:

	* **bii init -L**: Initializes biicode project with simple layout.

	* **bii find**: Finds external dependencies of your block.
	
	* **bii build**: Builds your project.

It is useful for a quick getting started of a new project or after cloning a git repository. 

To use it, go to your normal project directory and **bii buzz**:

.. code-block:: bash

 $ cd my_project
 $ bii buzz

.. container:: infonote

 Wirte your :ref:`biicode.conf <biicode_conf>` file before doing **bii buzz** to let biicode find your right dependencies.