#include <stdlib.h>

/* MNTDA_009 - field2 */
class MNTDA_009_Class {
public:
  MNTDA_009_Class() : value(0) {}

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

class MNTDA_009_Class2 {
public:
  MNTDA_009_Class2() : obj() {}

  void transaction(int* data) {
    obj.setValue(data);

    obj.release(); //It's ok.
  }

private:
  MNTDA_009_Class obj;
};

void MNTDA_009_function(){
  MNTDA_009_Class2 obj2;
  int* data = new int[10];
  int* data2 = new int(10);

  obj2.transaction(data); //It's ok.
  obj2.transaction(data2); //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}



