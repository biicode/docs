.. _bii_work_command:

**bii work**: process changes
-----------------------------

This command process changes made in your code and configuration files to update the project with all the information.

Here is an example:

.. code-block:: bash

 $ bii work
 INFO: Processing changes...
 INFO: Downloading files from: google/gtest
 Work done!


**bii work** is an internal use command that is called when executing **bii build**, **bii configure**, **bii deps**...

It comes handy to use when :ref:`changing the version of blocks you depend on<cpp_dependencies>`.