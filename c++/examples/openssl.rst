.. _openssl_examples:

OpenSSL
=======

`OpenSSL <https://www.openssl.org/>`_ is a robust, commercial-grade, full-featured, and Open Source toolkit implementing the Secure Sockets Layer (SSL v2/v3) and Transport Layer Security (TLS) protocols as well as a full-strength general purpose cryptography library.

The versions of OpenSSL library at biicode are:
	
	* OpenSSL 1.0.1 at `lasote/openssl <http://www.biicode.com/lasote/openssl>`_.

	* OpenSSL 1.0.2 at `lasote/openssl (v1.0.2) <http://www.biicode.com/lasote/lasote/openssl/v1.0.2>`_.

Both versions are generated from this `github repo <https://github.com/lasote/openssl>`_. 


Encrypting with MD5 and SHA1
----------------------------

This example shows how to use the **cryptography feature** of OpenSSL using a MD5 and SHA1 algorithm to encrypt a string.

Creating a new project
^^^^^^^^^^^^^^^^^^^^^^

Create a new simple layout project with the name of your block and copy the code below:

.. code-block:: bash

 $ bii init mysslproject -L
 $ cd mysslproject
 $ # Copy both files inside

The MD5 example encrypts a string "happy":

**md5.cpp**

.. literalinclude:: /_static/code/cpp/examples/openssl/md5.cpp
   :language: cpp
   :emphasize-lines: 1

Next, we'll use a similar code to encrypt a "hello world!" string with SHA1:

**sha1.cpp**

.. literalinclude:: /_static/code/cpp/examples/openssl/sha1.cpp
   :language: cpp
   :emphasize-lines: 1

Manage your dependencies 
^^^^^^^^^^^^^^^^^^^^^^^^

Take a look at the ``#include`` pointing to OpenSSL. Type **bii deps** to see unresolved dependencies:

..  code-block:: bash
 
 $ bii deps
 INFO: Processing changes...
 your_user/mysslproject depends on:
       system:
          stdio.h
          string.h
       unresolved:
          openssl/md5.h
          openssl/sha.h

Let's edit now the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

.. code-block:: text

 [requirements]
     lasote/openssl: 3
 
 [includes]
     openssl/*.h: lasote/openssl/include

Retrieve your unresolved dependencies:

..  code-block:: bash
 
 $ bii find
 INFO: Processing changes...
 INFO: Downloading files from: lasote/openssl
 INFO: Downloading files from: biicode/cmake
 INFO: Saving files from: lasote/openssl
 ...

Build the project
^^^^^^^^^^^^^^^^^

Now execute **bii build**.

.. code-block:: bash
 
 $ bii build

Go to */bin* directory and execute the binaries:

.. code-block:: bash
 
 $ cd bin
 $./examples_openssl_md5
 md5 digest: 56ab24c15b72a457069c5ea42fcfc640

That output is the MD5 hash value of your encrypted string.

.. code-block:: bash
 
 $./examples_openssl_sha1
 sha1 digest: 2d5ec68b0d061c75db

And that is the SHA1 hash value for the "hello world!" string.

Develop your project
--------------------

You can develop your own project with OpenSSL. Choose your version or switch between them using the :ref:`block track feature<dependencies_block_track>`.

Just modify the ``[requirements]`` section in the *biicode.conf* file of your block's folder:

* To depend on **OpenSSL 1.0.1**:

    .. code-block:: text

     [requirements]
     		 lasote/openssl: 2

* To depend on **OpenSSL 1.0.2**:

    .. code-block:: text
   
      [requirements]
     		 lasote/openssl(v1.0.2): 1

Open and build
--------------

This example is already in biicode: `examples/openssl <http://www.biicode.com/examples/openssl>`_.

Just open and build it to give it a quick try.

Create a new project and open the block:

.. code-block:: bash

 $ bii init mysslproject
 $ cd mysslproject
 $ bii open examples/openssl


Now build and run the examples:

.. code-block:: bash
 
 $ cd bin
 $./examples_openssl_md5
 md5 digest: 56ab24c15b72a457069c5ea42fcfc640

 $./examples_openssl_sha1
 sha1 digest: 2d5ec68b0d061c75db


Got any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_, visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.