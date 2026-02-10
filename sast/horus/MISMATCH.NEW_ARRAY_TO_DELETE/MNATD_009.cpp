#include <stdlib.h>

/* MNATD_009 - field2 */
class MNATD_009_Class {
public:
  MNATD_009_Class() : value(0) {}

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

class MNATD_009_Class2 {
public:
  MNATD_009_Class2() : obj() {}

  void transaction(int* data) {
    obj.setValue(data);

    obj.release(); //It's ok.
  }

private:
  MNATD_009_Class obj;
};

void MNATD_009_function(){
  MNATD_009_Class2 obj2;
  int* data = new int(10);
  int* data2 = new int[10];

  obj2.transaction(data); //It's ok.
  obj2.transaction(data2); //@violation MISMATCH.NEW_ARRAY_TO_DELETE
}



