Name of the library
===================

Short description. For more information, `visit the library official website <http://www.link.com>`_

This is the biicode library site and this is the biicode library examples.

Usage example (difficulty: low/medium/high)
-------------------------------------------

Description of the example.

**example_file.h**

.. code-block:: cpp
	:linenos:

	#pragma once

	#include <stdio.h>
	#include <assert.h>
	#include "zlib/zlib/zlib.h"

	/*********** Methods declarations *************/

	/* Compress from file source to file dest until EOF on source.
	def() returns Z_OK on success, Z_MEM_ERROR if memory could not be
	allocated for processing, Z_STREAM_ERROR if an invalid compression
	level is supplied, Z_VERSION_ERROR if the version of zlib.h and the
	version of the library linked do not match, or Z_ERRNO if there is
	an error reading or writing the files. */

	int def(FILE *source, FILE *dest, int level);

	/* Decompress from file source to file dest until stream ends or EOF.
	inf() returns Z_OK on success, Z_MEM_ERROR if memory could not be
	allocated for processing, Z_DATA_ERROR if the deflate data is
	invalid or incomplete, Z_VERSION_ERROR if the version of zlib.h and
	the version of the library linked do not match, or Z_ERRNO if there
	is an error reading or writing the files. */

	int inf(FILE *source, FILE* dest);


	/* report a zlib or i/o error */

	void zerr(int ret);

**example commands**

.. code-block:: bash

	$ bii find

