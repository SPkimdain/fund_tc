#include <stdlib.h>
#include <stdio.h>

/* TLF_001 - simple case */
#define PTHREAD_MUTEX_INITIALIZER {}

struct pthread_mutex_t {};

extern int pthread_mutex_lock(pthread_mutex_t* mutex);
extern int pthread_mutex_unlock(pthread_mutex_t* mutex);
extern int pthread_mutex_trylock(pthread_mutex_t* mutex);


void TLF_001_function(int flag, int flag2) {
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  char error1[10];
  char error2[20];
  
  FILE *fp;
  
  fp = fopen("filename", "r");
  
  if(flag > 10) {
    pthread_mutex_lock(&mutex);
    
    fread(error1, 1, 10, fp);
    
    if(flag2 == 20) {
      
      pthread_mutex_trylock(&mutex); //@violation TRYLOCK_FAIL
      
      fread(error2, 1, 10, fp);
      
    }
    
    pthread_mutex_unlock(&mutex);
  }

  fclose(fp);
}
