
#include "use_macro.h"
#include <stdio.h>

#define my_string(x) #x
#define my_string2(x, y) #x " " #y
#define my_add(x, y) (x + y)
#define my_max(op1, op2) ((op1 > op2) ? (op1) : (op2))
#define my_string3(x) my_##x

// Call a function from my_functions.h
int macro_test(void)
{
  printf("my_add is: %d\n", my_add(5, 10));
  printf("my_string macro: %s\n", my_string(Hello world));
  printf("my_string2 macro: %s\n", my_string2(Hello, world));
  printf("my_add macro: %d\n", my_add(5, 10));
  printf("my_max macro: %d\n", my_max(10, 5));
  char *my_string3(name) = "John"; // char *my_name = "John";
  printf("my_string3 macro: %s\n", my_name);
  return 0;
}