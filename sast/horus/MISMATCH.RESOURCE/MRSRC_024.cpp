#include <stdio.h>

#define O_WRONLY 0x0004

#ifdef _WIN32

extern int open(const char* fileName, int access, int permissin);
extern int close(int filedes);

#else

#include <sys/stat.h> 
#include <fcntl.h>

#define GENERIC_WRITE 0x1
#define GENERIC_READ 0x2
#define OPEN_ALWAYS 0
#define FILE_ATTRIBUTE_NORMAL 0
#define INVALID_HANDLE_VALUE (HANDLE)(long)-1
#define O_WRONLY 0

typedef void * HANDLE;


#define CreateFile CreateFileA

extern HANDLE CreateFileA(const char *, unsigned int, unsigned int, void *, unsigned int,
  unsigned int, void *);
extern bool CloseHandle(HANDLE hObject);

extern int close(int filedes);

#endif /* _WIN32 */ 

/* MRSRC_024 - socket -> file, field */
class MRSRC_024_Class {
public:
  MRSRC_024_Class() : file(0) {}

  int MRSRC_024_function1() {
    int fd = open("test.txt", O_WRONLY, 0644);
    return fd;
  }

  void MRSRC_024_function2() {
    fclose(file);
  }

  void MRSRC_024_function3(int fd) {
    close(fd);
  }

  void MRSRC_024_funciton4(int flag) {
    int fd = MRSRC_024_function1();
    if(fd == -1) {
      return;
    }

    if(flag > 0) {
      file = (FILE*)fd;
      MRSRC_024_function2(); //@violation MISMATCH.RESOURCE
      return;
    }
    else {
      MRSRC_024_function3(fd); //It's ok.
      return;
    }
  }
private:
  FILE* file;
};
