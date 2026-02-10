// @checker AVOID_PTHREAD_MUTEX_NORMAL

#define PTHREAD_MUTEX_NORMAL 0

struct pthread_mutexattr_t {};
struct pthread_mutex_t {};

extern int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type);
extern int pthread_mutex_init(pthread_mutex_t* mutex, pthread_mutexattr_t* attr);
extern int pthread_mutex_lock(pthread_mutex_t* mutex);
extern int pthread_mutex_unlock(pthread_mutex_t* mutex);

pthread_mutexattr_t attr;
pthread_mutex_t mutex;

unsigned const shared_var = 0;

int APMN_001_function(void) {
  int result;
  if((result = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL)) != 0) { //@violation AVOID_PTHREAD_MUTEX_NORMAL
    /* Handle Error */
  }
  if((result = pthread_mutex_init(&mutex, &attr)) != 0) {
    /* Handle Error */
  }
  if((result = pthread_mutex_lock(&mutex)) != 0) {
    /* Handle Error */
  }
  /* Critical Region*/
  if((result = pthread_mutex_unlock(&mutex)) != 0) {
    /* Handle Error */
  }
  return 0;
}
