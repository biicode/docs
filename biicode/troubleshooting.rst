.. _troubleshooting:

Troubleshooting
===============

In this section you will find information and helpful resources, in case you encounter any problem while using our service.

The biicode client stopped working
----------------------------------

As biicode is a rapidly evolving technology —right now we are releasing new versions of the product at least weekly—, you may find that suddenly some features have stopped working as expected. This can be due to some update in the logic of our servers or in the client program we provide. **If you are experiencing any difficulties with your local installation of biicode**, try to follow theses steps in order:

#. First, try updating your biicode client :ref:`downloading the latest available release <download_client_binaries>`.
#. Didn't that fix your problem? Then, from your workspace folder, execute the command ``bii clean``.
#. If the two previous steps didn't solve the issue, try executing the command ``bii clean --ws-cache``.

After these simple actions, everything should be back to normal.

Old hives don't work properly with Biicode 0.11.1
-------------------------------------------------

When we improved user experience in version 0.11.1, we realized that there was a worthy inconvenience: your local hives may need some editing.

So if you get this error:

.. code-block:: bash

   ERROR: Error parsing settings.bii
   MINGW is not a valid BuilderFamily. Possible values are set (['ant','maven','make','msbuild','nmake'])
   
To fix it, you have to update the file settings.bii, for C/C++ you have to do it manually:
Either by creating a new hive and copying it's settings.bii file or changing yours so it has this information:

.. code-block:: text

    cpp: {builder: {family: make, subfamily: mingw}}


If it's an Arduino hive just type this in your console:

.. code-block:: bash

    bii arduino:settings
    
and for Raspberry Pi hives:
    
.. code-block:: bash

    bii rpi:settings   
 

