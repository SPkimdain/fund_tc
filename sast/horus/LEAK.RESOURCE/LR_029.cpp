#include <stdlib.h>
#include <stdio.h>

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

struct LR_029_Struct {
  bool hasFd;
  int fd;
};

extern void LR_029_function1(LR_029_Struct* obj);

/* LR_029 - return base structure */

LR_029_Struct* LR_029_function2(char* name, int flag) {
  LR_029_Struct* obj = 0;
  obj = (LR_029_Struct*)malloc(sizeof(LR_029_Struct));
  int x = 0;

  if(obj == 0) {
    return 0;
  }
  obj->fd = 0;
  obj->hasFd = false;
  
  if((obj->fd = open(name, O_WRONLY, 0644)) == -1) goto err;
  obj->hasFd = true;

  if(flag > 0) {
    x++;
  }

  x++;

  LR_029_function1(obj);

  x++;
  
  return obj; //It's ok. base structure is returned.
  
err:
  free(obj);
  return 0;
    
}

LR_029_Struct* LR_029_function3(char* name, int flag) {
  LR_029_Struct* obj = 0;
  obj = (LR_029_Struct*)malloc(sizeof(LR_029_Struct));

  if(obj == 0) {
    return 0;
  }
  obj->fd = 0;
  obj->hasFd = false;

  if((obj->fd = open(name, O_WRONLY, 0644)) == -1) goto err;

  free(obj);
  return 0; //Leak fd.

err:
  free(obj);
  return 0;

} //@violation LEAK.RESOURCE
