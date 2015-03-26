.. _exparser:

Expression Parser
=================

Expression Parser is a C++ library to parse a character sequence as an expression using Dijkstra's `Shunting-yard algorithm <http://en.wikipedia.org/wiki/Shunting-yard_algorithm>`_  which modifies `Jesse Brown's code <http://www.daniweb.com/software-development/cpp/code/427500/calculator-using-shunting-yard-algorithm>`_.

The main block is at `amalulla/cpp-expression-parser <http://www.biicode.com/amalulla/cpp-expression-parser>`_, which is generated from this `github repo <https://github.com/MariadeAnton/cpp-expression-parser/>`_.

Simple form of mathematical expression parsing
-----------------------------------------------

In this example we'll show a simple code to develop a mathematical expression parser, with expressions like "pi" or "gravity".

Create a new project
^^^^^^^^^^^^^^^^^^^^
 
 Create a simple project and the code inside it:

.. code-block:: bash

   $ bii init exp-parser_example -L 
   $ cd exp-parser_example
   $ # copy the code below

**main.cpp**

.. code-block:: cpp

  #include <iostream>
  #include <limits>
  #include <map>
  #include <string>
  #include "shunting-yard.h"

  void calculation(const char* expr, 
      std::map<std::string, double>* vars = 0) {
    double result = calculator::calculate(expr, vars);
    std::cout << "'" << expr << "' calculated result is: " <<
        result << "." << std::endl;
  }
  int main() { 
      std::map <std::string, double> vars; 
      vars["gravity"] = 9.78; 
      vars["pi"] = 3.14;
      calculation("-pi+1", &vars);
      calculation("10*gravity", &vars);
  return 0; 

  } 

Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 INFO: Processing changes...
 your_user/expression_parser depends on:
       system:
          iostream
          limits
          map
          string
       unresolved:
          shunting-yard.h

Now, edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

.. code-block:: text

 [requirements]
     amalulla/cpp-expression-parser: 2

 [includes]
     shunting-yard.h: amalulla/cpp-expression-parser

Now, checking again **bii deps** shows all resolved dependencies.

Build the project
^^^^^^^^^^^^^^^^^

Just build the project and run this example!

.. code-block:: bash

 $ bii build
 $ cd bin
 $ # run executable

You can see the results of the parsed expressions in the output:
  
.. code-block:: bash
   
   $  '-pi+1' calculated result is -2.14.
   $  '10*gravity' calculated result is 97.8.

Open and build
--------------

This example is already in biicode at `examples/expression_parser <http://www.biicode.com/examples/expression-parser>`_.

To give it a simple run, just open the block and build it like this:

.. code-block:: bash

   $ bii init exp-parser_example
   $ cd exp-parser_example
   $ bii open examples/expression_parser
   $ bii build
   $ cd bin
   $ # run executable

Here is the output:
  
.. code-block:: bash
   
   $  '-pi+1' calculated result is -2.14.
   $  '10*gravity' calculated result is 97.8.

Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.
  

