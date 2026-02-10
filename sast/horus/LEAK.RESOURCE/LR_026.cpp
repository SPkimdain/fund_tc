
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

/* LR_026 - complex trace handle */
struct LR_026_Struct {
public:
  LR_026_Struct() : isOpen(false), fileName(0), handle(0) {}
  bool isOpen;
  char* fileName;
  HANDLE handle;
};

class LR_026_Class {
public:
  LR_026_Class() : file() {}

  void setFileInfo(LR_026_Struct& f) {
    file = f;
  }

  void close() {
    if(file.isOpen == false) { //Wrong check.
      CloseHandle(file.handle);
    }
  }

private:
  LR_026_Struct file;
};


int LR_026_function(char* fileName, int flag) {
  LR_026_Struct fileInfo;
  if(fileName != 0) {
    fileInfo.fileName = fileName;
    fileInfo.handle = CreateFile(fileInfo.fileName,
      (GENERIC_WRITE | GENERIC_READ), 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    fileInfo.isOpen = true;
  }

  if(flag > 0) {
    LR_026_Class obj;
    obj.setFileInfo(fileInfo);

    obj.close();
    return 0;
  } //@violation LEAK.RESOURCE
  else {
    CloseHandle(fileInfo.handle);
  }
  return 1;

}

