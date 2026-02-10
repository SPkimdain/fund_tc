//@checker REFER_ATOMIC_VARIABLE_MANY_TIMES_IN_EXPRESSION
/*
#ifdef _WIN32

#include <atomic>

#else

#include <stdatomic.h>
#include <stdbool.h>

#endif
*/

#ifndef __cplusplus
# include <stdatomic.h>
#else
# include <atomic>
# define _Atomic(X) std::atomic< X >
#endif

using namespace std;
   
static atomic_bool flag = ATOMIC_VAR_INIT(false);

atomic_int n = ATOMIC_VAR_INIT(0);


void init_flag(void) {
  atomic_init(&flag, false);
}
   
void toggle_flag(void) { 
  bool temp_flag = atomic_load(&flag);  //@violation REFER_ATOMIC_VARIABLE_MANY_TIMES_IN_EXPRESSION
  temp_flag = !temp_flag;
  atomic_store(&flag, temp_flag);
}
     
bool get_flag(void) {
  return atomic_load(&flag);
}


   