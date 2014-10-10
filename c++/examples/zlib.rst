Zlib
=====

|zlib_homepage| is an efficient cross platform serialization library for C++, with support for Java and Go. It was created at Google specifically for game development and other performance-critical applications.

The main block is |bii_zlib|, which is generated from this |fork_zlib|.



Usage example of the zlib compression library
-----------------------------------------------

You can check all the zlib examples which are uploaded in biicode and execute any of them. Then, create a new project and open the |examples_zlib|.

.. code-block:: bash

   ~$ bii init zlib_sample
   ~$ cd zlib_sample
   ~/zlib_sample$ bii open examples/zlib
   ~/zlib_sample$ bii cpp:build

Now, you could run a general test to try some functionalities about zlib:

.. code-block:: bash

   	~/zlib_sample$ bin/examples_zlib_example
	zlib version 1.2.8 = 0x1280, compile flags = 0x55
	uncompress(): hello, hello!
	gzread(): hello, hello!
	gzgets() after gzseek:  hello!
	inflate(): hello, hello!
	large_inflate(): OK
	after inflateSync(): hello, hello!
	inflate with dictionary: hello, hello!


.. |zlib_homepage| raw:: html

   <a href="http://www.zlib.net/" target="_blank">Zlib</a>

.. |bii_zlib| raw:: html

   <a href="http://www.biicode.com/zlib/zlib" target="_blank">here</a>

.. |fork_zlib| raw:: html

   <a href="https://github.com/franramirez688/zlib" target="_blank">github repo</a>

.. |examples_zlib| raw:: html

   <a href="https://www.biicode.com/examples/examples/zlib/master" target="_blank">examples/zlib block</a>