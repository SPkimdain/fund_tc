#include <stdlib.h>

/* DF_002 - DOUBLE_FREE branch example. */
char* DF_002_function(int flag, char* p) {
  char * str = (char *)malloc(4);
  
  if(flag > 0){
    free(str);
  }
  if(flag > 10){
	return p;
  }
  else{
    free(str);//@violation DOUBLE_FREE
    return p; 
  }
}
