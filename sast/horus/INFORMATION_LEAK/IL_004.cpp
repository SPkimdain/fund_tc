
/* IL_004 - function return */

#include <stdio.h>
#include <stdlib.h>

char* IL_004_function(char* alter, bool flag2){
  if(flag2 == true) {
    return getenv("PATH");
  }
  else {
    return alter;
  }
}

void IL_004_function2(char* alter, int flag) {
  char* ret = 0;

  if(flag > 10) {
    ret = IL_004_function(alter, false);
  }
  else {
    ret = IL_004_function(alter, true);
  }

  char buf[256] = { 0, };
  sprintf(buf, "%s", ret); //@violation INFORMATION_LEAK
}
