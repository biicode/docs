.. _building:

Adapt your library
--------------------

 Adapt your library to publish to biicode can be almost immediately or require some work. The more bigger or heavy configured libraries, the higher time require to adapt it.

 Key concepts to keep in mind:

1. Biicode analyzes your code and builds a dependency graph with how each file are connected to each others.
2. When some user #includes a header (ex: file.h) of a remote block, biicode will download only the files that depends on "file.h" (recursively) and will build a library with only needed files. The library built for the dependency will be linked to your targets.
3. So dependency graph must be built correctly in order to reuse a library.
4. Given that a library must be built only with few files of the whole library, you can't assume in your ```CMakeLists.txt``` file that all files are present. For example: You cannot add include path to an exe target without check if it exist.


Without previous CMakeLists.txt
===============================

- Solo 2 cambios generalmente
- Tips: Asegurar bien hiladas deps

With previous CMakeLists.txt
===========================

- Tips: Asegurar bien hiladas deps
- Checks si hacemos comprobaciones a nivel de file
- Caso de linkar al final: addaptacion a lo bruto

If you already have a ``CMakeLists.txt`` file there's no need to replace it, just adapt it like this:

.. code-block:: cmake

   IF(BIICODE)  
      ADD_BIICODE_TARGETS()
      RETURN()
   ENDIF()
   # Your regular project configuration here





