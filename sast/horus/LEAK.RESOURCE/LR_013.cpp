#include <stdlib.h>

#define O_WRONLY 0x0004

#ifdef _WIN32

extern int open(const char* fileName, int access, int permissin);

#else

#include <unistd.h>
#include <fcntl.h>

#endif /* _WIN32 */ 

/* LR_013 - for2 */
void LR_013_function(int value, int value2) {
  int p = 100;
  int fd = 0;

  for(int i = 0; i < 2; i++) {
    if(value > 10) { // True or False
      if(value2 > 5) { // True or False
        fd = open("1234.txt", O_WRONLY, 0644);
      } 
    }
  }
}//@violation LEAK.RESOURCE
