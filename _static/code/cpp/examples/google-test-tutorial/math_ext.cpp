#include "math_ext.h"
 
int Factorial (int num) {
  if (!num)return 1;
  if (num<0)return -1;
  return num*Factorial(num-1);
}