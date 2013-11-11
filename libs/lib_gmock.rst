Gmock (Google C++ Mocking Framework)
=====================================

Google C++ Mocking Framework (or Google Mock for short) is a library for writing and using C++ mock classes. For more information about this library, visit their `official website <https://code.google.com/p/googlemock/>`_ or `wiki <https://code.google.com/p/googlemock/w/list>`_ 

You can find here the `Gmock biicode library site <https://www.biicode.com/google/blocks/google/gmock/branches/master>`_ .

The following example shows how to use the gmock tests.

.. code-block:: cpp
	:linenos:

	// Copyright 2008, Google Inc.
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

	// Tests Google Mock's output in various scenarios.  This ensures that
	// Google Mock's messages are readable and useful.

	#include "phil/gmock/gmock/gmock.h"

	#include <stdio.h>
	#include <string>

	#include "google/gtest/gtest.h"

	using testing::_;
	using testing::AnyNumber;
	using testing::Ge;
	using testing::InSequence;
	using testing::NaggyMock;
	using testing::Ref;
	using testing::Return;
	using testing::Sequence;

	class MockFoo {
	 public:
	  MockFoo() {}

	  MOCK_METHOD3(Bar, char(const std::string& s, int i, double x));
	  MOCK_METHOD2(Bar2, bool(int x, int y));
	  MOCK_METHOD2(Bar3, void(int x, int y));

	 private:
	  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFoo);
	};

	class GMockOutputTest : public testing::Test {
	 protected:
	  NaggyMock<MockFoo> foo_;
	};
	
	TEST_F(GMockOutputTest, CatchesLeakedMocks) {
	  MockFoo* foo1 = new MockFoo;
	  MockFoo* foo2 = new MockFoo;

	  // Invokes ON_CALL on foo1.
	  ON_CALL(*foo1, Bar(_, _, _)).WillByDefault(Return('a'));

	  // Invokes EXPECT_CALL on foo2.
	  EXPECT_CALL(*foo2, Bar2(_, _));
	  EXPECT_CALL(*foo2, Bar2(1, _));
	  EXPECT_CALL(*foo2, Bar3(_, _)).Times(AnyNumber());
	  foo2->Bar2(2, 1);
	  foo2->Bar2(1, 1);

	  // Both foo1 and foo2 are deliberately leaked.
	}

	void TestCatchesLeakedMocksInAdHocTests() {
	  MockFoo* foo = new MockFoo;

	  // Invokes EXPECT_CALL on foo.
	  EXPECT_CALL(*foo, Bar2(_, _));
	  foo->Bar2(2, 1);

	  // foo is deliberately leaked.
	}

	int main(int argc, char **argv) {
	  testing::InitGoogleMock(&argc, argv);

	  // Ensures that the tests pass no matter what value of
	  // --gmock_catch_leaked_mocks and --gmock_verbose the user specifies.
	  testing::GMOCK_FLAG(catch_leaked_mocks) = true;
	  testing::GMOCK_FLAG(verbose) = "warning";

	  TestCatchesLeakedMocksInAdHocTests();
	  return RUN_ALL_TESTS();
	}

The output you will see in your console	after executing the command:
	
.. code-block:: bat

	$ bii cpp:run
	
	...
	
	[==========] Running 1 test from 1 test case.
	[----------] Global test environment set-up.
	[----------] 1 test from GMockOutputTest
	[ RUN      ] GMockOutputTest.CatchesLeakedMocks
	[       OK ] GMockOutputTest.CatchesLeakedMocks (0 ms)
	[----------] 1 test from GMockOutputTest (0 ms total)

	[----------] Global test environment tear-down
	[==========] 1 test from 1 test case ran. (0 ms total)
	[  PASSED  ] 1 test.

	ERROR: this mock object should be deleted but never is. Its address is @0x5956f0.
	ERROR: this mock object (used in test GMockOutputTest.CatchesLeakedMocks) should be deleted but never is. Its address is @0x596b90.
	ERROR: this mock object (used in test GMockOutputTest.CatchesLeakedMocks) should be deleted but never is. Its address is @0x596c68.
	
	ERROR: 3 leaked mock objects found at program exit.