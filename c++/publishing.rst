.. _cpp_publishing:

Publishing 
==========

:ref:`bii publish<bii_publish_command>` command, publishes your code to biicode. 

.. code-block:: bash

  $ bii publish


Tag's default value is ``DEV``, but  ``ALPHA``, ``BETA`` and ``STABLE`` are also available:

.. code-block:: bash

  $ bii publish  --tag STABLE

 
``ALPHA``, ``BETA`` and ``STABLE`` versions, are frozen after publication to achieve full reproducibility. ``DEV`` versions are overridden by a new version on any tag. Let's understand its behavior with an example:

* Publish a ``DEV`` version. That's number ``0``.
* Publish a ``DEV`` version. That's still number ``0``.
* Publish a ``BETA`` version. That's number ``1``.
* Publish a ``DEV`` version. That's number ``2``.
* Publish a ``ALPHA`` version. That's number ``2``.
* Publish a ``STABLE`` version. That's number ``3``.


Tag a version
--------------

Just execute:

.. code-block:: bash

  $ bii publish  --tag STABLE --versiontag=1.2rc3



.. container:: infonote

    ``DEV`` versions can not be tagged.


Add a descriptive message
-----------------------------------

Publish your blocks with a short message:

.. code-block:: bash

	$ bii publish --msg "A short block description"


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

