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

/* LR_003 - if branch1 */
void LR_003_function(int arg) {
  HANDLE data = CreateFile("BadSource_w32CreateFile.txt",
    (GENERIC_WRITE | GENERIC_READ), 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
  
  if(data == INVALID_HANDLE_VALUE) {
    return;
  }

  if(arg == 10) {
    CloseHandle(data);
  }
  else {
    return; 
  } //@violation LEAK.RESOURCE

}
