.. _node_getting_started:

Node.js
=======
This example shows **how to install biicode and code a node.js redis client**. You don't need to have installed redis, biicode will download for you.

Use the ``redis`` file of the ``noderedis`` block from ``mrnney`` user with the code line ``require("mranney/noderedis/redis")`` .

1. Installing biicode and node.js
---------------------------------

First of all, install biicode and node.js.

   - Download the biicode installer.

+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|Latest version 1.0                                                                                                                                                                                                                                                                                                           |
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+
|`MacOS <https://www.biicode.com/downloads>`_        |`Raspberry Pi <https://www.biicode.com/downloads>`_ |`Ubuntu 32 <https://www.biicode.com/downloads>`_    |`Ubuntu 64 <https://www.biicode.com/downloads>`_    |`Windows <https://www.biicode.com/downloads>`_      |`Devian Wheezy <https://www.biicode.com/downloads>`_|
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+


   - Download and install on your system the appropriate `version of Node.js <http://nodejs.org/download>`_ . 

2. Create your project
----------------------

To create a new project run``bii init`` with the project name as a parameter.

.. code-block:: bash

   ~$ bii init node_hello_project
   
This command will create the following layout:

.. code-block:: text

   |-- node_hello_project
   |    +-- bii
   |    +-- blocks
   |    +-- deps
   
Create a new block to place your code in it. Execute ``bii new anonymous/my_fist_block`` into the project folder to create a block.

.. code-block:: bash

   ~$ cd node_hello_project
   ~/node_hello_project$ bii new anonymous/my_first_block --hello=node

.. container:: infonote

    **why anonymous/my_first_block?**

    Because you distinguish a block by its owner's user-name and the block name. ``anonymous/my_first_block`` is what you write when you are not registered yet, but to publish your own blocks, you need to use your biicode user name.

    To change the user-name of a block, just edit the folders name: from anonymous to your user name.

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

    **What's the reason behind this layout?**

    With this layout, biicode analyzes your block's dependencies and downloads them into the deps folder. It is also used to configure and build your project.

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

And that's it. Your program is working!

.. container:: todo

    To learn more about node.js & biicode, check the :ref:`node.js section <nodejs-index>`.