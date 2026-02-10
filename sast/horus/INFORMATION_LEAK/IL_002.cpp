
/* IL_002 - simple case2 */

#include <stdio.h>
#include <stdlib.h>

void IL_002_function(){
  char* path = getenv("PATH");
  char buf[256] = { 0, };
  sprintf(buf, "%s", path); //@violation INFORMATION_LEAK
}

