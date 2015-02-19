.. _boost_examples:

Boost Libraries
===============

The examples below demonstrate how to use biicode to set up Boost-based projects.

First let's configure the examples project:

.. code-block:: bash

    $ bii init boost-examples
    $ cd boost-examples

We will be using that project across all the examples.

Boost.Lambda
------------

This is an example about the Boost.Lambda library, extracted from the `Boost getting started <http://www.boost.org/doc/libs/1_57_0/more/getting_started/windows.html>`_ header-only section.

First create a block for the example:

.. code-block:: bash

    $ bii new your-account/boost-lambda

Create a source file:

``blocks/your-account/boost-lambda/example.cpp``:

.. code-block:: cpp

    #include <boost/lambda/lambda.hpp>
    #include <iostream>
    #include <iterator>
    #include <algorithm>

    int main()
    {
        using namespace boost::lambda;
        typedef std::istream_iterator<int> in;

        std::for_each(
            in(std::cin), in(), std::cout << (_1 * 3) << " " );
    }

biicode sets up a Boost installation inside the biicode environment. This allows to support and switch between multiple Boost versions easily. 

Setting-up Boost
^^^^^^^^^^^^^^^^

To enable Boost in your biicode project, just go to the block's ``CMakeLists.txt`` and add the following lines:

``blocks/your-account/boost-lambda/CMakeLists.txt``

.. code-block:: cmake

    INIT_BIICODE_BLOCK()

    #Include the biicode Boost setup script
    include(biicode/boost/setup)

    ADD_BIICODE_TARGETS()

    #Setup Boost and build (if needed) the required Boost components
    #Since lambda is header-only, there are no components to build and find
    bii_find_boost()

    #Add Boost headers to the block include directories
    target_include_directories(${BII_BLOCK_TARGET} INTERFACE ${Boost_INCLUDE_DIRS})

``bii_find_boost()`` is intended to wrap ``find_package(Boost ...)``, with almost the same input and ouput variables:

.. code-block:: cmake

    bii_find_boost([COMPONENTS component1 component2 ...] [REQUIRED])

It takes the Boost components you need, exactly as ``find_package(Boost)``, configures the biicode boost installation, builds that components, and then calls ``find_package(Boost COMPONENTS ...)``.

biicode uses the current cmake C++ compiler as Boost toolset, multiple toolsets are supported inside the same Boost version installation. Also note that, except you delete the libraries at the biicode environment, each Boost component will be built only once for each Boost version and toolset.

Build and run project
^^^^^^^^^^^^^^^^^^^^^

To configure and build your project, run ``bii find`` to get the dependencies (The boost setup block), and then run ``bii cpp:configure`` and ``bii cpp:build`` as usual:

.. code-block:: bash

    $ bii find
    $ bii cpp:configure 
             block your-account/boost-lambda
    ------------------------------------------------
    -- Setting up biicode Boost configuration...
    -- Boost version: 1.57.0
    ...

    $ bii cpp:build

Boost version
^^^^^^^^^^^^^

You may notice that the example above uses Boost 1.57.0. This is the default Boost version, shipped by the ``biicode/boost`` master track. If you want other version, say Boost 1.56.0, go to the block's ``biicode.conf`` file and edit the requirements entry, explicitly asking for the ``biicode/boost`` track you want:

``blocks/your-account/boost-lambda/biicode.conf``

.. code-block:: text

    [requirements]
        biicode/boost(1.56.0)

.. container:: infonote

  **Tip**

  You may want to support multiple tracks for your block depending on the Boost version it uses. One way could be set different tracks for your block, matching the Boost version requested:

  .. code-block:: text

    [requirements]
        biicode/boost(1.56.0)

    [parent]
        your-account/boost-lambda(1.56.0): -1, 0, whatever version is available

Boost.Coroutine
---------------

Boost.Coroutine implements `coroutines <http://en.wikipedia.org/wiki/Coroutine>`_ which can be useful to implement cooperative multitasking, iterators, etc, in a more natural way.

Open `the Boost.Coroutine example <http://www.biicode.com/examples/boost-coroutine>`_

.. code-block:: bash

    $ bii open examples/boost-coroutine

The example source code:

.. code-block:: cpp

    #include <boost/coroutine/all.hpp>
    #include <iostream>

    using namespace boost::coroutines;

    void cooperative(coroutine<void>::push_type &sink)
    {
        std::cout << "Hello";
        sink();
        std::cout << "world";
    }

    int main()
    {
        coroutine<void>::pull_type source{cooperative};
        std::cout << ", ";
        source();
        std::cout << "!\n";
    }

In the code above, the string "Hello, world!" is written by writing "Hello", going back to ``main()`` which writes the comma, then calling the coroutine again to continue printing "world", and finally printing "!" on ``main()``.  

