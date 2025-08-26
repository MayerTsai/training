#include <stdio.h>
#include <use_func.h>
#include <use_semaphore.h>
#include <use_macro.h>
#include <use_collector.h>
#include <use_pointer.h>

int main()
{
  int a = 1;
  int b = a;
  printf("a = %d at %p\n", a, (void *)&a);
  printf("b = %d at %p\n", b, (void *)&b);

  a = 2;
  int *ptr = &a;
  *ptr = 3;
  printf("*ptr = %d at %p\n", *ptr, (void *)ptr);
  printf("a= %d at %p\n", a, (void *)ptr);

  *ptr = b;
  printf("b = %d at %p\n", b, (void *)ptr);
  printf("a = %d  and b= %d\n", a, b);

  ptr = &b;  
  printf("b = %d at %p\n", b, (void *)ptr);

  a = 4;
  printf("a = %d and *ptr = %d\n", a, *ptr);

  /*

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
*/
  return 0;
}

//
