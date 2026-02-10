#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32

#else

#include <unistd.h>

#endif 

/* PT_005 - simple case2 */
void PT_005_function(int flag) {
  char *rName = getenv("reportName");
  
  if(flag > 10) {
    FILE* file = fopen(rName, "w");   //@violation PATH_TRAVERSAL    
    
    fclose(file);
  }
  else {
    FILE* file = fopen("check.txt", "w"); //It's ok.

    fclose(file);
  }
}
