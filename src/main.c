#include <stdio.h>
#include <structure.h>
#include <string.h>
#include <use_func.h>
#include <use_macro.h>
#include <use_semaphore.h>

void test_struct();
void test_array();
void test_myfunction();
void test_macro();

void my_func(void);
void test_pointer();

int main()
{
  printf("\\ \" \' \n");
  test_pointer();
  test_macro();
  test_struct();
  test_array();
  test_myfunction();
  test_semaphore();
  return 0;
}

void test_struct()
{
  person p;
  p.name = "binbin";
  p.age = 55;
  printf("my name is : %s", p.name);
  printf("\tmy age is : %d\n", p.age);

  ptr_person ptr_p = create_person("mayer", 55);
  printf("my name is : %s", ptr_p->name);
  printf("\tmy age is : %d\n", ptr_p->age);
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

void test_myfunction()
{
  printf("my_add = %d\n", add(5, 10));
}

void test_macro()
{
  printf("my_add is: %d\n", my_add(5, 10));
  printf("my_max macro: %d\n", my_max(10, 5));

  printf("my_string1 macro: %s\n", my_string1("string1"));
  printf("my_string2 macro: %s\n", my_string2(string2));
  printf("my_string3 macro: %s\n", my_string3(string3));
  printf("my_string4 macro: %s\n", my_string4(string4));
}

void my_func(void)
{
  printf("print my_function\n");
}

void test_pointer()
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
}

//
