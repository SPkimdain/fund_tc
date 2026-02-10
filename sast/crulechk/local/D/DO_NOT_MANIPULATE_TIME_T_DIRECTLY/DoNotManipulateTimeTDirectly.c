// @checker DO_NOT_MANIPULATE_TIME_T_DIRECTLY
#define NULL 0

typedef long int time_t;

extern time_t time (time_t* timer);

int foo(int seconds_to_work){
  time_t start = time(NULL);
 
  if (start == (time_t)(-1)) {
    /* Handle error */
  }
  while (time(NULL) < start + seconds_to_work) {	//@violation DO_NOT_MANIPULATE_TIME_T_DIRECTLY
    /* ... */
  }
  return 0;
}
