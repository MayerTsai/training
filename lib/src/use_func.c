#include <stdio.h>
#include "use_func.h"

int add(int, int);

int test_myfunction()
{
  printf("Test my add = %d\n", add(5, 10));
  return 0;
}

int add(int a, int b)
{
  return a + b;
}