.. _faqs_biicode:

FAQs
====

Is biicode free?
----------------

**Yes, and it will be free forever for open source projects**. As long as you share your code, you will enjoy all the functionality and benefits of biicode totally free. However, if you prefer to keep your code private and only accessible to you and your collaborators, you'll have to upgrade to a **premium account** (not available at this moment, although we are working on it).


Is biicode an editor in the cloud?
----------------------------------

**No. In biicode you develop as usual, with your favourite platform and tools**. We provide a software tool that, once installed in your system, and using a very simple project layout (bin, build, src), is able to manage your source code in a powerful manner. Biicode allows you to reuse any single source file from any given project in any other project. So you can use your favourite IDE, builder, debugger... Now we have some fixed settings, that allow to define some tools as Visual, Eclipse, Mingw, CMake, but it will be soon generalized to all settings, and in any case, you have always the source code very well structured in your project.


Is biicode a VCS?
-----------------

No. If you need real version control for your projects, you can still use any available solution (git, svn, plasticscm). However, biicode does track and manage versions of the published code in order to provide a powerful, deterministic and scalable dependency manager that also allows easy collaboration on the platform without relaying on other tools.


Can I use biicode with my favourite VCS?
----------------------------------------

Yes, but this feature is still experimental. You can manage any of your biicode projects (projects) as a separate project under version control. You can zip and send by email, sync with dropbox, or put it into a VCS repository. But we store meta-information in a DB in binary format, as it doesn't allow straightforward merging by VCS. We are working on the merging process of such meta-information in case of conflicts that will likely arise, but this is an ongoing work.


Which languages are supported?
------------------------------

We have released our beta with a strong focus on C++, which lacks a multiOS dependency manager. We are experimenting with other languages as Python, Node, Java or Fortran. The support for these languages will mature during the next months, and new languages will enter the pipeline too.


How does biicode relate to Maven, NPM, PyPI...?
-----------------------------------------------

Biicode manages your code dependencies and retrieves the missing files from a central repository to your local machine. However, there are some differences with these services: 

* Biicode **always retrieves source code**. If necessary, artifacts (libs, jars) will be built locally for efficiency, but all the management is done with source code. In this way it is easier to develop, debug and collaborate on that source code if necessary. 
* Furthermore, **it only retrieves the strictly necessary files**. There is no concept of package in biicode. If you need just one file of biicode, just one file is retrieved. Obviously if that particular file has its own dependencies to other files, those files are also retrieved. The retrieved files are always managed at the project level, thus, it is very easy to have and develop with different versions of dependencies in different projects, in a similar way to a virtualenv compared with a global dependency (as packages with apt-get or similar). 
* Moreover, biicode **makes a strong effort on determinism and compatibility**. As the version of each file is tracked, we know when an upgrade is totally safe because it does not affect the specific files you are depending on. Biicode can even handle different versions of the same block (repo) if the dependency tree reaches such different versions but the affected files are not altered in such versions, i.e. we do not have to opt for the (typically) latest version (that can break code that rely on previous versions), but we can even mix in certain cases contents from different versions. In that way, the code that was published depending on specific versions of other code, is always compiled using exactly those versions, achieving fully determinism. Although upgrading version usually does not break code in case of mature libraries and packages, this is not true for more young and dynamic code. In this way, biicode works more as a CI system, in which developers quickly move forward their dependencies.

All that said, biicode does not try to compete against the power of such established systems nor tries to replace them, but to coexist with them as another source, and we are working hard with that purpose.


What is a project, a block?
-------------------------------------

Please, see :ref:`Introduction: Basic concepts <basic_concepts>`.
