.. _adapt_library:

Adapt your library
------------------

 Transform your **library** in a fully functional **block** can be almost immediately or require some work. The more bigger or heavy configured libraries, the higher time require to adapt it.

 We assume you read the section :ref:`Custom build configuration<_cmakelists_txt>` and you have understand how biicode builds your code.

Concepts you must understand
============================

* Put your library source code in a biicode block.
* Biicode **analyzes** your code and builds a **dependency graph** with how each file are connected to each others. These files are appended to ``BII_LIB_SRC`` variable in your *CMakeLists.txt* file 
* When some user **#includes** a header (ex: file.h) from a remote block, biicode will download only the files that depends on "file.h" (recursively) and will build a **library** with only needed files. The library built for the dependency will be linked to your targets automatically.
* So dependency graph must be built correctly in order to reuse a library.
* To be sure that a library is uploaded correctly is recommended to publish it with DEV tag and reuse it from other project making an example. The example can be a main including a header from your own library. You can check a lot of examples of reuse in |examples_user|.

**Key facts** 
_____________

.. container:: infonote numeric one

	Given that a library must be built only with few files of the whole library, you can't assume in your *CMakeLists.txt* file that all files are present. 
		
		> **Example**: You should not execute TARGET_LINK_LIBRARIES upon an exe target without check if it exist first.

		> **Example**: You should not add "my_file.cpp" to your library explicitly, because you don't know if biicode has downloaded this file.

.. container:: infonote numeric two

	You need a *CMakeLists.txt* that builds a library called **${BII_LIB_TARGET}** as a "plug". You also could change ``BII_LIB_TARGET`` variable value to the name of your cmake library. Its only needed that **${BII_LIB_TARGET}** exists and was a library.

.. _without-previous-cmakelists-txt:

Without previous CMakeLists.txt
===============================

If your current library doesn't have a *CMakeLists.txt* biicode will create it when you execute **bii configure** or **bii build**.

1. Execute **bii deps** and check ``unresolved`` dependencies. 
______________________________________________________________


 * If you see there **some of your header** files (\*.h) biicode are not detecting them right.  check :ref:`[paths]<paths_conf>` section in *biicode.conf*. Maybe you have non-relative #includes and need to add the folder with the headers to let biicode find them.
 
 * If you see there are references to **external** **headers** you have to check that the required library is in biicode. You can use the search engine in https://www.biicode.com and search for a file typing ``file:my_include.h``

 	* If you find the library in a block, just fill your :ref:`[requirements]<requirements_conf>` section of *biicode.conf* with it and ensure again with **bii deps** command that the #includes are resolved. If don't check :ref:`[includes]<includes_conf>` section in *biicode.conf*.
 	* If you don't find it you can try to upload it to biicode first ;)
 
 * If you don't have unresolved dependencies or it seems to be system dependencies, try to compile it (point 2).

2. Execute **bii build**
________________________

  * If there are compile errors

  	* Check if some compile definition is needed. You can use *TARGET_COMPILE_DEFINITIONS(${BII_BLOCK_TARGET} PUBLIC "MY_DEFINITION=1")* in your CMakeLists after *ADD_BIICODE_TARGETS()*.

  	* Review the **BII_LIB_SRC** variable in CMakeLists.txt (and **BII_exe_name_SRC**) and look for missing files. If you detect a file is missing, add it to :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf*.
  
  * If there are linker errors, search in code the missing symbols.

  	*  If you find them in you source code maybe biicode is not finding some implementation and dependency graph is not build correctly. Use :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf* to specify missing source file.

  	*  If you don't find them you can try to google. Maybe you need to link a system library. You can use *TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC pthread)* in your *CMakeLists.txt* after *ADD_BIICODE_TARGETS()*.

3. Test the library reuse
__________________________
 
