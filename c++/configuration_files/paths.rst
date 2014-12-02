.. _paths_bii:

``paths.bii``: specifying non-file-relative #include(s)
=======================================================

Use ``paths.bii`` to tell biicode in which folders it has to look for the local files specified in your `#includes`. You only need to specify this when your project has `non-file-relative #include (s)`. Here's how to do it:

* Create a ``paths.bii`` file in the `project/blocks/username/bii` folder::

	|-- my_project
	|    +-- bii
	|    +-- bin
	|    +-- blocks
	|    |	  +-- user25
	|    |    |     +-- library
	|    |    |     |     +-- bii
	|    |    |     |     |    |-- paths.bii

* Write into your :ref:`paths.bii <paths-common>` the folders where biicode has to look for the local files. 
* Make sure it compiles, by updating your :ref:`CMakeLists.txt  <paths-compile>`.
Let's understand this with a couple examples:

.. _paths-common:

Common use case example
-----------------------

Libraries usually have a folder structure like this one ::

|-- library
|    +-- include
|    |    |-- tool.h
|    +-- test
|    |    |-- main1.cpp (#include "tool.h")

In which main1.cpp includes: ``#include "tool.h"`` that it is truly located into **/include** folder. The proper #include would be ``#include "../include/tool.h"``

If we execute ``bii deps`` on this example, we'll see ``#include "tool.h"`` as unresolved. Why is this happening? 
Biicode, as well as the compiler, can't find the ``tool.h`` file unless we tell them where they can find it. 

Let's fix this: Create a **paths.bii** file into the **bii/**  subdirectory located into our block::

|-- library
|    +-- bii
|    |    |-- paths.bii
|    +-- include
|    |    |-- tool.h
|    +-- test
|    |    |-- main1.cpp (#include "tool.h")

And write into the paths.bii file:

.. code-block:: text

	/include


NOTE: You can always update the #includes instead of using **paths.bii**, ``#include "tool.h"`` -> ``#include "../include/tool.h"`` 

Root directory example
----------------------
Let's imagine now that we have a folder with the following structure into it ::

|-- mylib.h
|-- mylib.cpp
|    +-- examples
|    |	  |-- main.cpp (#include "mylib.h")

If we execute ``bii deps`` on this example, we'll see ``mylib.h`` as unresolved. Why is this happening? 
Biicode, as well as the compiler, considers the ``#include(s)`` relative to their location. So if there isn't a root folder they can refer to, when looking for ``mylib.h`` they will search it in the ``examples`` folder and they won't be able to find it.

What should we write on the ``paths.bii`` file?

.. code-block:: text

	/


Write ``/`` and biicode will know that it has to include the root directory on their search.

.. _paths-compile:

But, wait a minute, this isn't compiling
----------------------------------------
Well, the compiler also needs to understand your folder structure in the compiler's own language, so you have tell it in a CMakeLists.txt file located into your blocks/library main folder ::


|-- my_project
|    +-- bii
|    +-- bin
|    +-- blocks
|    |	  +-- user25
|    |    |     +-- library
|    |    |     |     |-- CMakeLists.txt
|    |    |     |     +-- bii
|    |    |     |     |    |-- paths.bii
|    |    |     |     +-- include
|    |    |     |     |    |-- tool.h
|    |    |     |     +-- test
|    |    |     |     |    |-- main1.cpp (#include "tool.h")

So, to achieve this, you should include, after the line ``ADD_BIICODE_TARGETS`` as many lines as directories you've included in your ``paths.bii`` file, so CMake understands it has to include those files while compiling.

On the **Common use case example** you should write right bellow ``ADD_BIICODE_TARGETS``:

.. code-block:: cmake

   TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

And on the **Root directory example**:

.. code-block:: cmake

   TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


That's nice, but why doesn't biicode speak CMakeLists.txt language for this?
----------------------------------------------------------------------------

Well, Biicode needs to know your code connections so if somebody reuses your code and includes ``mylib.h`` file in his/her program, biicode will automatically retrieve all the files ``mylib.h`` depends on.

That's why it's so important that ``bii deps`` command doesn't get any **unresolved dependencies**, this way biicode will be able to get all the files needed when somebody #includes your library. And as we've explained before, it will only get the files needed and no more.

Then, why doesn't biicode create a full CMakeLists.txt specifying the directories I need?
-----------------------------------------------------------------------------------------

We get it, you've already included information on the ``paths.bii`` file and maybe you're one of the bunch interested on biicode doing so. 

We've thought deeply about it, but we know that including them automatically maybe mistaken sometimes and could break your project's setup. Don't forget you can always write relative #include lines in your code and you won't have any of this troubles.

Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.



