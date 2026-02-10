#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DBZ_036 - strlen from opus */
void DBZ_036_function1(int n){
  char buf[10] = { 0, };
  int index = 0;
  if(fgets(buf, sizeof(buf), stdin) == 0){
    return;
  }

  if(n > 10){
    strcpy(buf, "abc");
  }
  index = strlen(buf);

  n = n - 10;
  if(n <= 0){
    index = 100 / index;  //@violation DIV_BY_ZERO
  }
  else {
    if(index > 0) {
      buf[index - 1] = '\0';
    }
  }
}

void DBZ_036_function2(void) {
  char buf[1024];
  char *p;

  if(fgets(buf, sizeof(buf), stdin)) {
    p = strchr(buf, '\n');
    if(p) {
      *p = '\0';
    }
  }
  else {
    /* Handle error */
  }
}
