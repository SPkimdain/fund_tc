
/* IL_006 - switch branch */

#include <stdio.h>
#include <stdlib.h>

int IL_006_function(char* buf, int flag, char* alter){
  int ret = 0;
  char* path = getenv("PATH");
  char* target = 0;

  switch(flag) {
  case 0:
    ret++;
    break;
  case 1:
    ret += 2;
    break;
  case 2:
    ret += 4;
    break;

  case 3:
    ret += 8;
    target = alter;
    break;

  case 4:
    ret += 16;
    target = path;
    break;
  default:
    ret += 32;
    break;
  }

  if(target != 0) {
    sprintf(buf, "%s", target); //@violation INFORMATION_LEAK
  }

  return ret;
}

