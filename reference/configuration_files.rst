.. _config_files:

Configuration files
===================

In this section you will find a detailed description of the biicode configuration files. These files **extend the basic biicode functionality, providing you with additional tools for taking a deeper control and full flexibility configuring your hives and blocks**.

All biicode configuration files have the ``.bii`` extension, and are located insinde ``bii`` folders across your workspace. Take a look at the :ref:`workspace <workspace_layout>` and :ref:`hives <hive_layout>` layouts, and see the examples trying to find the locations for different ``*.bii`` files, and their names.

* Configuration files contained in the ``bii`` folder of your workspace contain **general settings that are shared by all the hives and blocks in your workspace**. Their names start with the ``default_`` string, and that gives an idea of the characteristics of the rules contained in these files. The rules contained in this files are used as default settings when you create a new hive, and their contents are copied to the ``bii`` folder of the new hives. Examples of these files are ``default_policies.bii``, or ``default_filefilter.bii`` in the ``your_workspace/bii`` folder.

* Configuration files can also be placed inside the ``bii`` folder in a **hive** or **block**. These configurations provide **control of the settings for specific projects and groups of files**.

These are the configuration files that will be explained in this section:

* The :doc:`dependencies.bii<configuration_files/dependencies>` file contains information about **file dependencies** that cannot be automatically resolved by biicode, and allows you to take full control of the dependencies definition.
* The :doc:`filefilter.bii<configuration_files/filefilter>` allows you to define which types of files will be included in your hive.
* The :doc:`mains.bii<configuration_files/mains>` defines which cells contain entry points to executable code, or serve as static or dynamic libraries.
* The :doc:`policies.bii<configuration_files/policies>` determines rules to be applied when finding or updating specific versions of the dependencies.
* The :doc:`settings.bii<configuration_files/settings>` defines general settings about the tools you are using: compiler, configurer, IDE…

All these configuration files are explained in detail in their corresponding subsections:

.. toctree::
   :maxdepth: 1
   
   dependencies.bii: Configuring file dependencies <configuration_files/dependencies>
   filefilter.bii: Including and exluding cells in a hive <configuration_files/filefilter>
   mains.bii: Defining entry points in your code <configuration_files/mains>
   policies.bii: Defining the code you want to reuse <configuration_files/policies>
   settings.bii Defining your tools and preferences <configuration_files/settings>