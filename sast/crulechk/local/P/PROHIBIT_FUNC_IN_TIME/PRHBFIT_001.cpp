//@checker PROHIBIT_FUNC_IN_TIME
#include <stdio.h>
#include <time.h> //@violation PROHIBIT_FUNC_IN_TIME

void PRHBFIT_001_function (){
  time_t timer;
  timer = time(NULL); 
}
