
/* IL_010 - array */

#include <stdio.h>
#include <stdlib.h>

void IL_010_function(char* buf){
  char* path = getenv("PATH");
  
  char* arr[2] = { 0, };
  
  arr[0] = buf;
  arr[1] = path;

  sprintf(arr[0], "%s", arr[1]); //@violation INFORMATION_LEAK
}


