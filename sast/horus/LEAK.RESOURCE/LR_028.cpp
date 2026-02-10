
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

/* LR_028 - template initializer list */
template<typename T>
class LR_028_Class {
public:
  LR_028_Class(T& arg) : value(arg) {}

  T& getValue() { return value; }

private:
  T& value;
};

HANDLE LR_028_function(bool flag) {
  if(flag == true) {
    HANDLE dataX = CreateFile("1234.txt",
      (GENERIC_WRITE | GENERIC_READ), 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if(dataX == INVALID_HANDLE_VALUE) {
      return INVALID_HANDLE_VALUE;
    }

    LR_028_Class<HANDLE> obj(dataX);
    
    return obj.getValue();
     
  }//@violation LEAK.RESOURCE

  return INVALID_HANDLE_VALUE;
}
