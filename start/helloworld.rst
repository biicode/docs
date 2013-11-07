"Hello World!" in C++
=====================

This example shows how to build a simple "Hello World" appliction with biicode.

Create a new hive
-----------------

Creating a new hive is as easy as executing the ``bii new`` command. Open your console, move to your biicode workspace and create a new hive named **"hello"**:

.. code-block:: bash
	:emphasize-lines: 3

	$ cd /path/to/your/biicode_workspace
	$ bii new hello
	Created new Hive hello

In the previous figure, the highlighted line indicates that the process worked fine. Inside your workspace you will find a new folder named ``hello`` containing the subfolders ``bii``, ``dep`` and ``src`.

Just code!
----------

Our "hello" hive will have the following 3 files. Just copy them into your hive ``hello/src/your_user_name/hello`` folder. That is the source code for your **hello block** in you **hello hive**.

**hello.h**

.. code-block:: cpp
	:linenos:
	
	#pragma once
	 
	//Method to print "Hello World!"
	void hello();

**hello.cpp**

.. code-block:: cpp
	:linenos:

	#include "hello.h"
	#include  <iostream>
	using namespace std;
	 
	void hello(){
	 cout<<"Hello World"<<endl;
	}

**main.cpp**

.. code-block:: cpp
	:linenos:

	#include "hello.h"
	 
	int main() {
	  hello();
	  return 1;
	}

Build and run
-------------

Once you have completed all the coding process, and the source files are located under ``hello/src/your_user_name/hello``, you are ready to compile and run the application. Assuming that you are located in your biicode workspace folder, ``cd`` to your **"hello" hive folder**, and run the ``bii cpp:run`` command:

.. code-block:: bash

	$ cd hello
	$ bii cpp:run

Note that the ``bii cpp:run`` command needs to be executed from a folder containing a hive. After some messages showing information about the compiling process, the output message will appear in your console:

.. code-block:: bash

	Hello World!
 
Publish your code
-----------------

Once your have written, compiled and successfully executed some code, surely you are willing to share it with the biicode community! Uploading your code to biicode is really simple using the ``bii publish`` command. You will be requested to provide a **tag** and a **message**. Valid tags are ``STABLE``, ``ALPHA``, ``BETA``, and ``DEV``. They provide information about the development state of your hive. The message is any information describing your publication.

.. code-block:: bash

	$ bii publish
	block:   your_user_name/hello
	Introduce tag: STABLE
	Introduce msg: My first project with biicode
	  Reading Hive...
	  Checking block your_user_name/your_user_name/hello/master
	  Permissions OK

	  Preparing publication data for publish version 0

	  Remote read block your_user_name/hello(luispedraza/master): -1

	  Sending data!

	  Committing publish...
	Successfully published your_user_name/hello(your_user_name/master): 0

If your code has been published correctly —as it is the case in the previous example—, you can navigate using your favourite Web browser to you biicode homepage (located at http://www.biicode.com/your_user_name) and inspect online your new block.

Reuse it!
---------

One of the most interesting aspects of biicode is the ability it provides to easily reuse code. As the published files have already been uploaded to biicode servers, it is possible for anyone —even other biicode users— to use these files in new projects. We'll show the process creating a new hive named **"hellopretty"**. From your biicode workspace folder, execute again the ``bii new`` command to create a new hive:

.. code-block:: bash

	$ cd /path/to/your/biicode_workspace
	$ bii new hellopretty
	Created new Hive hellopretty
	$ cd hellopretty 

Add the following files to the folder ``hellopretty/src/your_user_name/hellopretty/`` (remember to substitute ``your_user_name`` with your actual biicode user name):

**hellopretty.h**

.. code-block:: cpp
	:linenos:

	#pragma once
	 
	void hellopretty ();

**hellopretty.cpp**

.. code-block:: cpp
	:linenos:

	#include "your_user_name/hello/hello.h" //reusing hello.h header
	#include "hellopretty.h"
	#include <iostream>
	 
	using namespace std;
	 
	void hellopretty (){   
	   cout<<"**********************************"<<endl;
	   hello();
	   cout<<"**********************************"<<endl;
	}

**main.cpp**

.. code-block:: cpp
	:linenos:

	#include "hellopretty.h"
	 
	int main(){ 
	    hellopretty();
	    return 1;
	}

In this case we are maing use of the ``hello()`` function, which is not explicitly defined in the current hive. If you tried to compile and run this program using the ``bii cpp:run`` command, you would see an error message:

.. code-block:: bash

	Detected 3 files created, 0 updated
	Processing hive
	  Cell your_user_name/hellopretty/hellopretty.h is implemented by set(['your_user_name/hellopretty/hellopretty.cpp'])
	...
	...
	#include "your_user_name/hello/hello.h" //reusing hello.h header
	         ^
	1 error generated.
	...
	...
	[!] Make failed

However, biicode knows that you are trying to reuse the ``hello.h`` header. To resolve the missing dependencies we use the ``bii find`` command. Hopefully the server will find the dependencies, and you will see a success message on your screen:

.. code-block:: bash

	$ bii find
	Finding missing dependencies in server
	Looking for your_user_name/hello...
	  >> Block candidate: your_user_name/hello(your_user_name/master)
	  >> Version your_user_name/hello(your_user_name/master): 0 (STABLE) valid due your policy!
	  Found blocks: your_user_name/hello(your_user_name/master): 0
	Analyzing compatibility for found dependencies... 
	  Resolved block!
	Dependencies resolved in server:
	Find resolved new dependencies:
		your_user_name/hello(your_user_name/master): 0
	All dependencies resolved
	Saving files on disk
	Computing dependencies
	Retrieving resources from server
	Retrieving resources from server
	Saving dependences on disk

Now you can try to compile and run again your new code. In this case the process will succeed:

.. code-block:: bash

	$ bii cpp:run
	No deps to find
	...
	...
	**********************************
	Hello World!
	**********************************

You will find the ``your_user_name/hello`` block along with the retrieved source files ``hello.h`` and ``hello.cpp`` in your  ``hellopretty/dep`` subfolder. Note that the ``main.cpp`` file of the **hello** block was not retrieved. That is because you don't need it to reuse the ``hello()`` function! 

Publish a new version of your hello block
-----------------------------------------

Modifying your code and publishing the results is easy with biicode. Now we´ll change the message displayed by the ``hello()`` function in the **hello** block. Update the ``hello.cpp`` as following:

**hello.cpp**

.. code-block:: cpp
	:linenos:
	:emphasize-lines: 6

	#include "hello.h"
	#include  <iostream>
	using namespace std;
	 
	void hello(){
	 cout<<"Hello biicode!"<<endl;
	}

Execute your block, to make sure everything works as expected:

.. code-block:: bash

	$ cd /path/to/your/biicode_workspace/hello
	$ bii cpp:run
	...
	Hello biicode!

Now, post your block to the biicode server just like you did before:

.. code-block:: bash

	$ bii publish
	block:     your_user_name/hello
	$ introduce tag: STABLE 
	$ introduce msg: My first block update
	...
	...
	Successfully published your_user_name/hello(your_user_name/master): 1

As you can see, the version of your block changed from 0 to 1. Your can see both versions published online visiting your biicode user main page, as before.
 
Update your hellopretty block with the new version of hello
-----------------------------------------------------------

To update your **hellopretty** block you only need to search the server for any published new versions of your dependencies using the ``bii find`` command with the ``--update`` modifier. If the server finds new published versions of any dependencies, you'll see a corresponding message on your screen:

.. code-block:: bash
	:emphasize-lines: 8,9

	$ cd /path/to/your/biicode_workspace/hellopretty
	$ bii find --update
	Finding missing dependencies in server
	Analyzing compatibility for found dependencies... 
	  Updated block!
	Dependencies resolved in server:
	All dependencies resolved
	Updated dependencies:
		your_user_name/your_user_name/hello/master:#1

	Saving files on disk
	Computing dependencies
	Retrieving resources from server
	Retrieving resources from server
	Saving dependences on disk


Finally, you can input the ``bii cpp:run`` command to see how your block has been updated.

.. code-block:: bash

	$ bii cpp:run
	...
	...
	**********************************
	Hello biicode!
	**********************************