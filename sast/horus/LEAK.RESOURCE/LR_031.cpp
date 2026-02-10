#include <stdlib.h>
#include <iostream>

using namespace std;

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

/* LR_031 - complex */
enum class LR_031_Type { SYMBOL, REGION, VALUE, NONE };

class LR_031_Class {
public:
  LR_031_Class() : record(false), state(0), handle(INVALID_HANDLE_VALUE) {}

  HANDLE nxOpen(const char* str, bool force, int threshold, int threshold2);
  
  int process(LR_031_Type type, const char* fileName, int flag, const char* regionStr);
  
  int checkFlag(int flag);
  
  int saveHandle(HANDLE h);
  int saveHandleWithCheck(HANDLE h);
  
  void setRecord(bool r) {
    record = r;
  }

  bool release(HANDLE h);

private:
  static HANDLE create(const char* str);

private:
  bool record;
  int state;
  HANDLE handle;
};

HANDLE LR_031_Class::create(const char* str) {
  if(str == 0) {
    return INVALID_HANDLE_VALUE;
  }

  return CreateFile(str, (GENERIC_WRITE | GENERIC_READ), 
    0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
}

HANDLE LR_031_Class::nxOpen(const char* str, bool force, int threshold, int threshold2) {
  HANDLE data = INVALID_HANDLE_VALUE;

  if(threshold > 100 || threshold2 > 50) {
    return INVALID_HANDLE_VALUE;
  }

  data = LR_031_Class::create(str);

  if(data == INVALID_HANDLE_VALUE) {
    cout << "Failed.";
    return INVALID_HANDLE_VALUE;
  }

  if(force == true) {
    cout << "Check.";
    state = 1;
  }

  cout << "Succeed.";
  return data;
}

int LR_031_Class::process(LR_031_Type type, const char* fileName, int flag, const char* regionStr) {
  if(fileName == 0) {
    return -1;
  }

  HANDLE h = nxOpen("Test.txt", true, 80, 40);
  
  HANDLE h2 = nxOpen("Dummy.txt", true, 150, 20); // INVALID_HANDLE_VALUE

  state++;
 
  state += checkFlag(flag);

  if(state == 1) {
    saveHandle(h); //Impossible path.
    cout << state;
  }
  else {
    setRecord(true); //Wrong set flag.

    saveHandleWithCheck(h);

    switch(type) {
    case LR_031_Type::SYMBOL:
      state++;
      break;

    case LR_031_Type::REGION:
      state += 2;

      if(strcmp(regionStr, "CheckRegion") != 0) {
        cout << "Wrong regionStr.";
        return 1;
      } //@violation LEAK.RESOURCE
      break;

    case LR_031_Type::VALUE:
      state += 5;
      break;

    default:
      state = 0;
      break;
    }

    release(h);
  }

  return state;
} 

int LR_031_Class::checkFlag(int flag) {
  if(flag < 0) {
    flag = 2;
  }

  flag++;

  return flag;
}

int LR_031_Class::saveHandle(HANDLE h) {
  if(handle == INVALID_HANDLE_VALUE) {
    return 1;
  }

  handle = h;

  return 0;
}

int LR_031_Class::saveHandleWithCheck(HANDLE h) {
  if(handle == INVALID_HANDLE_VALUE) {
    return 1;
  }

  if(record == false) {
    handle = h;
    
    record = true;
  }

  return 0;
}

bool LR_031_Class::release(HANDLE h) {
  CloseHandle(h);

  return 0;
}
