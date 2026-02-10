

/* UDS_029 - monostate pattern */
class UDS_029_Class {
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

int UDS_029_Class::sharedValue[10] = { 0, };
int UDS_029_Class::index = 0;

void UDS_029_function() {
  UDS_029_Class obj, obj2;
  obj.setIndex(5);

  obj.doSomething(); //It's ok.

  obj2.setIndex(-1);

  obj.doSomething(); //@violation UNDERRUN.STATIC

}


