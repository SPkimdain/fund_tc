

/* TOBC_011 - monostate pattern */
class TOBC_011_Class {
public:
  TOBC_011_Class() {}

  void setIndex(unsigned x) {
    index = x;
  }
  void doSomething() {
    sharedValue[index] = 10; 
  }
private:
  int sharedValue[10];
  static unsigned int index;
};

unsigned int TOBC_011_Class::index = 0;

void TOBC_011_function1(unsigned idx) {
  TOBC_011_Class obj, obj2;
  if(idx <= 10) { //[0, 10]
    obj2.setIndex(idx);

    obj.doSomething(); //@violation TYPE_OVERRUN.BAD_COND
  }

  if(idx < 6) { //[0, 5]
    obj.setIndex(idx);

    obj2.doSomething(); //It's ok.
  }
}


