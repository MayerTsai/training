#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include "use_semaphore.h"

sem_t my_semaphore; // 旗標
void *child(void *arg);

// 主程式
void test_semaphore()
{
  pthread_t threads[4];

  // Initialize the semaphore with an initial value of 2.
  // The second argument (0) indicates that the semaphore is shared between threads of the same process.
  // The third argument (2) is the initial value, allowing 2 threads in the critical section.
  if (sem_init(&my_semaphore, 0, 2) != 0)
  {
    perror("Semaphore initialization failed");
    return;
  }

  // Create multiple threads

  for (int i = 0; i < 4; i++)
  {
    int *a = malloc(sizeof(int));
    if (a == NULL)
    {
      perror("malloc for thread argument failed");
      return;
    }

    *a = i;
    if (pthread_create(&threads[i], NULL, child, (void *)a) != 0)
    {
      perror("Thread creation failed");
      free(a); // Avoid memory leak
      return;
    }
  }

  // Join threads to wait for their completion
  for (int i = 0; i < 4; i++)
  {
    pthread_join(threads[i], NULL);
  }

  // Destroy the semaphore
  sem_destroy(&my_semaphore);
  printf("All threads finished. Semaphore destroyed.\n");
  return;
}

// 子執行緒函數
void *child(void *arg)
{
  int a = *(int *)arg;
  int val;

  sem_wait(&my_semaphore); // Decrement semaphore value, wait if 0
  sem_getvalue(&my_semaphore, &val);
  printf("Thread %d: after sem_wait and semaphore value = %d\n", a, val);

  sleep(1); // Simulate work in critical section

  sem_post(&my_semaphore); // Increment semaphore value
  sem_getvalue(&my_semaphore, &val);
  printf("Thread %d: after sem_post and semaphore value = %d\n", a, val);
  free(arg);
  return NULL;
}
