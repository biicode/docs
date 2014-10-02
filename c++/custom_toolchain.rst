.. _custom_toolchains:

Using a custom toolchain
========================

Biicode generates a default toolchain to build projets, but you can use a custom one if you prefer so.
To use a custom toolchain you need to place it in your block folder (and add it as a dependency in :ref:`dependencies.bii<dependencies_bii>`)
and then specify you want to use that toolchain in your :ref:`settings.bii<settings_bii>`.

For example:

.. code-block:: none

	cpp: {cross_build: ARM, generator: Unix Makefiles,
	      toolchain: {path:fenix/armadillo/rpi_toolchain.cmake}}
	os: {arch: 64bit, family: Linux, subfamily: Ubuntu, version: '13.10'}
	rpi: {directory: armadillo, ip: 192.168.1.101, user: pi}


As you can see you define the path to the toolchain, that path includes a block which can be in blocks or deps folders.

You can also make your toolchain customizable by defining replacements tokens, for example:

.. code-block:: none

	INCLUDE(CMakeForceCompiler)
	SET(CMAKE_SYSTEM_NAME Linux)
	SET(CMAKE_SYSTEM_VERSION 1)
	SET(CMAKE_C_COMPILER COMPILER_PATH/bin/COMPILER_NAME-gcc)
	SET(CMAKE_CXX_COMPILER COMPILER_PATH/bin/COMPILER_NAME-g++)


and then in your :ref:`settings.bii<settings_bii>`:

.. code-block:: none

	cpp: {cross_build: ARM, generator: Unix Makefiles,
	      toolchain: {path: fenix/armadillo/rpi_toolchain.cmake,
	                  replacements: {COMPILER_PATH: /home/julia/raspberry_cross_compilers/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian,
	                                 COMPILER_NAME: gcc-linaro-arm-linux}
	                 }}
	os: {arch: 64bit, family: Linux, subfamily: Ubuntu, version: '13.10'}
	rpi: {directory: armadillo, ip: 192.168.1.101, user: pi}


So people reusing your block can redefine the tokens as they need.
