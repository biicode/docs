.. _settings:

Settings
========

Every hive contains **a special yaml file which allows you to define some custom settings for your project**. This file is located in the ``bii`` folder of your hive, and its name is ``settings.bii``.

The biicode client generates a default settings file for you when you create a new hive. Initially, it contains only information regarding your platform: architecture, operating system, and version. When you compile your project some additional information is included regarding the builder, compiler and configurer to be used.

You can also specify your own settings for any particular project. This information will be used, for instance, for defining the :ref:`virtual resources<virtual_cells`. You can :ref:`read more about the settings.bii file here<settings_bii>`.

