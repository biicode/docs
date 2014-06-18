Configure the CMake file of dependencie
=======================================

Just make a file wwith the name ``biicode.configure`` with the biicode macro ``BII_ADD_INTERFACE(user-name block-name)``.

For example, if you want to compile the block mrpotato/parts with the C++ 11 flag on Linux, just write a file like followwing.
 
**biicode.configure**

.. code-block:: cmake

	#############BIICODE MACROS############
	BII_ADD_INTERFACE(mrpotato parts)
	#######################################

	target_compile_options(interface_mrpotato_parts_lib PUBLIC -std=c++11)