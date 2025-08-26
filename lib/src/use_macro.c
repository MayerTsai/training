
#include "use_macro.h"
#include <stdio.h>

#define my_add(x, y) ((x) + (y))
#define my_max(op1, op2) ((op1 > op2) ? (op1) : (op2))

#define my_string1(x) x
#define my_string2(x) #x
#define my_string3(x) my_string2(x)
#define my_string4(x) my__##x
#define my__string4 "string4"

// Demonstrate various C preprocessor macros.
int macro_test(void)
{
  printf("my_add is: %d\n", my_add(5, 10));
  printf("my_max macro: %d\n", my_max(10, 5));

  printf("my_string1 macro: %s\n", my_string1("string1"));
  printf("my_string2 macro: %s\n", my_string2(string2));
  printf("my_string3 macro: %s\n", my_string3(string3));
  printf("my_string4 macro: %s\n", my_string4(string4));
  return 0;
}