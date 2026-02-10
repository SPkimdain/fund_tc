#include <stdlib.h>

/* AD_001 - simple case */

enum {
  thrd_success,
  thrd_nomem,
  thrd_timedout,
  thrd_busy,
  thrd_error
};


typedef int(*thrd_start_t)(void*);
typedef void* thrd_t;
typedef void* mtx_t;

extern int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
extern int thrd_join(thrd_t thr, int *res);

extern int mtx_init(mtx_t* mutex, int type);
extern int mtx_lock(mtx_t* mutex);
extern int mtx_unlock(mtx_t *mutex);
extern void mtx_destroy(mtx_t *mutex);
mtx_t AD_001_lock;

typedef struct {
  int balance;
  mtx_t balance_mutex;
} AD_001_bank_account;

typedef struct {
  AD_001_bank_account *from;
  AD_001_bank_account *to;
  int amount;
} AD_001_transaction;

void AD_001_create_bank_account(AD_001_bank_account **ba, int initial_amount) {
  AD_001_bank_account *nba = (AD_001_bank_account *)malloc(sizeof(AD_001_bank_account));
  if(nba == 0) {
    return;
    /* Handle error */
  }

  nba->balance = initial_amount;
  if(thrd_success != mtx_init(&nba->balance_mutex, 0)) {
    /* Handle error */
  }

  *ba = nba;
}

int AD_001_deposit(void *ptr) {
  AD_001_transaction *args = (AD_001_transaction *)ptr;

  if(thrd_success != mtx_lock(&args->from->balance_mutex)) {
    /* Handle error */
  }

  /* Not enough balance to transfer */
  if(args->from->balance < args->amount) {
    if(thrd_success
      != mtx_unlock(&args->from->balance_mutex)) {
      /* Handle error */
    }
    return -1; /* Indicate error */
  }
  if(thrd_success != mtx_lock(&args->to->balance_mutex)) {
    /* Handle error */
  }

  args->from->balance -= args->amount;
  args->to->balance += args->amount;

  if(thrd_success
    != mtx_unlock(&args->from->balance_mutex)) { //@violation AVOID_DEADLOCK
    /* Handle error */
  }

  if(thrd_success
    != mtx_unlock(&args->to->balance_mutex)) {
    /* Handle error */
  }

  free(ptr);
  return 0;
}

int AD_001_Function(void) {
  thrd_t thr1, thr2;
  AD_001_transaction *arg1;
  AD_001_transaction *arg2;
  AD_001_bank_account *ba1 = 0;
  AD_001_bank_account *ba2 = 0;

  AD_001_create_bank_account(&ba1, 1000);
  AD_001_create_bank_account(&ba2, 1000);

  if(ba1 == 0 || ba2 == 0) {
    return 0;
  }

  arg1 = (AD_001_transaction *)malloc(sizeof(AD_001_transaction));
  if(arg1 == NULL) {
    /* Handle error */
    return 0;
  }
  arg2 = (AD_001_transaction *)malloc(sizeof(AD_001_transaction));
  
  arg1->from = ba1;
  arg1->to = ba2;
  arg1->amount = 100;

  arg2->from = ba2;
  arg2->to = ba1;
  arg2->amount = 100;

  /* Perform the deposits */
  if(thrd_success
    != thrd_create(&thr1, AD_001_deposit, (void *)arg1)) {
    /* Handle error */
  }
  if(thrd_success
    != thrd_create(&thr2, AD_001_deposit, (void *)arg2)) {
    /* Handle error */
  }
  return 0;
}
