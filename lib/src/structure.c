#include "structure.h"
#include <stdio.h>
#include <stdlib.h>

ptr_person create_person(char *name, int age)
{
  ptr_person p = malloc(sizeof(person));
  if (p == NULL)
    return NULL;
  p->name = name;
  p->age = age;
  return p;
}
