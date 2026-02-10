/* PT_004 - trace taint.  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32

#else

#include <unistd.h>

#endif 

char* PT_004_function() {
  char *rName = getenv("reportName");

  return rName;
}


char* PT_004_function2(int flag) {
  if(flag == 0) {
    return 0;
  }
  char* ret = PT_004_function();

  return ret;
}

void PT_004_function3(int flag){  
  char buf[256];

  if(flag > 10) {
    char* target = PT_004_function2(1);

    strcpy(buf, target);

    unlink(buf);   //@violation PATH_TRAVERSAL
  }
}
