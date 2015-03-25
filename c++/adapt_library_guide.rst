.. _adapt_library:

Adapt your library
------------------------

 Transform your **library** in a fully functional **block** can be almost immediately or require some work. The more bigger or heavy configured libraries, the higher time require to adapt it.

 We assume you read the section :ref:`Custom build configuration<_cmakelists_txt>` and you have understand how biicode builds your code.

**Key concepts** to keep in mind
=================================

1. Put your library source code in a biicode block.
2. Biicode **analyzes** your code and builds a **dependency graph** with how each file are connected to each others.
3. When some user **#includes** a header (ex: file.h) from a remote block, biicode will download only the files that depends on "file.h" (recursively) and will build a **library** with only needed files. The library built for the dependency will be linked to your targets automatically.
4. So dependency graph must be built correctly in order to reuse a library.
5. Given that a library must be built only with few files of the whole library, you can't assume in your ``CMakeLists.txt`` file that all files are present. Example: You should not execute TARGET_LINK_LIBRARIES upon an exe target without check if it exist first.
6. To be sure that a library is uploaded correctly is recommended to publish it with DEV tag and reuse it from other project making an example. The example can be a main including a header from your own library. You can check a lot of examples of reuse in |examples_user|. https://www.biicode.com/examples
7. The previous points can be condensed in one: You need a CMakeLists.txt that build **${BII_LIB_TARGET}** in order to let biicode have an  "interface" through build and link libraries.

.. _without-previous-cmakelists-txt:

Without previous CMakeLists.txt
===============================

If your current library don't have a **CMakeLists.txt** file biicode will create one when you execute ``bii configure`` or ``bii build``.

1. Execute ``bii deps`` and check ``unresolved`` dependencies. 

 * If you see there some that biicode are not detecting **some of your header** files (\*.h) check :ref:`[paths]<paths_conf>` section in ``biicode.conf``. Maybe you have non-relative #includes and need to add the folder with the headers to let biicode find them.
 
 * If you see there are references to **external** **headers** you have to check that the required library is in biicode. You can use the search engine in https://www.biicode.com and search for a file typing ``file:my_include.h``

 	* If you find the library in a block, just fill your :ref:`[requirements]<requirements_conf>` section of ``biicode.conf`` with it and ensure again with ``bii deps`` command that the #includes are resolved. If don't check :ref:`[includes]<includes_conf>` section in ``biicode.conf``.
 	* If you don't find it you can try to upload it to biicode first ;)
 
 * If you don't have unresolved dependencies or it seems to be system dependencies, try to compile it (point 2).

2. Execute ``bii build``

  * If there are compile errors

  	* Check if some compile definition is needed. You can use *TARGET_COMPILE_DEFINITIONS(${BII_BLOCK_TARGET} PUBLIC "MY_DEFINITION=1")* in your CMakeLists after *ADD_BIICODE_TARGETS()*.
  	* Review the **BII_LIB_SRC** variable in CMakeLists.txt (and **BII_exe_name_SRC**) and look for missing files. If you detect a file is missing, add it to ref:`[dependencies]<dependencies_conf>` section in ``biicode.conf``.
  
  * If there are linker errors, search in code the missing symbols.

  	*  If you find them in you source code maybe biicode is not finding some implementation and dependency graph is not build correctly. Use :ref:`[dependencies]<dependencies_conf>` section in ``biicode.conf`` to specify missing source file.

  	*  If you don't find them you can try to google. Maybe you need to link a system library. You can use *TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC pthread)* in your ``CMakeLists.txt`` after *ADD_BIICODE_TARGETS()*.

3. Test the library reuse.
 
