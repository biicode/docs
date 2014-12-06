

.. _bii_find_command:

``bii find``: find your external dependencies
=============================================

This commands allows you to retrieve any code dependencies from the biicode servers. The client analyzes your code, and find missing dependencies that cannot be resolved searching in your project contents. The client then communicates with the biicode server and tries to find code that is missing in your project, and retrieves the best matching version according with your :ref:`policies<policies>`.

.. code-block:: bash

	$ bii find


.. _update_dependencies:

Update your dependencies
---------------------------

If you want to update already defined dependencies (as well as finding unresolved ones in the same step):

.. code-block:: bash

	$ bii find --update

Biicode uses user defined policies to resolve dependencies. The configuration file for configuring your policies for this is named "policies.bii" in your project "bii" folder. Note that all find commands depend on the values configured in such file. You can for example try to update your dependencies, but if there are no compatible versions that match your policies, you will not get such updates. E.g. a new ALPHA version for one of your dependencies will not be updated if you do not change your policy.

If you want to find compatible downgrades:

.. code-block:: bash

	$ bii find --downgrade

These options can be combined:

.. code-block:: bash

	$ bii find --update --downgrade

If you want to find any possible matching compatible version (not just updates or downgrades from your current one), type:

.. code-block:: bash

	$ bii find --modify
	

**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_

.. container:: todo

	* Visit the section: :ref:`requirements.bii <requirements_bii>`
	* Visit the section: :ref:`your project layout<project_layout>`

