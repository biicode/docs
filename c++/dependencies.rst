.. _cpp_dependencies:

Dependencies 
=============

Learn how to get the dependencies your project needs and how to handle their versions via your ``[requirements]`` and ``[includes]`` sections of your *biicode.conf* file.

Dependencies
------------
The :ref:`getting started guide<cpp_getting_started>` explained basics on depending. To recall, these are the steps to depend on a library available in biicode, we're using **OpenSSL** in this guide:

* Write your source code as usual:

.. code-block:: cpp
    :emphasize-lines: 3

	#include <stdio.h>
	#include <string.h>
	#include "openssl/md5.h"
	 
	int main()
	{
	    unsigned char digest[MD5_DIGEST_LENGTH];
	    char string[] = "happy";
	    
	    MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest);    
	 
	    char mdString[33];
	 
	    for(int i = 0; i < 16; i++)
	         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	 
	    printf("md5 digest: %s\n", mdString);
	 
	    return 0;
	}

* Search the library you want in biicode, then specify which lib is the one you're using in your *biicode.conf* file.

Let's use first OpenSSL 1.0.1 available in *lasote/openssl* version 0:

.. image:: /_static/img/c++/dependencies/openssl_md5_simple.png

Write in your *biicode.conf*:

	.. code-block:: text

		[requirements]
		     lasote/openssl: 0

		[includes]
		    openssl/md5.h: lasote/openssl/include


* **bii build** and you're done. Make sure you've **bii init -L** your repo's folder first.

.. container:: infonote

	    Here's more on this :ref:`OpenSSL example project <openssl_examples>`.


Modifying the version you depend on
-----------------------------------

Manually edit your **biicode.conf** file to depend on any version you want. 

To depend on *lasote/openssl* version 2, write in your *biicode.conf*:

.. code-block:: text
    :emphasize-lines: 2

	[requirements]
	    lasote/openssl: 2

	[includes]
	    openssl/md5.h: lasote/openssl/include

.. _tag_dependencies:

Update your *biicode.conf* file to depend on *lasote/OpenSSL tagged version 1.0.1l*:

.. code-block:: text
    :emphasize-lines: 2

	[requirements]
	    lasote/openssl: @1.0.1l

	[includes]
	    openssl/md5.h: lasote/openssl/include

Run **bii build** and you'll see the new dependencies in your *bii/deps* folder.

For OpenSSL, there are two tracks available:
 
* ``OpenSSL 1.0.1`` is available at *lasote/openssl* versions 0,1,2 and 3.

* ``OpenSSL 1.0.2`` is available at *lasote/openssl(v1.0.2)* versions 0 and 1.

Update to release 1.0.2, just write it in your *biicode.conf*:

.. code-block:: text
    :emphasize-lines: 2

	[requirements]
	    lasote/openssl(v1.0.2): 0

	[includes]
	    openssl/md5.h: lasote/openssl/include

Execute **bii build** and you'll see the new dependencies in your *bii/deps* folder.

.. _dependencies_block_track:

Depending on a block track
^^^^^^^^^^^^^^^^^^^^^^^^^^

Currently, **libuv** keeps 4 mantained versions or **block tracks**:

		* |libuv_0_10| (Stable, used by Nodejs)

		* |libuv_0_11| (Non stable, but commonly used)

		* |libuv_1_0|

		* |libuv_1_x| (Latest)

Depend on one or another to fit your needs:

* Write this *#include line* in your source code:

	.. code-block:: cpp
	    :emphasize-lines: 1

	   	#include "uv.h"

* And depend on |libuv_0_11|, write in your *biicode.conf* file ``[requirements]`` :

	.. code-block:: text
	    :emphasize-lines: 2

		[requirements] 
			lasote/libuv(v0.11): 1

		[includes]
			uv.h : lasote/libuv/include

* Execute **bii build** and you're ready to go. 

Let's switch to |libuv_1_0|:

* Modify ``[requirements]`` section in your *biicode.conf* :

	.. code-block:: text
		:emphasize-lines: 2

		[requirements]
			lasote/libuv(v1.0): 0

		[includes]
			uv.h : lasote/libuv/include

* Execute **bii build** and it's switched.

And now, switch to |libuv_0_10|:

* Modify ``[requirements]`` section in your *biicode.conf* :

	.. code-block:: text
	    :emphasize-lines: 2

		[requirements] 
			lasote/libuv(v0.10): 1

		[includes]
			uv.h : lasote/libuv/include

* **bii build** and it's switched.

At last, switch to |libuv_1_x|:

* Modify ``[requirements]`` section in your *biicode.conf* :

	.. code-block:: text
	    :emphasize-lines: 2

		[requirements] 
			lasote/libuv(v1.x): 8

		[includes]
			uv.h : lasote/libuv/include

* **bii build** and it's switched.


**Got any doubts?** |biicode_forum_link| or |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">Ask in our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |libuv_0_11| raw:: html

   <a href="http://www.biicode.com/lasote/lasote/libuv/v0.11" target="_blank"><strong>Libuv library v0.11</strong></a>

.. |libuv_0_10| raw:: html

   <a href="http://www.biicode.com/lasote/lasote/libuv/v0.10" target="_blank"><strong>Libuv libary v0.10</strong></a>

.. |libuv_1_0| raw:: html

   <a href="http://www.biicode.com/lasote/lasote/libuv/v1.0" target="_blank"><strong>Libuv library v1.0</strong></a>


.. |libuv_1_x| raw:: html

   <a href="http://www.biicode.com/lasote/lasote/libuv/v1.x" target="_blank"><strong>Libuv library v1.x</strong></a>


.. |Oscpack_biicode| raw:: html

   <a href="http://www.biicode.com/Maria/oscpack" target="_blank"><strong>Oscpack library</strong></a>