

/* UN_029 - monostate pattern */
class UN_029_Class {
public:
  void setValue1(int arg) {
    UN_029_Class::sharedValue = arg;
  }
  
  void setValue2(int& arg) {
    UN_029_Class::sharedValue2 = arg;
  }

  void accessSharedValue1() {
    int ret = sharedValue;
  }

  void accessSharedValue2() {
    int ret = sharedValue2;
  }
private:
  static int sharedValue;
  static int sharedValue2;
};

int UN_029_Class::sharedValue;
int UN_029_Class::sharedValue2;

void UN_029_function() {  
  UN_029_Class obj, obj2;
  int x;

  obj2.setValue1(10);

  obj.accessSharedValue1(); //It's ok.    
  
  obj.setValue2(x); //@violation UNINIT
}


