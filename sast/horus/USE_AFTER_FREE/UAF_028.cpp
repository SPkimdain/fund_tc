
/* UAF_028 - singleton pattern */
class UAF_028_Class {
public:
  static UAF_028_Class& getInstance() {
    static UAF_028_Class instance;
    return instance;
  }
  void releaseValue() {
    delete value;
  }

  void printValue() {
    *value = 10; // USE_AFTER_FREE
  }

private:
  UAF_028_Class() {
    value = new int(10);
  }
  ~UAF_028_Class() {}

  int* value;
};

void UAF_028_function() {
  int* x = new int();
  *x = 1000;
  UAF_028_Class& obj = UAF_028_Class::getInstance();
  UAF_028_Class& obj2 = UAF_028_Class::getInstance();
  
  obj.printValue(); //It's ok.

  obj2.releaseValue();

  obj.printValue(); //@violation USE_AFTER_FREE

  delete x;
}

