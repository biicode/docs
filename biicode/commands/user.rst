
.. _bii_user_command:

``bii user``: shows or change your current biicode user
---------------------------------------------------------

If you use it without parameter, it will show the current user, that can be None (anonymous).

.. code-block:: bash

	$ bii user
	INFO: Current user: None (anonymous)


If you pass a parameter, that will be the new biicode user. Such user should be already registered in `our website <https://www.biicode.com/>`_

.. code-block:: bash

	$ bii user phil
	INFO: Change user from None to phil

You could enter your account password to avoid entering into future occasions

.. code-block:: bash

	$ bii user phil -p myp@ssw0rd


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_