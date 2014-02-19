"Hello World!" C++ Raspberry Pi Cross Compiling
===============================================

In this section you'll learn how to write, cross-compile and execute your first *'Hello World'* program for your Raspberry Pi using biicode.

It is assumed that you have already :ref:`installed biicode on your system and created a workspace <first_steps>`, and :ref:`installed the tools for cross compiling <rpi_corss_compiling>`. **These previous two steps are mandatory** for the following instructions to work properly.

1. Create a new hive
--------------------

First of all, create a new hive inside your workspace using the ``bii new`` command. Open your console, move to your biicode workspace and **create a new hive named** ``hello_rpi_hive``:

.. code-block:: bash

	$ bii new hello_rpi_hive

The biicode assistant will ask you some questions regarding your **hive preferences**. For this tutorial we'll choose ``cpp`` as our programming language, and no IDE configuration. We'll create a new block named ``hello_rpi``. The assistant is also able to generate a default C++ *'hello world block'* for you, but in this case we will write the files from scratch. All in all, these are the options you should input when prompted:

.. code-block:: bash

	Created new hive hello_rpi_hive
	Select language: (java/node/fortran/python/cpp/arduino/None)
	Introduce lang (default:cpp): cpp
	Generate a default hello world? (YES/no) no
	Select IDE family: (Visual/CodeBlocks/Eclipse/NetBeans/None)
	Introduce ide (default:None): none
	Select build type: (None/Debug/Release/RelWithDebInfo/MinSizeRel)
	Introduce build type (default:Debug): debug

Inside your workspace you will find a new folder named ``hello_rpi_hive`` containing the subfolders ``bii`` (for your hive configuration files), ``deps`` and ``blocks``, and the following layout:

.. code-block:: text

   +-- hello_rpi_hive
   |    +-- bin
   |    +-- blocks
   |    |     +-- username
   |    |    |     +-- hello_rpi
   |    +-- build
   |    +-- cmake
   |    +-- deps

The ``bii`` folder contains specific configuration files for your hive. **You must update your settings and change the architecture** of the desired cpp compiler. To do so, open your ``hello_rpi_hive/bii/settings.bii`` file, look for the following lines:

.. code-block:: text

	cpp:
	  builder: {family: MAKE}
	  compiler: {arch: 32bit, family: GNU}
	  configurer: {family: CMake}
	 
and edit the *compiler* configuration as follows:

.. code-block:: text
	:emphasize-lines: 3
	 
	cpp:
	  builder: {family: MAKE}
	  compiler: {arch: ARM, family: GNU}
	  configurer: {family: CMake}

2. Just code!
-------------

Our ``hello_rpi`` block will contain the following three files: ``hello.h``, ``hello.cpp`` and ``main.cpp``. Just create them into your hive ``hello_rpi_hive/blocks/username/hello_rpi`` folder and copy and paste the following code.

**hello.h**

.. literalinclude:: ../_static/code/cpp/hello-world/hello.h
   :language: cpp


**hello.cpp**

.. literalinclude:: ../_static/code/cpp/hello-world/hello.cpp
   :language: cpp


**main.cpp**

.. literalinclude:: ../_static/code/cpp/hello-world/main.cpp
   :language: cpp


You can download these files here: :download:`hello.zip <../_static/code/cpp/hello-world/hello.zip>`

	
3. Build, deploy and run your program
-------------------------------------

Now you are ready to compile and deploy your new application. First, **cross-compile your program** and make sure the binary is generated running ``bii cpp:build`` from your hive location:

.. code-block:: bash

	$ bii cpp:build
	...
	Configuring cross compiler for ARM architecture:
	...
	[100%] Built target username_hello_rpi_main

The ouput indicates that the compiler has been configured for ARM architecture (using information provided in your workspace ``environment.bii`` configuration file, :ref:`as explained here<rpi_cc_tools>`).

The binaries are created in your hive's ``bin`` folder, but remember that **you cannot run this program locally, as it has been generated for a different architecture** using the cross-compiling tools. You need to send the binary to your Raspberry Pi to be executed.

