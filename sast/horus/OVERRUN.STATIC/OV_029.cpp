

/* OV_029 - monostate pattern */
class OV_029_Class {
public:
  void setIndex(int x) {
    index = x;
  }
  void doSomething() {
    sharedValue[index] = 10;
  }
private:
  static int sharedValue[10];
  static int index;
};

int OV_029_Class::sharedValue[10] = { 0, };
int OV_029_Class::index = 0;

void OV_029_function() {
  OV_029_Class obj, obj2;
  obj.setIndex(5);

  obj.doSomething(); //It's ok.

  obj2.setIndex(10);

  obj.doSomething(); //@violation OVERRUN.STATIC

}


