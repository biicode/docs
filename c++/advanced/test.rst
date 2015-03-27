Tests
-----

Sometimes your library includes some tests to check your its functionality. Your *biicode.conf* ``[tests]`` section is here to cover these tests.

Just write the test files specifically or the path to the folder that contains them like this:

.. code-block:: text

  [tests]

    projects/SelfTest/*
    tests/unit_test.cpp

This way, these files are not compiled executing **bii build** command.

Run **bii test** and you're ready to go. Check :ref:`bii test options here<bii_test_command>`.

.. container:: infonote

    You can specify in your ``[mains]`` section that which tests aren't mains. 
    :ref:`Here's more on [mains]<mains_conf>` and :ref:`[tests] <test_conf>` sections.