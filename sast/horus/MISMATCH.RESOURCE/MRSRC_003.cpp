#include <stdio.h>

#ifdef _WIN32

extern int close(int filedes);

#else

extern int close(int filedes);

#endif /* _WIN32 */ 

/* MRSRC_003 - file -> socket */
void MRSRC_003_function() {
  FILE* file = fopen("test.txt", "w");
  if(file != 0) {
    close((int)file); //@violation MISMATCH.RESOURCE
  }
}

