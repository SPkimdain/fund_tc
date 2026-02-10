#include <stdio.h>

#ifdef _WIN32

extern int close(int filedes);

#else

extern int close(int filedes);

#endif /* _WIN32 */ 

/* MRSRC_015 - file -> socket, return value */
FILE* MRSRC_015_function1() {
  FILE* file = fopen("test.txt", "w");
  return file;
}

void MRSRC_015_function2(int fd) {
  close(fd);
}

void MRSRC_015_funciton3(int flag) {
  FILE* file = MRSRC_015_function1();
  int fd = (int)file;
  if(file != 0) {
    MRSRC_015_function2(fd); //@violation MISMATCH.RESOURCE
  }  
}

