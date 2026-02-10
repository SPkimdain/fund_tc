#include <stdio.h>

#define O_WRONLY 0x0004

#ifdef _WIN32

#include <Windows.h>

extern int open(const char* fileName, int access, int permissin);
extern int close(int filedes);

#else

#include <unistd.h>
#include <fcntl.h>

#endif /* _WIN32 */

/* LR_027 - virtual function call */
class LR_027_Base {
public:
  LR_027_Base() : fd(-1) {}
  virtual ~LR_027_Base() {
    if(fd >= 0){
      close(fd);
    }
  }
  virtual void doSomethingVirtual(int _fd) {
    fd = _fd;
  }
private:
  int fd;
};

class LR_027_Derived : public LR_027_Base
{
public:
  LR_027_Derived() : LR_027_Base(), fd2(-1) {}
  ~LR_027_Derived() {
    //value2 is leaked.
  }
  virtual void doSomethingVirtual(int _fd) {
    fd2 = _fd;
  }
private:
  int fd2;
};

void LR_027_function() {
  LR_027_Base* inst1 = new LR_027_Base;
  LR_027_Base* inst2 = new LR_027_Derived;
  
  int fd = open("test.txt", O_WRONLY, 0644);
  int fd2 = open("5451234.txt", O_WRONLY, 0644);

  inst1->doSomethingVirtual(fd);
  inst2->doSomethingVirtual(fd2);

  delete inst1;
  delete inst2; 
  //fd2 is leaked.
}//@violation LEAK.RESOURCE

