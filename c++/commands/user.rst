
.. _bii_user_command:

``bii user``: shows or changes your current biicode user
---------------------------------------------------------

Execute ```bii user``` to show the current user. **Note**: It can be None (anonymous).

.. code-block:: bash

	$ bii user
	INFO: Current user: None (anonymous)


Once registered on `our website <https://www.biicode.com/>` you can use your user name:

.. code-block:: bash

	$ bii user phil
	INFO: Change user from None to phil

To enter it together with your password:

.. code-block:: bash

	$ bii user phil -p myp@ssw0rd


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_