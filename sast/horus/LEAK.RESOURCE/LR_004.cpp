#include <stdlib.h>

#define O_WRONLY 0x0004

#ifdef _WIN32

extern int open(const char* fileName, int access, int permissin);

extern int close(int filedes);

#else

#include <unistd.h>
#include <fcntl.h>


#endif /* _WIN32 */ 

/* LR_004 - if branch2 */
void LR_004_function(int arg) {
  int fd = open("test.txt", O_WRONLY, 0644);
  
  if(fd == -1) {
    return;
  }

  if(arg == 10) {
    close(fd);
  }
  else { 
  }

  return; 
} //@violation LEAK.RESOURCE
