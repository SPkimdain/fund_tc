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

/* MRSRC_004 - file -> handle */
void MRSRC_004_function() {
  FILE* file = fopen("test.txt", "w");
  if(file != 0) {
    CloseHandle(file); //@violation MISMATCH.RESOURCE
  }
}

