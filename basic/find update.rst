Update your hellopretty block with the new version of hello
--------------------------------------------------------------

To update your **hellopretty** block you only need to search the server for any published new versions of your dependencies using the ``bii find`` command with the ``--update`` modifier. If the server finds new published versions for any of your dependencies, you'll see an indicative message on your screen:

.. code-block:: bash

	$ bii find --update


Finally, you can input the ``bii cpp:run`` command to see how your block has been updated, showing on screen the new message.

.. raw:: html

	<script type="text/javascript" src="https://asciinema.org/a/7619.js" id="asciicast-7619" async data-speed="2"></script>


Publish a new version of your hello block
-------------------------------------------

Modifying your code and publishing the results is easy with biicode. Now we´ll change the message displayed by the ``hello()`` function in the **hello** block. Update the ``hello.cpp`` as following:

**hello.cpp**

.. literalinclude:: ../_static/code/cpp/hello-world/hello(modified).cpp
   :language: cpp


Execute your block, to make sure everything works as expected:

.. code-block:: bash

   $ cd cpp_hello_hive
   $ bii cpp:run
   ...
   Hello biicode!

Now, post your block to the biicode server just like you did before:

.. code-block:: bash

   $ bii publish                                                            

   block:   your_user_name/cpp_hello
   Introduce tag: STABLE                                                           
   Introduce msg: Updating my hello world project with biicode                            
   
   INFO: Successfully published your_user_name/cpp_hello(your_user_name/master): 1

As you can see, the version of your block changed from 0 to 1. Your can see both versions published online visiting your biicode user main page, as before.