Well, biicode now knows how to build your code. But you are not done yet. You should check that your library can be included and works fine.

	* ``bii publish`` to publish a DEV version of your code. 
	* Open a new terminal and create a new biicode project with an example that includes your library. You can check a lot of examples of reuse in |examples_user|. https://www.biicode.com/examples. So create a new folder and execute ``bii init -l`` and ``bii new --hello cpp``.
	* Execute ``bii configure`` to create ``biicode.conf`` and ``CMakeFiles.txt`` files.
	* Require your original block library in :ref:`[requirements]<requirements_conf>` section of ``biicode.conf``
	* Execute ``bii deps`` to ensure your requirement is wired right.
	* Execute ``bii build`` to build the example
		
		* If compilation fails because a missing file/s you can check the ``deps/`` folder to check the files that biicode has downloaded. If some file are missing you probably need to add some file in :ref:`[dependencies]<dependencies_conf>` section in ``biicode.conf``. Fix the library and publish again. Then execute ``bii build`` in your example folder again, it will be download the updated library automatically. Check again the downloaded files.

		* If compilation fails because an error in the **CMakeLists.txt** of your library check **key concepts number 5**.

	* You can build more examples including (if exists) more headers from your library for ensure it works well.
	* Congrats! You have a fully functionally library in biicode! Execute ``bii publish --tag STABLE`` for freeze an stable version.


With previous CMakeLists.txt
============================

1. Let biicode do their job in an isolated file:

  If you already have a ``CMakeLists.txt`` file there's no need to replace it, just adapt it like this:

  .. code-block:: cmake

	   IF(BIICODE)  
	      INCLUDE("biicode.cmake")
	      RETURN()
	   ENDIF()
	   # Your regular project configuration here

  Now create a file named ``biicode.cmake`` an add the line **ADD_BIICODE_TARGETS()**.
  Proceed reading :ref:`Without previous CMakeLists.txt<without-previous-cmakelists-txt>` section assuming ``biicode.cmake`` is now the file where you will write the needed code.

2. Adapt 



3. Build your own target library and link them to **${BII_LIB_TARGET}**

  Sometimes, with big and complex libraries that already have their CMakeLists.txt and builds his own library, the best approach is to link the result library to **${BII_LIB_TARGET}**

	* At the end of your **CMakeLists.txt** (or before installation steps), assuming ``${LIB_NAME}`` is the name of the library that you have built:

		.. code-block:: cmake

			IF(BIICODE)
			  SET(BII_LIB_SRC) # Clear biicode auto detected files. BII_LIB_TARGET will be an interface target.
			  
			  ADD_BIICODE_TARGETS()
			  
			  # If you have configured some file
			  # TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} INTERFACE ${CMAKE_CURRENT_BINARY_DIR}) 
			  
			  # Apply biicode dependencies to my library
			  TARGET_LINK_LIBRARIES(${LIB_NAME} PUBLIC ${BII_LIB_DEPS}) 
			  # Also the interface properties
			  TARGET_LINK_LIBRARIES(${LIB_NAME} PUBLIC ${BII_BLOCK_TARGET})
			  # Wire your lib to ${BII_LIB_TARGET} so biicode can use it
			  TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} INTERFACE ${LIB_NAME})

			ENDIF()


	* If you CMakeLists.txt has ``find_package`` calls and you want to replace this dependencies with the uploaded to biicode:

		* Let biicode handle requirements

			*EXAMPLE*: This library links OpenSSL library of the system. But we want to link openssl from biicode:

			.. code-block:: cmake

				if(NOT BIICODE) # Biicode uses OpenSSL as a dep, do not find it in system
				  find_package(OpenSSL)
				  if(OPENSSL_FOUND)
					set(USE_OPENSSL ON)
					# ...
					# ...
				  endif()
				else()
				  set(USE_OPENSSL ON)
				endif()

  		* Require your original block library in :ref:`[requirements]<requirements_conf>` section of ``biicode.conf``
		* Execute ``bii deps`` to ensure your requirement is wired right.


	* If you are assuming that targets always are present, tests for example:

		.. code-block:: cmake
		
			IF(BIICODE AND (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests"))
			   # Your code for generate examples targets
			ENDIF()


Example here: https://www.biicode.com/lasote/lasote/curl/master/2/lib/CMakeLists.txt


.. |examples_user| raw:: html
    
    <a href="https://www.biicode.com/examples" target="_blank">examples user</a>

