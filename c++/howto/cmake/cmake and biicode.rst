Configure the CMake file of dependencies
========================================

In this section, it explain the way to write cmake files for your dependencies.

Just make a file with the name ``biicode.configure`` inside your project with the biicode macro ``BII_ADD_INTERFACE(user-name block-name)``.

For example, if you want to compile the block mrpotato/parts with the C++ 11 flag on Linux, just write a file like followwing.
 
**biicode.configure**

.. code-block:: cmake

	#############BIICODE MACROS############
	BII_ADD_INTERFACE(mrpotato parts)
	#######################################

	target_compile_options(interface_mrpotato_parts_lib PUBLIC -std=c++11)