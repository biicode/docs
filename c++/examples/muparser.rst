MuParser
========

Many applications require the parsing of mathematical expressions. The main objective of this library is to provide a fast and easy way of doing this. muParser is an extensible high performance math expression parser library written in C++. It works by transforming a mathematical expression into bytecode and precalculating constant parts of the expression.. For more information about this library, visit their `official website <http://muparser.beltoforion.de//>`_.

You can find here the `Muparser library site <http://www.biicode.com/ingoberg/muparser>`_ .

The following example is a `math interactive interpreter <http://www.biicode.com/examples/muparser>`_ .

**main_muparser.cpp**

.. literalinclude:: /_static/code/cpp/examples/muparser/main_muparser.cpp
   :language: cpp
   :linenos:

**Download:**
:download:`main_muparser.cpp </_static/code/cpp/examples/muparser/main_muparser.cpp>`

Create a block:

.. code-block:: bash

	$ bii init my_project
	$ cd my_project
	$ bii new examples/muparser


Copy the cpp file in your block, then you need to resolve all the dependencies of this ``main.cpp``. Then you can compile it

.. code-block:: bash

	$ bii find
	$ bii cpp:build


You will see next console output after executing the command:

.. code-block:: bash

	$ cd bin
	$ bin $ ./examples_muparser_main_muparser
	                 __________
	    _____   __ __\______   \_____  _______  ______  ____ _______
	   /     \ |  |  \|     ___/\__  \ \_  __ \/  ___/_/ __ \\_  __ \
	  |  Y Y  \|  |  /|    |     / __ \_|  | \/\___ \ \  ___/ |  | \/
	  |__|_|  /|____/ |____|    (____  /|__|  /____  > \___  >|__|
	        \/                       \/            \/      \/
	  Version 2.2.3 (20121222; SF; 64BIT; RELEASE; ASCII)
	  (C) 2013 Ingo Berg
	-----------------------------------------------------------
	Running test suite:

	testing name restriction enforcement...passed
	testing syntax engine...passed
	testing postfix operators...
	  fail: 1000{m} (Unexpected token "1000" found at position 0.)
	  fail: 1000 {m} (Unexpected token "1000" found at position 0.)
	  fail: f1of1(1000){m} (Unexpected token "1000" found at position 6.)
	  fail: -f1of1(1000){m} (Unexpected token "1000" found at position 7.)
	  fail: -f1of1(-1000){m} (Unexpected token "1000" found at position 8.)
	  fail: f4of4(0,0,0,1000){m} (Unexpected token "1000" found at position 12.)
	  fail: 2+(a*1000){m} (Unexpected token "1000" found at position 5.)
	  fail: 2*3000meg+2 (Unexpected token "3000meg" found at position 2.)
	  failed with 8 errors
	testing infix operators...passed
	testing variable/constant detection...passed
	testing multiarg functions...passed
	testing expression samples...passed
	testing if-then-else operator...passed
	testing member functions...passed
	testing binary operators...passed
	testing error codes...passed
	testing string arguments...passed
	Test failed with 8 errors (527 expressions)
	-----------------------------------------------------------
	Commands:

	  list var     - list parser variables
	  list exprvar - list expression variables
	  list const   - list all numeric parser constants
	  opt on       - enable optimizer (default)
	  opt off      - disable optimizer
	  locale de    - switch to german locale
	  locale en    - switch to english locale
	  locale reset - reset locale
	  test bulk    - test bulk mode
	  quit         - exits the parser

	Constants:

	  "_e"   2.718281828459045235360287
	  "_pi"  3.141592653589793238462643
	-----------------------------------------------------------
	Enter an expression or a command:


You can now start typing mathematical expresions in the console.