Well, at this point biicode knows how to build your code. But you are not done yet. You should check that your library can be included and works fine.

	* ``bii publish`` to publish a DEV version of your code. 
	* Open a new terminal and create a new biicode project with an example that includes your library. You can check a lot of examples of reuse in |examples_user|.  So create a new folder and execute **bii init -l** and **bii new --hello cpp**.
	* Execute **bii configure** to create *biicode.conf* and *CMakeLists.txt* files.
	* Require your original block library in :ref:`[requirements]<requirements_conf>` section of *biicode.conf*
	* Execute **bii deps** to ensure your requirement is wired right.
	* Execute **bii build** to build the example
		
		* If compilation fails because a missing file/s you can check the ``deps/`` folder to check the files that biicode has downloaded. If some file are missing you probably need to add some file in :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf*. Fix the library and publish again. Then execute **bii build** in your example folder again, it will be download the updated library automatically. Check again the downloaded files.

		* If compilation fails because an error in the *CMakeLists.txt* of your library check that you are not supposing that (*key fact 1*) all files are present. Fix *CMakeLists.txt* or wire a dependency if needed in :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf*.

	* You can build more examples including (if exists) more headers from your library for ensure it works well.
	* Congrats! You have a fully functionally library in biicode! Execute ``bii publish --tag STABLE`` for freeze an stable version.


With previous CMakeLists.txt
============================

**Option 1**: Let biicode do their job in an isolated file
__________________________________________________________

  If you already have a *CMakeLists.txt* file there's no need to replace it, just adapt it like this:

  .. code-block:: cmake

	   IF(BIICODE)  
	      INCLUDE("biicode.cmake")
	      RETURN()
	   ENDIF()
	   # Your regular project configuration here

  Now create a file named *biicode.cmake* an add the line **ADD_BIICODE_TARGETS()**.
  Proceed reading :ref:`Without previous CMakeLists.txt<without-previous-cmakelists-txt>` section assuming *biicode.cmake* is now the file where you will write the needed code.


