#include "use_pointer.h"
#include <stdio.h>

void my_func(void);

int test_pointer(void)
{
  int a = 10;
  int *p = &a;
  printf("a = %d\t address &a= %p or pointer to %p\n", a, &a, (void *)p);

  int b = 10;
  printf("b = %d\t address &b= %p or pointer to %p\n", b, &b, (void *)p);

  p = &b;
  printf("b = %d\t address &b= %p or pointer to %p\n", b, &b, (void *)p);

  int c = a;
  printf("c = %d\t address &c= %p and a=%d \t &a = %p\n", c, &c, a, &a);

  void *q = (void *)&my_func;
  printf("q = %p\n", q);

  return 0;
}

void my_func(void)
{
  printf("my function\n");
}