**Note:** You can both compile and run locally your program restoring your ``hello_rpi_hive/bii/settings.bii`` configuration to the default ``32bit`` architecture. This is just simple C++ code, and you only need to change the compiler configuration!

To **send your binary to Raspberry Pi**, you only need to execute the ``rpi:send`` command and the file will be sent by `rsync <http://en.wikipedia.org/wiki/Rsync>`_ to the address provided in your workspace ``default_settings.bii`` file during the :ref:`cross-compiling configuration process <rpi_default_settings>`.

.. code-block:: bash

	$ bii rpi:send
	Sending with rsync -Pravdtze ssh [HIVE_DIRECTORY]/bin/* [RPI_USER]@[RPI_IP]:[DIRECTORY]/[HIVE_NAME]

	[RPI_USER]@[RPI_IP]'s password:

The Raspberry Pi user's password will be asked. If you have not changed your password, for Raspbian the default one is **raspberry**.

If you want to send programs to another Raspberry Pi or specify a directory other than the one that appears in your ``default_settings.bii``, you can pass additional parameters to the ``bii:send`` command (get all the information about these parameters with ``bii rpi:send --help``):

.. code-block:: bash

	$ bii rpi:send <directory> <user> <ip>

Finally, to **execute your program on your Raspberry Pi**, you need to establish a connection. You can use the ``rpi:ssh`` command if you want remote access. You'll find your program deployed in the path configured in your ``default_settings.bii`` file:

.. code-block:: bash

	$ bii rpi:ssh
	...
	Connecting with ssh <rpi_user>@<rpi_ip>
	<rpi_user>@<rpi_ip>'s password:
	
	pi@raspberrypi ~ $ cd hello_rpi
	pi@raspberrypi ~/hello_rpi $ ls
	username_hello_rpi_main
	pi@raspberrypi ~/hello_rpi $ ./username_hello_rpi_main
	Hello world!
	
And that's all. Your program is working!
	
4. Publish your code
--------------------

Once your have written, compiled and successfully deployed your code, surely you are willing to share it with the biicode community! Uploading your code to biicode is really simple using the ``bii publish`` command. You will be requested to provide a **tag** and a **message**. Valid tags are ``STABLE``, ``ALPHA``, ``BETA``, and ``DEV``, providing information about the development state of your hive. The message is any information describing your publication. You can :ref:`read more about publishing here <biipublish>`.

.. code-block:: bash

	$ bii publish
	block:   username/hello_rpi
	Introduce tag: STABLE                                                           
	Introduce msg: My first Raspberry Pi project with biicode                            
	
	INFO: Successfully published username/hello_rpi(username/master): 0

If your code has been published correctly —as it is the case in the previous example—, you can already browse its conents online, on the biicode web site, visiting the url: www.biicode.com/your_user_name. You can `see an example of a published block following this link <https://www.biicode.com/luispedraza/blocks/luispedraza/hello_rpi/branches/master/>`_. In this example the biicode user ``luispedraza`` has pusblished a block named ``hello_rpi``. You can browse online the block contents and files, and inspect all branches and versions for this block:

.. image:: ../_static/img/hello_rpi.PNG


5. Reuse it!
------------

One of the most interesting aspects of biicode is the ability it provides to easily reuse code. As the published files have already been uploaded to biicode servers, it is possible for anyone —even other biicode users— to use these files in new hives. We'll show the process with a new hive named ``pretty_hive``. From your biicode workspace folder, execute again the ``bii new`` command to create a new hive:

.. code-block:: bash

	$ cd /path/to/your/biicode/workspace
	$ bii new pretty_hive

Remember to provide adequate information about your new hive preferences: ``cpp`` as programming, language, and the name for the first block in your hive, ``hellopretty`` in our case.

Now, include the following files into the ``pretty_hive/blocks/username/hellopretty/`` folder (remember to substitute ``username`` with your actual biicode user name):

**hellopretty.h**

.. code-block:: cpp

	#pragma once
	void hellopretty ();


**hellopretty.cpp**

.. code-block:: cpp

	#include "username/hello_rpi/hello.h" // reusing the hello.h header
	#include "hellopretty.h"
	#include <iostream>
	using namespace std;

	void hellopretty () {
		cout<<"**********************************"<<endl;
		hello();
		cout<<"**********************************"<<endl;
	}

**mainpretty.cpp**

.. code-block:: cpp

	#include "hellopretty.h"

	int main() {
		hellopretty();
		return 1;
	}

In this case we are using of the ``hello()`` function, which is not explicitly defined in the current hive. When you reference, or put #includes to files that have been published before, it is necessary to retrieve them. Biicode knows that you are trying to reuse the ``hello.h`` header from the ``username/hello_rpi`` block. To resolve the missing dependencies we use the ``bii find`` command:

.. code-block:: bash

	$ bii find
	
You should see a success message indicating that biicode has been able to resolve your dependencies. Check that all necessary files have been stored in your hive's ``deps`` folder. Note that the ``main.cpp`` file of the ``username/hello_rpi`` block was not retrieved. That is because you don't need it to reuse the ``hello()`` function!

Now you are ready to compile and deploy your new program. Proceed as you learned before:

.. code-block:: bash
	
	$ bii cpp:build
	...
	$ bii rpi:send
	...
	
And finally, test your program working on your Raspberry Pi:

.. code-block:: bash

	$ bii rpi:ssh
	...
	pi@raspberrypi ~ $ cd hellopretty
	pi@raspberrypi ~/hellopretty $ ls
	<binary_name>
	pi@raspberrypi ~/hellopretty $ ./<binary_name>
	**********************************
	Hello World!
	**********************************

6. Publish a new version of your hello block
--------------------------------------------

Modifying your code and publishing the results is easy with biicode. Now we'll change the message displayed by the ``hello()`` function in the ``username/hello_rpi`` block. Update the ``hello.cpp`` as follows:

**hello.cpp**

.. code-block:: cpp
   :emphasize-lines: 6

   	#include "hello.h"
	#include  <iostream>
	using namespace std;

	void hello(){
	 cout << "---- Hello biicode! ----" << endl;
	}
	
Execute your block, to make sure everything works as expected:

.. code-block:: bash

	$ cd /path/to/your/biicode_workspace/hello
	$ bii cpp:build
		...
	$ bii rpi:send
		...
	$ bii rpi:ssh
		...
	
	pi@raspberrypi ~/hellopretty $ ./<binay_name>
	pi@raspberrypi ~/hellopretty 
		
	---- Hello biicode! ----

Now, post your block to the biicode server just like you did before. From your hive folder:

.. code-block:: bash

	$ bii publish
	block:     username/hello_rpi
	Introduce tag: STABLE
	Introduce msg: My first block update for Raspberry Pi
	...
	Successfully published username/hello_rpi(username/master): 1

As you can see, the version of your block changed from 0 to 1. Your can see both versions published online visiting your biicode user main page, as before.

7. Update your hellopretty block with the modifications
-------------------------------------------------------

To update your ``username/hellopretty`` block with the new modifications to the ``hello()`` function, you only need to search the server for any published new versions of your dependencies using the ``bii find`` command and the ``--update`` modifier. If the server finds new published versions for any of your dependencies, you'll see an indicative message on your screen:

.. code-block:: bash

	$ cd /path/to/your/biicode/workspace
	$ cd hellopretty
	$ bii find --update
	...

Finally, you can test the updated code running on your Raspberry Pi.

.. code-block:: bash

	$ bii cpp:build
	...
	$ bii rpi:send
	...
	$ bii rpi:ssh
	...
	
	pi@raspberrypi ~/hellopretty $ ./[binary_name]
	**********************************
	---- Hello biicode! ----
	**********************************

**Now you might be interested in:**

   - If something went wrong, you might want to `find some help in the forum <http://forum.biicode.com/category/cross-platform-support/raspberry-pi>`_, and open a new topic if necessary.
   - Seeing :ref:`more Raspberry Pi examples <raspberry_pi>`.
   - I don't want to publish my block, as it doesn't work yet, but I want to save my hive for continuing later in a different computer. :ref:`Read here to check how <hive_usage>`.
   - Specific :ref:`Raspberry Pi commands list<bii_rpi_tools>`