#include "use_collector.h"
#include <stdio.h>
#include <string.h>

void test_array(void);

int test_collector()
{
  test_array();
  return 0;
}

void test_array()
{
  int a[5] = {1, 2, 3, 4, 5};

  for (int i = 0; i < 5; i++)
    printf("%d", a[i]);
  printf("\n");

  char *str = "hello world";
  printf("%s\n", str);

  for (int i = 0; i < (int)strlen(str); i++)
    printf("%c", str[i]);
  printf("\n");
}