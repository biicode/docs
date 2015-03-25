Crypto++
========

Crypto++ is a C++ class library of cryptographic algorithms and schemes written by Wei Dai. For more information about this library, visit their `official website <http://www.cryptopp.com/>`_ or `wiki <http://en.wikipedia.org/wiki/Crypto%2B%2B>`_.

Crypto++ library is allocated and ready to use at `cryptopp/cryptopp <https://www.biicode.com/cryptopp/cryptopp>`_.

Encrypt a message
-----------------

The following example shows how to encrypt a message with SHA1 code.

Create a new project
^^^^^^^^^^^^^^^^^^^^

Start a new project and copy the code below:

.. code-block:: bash

 $ bii init cryptopp_example -L 
 $ cd cryptopp_example
 $ # Create main_cryptopp.cpp
 $ # Copy the code

**main_crypto.cpp**

.. literalinclude:: /_static/code/cpp/examples/crypto/main_crypto.cpp
   :language: cpp
   :linenos:


Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 INFO: Processing changes...
 examples/cryptopp depends on:
       system:
          iostream
          string
       unresolved:
          filters.h
          hex.h
          sha.h

Edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

.. code-block:: text

 [requirements]
     cryptopp/cryptopp: 8
 
 [includes]
     *.h: cryptopp/cryptopp

Check again with **bii deps** to show all dependencies are now resolved.

Build the project
^^^^^^^^^^^^^^^^^

Now, build and run the encryption code.

.. code-block:: bash
 
 $ bii build
 $ cd bin
 $ # run executable
 F7FF9E8B7BB2E09B70935A5D785E0CC5D9D0ABF0

Open and build
--------------

You can find this example in `the biicode crypto samples block <http://www.biicode.com/examples/cryptopp>`_. See how it works in a few steps here.

Create a project:

.. code-block:: bash

	$ bii init cryptopp_example
	$ cd cryptopp_example
	$ bii open examples/cryptopp

You will see next console output after executing the command:

.. code-block:: bash

	$ ./bin/examples_cryptopp_main_crypto
	F7FF9E8B7BB2E09B70935A5D785E0CC5D9D0ABF0

