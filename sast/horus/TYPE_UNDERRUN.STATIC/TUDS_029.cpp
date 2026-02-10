

/* TUDS_029 - monostate pattern */
class TUDS_029_Class {
public:
  TUDS_029_Class() {}
  void setIndex(int x) {
    index = x;
  }

  void doSomething() {
    sharedValue[index] = 10;
  }

private:
  int sharedValue[10];
  
  static int index;
};

int TUDS_029_Class::index = 0;

void TUDS_029_function() {
  TUDS_029_Class obj, obj2;
  obj.setIndex(5);

  obj.doSomething(); //It's ok.

  obj2.setIndex(-10);

  obj.doSomething(); //@violation TYPE_UNDERRUN.STATIC

}


