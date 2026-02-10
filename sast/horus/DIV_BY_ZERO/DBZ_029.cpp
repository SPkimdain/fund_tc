

/* DBZ_029 - monostate pattern */
class DBZ_029_Class {
public:
  void setValue(int x) {
    sharedValue = x;
  }
  int doSomething() {
    return 10000 / sharedValue;  //violation.
  }
private:
  static int sharedValue;
};

int DBZ_029_Class::sharedValue = 0;

void DBZ_029_function() {
  int ret = 0;
  DBZ_029_Class obj, obj2;
  obj.setValue(10);

  ret = obj.doSomething(); //It's ok.

  obj2.setValue(0);

  ret = obj.doSomething(); //@violation DIV_BY_ZERO

}


