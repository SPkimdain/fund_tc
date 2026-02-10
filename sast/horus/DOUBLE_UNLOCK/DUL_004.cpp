#include <stdlib.h>
#include <stdio.h>

/* DUL_004 - pthread */

#define PTHREAD_MUTEX_INITIALIZER {}

struct pthread_mutex_t {};

extern int pthread_mutex_lock(pthread_mutex_t* mutex);
extern int pthread_mutex_unlock(pthread_mutex_t* mutex);

void DUL_004_function(int flag, int flag2) {
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  char error1[10];
  char error2[20];
  FILE *fp = fopen("filename", "r");

  if(flag == 0) {
    pthread_mutex_lock(&mutex);
    fread(error1, 1, 10, fp);
    if(flag2 > 10) {
      pthread_mutex_unlock(&mutex);  

      fread(error2, 1, 10, fp);

      pthread_mutex_unlock(&mutex); //@violation DOUBLE_UNLOCK
    }
  }

  if(fp != 0) {
    fclose(fp);
  }
}
