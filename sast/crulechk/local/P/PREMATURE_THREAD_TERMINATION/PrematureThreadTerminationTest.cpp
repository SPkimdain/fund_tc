//@checker PREMATURE_THREAD_TERMINATION

#include "posix_headers.h"

pthread_t t;

extern void* start_function(void* arg);

void PMTTT_001_functionB()  //@violation PREMATURE_THREAD_TERMINATION
{
  pthread_attr_t attr;
  void* arg = 0;
	pthread_create(&t, &attr, start_function, arg);  //@b-violation PREMATURE_THREAD_TERMINATION
}
