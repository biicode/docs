.. _building:

Adapt your library
------------------

With previous CMakeLists.txt
===========================

If you already have a ``CMakeLists.txt`` file there's no need to replace it, just adapt it like this:

.. code-block:: cmake

   IF(BIICODE)  
      ADD_BIICODE_TARGETS()
      RETURN()
   ENDIF()
   # Your regular project configuration here




Without previous CMakeLists.txt
===============================


