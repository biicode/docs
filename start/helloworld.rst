"Hello World!" in C++
=====================

We will start with a simple example: the well-known "Hello World".

Create a new hive
-----------------

Open your console, move to your biicode workspace and create a new hive named "hello":

.. code-block:: bash

	$ cd ../biicode_workspace
	$ bii new hello

If it works correctly, you should see the following message:

.. code-block:: bash

	Created new Hive hello

Inside your workspace you will find a folder named hello with subfolders bii, dep and src.

Just code!
----------

Our "hello" hive project will have the following 3 files, just copy them to your hive inside the src folder, under the block name your_user_name/hello, i.e. inside /hello/src/your_user_name/hello/

**hello.h**

.. code-block:: cpp
	:linenos:
	
	#pragma once
	 
	//Method to print "Hello World"
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

Put those files into the folder  ~/hello/src/your_user_name/hello/, and write:

.. code-block:: bash

	$ cd hello
	$ bii cpp:run

After a while, this message will appear in your console:

.. code-block:: bash

	Hello World
 
Publish your code
-----------------

Uploading your code to Biicode is really simple, just type:

.. code-block:: bash

	$ bii publish

Then you will be requested to write a tag and a message:

.. code-block:: bash

	block:     your_name_user/hello
	$ introduce tag: STABLE 
	$ introduce msg: My first project with biicode

In the Tag option, you could write STABLE, ALPHA, BETA and DEV, depending on state of your code.

If your code has been published correctly, you will see a message like the following:

.. code-block:: bash

    Reading Hive...
    Permissions OK
    Preparing publication data for publish version -1
    Remote read block your_user_name/your_user_name/hello/master:#-1
    Sending data!
    Committing publish...
    Successfully published your_user_name/your_user_name/hello/master:#0

You will be able to navigate to your homepage www.biicode.com/your_user_name, and to navigate your recently uploaded code.

Reuse it!
---------

Now you will see how simple it is to reuse existing source code from biicode. As the published files have already been uploaded to biicode servers, it is possible for anyone —even other users— to do the following from another computer or location.

First, create a new hive named hellopretty

.. code-block:: bash

	$ cd ..
	$ bii new hellopretty
	$ cd hellopretty 

Add the following files to the folder ~/src/your_user_name/hellopretty/

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

To resolve any missing dependencies (in this case, the hello.h is not part of our project), we use:

.. code-block:: bash

	$ bii find

If the server successfully finds the dependencies, you will see a message like the following on your screen:

.. code-block:: bash

	Finding missing dependencies in server
	Looking for diego/hello...
	    >> Block candidate: diego/diego/hello/master
	    >> Version diego/diego/hello/master:#0 (STABLE) valid due your policy!
	    Found blocks: diego/diego/hello/master:#0
	Analyzing compatibility for found dependencies...
	    Resolved block!
	Dependencies resolved in server:
	Find resolved new dependencies:
	        diego/diego/hello/master:#0
	All dependencies resolved

You can try the new method in your console compiling and executing your new code. Write this at the hive's directory:

.. code-block:: bash

	$ bii cpp:run
	**********************************
	Hello World
	**********************************

You will find your_user_name/hello block with the recently retrieved source files hello.h and hello.cpp in your hive hellopretty/dep subfolder. Note that the main.cpp of the hello block has not been retrieved. You don't need it to reuse the hello function! 

Publish a new version of your hello block
-----------------------------------------

Change the message in the file to "Hello biicode".

**hello.cpp**

.. code-block:: cpp
	:linenos:

	#include "hello.h"
	#include  <iostream>
	using namespace std;
	 
	void hello(){
	 cout<<"Hello biicode"<<endl;
	}

Execute your block:

.. code-block:: bash

	$ cd ..
	$ cd hello
	$ bii cpp:run
	...
	Hello biicode

Now, post your block like before:

.. code-block:: bash

	$ bii publish
	block:     your_name_user/hello
	$ introduce tag: STABLE 
	$ introduce msg: My first update of my block
	...
	Successfully published diego/diego/hello/master:#1

As you can see, the version of your block changed from 0 to 1 
 
Update your hellopretty block with the new version of hello
-----------------------------------------------------------

To update your hellopretty block you only have to search the server for the published modifications of your dependencies.

.. code-block:: bash

	$ cd ..
	$ cd hellopretty
	$ bii find --update     (from version 0.1.10, before $ bii find --modify-existing)

If the server finds modifications that have been published before, a message like the following will appear in your console:

.. code-block:: bash

	Finding missing dependencies in server
	Analyzing compatibility for found dependencies...
	    Updated block!
	Dependencies resolved in server:
	All dependencies resolved
	Updated dependencies:
	        diego/diego/hello/master:#1
	Saving files on disk
	Computing dependencies
	Retrieving resources from server
	Retrieving resources from server
	Saving dependences on disk

Finally, just re-run cpp:run to see how your block has been updated.

.. code-block:: bash

	$ bii cpp:run

After a while, you will see this in your console:

.. code-block:: bash

	**********************************
	Hello biicode
	**********************************