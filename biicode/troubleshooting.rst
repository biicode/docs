.. _troubleshooting:

Troubleshooting
===============

In this section you will find information and helpful resources, in case you encounter any problem while using our service. Don't panic, and try to find a solution for your problem bellow. If you can't find a solution, please `contact us at our forum <http://forum.biicode.com/category/client>`__ and describe your problem.

The biicode client stopped working
----------------------------------

As biicode is a rapidly evolving technology —right now we are releasing new versions of the product at least weekly—, you may find that suddenly some features have stopped working as expected. 

C/C++ hives in Windows
^^^^^^^^^^^^^^^^^^^^^^

This problem affects to **Windows user that compile their C or C++ hives with MinGW** compilation tools. In this case, there is an issue if you have installed the Windows Shell Command Tool, ``sh.exe`` on your system. In this case, check if your ``PATH`` environment variable containes the ``sh.exe`` program, and if it does, remove it. To do so:

#. Right-click on *My Computer* icon, choose properties from the context menu. (Alternatively, you can double-click on the *System* icon in the *Control Panel*)

#. Now go to *Advaced System Settings* tab, click the *Enviroment Variables...* button and modify your ``PATH`` variable, removing the ``sh.exe`` route. 

If the problem persists, check other solutions proposed in this section, or `contact us at our forum <http://forum.biicode.com/category/client/windows>`__, and we'll try to solve your problem as soon as possible.

General solution
^^^^^^^^^^^^^^^^

If biicode client isn't working, this can be due to some update in the logic of our servers or in the client program we provide. If you are experiencing any difficulties with your local installation of biicode, try to **follow theses steps in order**:

#. First, try updating your biicode client `downloading the latest available release <https://www.biicode.com/downloads>`__.
#. Didn't that fix your problem? Then, from your **workspace folder**, execute the command ``bii clean``. That should remove all local information and force the client to update the local database.
#. If the two previous steps didn't solve the issue, try executing the command ``bii clean --ws-cache``.

After these simple actions, everything should get back to normal. However, if your problem isn't solved yet, please `contact us at our forum <http://forum.biicode.com/category/client/>`__, and we'll try to provide a solution as soon as possible.


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
 