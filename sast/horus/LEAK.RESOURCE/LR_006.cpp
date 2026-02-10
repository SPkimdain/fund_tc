#include <stdlib.h>

#define O_WRONLY 0x0004

#ifdef _WIN32

#include <Windows.h>

extern int open(const char* fileName, int access, int permissin);

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

/* LR_006 - Access field  */
struct LR_006_Struct {
  int value;
  int fd;
};

void LR_006_function(int arg) {
  LR_006_Struct ndStruct;
  ndStruct.value = 10;
  ndStruct.fd = open("test.txt", O_WRONLY, 0644);
  
  return;
} //@violation LEAK.RESOURCE
