.. _c++_troubleshooting:

Troubleshooting
===============

In this section you will find information and helpful resources, in case you encounter any problem while using our service. Don't panic, and try to find a solution for your problem bellow. If you can't find a solution, please `contact us at our forum <http://forum.biicode.com>`__ and describe your problem.


.. _eclipse_osx_binaries:

Eclipse projects: "Launch failed. Binary not found" (OS X)
----------------------------------------------------------

If you are using **OS X** as development platform, you will need some aditional setup for executing your biicode projects within Eclipse IDE. It could happen that after building your project, you cannot execute the binaries from the IDE toolbar, getting the following error:

.. image:: /_static/img/c++/binary_not_found.png

If you are getting this error, please proceed as follows:

#. Right-click on your project and select *Properties*.
#. Select *C/C++ Make project* and click on the *Binary Parser* subsection tab.
#. Unselect Mach-O Parser (deprecated).
#. Select Mach-O 64 Parser.
#. Click *OK*.

You can :ref:`read more in this section about configuring an IDE with your C/C++ projects <generators_ide>`.


g++ doesn't compile simple code, using thread header
------------------------------------------------------

If you have a block that **links to pthread library** and you're using **Ubuntu 13.10 or 14.04**, you'll find this bug in g++ compiler:

.. code-block:: bash

	$ ./executable_file
	terminate called after throwing an instance of 'std::system_error'

**Create a CMakelists.txt inside your block that fails** and copy the following content:

**CMakeLists.txt**

.. code-block:: cmake

	#############BIICODE MACROS###################
	include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)

	ADD_BIICODE_TARGETS()
	#############################################

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed")


Default Build Configuration with bii cpp:build not working
----------------------------------------------------------

Sometimes the default configuration when installing biicode does not detect the compiler you are using, ``bii cpp:build`` does not work and it is necessary to configure your compiler with biicode.

.. container:: infonote
 
 **Windows Users**

 This can be a problem due to your path configuration. Please, check it out and :ref:`ensure everything is right <cpp_desktop_win>` to use the build configuration by default.

Type inside your project directory:

.. code-block:: bash
 
 $ bii cpp:configure -G "CMake generator name"

If you want to check the generators available in your platform:

.. code-block:: bash

 $ cmake --help

To configure your project as default just type:

* **Windows:**

	.. code-block:: bash

	 $ bii cpp:configure -G "MinGW Makefiles"
    
* **Linux & MacOS:**

    .. code-block:: bash

     $ bii cpp:configure -G "Unix Makefiles"

**Note:** You can also type ``bii clean`` to :ref:`restore default configuration<biiclean>`.

Now doing ``bii cpp:build`` should work properly.

Check for more information about **generators** :ref:`here <generators_ide>`.

.. container:: todo

    Check our `forum <http://forum.biicode.com>`__ and `Stackoverflow tag <http://stackoverflow.com/questions/tagged/biicode?sort=newest>`__ for questions and answers.
