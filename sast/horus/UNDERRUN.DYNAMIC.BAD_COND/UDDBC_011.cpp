

/* UDDBC_011 - monostate pattern */
class UDDBC_011_Class {
public:
  void setArray(int* arr) {
    sharedValue = arr;
  }

  void setIndex(int x) {
    index = x;
  }
  void doSomething() {
    sharedValue[index] = 10; 
  }
private:
  static int* sharedValue;
  static int index;
};

int* UDDBC_011_Class::sharedValue = 0;
int UDDBC_011_Class::index = 0;

void UDDBC_011_function1(int idx) {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }

  UDDBC_011_Class obj, obj2;
  obj.setArray(arr);

  if(idx >= 0 && idx <= 10) { //[0, 10]
    obj2.setIndex(idx - 1);

    obj.doSomething(); //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  if(idx >= 0 && idx < 6) { //[0, 5]
    obj.setIndex(idx);

    obj2.doSomething(); //It's ok.
  }

  delete[] arr;
}


