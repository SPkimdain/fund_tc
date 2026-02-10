
/* IL_009 - class2 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

class IL_009_Class {
public:
  IL_009_Class() : path(0), buf() {}

  void setPath(char* name)  {
    path = getenv(name);
  }

  char* getPath() { return path; }

  char* getBuf() {
    memset(buf, 256, 0);

    return buf;
  }


private:
  char* path;
  char buf[256];
};

void IL_009_function(){

  IL_009_Class obj;

  obj.setPath("path_name");

  sprintf(obj.getBuf(), "test: %s", obj.getPath()); //@violation INFORMATION_LEAK
}


