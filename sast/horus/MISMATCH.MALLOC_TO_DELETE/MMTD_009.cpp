#include <stdlib.h>

/* MMTD_009 - field2 */
class MMTD_009_Class {
public:
  MMTD_009_Class() : value(0) {}

  void setValue(int* v) {
    value = v;
  }

  void release() {
    if(value != 0) {
      delete value;
      value = 0;
    }
  }

private:
  int* value;
};

class MMTD_009_Class2 {
public:
  MMTD_009_Class2() : obj() {}

  void transaction(int* data) {
    obj.setValue(data);

    obj.release(); //It's ok.
  }

private:
  MMTD_009_Class obj;
};

void MMTD_009_function(){
  MMTD_009_Class2 obj2;
  int* data = new int(10);
  int* data2 = (int*)malloc(sizeof(int) * 5);

  obj2.transaction(data); //It's ok.
  obj2.transaction(data2); //@violation MISMATCH.MALLOC_TO_DELETE
}



