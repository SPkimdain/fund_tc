

/* UAF_029 - monostate pattern */
class UAF_029_Class {
public:
  void releaseValue() {
    delete sharedValue;
  }
  void doSomething() {
    *sharedValue = 10;
  }
private:
  static int* sharedValue;
};

int* UAF_029_Class::sharedValue = new int(10);

void UAF_029_function() {
  int* x = new int();
  *x = 10;
  UAF_029_Class obj, obj2;

  obj.doSomething(); //It's ok.

  obj2.releaseValue();

  obj.doSomething(); //@violation USE_AFTER_FREE

  delete x;
}
