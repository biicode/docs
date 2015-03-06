POCO 
====

`POCO <http://pocoproject.org/>`_ POCO is an open-source third-party library, which contains a collection of C++ class libraries that simplify and accelerate the development of network-centric, portable applications in C++. With POCO you can develop network- and internet-based applications that run on desktop, server, mobile and embedded systems.

POCO C++ libraries available at biicode are:
	
	* `Poco (develop) <https://www.biicode.com/fenix/fenix/poco/develop>`_

	* `Poco v1.6.0 <https://www.biicode.com/fenix/fenix/poco/v1.6.0>`_

  	* `Poco v1.5.4 <https://www.biicode.com/fenix/fenix/poco/v1.5.4>`_

  	* `Poco v1.4.7p1 <https://www.biicode.com/fenix/fenix/poco/v1.4.7p1>`_

There are so many things you can try with POCO. This example shows a **PDF conversion** example from strings.

PDF example
-----------

This example is `already in biicode <http://www.biicode.com/examples/poco_pdf>`_. So just open the block:

.. code-block:: bash

 $ bii init pocoproject
 $ cd pocoproject
 $ bii open examples/poco_pdf

.. container:: infonote

 Windows users should use Visual Studio.

 .. code-block:: bash 

     $ bii cpp:configure -G "Visual Studio 12"

Choose your PDF output name, the font and size, the page of the document, the content of the string and the margins from the pdf page we want to generate:

**pdf.cpp**

.. literalinclude:: /_static/code/cpp/examples/poco/pdf.cpp
   :language: cpp
   :linenos:

**Note** that the original ``includes`` are mapped in the **biicode.conf** file of the block.

Generate the PDF
----------------

Now execute ``bii cpp:build`` to build the project.

.. code-block:: bash
 
 $ bii cpp:build

Go to bin directory and execute:

.. code-block:: bash
 
 $ cd bin
 $./examples_poco_pdf_pdf
 Text.pdf saved correctly

Your pdf file is ready! Look for it in your */bin* folder.

Got any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_, visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.