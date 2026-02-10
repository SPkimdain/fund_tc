
/* FNH_014 - class field */
class FNH_014_Class {
public:
  FNH_014_Class(int* v) : value(v) {}
  ~FNH_014_Class() {
    release();
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

class FNH_014_Class2 {
public:
  FNH_014_Class2(int* v) : obj(v) {}

  void doSomething() {
    obj.release();
  }

private:
  FNH_014_Class obj;
};

void FNH_014_function(int flag) {
  int* heapVal = new int(10);
  
  int localVal = 20;
  int* ptr = 0;

  if(flag > 0) {
    ptr = &localVal;
  }
  else {
    ptr = heapVal;
  }

  if(flag > 0) {
    FNH_014_Class2 obj(ptr);

    obj.doSomething(); //@violation FREE_NON_HEAP
    delete heapVal;
  }
  else {
    FNH_014_Class2 obj2(ptr);

    obj2.doSomething(); //It's ok.
  }
}
