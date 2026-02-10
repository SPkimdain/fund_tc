#include <stdlib.h>

/* MMTDA_009 - field2 */
class MMTDA_009_Class {
public:
  MMTDA_009_Class() : value(0) {}

  void setValue(int* v) {
    value = v;
  }

  void release() {
    if(value != 0) {
      delete[] value;
      value = 0;
    }
  }

private:
  int* value;
};

class MMTDA_009_Class2 {
public:
  MMTDA_009_Class2() : obj() {}

  void transaction(int* data) {
    obj.setValue(data);

    obj.release(); //It's ok.
  }

private:
  MMTDA_009_Class obj;
};

void MMTDA_009_function(){
  MMTDA_009_Class2 obj2;
  int* data = new int[10];
  int* data2 = (int*)malloc(sizeof(int) * 5);

  obj2.transaction(data); //It's ok.
  obj2.transaction(data2); //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
}



