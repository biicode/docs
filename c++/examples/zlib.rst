Zlib
====

Zlib is a software library written in C language used for data compression. For more information about this library, visit its `official website <http://www.zlib.net/>`_ or `Documentation <http://www.zlib.net/manual.html>`_.

This is the `biicode library site <https://www.biicode.com/zlib/zlib>`_ and this is the `biicode library examples <https://www.biicode.com/examples/zlib>`_.

Usage example (difficulty: medium)
----------------------------------

To check this library, we're using an `example <https://www.biicode.com/examples/zlib>`_ to compress and decompress a single file. We will use a \*.h and a \*.cpp file named **infdef.h** (inflate and deflate) and a **zpipe.cpp**.

The following code would be in each one.

**infdef.h**

.. literalinclude:: /_static/code/cpp/examples/zlib/infdef.h
   :language: cpp
   :linenos:
   :emphasize-lines: 3,4,5,16



**infdef.cpp**

.. literalinclude:: /_static/code/cpp/examples/zlib/infdef.cpp
   :language: cpp
   :linenos:



**zpipe.cpp**

.. literalinclude:: /_static/code/cpp/examples/zlib/zpipe.cpp
   :language: cpp
   :linenos:

   
Create a new project and open the example block:

.. code-block:: bash

	$ bii init zlib_example
	$ cd zlib_example
	$ bii open examples/zlib

Next, you can build and run the code:

.. code-block:: bash

	$ bii cpp:build
	$ cd bin
	$ #run executable

Then you'll be requested to select compression or decompression any file, and the file source name and file destination name.

This will be the output if you would want to compress a file.txt which is in your desktop directory and the compressed name file would be file.gz. The last one will be created in your ~/project_directory/bin/ directory

.. code-block:: bash

	Do you want to compress or decompress a file (to exit 'CTRL+C')? <comp|decomp>
	comp
	Enter file source name:
	C:\Users\Usuario\Desktop\file.txt
	Enter file destination name:
	file.gz
	The original file size is: 16944
	The file size after being compressed is: 5152


In this case file.txt had a size of 16944 bytes and file.gz 5152 bytes.

Now, if you want to decompress the file.gz to check all is correct, run the code again and the output will be the next

.. code-block:: bash

	Do you want to compress or decompress a file (to exit 'CTRL+C')? <comp|decomp>
	decomp
	Enter file source name:
	file.gz
	Enter file destination name:
	myfile.txt
	The original file size is: 5152
	The file size after being decompressed is: 16944

Finally, you can see that the new file, myfile.txt, has been created in the ~/project_directory/bin/ directory and it's exactly like the file.txt in terms of size and content.
