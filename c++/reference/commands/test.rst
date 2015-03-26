.. _bii_test_command:

**bii test**: test your code
--------------------------------

**bii test** uses the patterns defined in the ``[tests]`` section of the *biicode.conf* to execute tests your block's tests.

.. code-block:: bash

   $ bii test

**bii test** command wraps **bii build** and **ctest**. Now your tests are fully configurable with CTest CMake options.

.. code-block:: bash

	$ bii test -E _main -R test_

Check |ctest_options| to know more. 

**bii test** command truly runs:

.. code-block:: bash

   $ bii test -VV   (ctest extra verbose option)

But when using Visual Studio, **bii test** is truly executing:

.. code-block:: bash

   $ bii test -VV -C Debug

Note that **bii test** command supports CMake and CTest options, like:

.. code-block:: bash

   $ bii test -C Release


Also enables **-jx** option to launch build and/or tests with this flag (they've got different effects):

.. code-block:: bash

    $ bii test -j2 == $ bii build -j2 + $ bii test -j2

   
If you got any questions left, you can ask them at our `forum <http://forum.biicode.com/>`_.


.. |ctest_options| raw:: html

   <a href="http://www.cmake.org/cmake/help/v2.8.8/ctest.html" target="_blank">CTest docs</a>