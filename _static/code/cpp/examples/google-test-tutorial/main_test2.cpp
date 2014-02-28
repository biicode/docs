#include "google/gtest/gtest.h"
#include "stdio.h"
 
// Tests Factorial()
//
// bii:#dependencies(+ test_factorial1.cpp test_factorial2.cpp)
int main(int argc, char **argv) {
  printf("Running main() from sample1\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}