#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32

#else

#include <unistd.h>

#endif 

/* PT_001 - simple case */
void PT_001_function(){
  char *rName = getenv("reportName");   
  unlink(rName);   //@violation PATH_TRAVERSAL
}
