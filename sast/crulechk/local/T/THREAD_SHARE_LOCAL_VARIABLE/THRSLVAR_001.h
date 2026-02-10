
#ifndef _THRSLVAR_001_H_
#define _THRSLVAR_001_H_

#define 	thrd_error   0
#define 	thrd_success   1
#define 	thrd_timeout   2
#define 	thrd_busy   3
#define 	thrd_nomem   4

#define PTHREAD_MUTEX_DEFAULT	0
#define PTHREAD_MUTEX_NORMAL	0
#define PTHREAD_SCOPE_SYSTEM	0
#define PTHREAD_MUTEX_RECURSIVE	1
#define PTHREAD_SCOPE_PROCESS	1
#define PTHREAD_MUTEX_ERRORCHECK	2
#define PTHREAD_RWLOCK_DEFAULT_NP	2

#define PTHREAD_MUTEX_INITIALIZER {0, 0, -1, -1, -1}
#define PTHREAD_CANCEL_ASYNCHRONOUS   0

typedef struct{
	int field1;
}mtx_t;

int 	mtx_trylock (mtx_t *mtx);
int 	mtx_unlock (mtx_t *mtx);

typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned short    sa_family_t;
typedef int socklen_t;

typedef union {
    char __size[100];
    long int __align;
} pthread_attr_t;


struct in_addr {
	uint32_t s_addr;         /* Internet address */
};

struct sockaddr_in {
sa_family_t sin_family;    /* Address Family */
uint16_t sin_port;         /* Port number */
struct in_addr sin_addr;   /* Internet address */
unsigned char sin_zero[8]; /* Pad bytes */
};

extern int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

typedef struct {
    int __mutexkind;
} pthread_mutexattr_t;

typedef struct {
    int __m_reserved;
    int __m_count;
    int __m_kind;
	int __m_count1;
    int __m_kind2;
} pthread_mutex_t;


typedef unsigned long int pthread_t;

extern int pthread_mutex_init(pthread_mutex_t *,
			      const pthread_mutexattr_t *);

int pthread_join(pthread_t thread, void **retval);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);


unsigned int memset_s(void *s, unsigned int smax, int c, unsigned int n);

int chmod(char* fileName, int x); //Dummy for Mingw
int open(char* fileName, int flag, int x); //Dummy for Mingw
int fchmod(int fd, int x); //Dummy for Mingw
int close(int fd); //Dummy for Mingw
int fcloseall();
int pthread_setcanceltype(int t, int* val);

int isinf(float x);
int isnan(float x);

int unknown();
void opus1_print(int x);

#ifndef SIZE_MAX
#define SIZE_MAX 4294967295
#endif

#endif
