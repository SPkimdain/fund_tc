#include <stdio.h>

#ifdef _WIN32

extern int close(int filedes);

#else

extern int close(int filedes);

#endif /* _WIN32 */ 

/* MRSRC_021 - file -> socket, field */
class MRSRC_021_Class {
public:
  MRSRC_021_Class() : fd(-1) {}

  FILE* MRSRC_021_function1() {
    FILE* file = fopen("test.txt", "w");
    return file;
  }

  void MRSRC_021_function2() {
    close(fd);
  }

  void MRSRC_021_funciton3(int flag) {
    FILE* file = MRSRC_021_function1();
    fd = (int)file;
    if(file != 0) {
      MRSRC_021_function2(); //@violation MISMATCH.RESOURCE
    }
  }
private:
  int fd;
};
