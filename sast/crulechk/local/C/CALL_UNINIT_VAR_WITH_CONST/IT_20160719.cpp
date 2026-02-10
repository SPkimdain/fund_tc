//@checker CALL_UNINIT_VAR_WITH_CONST

#include <string.h>
#include <stdlib.h>
void foo(char *g_lat, int some){
  char temp_lat[30];
  char *endptr;
  if(some){
    temp_lat[0] = 'a';
  }else{
    temp_lat[0] = 'b';
  }

  double llat = strtod(temp_lat, &endptr);
}