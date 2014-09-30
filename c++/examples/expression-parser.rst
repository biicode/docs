.. _exparser:

Expression Parser
=================

This block is a C++ library to parse a character sequence as an expression using Dijkstra's `Shunting-yard algorithm <http://en.wikipedia.org/wiki/Shunting-yard_algorithm>`_  which modifies `Jesse Brown's code <http://www.daniweb.com/software-development/cpp/code/427500/calculator-using-shunting-yard-algorithm>`_.

The main block is `here <http://www.biicode.com/amalulla/cpp-expression-parser>`_, which is generated from this `github repo <https://github.com/MariadeAnton/cpp-expression-parser/>`_.

Simple form of mathematical expression parsing
-----------------------------------------------

This example is `already in biicode <http://www.biicode.com/examples/expression-parser>`_, it's simple to run, just open the block and build it like this:

.. code-block:: bash

   $ bii init exp-parser
   $ cd exp-parser
   $ bii open examples/expression_parser
   $ bii cpp:build

The code of the example is this one:

.. code-block:: cpp

   #include <iostream>
   #include <limits>
   #include <map>
   #include <string>
   #include "amalulla/cpp-expression-parser/shunting-yard.h"

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




Now, run the hello example.

.. code-block:: bash

   $ bin/examples_expression_parser_main.exe

You can see the results of the parsed expressions in the output:

  
.. code-block:: bash
   
   $  '-pi+1' calculated result is -2.14.
   $  '10*gravity' calculated result is 97.8.


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.
  

