Crypto++
========

Crypto++ is a C++ class library of cryptographic algorithms and schemes written by Wei Dai. For more information about this library, visit their `official website <http://www.cryptopp.com/>`_ or wiki.

The following example shows how to encrypt a message with SHA1 code. You can find this example in `the biicode crypto samples block <http://www.biicode.com/examples/cryptopp>`_ .

**main_crypto**

.. literalinclude:: /_static/code/cpp/examples/crypto/main_crypto.cpp
   :language: cpp
   :linenos:

**Download the file:** :download:`main_crypto.cpp </_static/code/cpp/examples/crypto/main_crypto.cpp>` 

Create a block:

.. code-block:: bash

	$ bii init my_project
	$ cd my_project
	$ bii new examples/cryptopp

Copy the main_cryptyo file in your block, then you need to resolve all the dependencies of this ``main_crypto.cpp``. Then you can compile it

.. code-block:: bash

	$ bii find
	$ bii cpp:build

You will see next console output after executing the command:

.. code-block:: bash

	$ ./bin/examples_cryptopp_main_crypto
	F7FF9E8B7BB2E09B70935A5D785E0CC5D9D0ABF0

