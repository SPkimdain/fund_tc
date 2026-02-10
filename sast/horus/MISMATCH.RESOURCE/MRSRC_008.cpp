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

/* MRSRC_008 - handle -> socket, return value */
HANDLE MRSRC_008_function1() {
  HANDLE data;
  /* Initialize data */
  data = INVALID_HANDLE_VALUE;
  data = CreateFile("BadSource_w32CreateFile.txt",
    (GENERIC_WRITE | GENERIC_READ),
    0,
    0,
    OPEN_ALWAYS,
    FILE_ATTRIBUTE_NORMAL,
    0);

  return data;
}

void MRSRC_008_function2(int flag) {
  HANDLE handle = MRSRC_008_function1();
  if(flag > 0) {
    if(handle != INVALID_HANDLE_VALUE) {
      close((int)handle); //@violation MISMATCH.RESOURCE
    }
  }
  else {
    if(handle != INVALID_HANDLE_VALUE) {
      CloseHandle(handle);
    }
  }
}

