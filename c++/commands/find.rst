

.. _bii_find_command:

**bii find**: find your external dependencies
=============================================

Retrieve any code dependencies from biicode's servers. 

Biicode analyzes your code, and finds missing dependencies that cannot be resolved searching in your project contents. After that, biicode tries to find the code you need in our serves, and retrieves the best matching version according with your :ref:`policies.bii<policies>`.

.. code-block:: bash

	$ bii find


.. _update_dependencies:

Update your dependencies
---------------------------

Update your dependencies and find new unresolved ones in one step:

.. code-block:: bash

	$ bii find --update

Biicode uses :ref:`policies.bii<policies>` to resolve your dependencies. You can find ``policies.bii`` in your project's ``bii`` folder. 

**Note:** ``policies.bii`` defines the way ``bii find`` command retrieves dependencies. For example, if you only want STABLE versions and there's a newer DEV version, this version will only retrieved if you say so in your ``policies.bii``.


Find compatible downgrades:

.. code-block:: bash

	$ bii find --downgrade


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_

.. container:: todo

	* Visit :ref:`[requirements] <requirements_conf>` section.

