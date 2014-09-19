Log4z
=======

|log4z_homepage| is an open source C++ lightweight & cross platform log library.

It provides in a C++ application log and trace debug function for 7*24h service program.
**Support**: 64/32 bits of debian, redhat, centos, suse, windows.

The main block is |bii_log4z|, which is generated from this |fork_log4z|.



Fast stream log strings test
-------------------------------

Now, you can check all the log4z examples which are uploaded in biicode and execute any of them. Then, create a new project and open the |examples_log4z|.

.. code-block:: bash

	~$ bii init log4z_sample
	~$ cd log4z_sample
	~/log4z_sample$ bii open examples/log4z
	~/log4z_sample$ bii cpp:build

When all the examples are built, execute for fast stream log strings testing:

.. code-block:: bash

	~/log4z_sample$ bin/examples_log4z_fast_test
	2014-09-19 12:15:08.223 LOG_ALARM -----------------  log4z thread started!   ----------------------------
	2014-09-19 12:15:08.223 LOG_ALARM logger id=0 path=./log/ name=examples_log4z_fast_test level=1 display=1
	2014-09-19 12:15:08.223 LOG_INFO  begin test stream log utf-16 string input.... ( C:\Users\Francisco\Desktop\release_1_0\examples\blocks\examples\log4z\fast_test.cpp ) : 20
	...

 
.. |log4z_homepage| raw:: html

   <a href="https://github.com/zsummer/log4z" target="_blank">Log4z</a>

.. |bii_log4z| raw:: html

   <a href="http://www.biicode.com/fenix/log4z" target="_blank">here</a>

.. |fork_log4z| raw:: html

   <a href="https://github.com/franramirez688/log4z" target="_blank">github repo</a>

.. |examples_log4z| raw:: html

   <a href="https://www.biicode.com/examples/examples/log4z/master" target="_blank">examples/log4z block</a>