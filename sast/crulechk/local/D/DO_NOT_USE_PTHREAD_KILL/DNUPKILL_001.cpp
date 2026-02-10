//@checker DO_NOT_USE_PTHREAD_KILL
#define SIGTERM 1

typedef void (*FuncPtr)(void*);

struct pthread_t {};
extern int pthread_create(pthread_t* thread, char* str, FuncPtr ptr, int val);
extern int pthread_kill(pthread_t thread, int signal);

void DNUPKILL_001_function1(void* arg) {
  /* Execution of thread */
  
  int x = 0;
  x++;  
  
  return;    
}

int DNUPKILL_001_function2(void) {
  int result;
  pthread_t thread;
  if ((result = pthread_create(&thread, 0, DNUPKILL_001_function1, 0)) != 0) {
    /* Handle Error */
  }
  if ((result = pthread_kill(thread, SIGTERM)) != 0) { //@violation DO_NOT_USE_PTHREAD_KILL
    /* Handle Error */
  }
  /* This point is not reached because the process terminates in pthread_kill() */
  return 0;
}


