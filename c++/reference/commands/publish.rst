.. _bii_publish_command:

**bii publish**: publish your blocks
=========================================

**bii publish** publishes your code to biicode. 

.. code-block:: bash

	$ bii publish


Once you've succesfully published your code to our servers, command line prompt will show a info message about your block name ``user_name/block_name`` and the version ID number:

.. code-block:: bash

	INFO: Publishing block: myuser/myblock
	INFO: *****************************
	INFO: ***** Publishing public ****
	INFO: *****************************
	INFO: Successfully published myuser/myblock: 1


Available publishing options:
-----------------------------

Tag's default value is ``DEV``, but all **release life-cycle tags** are available:

	* ``DEV``: Code is under development.
	
	|
	
	* ``ALPHA``: It's usually code ready to shared with close friends or colleagues.
	
	|

	* ``BETA``: Code ready for BETA testers!
	
	|

	* ``STABLE``: Tested and ready to reuse.


These tags define the development state of your code.


:ref:`policies.bii<policies>` file holds your policies about what kind of code tags you allow for each the blocks you use.

Publish your blocks with different tags:

.. code-block:: bash

	$ bii publish --tag STABLE


.. container:: infonote

        Here's a full guide about :ref:`publishing<cpp_publishing>` to biicode.


Publish from a git commit
-------------------------

When working with a block cloned from a git repository, use **bii publish -r** or **bii publish --remote** to publish git info along with your block:

.. code-block:: bash
 
 $ bii publish -r

This way your reference to the repo and commit will be saved and showed in your block header.

You can also use tags:

.. code-block:: bash
 
 $ bii publish -r --tag SATBLE

.. container:: infonote

        Check :ref:`Git integration <git_integration>` to know more about working with git repositories.


Publish one of your project's blocks
------------------------------------

If there's more than one block within your project, specify which one you want to publish:

.. code-block:: bash

	$ bii publish USER_NAME/BLOCK_NAME


An Example
^^^^^^^^^^

``fenix`` user is editing two blocks, ``fenix/vector`` and ``fenix/matrix``. He wants to publish **just fenix/vector** using DEV tag:

.. code-block:: bash

	$ bii publish fenix/vector

After a while, he's sure about publishing ``fenix/vector`` as STABLE version:

.. code-block:: bash

	$ bii publish fenix/vector --tag STABLE 


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_.

.. container:: infonote

	Visit the section: :ref:`bii update command <bii_update_command>`


