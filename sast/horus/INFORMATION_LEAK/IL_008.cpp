
/* IL_008 - class */

#include <stdio.h>
#include <stdlib.h>

class IL_008_Class {
public:
  IL_008_Class() : path(0) {}

  void setPath(char* name)  {
    path = getenv(name);
  }

  char* getPath() { return path; }

private:
  char* path;
};

void IL_008_function(char* buf){

  IL_008_Class obj;

  obj.setPath("path_name");

  sprintf(buf, "%s", obj.getPath()); //@violation INFORMATION_LEAK
}

