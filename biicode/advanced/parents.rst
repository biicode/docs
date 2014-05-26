.. _parents:

Parents
========

Every hive contains **a special yaml file which allows you to define some custom settings for your project**. This file is located in the ``bii`` folder of your hive, and its name is ``settings.bii``.

The biicode client generates a **default settings file** for you when you create a new hive. Initially, it contains only information regarding your platform: architecture, operating system, and version.

You can also specify your own settings for any particular project. These settings depend on your programming language. For instance, if you are working on a C/C++ hive, you can specify here your IDE, allowing :ref:`biicode integration with your preferred code editor <ide_configuration>`. For other hives, such as Arduino o Raspberry Pi projects, you provide information about your boards configuration using this file.

You don't need to manually edit this file. **Each language or platform provides its own command for settings customization**:

* :ref:`bii cpp:settings for C/C++ hives<bii_cpp_settings>`
* :ref:`bii arduino:settings for Arduino hives<bii_arduino_settings>`
* :ref:`bii rpi:settings for Raspberry Pi hives<bii_rpi_settings>`


You can :ref:`read more about the settings.bii file here<parents_bii>`.

