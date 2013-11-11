Gmock (Google C++ Mocking Framework)
=====================================

Google C++ Mocking Framework (or Google Mock, or simply gmock for short) is a library for writing and using C++ mock classes. For more information about this library, visit their `official website <https://code.google.com/p/googlemock/>`_ or `wiki <https://code.google.com/p/googlemock/w/list>`_ 

You can find here the `Gmock biicode library site <https://www.biicode.com/google/blocks/google/gmock/branches/master>`_ .

The following example shows a simple use of gmock test. You can find this and other examples in `the biicode gmock samples block <https://www.biicode.com/google/blocks/google/gmocksamples/branches/master>`_ .

.. code-block:: cpp
	:linenos:

	// Copyright 2013, Google Inc.
	// All rights reserved.
	//
	// Redistribution and use in source and binary forms, with or without
	// modification, are permitted provided that the following conditions are
	// met:
	//
	//     * Redistributions of source code must retain the above copyright
	// notice, this list of conditions and the following disclaimer.
	//     * Redistributions in binary form must reproduce the above
	// copyright notice, this list of conditions and the following disclaimer
	// in the documentation and/or other materials provided with the
	// distribution.
	//     * Neither the name of Google Inc. nor the names of its
	// contributors may be used to endorse or promote products derived from
	// this software without specific prior written permission.
	//
	// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	//
	// Author: wan@google.com (Zhanyong Wan)

	// Tests Google Mock's functionality that depends on exceptions.

	// Google Mock - a framework for writing C++ mock classes.
	//
	// This program is for verifying that a leaked mock object can be
	// caught by Google Mock's leak detector.

	#include "google/gmock/gmock.h"

	namespace {

	using ::testing::Return;

	class FooInterface {
	 public:
	  virtual ~FooInterface() {}
	  virtual void DoThis() = 0;
	};

	class MockFoo : public FooInterface {
	 public:
	  MockFoo() {}

	  MOCK_METHOD0(DoThis, void());

	 private:
	  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFoo);
	};

	TEST(LeakTest, LeakedMockWithExpectCallCausesFailureWhenLeakCheckingIsEnabled) {
	  MockFoo* foo = new MockFoo;

	  EXPECT_CALL(*foo, DoThis());
	  foo->DoThis();

	  // In order to test the leak detector, we deliberately leak foo.

	  // Makes sure Google Mock's leak detector can change the exit code
	  // to 1 even when the code is already exiting with 0.
	  exit(0);
	}

	TEST(LeakTest, LeakedMockWithOnCallCausesFailureWhenLeakCheckingIsEnabled) {
	  MockFoo* foo = new MockFoo;

	  ON_CALL(*foo, DoThis()).WillByDefault(Return());

	  // In order to test the leak detector, we deliberately leak foo.

	  // Makes sure Google Mock's leak detector can change the exit code
	  // to 1 even when the code is already exiting with 0.
	  exit(0);
	}

	TEST(LeakTest, CatchesMultipleLeakedMockObjects) {
	  MockFoo* foo1 = new MockFoo;
	  MockFoo* foo2 = new MockFoo;

	  ON_CALL(*foo1, DoThis()).WillByDefault(Return());
	  EXPECT_CALL(*foo2, DoThis());
	  foo2->DoThis();

	  // In order to test the leak detector, we deliberately leak foo1 and
	  // foo2.

	  // Makes sure Google Mock's leak detector can change the exit code
	  // to 1 even when the code is already exiting with 0.
	  exit(0);
	}

	}  // namespace


	int main(int argc, char **argv) {
	  testing::InitGoogleMock(&argc, argv);

	  // Ensures that the tests pass no matter what value of
	  // --gmock_catch_leaked_mocks and --gmock_verbose the user specifies.
	  testing::GMOCK_FLAG(catch_leaked_mocks) = true;
	  testing::GMOCK_FLAG(verbose) = testing::internal::kWarningVerbosity;

	  return RUN_ALL_TESTS();
	}

You will see next console output after executing the command:
	
.. code-block:: bat

	$ bii cpp:run
	
	...
	
	[==========] Running 3 tests from 1 test case.
	[----------] Global test environment set-up.
	[----------] 3 tests from LeakTest
	[ RUN      ] LeakTest.LeakedMockWithExpectCallCausesFailureWhenLeakCheckingIsEnabled
	
	ERROR: this mock object (used in test LeakTest.LeakedMockWithExpectCallCausesFailureWhenLeakCheckingIsEnabled) should be deleted but never is. Its address is @0x5d29e8.
	ERROR: 1 leaked mock object found at program exit.

