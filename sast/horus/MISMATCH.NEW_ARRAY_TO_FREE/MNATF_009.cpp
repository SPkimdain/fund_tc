#include <stdlib.h>

/* MNATF_009 - field2 */
class MNATF_009_Class {
public:
  MNATF_009_Class() : value(0) {}

  void setValue(int* v) {
    value = v;
  }

  void release() {
    if(value != 0) {
      free(value);
      value = 0;
    }
  }

private:
  int* value;
};

class MNATF_009_Class2 {
public:
  MNATF_009_Class2() : obj() {}

  void transaction(int* data) {
    obj.setValue(data);

    obj.release(); //It's ok.
  }

private:
  MNATF_009_Class obj;
};

void MNATF_009_function(){
  MNATF_009_Class2 obj2;
  int* data = (int*)malloc(sizeof(int) * 5);
  int* data2 = new int[5];

  obj2.transaction(data); //It's ok.
  obj2.transaction(data2); //@violation MISMATCH.NEW_ARRAY_TO_FREE
}



