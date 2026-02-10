#include <stdlib.h>
/* DF_003 - DOUBLE_FREE array */


char* DF_003_function(int flag, char* p) {
  char* str[2];
  str[0] = (char *)malloc(10);
  str[1] = (char *)malloc(5);
  
  if(flag > 10){
    free(str[1]);	
  }
  free(str[0]);
  free(str[1]); //@violation DOUBLE_FREE
  return p;
}

