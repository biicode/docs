Frequently Asked Questions
==========================

How do I configure my settings to build executables with Visual Studio Compiler?
--------------------------------------------------------------------------------

External dependencies to your hive are retrieved from biicode servers when found to your dep folders. The configuration file for configuring your policies for this is named "policies.bii" in your hive "bii" folder. 

If you simply want to find missing dependencies, type:

.. code-block:: bash

	$ bii find

If you want to update already defined dependencies (as well as finding unresolved ones in the same step): 

.. code-block:: bash

	$ bii find --update

Note that all find commands depend on the values configured in such file. You can for example try to update your dependencies, but if there are no compatible versions that match your policies, you will not get such updates. E.g. a new ALPHA version for one of your dependencies will not be updated if you do not change your policy.

If you want to find compatible downgrades:

.. code-block:: bash

	$ bii find --downgrade
