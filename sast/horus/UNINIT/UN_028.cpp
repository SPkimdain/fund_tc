#pragma warning(disable : 4700)

/* UN_028 - singleton pattern */
class UN_028_Class {
public:
  static UN_028_Class& getInstance() {
    static UN_028_Class instance;
    return instance;
  }
  void setValue1(int &x) {
    value = &x;
  }

  void setValue2(int &x) {
    value2 = &x;
  }

  void printValue1() {
    int ret = *value; //It's ok.
  }

  void printValue2() {
    int ret = *value2; 
  }

private:
  UN_028_Class() {}
  ~UN_028_Class() {}

  int *value;
  int *value2;
};

void UN_028_function() {
  int v = 10;
  int v2;
  UN_028_Class& obj = UN_028_Class::getInstance();
  obj.setValue1(v);
  
  obj.printValue1(); //It's ok.

  obj.setValue2(v2);

  obj.printValue2(); //@violation UNINIT
}

