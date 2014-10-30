Google Mock (GMock)
===================

|gmock_homepage| is a C++ library for writing and using C++ mock classes.

The main block is |bii_gmock|, which is generated from this |fork_gmock|.


Mocking a simple function
--------------------------------

You can check all the gmock examples which are uploaded in biicode and execute any of them. Then, create a new project and open the |examples_gmock|.

.. code-block:: bash

   ~$ bii init gmock_sample
   ~$ cd gmock_sample
   ~/gmock_sample$ bii open examples/gmock


We'll run a example based in `Google C++ Mocking Framework for Dummies sample <https://code.google.com/p/googlemock/wiki/ForDummies>`_. Then, the files that you can check out in your *~/blocks/google/gmock/* folder are:


**turtle.h**

.. code-block:: cpp

	#pragma once

	class Turtle {

	public:

	  virtual ~Turtle() {}
	  virtual void PenUp() = 0;
	  virtual void PenDown() = 0;
	  virtual void Forward(int distance) = 0;
	  virtual void Turn(int degrees) = 0;
	  virtual void GoTo(int x, int y) = 0;
	  virtual int GetX() const = 0;
	  virtual int GetY() const = 0;

	};

**painter.h**

.. code-block:: cpp

	#pragma once
	#include "turtle.h"

	class Painter
	{
		Turtle*	turtle;
	public:
		Painter( Turtle* turtle )
			:	turtle(turtle){}

		bool DrawCircle(int, int, int){
			turtle->PenDown();
			return true;
		}
	};

**mock_turtle.h**

.. code-block:: cpp

	#pragma once

	#include "turtle.h"
	#include "google/gmock/gmock.h"  // Brings in Google Mock

	class MockTurtle : public Turtle {
	 public:

	  MOCK_METHOD0(PenUp, void());
	  MOCK_METHOD0(PenDown, void());
	  MOCK_METHOD1(Forward, void(int distance));
	  MOCK_METHOD1(Turn, void(int degrees));
	  MOCK_METHOD2(GoTo, void(int x, int y));
	  MOCK_CONST_METHOD0(GetX, int());
	  MOCK_CONST_METHOD0(GetY, int());
	};

**mock_turtle_test.cc**

.. code-block:: cpp

	#include "../mock_turtle.h"
	#include "../painter.h"

	#include "google/gtest/gtest.h"

	using ::testing::AtLeast;
	TEST(PainterTest, CanDrawSomething) { 
	  MockTurtle turtle;
	  EXPECT_CALL(turtle, PenDown())
	      .Times(AtLeast(1)); 
	 
	  Painter painter(&turtle);
	 
	  EXPECT_TRUE(painter.DrawCircle(0, 0, 10)); 
	}
	 
	int main(int argc, char** argv) { 
	  // The following line must be executed to initialize Google Mock 
	  // (and Google Test) before running the tests. 
	  ::testing::InitGoogleMock(&argc, argv); 
	  return RUN_ALL_TESTS(); 
	}


Now, we compile and execute the test:

.. code-block:: bash

	~/gmock_sample$ bin/examples_gmock_test_mock_turtle_test
	[==========] Running 1 test from 1 test case.
	[----------] Global test environment set-up.
	[----------] 1 test from PainterTest
	[ RUN      ] PainterTest.CanDrawSomething
	[       OK ] PainterTest.CanDrawSomething (0 ms)
	[----------] 1 test from PainterTest (0 ms total)

	[----------] Global test environment tear-down
	[==========] 1 test from 1 test case ran. (2 ms total)
	[  PASSED  ] 1 test.


You can aggregate as many tests as you want and verify all the methods actions, returns, calls, etc.


.. |gmock_homepage| raw:: html

   <a href="https://code.google.com/p/googlemock/" target="_blank">Google C++ Mocking Framework</a>

.. |bii_gmock| raw:: html

   <a href="http://www.biicode.com/google/gmock" target="_blank">here</a>

.. |fork_gmock| raw:: html

   <a href="https://github.com/franramirez688/gmock" target="_blank">github repo</a>

.. |examples_gmock| raw:: html

   <a href="https://www.biicode.com/examples/examples/gmock/master" target="_blank">examples/gmock block</a>