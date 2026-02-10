

/* OSBC_011 - monostate pattern */
class OSBC_011_Class {
public:
  void setIndex(unsigned x) {
    index = x;
  }
  void doSomething() {
    sharedValue[index] = 10; 
  }
private:
  static int sharedValue[10];
  static unsigned int index;
};

int OSBC_011_Class::sharedValue[10] = { 0, };
unsigned int OSBC_011_Class::index = 0;

void OSBC_011_function1(unsigned idx) {
  OSBC_011_Class obj, obj2;
  if(idx <= 10) { //[0, 10]
    obj2.setIndex(idx);

    obj.doSomething(); //@violation OVERRUN.STATIC.BAD_COND
  }

  if(idx < 6) { //[0, 5]
    obj.setIndex(idx);

    obj2.doSomething(); //It's ok.
  }
}


