#include <stdio.h>
#include <use_func.h>
#include <use_semaphore.h>
#include <use_macro.h>
#include <use_collector.h>
#include <use_pointer.h>

int main()
{

  printf("\\ \" \' \n");
  if (test_pointer() != 0)
  {
    printf("Pointer failed.");
    return 1;
  }

  if (test_myfunction() != 0)
  {
    printf("Function failed.");
    return 1;
  }

  if (test_collector() != 0)
  {
    printf("Collector failed.");
    return 1;
  }

  if (macro_test() != 0)
  {
    printf("Macro failed.");
    return 1;
  }

  if (parent() != 0)
  {
    printf("Multithreading failed.");
    return 1;
  }

  return 0;
}

//
