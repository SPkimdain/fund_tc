//@checker CALL_UNINIT_VAR_WITH_CONST

#include <string.h>
#include <stdlib.h>
void foo(char *g_lat, int some){
  char temp_lat[30];
  char *endptr;
  if(some){
    strncpy(temp_lat, g_lat, strlen(g_lat) -1);
  }else{
    strncpy(temp_lat, g_lat, strlen(g_lat));
  }

  double llat = strtod(temp_lat, &endptr);
}