OpenSSL
=======

`OpenSSL <https://www.openssl.org/>`_ is a robust, commercial-grade, full-featured, and Open Source toolkit implementing the Secure Sockets Layer (SSL v2/v3) and Transport Layer Security (TLS) protocols as well as a full-strength general purpose cryptography library.

The versions of OpenSSL library at biicode are:
	
	* `OpenSSL 1.0.1 <http://www.biicode.com/lasote/openssl>`_

	* `OpenSSL 1.0.2 <http://www.biicode.com/lasote/lasote/openssl/v1.0.2>`_

Both versions are generated from this `github repo <https://github.com/lasote/openssl>`_. 

This example shows how to use the **cryptography feature** of OpenSSL using a MD5 and SHA1 algorithm to encrypt a string.

MD5 and SHA1 examples
---------------------

This example is already in biicode, `check it out <http://www.biicode.com/examples/openssl>`_!

.. code-block:: bash

 $ bii init mysslproject
 $ cd mysslproject
 $ bii open examples/openssl

Check the code
--------------

The MD5 example encrypts a string "happy":

**md5.cpp**

.. literalinclude:: /_static/code/cpp/examples/openssl/md5.cpp
   :language: cpp
   :linenos:

Next, we'll use a similar code to encrypt a "hello world!" string with SHA1:

**sha1.cpp**

.. literalinclude:: /_static/code/cpp/examples/openssl/sha1.cpp
   :language: cpp
   :linenos:


Encrypt strings
---------------

Now execute ``bii cpp:build`` to build the project.

.. code-block:: bash
 
 $ bii cpp:build

Go to bin directory and execute the binaries:

.. code-block:: bash
 
 $ cd bin
 $./examples_openssl_md5
 md5 digest: 56ab24c15b72a457069c5ea42fcfc640

That output is the MD5 hash value of your encrypted string.

.. code-block:: bash
 
 $./examples_openssl_sha1
 sha1 digest: 2d5ec68b0d061c75db

And that is the SHA1 hash value for the "hello world!" string.

Got any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.