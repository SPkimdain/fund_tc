/* PT_003 - open */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#ifdef _WIN32

#include <io.h>
# define OPEN _open
# define CLOSE _close
#define O_RDWR 1

#else

#include <sys/stat.h> 
#include <fcntl.h>

#define O_RDWR 1

#define OPEN open
#define CLOSE close

#endif

int PT_003_function(){
  char *rName = getenv("reportName");
  char buf[256];

  strcpy(buf, rName); //propagation

  int fd = OPEN(buf, O_RDWR);   //@violation PATH_TRAVERSAL

  return fd;
}
