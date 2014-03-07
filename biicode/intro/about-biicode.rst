.. _about_biicode:

What is biicode
=================

Biicode is a new dependencies manager for Software developers, with many unique characteristics:

* It is **simple**. Everybody should be able to seamlessly integrate and reuse anybody else's source code, quickly.
* **Reuse** of existing code is always done from **source code**. If required by the language (as C++) artifacts like libraries are built locally.
* **Dependencies** are always managed at the file level. **No libraries, no packaging**. If you need to reuse some files from previously developed code, just the required files, together with its transitive dependencies are integrated in your project.
* It also **manages updates**. You can easily upgrade your dependencies if new compatible versions that match your preferences are published.
* It is fully **deterministic**, the joint compatible configuration of libraries is computed.
* **Multilanguage**, **multi OS**. The work flow, the tool, the way you reuse code is exactly the same independently of the programming language or the OS you are using. Currently we are working mainly for C/C++, but we have many other languages in the pipeline.
* Biicode is not just for reusing other's source code! Publishing your code is also very simple, so you can easily **share with others and reuse your code** in all your projects.
* **Dependencies deduced from source code**. Just code as usual, write your #includes or imports in your source files. No need to explicitely write them in other files. Biicode scans your source files, and extracts relationships between those files.
* **Configurable**: you can define (if desired) manually in configuration files many things, such as dependencies and connections between your files, the policies to find new dependencies or the rules to be applied while building.
* **Highly automated**. Based only on your source files, we are able to create projects and build scripts. For example in C++, we automatically create a CMakeLists.txt file with the configuration required to build your project.

Biicode is now in an early Beta stage but we are already open, also we have many users that are giving us a lot of feedback that we have to process and further improve the usability of the system. We are doing our best to quickly attend our current users feedback.

Biicode has many core innovations, and we are following the lean startup and MVP paradigms, i.e. we try to release very often and quickly and perform fast iterations on user feedback. However,  this also means that much functionality you could expect is not as intuitive as you would desire, and errors and failures could arise often, specially on last features. New features are probably on the way, maybe even implemented but not yet properly documented. Moreover, commands, processes etc. are likely to change in the short term.