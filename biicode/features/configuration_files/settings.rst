.. _settings_bii:

``settings.bii``: defining your tools and preferences
======================================================

The ``settings.bii`` file defines your preferred tools and specific configurations for one given project. This file is created when you create a new project, inside the ``bii`` folder, as you can see in the examples in the :ref:`layouts section <project_layout>`.

A project's ``settings.bii`` file stores preferences for any given project (language, compiler and other tools and configurations for that particular scenario). It is important to keep the file yaml format for correct interpretation.

You don't need to manually edit this file. **Each language or platform provides its own command for settings customization (except C/C++ language)**.


.. container:: todo

	* See the section :ref:`How to configure your IDE (C/C++) <configure_cmake_generators>`
	* :ref:`bii arduino:settings for Arduino projects<bii_arduino_settings>`
	* :ref:`bii rpi:settings for Raspberry Pi projects<bii_rpi_settings>`
