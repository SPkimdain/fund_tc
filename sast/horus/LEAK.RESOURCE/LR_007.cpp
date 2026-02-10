#include <stdlib.h>

#define O_WRONLY 0x0004

#ifdef _WIN32

#include <Windows.h>

extern int open(const char* fileName, int access, int permissin);
extern int close(int filedes);

#else

#include <unistd.h>
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

#endif /* _WIN32 */ 

/* LR_007 - Function call, pointer parameter */
void LR_007_function1(int flag, int argfd) {
  if(flag == false) {
    close(argfd);
  }
  
  return; //LEAK.MEMORY
}

void LR_007_function2() {
  int fd = open("test.txt", O_WRONLY, 0644);
  LR_007_function1(false, fd); //It's ok. fd is released.

  fd = open("test2.txt", O_WRONLY, 0644);
  LR_007_function1(true, fd); 
}//@violation LEAK.RESOURCE
