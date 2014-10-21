.. _bii_open_command:

``bii open``: edit published blocks
=========================================

This command allows you to edit a published block.
You can use this command to edit one of your dependency blocks or **any block** you've seen on the web and you want to edit.
When you invoke this command the block is placed into the ``blocks`` folder within your project, and the source files that can be modified by you and eventually published in a new version of the same block or into a new block. If you are updating or creating a code block from another service, check the :ref:`integration guide<integration>` to know how to proceed.

.. code-block:: bash

	$ bii open USER_NAME/BLOCK_NAME


.. _edit_dependecies:


Edit any published block
---------------------------

To **edit a published block** you are interested in or you depend on, follow the steps below:

1. Open a block
^^^^^^^^^^^^^^^^^^^

Create a new biicode project and get into it:

.. code-block:: bash

	~$ bii init myproject
	~$ cd myproject

Use ``bii open`` command and move any published block to your project:

.. code-block:: bash

	~$ bii open user_name/block_name:VERSION

**Example**

Let's open the |diego_ardunet_block| (version=lastest by default) to edit it:

.. |diego_ardunet_block| raw:: html

   <a href="http://www.biicode.com/diego/diego/ardunet/master" target="_blank">diego/ardunet block</a>

.. code-block:: bash

	$ bii open diego/ardunet

Then you can code on it as if it was yours and changes will be reflected in your code, at build time.

Suppose that you want to open version ``2`` instead of the latest ``diego/ardunet`` version, you should execute: 

.. code-block:: bash

	$ bii open diego/ardunet:2



2. Publish the changes
^^^^^^^^^^^^^^^^^^^^^^^^

Once you are happy with the changes, publish your own version of the block. 

If (as in the Example) **the block in edition isn't yours**:

	* Rename **diego** folder with your **username**. 
	* Delete the ``parents.bii`` file.

And publish :

.. code-block:: bash

	$ bii publish  

Check the :ref:`publish command<bii_publish_command>` to know more.


3. Close the block
^^^^^^^^^^^^^^^^^^^^^^

Then you can close the block to remove it from your blocks folder:

.. code-block:: bash

	$ bii close user_name/block_name

If you're following the **Example**, execute:

.. code-block:: bash

	$ bii close user_name/ardunet


4. Depend on the block you've just published
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Now, if you want to depend on the block you've just published:

	* Update your #include (s) to the ones referring to your new published version
	* If you didn't publish it as STABLE, do it or update your :ref:`policies.bii <policies>` file to accept DEV versions.
	* Execute ``bii find`` and you're ready to build as usual. Here's :ref:`bii find command documentation<bii_find_command>` in case it's useful. 


.. container:: infonote

	If you need more information about publish or close command:

	*	:ref:`Publish command <bii_publish_command>`
	*	:ref:`Close command <bii_close_command>`


**Got any doubts?** Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.