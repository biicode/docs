Zlib
====

Zlib is a software library written in C language used for data compression. For more information about this library, visit its official website or Documentation.

This is the biicode library site and this is the biicode library examples.

Usage example (difficulty: medium)
---------------------------------

To check this library, we're making an example to compress and decompress a single file. Then you could create a \*.h and a \*.cpp file named infdef (inflate and deflate) and a zpipe.cpp which would be, for example, in ~/hive_directory/src/user_name/hive_name/.

The following code would be in each one.

infdef.h
^^^^^^^^

.. code-block:: cpp
	:linenos:
	:emphasize-lines: 3,4,5,16

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

infdef.cpp
^^^^^^^^^^

.. code-block:: cpp

	#include "infdef.h"
	 
	#define CHUNK 20000
	 
	int def(FILE *source, FILE *dest, int level)
	{
	   int ret, flush;
	   unsigned have;
	   z_stream strm;
	   unsigned char in[CHUNK];
	   unsigned char out[CHUNK];
	 
	  /* allocate deflate state */
	   strm.zalloc = Z_NULL;
	   strm.zfree = Z_NULL;
	   strm.opaque = Z_NULL;
	   ret = deflateInit(&strm, level);
	   if (ret != Z_OK)
	     return ret;
	 
	  /* compress until end of file */
	   do {
	     strm.avail_in = fread(in, 1, CHUNK, source);
	     if (ferror(source)) {
	       (void)deflateEnd(&strm);
	       return Z_ERRNO;
	     }
	     flush = feof(source) ? Z_FINISH : Z_NO_FLUSH;
	     strm.next_in = in;
	 
	   /* run deflate() on input until output buffer not full, finish
	     compression if all of source has been read in */
	     do {
	       strm.avail_out = CHUNK;
	       strm.next_out = out;
	       ret = deflate(&strm, flush); /* no bad return value */
	       assert(ret != Z_STREAM_ERROR); /* state not clobbered */
	       have = CHUNK - strm.avail_out;
	 
	       if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
	         (void)deflateEnd(&strm);
	         return Z_ERRNO;
	        }
	      } while (strm.avail_out == 0);
	      assert(strm.avail_in == 0); /* all input will be used */
	 
	   /* done when last data in file processed */
	    } while (flush != Z_FINISH);
	    assert(ret == Z_STREAM_END); /* stream will be complete */
	 
	  /* clean up and return */
	   (void)deflateEnd(&strm);
	   return Z_OK;
	}
	 
	int inf(FILE *source, FILE* dest)
	{
	   int ret;
	   unsigned have;
	   z_stream strm;
	   unsigned char in[CHUNK];
	   unsigned char out[CHUNK];
	 
	  /* allocate inflate state */
	   strm.zalloc = Z_NULL;
	   strm.zfree = Z_NULL;
	   strm.opaque = Z_NULL;
	   strm.avail_in = 0;
	   strm.next_in = Z_NULL;
	   ret = inflateInit(&strm);
	   if (ret != Z_OK)
	     return ret;
	 
	  /* decompress until deflate stream ends or end of file */
	   do {
	     strm.avail_in = fread(in, 1, CHUNK, source);
	     if (ferror(source)) {
	       (void)inflateEnd(&strm);
	       return Z_ERRNO;
	     }
	     if (strm.avail_in == 0)
	       break;
	     strm.next_in = in;
	 
	    /* run inflate() on input until output buffer not full */
	     do {
	       strm.avail_out = CHUNK;
	       strm.next_out = out;
	       ret = inflate(&strm, Z_NO_FLUSH);
	       assert(ret != Z_STREAM_ERROR); /* state not clobbered */
	       switch (ret) {
	         case Z_NEED_DICT:
	         ret = Z_DATA_ERROR; /* and fall through */
	         case Z_DATA_ERROR:
	         case Z_MEM_ERROR:
	        (void)inflateEnd(&strm);
	         return ret;
	       }
	       have = CHUNK - strm.avail_out;
	       if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
	         (void)inflateEnd(&strm);
	         return Z_ERRNO;
	       }
	      } while (strm.avail_out == 0);
	 
	     /* done when inflate() says it's done */
	     } while (ret != Z_STREAM_END);
	 
	  /* clean up and return */
	   (void)inflateEnd(&strm);
	   return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
	}
	 
	  /* report a zlib or i/o error */
	 void zerr(int ret)
	 {
	    fputs("zpipe: ", stderr);
	    switch (ret) {
	      case Z_ERRNO:
	        if (ferror(stdin))
	          fputs("error reading stdin\n", stderr);
	        if (ferror(stdout))
	          fputs("error writing stdout\n", stderr);
	        break;
	      case Z_STREAM_ERROR:
	        fputs("invalid compression level\n", stderr);
	        break;
	      case Z_DATA_ERROR:
	        fputs("invalid or incomplete deflate data\n", stderr);
	        break;
	      case Z_MEM_ERROR:
	        fputs("out of memory\n", stderr);
	        break;
	      case Z_VERSION_ERROR:
	        fputs("zlib version mismatch!\n", stderr);
	    }
	 }

