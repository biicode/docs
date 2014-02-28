#include "math_ext.h"
#include "google/gtest/gtest.h"
#include "stdio.h"
 
// Tests Factorial()
// Tests factorial of positive numbers.
TEST(FactorialTest, Positive) {
	EXPECT_EQ(1, Factorial(1));
	EXPECT_EQ(2, Factorial(2));
	EXPECT_EQ(6, Factorial(3));
	EXPECT_EQ(40320, Factorial(8));
}
