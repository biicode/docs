#include "math_ext.h"
#include "google/gtest/gtest.h"
 
// Tests Factorial()
 
// Tests factorial of negative numbers.
TEST(FactorialTest, Negative) {
	// This test is named "Negative", and belongs to the "FactorialTest"
	// test case  
	EXPECT_EQ(-1, Factorial(-5));
	EXPECT_EQ(-1, Factorial(-1));
	EXPECT_LT(Factorial(-10), 0);
}
 
// Tests factorial of 0.
TEST(FactorialTest, Zero) {
	EXPECT_EQ(1, Factorial(0));
}
