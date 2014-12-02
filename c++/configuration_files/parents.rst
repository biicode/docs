.. _parents_bii:

``parents.bii``: see your tracking information
==================================================

``parents.bii`` is **created whenever you publish a block**, inside the ``bii`` block folder (see the :ref:`layouts section <project_layout>`) and **provides insight about the origins of each of the blocks currently contained in the blocks folder of your project**. 

Example
--------

If you have published just once a project with the layout below ::

|-- my_project
|    +-- bii
|    +-- bin
|    +-- blocks
|    |	  +-- user25
|    |    |     +-- my_hello_block
|    |    |     |     +-- bii
|    |    |     |     |    |-- parents.bii
|    |    |  	|     |-- hello.c
|    |    |     |     |-- hello.h

Your ``parents.bii`` would have the following content:

.. code-block:: text

	# This file contains your block ancestors versions
	* user25/my_hello_block: 0

What does it mean?

* Parent: ``user25/my_hello_block``
* Version (previous published version of your block): ``0``
|
.. container:: infonote

	Take a look at the asterisk, it indicates you who is your block's parent.
	* Don't edit this file.


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.