**Option 2**: Build your own target library and link them to *BII_LIB_TARGET*
______________________________________________________________________________

  	Sometimes, with big and complex libraries that already have their CMakeLists.txt and builds his own library, the best approach is to link the result library to **${BII_LIB_TARGET}**

  	* Given that you want to use your own library targets and you are assuming that all files are always present, you are violating *key fact nº1*. The only way to proceed is wire all your library files together in :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf*.

		**EXAMPLE**: Here is the ``[dependencies]`` section of |curl_block|

		.. code-block:: cmake
		
		    [dependencies]
		    # Nothing depend on tests, so do not include tests if not needed
		    src/* - tests/*
		    lib/* - tests/*
		    include/* - tests/*

		    # Lib doesn't depend on src
		    lib/* - src/*

		    # Everything depends on libcurl
		    src/* + lib/* docs/MANUAL docs/curl.1 src/mkhelp.pl
		    include/* + lib/*
		    tests/*.h + src/* lib/* include/* tests/*

		    # Src module goes together
		    src/*.h + src/*.c

 	.. _link_to_bii_lib_target:

	* You have to enable a plug for biicode (*key fact nº2*) At the end of your *CMakeLists.txt* (or before installation steps), assuming ``${LIB_NAME}`` is the name of the library that you have built:

		.. code-block:: cmake

			IF(BIICODE)
			  # Clear biicode auto detected files. 
			  # BII_LIB_TARGET will be an interface target.
			  SET(BII_LIB_SRC) 
			  
			  ADD_BIICODE_TARGETS()
			  
			  # If you have configured some file, include the output directory
			  # TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} INTERFACE ${CMAKE_CURRENT_BINARY_DIR}) 
			  
			  # Apply biicode dependencies to my library
			  TARGET_LINK_LIBRARIES(${LIB_NAME} PUBLIC ${BII_LIB_DEPS}) 
			  # Also the interface properties
			  TARGET_LINK_LIBRARIES(${LIB_NAME} PUBLIC ${BII_BLOCK_TARGET})
			  # Wire your lib to ${BII_LIB_TARGET} so biicode can use it
			  TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} INTERFACE ${LIB_NAME})

			ENDIF()


	* You can't assume that targets are always present *(key fact nº1)*:

		**EXAMPLE**: *tests* folder is not present (because tests not depend on any header of your library), so its not downloaded

		.. code-block:: cmake
		
			IF(BIICODE AND (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests"))
			   # Your code for generate examples targets
			ENDIF()

	* If you CMakeLists.txt has ``find_package`` calls and you want to replace these dependencies and depends on biicode blocks:

		* Let biicode handle requirements

			**EXAMPLE**: This library links OpenSSL library of the system. But we want to link openssl from biicode:

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

  		* Require your original block library in :ref:`[requirements]<requirements_conf>` section of *biicode.conf*
		* Execute **bii deps** to ensure your requirement is wired right.


You can check a complete example of **Option 2** here with |curl_block| and |lib_curl_cmakelists|.
This **Option 2** is not ideal because is downloading, compiling and linking the whole library and some files may be unnecessary. But if your library files is heavily connected and/or there are so much files this is your best option.

**Option 3**: Adapt your CMakeLists.txt filtering files
_______________________________________________________

There is a third option, a mix of two previous option:
	
	* Do not force to interconnect all source code, just filter the files with the set of files detected by biicode (BII_LIB_SRC).

		*key fact 1* said us that we can't assume that all files are present in out CMakeLists.txt, but we know which files has been downloaded looking the ``BII_LIB_SRC`` variable, so you can always compose your library with the intersection of your list of sources and ``BII_LIB_SRC``

		**EXAMPLE**:

		.. code-block:: cmake

			
			MACRO(INTERSECTION var_name list1 list2)
			  # Store the intersection between the two given lists in var_name.
			  SET(intersect_tmp "")
			  FOREACH(l ${list1})
			    IF("${list2}" MATCHES "(^|;)${l}(;|$)")
			      SET(intersect_tmp ${intersect_tmp} ${l})
			    ENDIF("${list2}" MATCHES "(^|;)${l}(;|$)")
			  ENDFOREACH(l)
			  SET(${var_name} ${intersect_tmp})
			ENDMACRO(INTERSECTION)

			# Biicode detects that file2.cpp is not a dependency of the block that includes this one.
			# So in BII_LIB_SRC there are only file1.cpp and file3.cpp
			# If we try to add_library using file2.cpp will fail, so lets filter it.

			set(my_library_files file1.cpp file2.cpp file3.cpp)
			IF(BIICODE)
			  INTERSECTION(filtered_files "${my_library_files}" "${BII_LIB_SRC}")
			ELSE()
			  set(filtered_files ${my_library_files})
			END()
			add_library(my_library ${filtered_files})


		.. container:: infonote

			You can include |macro_intersection| from *biicode/cmake* block and reuse the macro ``INTERSECTION``. Check :ref:`[Publish, share and reuse CMake scripts]<reuse_cmake>` section for more information.

	* Keep the way you build the library

		Following *key fact 2*, you can build your library and :ref:`link to ${BII_LIB_TARGET}<link_to_bii_lib_target>`, or even change the value of ``BII_LIB_TARGET`` variable to match your library name. The only important is that the variable ``BII_LIB_TARGET`` contains a cmake library.

		.. code-block:: cmake

			SET(BII_LIB_TARGET my_library)


.. |macro_intersection| raw:: html
    
    <a href="https://www.biicode.com/biicode/biicode/cmake/master/4/tools.cmake" target="_blank">tools.cmake</a>

.. |examples_user| raw:: html
    
    <a href="https://www.biicode.com/examples" target="_blank">examples user</a>

.. |curl_block| raw:: html
	
	<a href="https://www.biicode.com/lasote/curl" target="_blank">curl block</a>

.. |lib_curl_cmakelists| raw:: html
	
	<a href="https://www.biicode.com/lasote/lasote/curl/master/2/lib/CMakeLists.txt" target="_blank">libcurl CMakeLists.txt</a>