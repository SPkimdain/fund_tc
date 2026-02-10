
/* IL_005 - function call by reference */

#include <stdio.h>
#include <stdlib.h>

void IL_005_function(char** out){
  *out = getenv("PATH");  
}

void IL_005_function2() {
  char* target = 0;
  
  IL_005_function(&target);

  char buf[256] = { 0, };
  sprintf(buf, "%s", target); //@violation INFORMATION_LEAK
}

