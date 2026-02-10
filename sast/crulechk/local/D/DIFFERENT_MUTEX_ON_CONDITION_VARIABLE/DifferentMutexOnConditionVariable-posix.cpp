//@checker DIFFERENT_MUTEX_ON_CONDITION_VARIABLE

#define PTHREAD_MUTEX_NORMAL 0
#define PTHREAD_MUTEX_ERRORCHECK 1
#define NULL 0

extern int printf ( const char * format, ... );

struct pthread_mutexattr_t {};
struct pthread_mutex_t {};
struct pthread_cond_t {};
struct pthread_t {};

typedef void* (*handler)(void);

extern int pthread_mutexattr_init(pthread_mutexattr_t* attr);
extern int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type);
extern int pthread_mutex_init(pthread_mutex_t* mutex, pthread_mutexattr_t* attr);
extern int pthread_mutex_lock(pthread_mutex_t* mutex);
extern int pthread_mutex_unlock(pthread_mutex_t* mutex);
extern int pthread_cond_init(pthread_cond_t* c, void* flag);
extern int pthread_cond_wait(pthread_cond_t* c, pthread_mutex_t* mutext);
extern int pthread_cond_signal(pthread_cond_t* c);
extern int pthread_create(pthread_t* thrd, void* flag, handler h, void* flag2);
extern int pthread_join(pthread_t thrd, void* flag);
 
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_cond_t cv;
pthread_cond_t cv2;
pthread_mutexattr_t attr;

void *waiter1();
void *waiter2();
void *waiter3();
void *signaler();
 
int count1 = 0, count2 = 0, count3 = 0;
#define COUNT_LIMIT 5
 
int main() {
  int ret;
  pthread_t thread1, thread2, thread3;
 
  if ((ret = pthread_mutexattr_init( &attr)) != 0) {
    /* Handle error */
  }
 
  if ((ret = pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_ERRORCHECK)) != 0) {
    /* Handle error */
  }
 
  if ((ret = pthread_mutex_init( &mutex1, &attr)) != 0) {
    /* Handle error */
  }
 
  if ((ret = pthread_mutex_init( &mutex2, &attr)) != 0) {
    /* Handle error */
  }

  if ((ret = pthread_cond_init( &cv, NULL)) != 0) {
    /* handle error */
  }

  if ((ret = pthread_cond_init( &cv2, NULL)) != 0) {
    /* handle error */
  }
 
  if ((ret = pthread_create( &thread1, NULL, waiter1, NULL))) {
    /* Handle error */
  }
 
  if ((ret = pthread_create( &thread2, NULL, waiter2, NULL))) {
    /* handle error */
  }
 
  if ((ret = pthread_create( &thread3, NULL, signaler, NULL))) {
    /* Handle error */
  }
 
  if ((ret = pthread_join( thread1, NULL)) != 0) {
    /* Handle error */
  }
 
  if ((ret = pthread_join( thread2, NULL)) != 0) {
    /* Handle error */
  }
 
  if ((ret = pthread_join( thread3, NULL)) != 0) {
    /* Handle error */
  }
 
  return 0;
}
 
 
void *waiter1() {
  int ret;
  while (count1 < COUNT_LIMIT) {
    if ((ret = pthread_mutex_lock(&mutex1)) != 0) {
      /* Handle error */
    }
 
    if ((ret = pthread_cond_wait(&cv, &mutex1)) != 0) {
      /* Handle error */
    }

    printf("count1 = %d\n", ++count1);
 
    if ((ret = pthread_mutex_unlock(&mutex1)) != 0) {
      /* Handle error */
    }
  }
 
  return NULL;
}
 
void *waiter2() {
  int ret;
  while (count2 < COUNT_LIMIT) {
    if ((ret = pthread_mutex_lock(&mutex2)) != 0) {
      /* Handle error */
    }
 
    if ((ret = pthread_cond_wait(&cv, &mutex2)) != 0) { //@violation DIFFERENT_MUTEX_ON_CONDITION_VARIABLE
      /* Handle error */
    }
 
    printf("count2 = %d\n", ++count2);
 
    if ((ret = pthread_mutex_unlock(&mutex2)) != 0) {
      /* Handle error */
    }
  }
 
  return NULL;
}

void *waiter3() {
  int ret;
  while (count2 < COUNT_LIMIT) {
    if ((ret = pthread_mutex_lock(&mutex2)) != 0) {
      /* Handle error */
    }
 
    if ((ret = pthread_cond_wait(&cv2, &mutex2)) != 0) {
      /* Handle error */
    }
 
    printf("count3 = %d\n", ++count2);
 
    if ((ret = pthread_mutex_unlock(&mutex2)) != 0) {
      /* Handle error */
    }
  }
 
  return NULL;
}


void *signaler() {
  int ret;
  while ((count1 < COUNT_LIMIT) || (count2 < COUNT_LIMIT)) {
    printf("signaling\n");
    if ((ret = pthread_cond_signal(&cv)) != 0) {
      /* Handle error */
    }
  }
 
  return NULL;
}