You can visualize it as:

.. code-block:: text
    
    main()  | cooperative()
    --------+--------------
            |   "Hello"
      ", "  |
            |   "world"
      "!"   |


This is the ``CMakeLists.txt`` from the example:

.. code-block:: cmake

    include(biicode/boost/setup)

    INIT_BIICODE_BLOCK()
    ADD_BIICODE_TARGETS()

    set(Boost_USE_STATIC_LIBS ON)
    bii_find_boost(COMPONENTS system coroutine context thread REQUIRED)
    target_include_directories(${BII_BLOCK_TARGET} INTERFACE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${BII_BLOCK_TARGET} INTERFACE ${Boost_LIBRARIES})

    if(MSVC)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
    else()
        target_compile_options(${BII_BLOCK_TARGET} INTERFACE -std=c++11)
    endif()

Besides Visual Studio specific configuration (`See <https://msdn.microsoft.com/en-us/library/9a89h429.aspx>`_), the configuration is pretty straightforward:

1. Set the way  you want to link against Boost libraries with ``Boost_USE_STATIC_LIBS`` as usually when using Boost with CMake. biicode assumes static linking by default.

2. Set up and find the required Boost components with ``bii_find_boost()``. Note the order matters, since it's the order the libraries are linked together.

3. Add Boost to your target include directories. Again as usual when using Boost with CMake, via ``taget_include_directories()`` and ``Boost_INCLUDE_DIRS`` variable.

4. Link your target against Boost libraries using the ``Boost_LIBRARIES`` variable. 

Now just run ``bii cpp:configure``, wait until the Boost components are built (If those were not used previously), and then build your project with ``bii cpp:build``:

.. code-block:: bash

    $ bii find
    $ bii cpp:configure -G "Unix Makefiles"

          examples/boost-corutine
    ---------------------------------
    -- Setting up Biicode Boost...
    -- Building Boost 1.57.0 components with toolset gcc-4.9.2...
    -- Building system library...
    -- Building coroutine library...
    -- Building context library...
    -- Building thread library...
    -- Boost 1.57.0

    Found the following Boost libraries
        system
        coroutine
        context
        thread

    ...

    $ bii cpp:build

Alternative setup call
----------------------

``bii_find_boost()`` sets up Boost and then calls ``find_package(Boost)`` with the components passed to the former. 
While this setup works in 90% cases, there are some situations when the Boost components you need do not correspond to Boost libraries directly. 

If that's the case, you can call ``bii_setup_boost()`` function passing the Boost libraries to build, and then do the classic ``find_package(Boost COMPONENTS ...)`` with the components you need.

Take `Boost.Log <http://www.biicode.com/examples/examples/boost-log/master>`_ as an example:

``examples/boost-log/CMakeLists.txt``

.. code-block:: cmake
    
    INIT_BIICODE_BLOCK()

    include(biicode/boost/setup)

    ADD_BIICODE_TARGETS()

    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_MULTITHREADED ON)

    bii_setup_boost(COMPONENTS system thread filesystem log REQUIRED)
    find_package(Boost COMPONENTS system thread filesystem date_time log log_setup REQUIRED)

    target_compile_options(${BII_BLOCK_TARGET} INTERFACE -DBOOST_LOG_DYN_LINK)
    target_include_directories(${BII_BLOCK_TARGET} INTERFACE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${BII_BLOCK_TARGET} INTERFACE  ${Boost_LIBRARIES})

Note how the components required by Log are not exactly the same libraries that should be built.

Extra configuration variables
-----------------------------

The Boost setup scripts have some extra variables to debug and or customize Boost a bit:

* ``BII_BOOST_VERBOSE``: When is set to on, the setup scripts print some internal info about the current setup being run, and the different steps.

* ``BII_BOOST_LIBCXX``: When using the Clang compiler, enables Boost build using LLVM's libc++ instead of the default GNU's stdlibc++ standard library implementation.

* ``BII_BOOST_BUILD_J``: Specifies the number of threads used when building Boost libraries. May be useful to speed up Boost builds in setups where the libraries are always built, like continuous integration builds without cache. For example: ``bii cpp:configure -DBII_BOOST_BUILD_J=16``

* ``BII_BOOST_GLOBAL_USE_STATIC_LIBS``: Overrides the ``Boost_USE_STATIC_LIBS`` values specified in each ``CMakeLists.txt`` and sets a value globally. Useful when you depend on many Boost-related blocks and you may experience issues related to different linkages against Boost in that blocks. Use this variable carefully.

Contribute to the setup scripts
-------------------------------

The setup scripts are maintained as an `open source project on GitHub <https://github.com/Manu343726/boost-biicode>`_, you may want to ask about new features, report bugs, etc.