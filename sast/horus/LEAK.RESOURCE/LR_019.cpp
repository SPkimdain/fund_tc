#include <stdlib.h>


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

#endif /* _WIN32 */

/* LR_019 - short circuit */
HANDLE LR_019_function1(char* fileName) {
  return CreateFile(fileName,
    (GENERIC_WRITE | GENERIC_READ), 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
}

HANDLE LR_019_function2() {
  HANDLE handle = LR_019_function1("5678.txt");
  int x = 10;
  int compareValue = 20;
  int ret = 0;

  if(handle != 0) {
    return 0; // LEAK.RESOURCE
  }//@violation LEAK.RESOURCE

  return 0;
}

