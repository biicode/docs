"Hello World!"  C++ Raspberry Pi Cross Compiling
--------------------------------------------------------

This example shows how to build a simple "Hello World" application with biicode.

Create a new hive
^^^^^^^^^^^^^^^^^^

Creating a new hive is as easy as executing the ``bii new`` command. Open your console, move to your biicode workspace and create a new hive named **"hello"** (some ouput informative messages are omitted):

.. code-block:: bash

	$ cd /path/to/your/biicode_workspace
	$ bii new hello
        Created new hive hello
        Select language: (java/node/fortran/python/cpp/None)
        Introduce lang (default:cpp): cpp
        INFO: Selected lang: cpp
		Introduce block name (default:my_block): my_block
		INFO: block name: my_block
        Generate a default hello world?  (YES/no) no
        Select IDE family: (Visual/CodeBlocks/Eclipse/NetBeans/None)
        Introduce ide (default:Eclipse): None
        Select build type: (None/Debug/Release/RelWithDebInfo/MinSizeRel)
        Introduce build_type (default:Debug): Debug
        invoking cmake   -G "Unix Makefiles" -Wno-dev ../cmake
	        ... here your new hive is created in your workspace
        -- Build files have been written to: /Users/luis/Workspace/biicode/production/temp/build

The command assistant will ask you some questions regarding your hive preferences. For this tutorial we have chosen ``cpp`` as our programming language, and no IDE configuration. We have also named the first hive in our block as ``my_block``. The assistant is also able to generate a default C++ 'hello world' block for you, but in this case we will write the files from scratch. Inside your workspace you will find a new folder named ``hello`` containing the subfolders ``bii``, ``deps`` and ``blocks``.

Let biicode download the cross compilers and configure your workspace
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

First, Install git-core if it is not installed:

.. code-block:: bash

	$ sudo apt-get install git-core

For biicode download and configure everything for you, you just have to run the ``bii rpi:setup`` command inside your hive:

.. code-block:: bash

	$ bii rpi:setup

	INFO: Cloning the ARM cross compiler into /usr/local/tools
	
	fatal: could not create work tree dir '/usr/local/tools'.: Permision denied
	INFO: Cloning the ARM cross compiler with sudo
	[sudo] password for [USER]:
	
If you already have downloaded the cross compilers the setup tool will indicate this with the following message:

.. code-block:: bash

	$ bii rpi:setup

	INFO: Cloning the ARM cross compiler into /usr/local/tools
	
	INFO: The tools are already Downloaded
	
If you want to download the cross compilers another folder or if you already have downloaded to another directory, you just have to indicate the directory  where you want it to clone or where it is

.. code-block:: bash

	$ bii rpi:setup [directory]

	...
	
Once you have done this, a cross compilers will have downloaded and added to :ref:`enviroment.bii <layouts>`.

Configure your settings
^^^^^^^^^^^^^^^^^^^^^^^

Update your :ref:`hello/bii/settings.bii <settings>` into your hive with the info of your Raspberry Pi ::
	
	rpi: {directory: /home/pi, ip: 192.168.1.68, password: raspberry, user: pi}
	
* **directory**: Raspberry Pi directory where you want to save the files you send for SCP
* **ip**: Raspberry Pi IP address. You can find it under ``inet addr`` field executing ``ifconfig`` in a console inside the raspberry.
* **user**: Raspberry Pi user name
* **password**: Raspberry Pi password

Change the architecture of the cpp compiler on the ``hello/bii/settings.bii`` into your hive. Where you see::

	cpp:
	  builder: {family: MAKE}
	  compiler: {amily: GNU}
	  configurer: {family: CMake}
	 
add ``arch: ARM``::
	 
	cpp:
	  builder: {family: MAKE}
	  compiler: {arch: ARM, family: GNU}
	  configurer: {family: CMake}

Just code!
^^^^^^^^^^

Our "hello" hive will have these files: ``hello.h``, ``hello.cpp`` and ``main.cpp``. Just create them into your hive ``hello/blocks/your_user_name/my_block`` and copy and paste the following code.

This is the source code for your **my_block block** in your **hello hive**:

**hello.h**

.. literalinclude:: ../_static/code/cpp/hello-world/hello.h
   :language: cpp
   :linenos:

**hello.cpp**

.. literalinclude:: ../_static/code/cpp/hello-world/hello.cpp
   :language: cpp
   :linenos:

**main.cpp**

.. literalinclude:: ../_static/code/cpp/hello-world/main.cpp
   :language: cpp
   :linenos:

Download all the files: :download:`main.cpp <../_static/code/cpp/hello-world/main.cpp>` :download:`hello.cpp <../_static/code/cpp/hello-world/hello.cpp>` :download:`hello.h <../_static/code/cpp/hello-world/hello.h>`
   
