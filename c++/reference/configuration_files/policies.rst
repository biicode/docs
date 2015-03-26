.. _policies:

**policies.bii**: defining the policies for the code you want to reuse
======================================================================

Policies are **rules bii find applies** when finding or updating external dependencies. Configure them in *your_project/bii/policies.bii*

*policies.bii* default value accepts all your *DEV* versions and other user's *STABLE* versions. It has this format as self-documented:::

	# This file configures your finds of dependencies.
	#
	# It is an ordered list of rules, which will be evaluated in order, of the form:
	#     block_pattern: TAG
	#
	# For each possible block that could resolve your dependencies,
	# only versions with tag >= TAG will be accepted

	your_username/* : DEV
	* : STABLE

**Notes**:

* *block_pattern* fits the *owner/block_name* pattern. 

* TAG can be **STABLE**, **BETA**, **DEV** or **ALPHA**.
	
Changing your policies
----------------------

Accept all your *DEV* versions as well as all *DEV* versions from *owner1* and *owner2* write:

.. code-block:: text

	# policies.bii file

		your_username/* : DEV
		owner1/* : DEV
		owner2/* : DEV
		* : STABLE

Unleash the tester in you, accept all latest *DEV* versions:

.. code-block:: text

	# policies.bii file

		* : DEV

Don't forget to update your dependencies according to your new *policies.bii*:

.. code-block:: bash

	$ bii find --update


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_