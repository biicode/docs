.. _bcl:

Basic Compression Library
==========================

`Basic Compression Library <http://bcl.comli.eu/>`_ by Marcus Geelnardis a set of open source implementations of several well known lossless compression algorithms, such as Huffman and RLE, written in portable ANSI C.
Currently, RLE (Run Length Encoding), Huffman, Rice, Lempel-Ziv (LZ77) and Shannon-Fano compression algorithms are implemented.

The Basic Compression Library is completely independent of system functions, such as file I/O or memory allocation routines. As such it can be used in almost any system, ranging from Windows, Mac OS X and Linux-systems to embedded systems.

You can check the `BCL documentation <http://bcl.comli.eu/index.php?media=manual>`_ for more information.

BCL library is stored at `marcus256/bcl <http://www.biicode.com/marcus256/bcl>`_ an it is generated from this `Github repository <https://github.com/MariadeAnton/bcl>`_.

Simple Huffman Compression - Uncompression
-----------------------------------------------

This example demonstrates how to get started using **BCL**. You'll learn to compress and uncompress a text file. It is simple to run.

Creating a new project
^^^^^^^^^^^^^^^^^^^^^^

Create a new project and a *main.cpp* inside like this:

.. code-block:: bash

   $ bii init bcl_example -L
   $ cd bcl_example
   $ # Create main.cpp

The code of the example is this one, it simply creates a new file *myfile.txt* and then it compresses and uncompresses the file created. It also calculates the time it takes to compress it.

Copy the code in the *main.cpp*:

**main.cpp**

.. code-block:: cpp

  /* Standard libraries */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  /* Basic Compression Library */
  #include "huffman.h"

  /* Timing */
  #include "systimer.h"


  /*************************************************************************
  * GetFileSize()
  *************************************************************************/

  long GetFileSize( FILE *f )
  {
    long pos, size;
    pos = ftell( f );
    fseek( f, 0, SEEK_END );
    size = ftell( f );
    fseek( f, pos, SEEK_SET );
    return size;
  }


  /*************************************************************************
  * CompressFile()
  *************************************************************************/

  int TestFile( ) 
  {
    unsigned int  insize, outsize, bufsize, *work, k, err_count;
    unsigned char *in, *out, *buf;
    FILE          *f;
    double        t0, t1, t_comp, t_uncomp;

    printf( "Compressing MyFile, ");

    /* Open input file */
    f = fopen( "myfile.txt", "rb" );
    if( !f )
    {
      printf( "unable to open!\n" );
      return 0;
    }

    /* Get input size */
    insize = GetFileSize( f );
    printf( "File Size:",f );
    if( insize < 1 )
    {
      printf( "empty file!\n" );
      fclose( f );
      return 0;
    }

    /* Worst case output buffer size */
    bufsize = (insize*104+50)/100 + 384;

    /* Allocate memory */
    in = (unsigned char *) malloc( insize + 2*bufsize );
    if( !in )
    {
      printf( "out of memory!\n" );
      fclose( f );
      return 0;
    }

    /* Pointers to compression buffer and output memory */
    buf = &in[ insize ];
    out = &buf[ bufsize ];

    /* Read and close input file */
    fread( in, 1, insize, f );
    fclose( f );

    /* Compress and decompress */
   
        t0 = GetTime();
        outsize = Huffman_Compress( in, buf, insize );
        t_comp = GetTime() - t0;
        t1 = GetTime();
        Huffman_Uncompress( buf, out, outsize, insize );
        t_uncomp = GetTime() - t1;

    err_count = 0;
    if(outsize > 0)
    {
      /* Show compression result */
      printf( "\n  Compression: %d/%d bytes (%.1f%%)", outsize, insize,
              100*(float)outsize/(float)insize );

      /* Compare input / output data */
      for( k = 0; k < insize; ++ k )
      {
        if( in[ k ] != out[ k ] )
        {
          if( err_count == 0 ) printf( "\n" );
          if( err_count == 30 ) printf( "    ...\n" );
          else if( err_count < 30 )
          {
              printf( "    %d: %d != %d\n", k, out[ k ], in[ k ] );
          }
          ++ err_count;
        }
      }

      /* Did we have success? */
      if( err_count == 0 )
      {
        printf( " - OK!\n" );
        printf( "    Compression speed: %.1f KB/s (%.2f ms)\n",
                (double) insize / (1024.0 * t_comp), 1000.0 * t_comp );
        printf( "    Uncompression speed: %.1f KB/s (%.2f ms)\n",
                (double) insize / (1024.0 * t_uncomp), 1000.0 * t_uncomp );
      }
      else
      {
        printf( "    *******************************\n" );
        printf( "    ERROR: %d faulty bytes\n", err_count );
        printf( "    *******************************\n" );
      }
    }

    /* Free all memory */
    free( in );

    return (outsize > 0) && (err_count == 0);
  }

  int main()
  {
     FILE * pFile;
     char buffer [100];

     pFile = fopen ("myfile.txt" , "w+");
     fprintf(pFile, "%s %s %s %d", "We", "are", "in", 2014);
     if (pFile == NULL) perror ("Error opening file");
     else
     {
       while ( ! feof (pFile) )
       {
         if ( fgets (buffer , 100 , pFile) == NULL ) break;
         fputs (buffer , stdout);
       }
       fclose (pFile);
     }
     TestFile();
  }


Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 your_user/bcl_example depends on:
       system:
          stdio.h
          stdlib.h
          string.h
       unresolved:
          huffman.h
          systimer.h


Now, edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

.. code-block:: text

 [requirements]
     marcus256/bcl: 2
 
 [includes]
     *.h: marcus256/bcl/src


Check again with **bii deps** to show all resolved dependencies.

Build the project
^^^^^^^^^^^^^^^^^

Now, build and run the huffman compression-uncompression example.

.. code-block:: bash

 $ bii build
 $ cd bin
 $ examples_bcl_main

Once you execute you should see an output like this one, it may vary depending on your computer:
  
.. code-block:: bash
   
   Compressing MyFile, File Size:
     Compression: 20/14 bytes (142.9%) - OK!
       Compression speed: 1246.6 KB/s (0.01 ms)
       Uncompression speed: 4778.7 KB/s (0.00 ms)

That's all! You can try it with other files too.

Open and build
--------------

This example is already in biicode: `examples/bcl <http://www.biicode.com/examples/bcl>`_.

To give it a try, create a new project and open the block:

.. code-block:: bash

 $ bii init bcl_example
 $ cd bcl_example
 $ bii open examples/bcl

Build the example and execute it:

.. code-block:: bash

 $ bii build
 $ cd bin
 $ # Execute it
   Compressing MyFile, File Size:
     Compression: 20/14 bytes (142.9%) - OK!
       Compression speed: 1246.6 KB/s (0.01 ms)
       Uncompression speed: 4778.7 KB/s (0.00 ms)


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.



