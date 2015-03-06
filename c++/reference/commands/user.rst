.. _bii_user_command:

**bii user**: specify your username
------------------------------------

Show or change your current biicode user.

**A quick tip:** Run ``bii user your_username`` before getting started, this way biicode knows you’re the one winning a badge.

.. container:: todo

    **You're now ready to** :ref:`get started.<cpp_getting_started>`.


Execute ``bii user`` to show the current user. **Note**: It can be None (anonymous).

.. code-block:: bash

	$ bii user
	INFO: Current user: None (anonymous)


Make sure you've got an `user name <https://www.biicode.com/>` and use it:

.. code-block:: bash

	$ bii user phil
	INFO: Change user from None to phil

You can enter it together with your password:

.. code-block:: bash

	$ bii user phil -p myp@ssw0rd


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_