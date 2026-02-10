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

/* LR_008 - Function call, return value */
HANDLE LR_008_function1() {
  return CreateFile("create.txt",
    (GENERIC_WRITE | GENERIC_READ), 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
}

void LR_008_function2() {
  HANDLE hd1 = LR_008_function1();
  HANDLE hd2 = LR_008_function1();

  free(hd1);

  return; 
  //hd2 leak.
}//@violation LEAK.RESOURCE
