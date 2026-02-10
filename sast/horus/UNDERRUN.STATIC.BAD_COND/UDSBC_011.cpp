

/* UDSBC_011 - monostate pattern */
class UDSBC_011_Class {
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

int UDSBC_011_Class::sharedValue[10] = { 0, };
int UDSBC_011_Class::index = 0;

void UDSBC_011_function1(int idx) {
  UDSBC_011_Class obj, obj2;
  if(idx > 0) { //[1, max]
    idx -= 5; //[-4, max]
    obj2.setIndex(idx);

    obj.doSomething(); //@violation UNDERRUN.STATIC.BAD_COND
  }

  if(idx > 0 && idx < 6) { //[min, 5]
    obj.setIndex(idx);

    obj2.doSomething(); //It's ok.
  }
}


