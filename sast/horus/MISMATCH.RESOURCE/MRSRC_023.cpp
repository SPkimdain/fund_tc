#include <stdio.h>

#define O_WRONLY 0x0004

#ifdef _WIN32

#include <Windows.h>

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

typedef void * HANDLE;


#define CreateFile CreateFileA

extern HANDLE CreateFileA(const char *, unsigned int, unsigned int, void *, unsigned int,
  unsigned int, void *);
extern bool CloseHandle(HANDLE hObject);

extern int close(int filedes);

#endif /* _WIN32 */ 

/* MRSRC_023 - socket -> handle, field */
class MRSRC_023_Class {
public:
  MRSRC_023_Class() : handle(0) {}
  int MRSRC_023_function1() {
    int fd = open("test.txt", O_WRONLY, 0644);
    return fd;
  }

  void MRSRC_023_function2() {
    CloseHandle(handle);
  }

  void MRSRC_023_function3(int fd) {
    close(fd); //It's ok.
  }

  void MRSRC_023_function4(int flag) {
    int fd = MRSRC_023_function1();
    handle = (HANDLE)fd;
    if(fd >= 0) {
      if(flag > 0) {
        MRSRC_023_function2(); //@violation MISMATCH.RESOURCE
        return;
      }
      else {
        MRSRC_023_function3(fd); //It's ok.
        return;
      }
    }
  }
private:
  HANDLE handle;
};