zpipe.cpp
^^^^^^^^^

.. code-block:: cpp

	#include "infdef.h"
	#include <iostream>
	 
	using namespace std;
	 
	/* compress or decompress */
	int main(void)
	{
	   int ret;
	   string request="";
	 
	   while (true)
	   {
	      cout<<"Do you want to compress or decompress a file (to exit 'CTRL+C')? <comp|decomp>"<<endl;
	      cin>>request;
	      if (request=="comp" || request=="decomp")
	        break;
	   }
	 
	  string name_file_source = "";
	  string name_file_dest = "";
	  float size_src=0.0, size_dest=0.0;
	 
	  /*
	   Enter or path to file, for example:
	   C:/Users/User/file.txt
	   Or
	   If you save the file in the bin folder, where
	   you will have the *.exe file, you just need write
	   name and extension file:
	       file.txt
	  */
	 
	  cout<<"Enter file source name: "<<endl;
	  cin>>name_file_source;
	  cout<<"Enter file destination name: "<<endl;
	  cin>>name_file_dest;
	 
	  FILE *source=NULL;//original file
	  FILE* dest=NULL; //file to compress or decompress
	 
	 /* do compression if "comp" specified */
	   if (request == "comp") {
	      try
	      {
	         source = fopen(name_file_source.c_str(),"r");
	         if(!source)
	            throw 0;
	      }
	      catch (int n)
	      {
	         cout << "File does not exist, method return with " << n << endl;
	         return 0;
	      }
	  
	      dest = fopen(name_file_dest.c_str(),"wb");//wb because write to binary format
	      ret = def(source, dest ,Z_DEFAULT_COMPRESSION);
	      if (ret != Z_OK)
	         zerr(ret);
	      else
	      {
	        /* Calculate size file to see the difference */
	        size_src = ftell(source);
	        size_dest = ftell(dest);
	    
	        cout<<"The original file size is: "<<size_src<<endl;
	        cout<<"The file size after being compressed is: "<<size_dest<<endl;
	      }
	      return ret;
	   }
	    
	   /* do decompression if "decomp" specified */
	   else {
	      try
	      {
	         source = fopen(name_file_source.c_str(),"rb");//rb because read from binary format
	         if(!source)
	            throw 0;
	      }
	      catch (int n)
	      {
	         cout << "File does not exist, method return with " << n << endl;
	         return 0;
	      }
	  
	      dest = fopen(name_file_dest.c_str(),"w");
	      ret = def(source, dest);
	      if (ret != Z_OK)
	         zerr(ret);
	      else
	      {
	        /* Calculate size file to see the difference */
	        size_src = ftell(source);
	        size_dest = ftell(dest);
	    
	        cout<<"The original file size is: "<<size_src<<endl;
	        cout<<"The file size after being decompressed is: "<<size_dest<<endl;
	      }
	      return ret;
	    }
	  return 1;
	}

Then, you need find all the depencies of your project, in this case, zlib.h, so execute in console::

	$ bii find

Next, you can already run the code::

	$ bii cpp:run

Then you'll be requested to select compression or decompression any file, and the file source name and file destination name.

This will be the output if you would want to compress a file.txt which is in your desktop directory and the compressed name file would be file.gz. The last one will be created in your ~/hive_directory/bin/ directory::

	Do you want to compress or decompress a file (to exit 'CTRL+C')? <comp|decomp>
	comp
	Enter file source name:
	C:\Users\Usuario\Desktop\file.txt
	Enter file destination name:
	file.gz
	The original file size is: 16944
	The file size after being compressed is: 5152


In this case file.txt had a size of 16944 bytes and file.gz 5152 bytes.

Now, if you want to decompress the file.gz to check all is correct, run the code again and the output will be the next::

	Do you want to compress or decompress a file (to exit 'CTRL+C')? <comp|decomp>
	decomp
	Enter file source name:
	file.gz
	Enter file destination name:
	myfile.txt
	The original file size is: 5152
	The file size after being decompressed is: 16944

Finally, you can see that the new file, myfile.txt, has been created in the ~/hive_directory/bin/ directory and it´s exactly like the file.txt in terms of size and content.


