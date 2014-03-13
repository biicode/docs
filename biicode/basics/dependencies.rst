.. _dependencies:

Dependencies
============
In this section we´re going to explain as you can check and find your hive dependencies.


Checking your dependencies
--------------------------

There is one command that, when executed inside any hive in your workspace, is able to determine all dependencies affecting your source code for that particular hive. This is the ``bii deps`` command.

.. code-block:: bash

	$ bii deps

With this command you can **check your hive dependencies**, the versions of external blocks you are depending on (in your deps folder) and also the dependencies internal to your own hive. This is an important source of information, we are working on it to make it more navigable and informative.

.. _biifind:

Finding dependencies
--------------------

External dependencies of your hive are retrieved from biicode servers when found to your dep folders.
If you simply want to find missing dependencies, type:

.. code-block:: bash

	$ bii find

If you want to update already defined dependencies (as well as finding unresolved ones in the same step):

.. code-block:: bash

	$ bii find --update

Biicode uses user defined policies to resolve dependencies. The configuration file for configuring your policies for this is named "policies.bii" in your hive "bii" folder. Note that all find commands depend on the values configured in such file. You can for example try to update your dependencies, but if there are no compatible versions that match your policies, you will not get such updates. E.g. a new ALPHA version for one of your dependencies will not be updated if you do not change your policy.

If you want to find compatible downgrades:

.. code-block:: bash

	$ bii find --downgrade

These options can be combined:

.. code-block:: bash

	$ bii find --update --downgrade

If you want to find any possible matching compatible version (not just updates or downgrades from your current one), type:

.. code-block:: bash

	$ bii find --modify
