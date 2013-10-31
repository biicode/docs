Changelog
=========

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
checkout --deps --force flow improved
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