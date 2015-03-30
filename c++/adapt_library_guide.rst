.. _adapt_library:

Adapt your library
======================

.. _adapt_library_cmakelists:

Transforming your **library** in a full functional biicode **block** can be straightforward or require some work. The bigger or "heavier" a library is, the higher time it takes to adapt it.

We assume you've read :ref:`Custom build configuration<cmakelists_txt>` section and have understood how biicode builds your code.

Concepts to understand
----------------------

* Place your library's source code in a biicode block.
* Biicode **analyzes** your code and builds a **dependency graph** with how each file connects to the others. These files are appended to ``BII_LIB_SRC`` variable in your *CMakeLists.txt* file.
* When you *#include* a header (ex: file.h) from a remote block, biicode only downloads the files that depend on "file.h" (recursively) and builds a **library** with the files needed. The dependency library built is linked to your targets automatically.
* When you're the one uploading a "reusable" library, it's really important that the dependency graph for that lib is built correctly.
* A quick way to be sure that your library is fully reusable, is publishing with DEV tag and then depend on it from another project making an example. The example can be a main including a header from your own library. You can check a lot of examples reusing libsS in |examples_user|.

**Key facts**
^^^^^^^^^^^^^

.. container:: infonote numeric one

	As biicode may build the libraries with just a few files from the whole library (biicode only downloads and builds the needed files), you shouldn't assume in your *CMakeLists.txt* that all your library files will be present. 
		
		> **Example**: Make sure an *exe target* exists before executing ``TARGET_LINK_LIBRARIES`` upon it. 

		> **Example**: Adding *my_file.cpp* to your library explicitly isn't recommended as you don't know if biicode has downloaded this file.

.. container:: infonote numeric two

	Biicode needs a library in ``BII_LIB_TARGET`` variable to make it reusable, as a "plug". 

	It builds ``${BII_LIB_TARGET}`` for each block with the source code files in ``BII_LIB_SRC`` variable (list).

.. _without-previous-cmakelists-txt:

Without a previous CMakeLists.txt
---------------------------------

If your current library doesn't have a *CMakeLists.txt* biicode creates it when you execute **bii configure** or **bii build**.

1. Look for ``unresolved`` dependencies with **bii deps**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

 * If **some of your header** files (\*.h) are *unresolved*, biicode has not been able to detect them. You can solve this by filling :ref:`[paths]<paths_conf>` section in *biicode.conf* with the folders containing the headers to let biicode find them.  
	
	You only need to specify your paths when your project has non-file-relative ``#include (s)``.

	For example:

	.. code-block:: text

	      [paths]
	          # Local directories to look for headers in your block
	          include
	          /

	.. container:: infonote

 
 * If there are references to **external headers**, look for the library you need in biicode. You can use the search engine in https://www.biicode.com and search for the file typing ``file:my_include.h``

 	* Found the library in biicode? Just fill your :ref:`[requirements]<requirements_conf>` section of *biicode.conf* as shown in :ref:`dependencies<cpp_dependencies>` section. Re-run **bii deps** command to ensure the #includes are resolved.
 	* Didn't find the library in biicode? You could be the first one adding it ;)
 
 * If there are no unresolved dependencies or it seems your unresolved dependencies are **system dependencies**, try to compile it (point 2).

2. Execute **bii build**
^^^^^^^^^^^^^^^^^^^^^^^^

  * There are **compilation errors**:

  	* Check if some compile definition is needed. You can use *TARGET_COMPILE_DEFINITIONS(${BII_BLOCK_TARGET} PUBLIC "MY_DEFINITION=1")* in your CMakeLists after ``ADD_BIICODE_TARGETS()``.

  	* Review the ``BII_LIB_SRC`` variable in CMakeLists.txt (and ``BII_exe_name_SRC``) and look for missing files. 

  	If you detect a file is missing, add it to :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf*.
  
  * If you receive **linker errors**, search in the code the missing symbols.

  	*  If they are in you source code, maybe biicode is not finding some implementation and the dependency graph wasn't built correctly. You can use :ref:`[bii deps --files]<bii_deps_command>` to inspect how the code is connected. Use :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf* to specify the missing source file.

  	*  Can't find them in your sources? Try to google them. You may need to link a system library. You can use ``TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC pthread)`` in your *CMakeLists.txt* after ``ADD_BIICODE_TARGETS()``.

3. Test the libary's reusability
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

