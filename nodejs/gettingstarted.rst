.. _node_getting_started:

Getting started
===============

This example shows how to install biicode and code a node.js redis client. You don't need to have installed redis, biicode will download for you, |redis_biicode_link|

.. |redis_biicode_link| raw:: html

   <a href="https://www.biicode.com/mranney/mranney/node_redis/master" target="_blank">it is already in biicode!</a>

1. Installing biicode and node.js
---------------------------------

First |downloads_link| and install biicode

.. |downloads_link| raw:: html

   <a href="https://www.biicode.com/downloads" target="_blank">download</a>

Then, download and install on your system the appropriate `version of Node.js <http://nodejs.org/download>`_ .

2. Create your project
----------------------

First, create a project:

.. code-block:: bash

  ~$ bii init myproject

Then we can use the convenience ``new`` command to create some folders and a "Hello World" Node.js main file. Of course, you can do it manually too.

.. code-block:: bash

  ~$ cd myproject
  ~/myproject$ bii new username/myblock --hello=node

.. container:: infonote

    You can directly type ``username``, there's no need to have your own user to reuse.

This should be the resulting layout:

.. code-block:: text

  +-- myproject
  |    +-- bii
  |    +-- blocks
  |    |    +-- username
  |    |    |    +-- myblock
  |    |    |    |    +-- main.js
  |    +-- deps

3. Run your program
-------------------
Lets check that everything is fine by running the hello world aplication.

.. code-block:: bash

  ~/myproject/$ cd blocks
  ~/myproject/blocks$ noderunner 
  username/myblock/main.js

4. Depending on redis
---------------------

Copy the following code containing a simple redis client into the **main.js** file:

**main.js**

.. code-block:: js
  :emphasize-lines: 1

  var redis = require("mranney/node_redis");
  client = redis.createClient();
  client.set("str key","str val", redis.print);
  client.quit(function (err, res) {
    console.log("Exiting from quit command.");
  });

.. code-block:: bash

   ~/myproject$ bii find

Run a redis server. If you need to install redis, |redis_link|

.. |redis_link| raw:: html

   <a href="http://redis.io/download" target="_blank">you can download it from redis.io.</a>

.. code-block:: bash

   ~/myproject$ redis server

Now, execute your script main.js.

.. code-block:: bash

  ~/myproject/$ cd blocks
  ~/myproject/blocks$ noderunner username/myblock/main.js

  Reply: OK
  Exiting from quit command.

That's it, if you see that output redis was downloaded and configured in your project!
You can check the ``deps`` folder, the redis code is there.

Didn't work? No problem, read or contact us in |biicode_forum_link|

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>



Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">Write us!</a>