
/* IL_007 - function return2 */

#include <stdio.h>
#include <stdlib.h>

char* IL_007_function(){
  char* path = getenv("PATH");
  
  return path;
}

char* IL_007_function2(int flag) {
  if(flag > 100) {
    return IL_007_function();
  }

  return 0;
}

void IL_007_function3(char* buf, char* alter, int flag) {
  char* target = 0;

  target = IL_007_function2(flag);
  if(target == 0) {
    target = alter;
    sprintf(buf, "%s", target); //It's ok.
  }
  else {
    sprintf(buf, "%s", target); //@violation INFORMATION_LEAK
  }  
}
