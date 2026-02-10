#include <stdio.h>

#ifdef _WIN32

#include <Windows.h>

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

/* MRSRC_013 - handle -> file, passing argument */
HANDLE MRSRC_013_function1() {
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

void MRSRC_013_function2(FILE* file) {
  fclose(file);
}

void MRSRC_013_function3() {
  HANDLE handle = MRSRC_013_function1();
  
  FILE* file = (FILE*)handle;
  
  if(handle != INVALID_HANDLE_VALUE) {
    MRSRC_013_function2(file);  //@violation MISMATCH.RESOURCE
  }
}

