#include <stdio.h>

#ifdef _WIN32

#include <Windows.h>

extern int close(int filedes);

#else

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

/* MRSRC_016 - file -> handle, return vale */
FILE* MRSRC_016_function1() {
  FILE* file = fopen("test.txt", "w");
  return file;
}

void MRSRC_016_function2(HANDLE handle) {
  CloseHandle(handle);
}

void MRSRC_016_function3(int flag) {
  FILE* file = MRSRC_016_function1();
  if(file != 0) {
    MRSRC_016_function2(file); //@violation MISMATCH.RESOURCE
  }
}