At this point biicode knows how to build your code. But you are not done yet. You should check that your library can be included and works fine.

	* ``bii publish`` to publish a DEV version of your code. 
	* Open a new terminal and create a new biicode project with an example including your library. You can check a lot of reuse examples in |examples_user|.  Create a new folder and execute **bii init -l** and **bii new --hello cpp**. Replace *main.cpp* code with your example code.  
	* Run **bii configure** to create *biicode.conf* and *CMakeLists.txt* files.
	* Require your original block library in :ref:`[requirements]<requirements_conf>` section of *biicode.conf*
	* Execute **bii deps** to ensure your requirement is wired right.
	* Execute **bii build** to build the example
		
		* If compilation fails because any files are missing, check ``bii/deps/`` folder to review the files biicode downloaded. If you notice some file are missing you probably need to add them in :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf*. Fix the library and **bii publish** again. Then execute **bii build** in your example folder again, this downloads the updated library automatically. Check again the files downloaded.

		* If compilation fails in cause of an error in your library's *CMakeLists.txt* check that you are not presuming that (*key fact 1*) all files are present. Fix *CMakeLists.txt* or wire a dependency (if needed) in :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf*.

	* You can build more examples including more headers from your library to ensure it works well.

	* Congrats! You have a full functional library in biicode! Execute ``bii publish --tag STABLE`` to freeze an stable version.

**Got any doubts?** Ask in |biicode_forum_link| or |biicode_write_us|.

With a previous CMakeLists.txt
------------------------------

**Option 1**: Let biicode do its job in an isolated file
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you already have a *CMakeLists.txt* file there's no need to replace it, just adapt it like this:

.. code-block:: cmake

   IF(BIICODE)  
      INCLUDE("biicode.cmake")
      RETURN()
   ENDIF()
   # Your regular project configuration here

Now create a file named *biicode.cmake* an add the line **ADD_BIICODE_TARGETS()**.
Then read :ref:`without a previous CMakeLists.txt<without-previous-cmakelists-txt>` section knowing that *biicode.cmake* is now the file where you will write the code needed.


**Option 2**: Build your own target library and link them to *BII_LIB_TARGET*
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sometimes, when adapting big and complex libraries that already have a CMakeLists.txt building its onw library, the best approach is to link the resulting library to ``${BII_LIB_TARGET}``

* As you want to use your own library targets and these take for granted that all files are always present, it's violating *key fact nº1*. The way to proceed is wiring all your library files together in :ref:`[dependencies]<dependencies_conf>` section in *biicode.conf*.

	**EXAMPLE**: ``[dependencies]`` section from |curl_block|. 

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

* Enable a plug for biicode (*key fact nº2*) at the end of your *CMakeLists.txt* (or before installation steps), assuming ``${LIB_NAME}`` is the name of the library you've built:

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

* Don't presume that targets are always present *(key fact nº1)*:

	**EXAMPLE**: *tests* folder is not present (because tests not depend on any header of your library), so its not downloaded.

	.. code-block:: cmake
	
		IF(BIICODE AND (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests"))
		   # Your code for generate examples targets
		ENDIF()

* If your *CMakeLists.txt* uses ``find_package`` directive and you want to replace these dependencies and depend on biicode blocks:

	* Let biicode handle requirements:

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

		* Require your original block library in :ref:`[requirements]<requirements_conf>` section in *biicode.conf*

		* Execute **bii deps** to ensure your requirement is wired right.

There's a complete example of **Option 2** you can check here at |curl_block| and |lib_curl_cmakelists|.

**Option 2** is not "ideal" because is downloading, compiling and linking the whole library and some files may be unnecessary. But if your library files are heavily connected and/or there are so many files this is your best option.

**Option 3**: Adapt your CMakeLists.txt filtering files
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There is a third option, a mix of the two previous options:
	
	* Filter the files with the set of files detected by biicode ``${BII_LIB_SRC}``, not forcing  all source code to interconnect.

		*key fact 1* said not to presume all files exist in our CMakeLists.txt, but we know which files has downloaded looking the ``BII_LIB_SRC`` variable, so you can always compose your library with the intersection of your list of sources and ``BII_LIB_SRC``

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

	* Keep the way you build the library:

		Following *key fact 2*, you can build your library and :ref:`link to ${BII_LIB_TARGET}<link_to_bii_lib_target>`, or even change the value of ``BII_LIB_TARGET`` variable to match your library name. The only thing important is that the variable ``BII_LIB_TARGET`` contains a cmake library.

		.. code-block:: cmake

			SET(BII_LIB_TARGET my_library)

As you know we're available at |biicode_forum_link| for questions and answers. You can also |biicode_write_us|.


.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">our forum </a>


.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>


.. |macro_intersection| raw:: html
    
    <a href="https://www.biicode.com/biicode/biicode/cmake/master/4/tools.cmake" target="_blank">tools.cmake</a>

.. |examples_user| raw:: html
    
    <a href="https://www.biicode.com/examples" target="_blank">examples user</a>

.. |curl_block| raw:: html
	
	<a href="https://www.biicode.com/lasote/curl" target="_blank">curl block</a>

.. |lib_curl_cmakelists| raw:: html
	
	<a href="https://www.biicode.com/lasote/lasote/curl/master/2/lib/CMakeLists.txt" target="_blank">libcurl CMakeLists.txt</a>
