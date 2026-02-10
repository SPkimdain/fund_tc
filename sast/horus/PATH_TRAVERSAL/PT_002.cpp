/* PT_002 - propagation */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32

#else

#include <unistd.h>

#endif 


void PT_002_function(){
  char *rName = getenv("reportName");   
  char buf[256];

  strcpy(buf, rName);

  unlink(buf);   //@violation PATH_TRAVERSAL
}
