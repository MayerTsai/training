#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct person
{
  char *name;
  int age;
} person, *ptr_person;

ptr_person create_person(char *name, int age);

#endif // STRUCTURE_H