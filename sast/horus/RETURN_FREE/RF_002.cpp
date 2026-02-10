#include <stdlib.h>
/* RF_002 - RETURN_FREE multiple return */


char* RF_002_function(int flag, char* p) {
  char * str = (char *)malloc(4);
  
  if(flag > 10){
    free(str);
  }
  if(flag > 0){
	return str; //@violation RETURN_FREE
  }
  else{
    free(str);
    return p;
  }
}

