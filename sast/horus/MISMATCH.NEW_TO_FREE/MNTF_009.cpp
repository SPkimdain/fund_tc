#include <stdlib.h>

/* MNTF_009 - field2 */
class MNTF_009_Class {
public:
  MNTF_009_Class() : value(0) {}

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

class MNTF_009_Class2 {
public:
  MNTF_009_Class2() : obj() {}

  void transaction(int* data) {
    obj.setValue(data);

    obj.release(); //It's ok.
  }

private:
  MNTF_009_Class obj;
};

void MNTF_009_function(){
  MNTF_009_Class2 obj2;
  int* data = (int*)malloc(sizeof(int) * 10);
  int* data2 = new int(10);

  obj2.transaction(data); //It's ok.
  obj2.transaction(data2); //@violation MISMATCH.NEW_TO_FREE
}