Build and send
^^^^^^^^^^^^^^

Once you have completed all the coding process, and the source files are located under ``hello/blocks/your_user_name/my_block``, you are ready to compile and run the application. Assuming that you are located in your biicode workspace folder, ``cd`` to your **"hello" hive folder**, and run the ``bii cpp:run`` command:

.. code-block:: bash

	$ cd hello
	$ bii cpp:build

Note that the ``bii cpp:build`` command needs to be executed from a folder containing a hive like any other biicode project. After some messages showing information about the compiling process, the binaries will created in your ``bin folder``.

Remember that when generating the binary by cross compilation, you can only run on the Raspberry Pi.

Send your binaries
^^^^^^^^^^^^^^^^^^

To send your binary to Raspberry Pi, you just execute the ``rpi:send`` command and the file will be send by rsync to the address that appears in your **settings.bii**:

.. code-block:: bash

	$ bii rpi:send

	...
	
	Sending with rsync -Pravdtze ssh [HIVE_DIRECTORY]/bin/* [RPI_USER]@[RPI_IP]:[DIRECTORY]/[HIVE_NAME]

	[RPI_USER]@[RPI_IP]'s password:

Finally, the Raspberry Pi user's password will be asked. If you have not changed your password, for raspbian is **raspberry**.

If you want to send files to another Raspberry Pi or specify a different directory that appears in your **settings.bii**, you have the option of passing these parameters to the ``bii:send``. These parameters are not obligatory, can be passed only a new directory and use the other parameters of **settings.bii**.

.. code-block:: bash

	$ bii rpi:send [directory] [user] [ip]
	
	...
	
	$ bii rpi:send [directory]
	

You just have to go to your Raspberry Pi and execute the binaries as any computer.

Connect with your Raspberry Pi
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can use the ``rpi:ssh`` command if you want a remotely access to your Raspberry Pi. With this command you **can run your binaries**.

.. code-block:: bash

	$ bii rpi:ssh

	...
	
	Connecting with ssh [RPI_USER]@[RPI_IP]

	[RPI_USER]@[RPI_IP]'s password:
	
	pi@raspberrypi ~ $ cd hello
	pi@raspberrypi ~/hello $ ls
	[binary_name]
	pi@raspberrypi ~/hello $ ./[binary_name]
	Hello world!
	
If you want to send files to another Raspberry Pi that appears in your **settings.bii**, you have the option of passing these parameters to the ``bii:ssh``.

.. code-block:: bash

	$ bii rpi:ssh [user] [ip]
	

Publish your code
^^^^^^^^^^^^^^^^^

Once your have written, compiled and successfully sended some code, surely you are willing to share it with the biicode community! Uploading your code to biicode is really simple using the ``bii publish`` command. You will be requested to provide a **tag** and a **message**. Valid tags are ``STABLE``, ``ALPHA``, ``BETA``, and ``DEV``. They provide information about the development state of your hive. The message is any information describing your publication.

.. code-block:: bash

	$ bii publish
	block:   your_user_name/my_block
	Introduce tag: STABLE
	Introduce msg: My first project with biicode
	  Reading Hive...
	  Checking block your_user_name/your_user_name/my_block/master
		  ... your block is being published here

	Successfully published your_user_name/my_block(your_user_name/master): 0

If your code has been published correctly —as it is the case in the previous example—, you can navigate it here: ``www.biicode.com/user_name``

Here is an example of sbaker's user:

.. image:: ../_static/img/sbaker1.png

And this is his block's view:

.. image:: ../_static/img/sbaker2.png


Reuse it!
^^^^^^^^^

One of the most interesting aspects of biicode is the ability it provides to easily reuse code. As the published files have already been uploaded to biicode servers, it is possible for anyone —even other biicode users— to use these files in new projects. We'll show the process creating a new hive named **"hellopretty"**. From your biicode workspace folder, execute again the ``bii new`` command to create a new hive:

.. code-block:: bash

	$ cd /path/to/your/biicode_workspace
	$ bii new hellopretty
	Created new Hive hellopretty
        ...
	Introduce lang (default:cpp):
	INFO: Selected lang: cpp
	How would you like to name your first block?
	Introduce block name (default:my_block): my_pretty_block
	INFO: block name: my_pretty_block
	Generate a default hello world?  (YES/no) no
	Select IDE family: (Visual/CodeBlocks/Eclipse/NetBeans/None)
	Introduce ide (default:Eclipse): None
        ...
	$ cd hellopretty

Add the following files to the folder ``hellopretty/blocks/your_user_name/my_pretty_block/`` (remember to substitute ``your_user_name`` with your actual biicode user name):

**hellopretty.h**

.. literalinclude:: ../_static/code/cpp/hello-world/hellopretty.h
   :language: cpp
   :linenos:

**hellopretty.cpp**

.. literalinclude:: ../_static/code/cpp/hello-world/hellopretty.cpp
   :language: cpp
   :linenos:

**mainpretty.cpp**

.. literalinclude:: ../_static/code/cpp/hello-world/mainpretty.cpp
   :language: cpp
   :linenos:

Download all the files: :download:`mainpretty.cpp <../_static/code/cpp/hello-world/mainpretty.cpp>` :download:`hellopretty.cpp <../_static/code/cpp/hello-world/hellopretty.cpp>` :download:`hellopretty.h <../_static/code/cpp/hello-world/hellopretty.h>`


In this case we are using of the ``hello()`` function, which is not explicitly defined in the current hive. If you tried to compile and run this program using the ``bii cpp:run`` command, you would see an error message:

.. code-block:: bash

	Detected 3 files created, 0 updated
	Processing hive
	  Cell your_user_name/my_pretty_block/hellopretty.h is implemented by set(['your_user_name/my_pretty_block/hellopretty.cpp'])
		...
	#include "your_user_name/my_block/hello.h" //reusing hello.h header
	         ^
	1 error generated.
		...
	[!] Make failed

However, biicode knows that you are trying to reuse the ``hello.h`` header. To resolve the missing dependencies we use the ``bii find`` command. Hopefully the server will find the dependencies, and you will see a success message on your screen:

.. code-block:: bash

	$ bii find
	Finding missing dependencies in server
		...
	Dependencies resolved in server:
	Find resolved new dependencies:
		your_user_name/my_block(your_user_name/master): 0
	
This is a successful ouput that indicates biicode has been able to resolve your dependencies. All needed files have been automatically downloaded and copied to your hive.

Now you can try to compile and send again your new code. In this case the process will succeed:

.. code-block:: bash

	$ bii rpi:send

	...
	
	Sending with rsync -Pravdtze ssh [HIVE_DIRECTORY]/bin/* [RPI_USER]@[RPI_IP]:[DIRECTORY]/[HIVE_NAME]
	
	$ bii rpi:ssh

	...
	
	Connecting with ssh [RPI_USER]@[RPI_IP]

	[RPI_USER]@[RPI_IP]'s password:
	
	pi@raspberrypi ~ $ cd hellopretty
	pi@raspberrypi ~/hellopretty $ ls
	[binary_name]
	pi@raspberrypi ~/hellopretty $ ./[binary_name]
	
		...
	
	**********************************
	Hello World!
	**********************************

You will find the ``your_user_name/my_block`` block along with the retrieved source files ``hello.h`` and ``hello.cpp`` in your  ``hellopretty/deps`` subfolder. Note that the ``main.cpp`` file of the **hello** block was not retrieved. That is because you don't need it to reuse the ``hello()`` function!

Publish a new version of your hello block
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modifying your code and publishing the results is easy with biicode. Now we'll change the message displayed by the ``hello()`` function in the **hello** block. Update the ``hello.cpp`` as following:

**hello.cpp**

.. literalinclude:: ../_static/code/cpp/hello-world/hellobiicode.cpp
   :language: cpp
   :linenos:
   
Download the file: :download:`hello.cpp <../_static/code/cpp/hello-world/hellobiicode.cpp>`

Execute your block, to make sure everything works as expected:

.. code-block:: bash

	$ cd /path/to/your/biicode_workspace/hello
	$ bii cpp:build
		...
	$ bii rpi:send
		...
	$ bii rpi:ssh
		...
		
	pi@raspberrypi ~/hello $ ./[binary_name]
	
	Hello biicode!

Now, post your block to the biicode server just like you did before:

.. code-block:: bash

	$ bii publish
	block:     your_user_name/my_block
	Introduce tag: STABLE
	Introduce msg: My first block update
		...
	Successfully published your_user_name/my_block(your_user_name/master): 1

As you can see, the version of your block changed from 0 to 1. Your can see both versions published online visiting your biicode user main page, as before.

Update your hellopretty block with the new version of hello
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To update your **hellopretty** block you only need to search the server for any published new versions of your dependencies using the ``bii find`` command with the ``--update`` modifier. If the server finds new published versions for any of your dependencies, you'll see an indicative message on your screen:

.. code-block:: bash

	$ cd /path/to/your/biicode_workspace/hellopretty
	$ bii find --update
	Finding missing dependencies in server
		...
	Updated dependencies:
		your_user_name/your_user_name/my_block/master:#1
		...
	Saving dependences on disk


Finally, you can input the ``bii cpp:run`` command to see how your block has been updated, showing on screen the new message.

.. code-block:: bash

	$ bii cpp:build
		...
	$ bii rpi:send
		...
	$ bii rpi:ssh
		...
		
	pi@raspberrypi ~/hellopretty $ ./[binary_name]
	**********************************
	Hello biicode!
	**********************************
