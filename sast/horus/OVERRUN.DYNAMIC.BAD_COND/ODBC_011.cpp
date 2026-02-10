

/* ODBC_011 - monostate pattern */
class ODBC_011_Class {
public:
  void setArray(int* arr) {
    sharedValue = arr;
  }

  void setIndex(unsigned x) {
    index = x;
  }
  void doSomething() {
    sharedValue[index] = 10; 
  }
private:
  static int* sharedValue;
  static unsigned int index;
};

int* ODBC_011_Class::sharedValue = 0;
unsigned int ODBC_011_Class::index = 0;

void ODBC_011_function1(unsigned idx) {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }

  ODBC_011_Class obj, obj2;
  obj.setArray(arr);

  if(idx <= 10) { //[0, 10]
    obj2.setIndex(idx);

    obj.doSomething(); //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  if(idx < 6) { //[0, 5]
    obj.setIndex(idx);

    obj2.doSomething(); //It's ok.
  }

  delete[] arr;
}


