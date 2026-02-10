#include <stdio.h>

/* LR_022 - object copy constructor */
class LR_022_Class {
public:
  LR_022_Class() : file(0) {}
  LR_022_Class(const LR_022_Class& rhs) {
    this->file = rhs.file;
  }

  void open(char* fileName) {
    if(file == 0) {
      file = fopen(fileName, "r");
    }
  }

  void close() {
    if(file != 0) {
      fclose(file);
    }
  }

private:
  FILE* file;
};

void LR_022_function1(LR_022_Class& obj) {
  obj.close();
}

int LR_022_function2(int flag) {
  LR_022_Class obj;
  obj.open("1234.txt");

  if(flag > 0) {
    LR_022_Class obj2(obj);
    LR_022_function1(obj); //obj, obj2 close.
    return 0;
  }

  return 1;
} //@violation LEAK.RESOURCE

