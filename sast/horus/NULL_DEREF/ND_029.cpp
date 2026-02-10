

/* ND_029 - monostate pattern */
class ND_029_Class {
public:
  void setValue(int* x) {
    sharedValue = x;
  }
  void doSomething() {
    *sharedValue = 10;
  }
private:
  static int* sharedValue;
};

int* ND_029_Class::sharedValue = 0;

void ND_029_function() {
  int* x = new int();
  *x = 10;
  ND_029_Class obj, obj2;
  obj.setValue(x);

  obj.doSomething(); //It's ok.

  obj2.setValue(0);

  obj.doSomething(); //@violation NULL_DEREF

  delete x;
}


