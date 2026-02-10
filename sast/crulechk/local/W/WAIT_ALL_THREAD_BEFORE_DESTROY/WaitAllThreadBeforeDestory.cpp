//@checker WAIT_ALL_THREAD_BEFORE_DESTROY
#define PTHREAD_MUTEX_NORMAL 0

struct pthread_mutexattr_t {};
struct pthread_mutex_t {};

extern int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type);
extern int pthread_mutex_init(pthread_mutex_t* mutex, pthread_mutexattr_t* attr);
extern int pthread_mutex_lock(pthread_mutex_t* mutex);
extern int pthread_mutex_unlock(pthread_mutex_t* mutex);
extern int pthread_mutex_destroy(pthread_mutex_t* mutex);

pthread_mutexattr_t attr;
pthread_mutex_t mutex;


pthread_mutex_t theLock;
int data;

void thread_wait_all();
 
int cleanupAndFinish(void) {
  int result = 0;
  if ((result = pthread_mutex_destroy(&theLock)) != 0) { //@violation WAIT_ALL_THREAD_BEFORE_DESTROY
    /* Handle error */
  }
  data++;
  return data;
}
 
void worker(int value) {
  int result = 0;
  if ((result = pthread_mutex_lock(&theLock)) != 0) {
    /* Handle error */
  }
  data += value;
  if ((result = pthread_mutex_unlock(&theLock)) != 0) {
    /* Handle error */
  }
}



int cleanupAndFinishCompliant(void) {
  int result = 0;
  thread_wait_all();
  if ((result = pthread_mutex_destroy(&theLock)) != 0) { 
    /* Handle error */
  }
  data++;
  return data;
}
 