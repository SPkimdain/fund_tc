
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


/* LR_024 - constructor */
class LR_024_Class{
public:
  LR_024_Class(HANDLE _ptr1) {
    ptr1 = _ptr1;
  }
  ~LR_024_Class() {
    CloseHandle(ptr1);
  }
  
private:
  HANDLE ptr1;
};

void LR_024_function(bool flag) {
  if(flag == true) {

    HANDLE dataX = CreateFile("1234.txt",
      (GENERIC_WRITE | GENERIC_READ), 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if(dataX == INVALID_HANDLE_VALUE) {
      return;
    }

    HANDLE dataY = CreateFile("BadSource_w32CreateFile.txt",
      (GENERIC_WRITE | GENERIC_READ), 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if(dataY == INVALID_HANDLE_VALUE) {
      CloseHandle(dataX);
      return;
    }
    
    LR_024_Class obj(dataX);    
    //dataX is released by destructor.
    //dataY is leaked.
   } 
} //@violation LEAK.RESOURCE
