.. _changelog:

Changelog
=========

v. 0.8
--------------------
*(4-Feb-14)*

* Merge bugfixes
* Hive download bugfixes


v. 0.7
--------------------
*(31-Jan-14)*

* Merge bugfixes
* Various bugfixes
* Deps output improved


v. 0.6.2
--------------------
*(28-Jan-14)*

* Added :ref:`arduino support <arduino>`
* Created :ref:`raspbian native client <installation>`
* Improved python native libraries
* Improved :ref:`virtual cells <virtual_cells>` management
* :ref:`Policies <policies>` made easier and now  user find their own DEV (in master branches) versions by default
* Bugfixes
* Added :ref:`new tagging system <comments_tags>`
* Added cpp:exe command that allows executing an already compiled binary w/o recompiling
* Improved renaming support
* Adding :ref:`OpenGL ES for RPI <opengles>` project generation
* Improved cpp wizard


v. 0.5
--------------------
*(10-Jan-14)*


* Raspberry now using rsync instead of scp
* Wizard rpi:setup for automatic install of cross compilers
* New breadcrumb navigation bar for blocks in browser
* Reduced computation by an order of magnitude, especially noticeable in large hives
* Fixed bugs in parsers, that kept old state even the file was modified
* Improved normalization of endlines, for handling also \\r
* Fixed bug of not finding new dependencies of files in already dependents blocks


v. 0.4
-------------------
*(20-Dec-13)*

* Improved wizards behavior
* Added cookies announcement in web as dictated by law


v. 0.3.4
--------------------
*(17-Dec-13)*

* Init and new configuration wizards
* Improved Eclipse support. You can read about it :ref:`here <use_ide>`
* Improved Raspberry Pi support. You can read about it :ref:`here <raspberry_pi>`
* Changed hive structure. You can read about new layout :ref:`here <hive_layout>`
* User can edit cmakes http://docs.biicode.com/en/latest/reference/cpp_build_files.html


v. 0.2.3  
--------------------
*(2-Dec-13)*

* Experimental upload-download of hives to biicode, so it is not necessary to publish to keep working in other computer.
* Navigation of uploaded hives in the web
* Updated exe creation to pyinstaller2.1, as 2.0 had some problems in some windows installs.
* Creation (experimental) of dynamic libraries from C code. Integration from python code with cffi.
* Improved use of biicode for C/C++ dev with RaspberryPI (linux only)


v. 0.1.11
---------
*(28-Oct-13)*

* Fixed bug in Eclipse Cmake generated project with empty targets
* Fixed bug that failed when trying to reuse just a data file from another published block (not reusing sources)
* Fixed bug of virtual cells in fortran, due to the "include" does not require to build source file
* Improved NMake support, launching vcvarsall in a .bat file to include environment variables
* Web loads much improved, loading of files with Ajax, rendering of color syntax highlighting with JS, client side and paginated to handle large files
* Web styles improvements, back and forward buttons
* Solved bug of hive with multiple src blocks, that was overwriting references to dep blocks
* WxWidgets binary support improved
* Improved handling of python imports, solved bug that didnt renamed properly to absolute imports
* Ctrl+C when init bug fixed (it created empty, wrong workspace)
* Applied some limits and constraints to block sizes, file sizes, number of files in a block and in a hive

v. 0.1.10.1 (Fix 1)
-------------------

* Fixed bug of crash when dep folder had connected cpp_rules files

v. 0.1.10
---------

* Setup & install in windows problem with setting PATH of biicode solved
* Defined C++0x as default, with possibility of changing it in settings
* Changed "find" command, now with parameters "update", "downgrade", "modify"
* Block referencing in client changed from full "owner/creator/block/branch" to "creator/block (owner/branch)"
* Improved setup tools, mainly  setup:cpp and setup:node, they update the Environment.bii
* Improved cpp:wizard to create classes and mains
* "dependencies.bii" now able to add, remove and redefine dependencies manually
* SyntaxHighligher done in browser instead of server to avoid timeouts while browsing large code files
* Solved some bugs in renaming files
* Transitive propagation of cpp_rules from libraries to executables requiring those libraries.
* Solved bugs for user login camelcase
* checkout --deps --force flow improved
* Use system proxy

v. 0.1.9
--------

* Added check of client version, so clients are informed about new releases and deprecated versions, with a download URL
* bii deps --detail command improved showing data dependencies and type of file
* Solved bugs in virtual resources that didn't let reuse published virtual resources
* cpp_rules files now can accept multiple statements per rule as well as rules without condition and else clauses
* Improved merge, but still very experimental
* Solved bug that allowed to "find" dependencies with cycles to own hive blocks
* bii deps --graph now working, showing hive block graph in browser
* Fixed problem with renaming files.
* Solved bug with user login upper-lower case mismatch
* Improved possibility of editing directly in dep folder, but still discouraged practice.
* Improved detection of implicit implementations in CPP with static class variables.
* Added preliminary support for fortran, and improved java and node; still experimental languages
* Changed folders in node, now using NODE_PATH variable so they dont have to be named node_modules
