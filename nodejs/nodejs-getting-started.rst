.. _hello_world_node:

Getting Started
===============
This example shows **how to install biicode and code a node.js redis client**. You don't need to have installed redis, biicode will download for you.

You will learn how to use the ``redis`` file of the ``noderedis`` block owner of ``mrnney`` with the code line ``require("mranney/noderedis/redis")`` .

1. Installing biicode and node.js
---------------------------------

For reuse code, you need to install biicode and node.js.

   - Download the biicode installer.

+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|Latest version 1.0                                                                                                                                                                                                                                                                                                           |
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+
|`MacOS <https://www.biicode.com/downloads>`_        |`Raspberry Pi <https://www.biicode.com/downloads>`_ |`Ubuntu 32 <https://www.biicode.com/downloads>`_    |`Ubuntu 64 <https://www.biicode.com/downloads>`_    |`Windows <https://www.biicode.com/downloads>`_      |`Devian Wheezy <https://www.biicode.com/downloads>`_|
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+


   - Download and install on your system the appropriate `version of Node.js <http://nodejs.org/download>`_ . 

2. Create your project
----------------------

To create a new project running ``bii init`` with the project name as a parameter.

.. code-block:: bash

   ~$ bii init node_hello_project
   
This command will create the following layout:

.. code-block:: text

   |-- node_hello_project
   |    +-- bii
   |    +-- blocks
   |    +-- deps
   
Now, we will create a block. a block is the place where you must place your code. Execute ``bii new anonymous/my_fist_block`` into the project folder to create a block.

.. code-block:: bash

   ~$ cd node_hello_project
   ~/node_hello_project$ bii new anonymous/my_first_block --hello=node

This command will create the following layout:

.. code-block:: text

   +-- node_hello_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- anonymous
   |    |    |    +-- my_first_block
   |    |    |    |    +-- main.js
   |    +-- deps

.. container:: infonote

    **why this layout?**

    This layout is because biicode analyse the dependencies of yours blocks and download it into de deps folder. It is important because biicode configure and build your project following this layout.

    For this reason, all the code you want to be analyzed must place into a block inside the blocks folder.

    The structure of this blocks is composed by two parts, the user owner and the block name. In this example we use the anonymous user, but if you want to publish your own blocks in the future, you need to create a biicode user and use that user name.


    If you want to change the user of a block into your blocks folder, just change the name folder where are this block.


3. Resolve your dependencies
----------------------------

Now, edit your main.js file with the following code and execute ``bii find``. With this command, all your dependencies will be downloaded.

**main.js**

.. code-block:: js
   :emphasize-lines: 1

	var redis = require("mranney/noderedis/redis"),
		client = redis.createClient(); 
	client.set("string key",
			   "string val", 
			   redis.print);
	client.quit(function (err, res) {
	  console.log("Exiting from quit command.");
	});

.. code-block:: bash

   ~/node_hello_project$ bii find

Now, execute your script main.js.

.. code-block:: bash

   ~/node_hello_project$ cd blocks/my_first_block
   ~/node_hello_project/blocks/my_first_block$ #execute your script

And that's all. Your program is working!