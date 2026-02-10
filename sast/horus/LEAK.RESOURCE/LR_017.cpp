#include <stdio.h>

/* LR_017 - field assign */
template<typename T>
class LR_017_Class {
public:
  LR_017_Class(T v) : value(v), file(0) {}
  ~LR_017_Class() {
    if(file != 0) {
      fclose(file);
    }
  }

  void open(char* fileName) {
    /* Missing check the exist fp. */
    file = fopen(fileName, "r");
  }

  void setValue(T val) {
    value = val;
  }


private:
  T value;
  FILE* file;
};


void LR_017_function(int flag, int flag2) {
  if(flag > 0) {
    LR_017_Class<int> obj(10);
    obj.open("file.txt");
    
    obj.setValue(1000);
  } //It's ok.
  else {
    LR_017_Class<char> obj2('x');
    obj2.open("file2.txt");

    if(flag2 != 0) {
      obj2.open("file3.txt"); 
    }
  } //Call dtor.

  return;
} //@violation LEAK.RESOURCE

