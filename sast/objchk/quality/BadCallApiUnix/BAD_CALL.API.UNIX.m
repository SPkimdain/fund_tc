#include <pthread.h>
#include <fcntl.h>

void f();

void test(const char *path) {
  int fd = open(path, O_CREAT); //@violation 
// call to 'open' requires a third argument when the 'O_CREAT' flag is set

  pthread_once_t pred = {0x30B1BCBA, {0}};
  pthread_once(&pred, f);    //@violation
// call to 'pthread_once' uses the local variable

  int *p = malloc(0); //@violation 
// allocation size of 0 bytes

   *p = calloc(0, 42); //@violation 
// allocation size of 0 bytes

   *p = malloc(1);
  p = realloc(p, 0); //@violation 
// allocation size of 0 bytes

   *p = alloca(0); //@violation 
// allocation size of 0 bytes

   *p = valloc(0); //@violation 
// allocation size of 0 bytes
}
//open
//pthread_once
//calloc
//malloc
//realloc
//alloca
