

/* TUDBC_011 - monostate pattern */
class TUDBC_011_Class {
public:
  TUDBC_011_Class() {}

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

int TUDBC_011_Class::index = 0;

void TUDBC_011_function1(int idx) {
  TUDBC_011_Class obj, obj2;
  if(idx > 0) { //[1, max]
    obj2.setIndex(idx - 2);

    obj.doSomething(); //@violation TYPE_UNDERRUN.BAD_COND
  }

  if(idx < 6) { //[0, 5]
    obj.setIndex(idx);

    obj2.doSomething(); //It's ok.
  }
}


