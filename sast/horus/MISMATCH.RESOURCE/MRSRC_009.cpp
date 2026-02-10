#include <stdio.h>

#ifdef _WIN32

extern int close(int filedes);

#else

extern int close(int filedes);

#endif /* _WIN32 */ 

/* MRSRC_009 - file -> socket, return value */
FILE* MRSRC_009_function1() {
  FILE* file = fopen("test.txt", "w");
  return file;
}

void MRSRC_009_funciton2(int flag) {
  FILE* file = MRSRC_009_function1();
  if(flag > 0) {
    if(file != 0) {
      close((int)file); //@violation MISMATCH.RESOURCE
    }
  }
  else {
    if(file != 0) {
      fclose(file); //It's ok.
    }
  }
}

